
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
		this->idJoueur = id++;
		this->pseudo = pseudo;
		/* Ajout des pions du joueur */
		for (unsigned int i = 0; i < 6; i++) pions.push_back(new Gazelle(idJoueur));
		for (unsigned int i = 0; i < 5; i++) pions.push_back(new Zebre(idJoueur));
		pions.push_back(new Elephant(idJoueur));
		pions.push_back(new Lion(idJoueur));
		pions.push_back(new Crocodile(idJoueur));
		pions.push_back(new Crocodile(idJoueur));
	}
	void jouer(Plateau* plateau,ImpalaJones* impalaJones){
		cout<<"Tour Joueur "<<pseudo<<endl;
		cout<<"Veillez seaisir votre"<<endl;
		int x;
		cin>>x;
	}

	int getIdJoueur() const {
		return idJoueur;
	}

	void setIdJoueur(int idJoueur) {
		this->idJoueur = idJoueur;
	}

	const string& getPseudo() const {
		return pseudo;
	}

	void setPseudo(const string& pseudo) {
		this->pseudo = pseudo;
	}

	int getScore() const {
		return score;
	}

	void setScore(int score) {
		this->score = score;
	}

	const vector<int>& getInauguration() const {
		return inauguration;
	}

	void setInauguration(const vector<int>& inauguration) {
		this->inauguration = inauguration;
	}

	void addInaugurationForIdScteur(int idSecteur){
		inauguration.push_back(idSecteur);
	}
protected:
private:
	vector<Pion*> pions;
	vector<int> inauguration;
	int score;
	int idJoueur;
	string pseudo;
};
int Joueur::id = 0;

#endif
