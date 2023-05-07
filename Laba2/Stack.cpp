#include "Stack.h"
#include <iostream>

template <class T>
void limStack<T>::print()
{
	for (T i = 0; count > i; i++) {
		std::cout << array[i] << "  ";
	}
	std::cout << std::endl;

}

template <class T>
limStack<T>::limStack(int size)
{
	try
	{
		array = new T[MaxSize = size];
	}
	catch (...)
	{
		WrongStackSize as;
		std::cout << as.what();
		exit(-1);
	}
	count = 0;
}

template <class T>
limStack<T>::limStack(const limStack<T>& src)
{

	try
	{
		array = new T[MaxSize = src.MaxSize];
	}
	catch (...)
	{
		WrongStackSize as;
		std::cout << as.what();
		exit(-1);
	}

	count = src.count;
	for (int i = 0; i < count; i++) array[i] = src.array[i];
}


template <class T> limStack<T>::~limStack() {}


template <class T> void limStack<T> ::push(const T& e)
{

	if (count == MaxSize) {
		StackOverflow as;
		std::cout << as.what();
		exit(-1);
	}

	array[count++] = e;

}

template <class T> T& limStack<T> ::pop()
{

	if (count == 0) {
		StackUnderflow as;
		std::cout << as.what();
		exit(-1);
	}
	return array[count--];
}
template <class T> bool limStack<T> ::isEmpty()
{


	if (count == NULL) {

		return true;
	}
	return false;
}

template <class T> T& limStack<T>::top()
{
	if (count == 0)
	{
		StackUnderflow as;
		std::cout << as.what();
		exit(-1);
	}
	return array[count - 1];
}

