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
#include <map>
using namespace std;

int main() {
	courte* courtePiste = new courte();
	moyenne* moyennePiste = new moyenne();
	longue* longuePiste = new longue();

	

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
	system("cls");
	piste->afficher();
	cout << "veuiller choisir votre voiture avec un nombre entre 1 et 3"<<endl;
	int voiture = 1;
	cin >> voiture;
	if (voiture > 3 || voiture < 1) voiture = 1;

	list<Voiture*> liste = piste->getListeVoiture();
	list<Voiture*>::iterator iterateur = liste.begin();

	bool quitter = false;
	bool victoire = false;
	while (!quitter) {
		system("cls");
		cout << "'q' pour quitter, 'd' pour avancer, 'a' pour reculer,'s' pour faire reculer tous sauf toi, 'n' pour beneficier de vitesse suplementaire"<<endl;
		piste->afficher();
		char commande = 'd';
		cin >> commande;
		int i = 1;
		switch (commande) {
		case 'q':
			quitter = true;
			break;
		case 'd':
			iterateur = liste.begin();
			(*iterateur)->avancer();
			iterateur++;
			(*iterateur)->avancer();
			iterateur++;
			(*iterateur)->avancer();
			break;
		case 'a':
			i = 1;
			for (iterateur = liste.begin(); iterateur != liste.end(); iterateur++) {
				if (i == voiture)
					(*iterateur)->reculer();
				else
					(*iterateur)->avancer();
				i++;
			}
			break;
		case 's':
			i = 1;
			for (iterateur = liste.begin(); iterateur != liste.end(); iterateur++) {
				if (i == voiture)
					(*iterateur)->avancer();
				else
					(*iterateur)->reculer();
				i++;
			}
			break;
		case 'n':
			i = 1;
			for (iterateur = liste.begin(); iterateur != liste.end(); iterateur++) {
				if (i == voiture)
					(*iterateur)->nitro();
				else
					(*iterateur)->avancer();
				i++;
			}
			break;
		case 'w':
			ofstream fichier;
			fichier.open("data/courses.xml");
			fichier << piste->exporter();
			fichier.close();
			break;
		}
		i = 1;
		for (iterateur = liste.begin(); iterateur != liste.end(); iterateur++) {
			if ((*iterateur)->getDistanceParcourue() >= piste->getLongueur()) {
				quitter = true;
				if (i == voiture)
					victoire = true;
				break;
			}
			i++;
		}
	}
	system("cls");
	if (victoire)
		cout << "Felicitation!!! tu a gagner";
	else
		cout << "haha ta perdu !";

	_getch();
	return 0;
}
