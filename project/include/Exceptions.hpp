#pragma once
#include<stdexcept>
#include<string>


class RiskLimitException :public std::invalid_argument {
public:

	RiskLimitException(const std::string& message) : std::invalid_argument(message) {}



};
class InvalidStopLossException :public std::runtime_error {
public:

	InvalidStopLossException(const std::string& message) : std::runtime_error(message) {}


};
