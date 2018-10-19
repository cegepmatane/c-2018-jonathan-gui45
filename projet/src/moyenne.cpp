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
#include "fstream"
namespace std {

moyenne::moyenne() {
	ifstream sourcePersonnage;
	    sourcePersonnage.open("data/voitures.csv");
	    string ligne;
	    string temp;
	    list<string> listeNom;
	    while(!sourcePersonnage.eof()){
	        getline(sourcePersonnage,ligne);
	        unsigned int positionDebut = 0;
	        unsigned int positionFin = 0;
	        do{
	            positionFin = ligne.find(";", positionDebut);
	            listeNom.push_back(ligne.substr(positionDebut, positionFin - positionDebut));
	            temp = ligne.substr(positionDebut, positionFin - positionDebut);
	            //cout << "pos fin "<< positionFin << endl;
	            //cout << "valeur " << valeur << endl;
	            positionDebut = positionFin+1;
	        }while(positionDebut != 0);
	    }

	list<string>::iterator iterateur = listeNom.begin();
	advance(iterateur, 1);
	listeNom.pop_front();
	Sedan* sedan = new Sedan();
	Sedan* sedan1 = new Sedan();
	Sedan* sedan2 = new Sedan();
	listeVoiture.push_back(*sedan);
	listeVoiture.push_back(*sedan1);
	listeVoiture.push_back(*sedan2);
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
