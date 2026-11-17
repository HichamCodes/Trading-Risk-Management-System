#include"TradeManager.hpp"
#include"RiskValidator.hpp"

TradeManager::TradeManager(std::shared_ptr<spdlog::logger>loggerPtr):m_logger(loggerPtr){}

void TradeManager::processTrade(const Trade& trade)const {

	m_logger->info("Starting Trade Processing...");

	try {

		Riskvalidator::validate(trade);
		m_logger->info("Trade validate successfuly!");

	}
	catch (const std::exception& caughtExeption) {

		m_logger->error("Trade Rejected! {}", caughtExeption.what());

		throw;


	}
}
