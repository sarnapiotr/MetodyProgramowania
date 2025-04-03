#include <iostream>
#include <chrono>

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

void printArray(int* array, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void mergeSort(int* array, int left, int right) {

}

int main()
{
    std::srand(std::time(0));

    int n;
    auto start = std::chrono::high_resolution_clock::now();
    auto stop = start;

    std::cout << "Dziel i zwyciezaj\n";
    std::cout << "Podaj rozmiar tablicy do posortowania: \n";
    std::cin >> n;

    int* array = new int[n];
    generateRandomArray(array, n);
    std::cout << "Tablica przed posortowaniem: \n";
    printArray(array, n);

    std::cout << "Tablica po posortowaniu: \n";
    start = std::chrono::high_resolution_clock::now();
    mergeSort(array, 0, n);
    stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Czas dzialania algorytmu wynosi " << duration.count() << " mikrosekund\n";


    delete[] array;
    return 0;
}
