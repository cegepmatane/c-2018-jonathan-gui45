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
string Sedan::afficher(sf::Window window) {
	//cout << nom << "(sedan), distance :" << distanceParcourue << endl;
	sf::Texture texture;
	texture.loadFromFile("images/sedan.png");
	string text = nom + "(sedan), distance :" + to_string(distanceParcourue);
	cout << text << endl;
	return text;
}
Sedan::~Sedan() {
	// TODO Auto-generated destructor stub
}
string Sedan::exporter(){
	stringstream xml;
	xml << "<sedan><nom>" << nom << "</nom>";
	xml << "<vitesse>" << vitesse << "</sedan>";
	xml << "<distance>" << distanceParcourue << "</distance>";
	return xml.str();
}
} /* namespace std */
