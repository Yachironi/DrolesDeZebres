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
	void start();
	void continueOuQuitter();
	bool isFinJeux(int *positionImpalaPossible);
	Joueur* getGagnant();

	Joueur* getGagnantByIdSecteur(int idSecteur);

	void saisirImpalaJonesPosition();

	string getImpalaJonesPossibleString(Plateau* plateau);

	bool isImpalaPositionDisponnible(int positionImpalaJones,int* positionImpalaPossible);
	/* enregistrer la partie */
	void enregistrer();

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

	Plateau* getPlateau() {
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
