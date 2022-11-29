#pragma once
#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>

template<typename T>
class DynamicArray {
public:
   DynamicArray();
   
   DynamicArray(std::initializer_list<T> list) : DynamicArray() {
      
      std::vector<T> temp = {list};
      while (_capacity < temp.size()) {
         // std::cout << "Expanded!" << std::endl;
         Expand();
      }

      // TODO transfer via memnmove /cpy
      for (int i = 0; i < temp.size(); ++i) 
         _arr[i] = temp[i];
      _size += temp.size();
      
      // std::cout << temp.size() << std::endl;
   }

   void Expand() {
      T* temp = new T[_capacity * 2];
      for (int i = 0; i < _capacity; ++i) {
         temp[i] = _arr[i];
      }

      delete _arr;
      _arr = temp;
      
      _capacity *=2;

      std::cout << "Exanding" << std::endl;
   }

   void Shrink() {
      if (_capacity <= 1) {
         return;
      }
      
      T* temp = new T[_capacity / 2];
      for (int i = 0; i < _capacity / 2; ++i) {
         temp[i] = _arr[i];
      }

      delete _arr;
      _arr = temp;
      
      _capacity /=2;
      std::cout << "Shrinking" << std::endl;
   }

   void PushBack(T data) {
      if (_size >= _capacity) // at max capacity, expand 
         Expand();

      _arr[_size] = data;
      _size++;
   }

   void InsertAtIndex(const int& index, T data) {
      if (OutOfRange(index)) {
         std::cout << k_ERROR << index << std::endl;
         std::string error = k_ERROR + " " + std::to_string( index);
         throw std::invalid_argument(error);
         return;
      }

      if (_size >= _capacity) // at max capacity, expand        
         Expand();

      for (int i = _size; i > index; --i) { // moving all elements after i one to the right
         _arr[i] = _arr[i-1];
      }

      _arr[index] = data;
      _size++;
      
      
   }

   void PopBack() {
      _size--;

      if (_size <= _capacity / 2) {
         Shrink();
      }
      // TODO can also reset element here if we want.
   }

   T& At(const int& index) {
      if (OutOfRange(index)) {
         std::cout << k_ERROR << index << std::endl;
         std::string error = k_ERROR + " " + std::to_string( index);
         throw std::invalid_argument(error);
      } 
      
      return _arr[index];
   }

   T& operator[](const int& i) {
      return At(i);
   }

   int Size() const {
      return _size;
   }

   int Capacity() const {
      return _capacity;
   }
   
   
private:
   bool OutOfRange(const int& i) const {
      if (i < 0 || i >= _size)
         return true;
      return false;
   }

   
   T* _arr{};  
   int _size;
   int _capacity;

   const std::string k_ERROR = "[ERROR] INDEX WAS OUT OF RANGE : ";
};


#include "DynamicArray.tpp"