/***********************************************************************
 * Module:  Partie.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 00:20:03
 * Purpose: Declaration of the class Partie
 ***********************************************************************/

#if !defined(__ImpalaJones_Partie_h)
#define __ImpalaJones_Partie_h

#include <algorithm> // for copy
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "Case.h"
#include "Joueur.h"
#include "Pion.h"
#include "Plateau.h"
#include "Zebre.h"

using namespace std;

class Partie {
public:

	Partie(Plateau* plateau, ImpalaJones* impalaJones, vector<Joueur*> joueurs) :
			plateau(plateau), joueurs(joueurs) {
		//this->plateau->getImpalaJones() = new ImpalaJones();
		this->plateau->getImpalaJones()->setPosition(
				impalaJones->getPosition());
	}
	~Partie() {

	}
	/*
	 * Le jeux se deroule principalement ici
	 * */
	/*
	 #############
	 # 1 # 2   2 #
	 # 1 #####   #
	 # 1   1 # 2 #
	 # 1   1 # 2 #
	 #############
	 */
	void start() {
		cout << "Partie.start() : Jeux Commencé !!!" << endl;
		//copy(inauguration.begin(), inauguration.end(), ostream_iterator<int>(cout, " "));

		Pion* pionJoueur1 = new Zebre(0);
		Pion* pionJoueur2 = new Zebre(1);
		plateau->setCases(0, 1, pionJoueur1);
		plateau->setCases(1, 1, pionJoueur1);
		plateau->setCases(2, 1, pionJoueur1);
		plateau->setCases(3, 1, pionJoueur2);
		plateau->setCases(4, 1, pionJoueur2);

		/*plateau->setCases(0, 2, pionJoueur2);
		plateau->setCases(1, 2, pionJoueur2);
		plateau->setCases(2, 2, pionJoueur2);
		plateau->setCases(3, 2, pionJoueur1);
		plateau->setCases(4, 2, pionJoueur1);

		plateau->setCases(0, 3, pionJoueur2);
		plateau->setCases(1, 3, pionJoueur2);
		plateau->setCases(2, 3, pionJoueur2);
		plateau->setCases(3, 3, pionJoueur1);
		plateau->setCases(4, 3, pionJoueur1);

		plateau->setCases(0, 4, pionJoueur2);
		plateau->setCases(1, 4, pionJoueur2);
		plateau->setCases(2, 4, pionJoueur2);
		plateau->setCases(3, 4, pionJoueur1);
		plateau->setCases(4, 4, pionJoueur1);

		plateau->setCases(0, 5, pionJoueur2);
		plateau->setCases(1, 5, pionJoueur2);
		plateau->setCases(2, 5, pionJoueur2);
		plateau->setCases(3, 5, pionJoueur1);
		plateau->setCases(4, 5, pionJoueur1);

		plateau->setCases(1, 0, pionJoueur2);
		plateau->setCases(2, 0, pionJoueur2);
		plateau->setCases(3, 0, pionJoueur1);
		plateau->setCases(4, 0, pionJoueur1);*/
		cout << *plateau;
		/*plateau->getImpalaJones() == NULL ?
				cout << "impala est NULL" : cout << "impala est  NON NULL";*/
		plateau->getImpalaJones()->setPosition(0);
		//joueurs[0]->jouer(plateau, impalaJones);
		int* positionImpalaPossible = plateau->getImpalaJones()->getPositionPossible(plateau);
		while (!isFinJeux(positionImpalaPossible)) {
			joueurs[0]->jouer(plateau, plateau->getImpalaJones());
			positionImpalaPossible =
					plateau->getImpalaJones()->getPositionPossible(plateau);
			if (!isFinJeux(positionImpalaPossible)) {
				joueurs[1]->jouer(plateau, plateau->getImpalaJones());
			} else {
				break;
			}
		}

		Joueur* gagnant = getGagnant();
		//Joueur* gagnant = getGagnantByIdSecteur(0);
		cout << joueurs[0]->getPseudo() << " = " << joueurs[0]->getScore()
				<< " VS " << joueurs[1]->getPseudo() << " = "
				<< joueurs[1]->getScore() << endl;
		cout << "Le gagnant est : " << gagnant->getPseudo() << endl;

	}
	bool isFinJeux(int *positionImpalaPossible) {
		if (positionImpalaPossible[0] == -1 && positionImpalaPossible[1] == -1
				&& positionImpalaPossible[2] == -1) {
			return true;
		} else {
			return false;
		}
	}

	Joueur* getGagnant() {
		/* On a que 6 secteurs*/
		int idSecteur = 0;
		;
		for (idSecteur = 0; idSecteur < 6; idSecteur++) {
			Joueur* gagnant = getGagnantByIdSecteur(idSecteur);
			/* Ajout de Points d'inauguration */
			if (find(gagnant->getInauguration().begin(),
					gagnant->getInauguration().end(), idSecteur)
					!= gagnant->getInauguration().end()) {
				gagnant->setScore(gagnant->getScore() + 5);
			}
			/* Parcour du plateau pour calculer le score final sur le secteur */
			for (unsigned int i = 0; i < plateau->getCases().size(); i++) {
				for (unsigned int j = 0; j < plateau->getCases()[0].size();
						j++) {
					if ((plateau->getCases()[i][j]->getIdSecteur() == idSecteur)
							&& (plateau->getCases()[i][j]->pion != NULL)) {
						if (!plateau->getCases()[i][j]->pion->isCache()) {
							gagnant->setScore(
									gagnant->getScore()
											+ plateau->getCases()[i][j]->pion->getValeur());
						}
					}
				}
			}
		}

		if (joueurs[0]->getScore() > joueurs[1]->getScore()) {

			return joueurs[0];
		} else {

			return joueurs[1];
		}
	}
	Joueur* getGagnantByIdSecteur(int idSecteur) {
		/* Parcours de t */

		int nbrPionsJoueurId1 = 0, nbrPionsJoueurId2 = 0;
		for (unsigned int i = 0; i < plateau->getCases().size(); i++) {
			for (unsigned int j = 0; j < plateau->getCases()[0].size(); j++) {
				int idSecteurTMP = plateau->getCases()[i][j]->getIdSecteur();
				if ((idSecteur == idSecteurTMP)
						&& (plateau->getCases()[i][j]->pion != NULL)) {
					int idJoeurTMP =
							plateau->getCases()[i][j]->pion->getIdJoueur();
					if (idJoeurTMP == 0) {
						nbrPionsJoueurId1++;
					} else if (idJoeurTMP == 1) {
						nbrPionsJoueurId2++;
					}
				}
			}
		}
		if (nbrPionsJoueurId1 > nbrPionsJoueurId2) {
			return joueurs[0];
		} else {
			return joueurs[1];
		}

	}
protected:
private:
	Plateau* plateau;
	int tour=-1;
	vector<Joueur*> joueurs;
};

#endif
