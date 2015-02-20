/***********************************************************************
 * Module:  JeuxFabrique.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 10:55:01
 * Purpose: Declaration of the class JeuxFabrique
 ***********************************************************************/

#if !defined(__ImpalaJones_JeuxFabrique_h)
#define __ImpalaJones_JeuxFabrique_h

#include <vector>

#include "Humain.h"
#include "ImpalaJones.h"
#include "Ordinateur.h"
#include "Partie.h"
#include "Plateau.h"

using namespace std;
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "stdlib.h"
class JeuxFabrique {
public:
	static Partie* init();
	static Partie* initJeux();
	static Partie* initJeuxSauvgarde();
	static Partie* initMultijoueur();
	static Partie* initContrePC();
	static Partie* chargerPartie(string nomFichier);

protected:
private:

};

Partie* JeuxFabrique::init() {

	cout << "+-------------------------------------------+"<< endl;
	cout << "|      Bienvenue a Drole de Zebres          |"<< endl;
	cout << "+-------------------------------------------+"<< endl;
	cout<<endl<<endl;
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
		partieFabrique = initJeux();
		break;
	case 2:
		partieFabrique = initJeuxSauvgarde();
		break;
	case 3:
		exit(0);
	default:
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
		cin >> modeJeux;
		modeJeuxInt = atoi(modeJeux.c_str());
	}

	switch (modeJeuxInt) {
	case 1:
		partieFabrique = initMultijoueur();
		break;
	case 2:
		partieFabrique = initContrePC();
		break;
	case 3:
		exit(0);
	default:

		break;
	}
	return partieFabrique;
	exit(0);
}
Partie* JeuxFabrique::chargerPartie(string nomFichier) {
	Partie* partieFabrique = NULL;
	Plateau* plateau = new Plateau(Plateau::CONFIGURATIONSTANDARD);
	ImpalaJones* impalaJones = new ImpalaJones();
	vector<Joueur*> joueurs;

	char buffer[256];
	fstream out;
	out.open(nomFichier.c_str(), ios::in);
	/* charger et verifier le type de partie */
	out.getline(buffer, 256, '\n');
	if (stol(buffer) == 0) {
		joueurs.push_back(new Humain("1"));
		joueurs.push_back(new Humain("2"));
	} else {
		joueurs.push_back(new Ordinateur());
		joueurs.push_back(new Humain("1"));
	}

	partieFabrique = new Partie(plateau, impalaJones, joueurs);
	/* charger le plateau dans le fichier (5*6=30 lignes) */
	for (int i = 0; i < 30; i++) {
		out.getline(buffer, 256, '\n');
		/* split une ligne dans string informations[4] */
		string informations[4];
		char * pch;
		pch = strtok(buffer, " ");
		int k = 0;
		while (pch != NULL) {
			informations[k] = pch;
			pch = strtok(NULL, " ");
			k++;
		}
		/* case est NULL */
		if (informations[0] == "0") {
			plateau->setCases(i / 6, i % 6, NULL);
		}
		/* y a pion dans la case */
		else {
			/* idJoueur */
			int idJoueurTemp = stol(informations[2]);
			/* creer new TypeDePion par rapport informations[1] */
			Pion* pionTemp;
			if (informations[1] == "G") {
				pionTemp = new Gazelle(idJoueurTemp);
			} else if (informations[1] == "Z") {
				pionTemp = new Zebre(idJoueurTemp);
			} else if (informations[1] == "E") {
				pionTemp = new Elephant(idJoueurTemp);
			} else if (informations[1] == "L") {
				pionTemp = new Lion(idJoueurTemp);
			} else if (informations[1] == "C") {
				pionTemp = new Crocodile(idJoueurTemp);
			}
			/* n'est pas Cache */
			if (informations[3] == "0") {
				pionTemp->setCache(false);
			}
			/* isCache */
			else {
				pionTemp->setCache(true);
			}
			plateau->setCases(i / 6, i % 6, pionTemp);
		}
	}
	/* 31eme ligne : charger position d'ImpalaJones */
	out.getline(buffer, 256, '\n');
	int impalaPosition = stol(buffer);
	plateau->getImpalaJones()->setPosition(impalaPosition);
	/* 32eme ligne : charger int tour */
	out.getline(buffer, 256, '\n');
	int tour = stol(buffer);
	partieFabrique->setTour(tour);
	/* enregistrer les 2 joueurs */
	for (int i = 0; i < 2; i++) {
		out.getline(buffer, 256, '\n');
		/* split une ligne dans string informations[2] */
		string informations[2];
		char * pch;
		pch = strtok(buffer, " ");
		int k = 0;
		while (pch != NULL) {
			informations[k] = pch;
			pch = strtok(NULL, " ");
			k++;
		}
		/* charger idJouerur et Pseudo "idJoueur(int) pseudo(string)" */
		int idJoueur = stol(informations[0]);
		joueurs[i]->setIdJoueur(idJoueur);
		joueurs[i]->setPseudo(informations[1]);

		/* charger le nombre des 5 types de pion "nbGazelle nbZebre nbElephant nbLion nbCrocodile" */
		out.getline(buffer, 256, '\n');
		/* split une ligne dans string informations[2] */
		string informationsBis[5];
		char * pchBis;
		pchBis = strtok(buffer, " ");
		int kBis = 0;
		while (pchBis != NULL) {
			informationsBis[kBis] = pchBis;
			pchBis = strtok(NULL, " ");
			kBis++;
		}
		int nbG = stol(informationsBis[0]);
		int nbZ = stol(informationsBis[1]);
		int nbE = stol(informationsBis[2]);
		int nbL = stol(informationsBis[3]);
		int nbC = stol(informationsBis[4]);
		joueurs[i]->setPionsRestant(nbG, nbZ, nbE, nbL, nbC);

		//joueurs[i]->setPionsRestant(1,2,3,4,5);
	}

	/* charger isInnaugure(bool) */
	out.getline(buffer, 256, '\n');
	int isInnaugure = stol(buffer);
	partieFabrique->setIsInnaugure(isInnaugure);

	out.close();

	return partieFabrique;
}

Partie* JeuxFabrique::initJeuxSauvgarde() {
	Partie* partieFabrique = NULL;

	string nomFichier;
	cout << "Veillez Saisir le nom du fichier de sauvgarde :" << endl;
	cin >> nomFichier;

	while (1) {
		//verifier nomFichier existe ou pas
		fstream _file;
		_file.open(nomFichier.c_str(), ios::in);
		if (!_file) {
			cout << nomFichier << " n'existe pas." << endl;
			cout << "Veillez Saisir le nom du fichier de sauvgarde :" << endl;
			cin >> nomFichier;
		} else {
			break;
		}


		_file.close();
	}

	partieFabrique = chargerPartie(nomFichier);

	return partieFabrique;
}

Partie* JeuxFabrique::initMultijoueur() {
	Partie* partieFabrique;
	cout << "Jeux Multjoureur :" << endl;

	Plateau* plateau = new Plateau(Plateau::CONFIGURATIONSTANDARD);
	ImpalaJones* impalaJones = new ImpalaJones();
	vector<Joueur*> joueurs;

	string pseudo;
	cout << "Veuillez saisir le pseudo du premier joueur : ";
	cin >> pseudo;
	joueurs.push_back(new Humain(pseudo));
	cout << "Veuillez saisir le pseudo du deuxieme joueur : ";
	cin >> pseudo;

	joueurs.push_back(new Humain(pseudo));

	partieFabrique = new Partie(plateau, impalaJones, joueurs);
	partieFabrique->setTypePartie(0);
	return partieFabrique;
}
Partie* JeuxFabrique::initContrePC() {
	Partie* partieFabrique = NULL;
	cout << "Jeux contre Ordinateur" << endl;

	Plateau* plateau = new Plateau(Plateau::CONFIGURATIONSTANDARD);
	ImpalaJones* impalaJones = new ImpalaJones();
	vector<Joueur*> joueurs;
	string pseudo;
	joueurs.push_back(new Ordinateur());
	cout << "Veuillez saisir votre pseudo : ";
	cin >> pseudo;
	joueurs.push_back(new Humain(pseudo));
	partieFabrique = new Partie(plateau, impalaJones, joueurs);

	partieFabrique->setTypePartie(1);

	return partieFabrique;
}

#endif
