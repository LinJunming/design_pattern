#pragma once
#include <string>
#include <iostream>

// 组装数据
class Marshaller {
public:
	void Marshall() {
		std::cout << "[" << __func__ << "]: " << "Hey, there is something need sending." << std::endl;
	};
};

// 发送者
class Sender {
public:
	void Send() {
		std::cout << "[" << __func__ << "]: " << "I have sent the request." << std::endl;
	};
};

// 接收者
class Receiver {
public:
	void Receive() {
		std::cout << "[" << __func__ << "]: " << "I receive somthing." << std::endl;
	};
};

// 解析数据
class Analyser {
public:
	void Analyse() {
		std::cout << "[" <<__func__ << "]: " << "Hey, there is something need displaying." << std::endl;
	};
};

// 给用户的就是一个窗口
class Window {
public:
	void Display()
	{
		std::cout << "This is data returned.<===============" << std::endl;
	}
	void ClickButton() {
		std::cout << "Button clicked.===============>" << std::endl;
		m_marshaller.Marshall();
		m_sender.Send();
		m_receiver.Receive();
		m_analyser.Analyse();
		this->Display();
	}
private:
	Analyser m_analyser;
	Receiver m_receiver;
	Sender m_sender;
	Marshaller m_marshaller;
};