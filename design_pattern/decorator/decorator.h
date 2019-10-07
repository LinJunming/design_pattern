#pragma once
#include <string>
#include <iostream>

// 人说话
class Man {
public:
	virtual void ExpressLove() = 0;
};

// 直来直去的小明，只会一句我爱你
class XiaoMing : public Man{
public:
	void ExpressLove() override{
		std::cout << "我爱你" << std::endl;
	}
};

// 上层修饰器，基本就是把对象包了一层，还没开始修饰
class Decoratetor : public Man {
public:
	Decoratetor(Man* man) : m_man(man) {};
	void ExpressLove() override {
		m_man->ExpressLove();
	}
private:
	Man* m_man;
};
// 实际修饰，A
class DecoratorA : public Decoratetor {
public:
	DecoratorA(Man* man) :Decoratetor(man) {};
	void ExpressLove() override{
		Decoratetor::ExpressLove();
		addDecoration();
	}
private:
	void addDecoration(){
		std::cout << "我爱你到海枯石烂" << std::endl;
	}
};

// 实际修饰，B
class DecoratorB : public Decoratetor {
public:
	DecoratorB(Man* man) :Decoratetor(man) {};
	void ExpressLove() override {
		Decoratetor::ExpressLove();
		addDecoration();
	}
private:
	void addDecoration() {
		std::cout << "我送你车和房" << std::endl;
	}
};