#pragma once
#include <string>
#include <iostream>

class People {
public:
	virtual void Apologize() = 0;
};

class Suitor : public People {
public:
	Suitor(const std::string& name) :m_girl(name) {};
	void Apologize() {
		std::cout << "向" << m_girl <<"道歉" << std::endl;
	}
private:
	std::string m_girl;
};

class Proxy : public People {
public:
	Proxy(Suitor* suitor) :m_suitor(suitor) {};
	void Apologize() {
		// 替人把话说了
		m_suitor->Apologize();
	}
private:
	Suitor* m_suitor;
};