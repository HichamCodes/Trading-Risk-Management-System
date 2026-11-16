#pragma once
#include<spdlog/spdlog.h>
#include<memory>
#include"Trade.hpp"

class TradeManager {

private:

	std::shared_ptr<spdlog::logger>m_logger;

public: 

	TradeManager(std::shared_ptr<spdlog::logger>loggerPtr);
	void processTrade(const Trade& trade)const;


};