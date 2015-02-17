/***********************************************************************
 * Module:  Joueur.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 10:55:58
 * Purpose: Declaration of the class Joueur
 ***********************************************************************/

#if !defined(__ImpalaJones_Joueur_h)
#define __ImpalaJones_Joueur_h

#include <string>
#include "../Headers/Pion.h"
#include "../Headers/Gazelle.h"
using namespace std;

class Pion;

class Joueur {
	static int id;
public:
	Joueur(string pseudo) :
			pseudo(pseudo) {
		this->score = 0;
		this->idJoeur = id++;
		this->pseudo = pseudo;
		pion.push_back(new Gazelle());
		/*pion = {
			new Gazelle(),new Gazelle(),new Gazelle(),
			new Gazelle(),new Gazelle(),new Gazelle(),
			new Zebre(),new Zebre(),new Zebre(),new Zebre(),new Zebre(),
			new Elephant(),
			new Lion(),
			new Crocodile(),new Crocodile()
		};*/
	}

protected:
private:
	vector<Pion*> pion;
	int score;
	int idJoeur;
	string pseudo;
};
int Joueur::id = 0;

#endif
