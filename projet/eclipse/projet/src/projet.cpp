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
#include <vector>
#include <fstream>
#include <map>
#include <SFML/Graphics.hpp>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 700), "race");
	sf::Texture tBackground;
	tBackground.loadFromFile("images/background.png");
	sf::Sprite sBackgroung(tBackground);

	courte* courtePiste = new courte();
	moyenne* moyennePiste = new moyenne();
	longue* longuePiste = new longue();



	//cout << "veuiller choisir une piste, courte[1], moyenne[2], longue[3]" << endl;
	sf::Font font;
	font.loadFromFile("fonts/arial.ttf");
	sf::Text Toptions1("veuiller choisir une piste, courte[1], moyenne[2], longue[3]\n appuyer sur entrer apres chaque commande \n appuyer sur entree apres chaque commande", font, 30);
	Toptions1.move(0, 300);
	Toptions1.setFillColor(sf::Color::Black);
	window.clear();
	window.draw(sBackgroung);
	window.draw(Toptions1);
	window.display();

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
	//piste->afficher();
	list<sf::Sprite*> listeSpriteVoitures = piste->afficherImages();
	sf::Text Toptions2(piste->afficher() + "\nveuiller choisir votre voiture avec un nombre entre 1 et 3\n appuyer sur entrer apres chaque commande \n appuyer sur entree apres chaque commande", font, 30);
	cout << "veuiller choisir votre voiture avec un nombre entre 1 et 3" << endl;
	Toptions2.move(0, 300);
	Toptions2.setFillColor(sf::Color::Black);
	window.clear();
	window.draw(sBackgroung);
	window.draw(Toptions2);
	for (list<sf::Sprite*>::iterator iterateur = listeSpriteVoitures.begin(); iterateur != listeSpriteVoitures.end(); iterateur++) {
		window.draw(*(*iterateur));
	}
	window.display();
	for (list<sf::Sprite*>::iterator iterateur = listeSpriteVoitures.begin(); iterateur != listeSpriteVoitures.end(); iterateur++) {
		delete((*iterateur)->getTexture());
		delete((*iterateur));
	}
	int voiture = 1;
	cin >> voiture;
	if (voiture > 3 || voiture < 1) voiture = 1;

	list<Voiture*> liste = piste->getListeVoiture();
	list<Voiture*>::iterator iterateur = liste.begin();

	bool quitter = false;
	bool victoire = false;
	while (window.isOpen())
	{
		//while (!quitter) {
			system("cls");
			cout << "'q' pour quitter, 'd' pour avancer, 'a' pour reculer,'s' pour faire reculer tous sauf toi, 'n' pour beneficier de vitesse suplementaire, 'w' pour suavegarder la partie en cour, ' ' pour changer de voiture, appuyer sur entrer apres chaque commande appuyer sur entree apres chaque commande" << endl;
			//piste->afficher();

			list<sf::Sprite*> listeSpriteVoitures = piste->afficherImages();
			sf::Text Toptions2(piste->afficher() + "\n voiture selectionner : " + to_string(voiture) + "\n'q' pour quitter, 'd' pour avancer, 'a' pour reculer,\n's' pour faire reculer tous sauf toi, 'n' pour beneficier de vitesse suplementaire, \n'w' pour suavegarder la partie en cour, 'e' pour changer de voiture \n appuyer sur entrer apres chaque commande \n appuyer sur entree apres chaque commande", font, 30);
			Toptions2.move(0, 300);
			Toptions2.setFillColor(sf::Color::Black);
			window.clear();
			window.draw(sBackgroung);
			window.draw(Toptions2);
			for (list<sf::Sprite*>::iterator iterateur = listeSpriteVoitures.begin(); iterateur != listeSpriteVoitures.end(); iterateur++) {
				window.draw(*(*iterateur));
			}
			window.display();
			for (list<sf::Sprite*>::iterator iterateur = listeSpriteVoitures.begin(); iterateur != listeSpriteVoitures.end(); iterateur++) {
				delete((*iterateur)->getTexture());
				delete((*iterateur));
			}

			char commande = 'd';
			cin >> commande;
			int i = 1;
			ofstream fichier;
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
				fichier.open("data/courses.xml");
				fichier << piste->exporter();
				fichier.close();
				break;
			case 'e':
				voiture++;
				if (voiture > 3) voiture = 1;
				break;
			}

			i = 1;
			for (iterateur = liste.begin(); iterateur != liste.end(); iterateur++) {
				if ((*iterateur)->getDistanceParcourue() >= piste->getLongueur()) {
					window.close();
					if (i == voiture)
						victoire = true;
					break;
				}
				i++;
			}
		//}
	}
	system("cls");
	if (victoire)
		cout << "Felicitation!!! tu a gagner";
	else
		cout << "haha ta perdu !";

	_getch();
	return 0;
}
