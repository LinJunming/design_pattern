#include <string>
#include <iostream>
#include "network_product.h"

NetworkProduct::NetworkProduct()
{
	info_ = "Unknown Network Product";
}

void NetworkProduct::Info() {
	std::cout << info_ << std::endl;
}