#pragma once
#include <iostream>
#include <functional>
#include <string>

// 【策略模式可以用函数指针实现】
void NormalShow(std::string str)
{
	std::cout << str << ":Normal Show." << std::endl;
}

void AbnormalShow(std::string str)
{
	std::cout << str << ":Abnormal Show." << std::endl;
}

class Boy {
public:
	// 示例1：用传统的C函数指针
	typedef void (*Function)(std::string);
	Boy(Function func) {
		show = func;
	}
	~Boy() {}
	void Show() {
		show("Boy");
	}
private:
	Function show;
};

class Girl {
public:
	// 示例1：用C++ 的 std::function<>
	typedef std::function<void(std::string)> Function;
	Girl(Function func) {
		show = func;
	}
	~Girl() {}
	void Show() {
		show("Girl");
	}
private:
	Function show;
};