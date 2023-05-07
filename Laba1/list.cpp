#include "list.h"

template<typename T>
DictionaryList<T>::DictionaryList() {
	head = nullptr;
	tail = nullptr;
}

template<typename T>
DictionaryList<T>::DictionaryList(const DictionaryList& list)noexcept {
	this->head = nullptr;
	this->tail = nullptr;
	Node<T>* next = list.head;
	while (next != nullptr) {
		Node<T>* temp = new Node<T>(next->key);
		this->insertNode(temp);
		next = next->next;
	}
}

template<typename T>
DictionaryList<T>::DictionaryList(DictionaryList&& list)noexcept {
	this->head = list.head;
	list.head = nullptr;
	this->tail = list.tail;
	list.tail = nullptr;
}

template<typename T>
void DictionaryList<T>::insert(T key) {
	Node<T>* temp = new Node<T>(key);
	if (insertNode(temp)) {

		return;
	}
	delete temp;

}

template<typename T>
void DictionaryList<T>::deleted(T key_1) {
	Node<T>* forDel = searchNode(key_1);
	if (forDel == nullptr) {
		return;
	}
	if (head->key == forDel->key) {
		Node<T>* buf = head->next;
		delete head;
		head = buf;
		return;
	}
	Node<T>* temp = head;
	while (temp->next != forDel) {
		temp = temp->next;
	}
	temp->next = nullptr;
	if (tail->key == forDel->key)
		tail = temp;
	return;
}

template<typename T>
void DictionaryList<T>::search(T key) {
	if (searchNode(key) == nullptr) {
		std::cout << "Not found";
		return;
	}
	std::cout << "Found";
}

template<typename T>
T& DictionaryList<T>::operator[](int index) {
	int count = 0;
	Node<T>* over = this->head;
	while (over != nullptr) {
		if (count == index)
		{
			return over->key;
		}
		over = over->next;
		count++;
	}

}

template<typename T>
void DictionaryList<T>::merge(DictionaryList& list) {
	while (list.head != nullptr) {
		Node<T>* temp = list.head->next;
		list.head->next = nullptr;
		if (insertNode(list.head)) {
			list.head = temp;
			continue;
		}
		delete list.head;
		list.head = temp;
	}
}

template<typename T>
void DictionaryList<T>::remove_list(DictionaryList& list) {
	if (list.head == nullptr || head == nullptr) {
		std::cerr << "One of the lists is empty";
		return;
	}
	else if (tail == nullptr) {
		std::cerr << "One of the lists is empty";
		return;
	}
	Node<T>* temp = list.head;
	while (temp != nullptr) {
		this->deleted(temp->key);
		temp = temp->next;
	}
	Node<T>* temp_ = list.tail;
	while (temp_ != nullptr) {
		this->deleted(temp_->key);
		temp_ = temp_->next;
	}
}

template<typename T>
bool DictionaryList<T>::insertNode(Node<T>* head_1) {
	if (head_1 == nullptr) {
		std::cerr << "	Node is empty";
		return false;
	}
	if (head == nullptr || tail == nullptr) {
		head = head_1;
		tail = head_1;
		return true;
	}

	if (head->key == head_1->key) {
		return false;
	}
	if (head->key > head_1->key) {
		head_1->next = head;
		head = head_1;
		return true;
	}
	Node<T>* temp = head;
	while (temp->next != nullptr) {
		if (temp->next->key == head_1->key) {
			return false;
		}
		if (temp->next->key > head_1->key) {
			head_1->next = temp->next;
			temp->next = head_1;
			return true;
		}
		temp = temp->next;
	}
	temp->next = head_1;
	return true;
}
