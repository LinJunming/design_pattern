#include "range_extender_factory.h"

ProductHandle RangeExtenderFactory::CreateProduct()
{
	ProductHandle range_extender = nullptr;
	range_extender = (ProductHandle) new RangeExtender();
	return range_extender;
}