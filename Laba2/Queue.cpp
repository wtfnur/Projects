#include "Queue.h"
#include <iostream>


template <class T>
QueueArray<T>::QueueArray(int size) {
    try {
        array_ = new T[size_ = size];
        head_ = 0;
        tail_ = 0;
    }
    catch (...)
    {
        WrongQueueSize as;
        std::cout << as.what();
        exit(-1);
    }
}


template <class T>
QueueArray<T>::QueueArray(const QueueArray<T>& src) {
    try {
        array_ = new T[size_ = src.size_];
    }
    catch (...) {
        WrongQueueSize as;
        std::cout << as.what();
        exit(-1);
    }

    for (int i = 0; i < src.head_; i++) {
        array_[i] = src.array_[i];
    }
    head_ = src.head_;
    tail_ = src.tail_;
}


template <class T>
void QueueArray<T>::enQueue(const T& enter) {

    if (tail_ == size_)
    {
        QueueOverflow as;
        std::cout << as.what();
        exit(-1);
    }

    //if (++tail_ == size_) tail_ = 0;
    array_[tail_++] = enter;

}

template <class T>
T QueueArray<T>::deQueue() {

    if (head_ == tail_) {
        QueueUnderflow as;
        std::cout << as.what();
        exit(-1);
    }

    return array_[head_++];
}

template <class T>
void QueueArray<T>::print() {
    for (int i = head_; i != tail_; i = (i + 1) % size_) {
        std::cout << array_[i] << " ";
    }
    std::cout << std::endl;
}
