#pragma once
#include "product_info.h"

// π§≥ß¿‡
class Factory
{
public:
	Factory() {};
	~Factory() {};
	ProductHandle CreateProduct(ProductType type);
};