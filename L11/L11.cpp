#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void inputData(std::string& inputString) {
    std::cout << "1. Podaj dane z klawiatury\n";
    std::cout << "2. Pobierz dane z pliku wejscie.txt\n";
    std::cout << "Wybierz opcje: \n";

    int wybor;
    std::cin >> wybor;

    std::ifstream wejscie("wejscie.txt");
    std::cin.ignore();

    switch (wybor) {
    case(1):
        std::cout << "Podaj pary oddzielone pojedynczymi spacjami, z ktorych pierwsza reprezentuje znak, a druga czestotliwosc jego wystepowania: \n";
        std::getline(std::cin, inputString);

        break;
    case(2):
        std::getline(wejscie, inputString);
        wejscie.close();

        break;
    default:
        std::cout << "Niepoprawny wybor\n";
        return;
    }
}

struct Node {
    char value;
    int frequency;
};

void sortNodeVector(std::vector<Node>& nodeVector) {
    for (int i = 0; i < nodeVector.size(); i++) {
        for (int j = 0; j < nodeVector.size(); j++) {
            if (nodeVector[j].frequency > nodeVector[i].frequency) {
                Node tempNode = nodeVector[i];
                nodeVector[i] = nodeVector[j];
                nodeVector[j] = tempNode;
            }
        }
    }
}

void huffmanCoding(std::vector<Node>& nodeVector) {
    while (!nodeVector.empty()) {
        sortNodeVector(nodeVector);
    }
    
}

int main()
{
    std::cout << "Algorytmy zachlanne\n";
    
    std::string inputString = "";
    inputData(inputString);
    
    std::vector<Node> nodeVector;
    std::istringstream stream(inputString);

    char value;
    int frequency;
    while (stream >> value >> frequency) {
        nodeVector.push_back({ value, frequency });
    }

    huffmanCoding(nodeVector);

    return 0;
}
