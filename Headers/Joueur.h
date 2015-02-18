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

class ImpalaJones;
class Plateau;

using namespace std;

class Pion;

class Joueur {
	static int id;
public:
	Joueur(string pseudo);
	void jouer(Plateau* plateau, ImpalaJones* impalaJones);
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
	void addInaugurationForIdScteur(int idSecteur);
	string getImpalaJonesPossibleString(Plateau* plateau);
	bool isImpalaPositionDisponnible(int positionImpalaJones,int* positionImpalaPossible);
	bool isFinJeux(int *positionImpalaPossible);
protected:
private:
	vector<vector<Pion*>> pions;
	vector<int> inauguration;
	int score;
	int idJoueur;
	string pseudo;
};

#endif
