#pragma once
#include <iostream>
#include <functional>
#include <string>

// ������ģʽ�����ú���ָ��ʵ�֡�
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
	// ʾ��1���ô�ͳ��C����ָ��
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
	// ʾ��1����C++ �� std::function<>
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