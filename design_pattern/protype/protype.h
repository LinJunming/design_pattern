#pragma once
#include <string>
#include <iostream>

// 原型模式的父类
class Protype {
public:
	virtual Protype* clone() = 0;// 一定要实现克隆函数
	virtual void show() = 0;
};

class Rocket {
public:
	Rocket(int fuel, int size, int direction, int load, bool is_manned, double first_launch_time,
		std::string manufatuer, std::string country_code) :
		m_fuel(fuel),
		m_size(size),
		m_direction(direction),
		m_load(load),
		m_is_manned(is_manned),
		m_first_launch_time(first_launch_time),
		m_manufactuer(manufatuer),
		m_country_code(country_code)
		{};
	~Rocket() {};
	Rocket(const Rocket& rocket) 
	{
		this->m_fuel = rocket.m_fuel;
		this->m_size = rocket.m_size;
		this->m_direction = rocket.m_direction;
		this->m_load = rocket.m_load;
		this->m_is_manned = rocket.m_is_manned;
		this->m_first_launch_time = rocket.m_first_launch_time;
		this->m_manufactuer = rocket.m_manufactuer;
		this->m_country_code = rocket.m_country_code;
	}

	Protype* Clone(std::string country_code);
	void Show();
private:
	int				m_fuel;
	int				m_size;
	int				m_direction;
	int				m_load;
	bool			m_is_manned;
	double			m_first_launch_time;
	std::string		m_manufactuer;
	std::string		m_country_code;
};

Protype* Rocket::Clone(std::string country_code)
{
	Rocket* clone_rocket = new Rocket(*this);
	if (clone_rocket == nullptr)
		return nullptr;
	clone_rocket->m_country_code.assign(country_code);
	return (Protype*)clone_rocket;

}

void Rocket::Show()
{
	std::cout << "I am super rocket made in " << this->m_country_code << "!" << std::endl;
}