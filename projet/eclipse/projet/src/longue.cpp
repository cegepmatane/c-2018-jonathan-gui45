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
#include "fstream"
namespace std {

longue::longue() {
	longueur = 1500;
	nom = "longue";
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
	
	Sedan* sedan = new Sedan();
	Sedan* sedan1 = new Sedan();
	Sport* sport = new Sport();

	list<string>::iterator iterateur = listeNom.begin();
	sedan1->setNom(*iterateur);
	iterateur++;
	sedan->setNom(*iterateur);
	iterateur++;
	sport->setNom(*iterateur);

	sedan1->setPosition(0);
	sedan->setPosition(100);
	sport->setPosition(200);

	sedan1->setLongueurPiste(longueur);
	sport->setLongueurPiste(longueur);
	sedan->setLongueurPiste(longueur);

	listeVoiture.push_back(sedan1);
	listeVoiture.push_back(sedan);
	listeVoiture.push_back(sport);
}

longue::~longue() {
	// TODO Auto-generated destructor stub
}
string longue::exporter(){
	stringstream xml;
	xml << "<longue><nom>" << nom << "</nom>";
	xml << "<longueur>" << longueur << "</longueur>";
	xml << "<listeVoitures>";
	for(Voiture *voiture : listeVoiture){
		xml << voiture->exporter();
	}
	xml << "</listeVoitures></longue>";
	return xml.str();
}
} /* namespace std */
