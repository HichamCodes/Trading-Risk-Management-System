#include"Trade.hpp"

Trade::Trade(int id, double accountBalance,
	double riskPercentage,  double entryPrice, double stopLoss,
	const std::string& strategyName, TradeStatus tradeStatus, TradeSide  tradeSide):id(id), accountBalance(accountBalance),
	 riskPercentage(riskPercentage), entryPrice(entryPrice), stopLoss(stopLoss),
	strategyName(strategyName), tradeStatus(tradeStatus), tradeSide(tradeSide){}

int Trade::getId()const {

	return id;
}
double  Trade::getAccountBalance()const {

	return accountBalance;
}
double  Trade::getEntryPrice()const {

	return entryPrice;
}
double  Trade::getRiskPercentage()const {

	return riskPercentage;
}
double  Trade::getStopLoss()const {

	return stopLoss;
}
TradeStatus  Trade::getTradeStatus()const {

	return tradeStatus;
}
TradeSide  Trade::getTradeSide()const {

	return tradeSide;

}
const std::string& Trade::getStrategyName()const {

	return strategyName;
}
void  Trade::setRiskPercentage(double newRiskPercentage) {

	riskPercentage = newRiskPercentage;

}
void   Trade::setStopLoss(double newStopLoss) {

	stopLoss = newStopLoss;
}
void   Trade::setTradeStatus(TradeStatus newTradeStatus) {

	tradeStatus = newTradeStatus;
}
