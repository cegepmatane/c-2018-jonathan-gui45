//============================================================================
// Name        : projet.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "courte.h"
#include "longue.h"
#include "moyenne.h"
#include "Sedan.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl;
	courte piste1;
	moyenne piste2;
	longue* piste3 = new longue();
	Sedan* voiture = new Sedan();
	cout << voiture->exporter()<<endl;
	cout << piste3->exporter()<<endl;
	delete voiture;
	return 0;
}
