#include <iostream>
#include <vector>
#include <sstream>

struct Point
{
    int X, Y;
};

void jarvis(const std::vector<Point>& pointVector, const int& pointCout) {
    Point P0 = pointVector[0];
    Point Q0 = pointVector[0];

    for (int i = 0; i < pointCout; i++) {
        if (pointVector[i].Y < P0.Y) {
            P0 = pointVector[i];
        }
    }

    for (int i = 0; i < pointCout; i++) {
        if (pointVector[i].Y > Q0.Y) {
            Q0 = pointVector[i];
        }
    }

    std::cout << "P0: " << P0.X << " " << P0.Y;
    std::cout << "Q0: " << Q0.X << " " << Q0.Y;
}

int main()
{
    std::cout << "Wyznaczanie otoczki wypuklej\n";
    std::cout << "Podaj liczbe punktow: \n";

    int pointCount = 0;
    std::cin >> pointCount;

    std::cout << "Podaj pary oddzielone pojedynczymi spacjami, z ktorych pierwsza oznacza wspolrzedna X a druga wspolrzedna Y: \n";

    std::string inputString = "";
    std::cin.ignore();
    std::getline(std::cin, inputString);

    std::vector<Point> pointVector;
    std::istringstream stream(inputString);
    int X, Y;
    while (stream >> X >> Y) {
        pointVector.push_back(Point{ X, Y });
    }

    jarvis(pointVector, pointCount);

    return 0;
}
//9
//0 0 0 2 -2 2 4 2 3 3 2 5 5 5 1 6 0 8
