/*
 * Familiale.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "Familiale.h"
#include "sstream"
namespace std {

Familiale::Familiale() {
	vitesse = 60;
	nom = "familiale";
}

Familiale::~Familiale() {
	// TODO Auto-generated destructor stub
}
string Familiale::exporter(){
	stringstream xml;
	xml << "<familiale><nom>" << nom << "</nom>";
	xml << "<vitesse>" << vitesse << "</familiale>";
	return xml.str();
}
} /* namespace std */
