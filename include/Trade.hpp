#pragma once
#include<string>

enum class TradeSide {
	UNKNOWN,
	BUY,
	SELL
};
enum class TradeStatus {
	UNKNOWN,
	PENDING,
	OPEN,
	CLOSED

};
class Trade {
  
private:

	int id{ 0 };
	double accountBalance{ 0.0 };
	double entryPrice{ 0.0 };
	double riskPercentage{ 0.0 };
	double stopLoss{ 0.0 };
	TradeStatus tradeStatus{ TradeStatus::UNKNOWN };
	TradeSide tradeSide{TradeSide::UNKNOWN};
	std::string strategyName{ "" };

public:
	Trade(int id, double accountBalance,
		double riskPercentage, double entryPrice, double stopLoss,
		const std::string& strategyName, TradeStatus tradeStatus, TradeSide  tradeSide);

	int getId()const;
	double getAccountBalance()const;
	double getEntryPrice()const;
	double getRiskPercentage()const;
	double getStopLoss()const;
	TradeStatus getTradeStatus()const;
	TradeSide getTradeSide()const;
	const std::string& getStrategyName()const;
	void setRiskPercentage(double riskPercentage);
	void  setStopLoss(double stopLoss);
	void  setTradeStatus(TradeStatus tradeStatus);
		
};