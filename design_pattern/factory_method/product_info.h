#pragma once
#include "network_product/network_product.h"
#include "range_extender/range_extender.h"
#include "wireless_router/wireless_router.h"


// 产品类型
typedef enum {
	RANGE_EXTENDER,
	WIRELESS_ROUTER
} ProductType;

typedef class NetworkProduct  *ProductHandle;