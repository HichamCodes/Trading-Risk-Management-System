#pragma once
#include"Asset.hpp"

class ForexAsset :public Asset {

private:

	static constexpr double FOREX_CONTRACT_SIZE = 100000.0;

public:

	 double calculateLotSize(const Trade& trade)const override;


};