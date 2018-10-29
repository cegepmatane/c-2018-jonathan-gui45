/*
 * Piste.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "Piste.h"
#include "sstream"
#include "Sedan.h"
namespace std {

Piste::Piste() {
	longueur = 1000;
	nom = "piste";
}

Piste::~Piste() {
	// TODO Auto-generated destructor stub
}
string Piste::exporter(){
	stringstream xml;
	xml << "<piste><nom>" << nom << "</nom>";
	xml << "<longueur>" << longueur << "</longueur>";
	xml << "<listeVoitures>";
	for(Voiture *voiture : listeVoiture){
		xml << voiture->exporter();
	}
	xml << "</listeVoitures></piste>";
	return xml.str();
}
list<sf::Sprite*> Piste::afficherImages() {
	list<sf::Sprite*> listeSVoitures;
	for (list<Voiture*>::iterator iterateur = listeVoiture.begin(); iterateur != listeVoiture.end(); iterateur++) {
		listeSVoitures.push_back((*iterateur)->afficherImage());
	}
	return listeSVoitures;
}
string Piste::afficher() {
	list<Voiture*>::iterator iterateur;
	string text = "";
	for (iterateur = listeVoiture.begin(); iterateur != listeVoiture.end(); ++iterateur) {
		text += (*iterateur)->afficher() + "\n";
	}

	text += nom + ": distance total a parcourir : " + to_string(longueur);
	cout << text << endl;
	return text;
}
int Piste::getLongueur() {
	return longueur;
}
list<Voiture*> Piste::getListeVoiture() {
	return listeVoiture;
}
} /* namespace std */
