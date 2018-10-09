/*
 * Voiture.h
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#ifndef VOITURE_H_
#define VOITURE_H_
#include <string>
namespace std {

class Voiture {
public:
	Voiture();
	virtual ~Voiture();
	virtual string exporter();
	int vitesse;
	string nom;
};

} /* namespace std */

#endif /* VOITURE_H_ */
