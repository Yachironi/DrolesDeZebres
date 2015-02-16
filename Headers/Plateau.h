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

	static vector<vector<Case*>> getConfigurationDuPresident(){
			// TODO Verification de la configuration
			vector<vector<Case*>> configurationDuPresident = {
				{new Case(0),new Case(3),new Case(3),new Case(3),new Case(5),new Case(5)},
				{new Case(0),new Case(1),new Case(1),new Case(3),new Case(3),new Case(5)},
				{new Case(0),new Case(1),new Case(2),new Case(2),new Case(3),new Case(3)},
				{new Case(1),new Case(1),new Case(2),new Case(4),new Case(4),new Case(3)},
				{new Case(2),new Case(2),new Case(2),new Case(2),new Case(4),new Case(3)}
											};
			return configurationDuPresident;
		}

		static vector<vector<Case*>> getConfigurationStandard(){
			// TODO Verification de la configuration
			vector<vector<Case*>> configurationStandard = 	{
				{new Case(0),new Case(2),new Case(3),new Case(3),new Case(3),new Case(3)},
				{new Case(0),new Case(2),new Case(2),new Case(3),new Case(5),new Case(5)},
				{new Case(0),new Case(0),new Case(2),new Case(3),new Case(3),new Case(5)},
				{new Case(1),new Case(0),new Case(2),new Case(2),new Case(2),new Case(4)},
				{new Case(1),new Case(1),new Case(4),new Case(4),new Case(4),new Case(4)}
													};
				return configurationStandard;
			}

	Plateau(vector<vector<Case*>> configuration){
		cases=configuration;
		impalaJones=NULL;
	}

	const vector<vector<Case*> >& getCases() const {
		return cases;
	}

	void setCases(const vector<vector<Case*> >& cases) {
		this->cases = cases;
	}

	void afficher() {
		char c[9][11];
		
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				if (cases[i][j]->getIdSecteur() != cases[i][j + 1]->getIdSecteur()){
						c[2*i][2 * j + 1] = '|';
				}
				else c[2*i][2 * j + 1] = ' ';
			}
		}

		for (int i = 0; i < 6; i++){
			for (int j = 0; j < 4; j++){
				c[2*j+1][2*i + 1] =' ';
				if (cases[j][i]->getIdSecteur() != cases[j+1][i]->getIdSecteur()){
					c[2*j+1][2 * i] = '-';
				}
				else c[2*j+1][2 * i] = ' ';
			}
		}

		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 6; j++){
				//c[2 * i][2 * j] = (char)cases[i][j]->getIdSecteur;
				c[2 * i][2 * j] = '0';
			}
		}

		// afficher la table de char 
		for (int i = 0; i < 9; i++){
			cout << endl;
			for (int j = 0; j < 11; j++){
				cout << c[i][j];
			}
		}
		cout << endl;
	}
protected:
private:
	vector<vector<Case*>> cases;
	ImpalaJones* impalaJones;
	map<char, int> impalaPositions;


};

vector<vector<Case*>> Plateau::CONFIGURATIONDUPRESIDENT=Plateau::getConfigurationDuPresident();
vector<vector<Case*>> Plateau::CONFIGURATIONSTANDARD=Plateau::getConfigurationStandard();

#endif
