#include "Triangle.h"

//Angle
void Triangle::Angle::SetGrades(double grades) { this->grades = grades; }
void Triangle::Angle::SetMinutes(double minutes) { this->minutes = minutes; }

double Triangle::Angle::GetGrades() const { return grades; }
double Triangle::Angle::GetMinutes() const { return minutes; }

void Triangle::Angle::Init(double grades, double minutes)
{
	this->grades = grades;
	this->minutes = minutes;
}
void Triangle::Angle::Read()
{
	cout << "\nGrades = "; cin >> grades;
	cout << "Minutes = "; cin >> minutes;
}
void Triangle::Angle::Display()
{
	cout << "\nGrades = " << GetGrades() << endl;
	cout << "Minutes = " << GetMinutes() << endl;
}
string Triangle::Angle::toString() const
{
	stringstream sout;

	sout << "\nGrades = " << GetGrades() << endl;
	sout << "Minutes = " << GetMinutes() << endl;

	return sout.str();
}

double Triangle::Angle::to360() const { return GetGrades() + GetMinutes() / 60.; }
double Triangle::Angle::toRadian()const { return (to360() * 3.141592) / 180.; }
void Triangle::Angle::Increase(Triangle::Angle X, Triangle::Angle& A, Triangle::Angle& B, Triangle::Angle& C, int tmp)
{
	switch (tmp)
	{
	case 1:
		A.grades = (A.GetGrades() + X.GetGrades());
		A.minutes = (A.GetMinutes() + X.GetMinutes());
		B.grades = (B.GetGrades() - X.GetGrades() / 2.);
		B.minutes = (B.GetMinutes() - X.GetMinutes() / 2.);
		C.grades = (C.GetGrades() - X.GetGrades() / 2.);
		C.minutes = (C.GetMinutes() - X.GetMinutes() / 2.);
		break;
	case 2:
		B.grades = (B.GetGrades() + X.GetGrades());
		B.minutes = (B.GetMinutes() + X.GetMinutes());
		A.grades = (A.GetGrades() - X.GetGrades() / 2.);
		A.minutes = (A.GetMinutes() - X.GetMinutes() / 2.);
		C.grades = (C.GetGrades() - X.GetGrades() / 2.);
		C.minutes = (C.GetMinutes() - X.GetMinutes() / 2.);
		break;
	case 3:
		C.grades = (C.GetGrades() + X.GetGrades());
		C.minutes = (C.GetMinutes() + X.GetMinutes());
		B.grades = (B.GetGrades() - X.GetGrades() / 2.);
		B.minutes = (B.GetMinutes() - X.GetMinutes() / 2);
		A.grades = (A.GetGrades() - X.GetGrades() / 2.);
		A.minutes = (A.GetMinutes() - X.GetMinutes() / 2.);
		break;
	}
}
void Triangle::Angle::Decrease(Triangle::Angle X, Triangle::Angle& A, Triangle::Angle& B, Triangle::Angle& C, int tmp)
{
	Angle minus;
	minus.SetGrades(-1 * X.GetGrades());
	minus.SetMinutes(-1 * X.GetMinutes());
	minus.Increase(minus, A, B, C, tmp);
}
double Triangle::Angle::getSin() const { return sin(toRadian() * 1.); }
void Triangle::Angle::Comparison(Triangle::Angle A, Triangle::Angle B)
{
	if (A.to360() > B.to360())
		cout << "The largest angle = " << A.to360() << endl;
	else if (A.to360() == B.to360())
		cout << "Angles are equal" << endl;
	else
		cout << "The largest angle = " << B.to360() << endl;
}
void Triangle::Angle::Comparison(Triangle::Angle A, Triangle::Angle B, Triangle::Angle C)
{
	double arr[3] = { A.to360(), B.to360(), C.to360() };
	double max = arr[0];

	if ((A.to360() == B.to360()) && (B.to360() == C.to360()))
		cout << "Angles are equal" << endl;
	else
	{
		for (int i = 0; i < 3; i++)
		{
			if (max < arr[i])
				max = arr[i];
		}
		cout << "The largest angle = " << max << endl;
	}
}

//Triangle
void Triangle::SetA(Triangle::Angle A)
{
	this->A.Angle::SetGrades(A.GetGrades());
	this->A.Angle::SetMinutes(A.GetMinutes());
}
void Triangle::SetB(Triangle::Angle B)
{
	this->B.Angle::SetGrades(B.GetGrades());
	this->B.Angle::SetMinutes(B.GetMinutes());
}
void Triangle::SetC(Triangle::Angle C)
{
	this->C.Angle::SetGrades(C.GetGrades());
	this->C.Angle::SetMinutes(C.GetMinutes());
}

void Triangle::Set_a(double value) { a = value; }
void Triangle::Set_b(double value) { b = value; }
void Triangle::Set_c(double value) { c = value; }

Triangle::Angle Triangle::GetA() const { return A; }
Triangle::Angle Triangle::GetB() const { return B; }
Triangle::Angle Triangle::GetC() const { return C; }

double Triangle::Get_a() const { return a; }
double Triangle::Get_b() const { return b; }
double Triangle::Get_c() const { return c; }

void Triangle::DisplayAngles()
{
	cout << "\nAngle A" << endl;
	A.Display();
	cout << "\nAngle B" << endl;
	B.Display();
	cout << "\nAngle C" << endl;
	C.Display();
}
void Triangle::DisplaySides()
{
	cout << "\na = " << Get_a() << endl;
	cout << "\nb = " << Get_b() << endl;
	cout << "\nc = " << Get_c() << endl;
}

void Triangle::InitAngles(Triangle::Angle A, Triangle::Angle B, Triangle::Angle C)
{
	SetA(A);
	SetB(B);
	SetC(C);
}
void Triangle::InitSides(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
void Triangle::ReadSides()
{
	cout << "\na = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;
}

double Triangle::Square() const
{
	double p = Perimeter() / 2.;
	return sqrt(p * (p - Get_a()) * (p - Get_b()) * (p - Get_c()));
}
double Triangle::Perimeter() const { return Get_a() + Get_b() + Get_c(); }
double Triangle::Altitude(int tmp) const
{
	switch (tmp)
	{
	case 1:
		return (2 * Square()) / (Get_a() * 1.);
	case 2:
		return (2 * Square()) / (Get_b() * 1.);
	case 3:
		return (2 * Square()) / (Get_c() * 1.);
	}
}
void Triangle::TypeOFTriangle()
{
	if ((Get_a() == Get_b()) && (Get_b() == Get_c()))
		cout << "Equilateral triangle" << endl; //рівносторонній
	else if ((Get_a() == Get_b() && Get_a() != Get_c()) ||
		(Get_a() == Get_c() && Get_a() != Get_b()) ||
		(Get_c() == Get_b() && Get_c() != Get_a()))
		cout << "Isosceles triangle" << endl;//рівнобедрений
	else if (A.to360() == 90 || B.to360() == 90 || C.to360() == 90)
		cout << "Rectangular triangle" << endl;//прямокутний
	else if (A.to360() > 90 || B.to360() > 90 || C.to360() > 90)
		cout << "Obtuse triangle" << endl;// тупокутний 
	else if (A.to360() < 90 && B.to360() < 90 && C.to360() < 90)
		cout << "Oxygon" << endl;// гострокутний
}

void Triangle::Equalizetriangle(int tmp)
{
	switch (tmp)
	{
	case 1:
		Set_b((Get_a() * B.getSin()) / (A.getSin() * 1.));
		Set_c((Get_a() * C.getSin()) / (A.getSin() * 1.));
		break;
	case 2:
		Set_a((Get_b() * A.getSin()) / (B.getSin() * 1.));
		Set_c((Get_b() * C.getSin()) / (B.getSin() * 1.));
		break;
	case 3:
		Set_a((Get_c() * A.getSin()) / (C.getSin() * 1.));
		Set_b((Get_c() * B.getSin()) / (C.getSin() * 1.));
		break;
	}
}