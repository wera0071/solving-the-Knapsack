#include <iostream>
#include "InputProcessor.h"
#include <algorithm> // Для std::max

void InputProcessor::allocateMemory() {
    // Резервируем место для матрицы
    matrix.resize(itemCount + 1, std::vector<int>(capacity + 1, 0));
}

void InputProcessor::clearData() {
    // Просто очищаем векторы, память освобождать не нужно
    items.clear();
    matrix.clear();
    itemCount = 0;
    capacity = 0;
}

void InputProcessor::readFile(const std::string& filename) {
    this->clearData();

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return;
    }

    file >> itemCount >> capacity;
    items.reserve(itemCount);

    for(int i = 0; i < itemCount; i++) {
        int value, weight;
        file >> value >> weight;
        items.emplace_back(value, weight);
    }

    file.close();
    allocateMemory();
}


