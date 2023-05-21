/*! \file rhombus.cpp
	\brief class Rhombus: implementation of the functions

	Details.
*/



#include<iostream>
#include "rhombus.h"



/// @brief default constructor
Rhombus::Rhombus()
{

	cout << "Rhombus - Default Constructor" << endl;

	Init();

}

/// @brief init constructor
/// @param dH horizontal diagonal 
/// @param dV vertical diagonal 
Rhombus::Rhombus(float dH, float dV)
{

	Init();

	cout << "Rhombus - constructor" << endl;

	if (dH <= 0.)
		WarningMessage("constructor: diagH should be > 0");
	else
		diagH = dH;

	if (dV <= 0.)
		WarningMessage("constructor: diagV should be > 0");
	else
		diagV = dV;


	Update();

}


/// @brief copy constructor
/// @param Rhombus to copy passed by reference
Rhombus::Rhombus(const Rhombus& r)
{

	cout << "Rhombus - Copy Constructor" << endl;

	Init(r);

}


/// @brief destructor 
Rhombus::~Rhombus()
{

	cout << "Rhombus - Destructor" << endl;
	Reset();

}


/// @brief overload of operator = 
/// @param t reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Rhombus& Rhombus::operator=(const Rhombus& r)
{

	cout << "Rhombus - operator =" << endl;

	Reset();
	Init(r);


	return *this;

}

//// @brief overload of operator == 
/// @param t reference to the object on the right side of the operator 
/// @return true if the two objects have the same base and the same height  
/// 
bool Rhombus::operator==(const Rhombus& r)
{

	if (diagH == r.diagH && diagV == r.diagV)
	{
		return true;
	}
	return false;

}


/// @brief default initialization of the object

void Rhombus::Init()
{

	Reset();

	diagH = 0;
	diagV = 0;

	Update();

}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 

void Rhombus::Init(const Rhombus& r)
{

	Reset();

	diagH = r.diagH;
	diagV = r.diagV;
	Update();

}


/// @brief total reset of the object 

void Rhombus::Reset()
{

	diagH = 0;
	diagV = 0;

	Update();

}



/// @brief get the area of the object
/// @return area of the Rhombus

float Rhombus::Area()
{
	area = ((diagH * diagV) / 2.);
	return area;
}

/// @brief get the perimeter of the object
/// @return perimeter of the Rhombus
/// 
float Rhombus::Perimeter()
{
	perimeter = (GetSide() * 4);
	return perimeter;

}


/// @brief set diagH of the object
/// @param dH diagH value

void Rhombus::SetDiagH(float dH)
{

	if (dH < 0.) {
		WarningMessage("SetDiagH: horizontal diagonal should be > 0");
		return;
	}

	diagH = dH;

	Update();

}

/// @brief set diagV of the object
/// @param dV diagV value

void Rhombus::SetDiagV(float dV)
{

	if (dV < 0.) {
		WarningMessage("SetDiagV: vertical diagonal should be > 0");
		return;
	}

	diagV = dV;

	Update();

}

/// @brief set dimensions of the object
/// @param dH diagH value
/// @param dV diagV value
void Rhombus::SetDim(float dH, float dV)
{

	SetDiagH(dH);
	SetDiagV(dV);

}

/// @brief get horizontal diagonal of the object
/// @return diagH value
float Rhombus::GetDiagH()
{

	return diagH;

}

/// @brief get vertical diagonal of the object
/// @return diagV value
float Rhombus::GetDiagV()
{

	return diagV;

}

/// @brief get diagH and diagV of the object 
/// @param diagH
/// @param  diagV
void Rhombus::GetDim(float& dH, float& dV)
{

	dH = diagH;
	dV = diagV;

}

/// @brief get side of the object
/// @return side value
float Rhombus::GetSide()
{
	return sqrt(pow(diagH / 2, 2) + pow(diagV / 2, 2));
}



/// @brief write an error message 
/// @param string message to be printed
void Rhombus::ErrorMessage(const char* string)
{

	cout << endl << "ERROR -- Rhombus --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Rhombus::WarningMessage(const char* string)
{

	cout << endl << "WARNING -- Rhombus --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void Rhombus::Dump()
{
	cout << "Rhombus data:" << endl;
	cout << endl;

	cout << "Horizontal Diagonal = " << diagH << endl;
	cout << "Vertical Diagonal = " << diagV << endl;
	cout << "Area = " << GetArea() << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;


	cout << endl << flush;

}

/// @brief draw function
void Rhombus::Draw()
{
	cout << endl;
	cout << "Sto disegnando un rombo: " << endl;
	cout << endl << flush;
	Dump();

}

/// @brief function to update parameters of the objects
void Rhombus::Update() {

	GetSide();
	Area();
	Perimeter();

}