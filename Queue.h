/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Evgeni Dimov
* @idnumber 45137
* @task 2
* @compiler VC
*
*/
#ifndef QUEUE_H
#define QUEUE_H

template <typename T>

class Queue {
private:
	struct Node {
		T m_data;
		Node* m_next;
	};
	Node* front;
	Node* back;

public:
	Queue() { front = nullptr; back = nullptr; }
	bool isEmpty();
	void enqueue(const T&);
	void dequeue();
	T& getFront();
	T& getBack();
	~Queue();
};

template <typename T>
inline bool Queue<T>::isEmpty()
{
	if (front == nullptr)
		return true;
	else
		return false;
}

template <typename T>
inline void Queue<T>::enqueue(const T& data)
{
	Node* tmp = new Node;
	tmp->m_data = data;
	if (front == nullptr)
	{
		front = tmp;
		back = tmp;
	}
	else {
		back->m_next = tmp;
		back = tmp;
	}
}

template <typename T>
inline void Queue<T>::dequeue()
{
	if (front != back)
	{
		Node* tmp = front;
		front = tmp->m_next;
		delete tmp;
	}
	else {
		delete front;
		front = nullptr;
		back = nullptr;
	}
}

template <typename T>
inline T& Queue<T>::getFront()
{
	if (!isEmpty())
	{
		return front->m_data;
	}
	else throw 420;
}

template<typename T>
inline T& Queue<T>::getBack()
{
	if (!isEmpty())
	{
		return back->m_data;
	}
	else throw 420;
}

template<typename T>
inline Queue<T>::~Queue() {
	while (!isEmpty()) {
		dequeue();
	}
	delete front;
}

#endif