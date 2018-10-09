/*
 * Sport.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "Sport.h"
#include "sstream"
namespace std {

Sport::Sport() {
	vitesse = 250;
	nom = "sport";
}

Sport::~Sport() {
	// TODO Auto-generated destructor stub
}
string Sport::exporter(){
	stringstream xml;
	xml << "<sport><nom>" << nom << "</nom>";
	xml << "<vitesse>" << vitesse << "</sport>";
	return xml.str();
}
} /* namespace std */
