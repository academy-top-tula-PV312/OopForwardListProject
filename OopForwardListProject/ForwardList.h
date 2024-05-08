#pragma once
#include <iostream>
#include <exception>

template <typename T>
struct Node
{
	T value;
	Node<T>* next = nullptr;
};


template <typename T>
class ForwardList;

template <typename T>
class ForwarListIterator
{
	ForwardList<T>* container;
	Node<T>* current;
public:
	ForwarListIterator(ForwardList<T>* container)
		: container{ container },
		current{ container->Head() } {}
	
	void Set();
	void Next();
	bool EndOf();
	T Current();
};



template <typename T>
class ForwardList
{
	Node<T>* head;
	int size;
public:
	ForwardList();
	ForwardList(const ForwardList<T>& other);
	ForwardList(ForwardList<T>&& other) noexcept;

	~ForwardList();

	int Size();
	Node<T>* Head();

	void PushHead(T value);
	T PopHead();

	void Insert(int index, T value);
	T Remove(int index);

	T& At(int index);
	T& operator[](int index);

	ForwarListIterator<T> GetIterator();

	//
	void Show();
};

template<typename T>
inline ForwardList<T>::ForwardList() : head{}, size{} {}

template<typename T>
inline ForwardList<T>::ForwardList(const ForwardList<T>& other)
{
	size = 0;
	for (int step{ other.size - 1 }; step >= 0; step--)
	{
		Node<T>* currentNode = other.head;
		for (int i{}; i < step; i++)
			currentNode = currentNode->next;
		
		PushHead(currentNode->value);
	}
}

template<typename T>
inline ForwardList<T>::ForwardList(ForwardList<T>&& other) noexcept
{
	this->head = other.head;
	this->size = other.size;
	other.head = nullptr;
	other.size = 0;
}

template<typename T>
inline ForwardList<T>::~ForwardList()
{
	while (head)
		PopHead();
}

template<typename T>
inline int ForwardList<T>::Size()
{
	return size;
}

template<typename T>
inline Node<T>* ForwardList<T>::Head()
{
	return head;
}

template<typename T>
inline void ForwardList<T>::PushHead(T value)
{
	Node<T>* newNode = new Node<T>;
	newNode->value = value;
	newNode->next = head;

	head = newNode;

	size++;
}

template<typename T>
inline T ForwardList<T>::PopHead()
{
	T value = head->value;

	Node<T>* deleteNode = head;
	head = head->next;

	delete deleteNode;

	size--;

	return value;
}

template<typename T>
inline void ForwardList<T>::Insert(int index, T value)
{
	if (index <= 0 || !head)
	{
		PushHead(value);
		return;
	}

	if (index >= size)
		index = size;

	Node<T>* currentNode = head;
	for (int i{}; i < index - 1; i++)
		currentNode = currentNode->next;

	Node<T>* newNode = new Node<T>;
	newNode->value = value;
	newNode->next = currentNode->next;

	currentNode->next = newNode;
	size++;
}

template<typename T>
inline T ForwardList<T>::Remove(int index)
{
	if (index <= 0)
		return PopHead();

	if (index >= size - 1)
		index = size - 1;

	Node<T>* currentNode = head;
	for (int i{}; i < index - 1; i++)
		currentNode = currentNode->next;
	T value = currentNode->next->value;

	Node<T>* deleteNode = currentNode->next;
	currentNode->next = currentNode->next->next;

	delete deleteNode;
	size--;

	return value;
}

template<typename T>
inline T& ForwardList<T>::At(int index)
{
	if (index < 0 || index >(size - 1))
		throw std::out_of_range("Out of list's range ");

	Node<T>* currentNode = head;
	for (int i{}; i < index; i++)
		currentNode = currentNode->next;

	return currentNode->value;
}

template<typename T>
inline T& ForwardList<T>::operator[](int index)
{
	return At(index);
}

template<typename T>
inline ForwarListIterator<T> ForwardList<T>::GetIterator()
{
	return ForwarListIterator<T>(this);
}



template<typename T>
inline void ForwardList<T>::Show()
{
	Node<T>* currentNode = head;
	while (currentNode)
	{
		std::cout << currentNode->value << "\n";
		currentNode = currentNode->next;
	}
}





template<typename T>
inline void ForwarListIterator<T>::Set()
{
	current = container->Head();
}

template<typename T>
inline void ForwarListIterator<T>::Next()
{
	if (current)
		current = current->next;
}

template<typename T>
inline bool ForwarListIterator<T>::EndOf()
{
	return !current;
}

template<typename T>
inline T ForwarListIterator<T>::Current()
{
	return current->value;
}

