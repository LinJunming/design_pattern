#pragma once
#include <string>
#include <iostream>

class Phone {
public:
	void SetBoard(std::string board)
	{
		m_board.assign(board);
	}
	void SetCamera(std::string camera)
	{
		m_camera.assign(camera);
	}
	void SetShell(std::string shell)
	{
		m_shell.assign(shell);
	}
	void SetBrand(std::string brand)
	{
		m_brand.assign(brand);
	}
	void CheckInfo()
	{
		std::cout << "---------------------------------" << std::endl;
		std::cout << "           " << m_brand<< "           " << std::endl;
		std::cout << "Board: " << m_board << std::endl;
		std::cout << "Shell: " << m_shell << std::endl;
		std::cout << "Camera: " << m_camera << std::endl;
		std::cout << "---------------------------------" << std::endl;
	}
private:
	std::string m_camera;
	std::string m_board;
	std::string m_shell;
	std::string m_brand;
};


class PhoneBuilder {
public:
	PhoneBuilder() {
		m_phone = new Phone();
	};
	virtual ~PhoneBuilder() {
		delete m_phone;
	}; // 用户会用PhoneBuilder的指针指向具体的builder类，这样子去使用具体的buidler，所以析构函数需要是虚析构函数。
	Phone* GetPhone() {
		return m_phone;
	};
	virtual void SetPhoneCamera() = 0;
	virtual void SetPhoneBoard() = 0;
	virtual void SetPhoneShell() = 0;
	virtual void SetPhoneBrand() = 0;
private:
	Phone* m_phone;
};

class XiaoMiPhoneBuilder : public PhoneBuilder {
	// 各个零件的生产过程
public:
	void SetPhoneCamera() override {
		/*
		小米经过某某过程，从A厂商那里搞来了一批摄像头，此处省略。
		*/
		GetPhone()->SetCamera("A-Camera");
	}
	void SetPhoneBoard() override {
		/*
		小米经过某某过程，从A厂商那里搞来了一批主板，此处省略。
		*/
		GetPhone()->SetBoard("A-Board");
	}
	void SetPhoneShell() override {
		/*
		小米经过某某过程，从A厂商那里搞来了一批外壳，此处省略。
		*/
		GetPhone()->SetShell("A-Shell");
	}
	void SetPhoneBrand() override {
		/*
		小米贴标签
		*/
		GetPhone()->SetBrand("MI");
	}
};

class HuaweiPhoneBuilder : public PhoneBuilder {
	// 各个零件的生产过程
public:
	void SetPhoneCamera() override {
		/*
		华为经过某某过程，从C厂商那里搞来了一批摄像头，此处省略。
		*/
		GetPhone()->SetCamera("C-Camera");
	}
	void SetPhoneBoard() override {
		/*
		华为经过某某过程，从C厂商那里搞来了一批主板，此处省略。
		*/
		GetPhone()->SetBoard("C-Board");
	}
	void SetPhoneShell() override {
		/*
		华为经过某某过程，从C厂商那里搞来了一批外壳，此处省略。
		*/
		GetPhone()->SetShell("C-Shell");
	}
	void SetPhoneBrand() override {
		/*
		华为贴标签
		*/
		GetPhone()->SetBrand("Huawei");
	}
};


class Director {
public:
	Director(PhoneBuilder* phone_builder) :m_phone_builder(phone_builder){};
	void Construct() {
		std::cout << "开始组装..." << std::endl;
		std::cout << "装配主板" << std::endl;
		m_phone_builder->SetPhoneBoard();
		std::cout << "装配摄像头" << std::endl;
		m_phone_builder->SetPhoneCamera();
		std::cout << "装配外壳" << std::endl;
		m_phone_builder->SetPhoneShell();
		std::cout << "贴标签" << std::endl;
		m_phone_builder->SetPhoneBrand();
	}
private:
	PhoneBuilder* m_phone_builder;
};