#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

// Функция для проверки, отсортирован ли вектор
bool isSorted(const std::vector<int>& arr) {
    return std::is_sorted(arr.begin(), arr.end());
}

// Функция для построения пирамиды (heapify)
void heapify(std::vector<int>& arr, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Находим наибольший элемент среди корня, левого и правого потомков
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // Если наибольший элемент не является текущим, меняем их местами и рекурсивно вызываем heapify
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

// Функция для сортировки вектора с использованием пирамиды
void heapSort(std::vector<int>& arr) {
    int size = arr.size();

    // Строим начальную пирамиду
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(arr, size, i);
    }

    // Извлекаем элементы из пирамиды и перестраиваем ее
    for (int i = size - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Функция для создания вектора с случайными числами в указанном диапазоне
std::vector<int> createRandomVector(int size, int min_val, int max_val) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (max_val - min_val + 1) + min_val;
    }
    return arr;
}

int main() {
    // Ввод количества элементов от пользователя
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    // Создание вектора с случайными числами от 1 до 100
    std::vector<int> arr = createRandomVector(n, 1, 100);

    // Замер времени начала выполнения сортировки
    clock_t start_time = clock();

    // Вызов функции пирамидальной сортировки
    heapSort(arr);

    // Замер времени окончания выполнения сортировки
    clock_t end_time = clock();

    // Вычисление и вывод времени выполнения программы в миллисекундах
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Время выполнения: " << elapsed_time * 1000 << " миллисекунд" << std::endl;

    // Проверка, упорядочен ли вектор, и вывод результата
    std::cout << "Вектор " << (isSorted(arr) ? "упорядочен" : "не упорядочен") << std::endl;

    return 0;
}
