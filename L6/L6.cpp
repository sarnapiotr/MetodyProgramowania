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

void merge(int* array, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int* leftArray = new int[leftSize];
    int* rightArray = new int[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = array[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArray[i] = array[mid + 1 + i];
    }

    int leftMergeIndex = 0;
    int rightMergeIndex = 0;
    int mergedIndex = left;

    while (leftMergeIndex < leftSize && rightMergeIndex < rightSize) {
        if (leftArray[leftMergeIndex] < rightArray[rightMergeIndex]) {
            array[mergedIndex] = leftArray[leftMergeIndex];
            leftMergeIndex++;
        }
        else {
            array[mergedIndex] = rightArray[rightMergeIndex];
            rightMergeIndex++;
        }

        mergedIndex++;
    }

    while (leftMergeIndex < leftSize) {
        array[mergedIndex] = leftArray[leftMergeIndex];
        leftMergeIndex++;
        mergedIndex++;

    }

    while (rightMergeIndex < rightSize) {
        array[mergedIndex] = rightArray[rightMergeIndex];
        rightMergeIndex++;
        mergedIndex++;

    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int* array, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
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
    mergeSort(array, 0, n - 1);
    stop = std::chrono::high_resolution_clock::now();
    printArray(array, n);

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Czas dzialania algorytmu wynosi " << duration.count() << " mikrosekund\n";


    delete[] array;
    return 0;
}
