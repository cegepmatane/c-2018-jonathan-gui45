/*
 * longue.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "longue.h"
#include "Sedan.h"
#include "Sport.h"
namespace std {

longue::longue() {
	longueur = 1000;
	Sedan sedan;
	Sport sport;
	listeVoiture.assign(2, sedan);
	listeVoiture.assign(1, sport);
	nom = "longue";
}

longue::~longue() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
