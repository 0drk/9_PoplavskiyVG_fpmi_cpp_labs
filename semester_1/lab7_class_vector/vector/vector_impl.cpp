#include "vector_impl.h"
#include <algorithm>
#include <utility>
#include <iostream>  

void Vector::reallocate(std::size_t new_capacity) {
    if (new_capacity == 0) {
        delete[] data_;
        data_ = nullptr;
        capacity_ = 0;
        return;
    }

    int* new_data = new int[new_capacity];
    std::size_t copy_size = std::min(size_, new_capacity);
    for (std::size_t i = 0; i < copy_size; ++i) {
        new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
    if (size_ > new_capacity) {
        size_ = new_capacity;
    }
}

Vector::Vector() : data_(nullptr), size_(0), capacity_(0) {
}

Vector::Vector(std::size_t size) : size_(size), capacity_(size) {
    data_ = new int[size_]();  
}

Vector::Vector(std::initializer_list<int> init) : size_(init.size()), capacity_(init.size()) {
    data_ = new int[capacity_];
    std::size_t i = 0;
    for (const int& val : init) {
        data_[i++] = val;
    }
}

Vector::Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
    data_ = new int[capacity_];
    for (std::size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new int[capacity_];
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

Vector::~Vector() {
    delete[] data_;
}

void Vector::Swap(Vector& other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

int& Vector::operator[](std::size_t index) {
    return data_[index];
}

const int& Vector::operator[](std::size_t index) const {
    return data_[index];
}

int& Vector::At(std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

const int& Vector::At(std::size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

std::size_t Vector::Size() const {
    return size_;
}

std::size_t Vector::Capacity() const {
    return capacity_;
}

void Vector::PushBack(int value) {
    if (size_ >= capacity_) {
        std::size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        reallocate(new_capacity);
    }
    data_[size_++] = value;
}

void Vector::PopBack() {
    if (size_ > 0) {
        --size_;
    }
}

void Vector::Clear() {
    size_ = 0;
}

void Vector::Reserve(std::size_t new_capacity) {
    if (new_capacity > capacity_) {
        reallocate(new_capacity);
    }
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "[";
    for (std::size_t i = 0; i < v.size_; ++i) {
        if (i != 0)
            os << ", ";
        os << v.data_[i];
    }
    os << "]";
    return os;
}
