/*
 * Sedan.h
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#ifndef SEDAN_H_
#define SEDAN_H_
#include"Voiture.h"
namespace std {

class Sedan  : public Voiture{
public:
	Sedan();
	virtual ~Sedan();
	string exporter();
	void afficher();
};

} /* namespace std */

#endif /* SEDAN_H_ */
