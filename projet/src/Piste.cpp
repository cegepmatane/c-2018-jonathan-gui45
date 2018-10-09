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
	longueur = 100;
	nom = "piste";
	Sedan sedan;
	listeVoiture.assign(3, sedan);
}

Piste::~Piste() {
	// TODO Auto-generated destructor stub
}
string Piste::exporter(){
	stringstream xml;
	xml << "<piste><nom>" << nom << "</nom>";
	xml << "<longueur>" << longueur << "</longueur>";
	xml << "<listeVoitures>";
	for(Voiture voiture : listeVoiture){
		xml << voiture.exporter();
	}
	xml << "</listeVoitures></piste>";
	return xml.str();
}
} /* namespace std */
