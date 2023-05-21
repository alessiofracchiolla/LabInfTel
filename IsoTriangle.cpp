//IsoTriangle.cpp
/// \file IsoTriangle.cpp
/// \brief class IsoTriangle: implementation of the functions
///
/// Details.
///

#include<iostream>
#include <math.h>
#include "IsoTriangle.h"

/// @brief default constructor 
IsoTriangle::IsoTriangle() {

	cout<<"IsoTriangle - constructor - default"<< endl;

	Init();

}

/// @brief constructor 
/// @param b base of the IsoTriangle
/// @param h height of the IsoTriangle
IsoTriangle::IsoTriangle(float b, float h) {

	Init();

	cout << "IsoTriangle - constructor" << endl;

	if (b <= 0.)
		WarningMessage("constructor: base should be > 0");
	else
		base = b;

	if (h <= 0.)
		WarningMessage("constructor: height should be > 0");
	else
		height = h;

	Update();


}

/// @brief destructor 
IsoTriangle::~IsoTriangle() {

	cout << "IsoTriangle - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param t reference to the object that should be copied 
IsoTriangle::IsoTriangle(const IsoTriangle& t) {

	cout << "IsoTriangle - copy constructor" << endl;

	Init(t);

}

/// @brief overload of operator = 
/// @param t reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
IsoTriangle& IsoTriangle::operator=(const IsoTriangle& t) {

	cout << "IsoTriangle - operator =\n" << endl;

	Init(t);

	return *this;

}

/// @brief overload of operator == 
/// @param t reference to the object on the right side of the operator 
/// @return true if the two objects have the same base and the same height  
bool IsoTriangle::operator==(const IsoTriangle& t) {

	if (t.base == base && t.height == height)
		return true;

	return false;
}

/// @brief default initialization of the object
void IsoTriangle::Init() {
	Reset();
	base = 0.;
	height = 0.;
	Update();
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
/// 
void IsoTriangle::Init(const IsoTriangle& t) {
	Reset();
	base = t.base;
	height = t.height;
	
}

/// @brief total reset of the object  
void IsoTriangle::Reset() {
	base = 0.;
	height = 0.;
}


/// @brief set base of the object
/// @param b base 
void IsoTriangle::SetBase(float b) {

	if (b < 0.) {
		WarningMessage("SetBase: base should be > 0");
		return;
	}

	base = b;
	Update();
}

/// @brief set height of the object
/// @param h height 
void IsoTriangle::SetHeight(float h) {

	if (h < 0.) {

		WarningMessage("SetHeight: height should be > 0");
		return;
	}

	height = h;
	Update();
}



/// @brief set base and height of the object 
/// @param b base 
/// @param h height 
void IsoTriangle::SetDim(float b, float h) {

	SetBase(b);
	SetHeight(h);
	
}


/// @brief get base of the object
/// @return base 
float IsoTriangle::GetBase() {

	return base;

}

/// @brief get height of the object
/// @return height
float IsoTriangle::GetHeight() {

	return height;
}

/// @brief get side of the object
/// @return side
float IsoTriangle::GetSide() {

	return sqrt(pow(base/2,2)+pow(height,2));  
}

/// @brief get base and height of the object
/// @param b base 
/// @param h height
void IsoTriangle::GetDim(float& b, float& h) {

	b = base;
	h = height;
    return;
}

/// @brief get the area of the object
/// @return area of the IsoTriangle
float IsoTriangle::Area() {

	area = (float)((base * height) / 2);
	return area;

}

/// @brief get the perimeter of the object
/// @return perimeter of the IsoTriangle
float IsoTriangle::Perimeter() {

	float side = GetSide();
	perimeter = (2 * side) + base;
	return perimeter;

}



/// @brief write an error message 
/// @param string message to be printed
void IsoTriangle::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- IsoTriangle --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void IsoTriangle::WarningMessage(const char* string) {

	cout << endl << "WARNING -- IsoTriangle --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void IsoTriangle::Dump() {
	cout << "IsoTriangle data: \n" << endl;
	cout << "base = " << base << endl;
	cout << "height = " << height << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	cout << "Area = " << GetArea() << endl;
	cout << endl;

}


/// @brief draw function

 void IsoTriangle::Draw() {

	cout << endl;
	cout << "Sto disegnando un triangolo isoscele: " << endl;
	cout << endl << flush;
	Dump();

}

 /// @brief function to update parameters of the objects
 void IsoTriangle::Update() {

	 GetSide();
	 Area();
	 Perimeter();

 }


 