
#include<gtest/gtest.h>
#include"RiskValidator.hpp"
#include"Exceptions.hpp"
#include"Trade.hpp"


TEST(riskvalidatorTest,validBuyTrade_ShouldNotThrow) {

	Trade trade(1, 1000.0, 1.0, 1.0850, 1.0800, "ICT_SMC", TradeStatus::OPEN, TradeSide::BUY);

	Riskvalidator validator;
	EXPECT_NO_THROW(validator.validate(trade));

}
TEST(riskvalidatorTest, validSellTrade_ShouldNotThrow) {

	Trade trade(1, 1000.0, 1.0, 1.0850, 1.0900, "ICT_SMC", TradeStatus::OPEN, TradeSide::SELL);

	Riskvalidator validator;
	EXPECT_NO_THROW(validator.validate(trade));
}
TEST(riskvalidatorTest, riskAboveMax_ShouldThrow) {

	Trade trade(1, 1000.0, 15.0, 1.0850, 1.0800, "ICT_SMC", TradeStatus::OPEN, TradeSide::BUY);

	Riskvalidator validator;
	EXPECT_THROW(validator.validate(trade), RiskLimitException);
}


TEST(riskvalidatorTest, riskZero_ShouldThrow) {

	Trade trade(1, 1000.0, 0.0, 1.0850, 1.0800, "ICT_SMC", TradeStatus::OPEN, TradeSide::BUY);
	Riskvalidator validator;
	EXPECT_THROW(validator.validate(trade), RiskLimitException);

}
TEST(riskvalidatorTest, riskNegative_ShouldThrow) {

	Trade trade(1, 1000.0, -5.0, 1.0850, 1.0800, "ICT_SMC", TradeStatus::OPEN, TradeSide::BUY);

	Riskvalidator validator;
	EXPECT_THROW(validator.validate(trade), RiskLimitException);


}
TEST(riskvalidatorTest, TradeBuyStopLossEqualEntryPrice_ShouldThrow) {

	Trade trade(1, 1000.0, 2.0, 1.0800, 1.0800, "ICT_SMC", TradeStatus::OPEN, TradeSide::BUY);

	Riskvalidator validator;
	EXPECT_THROW(validator.validate(trade), InvalidStopLossException);


}
TEST(riskvalidatorTest, TradeBuyStopLossAboveEntryPrice_ShouldThrow) {

	Trade trade(1, 1000.0, 2.0, 1.0800, 1.0850, "ICT_SMC", TradeStatus::OPEN, TradeSide::BUY);

	Riskvalidator validator;
	EXPECT_THROW(validator.validate(trade), InvalidStopLossException);


}
TEST(riskvalidatorTest, TradeSellStopLossEqualEntryPrice_ShouldThrow) {

	Trade trade(1, 1000.0, 2.0, 1.0800, 1.0800, "ICT_SMC", TradeStatus::OPEN, TradeSide::SELL);

	Riskvalidator validator;
	EXPECT_THROW(validator.validate(trade), InvalidStopLossException);


}
TEST(riskvalidatorTest, TradeSellEntryPriceAboveStopLoss_ShouldThrow) {

	Trade trade(1, 1000.0, 2.0, 1.0850, 1.0800, "ICT_SMC", TradeStatus::OPEN, TradeSide::SELL);

	Riskvalidator validator;
	EXPECT_THROW(validator.validate(trade), InvalidStopLossException);


}
