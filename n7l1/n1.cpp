#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

class Point {
protected:
    int X, Y;
    int Cvet;
public:
    void Init(int XN, int YN, int Color) {
        X = XN;
        Y = YN;
        Cvet = Color;
    }
    void Local(int& XL, int& YL) const {
        XL = X;
        YL = Y;
    }
    void Fly(int Cost) {
        std::srand(std::time(nullptr));
        int XX, YY;
        do {
            Local(XX, YY);
            do { // перемещение1
                XX += std::rand() % Cost - Cost / 2;
            } while (!(XX > 0 && XX < 800)); // assuming 800x600 window
            do { // перемещение2
                YY += std::rand() % Cost - Cost / 2;
            } while (!(YY > 0 && YY < 600)); // assuming 800x600 window
            X = XX;
            Y = YY;
            std::cout << "X: " << X << ", Y: " << Y << std::endl;
            std::system("pause");
            std::system("cls");
        } while (true); // Loop indefinitely until user terminates
    }
};

class Krug : public Point {
private:
    int Radius;
public:
    void Init(int XN, int YN, int R, int Color) {
        Point::Init(XN, YN, Color);
        Radius = R;
    }
};

class Ring : public Krug {
private:
    int Width;
public:
    void Init(int XN, int YN, int R, int Color, int Wide) {
        Width = Wide;
        Krug::Init(XN, YN, R, Color);
    }
};

int main() {
    Krug testKrug;
    testKrug.Init(150, 150, 50, 0xFF0000); // Red

    Ring testing;
    testing.Init(400, 300, 100, 0x00FF00, 20); // Green

    testKrug.Fly(50);

    return 0;
}