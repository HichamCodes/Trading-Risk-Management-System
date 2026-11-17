#pragma once
#include"Asset.hpp"

class CryptoAsset :public Asset {

public:

	double calculateLotSize(const Trade& trade)const override;


};