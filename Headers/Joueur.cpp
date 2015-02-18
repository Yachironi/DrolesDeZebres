/*
 * Joueur.cpp
 *
 *  Created on: 18 févr. 2015
 *      Author: yachironi
 */

#include "Joueur.h"
#include <string>
#include <iostream>

#include "Case.h"
#include "Crocodile.h"
#include "Elephant.h"
#include "Gazelle.h"
#include "ImpalaJones.h"
#include "Lion.h"
#include "Plateau.h"
#include "Zebre.h"

Joueur::Joueur(string pseudo) :
		pseudo(pseudo), pions(5, vector<Pion*>()) {
	this->score = 0;
	this->idJoueur = id++;
	this->pseudo = pseudo;
	/* Ajout des pions du joueur */
	for (unsigned int i = 0; i < 6; i++)
		pions[0].push_back(new Gazelle(idJoueur));
	for (unsigned int i = 0; i < 5; i++)
		pions[1].push_back(new Zebre(idJoueur));
	pions[2].push_back(new Elephant(idJoueur));
	pions[3].push_back(new Lion(idJoueur));
	pions[4].push_back(new Crocodile(idJoueur));
	pions[4].push_back(new Crocodile(idJoueur));
}

void Joueur::jouer(Plateau* plateau, ImpalaJones* impalaJones) {
	cout << "Tour Joueur " << pseudo << endl;
	int i = -1, j = -1;
	cout<<"=======> DEB SAISIE <======="<<endl;

	cout << "Position  ImpalaJones = " << plateau->getImpalaJones()->getPosition()<< endl;
	cout << "Veillez saisir votre movement [i,j]:" << endl;
	cin >> i;
	cin >> j;
	while (!plateau->estPossible(i, j)) {
		cout << "Veillez saisir votre movement [i,j]:" << endl;
		cin >> i;
		cin >> j;
	}
	cout<<"=======> FIN SAISIE <======="<<endl;

	int pionAdeposer = 0;
	cout << "Veuillez choisir le pion à deposer :" << endl;
	getPionsRestants();
	cin >> pionAdeposer;
	while (!isPionTypeEstDisponnible(pionAdeposer)) {
		cin >> pionAdeposer;
	}
	pionAdeposer--;
	plateau->getCases()[i][j]->pion = pions[pionAdeposer].front();
	pions[pionAdeposer].erase(pions[pionAdeposer].begin());
	//getPionsRestants();

	int* positionImpalaPossible =plateau->getImpalaJones()->getPositionPossible(plateau);
	int positionImpalaJones=-1;
	if (!isFinJeux(positionImpalaPossible)) {
		cout << "Veuillez choisir la position de ImpalaJones :" << endl;
		cout << getImpalaJonesPossibleString(plateau);
		cin >> positionImpalaJones;
		while (!isImpalaPositionDisponnible(positionImpalaJones,
				positionImpalaPossible)) {
			cin >> positionImpalaJones;
		}
		cout << "La Position choisit pour Impala est " << positionImpalaJones
				<< endl;
		plateau->getImpalaJones()->setPosition(positionImpalaJones);
	}
	cout << *plateau << endl;

}

bool Joueur::isFinJeux(int *positionImpalaPossible) {
	if (positionImpalaPossible[0] == -1 && positionImpalaPossible[1] == -1
			&& positionImpalaPossible[2] == -1) {
		return true;
	} else {
		return false;
	}
}

bool Joueur::isPionTypeEstDisponnible(int pionAdeposer) {

	if ((pionAdeposer > 0 && pionAdeposer < 6)) {
		if (pions[pionAdeposer].size() > 0) {
			return true;
		} else {
			cout << "Ce type n\'existe plus" << endl;
			return false;
		}
	} else {
		cout << "Le choix ne figure pas sur la liste" << endl;
		return false;
	}
}

string Joueur::getImpalaJonesPossibleString(Plateau* plateau) {
	int* positionImpalaPossible =
			plateau->getImpalaJones()->getPositionPossible(plateau);
	string res = "[ ";
	if (positionImpalaPossible[0] >= 0) {
		res = res + to_string(positionImpalaPossible[0]);
	}
	if (positionImpalaPossible[1] >= 0) {
		res = res + " , " + to_string(positionImpalaPossible[1]);
	}
	if (positionImpalaPossible[2] >= 0) {
		res = res + " , " + to_string(positionImpalaPossible[2]);
	}
	res += " ]";
	return res;
}

bool Joueur::isImpalaPositionDisponnible(int positionImpalaJones,
		int* positionImpalaPossible) {
	if (positionImpalaJones >= 0) {
		if (positionImpalaJones != positionImpalaPossible[0]
				&& positionImpalaJones != positionImpalaPossible[1]
				&& positionImpalaJones != positionImpalaPossible[2]) {
			return false;
		} else {
			return true;
		}
	} else {
		return false;
	}
}

void Joueur::getPionsRestants() {
	cout << "[ [1] Gazelle : " << pions[0].size();
	cout << " | [2] Zebre : " << pions[1].size();
	cout << " | [3] Elephant : " << pions[2].size();
	cout << " | [4] Lion : " << pions[3].size();
	cout << " | [5] Crocodile : " << pions[4].size() << "]\n";

}
int Joueur::getIdJoueur() const {
	return idJoueur;
}

void Joueur::setIdJoueur(int idJoueur) {
	this->idJoueur = idJoueur;
}

const string& Joueur::getPseudo() const {
	return pseudo;
}

void Joueur::setPseudo(const string& pseudo) {
	this->pseudo = pseudo;
}

int Joueur::getScore() const {
	return score;
}

void Joueur::setScore(int score) {
	this->score = score;
}

const vector<int>& Joueur::getInauguration() const {
	return inauguration;
}

void Joueur::setInauguration(const vector<int>& inauguration) {
	this->inauguration = inauguration;
}

void Joueur::addInaugurationForIdScteur(int idSecteur) {
	inauguration.push_back(idSecteur);
}

int Joueur::id = 0;
