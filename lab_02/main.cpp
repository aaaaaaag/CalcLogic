#include <iostream>
#include <cmath>
#include "iomanip"
#include "TaskData.h"
#include "Newton.h"
#include "Approximation.h"

int main() {


    std::vector<std::vector<double>> vData;
    for (int i = 0; i < 5; i++) {
        std::vector<double> vStr;
        vStr.reserve(5);
        for (int j = 0; j < 5; j++)
            vStr.push_back(pow(i, 2) + pow(j, 2));
        vData.push_back(vStr);
    }

    auto approximation = std::make_unique<Approximation>(vData);
    for (int n = 1; n < 4; n++)
        std::cout << "power: " << n << "   Result: " << approximation->FindResult(3.15, 2.25, n) << std::endl;

    return 0;
}
