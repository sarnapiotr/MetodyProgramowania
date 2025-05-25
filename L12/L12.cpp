#include <iostream>
#include <vector>
#include <fstream>

std::vector<int> getPrimeFactors(int number) {
    int temp = 2;
    std::vector<int> primeFactors;

    while (number != 1) {
        if (number % temp == 0) {
            number /= temp;
            primeFactors.push_back(temp);
        }
        else {
            temp++;
        }
    }

    return primeFactors;
}

std::vector<int> getUniquePrimeFactors(int number) {
    int temp = 2;
    std::vector<int> uniquePrimeFactors;

    while (number != 1) {
        if (number % temp == 0) {
            number /= temp;
            if (uniquePrimeFactors.empty() || uniquePrimeFactors.back() != temp) {
                uniquePrimeFactors.push_back(temp);
            }
        }
        else {
            temp++;
        }
    }

    return uniquePrimeFactors;
}

std::vector<int> generateLCG(const int& maxNumber) {
    int m = maxNumber + 1;
    int x0 = 0;

    std::vector<int> uniqueFactors = getUniquePrimeFactors(m);
    int c = 1;
    for (int factor : uniqueFactors) {
        c *= factor;
    }
    c += 1;

    std::vector<int> allFactors = getPrimeFactors(m);
    int a = 1;
    for (int factor : allFactors) {
        a *= factor;
    }
    a += 1;

    std::vector<int> pseudoRandomNumbers;
    pseudoRandomNumbers.push_back(x0);
    for (int i = 1; i < m; i++) {
        pseudoRandomNumbers.push_back((a * pseudoRandomNumbers[i - 1] + c) % m);
    }

    std::cout << "m = " << m << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "x0 = " << x0 << std::endl;

    return pseudoRandomNumbers;
}

int main()
{
    std::cout << "Generacja liczb pseudolosowych\n";
    std::cout << "Podaj maksymalna liczbe z zakresu: \n";

    int maxNumber{ 0 };
    std::cin >> maxNumber;

    std::vector<int> pseudoRandomNumbers = generateLCG(maxNumber);

    std::cout << "Wybierz sposob przedstawienia wyniku: \n";
    std::cout << "1. Wyswietl w konsoli\n";
    std::cout << "2. Zapisz w pliku wynik.txt\n";
    int choice{ 0 };
    std::cin >> choice;

    if (choice == 1) {
        for (int i : pseudoRandomNumbers) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
    else if (choice == 2) {
        std::ofstream wy("wynik.txt");

        if (!wy.is_open()) {
            std::cout << "Nie mozna otworzyc pliku wynik.txt";
            return -1;
        }

        for (int i : pseudoRandomNumbers) {
            wy << i << " ";
        }

        wy.close();

    }
    else{
        std::cout << "Niepoprawny wybor\n";
        return -1;
    }

    return 0;
}
