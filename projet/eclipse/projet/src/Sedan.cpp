/*
 * Sedan.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "Sedan.h"
#include "sstream"
#include "iostream"
namespace std {

Sedan::Sedan() {
	distanceParcourue = 0;
	vitesse = 120;
	nom = "sedan";
}
void Sedan::afficher() {
	cout << nom << "(sedan), distance :" << distanceParcourue << endl;
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
