#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>
#include <sstream>
#include <stack>

std::ofstream wynik;

std::string inputData() {
    std::cout << "1. Pobierz dane z klawiatury\n";
    std::cout << "2. Pobierz dane z pliku wejscie.txt\n";
    std::cout << "Wybierz opcje: \n";

    int wybor;
    std::cin >> wybor;
    std::string dane;
    std::ifstream wejscie("wejscie.txt");

    switch (wybor) {
    case(1):
        std::cout << "Podaj dane wejsciowe: \n";
        std::cin.ignore();
        std::getline(std::cin, dane);
        return dane;
    case(2):
        std::getline(wejscie, dane);
        wejscie.close();
        return dane;
    default:
        std::cout << "Niepoprawny wybor\n";
        return "";
    }
}

bool isOperator(const std::string& token) {
    if (token.length() != 1) return false;
    char c = token[0];
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isParenthesis(const std::string& token) {
    if (token.length() != 1) return false;
    char c = token[0];
    return c == '(' || c == ')';
}

void calculateONP(std::string dane) {
    std::vector<std::string> daneWektor;
    std::istringstream stream(dane);
    std::string temp;

    while (stream >> temp) {
        daneWektor.push_back(temp);
    }

    std::stack<double> operands;

    for (int i = 0; i < daneWektor.size(); i++) {
        if (daneWektor[i] == "=") {
            break;
        }

        if (isdigit(daneWektor[i][0]) || (daneWektor[i][0] == '-' && isdigit(daneWektor[i][1]))) {
            operands.push(std::stod(daneWektor[i]));
            continue;
        }

        double b = operands.top();
        operands.pop();
        double a = operands.top();
        operands.pop();

        switch (daneWektor[i][0]) {
        case '+':
            operands.push(a + b);
            break;
        case '-':
            operands.push(a - b);
            break;
        case '*':
            operands.push(a * b);
            break;
        case '/':
            if (b != 0) {
                operands.push(a / b);
            }
            else {
                std::cout << "Dzielenie przez zero\n";
                return;
            }
            break;
        case '^':
            operands.push(std::pow(a, b));
            break;
        default:
            std::cout << "Nieznany operator\n";
            return;
        }
    }

    if (!operands.empty()) {
        wynik << operands.top();
    }

    std::cout << operands.top() << std::endl;
}

int getPriority(char c) {
    switch (c) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

std::string infixToONP(std::string dane) {
    std::vector<std::string> daneWektor;
    std::istringstream stream(dane);
    std::string temp;

    while (stream >> temp) {
        daneWektor.push_back(temp);
    }

    std::stack<char> operators;
    std::string ONP = "";

    for (int i = 0; i < daneWektor.size(); i++) {
        std::string token = daneWektor[i];

        if (token == "=") {
            continue;
        }
        else if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            ONP += token + " ";
            continue;
        }
        else if (isParenthesis(token)) {
            if (token == "(") {
                operators.push(token[0]);
            }
            else if (token == ")") {
                while (!operators.empty() && operators.top() != '(') {
                    ONP += operators.top();
                    ONP += " ";
                    operators.pop();
                }
                if (!operators.empty() && operators.top() == '(') {
                    operators.pop();
                }
                else {
                    std::cout << "Nieprawidłowe nawiasy\n";
                    return "";
                }
            }
        }
        else if (isOperator(token)) {
            char op = token[0];
            while (!operators.empty() && operators.top() != '(' &&
                ((op != '^' && getPriority(op) <= getPriority(operators.top())) ||
                    (op == '^' && getPriority(op) < getPriority(operators.top())))) {
                ONP += operators.top();
                ONP += " ";
                operators.pop();
            }
            operators.push(op);
        }
        else {
            std::cout << "Nieznany token: " << token << "\n";
            return "";
        }
    }

    while (!operators.empty()) {
        if (operators.top() == '(') {
            std::cout << "Nieprawidłowe nawiasy\n";
            return "";
        }
        ONP += operators.top();
        ONP += " ";
        operators.pop();
    }

    return ONP;
}

int main(){
    wynik.open("wynik.txt");

    std::cout << "ONP - zastosowanie stosu\n";
    std::cout << "1. Algorytm obliczania wartosci wyrazenia w postaci ONP\n";
    std::cout << "2. Algorytm przeksztalcenia wyrazenia do postaci ONP\n";
    std::cout << "3. Algorytm przeksztalcenia wyrazenia do postaci ONP i obliczenia wartosci wyrazenia w postaci ONP\n";
    std::cout << "Wybierz algorytm: \n";

    int wybor;
    std::cin >> wybor;

    auto start = std::chrono::high_resolution_clock::now();
    auto stop = start;
    std::string dane;

    switch (wybor) {
    case(1):
        dane = inputData();

        start = std::chrono::high_resolution_clock::now();
        calculateONP(dane);
        stop = std::chrono::high_resolution_clock::now();
        break;
    case(2):
        dane = inputData();

        start = std::chrono::high_resolution_clock::now();
        wynik << infixToONP(dane);
        stop = std::chrono::high_resolution_clock::now();
        std::cout << infixToONP(dane);
        break;
    case(3):
        dane = inputData();

        start = std::chrono::high_resolution_clock::now();
        calculateONP(infixToONP(dane));
        stop = std::chrono::high_resolution_clock::now();
        break;
    default:
        std::cout << "Niepoprawny wybor\n";
        return -1;
    }

    wynik.close();
    std::cout << "Wynik zostal zapisany do pliku wynik.txt\n";

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Czas dzialania algorytmu wynosi " << duration.count() << " mikrosekund";
    
    return 0;
}

//( ( 23 + 2 ) * 2 * ( 4 - 2 ) ) / ( 7 - 2 ) * 2 + 10 / 5 * 2 * ( 6 - 3 ) =
//( -3.5 + 4 ) * 2 ^ -1 =
