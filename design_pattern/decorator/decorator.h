#pragma once
#include <string>
#include <iostream>

// ��˵��
class Man {
public:
	virtual void ExpressLove() = 0;
};

// ֱ��ֱȥ��С����ֻ��һ���Ұ���
class XiaoMing : public Man{
public:
	void ExpressLove() override{
		std::cout << "�Ұ���" << std::endl;
	}
};

// �ϲ����������������ǰѶ������һ�㣬��û��ʼ����
class Decoratetor : public Man {
public:
	Decoratetor(Man* man) : m_man(man) {};
	void ExpressLove() override {
		m_man->ExpressLove();
	}
private:
	Man* m_man;
};
// ʵ�����Σ�A
class DecoratorA : public Decoratetor {
public:
	DecoratorA(Man* man) :Decoratetor(man) {};
	void ExpressLove() override{
		Decoratetor::ExpressLove();
		addDecoration();
	}
private:
	void addDecoration(){
		std::cout << "�Ұ��㵽����ʯ��" << std::endl;
	}
};

// ʵ�����Σ�B
class DecoratorB : public Decoratetor {
public:
	DecoratorB(Man* man) :Decoratetor(man) {};
	void ExpressLove() override {
		Decoratetor::ExpressLove();
		addDecoration();
	}
private:
	void addDecoration() {
		std::cout << "�����㳵�ͷ�" << std::endl;
	}
};