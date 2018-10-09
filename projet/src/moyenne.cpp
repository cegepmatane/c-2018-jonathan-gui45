/*
 * moyenne.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "moyenne.h"
#include "Sedan.h"
#include "Sport.h"
#include "sstream"
namespace std {

moyenne::moyenne() {
	Sedan sedan;
	listeVoiture.assign(3, sedan);
	nom = "moyenne";
}

moyenne::~moyenne() {
	// TODO Auto-generated destructor stub
}
string moyenne::exporter(){
	stringstream xml;
	xml << "<moyenne><nom>" << nom << "</nom>";
	xml << "<longueur>" << longueur << "</longueur>";
	xml << "<listeVoitures>";
	for(Voiture voiture : listeVoiture){
		xml << voiture.exporter();
	}
	xml << "</listeVoitures></moyenne>";
	return xml.str();
}
} /* namespace std */
