//
// Created by maxforce01 on 03.12.2019.
//

#include <string>
#include <iostream>
using namespace std;

class Util{
public:
    static int enterInteger() {
        while (true) {
            string num;
            std::getline(std::cin >> std::ws, num);
            int id = atoi(num.c_str());
            if (id > 0) {
                return id;
            }
            std::cout << "Invalid value" << std::endl;
        }
    }

    static double enterDouble() {
        while (true) {
            string num;
            std::getline(std::cin >> std::ws, num);
            double id = atoi(num.c_str());
            if (id > 0) {
                return id;
            }
            std::cout << "Invalid value" << std::endl;
        }
    }

    static long enterLong() {
        while (true) {
            string num;
            std::getline(std::cin >> std::ws, num);
            long id = atoi(num.c_str());
            if (id > 0) {
                return id;
            }
            std::cout << "Invalid value" << std::endl;
        }
    }
};