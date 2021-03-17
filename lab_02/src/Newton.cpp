//
// Created by denis on 25.02.2021.
//

#include "Newton.h"
#include "VectorUtils.h"
#include <utility>

Newton::Newton(std::vector<TaskData> inTaskData): m_vTaskData(std::move(inTaskData)) {
}

void Newton::FillDelta(std::vector<double> vCurrentDelta) {
    unsigned int deltaX = m_vChooseData.size() - vCurrentDelta.size() + 1;

    std::vector<double> vNewDelta;
    vNewDelta.reserve(vCurrentDelta.size() - 1);
    for (int i = 0; i < vCurrentDelta.size() - 1; i++) {
        if (m_vChooseData[i].x != m_vChooseData[i + deltaX].x)
            vNewDelta.push_back((vCurrentDelta[i] - vCurrentDelta[i + 1]) / (m_vChooseData[i].x - m_vChooseData[i + deltaX].x));
        else
            vNewDelta.push_back(m_vChooseData[i].y_p);
    }
    m_DeltaMatrix.push_back(vNewDelta);
}

double Newton::GetResult(double x) {
    std::vector<double> vYDelta;
    vYDelta.reserve(m_vChooseData.size());
    for (auto elem: m_vChooseData)
        vYDelta.push_back(elem.y);
    m_DeltaMatrix.clear();
    m_DeltaMatrix.push_back(vYDelta);
    while (m_DeltaMatrix.back().size() != 1)
        FillDelta(m_DeltaMatrix.back());

    double resNewton = 0;
    for (int i = 0; i < m_DeltaMatrix.size(); i++) {
        auto resTmp = m_DeltaMatrix[i][0];
        for (int j = 0; j < i; j++)
            resTmp *= x - m_vChooseData[j].x;
        resNewton += resTmp;
    }
    return resNewton;
}

double Newton::GetNewtonResult(double x, int powerApproximation) {
    m_vChooseData.clear();
    FillChooseData(x, powerApproximation);
    return GetResult(x);
}

void Newton::FillChooseData(double x, int powerApproximation) {
    std::vector<TaskData> vDeltaXAndData;
    for (auto elem: m_vTaskData) {
        vDeltaXAndData.push_back(elem);
        vDeltaXAndData.back().x = std::abs(x - elem.x);
    }
    auto copyData = m_vTaskData;
    while (m_vChooseData.size() != powerApproximation + 1) {
        auto findIndex = VectorUtils::GetVectorMinValue(vDeltaXAndData);
        m_vChooseData.push_back(copyData[findIndex]);
        vDeltaXAndData.erase(vDeltaXAndData.begin() + findIndex);
        copyData.erase(copyData.begin() + findIndex);
    }
    VectorUtils::Sort(m_vChooseData);
}

void Newton::UpdateTaskData(std::vector<TaskData> inTaskData) {
    m_vTaskData = std::move(inTaskData);
    m_vChooseData.clear();
}
