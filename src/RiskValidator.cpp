#include"RiskValidator.hpp"
#include"Exceptions.hpp"

void Riskvalidator::validate(const Trade& trade){



		if (trade.getRiskPercentage()  <= 0 || trade.getRiskPercentage() >= 5) {

			throw RiskLimitException("Risk must be between 0 and 5");


		}

		if (((trade.getTradeSide() == TradeSide::BUY) && trade.getStopLoss() >= trade.getEntryPrice())) {

			throw InvalidStopLossException("BUY,Stop Loss must be below Entry Price");


		}






		if	((( trade.getTradeSide() == TradeSide::SELL) && trade.getStopLoss() <= trade.getEntryPrice ())) {

			throw InvalidStopLossException("SELL,Stop Loss must be above Entry Price");


		}




}

