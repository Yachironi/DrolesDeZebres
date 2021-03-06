/***********************************************************************
 * Module:  Pion.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 10:52:26
 * Purpose: Declaration of the class Pion
 ***********************************************************************/

#if !defined(__ImpalaJones_Pion_h)
#define __ImpalaJones_Pion_h

typedef struct _position {
	int x = -1;
	int y = -1;
} Position;
using namespace std;

class Pion {
public:
	Pion(bool cache, int valeur, int idJoueur, string intitulePion) {
		this->cache = cache;
		this->valeur = valeur;
		this->idJoueur = idJoueur;
		this->intitulePion = intitulePion;
	}
	~Pion() {

	}
	bool isCache() const {
		return cache;
	}

	void setCache(bool cache) {
		this->cache = cache;
	}

	int getValeur() const {
		return valeur;
	}

	const string& getIntitulePion() const {
		return intitulePion;
	}

	void setIntitulePion(const string& intitulePion) {
		this->intitulePion = intitulePion;
	}

	int getIdJoueur() const {
		return idJoueur;
	}
//virtual string getType();
protected:
	bool cache; /* Pion cache ou pas {True , False}*/
	int valeur; /* Le nombre de points du pion */
	int idJoueur;
	string intitulePion;
private:

};

#endif
