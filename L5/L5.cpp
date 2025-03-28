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

int getParent(int i) {
    return (i - 1) / 2;
}

void shiftUp(int* array, int childIndex) {
    while (array[childIndex] > array[getParent(childIndex)] && childIndex != 0) {
        int parentIndex = getParent(childIndex);
        int temp = array[parentIndex];
        array[parentIndex] = array[childIndex];
        array[childIndex] = temp;
        childIndex = parentIndex;
    }
}

void generateHeap(int* array, int n) {
    for (int i = 0; i < n; i++) {
        shiftUp(array, i);
    }
}

void sortNonDescending(int* array, int n) {
    int tempIndex = n;

    for (int i = 0; i < n; i++) {
        int temp = array[0];
        array[0] = array[tempIndex - 1];
        array[tempIndex - 1] = temp;
        tempIndex--;
        generateHeap(array, tempIndex);
    }
}

void sortNonAscending(int* array, int n) {
    sortNonDescending(array, n);

    for (int i = 0; i < n / 2; i++) {
        int temp = array[i];
        array[i] = array[n - 1 - i];
        array[n - 1 - i] = temp;
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
    generateHeap(array, n);

    std::cout << "1. Sortowanie niemalejace\n";
    std::cout << "2. Sortowanie nierosnace\n";
    std::cout << "Wybierz algorytm: \n";

    int choice;
    std::cin >> choice;

    std::cout << "Tablica po posortowaniu: \n";
    if (choice == 1) {
        sortNonDescending(array, n);
        printArray(array, n);

    }
    else if (choice == 2) {
        sortNonAscending(array, n);
        printArray(array, n);
    }
    else {
        std::cout << "Niepoprawny wybor\n";
        return -1;
    }

    delete[] array;
    return 0;
}
