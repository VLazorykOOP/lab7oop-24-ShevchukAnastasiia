#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

// === Шаблон функції ===
template <typename T>
T findMin(T* arr, int size) {
    T min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

// === Спеціалізація для char* ===
template <>
char* findMin<char*>(char** arr, int size) {
    char* min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (strcmp(arr[i], min) < 0)
            min = arr[i];
    }
    return min;
}

// === Функція для випадкового заповнення ===
template <typename T>
void fillRandom(T* arr, int size);

// Спеціалізація для int
template <>
void fillRandom<int>(int* arr, int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 100;
}

// Спеціалізація для double
template <>
void fillRandom<double>(double* arr, int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = (rand() % 10000) / 100.0;
}

// === Тестування ===
int main() {
    srand(time(0));
    const int size = 5;

    // --- 1. int: з клавіатури ---
    int arr1[size];
    cout << "Vvedit " << size << " tsilykh chysel:\n";
    for (int i = 0; i < size; ++i)
        cin >> arr1[i];
    cout << "Min (int): " << findMin(arr1, size) << endl;

    // --- 2. double: з файлу ---
    ofstream fout("input.txt");
    for (int i = 0; i < size; ++i)
        fout << (rand() % 10000) / 100.0 << " ";
    fout.close();

    double arr2[size];
    ifstream fin("input.txt");
    for (int i = 0; i < size; ++i)
        fin >> arr2[i];
    fin.close();
    cout << "Min (double from file): " << findMin(arr2, size) << endl;

    // --- 3. char*: масив рядків ---
    char* arr3[] = {
        (char*)"banana",
        (char*)"apple",
        (char*)"cherry",
        (char*)"grape",
        (char*)"orange"
    };
    cout << "Min (char*): " << findMin(arr3, size) << endl;

    return 0;
}
