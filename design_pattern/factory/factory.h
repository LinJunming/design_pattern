#pragma once
#include "product_info.h"

// ������
class Factory
{
public:
	Factory() {};
	~Factory() {};
	ProductHandle CreateProduct(ProductType type);
};