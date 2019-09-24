#include "product_info.h"
#include "factory.h"

ProductHandle Factory::CreateProduct(ProductType type) {
	ProductHandle product_handle = nullptr;
	// �˴����ԸĽ�����Ҫ�;���Ĳ�Ʒ����ϡ�������ʱ����ôд�ˡ�
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