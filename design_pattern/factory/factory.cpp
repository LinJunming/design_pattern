#include "product_info.h"
#include "factory.h"

ProductHandle Factory::CreateProduct(ProductType type) {
	ProductHandle product_handle = nullptr;
	// 此处可以改进，不要和具体的产品类耦合。不过暂时先这么写了。
	switch (type){
	case RANGE_EXTENDER:
		product_handle = (ProductHandle) new RangeExtender();
		break;
	case WIRELESS_ROUTER:
	default:
		product_handle = (ProductHandle) new WirelessRouter();
		break;
	}
	return product_handle;
}