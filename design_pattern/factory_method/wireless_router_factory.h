#pragma once
#include "factory_method.h"

typedef class WirelessRouterFactory : public FactoryMethod {
public:
	WirelessRouterFactory() {};
	~WirelessRouterFactory() {};
	ProductHandle CreateProduct();
} WirelessRouterFactory;