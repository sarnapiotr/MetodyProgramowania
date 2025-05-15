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
    Node* leftChild;
    Node* rightChild;

    Node(char val, int freq) : value(val), frequency(freq), leftChild(nullptr), rightChild(nullptr) {}
};

void sortNodeVector(std::vector<Node*>& nodeVector) {
    for (size_t i = 0; i < nodeVector.size(); i++) {
        for (size_t j = i + 1; j < nodeVector.size(); j++) {
            if (nodeVector[j]->frequency < nodeVector[i]->frequency) {
                std::swap(nodeVector[i], nodeVector[j]);
            }
        }
    }
}

void huffmanCoding(std::vector<Node*>& nodeVector) {
    while (nodeVector.size() > 1) {
        sortNodeVector(nodeVector);

        Node* left = nodeVector[0];
        Node* right = nodeVector[1];

        Node* parent = new Node('\0', left->frequency + right->frequency);
        parent->leftChild = left;
        parent->rightChild = right;

        nodeVector.erase(nodeVector.begin(), nodeVector.begin() + 2);
        nodeVector.push_back(parent);
    }
}

void printHuffmanCoding(Node* root, std::string code = "") {
    if (!root) return;

    if (root->value != '\0') {
        std::cout << root->value << " : " << code << std::endl;
    }

    printHuffmanCoding(root->leftChild, code + "0");
    printHuffmanCoding(root->rightChild, code + "1");
}

void deleteNodeVector(Node* root) {
    if (!root) return;
    deleteNodeVector(root->leftChild);
    deleteNodeVector(root->rightChild);
    delete root;
}

int main()
{
    std::cout << "Algorytmy zachlanne\n";
    
    std::string inputString = "";
    inputData(inputString);
    
    std::vector<Node*> nodeVector;
    std::istringstream stream(inputString);

    char value;
    int frequency;
    while (stream >> value >> frequency) {
        nodeVector.push_back(new Node(value, frequency));
    }

    huffmanCoding(nodeVector);
    printHuffmanCoding(nodeVector[0]);
    deleteNodeVector(nodeVector[0]);

    return 0;
}
