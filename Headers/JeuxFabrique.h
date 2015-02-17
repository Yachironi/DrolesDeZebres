/***********************************************************************
 * Module:  JeuxFabrique.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 10:55:01
 * Purpose: Declaration of the class JeuxFabrique
 ***********************************************************************/

#if !defined(__ImpalaJones_JeuxFabrique_h)
#define __ImpalaJones_JeuxFabrique_h

#include <vector>

#include "Partie.h"
#include "Plateau.h"

using namespace std;
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
//#include "stdlib.h"
class JeuxFabrique {
public:
	static Partie* init();
	static Partie* initJeux();
	static Partie* initJeuxSauvgarde();
	static Partie* initMultijoueur();
	static Partie* initContrePC();

protected:
private:

};

Partie* JeuxFabrique::init() {
	Partie* partieFabrique;
	string typeJeux;
	cout << "Veillez saisir le type de jeux :" << endl;
	cout << "1 - Nouvelle partie \n2 - Charger une partie\n3 - Quit" << endl;
	cin >> typeJeux;
	int typeJeuxInt = atoi(typeJeux.c_str());
	while (typeJeuxInt != 1 && typeJeuxInt != 2 && typeJeuxInt != 3) {
		cin >> typeJeux;
		typeJeuxInt = atoi(typeJeux.c_str());
	}
	switch (typeJeuxInt) {
	case 1:
		partieFabrique=initJeux();
		cout << "Fin initialiation jeux a deux" << endl;
		break;
	case 2:
		partieFabrique=initJeuxSauvgarde();
		cout << "typeJeux = 2" << endl;
		cout << "Fin chargement de jeux" << endl;

		break;
	case 3:
		exit(0);
	default:
		cout << "default";

		break;
	}
	return partieFabrique;
	exit(0);
}

Partie* JeuxFabrique::initJeux() {
	Partie* partieFabrique;
	string modeJeux;
	cout << "Veillez saisir le mode de jeux :" << endl;
	cout << "1 - Multijoueur \n2 - Contre ordinateur\n3 - Quit" << endl;
	cin >> modeJeux;
	int modeJeuxInt = atoi(modeJeux.c_str());
	while (modeJeuxInt != 1 && modeJeuxInt != 2 && modeJeuxInt != 3) {
		cin >> modeJeuxInt;
		modeJeuxInt = atoi(modeJeux.c_str());
	}
	switch (modeJeuxInt) {
	case 1:
		partieFabrique=initMultijoueur();
		break;
	case 2:
		partieFabrique=initContrePC();
		break;
	case 3:
		exit(0);
	default:
		cout << "default";
		break;
	}
	return partieFabrique;
	exit(0);
}

Partie* JeuxFabrique::initJeuxSauvgarde() {
	Partie* partieFabrique = NULL;
	string initJeuxSauvgarde;
	while (initJeuxSauvgarde != "NON TROUVE") {
		cout << "Fichier non trouve" << endl;
	}
	return partieFabrique;
}

Partie* JeuxFabrique::initMultijoueur() {
	Partie* partieFabrique;
	cout << "Jeux Multjoureur :" << endl;
	Plateau* plateau = new Plateau(Plateau::CONFIGURATIONSTANDARD);
	ImpalaJones* impalaJones = new ImpalaJones();
	vector<Joueur*> joueurs;
	string pseudo;
	cout<<"Veuillez saisir le pseudo du premier joueur : ";
	cin>>pseudo;
	joueurs.push_back(new Joueur(pseudo));
	cout<<"Veuillez saisir le pseudo du deuxieme joueur : ";
	cin>>pseudo;
	joueurs.push_back(new Joueur(pseudo));
	partieFabrique = new Partie(plateau,impalaJones,joueurs);
	return partieFabrique;
}
Partie* JeuxFabrique::initContrePC() {
	Partie* partieFabrique = NULL;
	cout << "Jeux contre PC" << endl;
	return partieFabrique;
}

#endif
