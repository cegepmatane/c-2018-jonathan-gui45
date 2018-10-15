/*
 * Voiture.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "Voiture.h"
#include "sstream"
namespace std {

Voiture::Voiture() {
	vitesse = 100;
	nom = "voiture";
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
void Voiture::setNom(string nom){
this->nom = nom;
}
} /* namespace std */
