
/***********************************************************************
 * Module:  Plateau.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 10:55:14
 * Purpose: Declaration of the class Plateau
 ***********************************************************************/

#if !defined(__ImpalaJones_Plateau_h)
#define __ImpalaJones_Plateau_h

#include <map>
#include <vector>
#include <iostream>
#include "Case.h"
class ImpalaJones;

using namespace std;

class Plateau {
public:
	static vector<vector<Case*>> CONFIGURATIONDUPRESIDENT;
	static vector<vector<Case*>> CONFIGURATIONSTANDARD;
	static int configuration ;
	static vector<vector<Case*>> getConfigurationDuPresident(){
		// TODO Verification de la configuration
		vector<vector<Case*>> configurationDuPresident = {
			{ new Case(0), new Case(3), new Case(3), new Case(3), new Case(5), new Case(5) },
			{ new Case(0), new Case(1), new Case(1), new Case(3), new Case(3), new Case(5) },
			{ new Case(0), new Case(1), new Case(2), new Case(2), new Case(3), new Case(3) },
			{ new Case(1), new Case(1), new Case(2), new Case(4), new Case(4), new Case(3) },
			{ new Case(2), new Case(2), new Case(2), new Case(2), new Case(4), new Case(3) }
		};
		configuration=1;
		return configurationDuPresident;
	}

	static vector<vector<Case*>> getConfigurationStandard(){
		// TODO Verification de la configuration
		vector<vector<Case*>> configurationStandard = {
			{ new Case(0), new Case(2), new Case(3), new Case(3), new Case(3), new Case(3) },
			{ new Case(0), new Case(2), new Case(2), new Case(3), new Case(5), new Case(5) },
			{ new Case(0), new Case(0), new Case(2), new Case(3), new Case(3), new Case(5) },
			{ new Case(1), new Case(0), new Case(2), new Case(2), new Case(2), new Case(4) },
			{ new Case(1), new Case(1), new Case(4), new Case(4), new Case(4), new Case(4) }
		};
		configuration=0;
		return configurationStandard;
	}

	Plateau(vector<vector<Case*>> configuration){
		cases = configuration;
		impalaJones = NULL;
	}

	const vector<vector<Case*> >& getCases() const {
		return cases;
	}

	void setCases(const vector<vector<Case*> >& cases) {
		this->cases = cases;
	}
	friend ostream& operator<<(ostream& os, const Plateau& plateau) {
		os<<plateau.cases[0][0]<<endl;
		os<<"tableau"<<endl;
			return os;
		}
/*
	void afficher() {
		//char c[9][11];
		char c[11][13];
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				if (cases[i][j]->getIdSecteur() != cases[i][j + 1]->getIdSecteur()){
					c[2 * i + 1][2 * j + 2] = '|';
				}
				else c[2 * i + 1][2 * j + 2] = ' ';
			}
		}

		for (int i = 0; i < 6; i++){
			for (int j = 0; j < 4; j++){
				c[2 * j + 2][2 * i] = ' ';
				if (cases[j][i]->getIdSecteur() != cases[j + 1][i]->getIdSecteur()){
					c[2 * j + 2][2 * i + 1] = '-';
				}
				else c[2 * j + 2][2 * i + 1] = ' ';
			}
		}

		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 6; j++){
				if (cases[i][j]->pion == NULL){
					c[2 * i + 1][2 * j + 1] = '0';
				}
				else {
					string pionType = cases[i][j]->pion->getIntitulePion();
					//Le Zebre
					if (pionType == "Zebre") c[2 * i + 1][2 * j + 1] = 'Z';
					//La Gazelle
					else if (pionType == "Gazelle") c[2 * i + 1][2 * j + 1] = 'G';
					//Le Lion
					else if (pionType == "Lion") c[2 * i + 1][2 * j + 1] = 'L';
					//L'Elephant
					else if (pionType == "Elephant") c[2 * i + 1][2 * j + 1] = 'L';
					//Le Crocodile	
					else if (pionType == "Elephant") c[2 * i + 1][2 * j + 1] = '0';
				}
			}
		}

		// afficher le chemin d'Impala Jones
		c[0][0] = 'X';
		c[0][12] = 'X';
		c[10][0] = 'X';
		c[10][12] = 'X';

		for (int i = 1; i < 12; i++){
			c[0][i] = ' ';
			c[10][i] = ' ';
		}
		for (int i = 1; i < 10; i++){
			c[i][0] = ' ';
			c[i][12] = ' ';
		}

		// afficher la table de char 
		for (int i = 0; i < 11; i++){
			cout << endl;
			for (int j = 0; j < 13; j++){
				cout << c[i][j];
			}
		}
		cout << endl;
	}*/

protected:
private:
	vector<vector<Case*>> cases;
	ImpalaJones* impalaJones;
	map<char, int> impalaPositions;
};

vector<vector<Case*>> Plateau::CONFIGURATIONDUPRESIDENT = Plateau::getConfigurationDuPresident();
vector<vector<Case*>> Plateau::CONFIGURATIONSTANDARD = Plateau::getConfigurationStandard();
int Plateau::configuration;
#endif
