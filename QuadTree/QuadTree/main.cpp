#include <iostream>
#include "Classes/QuadTree.h"

#include <string>

int main() {
    QuadTree tree(Bounds(Vector2(0, 0), Vector2(100, 100)), 1);
    std::cout << "INSERTING POINTS" <<std::endl;
    tree.Insert(Vector2(25, 25));
    tree.Insert(Vector2(-25, 25));
    tree.Insert(Vector2(25, -25));
    tree.Insert(Vector2(-25, -25));

    std::vector<Vector2> list(0);
    Bounds bounds = Bounds(Vector2(25,25), Vector2(10,10));
    tree.Query(list, bounds);

    std::cout << "|" << std::endl;
    
    std::cout << "Quieried points: " <<std::endl;
    for (int i = 0; i < list.size(); ++i) {
        std::cout << list[i].ToString() << std::endl;
    }
    // std::cout << tree.ToString(0);
    return 0;
}
