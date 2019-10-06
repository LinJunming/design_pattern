#pragma once
#include <queue>

// 常见面试题之“指定使用双端队列去实现一个栈”，就是比较经典的适配器应用场景。
// 适配器模式：基于组合实现
template<typename T>
class Stack {
public:
	using ElementType = T;
	void Push(ElementType v);
	void Pop();
	ElementType Top();
	size_t Size();
private:
	std::deque<T> d;
};

template<typename T>
void Stack<T>::Push(ElementType v)
{
	this->d.push_back(v);
}

template<typename T>
void Stack<T>::Pop()
{
	this->d.pop_back();
}

template<typename T>
T Stack<T>::Top()
{
	return this->d.back();
}

template<typename T>
size_t Stack<T>::Size()
{
	return this->d.size();
}