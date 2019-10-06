#pragma once
#include <queue>

// ����������֮��ָ��ʹ��˫�˶���ȥʵ��һ����ͨ���С������ǱȽϾ����������Ӧ�ó�����
// ������ģʽ�����ڼ̳�ʵ��

template <typename T>
class Queue : private std::deque<T>{
public:
	using ElementType = T;
	void PushBack(ElementType v);
	void PopFront();
	T Front();
	size_t Size();
};

template <typename T>
void Queue<T>::PushBack(ElementType v)
{
	this->push_back(v);
}

template <typename T>
void Queue<T>::PopFront()
{
	this->pop_front();
}

template <typename T>
T Queue<T>::Front()
{
	return this->front();
}

template <typename T>
size_t Queue<T>::Size()
{
	return this->size();
}