#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

struct Point {
    int X, Y;
};

bool arePointsEqual(const Point& a, const Point& b) {
    return a.X == b.X && a.Y == b.Y;
}

void jarvis(const std::vector<Point>& pointVector, const int& pointCount) {
    if (pointCount < 3) {
        return;
    }

    Point P0 = pointVector[0];
    Point Q0 = pointVector[0];


    for (int i = 0; i < pointCount; i++) {
        if (pointVector[i].Y < P0.Y ) {
            P0 = pointVector[i];
        }
    }

    for (int i = 0; i < pointCount; i++) {
        if (pointVector[i].Y > Q0.Y) {
            Q0 = pointVector[i];
        }
    }

    std::vector<Point> convexHull;
    Point r = P0;

    do {
        convexHull.push_back(r);

        int tempPointIndex = 0;
        for (int i = 0; i < pointCount; i++) {
            Point t = pointVector[i];
            if (!arePointsEqual(r, t)) {

            }
        }
        r = pointVector[tempPointIndex];

    } while (!arePointsEqual(r, Q0));

    for (int i = 0; i < convexHull.size(); i++) {
        std::cout << convexHull[i].X << " " << convexHull[i].Y << std::endl;
    }
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
