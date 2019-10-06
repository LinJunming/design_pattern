#pragma once
#include <iostream>

// ����ʽ(�����汾)
class Singleton {
public:
	static Singleton* GetInstance();
	void hello() { std::cout << "I am Singleton." << std::endl; }
private:
	Singleton() {};
	Singleton(const Singleton& singleton) = delete;
	Singleton& operator=(const Singleton& singleton) = delete;

	static Singleton* singleton_;
};
// ��̬���ݳ�Ա��ʼ��
Singleton* Singleton::singleton_ = new Singleton();

Singleton* Singleton::GetInstance()
{
	return singleton_;
}


#include <mutex>
// ����ʽ(�̰߳�ȫ�汾,��Ϊ��ͨ��new��ʽ�����ģ����Ի���Ҫʵ��˫����)
class SingletonT {
public:
	static SingletonT* GetInstance();
	void hello() { std::cout << "I am SingletonT." << std::endl; }
private:
	SingletonT() {};
	SingletonT(const SingletonT& singleton) = delete;
	SingletonT& operator=(const SingletonT& singleton) = delete;
	static std::mutex  m_; // ά��һ��������(��̬��Ա����)�������̰߳�ȫʵ��
	static SingletonT* singleton_t_;
};

SingletonT* SingletonT::singleton_t_ = nullptr;
std::mutex SingletonT::m_;

SingletonT* SingletonT::GetInstance()
{
	if (singleton_t_ == nullptr)
	{
		m_.lock();
		if (singleton_t_ == nullptr) {
			singleton_t_ = new SingletonT();
		}
		m_.unlock();
	}
	return singleton_t_;
}