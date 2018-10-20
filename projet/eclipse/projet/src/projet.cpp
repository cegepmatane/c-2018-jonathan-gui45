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
#include "conio.h" 
#include <fstream>
using namespace std;

int main() {
	courte* courtePiste = new courte();
	moyenne* moyennePiste = new moyenne();
	longue* longuePiste = new longue();

	ofstream fichier;
	fichier.open("data/courses.xml");
	fichier << courtePiste->exporter()<< moyennePiste->exporter()<< longuePiste->exporter();
	fichier.close();

	cout << "veuiller choisir une piste, courte[1], moyenne[2], longue[3]"<<endl;
	Piste* piste;
	int choix;
	cin >> choix;
	switch (choix) {
	case 1:
		piste = courtePiste;
		break;
	case 2:
		piste = moyennePiste;
		break;
	case 3:
		piste = longuePiste;
		break;
	default:
		piste = moyennePiste;
		break;
	}

	piste->afficher();
	cout << "veuiller choisir votre voiture avec un nombre entre 1 et 3"<<endl;
	int voiture = 1;
	cin >> voiture;
	if (voiture > 3 || voiture < 1) voiture = 1;
	
	bool quitter = false;
	while (!quitter) {
		cout << "'q' pour quitter, 'd' pour avancer, 'a' pour reculer"<<endl;
		piste->afficher();
		//while ((getchar()) != '\n');
		switch (_getch()) {
		case 'q':
			quitter = true;
			break;
		case 'd':
			break;
		case 'a':
			break;
		}
	}

	return 0;
}
