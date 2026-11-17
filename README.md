# AlgoRisk - Automated Trade Risk & Lot Size Calculator

#### Video https://www.loom.com/share/51be90fe35db4a59ad41c7d91953cd30

## Description
AlgoRisk is a C++20 trading risk management system designed to validate trade execution parameters and automatically calculate precise lot sizes for financial assets, including Forex, Cryptocurrencies, and Gold.

In live market execution, manual position sizing often leads to human error and improper risk exposure. AlgoRisk prevents this by enforcing strict risk boundaries (e.g., maximum risk percentage per trade, valid Stop-Loss placement relative to BUY/SELL orders), raising custom exceptions for invalid trades, and applying dynamic lot-size formulas tailored to each asset's contract rules.

---

## Technical Features
* Modern C++20 Standard: Leverages smart pointers (std::unique_ptr), RAII, and object-oriented dynamic dispatch.
* Polymorphic Asset Architecture: Extensible base Asset class with specialized implementations for ForexAsset, CryptoAsset, and GoldAsset.
* Strict Validation Rules: Automated pre-trade validation to ensure risk parameters stay strictly within defined risk thresholds.
* Automated Unit Testing: Full test suite powered by GoogleTest (gtest) covering valid calculations and edge-case exceptions.
* Structured System Logging: Integrated spdlog library for structured, real-time diagnostic logs.
* Build Automation: Configured with CMake for modular source compilation and external dependency management.

---

## File Structure & Overview

`text
AlgoRisk/
├── CMakeLists.txt # CMake build configuration
├── include/ # Header files
│ ├── Exceptions.hpp # Custom exception classes
│ ├── Asset.hpp # Base abstract class for financial assets
│ ├── ForexAsset.hpp # Forex asset implementation
│ ├── CryptoAsset.hpp # Crypto asset implementation
│ ├── GoldAsset.hpp # Gold asset implementation
│ ├── Trade.hpp # Trade structure and state properties
│ ├── RiskValidator.hpp # Static validation engine for risk limits
│ └── TradeManager.hpp # Execution coordinator & spdlog wrapper
├── src/ # Core implementation files
│ ├── main.cpp # Main program demonstration
│ ├── ForexAsset.cpp
│ ├── CryptoAsset.cpp
│ ├── GoldAsset.cpp
│ ├── Trade.cpp
│ ├── RiskValidator.cpp
│ └── TradeManager.cpp
└── tests/ # GoogleTest suite
├── Test_Forex_Asset.cpp
├── Test_Crypto_Asset.cpp
├── Test_Gold_Asset.cpp
└── Test_RiskValidator.cpp

### Key Modules:
* **`Exceptions.hpp`**: Defines domain exceptions (`RiskLimitException`, `InvalidStopLossException`) derived from standard C++ runtime/argument errors.
* **`RiskValidator.hpp`**: Ensures strict validation (e.g., verifying Buy trades have Stop Loss below Entry, Sell trades have Stop Loss above Entry, and risk percentages remain within configured limits).
* **`TradeManager.hpp`**: Coordinates trade checking, manages logging output via `spdlog`, and computes position parameters cleanly.

---

## Key Design Choices

1. **Smart Pointers Over Raw Pointers:** Using `std::unique_ptr` ensures memory safety, clean lifecycle management, and zero memory leaks without manual destruction.
2. **Exception-Driven Validation:** Rather than returning simple `bool` flags, throwing explicit custom exceptions ensures invalid trades are safely caught and handled at the top execution layer.
3. **Decoupled Unit Testing:** Decoupled business logic from `main.cpp` into isolated components, allowing 100% automated test coverage with GoogleTest.

---

## Prerequisites & Building

### Requirements
* C++20 compatible compiler (GCC/G++)
* CMake v3.15+
* Make
* `spdlog` development headers (`libspdlog-dev`)

### Installation & Build Steps

1. Install dependencies (Linux/CS50 Codespace):
bash
sudo apt update && sudo apt install -y build-essential cmake libspdlog-dev

2. Compile the project:
bash
mkdir -p build && cd build
cmake ..
make

3. Run unit tests:
bash
./unit_tests

4. Run the demo application:
bash
./AlgoRisk
`
