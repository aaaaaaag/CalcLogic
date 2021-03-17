//
// Created by denis on 27.02.2021.
//

#include "Approximation.h"
#include "Newton.h"
#include <utility>
#include <memory>

Approximation::Approximation(std::vector<std::vector<double>> vData): m_vData(std::move(vData)) {
}

double Approximation::FindResult(double searchX, double searchY, int power) {
    auto newton = std::make_shared<Newton>(std::vector<TaskData>());


    std::vector<double> vIndexes;
    for (int i = 0; i < m_vData.size(); i++)
    {
        newton->UpdateTaskData(GetTaskStringData(i));
        vIndexes.push_back(newton->GetNewtonResult(searchX, power));
    }

    std::vector<TaskData> finalData;
    finalData.reserve(vIndexes.size());
    for (int i = 0; i < vIndexes.size(); i++)
        finalData.emplace_back(i, vIndexes[i], 0);

    newton->UpdateTaskData(finalData);
    return newton->GetNewtonResult(searchY, power);
}

std::vector<TaskData> Approximation::GetTaskStringData(int index) {
    std::vector<TaskData> resV;
    resV.reserve(m_vData[0].size());
    for (int i = 0; i < m_vData[0].size(); i++)
        resV.emplace_back(i, m_vData[index][i], 0);
    return resV;
}
