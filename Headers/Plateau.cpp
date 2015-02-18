/*
 * Plateau.cpp
 *
 *  Created on: 18 févr. 2015
 *      Author: yachironi
 */

#include "Plateau.h"

#include <string>

#include "ImpalaJones.h"


vector<vector<Case*>> Plateau::CONFIGURATIONDUPRESIDENT = Plateau::getConfigurationDuPresident();
vector<vector<Case*>> Plateau::CONFIGURATIONSTANDARD = Plateau::getConfigurationStandard();
int Plateau::configuration;
vector<vector<Case*>> Plateau::getConfigurationDuPresident() {
	// TODO Verification de la configuration
	vector<vector<Case*>> configurationDuPresident = { { new Case(0), new Case(
			3), new Case(3), new Case(3), new Case(5), new Case(5) }, {
			new Case(0), new Case(1), new Case(1), new Case(3), new Case(3),
			new Case(5) }, { new Case(0), new Case(1), new Case(2), new Case(2),
			new Case(3), new Case(3) }, { new Case(1), new Case(1), new Case(2),
			new Case(4), new Case(4), new Case(3) }, { new Case(2), new Case(2),
			new Case(2), new Case(2), new Case(4), new Case(3) } };
	configuration = 1;
	return configurationDuPresident;
}

vector<vector<Case*>> Plateau::getConfigurationStandard() {
	// TODO Verification de la configuration
	vector<vector<Case*>> configurationStandard = { { new Case(0), new Case(2),
			new Case(3), new Case(3), new Case(3), new Case(3) }, { new Case(0),
			new Case(2), new Case(2), new Case(3), new Case(5), new Case(5) }, {
			new Case(0), new Case(0), new Case(2), new Case(3), new Case(3),
			new Case(5) }, { new Case(1), new Case(0), new Case(2), new Case(2),
			new Case(2), new Case(4) }, { new Case(1), new Case(1), new Case(4),
			new Case(4), new Case(4), new Case(4) } };
	configuration = 0;
	return configurationStandard;
}

Plateau::Plateau(vector<vector<Case*>> configuration) {
	cases = configuration;
	impalaJones = new ImpalaJones;
}

const vector<vector<Case*> >& Plateau::getCases() const {
	return cases;
}

void Plateau::setCases(int i, int j, Pion* pion) {
	this->cases[i][j]->pion = pion;
}

string Plateau::getImpalaPositions(int position) const {
	return impalaPositions[position];
}
ImpalaJones* Plateau::getImpalaJones() {
	return impalaJones;
}

bool Plateau::estPossible(int i, int j) {
	int lignes = cases.size();
	int colonnes = cases[0].size();
	if ((i > -1) && (i < lignes) && (j > -1) && (j < colonnes)) {
		cout << i << " , " << j << endl;
		if (cases[i][j]->pion == NULL) {
			return impalaJones->mouvementEstPossible(i, j);
		} else {
			cout << "La case est pleine" << endl;
			return false;
		}
	} else {
		cout << "Position Invalide" << endl;
		return false;
	}
}
