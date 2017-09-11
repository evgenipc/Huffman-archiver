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
#ifndef PQUEUE_H
#define PQUEUE_H
template<typename T>

class PQueue
{
private:
	struct Node
	{
		T m_data;
		int m_priority;
		Node* m_next;
		Node() {
			m_next = nullptr;
		}
	};
	Node* front;
	Node* back;
	int size;


public:
	PQueue() { front = nullptr; back = nullptr; size = 0; }
	bool isEmpty();
	void enqueue(const T&,const int);
	void dequeue();
	T& getFront();
	int getFrontPri();
	T& getBack();
	int getSize() const { return size; }
	void print();
	~PQueue();
};

template<typename T>
inline bool PQueue<T>::isEmpty()
{
	if (size==0)
		return true;
	else
		return false;
}

template<typename T>
inline void PQueue<T>::enqueue(const T& data,const int priority)
{
	Node* q = new Node;
	Node * tmp = new Node;
	tmp->m_data = data;
	tmp->m_priority = priority;

	if (front == nullptr)
	{
		front = tmp;
		back = tmp;
	}
	else if (priority < front->m_priority ||(priority==front->m_priority && data< front->m_data))
	{
		tmp->m_next = front;
		front = tmp;
	}
	else
	{
		q = front;
		while (q->m_next != nullptr
			&& ((q->m_next->m_priority < priority || (priority == q->m_next->m_priority && q->m_next->m_data<data ))))
			q = q->m_next;
		tmp->m_next = q->m_next;
		q->m_next = tmp;
		if (tmp->m_next == nullptr)
			back = tmp;
	}
	++size;

}

template<typename T>
inline void PQueue<T>::dequeue()
{
	if (front != back)
	{
		Node* tmp = front;
		front = tmp->m_next;
		//delete tmp;

	}
	else
	{
		//delete front;
		front = nullptr;
		back = nullptr;
	}
	--size;
}

template<typename T>
inline T& PQueue<T>::getFront()
{
	if (!isEmpty())
	{
		return front->m_data;
	}
	else throw 420;
}
template<typename T>
inline int PQueue<T>::getFrontPri()
{
	if (!isEmpty())
	{
		return front->m_priority;
	}
	else throw 420;
}

template<typename T>
inline T& PQueue<T>::getBack()
{
	if (!isEmpty())
	{
		return back->m_data;
	}
	else throw 420;
}

template<typename T>
inline void PQueue<T>::print()
{
	std::cout <<"----------Queue------" << std::endl;
	Node* curr = front;
	while (curr->m_next!=nullptr)
	{
		std::cout << curr->m_priority << std::endl;
		curr = curr->m_next;
	}
	std::cout << "--------------------" << std::endl;
}

template<typename T>
inline PQueue<T>::~PQueue()
{
	while (!isEmpty())
	{
		dequeue();
	}
	delete front;
}

#endif // !PQUEUE_H
