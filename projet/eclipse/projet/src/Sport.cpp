/*
 * Sport.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "Sport.h"
#include "sstream"
#include "iostream"
namespace std {

Sport::Sport() {
	distanceParcourue = 0;
	vitesse = 250;
	nom = "sport";
	type = "sport";
}
string Sport::afficher() {
	//cout << nom << "(sport), distance :" << distanceParcourue << endl;
	string text = nom + "(sport), distance :" + to_string(distanceParcourue);
	cout << text << endl;
	return text;
}
Sport::~Sport() {
	// TODO Auto-generated destructor stub
}
string Sport::exporter(){
	stringstream xml;
	xml << "<sport><nom>" << nom << "</nom>";
	xml << "<vitesse>" << vitesse << "</sport>";
	xml << "<distance>" << distanceParcourue << "</distance>";
	return xml.str();
}
} /* namespace std */
