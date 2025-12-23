#include "forward_list_impl.h"
#include <cstddef>
#include <initializer_list>
#include <iostream>

ForwardList::ForwardList() : head_(nullptr) {
}

ForwardList::ForwardList(const ForwardList& right_hs) : head_(nullptr) {
    Node** current = &head_;
    Node* other = right_hs.head_;
    while (other != nullptr) {
        *current = new Node(other -> value_);
        current = &((*current) -> next_);
        other = other -> next_;
    }
}

ForwardList::ForwardList(size_t count, int32_t value) : head_(nullptr) {
    Node** current = &head_;
    for (size_t i = 0; i < count; ++i) {
        *current = new Node(value);
        current = &((*current) -> next_);
    }
}

ForwardList::ForwardList(std::initializer_list<int32_t> init) : head_(nullptr) {
    Node** current = &head_;
    for (int32_t value : init) {
        *current = new Node(value);
        current = &((*current) -> next_);
    }
}

ForwardList& ForwardList::operator=(const ForwardList& rhs) {
    if (this != &rhs) {
        Clear();
        Node** current = &head_;
        Node* other = rhs.head_;
        while (other != nullptr) {
            *current = new Node(other -> value_);
            current = &((*current) -> next_);
            other = other -> next_;
        }
    }
    return *this;
}

ForwardList::~ForwardList() {
    Clear();
}

void ForwardList::PushFront(int32_t value) {
    Node* new_Node = new Node(value);
    new_Node -> next_ = head_;
    head_ = new_Node;
}

void ForwardList::PopFront() {
    if (head_ == nullptr)
        return;
    Node* temp = head_;
    head_ = head_ -> next_;
    delete temp;
}

void ForwardList::Remove(int32_t value) {
    while (head_ != nullptr && head_ -> value_ == value) {
        Node* tmp = head_;
        head_ = head_ -> next_;
        delete tmp;
    }

    Node* current = head_;
    while (current != nullptr && current -> next_ != nullptr) {
        if (current -> next_ -> value_ == value) {
            Node* to_delete = current -> next_;
            current -> next_ = to_delete -> next_;
            delete to_delete;
        } else {
            current = current -> next_;
        }
    }
}

void ForwardList::Clear() {
    while (head_ != nullptr) {
        Node* tmp = head_;
        head_ = head_ -> next_;
        delete tmp;
    }
}

bool ForwardList::FindByValue(int32_t value) {
    Node* current = head_;
    while (current != nullptr) {
        if (current -> value_ == value) {
            return true;
        }
        current = current -> next_;
    }
    return false;
}

void ForwardList::Print(std::ostream& out) {
    Node* current = head_;
    while (current != nullptr) {
        out << current -> value_;
        if (current -> next_ != nullptr) {
            out << " ";
        }
        current = current -> next_;
    }
}

int32_t ForwardList::Front() const {
    return head_ -> value_;
}

size_t ForwardList::Size() const {
    size_t count = 0;
    Node* current = head_;
    while (current != nullptr) {
        ++count;
        current = current -> next_;
    }
    return count;
}

bool ForwardList::ForwardListIterator::operator==(const ForwardListIterator& other) const {
    return position_ == other.position_;
}

ForwardList::ForwardListIterator ForwardList::begin() {
    return ForwardListIterator(head_);
}

ForwardList::ForwardListIterator ForwardList::end() {
    return ForwardListIterator(nullptr);
}

ForwardList::ForwardListIterator ForwardList::begin() const {
    return ForwardListIterator(head_);
}

ForwardList::ForwardListIterator ForwardList::end() const {
    return ForwardListIterator(nullptr);
}

