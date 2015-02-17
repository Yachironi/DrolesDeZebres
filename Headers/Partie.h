/***********************************************************************
 * Module:  Partie.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 00:20:03
 * Purpose: Declaration of the class Partie
 ***********************************************************************/

#if !defined(__ImpalaJones_Partie_h)
#define __ImpalaJones_Partie_h
#include "Plateau.h"
#include "ImpalaJones.h"
#include "Joueur.h"

using namespace std;

class Partie {
public:
	Partie(Plateau* plateau,ImpalaJones* impalaJones,vector<Joueur*> joueurs):plateau(plateau),impalaJones(impalaJones),joueurs(joueurs){
	}
	~Partie(){

	}
	/*
	 * Le jeux se deroule principalement ici
	 * */
	void start(){
		cout<<"Partie.start() : Jeux Commencé !!!"<<endl;
		cout<<*plateau;
	}

protected:
private:
	Plateau* plateau;
	ImpalaJones* impalaJones;
	vector<Joueur*> joueurs;
};

#endif
