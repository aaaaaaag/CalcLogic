//
// Created by denis on 27.02.2021.
//

#ifndef LAB_02_APPROXIMATION_H
#define LAB_02_APPROXIMATION_H

#include "vector"
#include "TaskData.h"

class Approximation {
public:

    explicit Approximation(std::vector<std::vector<double>> vData);

    double FindResult(double searchX, double searchY, int power);

private:


    std::vector<TaskData> GetTaskStringData(int index);

    std::vector<std::vector<double>> m_vData;

};


#endif //LAB_02_APPROXIMATION_H
