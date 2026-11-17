cmake_minimum_required(VERSION 3.15)
project(AlgoRisk)

# Force the compiler to use Modern C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


find_package(spdlog REQUIRED)

# Include the FetchContent module
include(FetchContent)

# Declare the GoogleTest repository
FetchContent_Declare(
googletest
GIT_REPOSITORY https://github.com/google/googletest.git
GIT_TAG release-1.12.1
)

# Make GoogleTest available
FetchContent_MakeAvailable(googletest)

# Executable for Main Project
add_executable(AlgoRisk
src/cli/Menu.cpp
src/main.cpp
src/ForexAsset.cpp
src/GoldAsset.cpp
src/CryptoAsset.cpp
src/Trade.cpp
src/RiskValidator.cpp
src/TradeManager.cpp
)

# Executable for Unit Tests
add_executable(unit_tests
tests/Test_Forex_Asset.cpp
tests/Test_Crypto_Asset.cpp
tests/Test_Gold_Asset.cpp
tests/Test_RiskValidator.cpp
src/ForexAsset.cpp
src/CryptoAsset.cpp
src/GoldAsset.cpp
src/Trade.cpp
src/RiskValidator.cpp
src/TradeManager.cpp
)

# Link libraries
target_link_libraries(AlgoRisk PRIVATE spdlog::spdlog)
target_link_libraries(unit_tests PRIVATE gtest_main spdlog::spdlog)

# Specify include directories
target_include_directories(unit_tests PRIVATE include)
target_include_directories(AlgoRisk PRIVATE include)
