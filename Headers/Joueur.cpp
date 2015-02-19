/*
 * Joueur.cpp
 *
 *  Created on: 18 févr. 2015
 *      Author: yachironi
 */

#include "Joueur.h"

#include <iostream>

#include "Case.h"
#include "Crocodile.h"
#include "Elephant.h"
#include "Gazelle.h"
#include "ImpalaJones.h"
#include "Lion.h"
#include "Partie.h"
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
/*Joueur::~Joueur(){

 }*/

void Joueur::jouer(Plateau* plateau, Partie* partie) {
	cout << "### DEB ### Tour de ===>   " << pseudo << "   <===" << endl;
	int i = -1, j = -1;
	if (plateau->getImpalaJones()->getPosition() == -1) {
		cout << *plateau << endl;
		int positionImpalaJones = gettacticImpalaJonesPosition(plateau);
		plateau->getImpalaJones()->setPosition(positionImpalaJones);
		cout << *plateau << endl;

	} else {
		cout << *plateau << endl;
		cout << "Position  ImpalaJones = "
				<< plateau->getImpalaJones()->getPosition() << endl;

		/* Saisie de position de pion*/
		//int* positionPionAdeposer = plateau->saisirPositionPion();
		int* positionPionAdeposer = gettacticPositionPionAdeposer(plateau);
		i = positionPionAdeposer[0];
		j = positionPionAdeposer[1];

		/* Saisie de type de pion */
		int pionAdeposer = 0;
		//pionAdeposer = saisirPionAdeposer();
		pionAdeposer = gettacticTypePionAdeposer();
		plateau->getCases()[i][j]->pion = pions[pionAdeposer].front();
		pions[pionAdeposer].erase(pions[pionAdeposer].begin());

		plateau->updateSelonReglesDeJeux(i, j);
		if (!partie->isIsInnaugure())
			inaugurationUpdate(i, j, plateau, partie);

		/* Saisie de position de ImpalaJones */
		//int positionImpalaJones = plateau->saisirImpalaJonesPosition();
		int* positionImpalaPossible =
				plateau->getImpalaJones()->getPositionPossible(plateau);
		if (!isFinJeux(positionImpalaPossible)) {
			int positionImpalaJones = gettacticImpalaJonesPosition(plateau);
			plateau->getImpalaJones()->setPosition(positionImpalaJones);
		}
		cout << *plateau << endl;

	}
	cout << "\n### FIN ### Tour de ===>   " << pseudo << "   <===\n" << endl;

}
void Joueur::inaugurationUpdate(int x, int y, Plateau* plateau,
		Partie* partie) {
	int idSecteur = -1;
	int nbrPionsJoueurId1 = 0, nbrPionsJoueurId2 = 0;
	bool innauguration = true;
	idSecteur = plateau->getCases()[x][y]->getIdSecteur();
	for (unsigned int i = 0; i < plateau->getCases().size(); i++) {
		for (unsigned int j = 0; j < plateau->getCases()[0].size(); j++) {
			if (plateau->getCases()[i][j]->getIdSecteur()
					== idSecteur&&plateau->getCases()[i][j]->pion==NULL) {
				innauguration = false;
				break;
			}

			int idSecteurTMP = plateau->getCases()[i][j]->getIdSecteur();
			if ((idSecteur == idSecteurTMP)
					&& (plateau->getCases()[i][j]->pion != NULL)) {
				int idJoeurTMP = plateau->getCases()[i][j]->pion->getIdJoueur();
				if (idJoeurTMP == 0) {
					nbrPionsJoueurId1++;
				} else if (idJoeurTMP == 1) {
					nbrPionsJoueurId2++;
				}
			}
		}
	}
	if (innauguration) {
		if (nbrPionsJoueurId1 > nbrPionsJoueurId2) {

			if (nbrPionsJoueurId1 == idJoueur) {
				score = 5;
				partie->setIsInnaugure(true);
			}
		} else {
			if (nbrPionsJoueurId2 == idJoueur) {
				score = 5;
				partie->setIsInnaugure(true);
			}
		}
	}
}
int Joueur::saisirPionAdeposer() {
	int pionAdeposer = -1;
	cout << "Veuillez choisir le pion à deposer :" << endl;
	getPionsRestants();
	cin >> pionAdeposer;
	while (!isPionTypeEstDisponnible(pionAdeposer)) {
		cin >> pionAdeposer;
	}
	pionAdeposer--;
	return pionAdeposer;
}

bool Joueur::isPionTypeEstDisponnible(int pionAdeposer) {
	cout << "" << endl;
	if ((pionAdeposer > 0 && pionAdeposer < 6)) {
		if (pions[pionAdeposer - 1].size() > 0) {
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

bool Joueur::isFinJeux(int *positionImpalaPossible) {
	if (positionImpalaPossible[0] == -1 && positionImpalaPossible[1] == -1
			&& positionImpalaPossible[2] == -1) {
		return true;
	} else {
		return false;
	}
}

void Joueur::setPionsRestant(int nbG, int nbZ, int nbE, int nbL, int nbC) {
	pions[0].erase(pions[0].begin(), pions[0].end());
	pions[1].erase(pions[1].begin(), pions[1].end());
	pions[2].erase(pions[2].begin(), pions[2].end());
	pions[3].erase(pions[3].begin(), pions[3].end());
	pions[4].erase(pions[4].begin(), pions[4].end());
	for (unsigned int i = 0; i < nbG; i++)
		pions[0].push_back(new Gazelle(idJoueur));
	for (unsigned int i = 0; i < nbZ; i++)
		pions[1].push_back(new Zebre(idJoueur));
	for (unsigned int i = 0; i < nbE; i++)
		pions[2].push_back(new Elephant(idJoueur));
	for (unsigned int i = 0; i < nbL; i++)
		pions[3].push_back(new Lion(idJoueur));
	for (unsigned int i = 0; i < nbC; i++)
		pions[4].push_back(new Crocodile(idJoueur));

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

int Joueur::gettacticImpalaJonesPosition(Plateau* plateau) {
	return -1;
}
int* Joueur::gettacticPositionPionAdeposer(Plateau* plateau) {
	return NULL;
}
int Joueur::gettacticTypePionAdeposer() {
	return -1;
}
;

int Joueur::id = 0;
