/*
 * courte.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "courte.h"
#include "Familiale.h"
#include "sstream"
namespace std {

courte::courte() {
	Familiale familliale;
	listeVoiture.assign(3, familliale);
	nom = "courte";
}

courte::~courte() {
	// TODO Auto-generated destructor stub
}
string courte::exporter(){
	stringstream xml;
	xml << "<courte><nom>" << nom << "</nom>";
	xml << "<longueur>" << longueur << "</longueur>";
	xml << "<listeVoitures>";
	for(Voiture voiture : listeVoiture){
		xml << voiture.exporter();
	}
	xml << "</listeVoitures></courte>";
	return xml.str();
}
} /* namespace std */
