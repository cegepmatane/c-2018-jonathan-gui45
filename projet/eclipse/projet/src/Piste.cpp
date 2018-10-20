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
list<Voiture*> Piste::getListeVoiture() {
	return listeVoiture;
}
void Piste::afficher() {
	list<Voiture*>::iterator iterateur;
	for (iterateur = listeVoiture.begin(); iterateur != listeVoiture.end(); ++iterateur) {
		(*iterateur)->afficher();
	}
	cout << nom << ": distance total a parcourir : " << longueur << endl;
}
int Piste::getLongueur() {
	return longueur;
}
} /* namespace std */
