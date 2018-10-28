/*
 * Familiale.h
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#ifndef FAMILIALE_H_
#define FAMILIALE_H_
#include"Voiture.h"
namespace std {

class Familiale : public Voiture{
public:
	Familiale();
	virtual ~Familiale();
	string exporter();
	string afficher();
};

} /* namespace std */

#endif /* FAMILIALE_H_ */
