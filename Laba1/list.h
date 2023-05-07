#pragma once

#include <iostream>
template<typename T>
class DictionaryList
{
private:
	template<typename T>
	class Node
	{
	public:
		Node* next;
		T key;
		Node(T key = T(), Node* next = nullptr)
		{
			this->key = key;
			this->next = next;
		}
	};

	Node<T>* head;
	Node<T>* tail;
	bool insertNode(Node<T>* head_1);

	Node<T>* searchNode(T key_1)const {
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			if (temp->key == key_1)
			{
				return temp;
			}

			temp = temp->next;
		}
		return nullptr;
	}

public:
	DictionaryList();

	DictionaryList(const DictionaryList& list)noexcept;

	DictionaryList(DictionaryList&& list)noexcept;

	~DictionaryList() {};

	void insert(T key);

	void deleted(T key_1);

	void search(T key);

	T& operator[](int index);

	void merge(DictionaryList& list);

	void remove_list(DictionaryList& list);

	friend DictionaryList getIntersection(const DictionaryList<T>& list1, const DictionaryList<T>& list2) {
		DictionaryList<T> count;
		if (list1.head == nullptr || list2.head == nullptr) {
			std::cerr << "One of the lists is empty";
			return count;
		}
		DictionaryList<T>::template Node<T>* temp1 = list1.head;
		while (temp1 != nullptr) {
			DictionaryList<T>::template Node<T>* temp2 = list2.head;
			while (temp2 != nullptr) {
				if (temp1->key == temp2->key) {
					count.insert(temp1->key);
					break;
				}
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}
		return count;
	}

	DictionaryList& operator = (const DictionaryList& list) {
		Node<T>* buf = nullptr;
		Node<T>* next = head;
		while (next != nullptr)
		{
			buf = next;
			next = next->next;
			delete buf;
		}
		this->head = nullptr;
		next = list.head;
		while (next != nullptr)
		{
			Node<T>* temp = new Node<T>(next->key);
			this->insertNode(temp);
			next = next->next;
		}
		return *this;
	}

	DictionaryList& operator = (DictionaryList&& list)noexcept {
		if (this->head != list.head)
		{
			this->head = list.head;
			list.head = nullptr;
		}
		if (this->tail != list.tail)
		{
			this->tail = list.tail;
			list.tail = nullptr;
		}
		return *this;
	}

	friend std::ostream& operator << (std::ostream& out, const DictionaryList<T>& list) {
		if (list.head == nullptr || list.tail == nullptr) {
			out << "The list is empty";
		}

		DictionaryList<T>::template Node<T>* temp = list.head;
		while (temp != nullptr) {
			out << temp->key << " ";
			temp = temp->next;
		}
		return out;
	}

};

