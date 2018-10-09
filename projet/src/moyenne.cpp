/*
 * moyenne.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "moyenne.h"
#include "Sedan.h"
#include "Sport.h"
namespace std {

moyenne::moyenne() {
	Sedan sedan;
	listeVoiture.assign(3, sedan);
	nom = "moyenne";
}

moyenne::~moyenne() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
