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
	}; // �û�����PhoneBuilder��ָ��ָ������builder�࣬������ȥʹ�þ����buidler����������������Ҫ��������������
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
	// �����������������
public:
	void SetPhoneCamera() override {
		/*
		С�׾���ĳĳ���̣���A�������������һ������ͷ���˴�ʡ�ԡ�
		*/
		GetPhone()->SetCamera("A-Camera");
	}
	void SetPhoneBoard() override {
		/*
		С�׾���ĳĳ���̣���A�������������һ�����壬�˴�ʡ�ԡ�
		*/
		GetPhone()->SetBoard("A-Board");
	}
	void SetPhoneShell() override {
		/*
		С�׾���ĳĳ���̣���A�������������һ����ǣ��˴�ʡ�ԡ�
		*/
		GetPhone()->SetShell("A-Shell");
	}
	void SetPhoneBrand() override {
		/*
		С������ǩ
		*/
		GetPhone()->SetBrand("MI");
	}
};

class HuaweiPhoneBuilder : public PhoneBuilder {
	// �����������������
public:
	void SetPhoneCamera() override {
		/*
		��Ϊ����ĳĳ���̣���C�������������һ������ͷ���˴�ʡ�ԡ�
		*/
		GetPhone()->SetCamera("C-Camera");
	}
	void SetPhoneBoard() override {
		/*
		��Ϊ����ĳĳ���̣���C�������������һ�����壬�˴�ʡ�ԡ�
		*/
		GetPhone()->SetBoard("C-Board");
	}
	void SetPhoneShell() override {
		/*
		��Ϊ����ĳĳ���̣���C�������������һ����ǣ��˴�ʡ�ԡ�
		*/
		GetPhone()->SetShell("C-Shell");
	}
	void SetPhoneBrand() override {
		/*
		��Ϊ����ǩ
		*/
		GetPhone()->SetBrand("Huawei");
	}
};


class Director {
public:
	Director(PhoneBuilder* phone_builder) :m_phone_builder(phone_builder){};
	void Construct() {
		std::cout << "��ʼ��װ..." << std::endl;
		std::cout << "װ������" << std::endl;
		m_phone_builder->SetPhoneBoard();
		std::cout << "װ������ͷ" << std::endl;
		m_phone_builder->SetPhoneCamera();
		std::cout << "װ�����" << std::endl;
		m_phone_builder->SetPhoneShell();
		std::cout << "����ǩ" << std::endl;
		m_phone_builder->SetPhoneBrand();
	}
private:
	PhoneBuilder* m_phone_builder;
};