#include <iostream>

class grafLosowy {
private:
	int liczbaWierzcholkow;
	int liczbaKrawedzi;
	bool czySkierowany;
	bool czyWazony;

public:
	grafLosowy() {
		std::cout << "Podaj ilosc wierzcholkow: \n";
		std::cin >> liczbaWierzcholkow;
		std::cout << "Podaj ilosc krawedzi: \n";
		std::cin >> liczbaKrawedzi;
		std::cout << "Czy graf ma byc skierowany? 1 jesli tak, 0 jesli nie\n";
		std::cin >> czySkierowany;
		std::cout << "Czy graf ma byc wazony? 1 jesli tak, 0 jesli nie\n";
		std::cin >> czyWazony;
	}
};

int main() {
	std::cout << "Generacja grafow\n";
	std::cout << "1. Algorytm generacji grafu losowego\n";
	std::cout << "2. Algorytm R-MAT\n";
	std::cout << "Wybierz algorytm: \n";

	int wybor;
	std::cin >> wybor;

	if (wybor == 1) {
		grafLosowy graf = grafLosowy();
	}
	else if (wybor == 2) {
		//R-MAT
	}
	else {
		std::cout << "Niepoprawny wybor\n";
		return -1;
	}

	return 0;
}
