#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Triangle
{
public:
	class Angle
	{
		double grades, minutes;
	public:
		void SetGrades(double grades);
		void SetMinutes(double minutes);

		double GetGrades() const;
		double GetMinutes() const;

		void Init(double grades, double minutes);
		void Read();
		void Display();

		std::string toString() const;

		double to360() const;
		double toRadian() const;
		void Increase(Angle X, Angle& A, Angle& B, Angle& C, int tmp);
		void Decrease(Angle X, Angle& A, Angle& B, Angle& C, int tmp);
		double getSin() const;
		void Comparison(Angle A, Angle B);
		void Comparison(Angle A, Angle B, Angle C);
	};

	void SetA(Angle A);
	void SetB(Angle B);
	void SetC(Angle C);

	void Set_a(double value);
	void Set_b(double value);
	void Set_c(double value);

	Angle GetA() const;
	Angle GetB() const;
	Angle GetC() const;

	double Get_a() const;
	double Get_b() const;
	double Get_c() const;

	void DisplayAngles();
	void DisplaySides();

	void InitAngles(Angle A, Angle B, Angle C);
	void InitSides(double a, double b, double c);
	void ReadSides();

	double Square() const;
	double Perimeter() const;
	double Altitude(int tmp) const;
	void TypeOFTriangle();
	void Equalizetriangle(int tmp);
private:
	Angle A, B, C;
	double a, b, c;
};
