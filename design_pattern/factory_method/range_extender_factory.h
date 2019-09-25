#pragma once
#include "factory_method.h"

typedef class RangeExtenderFactory : public FactoryMethod {
public:
	RangeExtenderFactory() {};
	~RangeExtenderFactory() {};
	ProductHandle CreateProduct();
}RangeExtenderFactory;