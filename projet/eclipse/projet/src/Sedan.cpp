/*
 * Sedan.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "Sedan.h"
#include "sstream"
namespace std {

Sedan::Sedan() {
	vitesse = 120;
	nom = "sedan";
}

Sedan::~Sedan() {
	// TODO Auto-generated destructor stub
}
string Sedan::exporter(){
	stringstream xml;
	xml << "<sedan><nom>" << nom << "</nom>";
	xml << "<vitesse>" << vitesse << "</sedan>";
	return xml.str();
}
} /* namespace std */
