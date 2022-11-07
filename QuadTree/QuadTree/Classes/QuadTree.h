#pragma once
#include <iostream>
#include <string>
#include <vector>


class Vector2 {
public:
    Vector2() {
        x = 0;
        y = 0;
    }

    Vector2(float _x, float _y) {
        x = _x;
        y = _y;
    }

    float x;
    float y;

    Vector2 operator -() const {
        return {-x, -y};
    }

    std::string ToString() {
        std::string s = std::to_string(x) + " " + std::to_string(y);
        return s;
    }

    // Vector2 operator +() const {
    //     return Vector2(x, y);
    // }

    Vector2 operator +(const Vector2& right) const {
        return Vector2(x + right.x, y + right.y);
    }

    Vector2 operator *(const float& right) const {
        return Vector2(x * right, y * right);
    }

    Vector2 operator /(const float& right) const {
        return Vector2(x / right, y / right);
    }
};

/**
 * \brief size of diameter!
 */
class Bounds {
public:
    Bounds() {

    }

    Bounds(Vector2 center, Vector2 size) {
        this->center = center;
        this->size = size;
    }

    Vector2 center;
    Vector2 size;

    Vector2 awdawd = -center;

    bool Contains(Vector2 point) const {
        if (point.x > center.x + size.x / 2.f ||
            point.x < center.x - size.x / 2.f ||
            point.y > center.y + size.y / 2.f ||
            point.y < center.y - size.y / 2.f) {
            return false;
        }
        return true;
    }
};

class QuadTree {
public:
    QuadTree* NW = nullptr;
    QuadTree* NE = nullptr;
    QuadTree* SW = nullptr;
    QuadTree* SE = nullptr;

    // Config
    int capacity = 1;
    Bounds bounds;

    // State
    std::vector<Vector2> points;
    bool bSubdivided = false;

    QuadTree() {

    }

    QuadTree(const Bounds& bounds, int capacity) {
        this->bounds = bounds;
        this->capacity = capacity;
    }

    void Subdivide() {
        bSubdivided = true;
        float x = bounds.size.x / 2.f;
        float y = bounds.size.y / 2.f;
        Vector2 size(x, y);
        NW = new QuadTree(Bounds(bounds.center + Vector2(-x, y),
                                 size), capacity);
        NE = new QuadTree(Bounds(bounds.center + Vector2(x, y),
                                 size), capacity);
        SW = new QuadTree(Bounds(bounds.center + Vector2(-x, -y),
                                 size), capacity);
        SE = new QuadTree(Bounds(bounds.center + Vector2(x, -y),
                                 size), capacity);

    }

    void Insert(Vector2 point) {
        if (!bounds.Contains(point)) {
            // if does not containt, bail
            return;
        }

        if (bSubdivided) {

            std::cout << "INSERTING IN SUBTREES" << std::endl;
            NW->Insert(point);
            NE->Insert(point);
            SW->Insert(point);
            SE->Insert(point);
        }
        else if (points.size() < capacity) {
            std::cout << "HAS SPACE" << std::endl;
            points.push_back(point);
        }
        else {
            // at capacity and not subdivided
            std::cout << "SUBDIVIDE" << std::endl;
            Subdivide();
            Insert(point);
        }
    }

    void Query(std::vector<Vector2>& list, Bounds queryBounds) {
        for (int i = 0; i < points.size(); ++i) {
            if (queryBounds.Contains(points[i])) {
                list.push_back(points[i]);
            }
        }

        if (bSubdivided) {
            NW->Query(list, queryBounds);
            NE->Query(list, queryBounds);
            SW->Query(list, queryBounds);
            SE->Query(list, queryBounds);
        }

    }

    std::string ToString(int depth) {
        std::string s = "DEPTH : " + std::to_string(depth) + "\n";
        for (int i = 0; i < points.size(); ++i) {
            s += "    " + points[i].ToString() + "\n";
        }
        return s;
    }
};
