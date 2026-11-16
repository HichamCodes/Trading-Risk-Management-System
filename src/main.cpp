#include<iostream>
#include<memory>
#include"ForexAsset.hpp"
#include"Trade.hpp"

int main() {

	Trade trade(1, 1000.0, 1.0, 1.0850, 1.0800, "ICT_SMC", TradeStatus::OPEN, TradeSide::BUY);

	auto forexAsset =std::make_unique<ForexAsset>();

	std::cout <<"Lot Size is:"<< forexAsset->calculateLotSize(trade) << "\n";

	return 0;
}
