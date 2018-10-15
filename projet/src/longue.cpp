/*
 * longue.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "longue.h"
#include "Sedan.h"
#include "Sport.h"
#include "sstream"
namespace std {

longue::longue() {
	longueur = 1000;
	Sedan sedan;
	Sport sport;
	listeVoiture.push_back( sedan);
	listeVoiture.push_back( sedan);
	listeVoiture.push_back( sport);
	nom = "longue";
}

longue::~longue() {
	// TODO Auto-generated destructor stub
}
string longue::exporter(){
	stringstream xml;
	xml << "<longue><nom>" << nom << "</nom>";
	xml << "<longueur>" << longueur << "</longueur>";
	xml << "<listeVoitures>";
	for(Voiture voiture : listeVoiture){
		xml << voiture.exporter();
	}
	xml << "</listeVoitures></longue>";
	return xml.str();
}
} /* namespace std */
