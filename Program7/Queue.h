#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

using std::underflow_error;

template <class T>
class Queue;

template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T>
struct Node
{
	T data;
	Node<T>* next;

	Node(const T& = T(), Node<T>* next = nullptr);
};

template <class T>
Node<T>::Node(const T& nData, Node<T>* nNext)
{
	data = nData;
	next = nNext;
}

template <class T>
class Queue
{
	friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);

	private:
		Node<T>* qFront;
		Node<T>* qBack;
		size_t qSize;

	public:
		Queue();
		~Queue();
		Queue(const Queue<T>&);
		size_t size() const;
		bool empty() const;
		void clear();
		T& front() const;
		T& back() const;
		void push(int);
		void pop();
		void copyList(const Queue<T>&);
		Queue<T>& operator=(const Queue<T>&);
};

template <class T>
Queue<T>::Queue()
{
	qFront = qBack = nullptr;
	qSize = 0;
}

template <class T>
Queue<T>::Queue(const Queue<T>& other)
{
	qFront = qBack = nullptr;
	qSize = 0;
	copyList(other);
}

template <class T>
Queue<T>::~Queue()
{
	clear();
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& equal)
{
	if(this != &equal)
	{
		clear();
		copyList(equal);
	}
	return *this;
}

template <class T>
size_t Queue<T>::size() const
{
	return qSize;
}

template <class T>
bool Queue<T>::empty() const
{
	return qSize == 0;
}

template <class T>
std::ostream& operator<<(std::ostream& lhs, const Queue<T>& out)
{
	Node<T>* ptr;

	for (ptr = out.qFront; ptr != nullptr; ptr = ptr->next)
	{
		lhs << ptr->data << ' ';
	}
	return lhs;
}

template <class T>
void Queue<T>::clear()
{
	while (!empty())
		pop();
}

template <class T>
T& Queue<T>::front() const
{
	if (empty())
	{
		throw underflow_error("underflow error on front()");
	}
	return qFront -> data;
}

template <class T>
T& Queue<T>::back() const
{
	if (empty())
	{
		throw underflow_error("underflow error on back()");
	}
	return qBack -> data;
}

template <class T>
void Queue<T>::push(int val)
{
	Node<T>* nNode = new Node<T>(val);
	if(empty())
	qFront = nNode;
	else
	qBack->next = nNode;

	qBack = nNode;
	qSize++;
}

template <class T>
void Queue<T>::pop()
{
	if(empty())
	throw underflow_error("underflow error on pop()");
	Node<T>* delNode = qFront;
	qFront = qFront->next;
	if(qFront == nullptr)
	qBack = nullptr;

	delete delNode;
	qSize--;
}

template <class T>
void Queue<T>::copyList(const Queue<T>& other)
{
	Node<T>* ptr;

	for (ptr = other.qFront; ptr != nullptr; ptr = ptr->next)
	push(ptr->data);
}
#endif
