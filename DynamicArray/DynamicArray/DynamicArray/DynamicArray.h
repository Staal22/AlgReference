#pragma once
#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>

template<typename T>
class DynamicArray {
public:
   DynamicArray();
   
   DynamicArray(std::initializer_list<T> list);

   void Expand();

   void Shrink();

   void PushBack(T data);

   void InsertAtIndex(const int& index, T data);

   void PopBack();

   T& At(const int& index);

   T& operator[](const int& i);

   // return a copy
   T SafeAt(const int& index) const;

   int Size() const; 

   int Capacity() const;

   template<typename U>
   friend std::ostream& operator<<(std::ostream& os, const DynamicArray<U>& n); 
   
   
private:
   bool OutOfRange(const int& i) const;

   
   T* _arr{};  
   int _size;
   int _capacity;

   const std::string k_ERROR = "[ERROR] INDEX WAS OUT OF RANGE : ";
};


#include "DynamicArray.tpp"