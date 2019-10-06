#pragma once
#include <iostream>

// 饿汉式(基础版本)
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
// 静态数据成员初始化
Singleton* Singleton::singleton_ = new Singleton();

Singleton* Singleton::GetInstance()
{
	return singleton_;
}


#include <mutex>
// 懒汉式(线程安全版本,因为是通过new方式创建的，所以还需要实现双检锁)
class SingletonT {
public:
	static SingletonT* GetInstance();
	void hello() { std::cout << "I am SingletonT." << std::endl; }
private:
	SingletonT() {};
	SingletonT(const SingletonT& singleton) = delete;
	SingletonT& operator=(const SingletonT& singleton) = delete;
	static std::mutex  m_; // 维护一个互斥锁(静态成员变量)，用于线程安全实现
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