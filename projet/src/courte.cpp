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

	Familiale familliale;
	list<string>::iterator iterateur = listeNom.begin();
	advance(iterateur, 1);
	listeNom.pop_front();
	familliale.setNom(temp);
	listeVoiture.assign(3, familliale);
	nom = "courte";
}


courte::~courte() {
	// TODO Auto-generated destructor stub
}
	string courte::exporter(){
		stringstream xml;
		xml << "<courte><nom>" << nom << "</nom>";
		xml << "<longueur>" << longueur << "</longueur>";
		xml << "<listeVoitures>";
		for(Voiture voiture : listeVoiture){
			xml << voiture.exporter();
		}
		xml << "</listeVoitures></courte>";
		return xml.str();
	}
}
