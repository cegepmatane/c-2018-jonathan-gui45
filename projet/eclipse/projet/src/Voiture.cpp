/*
 * Voiture.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "Voiture.h"
#include "sstream"
#include "iostream"
namespace std {

Voiture::Voiture() {
	distanceParcourue = 0;
	vitesse = 100;
	nom = "voiture";
}

void Voiture::afficher() {
	cout << nom << "(), distance :" << distanceParcourue << endl;
}
void Voiture::nitro() {
	distanceParcourue += vitesse * 2;
}
void Voiture::avancer() {
	distanceParcourue += vitesse;
}

void Voiture::reculer() {
	int vitesseReculon = vitesse / 2;
	distanceParcourue -= vitesseReculon;
}
void Voiture::operator++() {
	vitesse += 50 ;
	distanceParcourue = 0;
}
Voiture::~Voiture() {
	// TODO Auto-generated destructor stub
}

string Voiture::exporter(){
	stringstream xml;
	xml << "<voiture><nom>" << nom << "</nom>";
	xml << "<vitesse>" << vitesse << "</vitesse></voiture>";
	return xml.str();
}
int Voiture::getDistanceParcourue() {
	return distanceParcourue;
}
void Voiture::setNom(string nom){
this->nom = nom;
}
} /* namespace std */
