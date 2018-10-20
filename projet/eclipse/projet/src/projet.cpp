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
#include <fstream>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl;
	courte* piste1 = new courte();
	moyenne* piste2 = new moyenne();
	longue* piste3 = new longue();
	ofstream fichier;
	fichier.open("data/courses.xml");
	fichier <<piste1->exporter()<<piste2->exporter()<<piste3->exporter();
	fichier.close();
	return 0;
}
