#pragma once
#include <iostream>
class InstructionBook {
	public:
		virtual void IntroduceFunction() = 0;
};

class MedicineInstructionBook : public InstructionBook {
public:
	void IntroduceFunction() override;
};

void MedicineInstructionBook::IntroduceFunction() {
	std::cout << "This is a medicine instruction book." << std::endl;
}

class ToyInstructionBook : public InstructionBook {
public:
	void IntroduceFunction() override;
};

void ToyInstructionBook::IntroduceFunction() {
	std::cout << "This is a toy instruction book." << std::endl;
}