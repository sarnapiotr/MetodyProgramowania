#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void inputData(int& count, std::string& itemsString, int& weight) {
    std::cout << "1. Pobierz dane z klawiatury\n";
    std::cout << "2. Pobierz dane z pliku wejscie.txt\n";
    std::cout << "Wybierz opcje: \n";

    int wybor;
    std::string dane = "";
    std::ifstream wejscie("wejscie.txt");
    std::cin >> wybor;
    std::cin.ignore();

    std::string temp = "";

    switch (wybor) {
    case(1):
        std::cout << "Podaj liczbe elementow: \n";
        std::getline(std::cin, temp);
        count = stoi(temp);

        std::cout << "Podaj n par liczb oddzielonych pojedynczymi spacjami, z ktorych pierwsza reprezentuje wage, a druga wartosc: \n";
        std::getline(std::cin, itemsString);

        std::cout << "Podaj wage plecaka: \n";
        std::getline(std::cin, temp);
        weight = stoi(temp);
        break;
    case(2):
        std::getline(wejscie, temp);
        count = stoi(temp);
        std::getline(wejscie, itemsString);
        std::getline(wejscie, temp);
        weight = stoi(temp);

        wejscie.close();
        break;
    default:
        std::cout << "Niepoprawny wybor\n";
        return;
    }
}

struct Item {
    int weight;
    int value;
};

void knapsackProblem(const int& count, const Item itemsArray[], const int& weight) {
    int** knapsackArray = new int*[count + 1];

    for (int i = 0; i <= count; i++) {
        knapsackArray[i] = new int[weight + 1] {0};
    }

    for (int i = 1; i <= weight; i++) {
        if (itemsArray[0].weight <= i) {
            knapsackArray[1][i] = itemsArray[0].value;
        }
    }

    for (int i = 1; i <= count; i++) {
        for (int j = 1; j <= weight; j++) {
            if (itemsArray[i - 1].weight <= j) {
                knapsackArray[i][j] = std::max(knapsackArray[i - 1][j], knapsackArray[i - 1][j - itemsArray[i - 1].weight] + itemsArray[i - 1].value);
            }
            else {
                knapsackArray[i][j] = knapsackArray[i - 1][j];
            }
        }
    }

    std::cout << knapsackArray[count][weight];

    for (int i = 0; i <= count; i++) {
        delete[] knapsackArray[i];
    }
    delete[] knapsackArray;
}

int main()
{
    std::cout << "Programowanie dynamicznie\n";

    int count;
    std::string itemsString = "";
    int weight;
    inputData(count, itemsString, weight);

    Item* itemsArray = new Item[count];
    std::istringstream stream(itemsString);
    for (int i = 0; i < count; i++) {
        stream >> itemsArray[i].weight >> itemsArray[i].value;
    }

    knapsackProblem(count, itemsArray, weight);

    delete[] itemsArray;

    return 0;
}
