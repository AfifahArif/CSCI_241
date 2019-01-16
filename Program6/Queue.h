#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

/***
Queue template class definition
***/

template <class T>
class Queue;

template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T>
class Queue
{
	friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);

	private:
		T* qArray;
		size_t qSize,
		qCapacity;
		int qFront,
		qBack;

	public:
		Queue();
		~Queue();
		Queue(const Queue<T>&);
		Queue<T>& operator=(const Queue<T>&);
		void clear();
		size_t size() const;
		size_t capacity() const;
		bool empty() const;
	
		int back() const;
		const T& front() const;
		void push(const T&);
		void pop();

		void reserve(size_t);
};

/***
Queue template class method definitions
***/
template<class T>
Queue<T>::Queue()
{
	qSize = 0;
	qCapacity = 0;
	qArray = nullptr;
	qFront = 0;
	qBack = qCapacity-1;
}

template<class T>
void Queue<T>::clear()
{
	qSize = 0;
	qFront = 0;
	qBack = qCapacity-1;
}

template<class T>
size_t Queue<T>::size() const
{
	return qSize;
}

template<class T>
size_t Queue<T>::capacity() const
{
	return qCapacity;
}

template<class T>
Queue<T>::~Queue()
{
	delete[] qArray;
}

template<class T>
bool Queue<T>::empty() const
{
	if (qSize == 0)
	return true;
	else
	return false;
}

template<class T>
Queue<T>::Queue(const Queue<T>& other)
{
	qCapacity = other.qCapacity;
	qSize = other.qSize;
	qArray = new T[qCapacity];

	for (size_t i = 0; i < qSize; ++i)
	qArray[i] = other.qArray[i];

	qFront = other.qFront;
	qBack = other.qBack;
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other)
	{
		delete[] qArray;

		qSize = other.qSize;
		qCapacity = other.qCapacity;

		qFront = other.qFront;
		qBack = other.qBack;

		if (qCapacity == 0)
		qArray = nullptr;
		else
		qArray = new T[qCapacity];

		for (size_t i = 0; i < qSize; i++)
		qArray[i] = other.qArray[i];
	}
	return *this;
}

template<class T>
ostream& operator<<(ostream& lhs, const Queue<T>& rhs)
{
	size_t current;
	size_t i;

	for (current = rhs.qFront, i = 0; i < rhs.qSize; i++)
	{
		lhs << rhs.qArray[current] << ' ';
		current = (current+1) % rhs.qCapacity;
	}
	return lhs;
}

template<class T>
const T& Queue<T>::front() const
{
	if (empty())
	throw underflow_error ("queue underflow on call to front()");
	else
	return qArray[qFront];
}

template<class T>
int Queue<T>::back() const
{
	if (empty())
	throw underflow_error ("queue underflow on call to back()");
	else
	return qArray[qBack];
}

template<class T>
void Queue<T>::push(const T& val)
{
	//if stack is full, allocate additional storage
	if (qSize == qCapacity)
	{
		if (qCapacity == 0)
		reserve(1);
		else
		reserve(qCapacity*2);
	}
	qBack = (qBack+1) % qCapacity;
	qArray[qBack] = val;
	++qSize;
}

template<class T>
void Queue<T>::pop()
{
	if (empty())
	throw underflow_error ("queue underflow on pop()");
	else
	{
		qFront = (qFront + 1) % qCapacity;
		--qSize;
	}
}

template<class T>
void Queue<T>::reserve(size_t n)
{
	if (n < qSize || n == qCapacity)
	return;

	T* tempArray = new T[n];

	int current = qFront;
	for (size_t i = 0; i < qSize; i++)
	{
		tempArray[i] = qArray[current];
		current = (current + 1) % qCapacity;
	}
	qCapacity = n;
	qFront = 0;
	qBack = qSize - 1;
	delete[] qArray;
	qArray = tempArray;
}
#endif
