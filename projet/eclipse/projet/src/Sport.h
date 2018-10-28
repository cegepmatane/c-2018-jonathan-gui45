/*
 * Sport.h
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#ifndef SPORT_H_
#define SPORT_H_
#include"Voiture.h"
namespace std {

class Sport : public Voiture{
public:
	Sport();
	virtual ~Sport();
	string exporter();
	string afficher();
};

} /* namespace std */

#endif /* SPORT_H_ */

