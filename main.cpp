#include "InputProcessor.h"
#include "OptimizationSolver.h"

#include <iostream>
#include <string>

int main() {
    InputProcessor inputProcessor;
    OptimizationSolver optimizationSolver;
    std::string filename;

    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    inputProcessor.readFile(filename);
    int itemCount = inputProcessor.getItemCount();
    int capacity = inputProcessor.getCapacity();
    auto& items = inputProcessor.getItems();
    auto& matrix = inputProcessor.getMatrix();

    optimizationSolver.setData(itemCount, capacity, matrix, items);
    optimizationSolver.solve();

    auto solution = optimizationSolver.getSolution();
    int maxValue = optimizationSolver.getMaxValue();

    std::cout << "Максимальная стоимость: " << maxValue << std::endl;
    std::cout << "Взятые предметы (индексы): ";
    for (size_t i = 0; i < solution.size(); ++i) {
        if (solution[i] == 1) {
            std::cout << i + 1 << " "; // Индексы начинаются с 1 для пользователя
        }
    }
    std::cout << std::endl;

    return 0;
}
