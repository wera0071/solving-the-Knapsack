#ifndef OPTIMIZATION_SOLVER_H
#define OPTIMIZATION_SOLVER_H

#include <vector>
#include <utility>

// Класс для решения задачи оптимизации
class OptimizationSolver {
public:
    OptimizationSolver() : itemCount(0), capacity(0), maxValue(0) {}
    void setData(int size, int volume, std::vector<std::vector<int>>& matrix, std::vector<std::pair<int, int>>& items);
    void clear();
    ~OptimizationSolver() { clear(); }
    void solve();
    void traceBack(int i, int j);
    int getMaxValue() const { return maxValue; }
    std::vector<int> getSolution() const { return solution; }

private:
    int itemCount;
    int capacity;
    std::vector<std::vector<int>>* matrix;
    std::vector<std::pair<int, int>>* items;
    std::vector<int> solution;
    int maxValue;
};

#endif // OPTIMIZATION_SOLVER_H
