#pragma once
#include <queue>

// 常见面试题之“指定使用双端队列去实现一个普通队列”，就是比较经典的适配器应用场景。
// 适配器模式：基于继承实现

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