#include<cmath>
#include"CryptoAsset.hpp"

double CryptoAsset::calculateLotSize(const Trade& trade)const {

	const double priceDistance = std::abs(trade.getEntryPrice() - trade.getStopLoss());
	if (priceDistance <= 0) {

		return 0.0;
	}
	return ((trade.getAccountBalance() * trade.getRiskPercentage()) / 100) / priceDistance ;
}