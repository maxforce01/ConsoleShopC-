cmake_minimum_required(VERSION 3.15)
project(ConsoleShop_2019)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConsoleShop_2019 main.cpp main/commands/DeleteItemCommand.h main/core/Util.h main/commands/UpdateItemCommand.h main/commands/InvalidCommand.h main/commands/SaveProductIntoBucket.h main/commands/ShowBucketCommand.h main/service/OrderService.h main/commands/BuyProductsCommand.h main/commands/AllOrdersCommand.h)