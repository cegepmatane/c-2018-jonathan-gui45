/*
 * Voiture.h
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#ifndef VOITURE_H_
#define VOITURE_H_
#include <string>
#include <SFML/Graphics.hpp>
namespace std {

class Voiture {
public:
	Voiture();
	virtual ~Voiture();
	virtual string exporter();
	virtual void setNom(string nom);
	virtual void avancer();
	virtual void reculer();
	virtual string afficher();
	virtual void nitro();
	virtual int getDistanceParcourue();
	virtual void operator++();
	virtual sf::Sprite* afficherImage();
	virtual void setPosition(float position);
	virtual void setLongueurPiste(int longeur);
	float position;
	int distanceParcourue;
	int vitesse;
	int longeurPiste;
	string type;
	string nom;
};

} /* namespace std */

#endif /* VOITURE_H_ */
