#pragma once
#include"Asset.hpp"

class GoldAsset :public Asset {
private:

	static constexpr double GOLD_CONTRACT_SIZE = 100.0;

public:
	double calculateLotSize(const Trade& trade)const override;

	
};