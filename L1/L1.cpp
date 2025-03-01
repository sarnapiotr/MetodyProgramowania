#include <iostream>
#include <fstream>
#include <chrono>

std::ofstream wynik;

void lexicographical(int n, int k) {
    int* K = new int[k + 1];
    int* L = new int[k + 1];

    for (int i = 1; i <= k; i++) {
        K[i] = i;
        L[i] = n - k + i;

        wynik << K[i] << " ";
    }
    wynik << std::endl;

    while (K[1] != L[1]) {
        int i = k;

        if (K[i] < L[i]) {
            K[i] = K[i] + 1;
        }
        else {
            while (K[i] >= L[i]) {
                i = i - 1;
            }

            K[i] = K[i] + 1;

            for (int j = i + 1; j <= k; j++) {
                K[j] = K[j - 1] + 1;
            }
        }

        for (int i = 1; i <= k; i++) {
            wynik << K[i] << " ";
        }
        wynik << std::endl;
    }

    delete[] K;
    delete[] L;
}

void semba(int n){
    int k = 0;
    int* K = new int[n + 1];
    K[k] = 0;

    while (K[1] != n) {
        if (K[k] < n) {
            K[k + 1] = K[k] + 1;
            k++;
        }
        else {
            k--;
            K[k]++;
        }
        for (int i = 1; i <= k; i++) {
            wynik << K[i] << " ";
        }
        wynik << std::endl;
    }

    delete[] K;
}

int main()
{
    wynik.open("wynik.txt");

    std::cout << "Generacja (n,k)-kombinacji - algorytmy\n";
    std::cout << "1. Algorytm generacji kombinacji w rosnacym porzadku leksykograficznym\n";
    std::cout << "2. Algorytm Semby\n";
    std::cout << "Wybierz algorytm: \n";

    int wybor, n;
    std::cin >> wybor;

    auto start = std::chrono::high_resolution_clock::now();
    auto stop = start;

    switch (wybor) {
    case(1): {
        std::cout << "Podaj wielkosc zbioru:\n";
        std::cin >> n;
        int k;
        std::cout << "Podaj wielkosc podzbioru:\n";
        std::cin >> k;

        if (k > n || k < 1) {
            std::cout << "Niepoprawne dane wejsciowe\n";
            return -1;
        }

        start = std::chrono::high_resolution_clock::now();
        lexicographical(n, k);
        stop = std::chrono::high_resolution_clock::now();
        break;
        }

    case(2): {
        std::cout << "Podaj wielkosc zbioru:\n";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Niepoprawne dane wejsciowe\n";
            return -1;
        }

        start = std::chrono::high_resolution_clock::now();
        semba(n);
        stop = std::chrono::high_resolution_clock::now();
        break;
        }

    default: {
        std::cout << "Niepoprawny wybor\n";
        return -1;
        }
    }

    wynik.close();
    std::cout << "Wynik zostal zapisany do pliku wynik.txt\n";

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Czas dzialania algorytmu wynosi " << duration.count() << " mikrosekund";

    return 0;
}
