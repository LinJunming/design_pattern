#pragma once
#include <list>
#include <iostream>
#include <memory>


// 观察者接口
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


// 明星（被观察者）
class Star {
public:
	Star(std::string name): m_name(name){}
	~Star() { std::cout << __func__ << "不火了" << std::endl; }
	using ObserverList = std::list<std::shared_ptr<Observer>>;
	void Add(Observer* observer) {
		observer->Observe(this); // 让观察者观察我

		std::shared_ptr<Observer> tmp(observer);
		m_observers.push_back(tmp); // 把观察者加入我的列表
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

// 水军
class PaidPosters : public Observer {
public:
	~PaidPosters() { std::cout << __func__ << ": Bye Bye." << std::endl; }
	void Update() override {
		std::cout << "PaidPosters: ";
		std::cout << this->GetSubject()->Name().c_str() << "好励志啊，嘤嘤嘤" << std::endl;
	}
};
// 黑粉
class AntiFans : public Observer {
public:
	~AntiFans() { std::cout << __func__ << ": Bye Bye." << std::endl; }
	void Update() override {
		std::cout << "AntiFans: ";
		std::cout << this->GetSubject()->Name().c_str() << "好lj啊" << std::endl;
	}
};
// 路人
class PassBy : public Observer {
public:
	~PassBy() { std::cout << __func__ << ": Bye Bye." << std::endl; }
	void Update() override {
		std::cout << "PassBy: ";
		std::cout << this->GetSubject()->Name().c_str() << "虽然有不好的地方，但不得不说，看人得两看，他还是有优点的。" << std::endl;
	}
};