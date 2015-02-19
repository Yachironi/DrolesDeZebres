/***********************************************************************
 * Module:  Partie.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 00:20:03
 * Purpose: Declaration of the class Partie
 ***********************************************************************/

#if !defined(__ImpalaJones_Partie_h)
#define __ImpalaJones_Partie_h

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include<cstring>
#include<string>


#include "Case.h"
#include "Crocodile.h"
#include "Elephant.h"
#include "Gazelle.h"
#include "ImpalaJones.h"
#include "Joueur.h"
#include "Lion.h"
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

		plateau->setCases(2, 4, new Gazelle(0));
		plateau->setCases(3, 3, new Zebre(0));
		plateau->setCases(3, 5, new Lion(0));
		plateau->setCases(4, 4, new Zebre(1));
		plateau->setCases(4, 1, new Zebre(1));

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
		//plateau->getImpalaJones()->setPosition(0);
		//joueurs[0]->jouer(plateau, impalaJones);
		//saisirImpalaJonesPosition();
		int* positionImpalaPossible =
				plateau->getImpalaJones()->getPositionPossible(plateau);
		while (!isFinJeux(positionImpalaPossible)) {
			joueurs[0]->jouer(plateau, plateau->getImpalaJones());
			cout<<"DEB SAUVGUARDE"<<endl;
			enregistrer();
			cout<<"FIN SAUVGUARDE"<<endl;
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
//			if (find(gagnant->getInauguration().begin(),
//					gagnant->getInauguration().end(), idSecteur)
//					!= gagnant->getInauguration().end()) {
//				gagnant->setScore(gagnant->getScore() + 5);
//			}
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

	void saisirImpalaJonesPosition() {
		int positionImpalaJones = -1;
		int* positionImpalaPossible =
				plateau->getImpalaJones()->getPositionPossible(plateau);
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

	string getImpalaJonesPossibleString(Plateau* plateau) {
		int* positionImpalaPossible =
				plateau->getImpalaJones()->getPositionPossible(plateau);
		string res = "[ ";
		if (positionImpalaPossible[0] >= 0) {
			res = res + "  " + to_string(positionImpalaPossible[0]);
		}
		if (positionImpalaPossible[1] >= 0) {
			res = res + "  " + to_string(positionImpalaPossible[1]);
		}
		if (positionImpalaPossible[2] >= 0) {
			res = res + "  " + to_string(positionImpalaPossible[2]);
		}
		res += " ]";
		return res;
	}

	bool isImpalaPositionDisponnible(int positionImpalaJones,
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

	/* enregistrer la partie */
	void enregistrer() {
		ofstream in;
		in.open("partie0.txt", ios::trunc);
		/* enregistrer plateau dans le fichier (5*6=30 lignes) */
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 6; j++) {
				Pion* pionTemp = plateau->getCases()[i][j]->pion;
				/* y a pas de pion dans la case, on met 0 dans la ligne */
				if (pionTemp == NULL) {
					in << "0" << "\n";
				}
				/* si y a pion, on met "1 type(char) idJoueur(int) cache(bool)" */
				else {
					in << "1 " << pionTemp->getIntitulePion()[0] << " "
							<< pionTemp->getIdJoueur() << " "
							<< pionTemp->isCache() << "\n";
				}
			}
		}
		/* 31eme ligne : position d'ImpalaJones */
		in << plateau->getImpalaJones()->getPosition() << "\n";
		/* 32eme ligne : enregistrer int tour */
		in << tour << "\n";
		/* enregistrer les 2 joueurs */
		for (int i = 0; i < 2; i++) {
			/* enregistrer idJouerur et Pseudo "idJoueur(int) pseudo(string)" */
			in << joueurs[i]->getIdJoueur() << " " << joueurs[i]->getPseudo()
					<< "\n";
			/* enregistrer le nombre des 5 types de pion "nbGazelle nbZebre nbElephant nbLion nbCrocodile" */
			for (int j = 0; j < 5; j++) {
				in << joueurs[i]->getPions()[j].size() << " ";
			}
			in << "\n";
		}
		in.close();
		cout << "enregistrer fini" << endl;		//TODO supprimer apres test
	}

	bool isIsInnaugure() const {
		return isInnaugure;
	}

	void setIsInnaugure(bool isInnaugure) {
		this->isInnaugure = isInnaugure;
	}

	const vector<Joueur*>& getJoueurs() const {
		return joueurs;
	}

	void setJoueurs(const vector<Joueur*>& joueurs) {
		this->joueurs = joueurs;
	}

	Plateau* getPlateau(){
		return plateau;
	}

	int getTour() const {
		return tour;
	}

	void setTour(int tour = -1) {
		this->tour = tour;
	}

	int getTypeParie() const {
		return typeParie;
	}

	void setTypeParie(int typeParie) {
		this->typeParie = typeParie;
	}

protected:
private:
	Plateau* plateau;
	vector<Joueur*> joueurs;
	int typeParie;
	int tour = -1;
	bool isInnaugure;
};

#endif
