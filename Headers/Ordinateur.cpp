/*
 * Ordinateur.cpp
 *
 *  Created on: 19 févr. 2015
 *      Author: yachironi
 */

#include "Ordinateur.h"

#include <cstdlib>
#include <iostream>

#include "ImpalaJones.h"
#include "Plateau.h"

int Ordinateur::gettacticImpalaJonesPosition(Plateau* plateau) {
	int positionImpalaJones = -1;
	//cout<<"==> ICI <=="<<endl;
	/* Intelligence Artificiel */
	int* impalaPossiblePosition =
			plateau->getImpalaJones()->getPositionPossible(plateau);
	if (plateau->getImpalaJones()->getPosition() == -1) {
		positionImpalaJones = rand() % 22;
		//cout<<"==> F ICI 1 <=="<<endl;

		return positionImpalaJones;
	} else {
		int* positions = plateau->getImpalaJones()->getPositionPossible(
				plateau);
		positionImpalaJones = rand() % 3;

		while (positions[positionImpalaJones] < 0) {
			positionImpalaJones = rand() % 3;
		}
		//cout<<"==> F ICI 2 <=="<<endl;
		return impalaPossiblePosition[positionImpalaJones];

	}

}
int* Ordinateur::gettacticPositionPionAdeposer(Plateau* plateau) {
	//cout << "TACTIC ORDINATEUR PositionPionAdeposer : " << endl;

	int* positionPionAdeposer = new int[2];
	int position = plateau->getImpalaJones()->getPosition();
	int i, j;
	if ((position >= 0 && position <= 5)) {
		//cout<<"entree 1 "<<endl;
		// (j == position)
		j = position;
		i = rand() % 5;
		while (plateau->getCases()[i][j]->pion != NULL) {
			i = rand() % 5;
		}
	} else if (position <= 16 && position >= 11) {
		//cout<<"entree 2 "<<endl;
		// (j == 16 - position)

		j = 16 - position;
		i = rand() % 5;
		while (plateau->getCases()[i][j]->pion != NULL) {
			i = rand() % 5;
		}
	} else if (position >= 6 && position <= 10) {
		//cout<<"entree 3 "<<endl;
		// (i == position - 6)
		i = position - 6;
		j = rand() % 6;
		while (plateau->getCases()[i][j]->pion != NULL) {
			j = rand() % 6;
		}
	} else if (position >= 17 && position <= 21) {
		//cout<<"entree 4 "<<endl;
		//(i == 21 - position)
		i = 21 - position;
		j = rand() % 6;
		while (plateau->getCases()[i][j]->pion != NULL) {
			j = rand() % 6;
		}
	}
	positionPionAdeposer[0] = i;
	positionPionAdeposer[1] = j;
	return positionPionAdeposer;
}

int Ordinateur::gettacticTypePionAdeposer() {
	//cout << "TACTIC ORDINATEUR TYPE PION : " << endl;
	int pionAdeposer = -1;
	pionAdeposer = rand() % 5;
	while (!isPionTypeEstDisponnible(pionAdeposer)) {
		pionAdeposer = rand() % 5;
	}
	return pionAdeposer;
}
