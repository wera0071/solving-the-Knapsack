# Определение компилятора
CXX = g++

# Определение флагов компиляции
CXXFLAGS = -std=c++11 -Wall

# Исходные файлы
SOURCES = main.cpp InputProcessor.cpp OptimizationSolver.cpp

# Объектные файлы
OBJECTS = $(SOURCES:.cpp=.o)

# Имя исполняемого файла
EXECUTABLE = optimization_app

# Правило по умолчанию
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Чистка проекта
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
