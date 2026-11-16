#include<gtest/gtest.h>
#include<memory>
#include"CryptoAsset.hpp"
#include"Trade.hpp"


TEST(CryptoAssetTest, calculateLotSize) {

	Trade trade(1, 10000.0, 2.0, 60000.0, 58000.0, "ICT_SMC", TradeStatus::OPEN, TradeSide::BUY);

	auto cryptoAsset = std::make_unique<CryptoAsset>();

	double calculateLot = cryptoAsset->calculateLotSize(trade);

	double expectedLot = 0.1;

	EXPECT_NEAR(calculateLot, expectedLot, 0.0001);

}