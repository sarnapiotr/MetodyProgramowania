#include <iostream>

void generacjaPodzialow(int n) {
    int* a = new int[n];
    int* b = new int[n];
    int c;

    for (int i = 0; i < n; i++) {
        a[i] = 1;
        b[i] = 1;
    }

    while (a[0] == 1) {
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
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n;
    std::cout << "Podaj wielkosc zbioru: \n";
    std::cin >> n;
    generacjaPodzialow(n);

    return 0;
}
