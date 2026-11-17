#pragma once
#include"Trade.hpp"

class Asset {

public:
	virtual ~Asset() = default;
	virtual double calculateLotSize(const Trade& trade)const = 0;


};