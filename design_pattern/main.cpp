#ifdef TEST_SIMPLE_FACTORY
#include "factory/factory.h"
#else
#include "factory_method/range_extender_factory.h"
#include "factory_method/wireless_router_factory.h"
#endif
#include "strategy/emotion.h"
#include "strategy/show.h"
#include "adapter/stack.h"
#include "adapter/queue.h"
#include "singleton/singleton.h"


#ifdef TEST_SIMPLE_FACTORY
// ����ģʽ�Ĳ��Ժ���
void TestFactory()
{
	Factory* factory = new Factory();
	RangeExtender *range_extender = (RangeExtender*)factory->CreateProduct(RANGE_EXTENDER);
	WirelessRouter *wireless_router = (WirelessRouter*)factory->CreateProduct(WIRELESS_ROUTER);

	if (range_extender != nullptr) {
		range_extender->Info();
	}
	if (wireless_router != nullptr) {
		wireless_router->Info();
	}
	// pause
	getchar();
	delete factory;
	delete range_extender;
	delete wireless_router;
}
#else
void TestFactoryMethod()
{
	// ��������ģʽ��ʹ���Ϻͼ򵥹����Ĳ�֮ͬ����
	// ����Ҫ������Ʒ���͡�������������ϲ����Ҫ֪�����幤����Ķ��塣
	RangeExtenderFactory* range_extender_factory = new RangeExtenderFactory();
	WirelessRouterFactory* wireless_router_factory = new WirelessRouterFactory();


	RangeExtender *range_extender = (RangeExtender*)range_extender_factory->CreateProduct();
	WirelessRouter *wireless_router = (WirelessRouter*)wireless_router_factory->CreateProduct();

	if (range_extender != nullptr) {
		range_extender->Info();
	}
	if (wireless_router != nullptr) {
		wireless_router->Info();
	}
	// pause
	getchar();

	delete range_extender_factory;
	delete wireless_router_factory;
	delete range_extender;
	delete wireless_router;
}
#endif

void TestStrategy()
{
	// ���ڼ̳�ʵ��
	Robot* happy_robot = new Robot(new Happy());
	Robot* sad_robot = new Robot(new Sad());
	Poet* happy_poet = new Poet(EMOTION_HAPPY);
	Poet* sad_poet = new Poet(EMOTION_SAD);
	Person<Happy> *happy_person = new Person<Happy>;
	Person<Sad> *sad_person = new Person<Sad>;

	// ���ں���ָ��ʵ��
	Boy* boy = new Boy(NormalShow);
	Girl* girl = new Girl(AbnormalShow);

	happy_robot->Say();
	sad_robot->Say();
	happy_poet->Say();
	sad_poet->Say();
	happy_person->Say();
	sad_person->Say();
	boy->Show();
	girl->Show();

	getchar();

	delete happy_robot;
	delete sad_robot;
	delete happy_poet;
	delete sad_poet;
	delete happy_person;
	delete sad_person;
	delete boy;
	delete girl;
}


void TestAdapter()
{
	Stack<int> *s = new Stack<int>;
	s->Push(1);
	s->Push(2);
	std::cout << "Expected 2: " << s->Top() << std::endl;
	s->Pop();
	s->Push(4);
	std::cout << "Expected 4: " << s->Top() << std::endl;
	s->Pop();
	std::cout << "Expected 1: " << s->Top() << std::endl;
	s->Pop();
	std::cout << "Expected 0: " << s->Size() << std::endl;
	getchar();

	Queue<int> *q = new Queue<int>;
	q->PushBack(1);
	q->PushBack(2);
	std::cout << "Expected 1: " << q->Front() << std::endl;
	q->PopFront();
	q->PushBack(4);
	std::cout << "Expected 2: " << q->Front() << std::endl;
	q->PopFront();
	std::cout << "Expected 4: " << q->Front() << std::endl;
	q->PopFront();
	std::cout << "Expected 0: " << q->Size() << std::endl;
	getchar();

}

void TestSingleton()
{
	Singleton *singleton_a = Singleton::GetInstance();
	singleton_a->hello();

	SingletonT *singleton_b = SingletonT::GetInstance();
	singleton_b->hello();

	getchar();
}

int main()
{
#ifdef TEST_SIMPLE_FACTORY
	TestFactory();
#else
	TestFactoryMethod();
#endif
	TestStrategy();
	TestAdapter();
	TestSingleton();
	return 0;
}