/*
 * Voiture.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: gui
 */

#include "Voiture.h"
#include "sstream"
#include "iostream"
#include <SFML/Graphics.hpp>
namespace std {

Voiture::Voiture() {
	distanceParcourue = 0;
	vitesse = 100;
	nom = "voiture";
	type = "voiture";
}
sf::Sprite* Voiture::afficherImage() {
	sf::Texture *texture = new sf::Texture();
	texture->loadFromFile("images/" + type + "Resize.png");
	sf::Sprite *sprite = new sf::Sprite();
	sprite->setTexture(*texture);
	sprite->move(0, position);
	return sprite;
}
string Voiture::afficher() {
	int distancepx = (1200 * 100) / distanceParcourue;
	string text = nom + "(), distance :" + to_string(distanceParcourue);
	cout << text << endl;
	return text;
}
void Voiture::nitro() {
	distanceParcourue += vitesse * 2;
}
void Voiture::avancer() {
	distanceParcourue += vitesse;
}

void Voiture::reculer() {
	int vitesseReculon = vitesse / 2;
	distanceParcourue -= vitesseReculon;
}
void Voiture::operator++() {
	vitesse += 50 ;
	distanceParcourue = 0;
}
Voiture::~Voiture() {
	// TODO Auto-generated destructor stub
}

string Voiture::exporter(){
	stringstream xml;
	xml << "<voiture><nom>" << nom << "</nom>";
	xml << "<vitesse>" << vitesse << "</vitesse></voiture>";
	return xml.str();
}
void Voiture::setPosition(float position) {
	this->position = position;
}
int Voiture::getDistanceParcourue() {
	return distanceParcourue;
}
void Voiture::setNom(string nom){
this->nom = nom;
}
} /* namespace std */
