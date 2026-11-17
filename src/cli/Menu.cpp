#include <iostream>
#include <memory>
#include <limits>
#include <string>
#include <exception>
#include <iomanip>

#include "Menu.hpp"
#include "Trade.hpp"
#include "ForexAsset.hpp"
#include "RiskValidator.hpp"

// ==========================================
// 1. Read Valid Numeric Input
// ==========================================

double readNumber(const std::string& message)
{
double value;

while (true)
{
std::cout << message;
std::cin >> value;

if (!std::cin.fail())
return value;

std::cout << "Invalid input! Enter a number.\n";

std::cin.clear();
std::cin.ignore(
std::numeric_limits<std::streamsize>::max(), '\n'
);
}
}

// ==========================================
// 2. Display Main Menu
// ==========================================

void displayMenu()
{
int choice = 0;

do
{
std::cout << "\n========================================\n";
std::cout << " TRADING RISK MANAGEMENT SYSTEM\n";
std::cout << "========================================\n";
std::cout << "1. Calculate Custom Trade\n";
std::cout << "2. Run Demo Trade\n";
std::cout << "3. Exit\n";
std::cout << "========================================\n";

std::cout << "Choose an option: ";
std::cin >> choice;

if (std::cin.fail())
{
std::cin.clear();
std::cin.ignore(
std::numeric_limits<std::streamsize>::max(), '\n'
);

std::cout << "Invalid input!\n";
continue;
}

switch (choice)
{
case 1:
runCustomTrade();
break;

case 2:
runDemoTrade();
break;

case 3:
std::cout << "\nThank you for using AlgoRisk!\n";
break;

default:
std::cout << "Invalid choice! Try again.\n";
}

} while (choice != 3);
}

// ==========================================
// 3. Run Demo Trade
// ==========================================

void runDemoTrade()
{
Trade trade(
1,
1000.0,
1.0,
1.0850,
1.0800,
"ICT_SMC",
TradeStatus::OPEN,
TradeSide::BUY
);

calculateAndDisplay(trade);
}

// ==========================================
// 4. Run Custom Trade
// ==========================================

void runCustomTrade()
{
std::cout << "\n========== CUSTOM TRADE ==========\n";

double balance = readNumber("Account Balance: ");
double risk = readNumber("Risk Percentage: ");
double entry = readNumber("Entry Price: ");
double stopLoss = readNumber("Stop Loss: ");

std::string strategy;

std::cout << "Strategy Name: ";
std::cin >> strategy;

int sideChoice;

std::cout << "\nSelect Trade Side:\n";
std::cout << "1. BUY\n";
std::cout << "2. SELL\n";
std::cout << "Your choice: ";

std::cin >> sideChoice;

if (std::cin.fail())
{
std::cin.clear();
std::cin.ignore(
std::numeric_limits<std::streamsize>::max(), '\n'
);

std::cout << "Invalid trade side!\n";
return;
}

TradeSide side;

if (sideChoice == 1)
{
side = TradeSide::BUY;
}
else if (sideChoice == 2)
{
side = TradeSide::SELL;
}
else
{
std::cout << "Invalid trade side!\n";
return;
}

Trade trade(
2,
balance,
risk,
entry,
stopLoss,
strategy,
TradeStatus::OPEN,
side
);

calculateAndDisplay(trade);
}

// ==========================================
// 5. Calculate and Display Trade Result
// ==========================================

void calculateAndDisplay(const Trade& trade)
{
try
{
Riskvalidator::validate(trade);

auto forexAsset = std::make_unique<ForexAsset>();

double lotSize = forexAsset->calculateLotSize(trade);

std::cout << std::fixed << std::setprecision(2);

std::cout << "\n========== TRADE RESULT ==========\n";

std::cout << "Account Balance: "
<< trade.getAccountBalance() << '\n';

std::cout << "Risk: "
<< trade.getRiskPercentage() << "%\n";

std::cout << "Entry Price: "
<< trade.getEntryPrice() << '\n';

std::cout << "Stop Loss: "
<< trade.getStopLoss() << '\n';

std::cout << "Strategy: "
<< trade.getStrategyName() << '\n';

std::cout << "Trade Side: "
<< (trade.getTradeSide() == TradeSide::BUY
? "BUY" : "SELL") << '\n';

std::cout << "Lot Size: "
<< lotSize << '\n';

std::cout << "==================================\n";
}
catch (const std::exception& e)
{
std::cout << "\nTrade Error: " << e.what() << '\n';
}
}
