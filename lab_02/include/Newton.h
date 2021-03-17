//
// Created by denis on 25.02.2021.
//

#ifndef LAB_05_NEWTON_H
#define LAB_05_NEWTON_H

#include <vector>
#include "TaskData.h"

class Newton {
public:

    explicit Newton(std::vector<TaskData> inTaskData);

    double GetNewtonResult(double x, int powerApproximation);

    void UpdateTaskData(std::vector<TaskData> inTaskData);

private:

    void FillChooseData(double x, int powerApproximation);

    double GetResult(double x);

    void FillDelta(std::vector<double> vCurrentDelta);

    std::vector<TaskData> m_vChooseData;

    std::vector<TaskData> m_vTaskData;

    std::vector<std::vector<double>> m_DeltaMatrix;
};

#endif //LAB_05_NEWTON_H
