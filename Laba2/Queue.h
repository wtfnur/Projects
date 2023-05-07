#pragma once
#include <iostream>


template <class T>
class Queue
{
public:
    virtual void enQueue(const T& e) = 0;
    virtual T deQueue() = 0;
    virtual bool isEmpty() = 0;
    virtual ~Queue() {}

};


template <class T>
class QueueArray : public Queue<T>
{
public:
    QueueArray(int size);
    QueueArray(const QueueArray<T>& src);
    ~QueueArray() {};
    void enQueue(const T& e);
    T deQueue();
    bool isEmpty() { return head_ == tail_; }
    void print();
private:
    T* array_;
    int head_;
    int tail_;
    int size_;
};

class QueueOverflow : public std::exception
{
public:
    QueueOverflow() : reason_("Queue Overflow") {}
    const char* what() const { return reason_; }
private:
    const char* reason_;
};
class QueueUnderflow : public std::exception
{
public:
    QueueUnderflow() : reason_("Queue Underflow") {}
    const char* what() const { return reason_; }
private:
    const char* reason_;
};
class WrongQueueSize : public std::exception
{
public:
    WrongQueueSize() : reason_("Wrong Queue Size") {}
    const char* what() const { return reason_; }
private:
    const char* reason_;
};



