//
// Created by denis on 25.02.2021.
//

#ifndef LAB_05_VECTORUTILS_H
#define LAB_05_VECTORUTILS_H

#include <vector>
#include "TaskData.h"
#include "algorithm"

bool comp(TaskData first, TaskData second)
{
    return first.x < second.x;
}

class VectorUtils
{
public:

    static void Sort(std::vector<TaskData>& inVector);

    static int GetVectorMinValue(std::vector<TaskData>& inVector);
};

int VectorUtils::GetVectorMinValue(std::vector<TaskData>& inVector) {
    auto min = inVector[0];
    int indexMin = 0;
    for (int i = 0; i < inVector.size(); i++) {
        if (inVector[i].x < min.x) {
            min = inVector[i];
            indexMin = i;
        }
    }
    return indexMin;
}

void VectorUtils::Sort(std::vector<TaskData> &inVector) {
    std::sort(inVector.begin(), inVector.end(), comp);
}

#endif //LAB_05_VECTORUTILS_H
