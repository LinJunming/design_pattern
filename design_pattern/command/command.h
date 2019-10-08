#pragma once
#include <list>
#include <iostream>
#include <string>

class Executer {
public:
	virtual void Do() = 0;
};

class Swimmer :public Executer {
public:
	~Swimmer() { std::cout << "Swimmer is gone." << std::endl; }
	void Do() {
		std::cout << "Swimmer is swimming." << std::endl;
	}
};

class Jogger :public Executer {
public:
	~Jogger() { std::cout << "Jogger is gone." << std::endl; }
	void Do() {
		std::cout << "Jogger is jogging." << std::endl;
	}
};

class Command {
public:
	Command(Executer* executer) :m_executer(executer) {}
	virtual ~Command() {
		delete m_executer;
	};
	void ExecCmd() {
		m_executer->Do();
	}
private:
	Executer* m_executer;
};

class Swim : public Command
{
public:
	Swim() :Command((Executer*)new Swimmer()) {}
};

class Run : public Command
{
public:
	Run() :Command((Executer*)new Jogger()) {}
};

class CommandWaiter {
public:
	void Add(Command* command) {
		m_commands.push_back(command);
	}
	void Remove(Command* command) {
		m_commands.remove(command);
	}
	void Notify() {
		std::list<Command*>::iterator it = m_commands.begin();
		while (it != m_commands.end()) {
			(*it)->ExecCmd();
			it++;
		}
		m_commands.clear();
		std::cout << "命令全执行了，请重新添加" << std::endl;
	}
private:
	std::list<Command*> m_commands;
};