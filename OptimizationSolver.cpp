#include "OptimizationSolver.h"
#include <algorithm> // Для std::max

void OptimizationSolver::setData(int size, int volume, std::vector<std::vector<int>>& matrix, std::vector<std::pair<int, int>>& items) {
    this->clear();

    itemCount = size;
    capacity = volume;
    this->matrix = &matrix;
    this->items = &items;
    solution.resize(itemCount, 0);
}

void OptimizationSolver::clear() {
    itemCount = 0;
    capacity = 0;
    matrix = nullptr;
    items = nullptr;
    solution.clear();
    maxValue = 0;
}

void OptimizationSolver::solve() {
    if (itemCount <= 0 || capacity <= 0 || matrix == nullptr || items == nullptr)
        return;

    for (int i = 1; i <= itemCount; i++) {
        for (int j = 0; j <= capacity; j++) {
            if ((*items)[i - 1].second > j) {
                (*matrix)[i][j] = (*matrix)[i - 1][j];
            } else {
                (*matrix)[i][j] = std::max((*matrix)[i - 1][j], 
                (*matrix)[i - 1][j - (*items)[i - 1].second] + (*items)[i - 1].first);
            }
        }
    }

    maxValue = (*matrix)[itemCount][capacity];
    traceBack(itemCount, capacity);
}

void OptimizationSolver::traceBack(int i, int j) {
    if (i == 0) {
        return;
    }

    if ((*matrix)[i][j] != (*matrix)[i-1][j]) {
        solution[i-1] = 1; // Помечаем, что предмет был включен в решение
        traceBack(i-1, j - (*items)[i-1].second);
    } else {
        traceBack(i-1, j);
    }
}
