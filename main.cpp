#include <iostream>
#include "polygon.h"
#include "IsoTriangle.h"
#include "rhombus.h"
#include "rectangle.h"


int main () {

	Polygon* array[100] = { 0 };
	int d = 0;
	int i = 0;

	while (i != 5) {

		int j = 0;
		
		cout << "\nMENU\n" << endl;
		cout << "Inserire il numero corrispondente alla scelta:\n " << endl;
		cout << "premere 1 per creare un rettangolo" << endl;
		cout << "premere 2 per creare un rombo" << endl;
		cout << "premere 3 per creare un triangolo isoscele" << endl;
		cout << "premere 4 per disegnare tutto" << endl;
		cout << "premere 5 per chiudere il programma\n\n" << endl;
		scanf_s("%i", &i);

		getchar();
		cout << "\n" << endl;
		
		switch (i)
		{

		case 1:        //creare un rettangolo
			float baseR, altezzaR;
			cout << "Inserisci base e altezza del rettangolo: " << endl;
			scanf_s("%f %f", &baseR, &altezzaR);		
			getchar();
			array[d] = new Rectangle(baseR, altezzaR);
			d++;
			break;

		case 2:         //creare un rombo
			float diagH, diagV;
			cout << "Inserisci la diagonale orizzontale e la verticale del rombo: "<< endl;
			scanf_s("%f %f", &diagH, &diagV);
			getchar();
			array[d] = new Rhombus(diagH, diagV);
			d++;
			break;

		case 3:         //creare un triangolo isoscele
			float baseT, altezzaT;
			cout << "Inserisci base e altezza del triangolo isoscele: " << endl;
			scanf_s("%f %f", &baseT, &altezzaT);
			getchar();
			array[d] = new IsoTriangle(baseT, altezzaT);
			d++;
            break;

		case 4:

			cout << "Disegno i poligoni creati:\n\n" << endl;

				while (j<d && array[j] != NULL) {
				cout << "Poligono " << j + 1 << endl;
				array[j]->Draw();
				j++;
			}
			break;

		case 5:
			break;

		default:
			cout << "Scelta errata, prego reinserire la propria scelta...\n";
			break;
		}
		
	}

	for (int i = 0; i <= d; i++) {
		if (array[i] != NULL)
		cout << "Sto distruggendo il poligono  " << i + 1 << "...\n" << endl;

		delete array[i];
		
	}

	cout << "Chiusura programma in corso..." << endl;
	return 0;

}


