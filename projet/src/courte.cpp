/*
 * courte.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "courte.h"
#include "Familiale.h"
namespace std {

courte::courte() {
	Familiale familliale;
	listeVoiture.assign(3, familliale);
	nom = "courte";
}

courte::~courte() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
