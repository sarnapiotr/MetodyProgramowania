#include <iostream>

int getRand(int min, int max) {
    int range = max - min + 1;
    int num = rand() % range + min;

    return num;
}

int* generateRandomArray(int n) {
    int* array = new int[n];

    for (int i = 0; i < n; i++) {
        array[i] = getRand(1, n);
    }

    return array;
}

int* generateHeap(int* array, int n) {

}

int* sortNonDescending(int* array, int n) {

}

int* sortNonAscending() {

}

int main()
{
    std::srand(std::time(0));

    int n;

    std::cout << "Sortowanie przez kopcowanie\n";
    std::cout << "Podaj rozmiar tablicy do posortowania: \n";
    std::cin >> n;
    int* array = generateRandomArray(n);
    array = generateHeap(array, n);

    std::cout << "1. Sortowanie niemalejace\n";
    std::cout << "2. Sortowanie nierosnace\n";
    std::cout << "Wybierz algorytm: \n";

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        array = sortNonDescending(array, n);
    }
    else if (choice == 2) {

    }
    else {
        std::cout << "Niepoprawny wybor\n";
        return -1;
    }


    return 0;
}
