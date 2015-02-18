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

#include "Case.h"
#include "Crocodile.h"
#include "Elephant.h"
#include "Gazelle.h"
#include "Lion.h"
#include "Pion.h"
#include "Plateau.h"
#include "Zebre.h"


using namespace std;

class Pion;

class Joueur {
	static int id;
public:
	Joueur(string pseudo) :
				pseudo(pseudo), pions(5, vector<Pion*>()) {
			this->score = 0;
			this->idJoueur = id++;
			this->pseudo = pseudo;
			/* Ajout des pions du joueur */
			for (unsigned int i = 0; i < 6; i++)
				pions[0].push_back(new Gazelle(idJoueur));
			for (unsigned int i = 0; i < 5; i++)
				pions[1].push_back(new Zebre(idJoueur));
			pions[2].push_back(new Elephant(idJoueur));
			pions[3].push_back(new Lion(idJoueur));
			pions[4].push_back(new Crocodile(idJoueur));
			pions[4].push_back(new Crocodile(idJoueur));
		}

		void jouer(Plateau* plateau, ImpalaJones* impalaJones) {
			cout << "Tour Joueur " << pseudo << endl;
			int i = -1, j = -1;
			cout << "Veillez saisir votre movement [i,j]:" << endl;
			cin >> i;
			cin >> j;
			while (!plateau->estPossible(i, j)) {
				cout << "Veillez saisir votre movement [i,j]:" << endl;
				cin >> i;
				cin >> j;
			}
			int pionAdeposer = 0;
			cout << "Veuillez choisir le pion à deposer :" << endl;
			getPionsRestants();
			cin >> pionAdeposer;
			while (!isPionTypeEstDisponnible(pionAdeposer)) {
				cin >> pionAdeposer;
			}
			pionAdeposer--;
			plateau->getCases()[i][j]->pion = pions[pionAdeposer].front();
			pions[pionAdeposer].erase(pions[pionAdeposer].begin());
			getPionsRestants();

			cout<<*plateau<<endl;

		}

		bool isPionTypeEstDisponnible(int pionAdeposer) {

			if ((pionAdeposer > 0 && pionAdeposer < 6)) {
				if (pions[pionAdeposer].size() > 0) {
					return true;
				} else {
					cout << "Ce type n\'existe plus" << endl;
					return false;
				}
			} else {
				cout << "Le choix ne figure pas sur la liste" << endl;
				return false;
			}
		}
		void getPionsRestants() {
			cout << "[ [1] Gazelle : " << pions[0].size();
			cout << " | [2] Zebre : " << pions[1].size();
			cout << " | [3] Elephant : " << pions[2].size();
			cout << " | [4] Lion : " << pions[3].size();
			cout << " | [5] Crocodile : " << pions[4].size() << "]\n";

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

		void addInaugurationForIdScteur(int idSecteur) {
			inauguration.push_back(idSecteur);
		}
protected:
private:
	vector<vector<Pion*>> pions;
	vector<int> inauguration;
	int score;
	int idJoueur;
	string pseudo;
};
int Joueur::id = 0;

#endif
