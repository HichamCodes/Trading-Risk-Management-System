#include<gtest/gtest.h>
#include<memory>
#include"ForexAsset.hpp"
#include"Trade.hpp"


TEST(ForexAssetTest, calculateLotSize){

	Trade trade(1, 1000.0, 1.0, 1.0850, 1.0800, "ICT_SMC", TradeStatus::OPEN, TradeSide::BUY);

	auto forexAsset = std::make_unique<ForexAsset>();

	double calculateLot = forexAsset->calculateLotSize(trade);

	double expectedLot = 0.02;

	EXPECT_NEAR(calculateLot, expectedLot, 0.00001);

	}