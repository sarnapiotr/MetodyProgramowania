#include <iostream>

int getRand(int min, int max) {
    int range = max - min + 1;
    int num = rand() % range + min;

    return num;
}

void generateRandomArray(int* array, int n) {
    for (int i = 0; i < n; i++) {
        array[i] = getRand(1, n);
    }
}

void shiftDown(int* array, int tempRange, int rootIndex, bool max) {
    int largestIndex = rootIndex;
    int leftIndex = 2 * rootIndex + 1;
    int rightIndex = leftIndex + 1;

    if (leftIndex < tempRange && ((max && array[leftIndex] > array[largestIndex]) || (!max && array[leftIndex] < array[largestIndex]))) {
        largestIndex = leftIndex;
    }
    if (rightIndex < tempRange && ((max && array[rightIndex] > array[largestIndex]) || (!max && array[rightIndex] < array[largestIndex]))) {
        largestIndex = rightIndex;
    }

    if (largestIndex != rootIndex) {
        std::swap(array[rootIndex], array[largestIndex]);
        shiftDown(array, tempRange, largestIndex, max);
    }
}

void generateHeap(int* array, int tempRange, bool max) {
    for (int i = tempRange / 2 - 1; i >= 0; i--) {
        shiftDown(array, tempRange, i, max);
    }
}

void sortNonDescending(int* array, int n) {
    for (int i = 0; i < n; i++) {
        int tempRange = n - i - 1;
        std::swap(array[0], array[tempRange]);
        generateHeap(array, tempRange, true);
    }
}

void sortNonAscending(int* array, int n) {
    for (int i = 0; i < n; i++) {
        int tempRange = n - i - 1;
        std::swap(array[0], array[tempRange]);
        generateHeap(array, tempRange, false);
    }
}

void printArray(int* array, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::srand(std::time(0));

    int n;

    std::cout << "Sortowanie przez kopcowanie\n";
    std::cout << "Podaj rozmiar tablicy do posortowania: \n";
    std::cin >> n;

    int* array = new int[n];
    generateRandomArray(array, n);
    std::cout << "Tablica przed posortowaniem: \n";
    printArray(array, n);

    std::cout << "1. Sortowanie niemalejace\n";
    std::cout << "2. Sortowanie nierosnace\n";
    std::cout << "Wybierz algorytm: \n";

    int choice;
    std::cin >> choice;

    std::cout << "Tablica po posortowaniu: \n";
    if (choice == 1) {
        generateHeap(array, n, true);
        sortNonDescending(array, n);
        printArray(array, n);

    }
    else if (choice == 2) {
        generateHeap(array, n, false);
        sortNonAscending(array, n);
        printArray(array, n);
    }
    else {
        std::cout << "Niepoprawny wybor\n";
        delete[] array;
        return -1;
    }

    delete[] array;
    return 0;
}
