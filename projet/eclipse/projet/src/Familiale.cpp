/*
 * Familiale.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "Familiale.h"
#include "sstream"
#include "iostream"
namespace std {

Familiale::Familiale() {
	distanceParcourue = 0;
	vitesse = 60;
	nom = "familiale";
}
void Familiale::afficher() {
	cout << nom << "(famillliale), distance :" << distanceParcourue << endl;
}
Familiale::~Familiale() {
	// TODO Auto-generated destructor stub
}
string Familiale::exporter(){
	stringstream xml;
	xml << "<familiale><nom>" << nom << "</nom>";
	xml << "<vitesse>" << vitesse << "</familiale>";
	xml << "<distance>" << distanceParcourue << "</distance>";
	return xml.str();
}
} /* namespace std */
