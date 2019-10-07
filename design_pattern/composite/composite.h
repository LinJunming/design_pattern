#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <list>

class Relation {
public:
	using RelationList = std::list<std::shared_ptr<Relation>>;
	Relation(std::string name) :m_name(name) {};
	virtual ~Relation() { std::cout << "Relation deconstructed." << std::endl; };
	virtual void Add(Relation* relation) = 0;
	virtual void Remove(std::string name) = 0;
	virtual void Display(int depth) = 0;
	const std::string& Name() {
		return m_name;
	}
protected:
	std::string m_name;
};

class Leader : public Relation{
public:
	Leader(std::string name) : Relation(name) {}; // 调用Relation类的构造函数初始化继承过来的m_name成员
	virtual ~Leader() { std::cout << "Leader [" << Name() <<"] is gone." << std::endl; };
	void Add(Relation* relation) override {
		std::shared_ptr<Relation> temp(relation);
		m_relations.push_back(temp);
	};

	void Remove(std::string name) override {
		RelationList::iterator it = m_relations.begin();
		while (it != m_relations.end()) {
			if ((*it).get()->Name() == name) {
				m_relations.erase(it);
				break;
			}
			it++;
		}
	};
	void Display(int depth) override{
		std::cout << Name() << std::endl;
		if (depth > 0) {
			RelationList::iterator it = m_relations.begin();
			while (it != m_relations.end()) {
				(*it).get()->Display(depth-1);
				it++;
			}
		}
	};
private:
	RelationList m_relations;
};

class Worker : public Relation {
public:
	Worker(std::string name) : Relation(name) {}; // 调用Relation类的构造函数初始化继承过来的m_name成员
	virtual ~Worker() { std::cout << "Worker [" << Name() << "] is gone." << std::endl; };

	void Add(Relation* relation) {
	};

	void Remove(std::string name) {
	};
	void Display(int depth) {
		std::cout << Name() << std::endl;
	};
};