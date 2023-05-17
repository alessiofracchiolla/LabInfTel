#include <iostream>
#include"polygon.h"
#include "IsoTriangle.h"

int main () {
	IsoTriangle triangle1(6, 4);
	IsoTriangle triangle2;
	triangle2.SetDim(10, 12);
	triangle1.Dump();
	IsoTriangle triangleNeg(-1, -5);
	//triangleNeg.Dump();

	if (triangle1 == triangle2) {
		cout << "triangoli uguali\n" << endl;
	}
	else cout << "triangoli diversi\n" << endl;

	triangle2 = triangle1;
	if (triangle1 == triangle2) {
		cout << "triangoli uguali\n" << endl;
	}
	else cout << "triangoli diversi\n" << endl;

	return 0;

}