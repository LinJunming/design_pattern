#pragma once
#include <iostream>

// ������ģʽ�����ü̳�ʵ�֡�
// ���Գ�����
typedef class Emotion {
public:
	virtual void ShowEmotion() = 0;
} Emotion;

// ������ԣ�����
typedef class Happy :public Emotion {
public:
	void ShowEmotion() override {
		std::cout << "I am happy!" << std::endl;
	};
};
// ������ԣ�����
typedef class Sad :public Emotion {
public:
	void ShowEmotion() override {
		std::cout << "I am sad!" << std::endl;
	};
};

// �����ɫ��������
class Robot{
// ���Գ�ʼ��ʾ��1���ɵ����ߴ���������Զ��󲢴���ָ�롣
// ��ɫ���õ��ǲ��Զ���ָ�룬�踺���ͷ�
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

// �����ɫ��������
class Poet {
// ���Գ�ʼ��ʾ��2�������ߴ������Ĳ���ֵ����������ɽ�ɫ���д�����
// ��ɫ���õ��ǲ��Զ���ָ�룬�踺���ͷ�
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
// �����ɫ��������
class Person {
// ���Գ�ʼ��ʾ��3������ģ����в��Գ�ʼ��
// ��ɫ���õ��ǲ��Զ��󣬲���Ҫ�����ͷ�
public:
	Person() {}
	~Person() {}
	void Say() { 
		this->my_emotion_.ShowEmotion(); 
	}
private:
	T my_emotion_;
};
