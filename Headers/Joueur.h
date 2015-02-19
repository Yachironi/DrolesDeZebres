/***********************************************************************
 * Module:  Joueur.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 10:55:58
 * Purpose: Declaration of the class Joueur
 ***********************************************************************/

#if !defined(__ImpalaJones_Joueur_h)
#define __ImpalaJones_Joueur_h

#include <string>
#include <vector>

#include "Pion.h"

class Partie;

class ImpalaJones;
class Plateau;

using namespace std;

class Pion;

class Joueur {
	static int id;
public:
	Joueur(string pseudo);
	void jouer(Plateau* plateau, Partie* partie);
	bool isPionTypeEstDisponnible(int pionAdeposer);
	void getPionsRestants();
	int getIdJoueur() const;
	void setIdJoueur(int idJoueur);
	const string& getPseudo() const;
	void setPseudo(const string& pseudo);
	int getScore() const;
	void setScore(int score);
	const vector<int>& getInauguration() const;
	void setInauguration(const vector<int>& inauguration);
	int saisirPionAdeposer();
	virtual int gettacticImpalaJonesPosition(Plateau* plateau);
	virtual int* gettacticPositionPionAdeposer(Plateau* plateau);
	virtual int gettacticTypePionAdeposer();
	void setPionsRestant(int nbG, int nbZ, int nbE, int nbL, int nbC);
	void inaugurationUpdate(int i, int j, Plateau* plateau, Partie* partie);
	//string getImpalaJonesPossibleString(Plateau* plateau);
	//bool isImpalaPositionDisponnible(int positionImpalaJones,int* positionImpalaPossible);
	bool isFinJeux(int *positionImpalaPossible);

	const vector<vector<Pion*> >& getPions() const {
		return pions;
	}

	void setPions(const vector<vector<Pion*> >& pions) {
		this->pions = pions;
	}

protected:
private:
	vector<vector<Pion*>> pions;
	int score;
	int idJoueur;
	string pseudo;
};

#endif
