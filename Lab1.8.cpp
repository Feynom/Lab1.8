#include <iostream>
#include "Triangle.h"

int main()
{
    Triangle first;
    Triangle::Angle A_t, B_t, C_t, X;

    cout << "\nAngle A " << endl;
    A_t.Read();
    first.SetA(A_t);
    cout << A_t.toString();

    cout << "\nAngle B" << endl;
    B_t.Init(60, 0);
    first.SetB(B_t);
    cout << B_t.toString();

    cout << "\nAngle C" << endl;
    C_t.Read();
    first.SetC(C_t);
    C_t.Display();

    cout << "\nAngle B to 360" << endl;
    cout << B_t.to360() << endl;

    cout << "\nAngle B to radians" << endl;
    cout << B_t.toRadian() << endl;

    cout << "\nAngle C get sin" << endl;
    cout << C_t.getSin() << endl;

    cout << "\nCompare angles A and B" << endl;
    C_t.Comparison(A_t, B_t);

    cout << "\nCompare angles A and B and C" << endl;
    C_t.Comparison(A_t, B_t, C_t);

    cout << "\nFirst triangle" << endl;

    cout << "\nAngles: " << endl;
    first.DisplayAngles();

    cout << "\nSides" << endl;
    first.ReadSides();

    cout << "\nSides" << endl;
    first.DisplaySides();

    cout << "\nSquare" << endl;
    cout << first.Square() << endl;

    cout << "\nAltitude A" << endl;
    cout << first.Altitude(1) << endl;


    cout << "\nPerimeter" << endl;
    cout << first.Perimeter() << endl;
    cout << "\nIncrease angle A" << endl;
    X.Read();

    A_t.Increase(X, A_t, B_t, C_t, 1);
    first.InitAngles(A_t, B_t, C_t);
    first.Equalizetriangle(1);

    cout << "\nAngles: " << endl;
    first.DisplayAngles();

    cout << "\nSides" << endl;
    first.DisplaySides();

    cout << "\nType of triangle" << endl;
    first.TypeOFTriangle();

    cout << "\nDecrease angle A" << endl;
    X.Read();

    A_t.Decrease(X, A_t, B_t, C_t, 1);
    first.InitAngles(A_t, B_t, C_t);
    first.Equalizetriangle(1);

    cout << "\nAngles: " << endl;
    first.DisplayAngles();

    cout << "\nSides" << endl;
    first.DisplaySides();

    cout << "\nType of triangle" << endl;
    first.TypeOFTriangle();

    return 0;
}