#include <iostream>
#include <cstring>
using namespace std;

// === Шаблон сортування (бульбашкове) ===
template <typename T>
void sortArray(T* arr, int size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Спеціалізація для char*
template <>
void sortArray<char*>(char** arr, int size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (strcmp(arr[j], arr[j + 1]) > 0)
                swap(arr[j], arr[j + 1]);
}

// === Шаблон бінарного пошуку ===
template <typename T>
int binarySearch(T* arr, int size, T key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Спеціалізація для char*
template <>
int binarySearch<char*>(char** arr, int size, char* key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid], key);
        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// === Тестування ===
int main() {
    const int size = 5;

    // 1. int
    int arr1[] = {23, 5, 18, 9, 12};
    sortArray(arr1, size);
    int key1 = 9;
    cout << "int: Index of " << key1 << " = " << binarySearch(arr1, size, key1) << endl;

    // 2. double
    double arr2[] = {5.5, 1.2, 8.8, 3.3, 2.1};
    sortArray(arr2, size);
    double key2 = 3.3;
    cout << "double: Index of " << key2 << " = " << binarySearch(arr2, size, key2) << endl;

    // 3. char*
    char* arr3[] = {
        (char*)"grape",
        (char*)"apple",
        (char*)"banana",
        (char*)"orange",
        (char*)"cherry"
    };
    sortArray(arr3, size);
    char key3[] = "banana";
    int result = binarySearch(arr3, size, key3);
    if (result != -1)
        cout << "char*: Index of \"" << key3 << "\" = " << result << endl;
    else
        cout << "char*: \"" << key3 << "\" not found\n";

    return 0;
}
