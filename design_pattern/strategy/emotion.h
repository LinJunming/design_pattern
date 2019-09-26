#pragma once
#include <iostream>

// 【策略模式可以用继承实现】
// 策略抽象类
typedef class Emotion {
public:
	virtual void ShowEmotion() = 0;
} Emotion;

// 具体策略：开心
typedef class Happy :public Emotion {
public:
	void ShowEmotion() override {
		std::cout << "I am happy!" << std::endl;
	};
};
// 具体策略：伤心
typedef class Sad :public Emotion {
public:
	void ShowEmotion() override {
		std::cout << "I am sad!" << std::endl;
	};
};

// 具体角色：机器人
class Robot{
// 策略初始化示例1：由调用者创建具体策略对象并传入指针。
// 角色引用的是策略对象指针，需负责释放
public:
	Robot(Emotion* emo){
		this->my_emotion_ = emo;
	}
	~Robot()
	{
		delete this->my_emotion_;
	}
	void Say() { this->my_emotion_->ShowEmotion(); };
private:
	Emotion* my_emotion_;
};

typedef enum {
	EMOTION_HAPPY,
	EMOTION_SAD
} EmotionType;

// 具体角色：机器人
class Poet {
// 策略初始化示例2：调用者传入具体的策略值，具体策略由角色自行创建。
// 角色引用的是策略对象指针，需负责释放
public:
	Poet(EmotionType emotion_type) {
		switch(emotion_type) {
		case EMOTION_HAPPY:
			this->my_emotion_ = new Happy();
			break;
		case EMOTION_SAD:
		default:
			this->my_emotion_ = new Sad();
			break;
		}
	}
	~Poet()
	{
		delete this->my_emotion_;
	}
	void Say() { this->my_emotion_->ShowEmotion(); };
private:
	Emotion* my_emotion_;
};

template <typename T>
// 具体角色：机器人
class Person {
// 策略初始化示例3：利用模板进行策略初始化
// 角色引用的是策略对象，不需要负责释放
public:
	Person() {}
	~Person() {}
	void Say() { 
		this->my_emotion_.ShowEmotion(); 
	}
private:
	T my_emotion_;
};
