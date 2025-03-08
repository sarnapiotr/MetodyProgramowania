#include <iostream>
#include <fstream>
#include <chrono>

std::ofstream wynik;

void generacjaPodzialow(int n) {
    int* a = new int[n];
    int* b = new int[n];
    int c;

    for (int i = 0; i < n; i++) {
        a[i] = 1;
        b[i] = 1;
    }

    while (true) {
        c = n;

        while (a[c] == n || a[c] > b[c]) {
            c--;
        }

        if (c == 0) {
            return;
        }

        a[c]++;

        for (int i = c + 1; i < n; i++) {
            a[i] = 1;
            if (a[i - 1] >= b[i - 1]) {
                b[i] = a[i - 1];
            }
            else {
                b[i] = b[i - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            wynik << a[i] << " ";
        }
        wynik << std::endl;
    }
}

int main()
{
    wynik.open("wynik.txt");
    
    int n;
    auto start = std::chrono::high_resolution_clock::now();
    auto stop = start;

    std::cout << "Generacja podzialow zbioru - algorytm\n";
    std::cout << "Podaj wielkosc zbioru: \n";
    std::cin >> n;

    if (n <= 1) {
        std::cout << "Niepoprawne dane wejsciowe\n";
        return -1;
    }

    start = std::chrono::high_resolution_clock::now();
    generacjaPodzialow(n);
    stop = std::chrono::high_resolution_clock::now();

    wynik.close();
    std::cout << "Wynik zostal zapisany do pliku wynik.txt\n";

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Czas dzialania algorytmu wynosi " << duration.count() << " mikrosekund";

    return 0;
}
