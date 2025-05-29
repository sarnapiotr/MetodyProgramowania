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

int vectorProduct(const Point& a, const Point& b, const Point& c) {
    return (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
}

void jarvis(const std::vector<Point>& pointVector, const int& pointCount) {
    if (pointCount < 3) {
        return;
    }

    Point P0 = pointVector[0];

    for (int i = 1; i < pointCount; i++) {
        if (pointVector[i].Y < P0.Y) {
            P0 = pointVector[i];
        }
    }

    std::vector<Point> convexHull;
    Point r = P0;

    do {
        convexHull.push_back(r);
        int tempPointIndex = -1;

        for (int i = 0; i < pointCount; i++) {
            const Point& t = pointVector[i];
            if (arePointsEqual(r, t)) continue;

            if (tempPointIndex == -1 || vectorProduct(r, pointVector[tempPointIndex], t) < 0) {
                tempPointIndex = i;
            }
        }

        r = pointVector[tempPointIndex];
    } while (!arePointsEqual(r, P0));

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
