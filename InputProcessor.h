#ifndef INPUT_PROCESSOR_H
#define INPUT_PROCESSOR_H

#include <fstream>
#include <cmath>
#include <vector>
#include <utility>

// Класс для обработки входных данных из файла
class InputProcessor {
public:
    InputProcessor(): itemCount(0) {};
    void allocateMemory();
    void clearData();
    ~InputProcessor() {clearData();};
    void readFile(const std::string& filename);
    void initializeMatrix();

    int getItemCount() const {return itemCount;};
    int getCapacity() const {return capacity;};
    std::vector<std::pair<int, int>>& getItems() {return items;};
    std::vector<std::vector<int>>& getMatrix() {return matrix;};

private:
    int itemCount; // Количество предметов
    int capacity; // Вместимость
    std::vector<std::pair<int, int>> items; // Вектор предметов (значение, вес)
    std::vector<std::vector<int>> matrix; // Матрица для динамического программирования
};

#endif // INPUT_PROCESSOR_H
