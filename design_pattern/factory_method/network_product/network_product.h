#pragma once
#include <string>

typedef class NetworkProduct {
public:
	NetworkProduct();
	virtual ~NetworkProduct() {};
	void Info();
protected:
	std::string info_;
} NetworkProduct;
