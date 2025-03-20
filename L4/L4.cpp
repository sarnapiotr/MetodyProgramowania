#include <iostream>

int getRand(int min, int max) {
	int range = max - min + 1;
	int num = rand() % range + min;

	return num;
}

class grafLosowy {
private:
	int liczbaWierzcholkow;
	int liczbaKrawedzi;
	bool czySkierowany;
	bool czyWazony;
	int m = 0;
	int** macierzGrafu;

public:
	grafLosowy() {
		do {
			std::cout << "Podaj ilosc wierzcholkow: \n";
			std::cin >> liczbaWierzcholkow;
		} while (liczbaWierzcholkow <= 0);

		do {
			std::cout << "Czy graf ma byc skierowany? Wpisz 1 jesli tak, 0 jesli nie: \n";
			std::cin >> czySkierowany;
		} while (czySkierowany != 0 && czySkierowany != 1);

		int maxKrawedzi;
		if (czySkierowany) {
			maxKrawedzi = liczbaWierzcholkow * (liczbaWierzcholkow - 1);
		}
		else {
			maxKrawedzi = (liczbaWierzcholkow * (liczbaWierzcholkow - 1)) / 2;
		}

		do {
			std::cout << "Podaj ilosc krawedzi: \n";
			std::cin >> liczbaKrawedzi;
		} while (liczbaKrawedzi < 0 || liczbaKrawedzi > maxKrawedzi);

		do {
			std::cout << "Czy graf ma byc wazony? Wpisz 1 jesli tak, 0 jesli nie: \n";
			std::cin >> czyWazony;
		} while (czyWazony != 0 && czyWazony != 1);

		macierzGrafu = new int*[liczbaWierzcholkow];

		for (int i = 0; i < liczbaWierzcholkow; i++) {
			macierzGrafu[i] = new int[liczbaWierzcholkow];
		}

		for (int i = 0; i < liczbaWierzcholkow; i++) {
			for (int j = 0; j < liczbaWierzcholkow; j++) {
				macierzGrafu[i][j] = 0;
			}
		}

		while (m < liczbaKrawedzi) {
			int i = getRand(0, liczbaWierzcholkow - 1);
			int j = getRand(0, liczbaWierzcholkow - 1);

			if (i == j || macierzGrafu[i][j] != 0) {
				continue;
			}

			if (czySkierowany) {
				if (czyWazony) {
					macierzGrafu[i][j] = getRand(1, liczbaWierzcholkow);
				}
				else {
					macierzGrafu[i][j] = 1;
				}
			}
			else {
				if (czyWazony) {
					int rand = getRand(1, liczbaWierzcholkow);
					macierzGrafu[i][j] = rand;
					macierzGrafu[j][i] = rand;
				}
				else {
					macierzGrafu[i][j] = 1;
					macierzGrafu[j][i] = 1;
				}
			}

			m++;
		}
	}

	void wypiszGraf() {
		for (int i = 0; i < liczbaWierzcholkow; i++) {
			for (int j = 0; j < liczbaWierzcholkow; j++) {
				std::cout << macierzGrafu[j][i] << " ";
			}
			std::cout << std::endl;
		}
	}

	~grafLosowy() {
		for (int i = 0; i < liczbaWierzcholkow; i++) {
			delete[] macierzGrafu[i];
		}
		delete[] macierzGrafu;
	}
};

int main() {
	std::srand(std::time(nullptr));

	std::cout << "Generacja grafow\n";
	std::cout << "1. Algorytm generacji grafu losowego\n";
	std::cout << "2. Algorytm R-MAT\n";
	std::cout << "Wybierz algorytm: \n";

	int wybor;
	std::cin >> wybor;

	if (wybor == 1) {
		grafLosowy graf = grafLosowy();
		graf.wypiszGraf();
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
