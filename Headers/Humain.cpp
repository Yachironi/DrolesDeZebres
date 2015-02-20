/*
 * Humain.cpp
 *
 *  Created on: 19 févr. 2015
 *      Author: yachironi
 */

#include "Humain.h"

#include "Plateau.h"

int Humain::gettacticImpalaJonesPosition(Plateau* plateau) {
	int positionImpalaJones = -1;
	positionImpalaJones = plateau->saisirImpalaJonesPosition();
	return positionImpalaJones;
}
int* Humain::gettacticPositionPionAdeposer(Plateau* plateau) {
	int* positionPionAdeposer = new int[2];
	positionPionAdeposer = plateau->saisirPositionPion();
	return positionPionAdeposer;
}
int Humain::gettacticTypePionAdeposer() {
	int pionAdeposer = -1;
	pionAdeposer = saisirPionAdeposer();
	return pionAdeposer;
}
