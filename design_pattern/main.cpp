#ifdef TEST_SIMPLE_FACTORY
#include "factory/factory.h"
#else
#include "factory_method/range_extender_factory.h"
#include "factory_method/wireless_router_factory.h"
#endif
#include "strategy/emotion.h"
#include "strategy/show.h"


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

int main()
{
#ifdef TEST_SIMPLE_FACTORY
	TestFactory();
#else
	TestFactoryMethod();
#endif
	TestStrategy();
	return 0;
}