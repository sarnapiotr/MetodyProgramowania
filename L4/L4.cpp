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
	int czySkierowany;
	int czyWazony;
	int m = 0;
	int** macierzGrafu;

public:
	grafLosowy(int liczbaWierzcholkow, int liczbaKrawedzi, int czySkierowany, int czyWazony) {
		this->liczbaWierzcholkow = liczbaWierzcholkow;
		this->liczbaKrawedzi = liczbaKrawedzi;
		this->czySkierowany = czySkierowany;
		this->czyWazony = czyWazony;
		this->macierzGrafu = new int*[liczbaWierzcholkow];

		for (int i = 0; i < liczbaWierzcholkow; i++) {
			macierzGrafu[i] = new int[liczbaWierzcholkow] {0};
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

class RMAT {
private:
	int N;
	float a;
	float b;
	float c;
	float d;
	float g;
	int czySkierowany;
	int czyWazony;
	int** macierzGrafu;
	int m = 0;
	int liczbaKrawedzi;
	int p, x, y;

public:
	RMAT(int N, float a, float b, float c, float d, float g, int czySkierowany, int czyWazony) {
		this->N = N;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->czySkierowany = czySkierowany;
		this->czyWazony = czyWazony;
		this->macierzGrafu = new int* [N];

		for (int i = 0; i < N; i++) {
			macierzGrafu[i] = new int[N] {0};
		}

		if (czySkierowany) {
			liczbaKrawedzi = static_cast<int>(g * N * (N - 1));
		}
		else {
			liczbaKrawedzi = static_cast<int>(g * ((N * (N - 1)) / 2.0));
		}

		do {
			int p = N;
			x = 0;
			y = 0;

			do {
				p /= 2;
				float wyborCwiartki = static_cast<float>(getRand(1, 100)) / 100;

				if (wyborCwiartki <= a) {
					
				}
				else if (wyborCwiartki <= a + b) {
					x += p;
				}
				else if (wyborCwiartki <= a + b + c) {
					y += p;
				}
				else {
					x += p;
					y += p;
				}

			} while (p != 1);

			if (czySkierowany) {
				if (czyWazony) {
					macierzGrafu[x][y] = getRand(1, N);
				}
				else {
					macierzGrafu[x][y] = 1;
				}
			}
			else {
				if (czyWazony) {
					int rand = getRand(1, N);
					macierzGrafu[x][y] = rand;
					macierzGrafu[y][x] = rand;
				}
				else {
					macierzGrafu[x][y] = 1;
					macierzGrafu[y][x] = 1;
				}
			}

			m++;
		} while (m < liczbaKrawedzi);
	}

	void wypiszGraf() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				std::cout << macierzGrafu[j][i] << " ";
			}
			std::cout << std::endl;
		}
	}

	~RMAT() {
		for (int i = 0; i < N; i++) {
			delete[] macierzGrafu[i];
		}
		delete[] macierzGrafu;
	}
};

int main() {
	std::srand(std::time(0));

	int liczbaWierzcholkow;
	int liczbaKrawedzi;
	int czySkierowany;
	int czyWazony;

	int N;
	float a;
	float b;
	float c;
	float d;
	float g;

	std::cout << "Generacja grafow\n";
	std::cout << "1. Algorytm generacji grafu losowego\n";
	std::cout << "2. Algorytm R-MAT\n";
	std::cout << "Wybierz algorytm: \n";

	int wybor;
	std::cin >> wybor;

	if (wybor == 1) {
		std::cout << "Podaj ilosc wierzcholkow: \n";
		std::cin >> liczbaWierzcholkow;
		std::cout << "Podaj ilosc krawedzi: \n";
		std::cin >> liczbaKrawedzi;
		std::cout << "Czy graf ma byc skierowany? Wpisz 1 jesli tak, 0 jesli nie: \n";
		std::cin >> czySkierowany;
		std::cout << "Czy graf ma byc wazony? Wpisz 1 jesli tak, 0 jesli nie: \n";
		std::cin >> czyWazony;

		int maxKrawedzi;
		if (czySkierowany) {
			maxKrawedzi = liczbaWierzcholkow * (liczbaWierzcholkow - 1);
		}
		else {
			maxKrawedzi = (liczbaWierzcholkow * (liczbaWierzcholkow - 1)) / 2;
		}

		if (liczbaWierzcholkow <= 0 || liczbaKrawedzi < 0 || liczbaKrawedzi > maxKrawedzi || (czySkierowany != 0 && czySkierowany != 1) || (czyWazony != 0 && czyWazony != 1)) {
			std::cout << "Niepoprawne dane wejsciowe\n";
			return -1;
		}

		grafLosowy graf = grafLosowy(liczbaWierzcholkow, liczbaKrawedzi, czySkierowany, czyWazony);
		graf.wypiszGraf();
	}
	else if (wybor == 2) {
		std::cout << "Podaj ilosc wierzcholkow: \n";
		std::cin >> N;
		std::cout << "Podaj a: \n";
		std::cin >> a;
		std::cout << "Podaj b: \n";
		std::cin >> b;
		std::cout << "Podaj c: \n";
		std::cin >> c;
		std::cout << "Podaj d: \n";
		std::cin >> d;
		std::cout << "Podaj gestosc grafu: \n";
		std::cin >> g;
		std::cout << "Czy graf ma byc skierowany? Wpisz 1 jesli tak, 0 jesli nie: \n";
		std::cin >> czySkierowany;
		std::cout << "Czy graf ma byc wazony? Wpisz 1 jesli tak, 0 jesli nie: \n";
		std::cin >> czyWazony;

		if (N <= 0 || (N & (N - 1)) != 0 || (a + b + c + d) != 1.0  || g <= 0 || g > 1.0 || (czySkierowany != 0 && czySkierowany != 1) || (czyWazony != 0 && czyWazony != 1)) {
			std::cout << "Niepoprawne dane wejsciowe\n";
			return -1;
		}

		RMAT graf = RMAT(N, a, b, c, d, g, czySkierowany, czyWazony);
		graf.wypiszGraf();
	}
	else {
		std::cout << "Niepoprawny wybor\n";
		return -1;
	}

	return 0;
}
