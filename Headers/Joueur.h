
/***********************************************************************
 * Module:  Joueur.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 10:55:58
 * Purpose: Declaration of the class Joueur
 ***********************************************************************/

#if !defined(__ImpalaJones_Joueur_h)
#define __ImpalaJones_Joueur_h



#include <iostream>
#include <string>
#include <vector>

#include "Crocodile.h"
#include "Elephant.h"
#include "Gazelle.h"
#include "Lion.h"
#include "Pion.h"
#include "Zebre.h"

class ImpalaJones;
class Plateau;

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
		/* Ajout des pions du joueur */
		for (unsigned int i = 0; i < 6; ++i) pion.push_back(new Gazelle());
		for (unsigned int i = 0; i < 5; ++i) pion.push_back(new Zebre());
		pion.push_back(new Elephant());
		pion.push_back(new Lion());
		pion.push_back(new Crocodile());
		pion.push_back(new Crocodile());
	}
	void jouer(Plateau* plateau,ImpalaJones* impalaJones){
		cout<<"Tour Joueur "<<pseudo<<endl;
		cout<<"Veillez seaisir votre"<<endl;
		int x;
		cin>>x;
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
