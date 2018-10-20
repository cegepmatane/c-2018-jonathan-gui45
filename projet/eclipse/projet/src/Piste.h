/*
 * Piste.h
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#ifndef PISTE_H_
#define PISTE_H_
#include<iostream>
#include<list>
#include"Voiture.h"
namespace std {

class Piste {
public:
	Piste();
	virtual ~Piste();
	virtual string exporter();
	virtual void afficher();
	virtual int getLongueur();
	virtual list<Voiture*> getListeVoiture();
	int longueur;
	list<Voiture*> listeVoiture;
	string nom;
};

} /* namespace std */

#endif /* PISTE_H_ */
