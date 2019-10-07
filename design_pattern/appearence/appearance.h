#pragma once
#include <string>
#include <iostream>

// ��װ����
class Marshaller {
public:
	void Marshall() {
		std::cout << "[" << __func__ << "]: " << "Hey, there is something need sending." << std::endl;
	};
};

// ������
class Sender {
public:
	void Send() {
		std::cout << "[" << __func__ << "]: " << "I have sent the request." << std::endl;
	};
};

// ������
class Receiver {
public:
	void Receive() {
		std::cout << "[" << __func__ << "]: " << "I receive somthing." << std::endl;
	};
};

// ��������
class Analyser {
public:
	void Analyse() {
		std::cout << "[" <<__func__ << "]: " << "Hey, there is something need displaying." << std::endl;
	};
};

// ���û��ľ���һ������
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