#pragma once
#include <list>
#include <iostream>
#include <memory>


// �۲��߽ӿ�
class Star;
class Observer {
public:
	virtual ~Observer() {}
	void Observe(Star* subject) {
		m_subject = subject;
	}
	virtual void Update() = 0;

	Star* GetSubject() {
		return m_subject;
	}
private:
	Star* m_subject;
};


// ���ǣ����۲��ߣ�
class Star {
public:
	Star(std::string name): m_name(name){}
	~Star() { std::cout << __func__ << "������" << std::endl; }
	using ObserverList = std::list<std::shared_ptr<Observer>>;
	void Add(Observer* observer) {
		observer->Observe(this); // �ù۲��߹۲���

		std::shared_ptr<Observer> tmp(observer);
		m_observers.push_back(tmp); // �ѹ۲��߼����ҵ��б�
	}
	void NotifyAllObservers(std::string action) {
		std::cout << m_name << action << std::endl;
		if (m_observers.size() > 0) {
			ObserverList::iterator it = m_observers.begin();
			while (it != m_observers.end()) {
				(*it).get()->Update();
				it++;
			}
		}
	}
	std::string Name() {
		return m_name;
	}
private:
	ObserverList	m_observers;
	std::string		m_name;
};

// ˮ��
class PaidPosters : public Observer {
public:
	~PaidPosters() { std::cout << __func__ << ": Bye Bye." << std::endl; }
	void Update() override {
		std::cout << "PaidPosters: ";
		std::cout << this->GetSubject()->Name().c_str() << "����־����������" << std::endl;
	}
};
// �ڷ�
class AntiFans : public Observer {
public:
	~AntiFans() { std::cout << __func__ << ": Bye Bye." << std::endl; }
	void Update() override {
		std::cout << "AntiFans: ";
		std::cout << this->GetSubject()->Name().c_str() << "��lj��" << std::endl;
	}
};
// ·��
class PassBy : public Observer {
public:
	~PassBy() { std::cout << __func__ << ": Bye Bye." << std::endl; }
	void Update() override {
		std::cout << "PassBy: ";
		std::cout << this->GetSubject()->Name().c_str() << "��Ȼ�в��õĵط��������ò�˵�����˵����������������ŵ�ġ�" << std::endl;
	}
};