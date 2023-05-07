#pragma once
#include <iostream>

template <class T>
class Stack
{
public:
	virtual ~Stack() {}
	virtual void push(const T& e) = 0;
	virtual T& pop() = 0;
	virtual void print() = 0;
	virtual bool isEmpty() = 0;

};


template <class T>
class limStack : public Stack<T>
{
public:
	T* array;
	int count, MaxSize;

	limStack(int size);
	limStack(const limStack<T>& src);
	~limStack();

	void push(const T& e);
	T& pop();
	T& top();
	bool isEmpty();
	void print();

};

class StackOverflow : public std::exception {
public:
	StackOverflow() : reason_("Stack Overflow") {}
	const char* what() const { return reason_; }
private:
	const char* reason_;
};

class StackUnderflow : public std::exception {
public:
	StackUnderflow() : reason_("Stack Underflow") {}
	const char* what() const {
		return reason_;
	}
private:
	const char* reason_;
};

class WrongStackSize : public std::exception
{
public:
	WrongStackSize() : reason_("Wrong Stack Size") {}
	const char* what() const { return reason_; }
private:
	const char* reason_;
};






