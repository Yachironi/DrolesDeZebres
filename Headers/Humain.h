/***********************************************************************
 * Module:  Humain.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 11:00:03
 * Purpose: Declaration of the class Humain
 ***********************************************************************/

#if !defined(__ImpalaJones_Humain_h)
#define __ImpalaJones_Humain_h

using namespace std;

#include "Joueur.h"

class Humain: public Joueur {
public:
	Humain(string pseudo) :
			Joueur(pseudo) {
	}

	virtual ~Humain(){

	}
	int gettacticImpalaJonesPosition(Plateau* plateau);
	int* gettacticPositionPionAdeposer(Plateau* plateau);
	int gettacticTypePionAdeposer();
	protected:
private:

};

#endif
