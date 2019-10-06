#pragma once
#include <queue>

// ����������֮��ָ��ʹ��˫�˶���ȥʵ��һ��ջ�������ǱȽϾ����������Ӧ�ó�����
// ������ģʽ���������ʵ��
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