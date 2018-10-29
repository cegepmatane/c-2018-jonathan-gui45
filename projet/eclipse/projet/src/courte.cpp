/*
 * courte.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "courte.h"
#include "Familiale.h"
#include "sstream"
#include "fstream"
namespace std {

courte::courte() {
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
	Familiale* familiale = new Familiale();
	Familiale* familiale1 = new Familiale();
	Familiale* familiale2 = new Familiale();

	list<string>::iterator iterateur = listeNom.begin();
	familiale->setNom(*iterateur);
	iterateur++;
	familiale1->setNom(*iterateur);
	iterateur++;
	familiale2->setNom(*iterateur);

	familiale->setPosition(0);
	familiale1->setPosition(100);
	familiale2->setPosition(200);

	listeVoiture.push_back(familiale);
	listeVoiture.push_back(familiale1);
	listeVoiture.push_back(familiale2);
	nom = "courte";
	longueur = 500;
}


courte::~courte() {
	// TODO Auto-generated destructor stub
}
	string courte::exporter(){
		stringstream xml;
		xml << "<courte><nom>" << nom << "</nom>";
		xml << "<longueur>" << longueur << "</longueur>";
		xml << "<listeVoitures>";
		for(Voiture *voiture : listeVoiture){
			xml << voiture->exporter();
		}
		xml << "</listeVoitures></courte>";
		return xml.str();
	}
}
