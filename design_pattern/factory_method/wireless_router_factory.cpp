#include "wireless_router_factory.h"

ProductHandle WirelessRouterFactory::CreateProduct()
{
	ProductHandle range_extender = nullptr;
	range_extender = (ProductHandle) new WirelessRouter();
	return range_extender;
}