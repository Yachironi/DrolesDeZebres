
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
	static vector<vector<Case*>> CONFIGURATIONSTANDARD; // configuration 0
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

	void setCases(int i, int j,Pion* pion) {
		this->cases[i][j]->pion = pion;
	}

	friend ostream& operator<<(ostream& os, const Plateau& plateau) {
		/*
		char c[11][13];
					for (int i = 0; i < 5; i++){
						for (int j = 0; j < 5; j++){
							if (plateau.cases[i][j]->getIdSecteur() != plateau.cases[i][j + 1]->getIdSecteur()){
								c[2 * i + 1][2 * j + 2] = '|';
							}
							else c[2 * i + 1][2 * j + 2] = ' ';
						}
					}

					for (int i = 0; i < 6; i++){
						for (int j = 0; j < 4; j++){
							c[2 * j + 2][2 * i] = ' ';
							if (plateau.cases[j][i]->getIdSecteur() != plateau.cases[j + 1][i]->getIdSecteur()){
								c[2 * j + 2][2 * i + 1] = '-';
							}
							else c[2 * j + 2][2 * i + 1] = ' ';
						}
					}

					for (int i = 0; i < 5; i++){
						for (int j = 0; j < 6; j++){
							if (plateau.cases[i][j]->pion == NULL){
								c[2 * i + 1][2 * j + 1] = '0';
							}
							else if(plateau.cases[i][j]->pion->isCache()){
								c[2 * i + 1][2 * j + 1] = '#';
							}
							else {
								string pionType = plateau.cases[i][j]->pion->getIntitulePion();
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
						os << endl;
						for (int j = 0; j < 13; j++){
							os << c[i][j];
						}
					}
					os << endl;
					return os;
					*/

				string c[13][35];
							for (int i = 0; i < 5; i++){
								for (int j = 0; j < 5; j++){
									if (plateau.cases[i][j]->getIdSecteur() != plateau.cases[i][j + 1]->getIdSecteur()){
										c[2 * i + 2][5 * j + 1 + 6] = '|';
									}
									else c[2 * i + 2][5 * j + 1 + 6] = ' ';
								}
							}

							for (int i = 0; i < 6; i++){
								for (int j = 0; j < 4; j++){
									c[2 * j + 3][5 * i + 2] = ' ';
									if (plateau.cases[j][i]->getIdSecteur() != plateau.cases[j + 1][i]->getIdSecteur()){
										c[2 * j + 3][5 * i + 3] = "----";
									}
									else c[2 * j + 3][5 * i + 3] = "    ";
								}
							}

							for (int i = 0; i < 5; i++){
								for (int j = 0; j < 6; j++){
									if (plateau.cases[i][j]->pion == NULL){
										c[2 * i + 2][5 * j + 3] = "0(0)";

									}
									else if(plateau.cases[i][j]->pion->isCache()){
										c[2 * i + 2][5 * j + 3] = "#(0)";
									}
									//TODO change!!!
									else {
										string pionType = plateau.cases[i][j]->pion->getIntitulePion();
										//Le Zebre
										if (pionType == "Zebre") c[2 * i + 2][5 * j + 3] = "--Z-";
										//La Gazelle
										else if (pionType == "Gazelle") c[2 * i + 2][5 * j + 3] = 'G';
										//Le Lion
										else if (pionType == "Lion") c[2 * i + 2][5 * j + 3] = 'L';
										//L'Elephant
										else if (pionType == "Elephant") c[2 * i + 2][5 * j + 3] = 'L';
										//Le Crocodile
										else if (pionType == "Elephant") c[2 * i + 2][5 * j + 3] = '0';
									}
								}
							}

							//afficher la frontiere
							for (int i = 1; i < 11; i++){
								c[i][2] = '|';
								c[i][32] = '|';
							}
							for(int i =1;i<31;i++){
								c[1][i+1] = "-";
								c[11][i+1] = "-";
							}
							c[1][2] = 'X';
							c[1][32] = 'X';
							c[11][2] = 'X';
							c[11][32] = 'X';


							//afficher le chemin d'Impala Jones
							c[0][0] = 'X';
							c[0][34] = 'X';
							c[12][0] = 'X';
							c[12][34] = 'X';
							for (int i = 1; i < 34; i++){
									c[0][i] = ' ';
									c[12][i] = ' ';
							}
							for (int i = 1; i < 12; i++){
									c[i][0] = "  ";
									c[i][33] = "  ";
							}

							c[0][4] = '0';
							c[0][9] = '1';
							c[0][14] = '2';
							c[0][19] = '3';
							c[0][24] = '4';
							c[0][29] = '5';
							c[2][33] = '6';
							c[4][33] = '7';
							c[6][33] = '8';
							c[8][33] = '9';
							c[10][33] = "10";
							c[10][0] = "17";
							c[8][0] = "18";
							c[6][0] = "19";
							c[4][0] = "20";
							c[2][0] = "21";

							// afficher la table de char
							for (int i = 0; i < 13; i++){
								os << endl;
								for (int j = 0; j < 35; j++){
									os << c[i][j];
								}
							}
							os << endl;
							return os;
		}

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
