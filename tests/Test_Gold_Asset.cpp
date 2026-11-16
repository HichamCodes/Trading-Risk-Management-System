#include<gtest/gtest.h>
#include<memory>
#include"GoldAsset.hpp"
#include"Trade.hpp"


TEST(GoldAssetTest, calculateLotSize) {

	Trade trade(1, 10000.0, 1.0, 2000.0, 1990.0, "ICT_SMC", TradeStatus::OPEN, TradeSide::BUY);

	auto goldAsset = std::make_unique<GoldAsset>();

	double calculateLot = goldAsset->calculateLotSize(trade);

	double expectedLot = 0.1;

	EXPECT_NEAR(calculateLot, expectedLot, 0.0001);

}