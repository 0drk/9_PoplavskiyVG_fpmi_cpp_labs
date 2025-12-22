#pragma once

#ifndef VECTOR_IMPL_H
#define VECTOR_IMPL_H

#include <ostream>
#include <initializer_list>
#include <stdexcept>
#include <cstddef>


class Vector {
private:
    int* data_;
    std::size_t size_;
    std::size_t capacity_;

    void reallocate(std::size_t new_capacity);

public:
   

    //конструкторы
    Vector();
    Vector(std::size_t size);
    Vector(std::initializer_list<int> init);
    Vector(const Vector& other);


    // Оператор присваивания
    Vector& operator=(const Vector& other);

    ~Vector();

    

    int& operator[](std::size_t index);
    const int& operator[](std::size_t index) const;

    int& At(std::size_t index);
    const int& At(std::size_t index) const;

    std::size_t Size() const;
    std::size_t Capacity() const;

    //методы
    void Swap(Vector& other);
    void PushBack(int value);
    void PopBack();
    void Clear();
    void Reserve(std::size_t new_capacity);

    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
};

#endif  ;

