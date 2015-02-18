
/***********************************************************************
 * Module:  ImpalaJones.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 00:21:31
 * Purpose: Declaration of the class ImpalaJones
 ***********************************************************************/

#if !defined(__ImpalaJones_ImpalaJones_h)
#define __ImpalaJones_ImpalaJones_h
#include "Plateau.h"
#include "Pion.h"
using namespace std;

class ImpalaJones {
public:
	ImpalaJones(){
		this->position=-1;
	}
	~ImpalaJones(){}

	/* Je utilise pas cette fonction */
	/**
	 * if getPositionPossible()==(-1,-1,-1) => false else true
	 */
	bool isPositionPossibleExist(Plateau plateau){
		if((getPositionPossible(plateau)[0])==-1&&(getPositionPossible(plateau)[0]==-1)&&(getPositionPossible(plateau)[0]==-1)){
			return false;
		}else{
			return true;
		}
	}

	int* getPositionPossible(Plateau plateau)  {
		int* positionsPossible= new int[3];
		cout << "position actual : " << plateau.getImpalaPositions(position) << endl;
		/* Le debut du jeu */
		if(position == -1){
			cout << "1er etape" << endl;//for test
			positionsPossible[0] = -2;
			positionsPossible[1] = -2;
			positionsPossible[2] = -2;
		}

		/* On donne les positions possibles par rapport la position d'Impala Jones */
		else{
			cout << "n eme etape" << endl;//for test
			string nomLigneColumn;
			/* 1er position possible */
			int nbLigneColum = position + 1;
			if(nbLigneColum > 21){
				nbLigneColum = nbLigneColum - 22;
			}
			nomLigneColumn = plateau.getImpalaPositions(nbLigneColum);
			cout << "1er LigneOuColumn : " << nomLigneColumn <<endl;//for test
			/* Column */
			if(nomLigneColumn[0] == 'C'){
				cout << "column" <<endl;//for test
				/* string -> int */
				int nbColumn = nomLigneColumn[1]-48;
				cout << "nbColumn : " << nomLigneColumn[1] << endl;//for test
				cout << "nbColumn : " << nbColumn << endl;//for test
				/* verifier y a case libre pour pion dans column ou pas */
				bool libre = false;
				for(int i =0; i< 5; i++){
					if(plateau.getCases()[i][nbColumn]->pion == NULL){
						libre = true;
						break;
					}
				}
				if(libre == true){
					positionsPossible[0] = nbLigneColum;
				}else{
					positionsPossible[0] = -1;
				}
			/* Ligne */
			} else {
				cout << "Ligne" << endl; //for test
				/* string -> int */
				int nbLigne = nomLigneColumn[1] - 48;
				cout << "nbLigne : " << nomLigneColumn[1] << endl; //for test
				cout << "nbLigne : " << nbLigne << endl; //for test
				/* verifier y a case libre pour pion dans column ou pas */
				bool libre = false;
				for (int i = 0; i < 6; i++) {
					if (plateau.getCases()[nbLigne][i]->pion == NULL) {
						libre = true;
						break;
					}
				}
				if (libre == true) {
					positionsPossible[0] = nbLigneColum;
				} else {
					positionsPossible[0] = -1;
				}
			}

			/* 2eme position possible */
			nbLigneColum = position + 2;
			if (nbLigneColum > 21) {
				nbLigneColum = nbLigneColum - 22;
			}
			nomLigneColumn = plateau.getImpalaPositions(nbLigneColum);
			cout << "2eme LigneOuColumn : " << nomLigneColumn << endl; //for test
			/* Column */
			if (nomLigneColumn[0] == 'C') {
				cout << "column" << endl; //for test
				/* string -> int */
				int nbColumn = nomLigneColumn[1] - 48;
				cout << "nbColumn : " << nomLigneColumn[1] << endl; //for test
				cout << "nbColumn : " << nbColumn << endl; //for test
				/* verifier y a case libre pour pion dans column ou pas */
				bool libre = false;
				for (int i = 0; i < 5; i++) {
					if (plateau.getCases()[i][nbColumn]->pion == NULL) {
						libre = true;
						break;
					}
				}
				if (libre == true) {
					positionsPossible[1] = nbLigneColum;
				} else {
					positionsPossible[1] = -1;
				}
				/* Ligne */
			} else {
				cout << "Ligne" << endl; //for test
				/* string -> int */
				int nbLigne = nomLigneColumn[1] - 48;
				cout << "nbLigne : " << nomLigneColumn[1] << endl; //for test
				cout << "nbLigne : " << nbLigne << endl; //for test
				/* verifier y a case libre pour pion dans column ou pas */
				bool libre = false;
				for (int i = 0; i < 6; i++) {
					if (plateau.getCases()[nbLigne][i]->pion == NULL) {
						libre = true;
						break;
					}
				}
				if (libre == true) {
					positionsPossible[1] = nbLigneColum;
				} else {
					positionsPossible[1] = -1;
				}
			}

			/* 3eme position possible */
			nbLigneColum = position + 3;
			if (nbLigneColum > 21) {
				nbLigneColum = nbLigneColum - 22;
			}
			nomLigneColumn = plateau.getImpalaPositions(nbLigneColum);
			cout << "3eme LigneOuColumn : " << nomLigneColumn << endl; //for test
			/* Column */
			if (nomLigneColumn[0] == 'C') {
				cout << "column" << endl; //for test
				/* string -> int */
				int nbColumn = nomLigneColumn[1] - 48;
				cout << "nbColumn : " << nomLigneColumn[1] << endl; //for test
				cout << "nbColumn : " << nbColumn << endl; //for test
				/* verifier y a case libre pour pion dans column ou pas */
				bool libre = false;
				for (int i = 0; i < 5; i++) {
					if (plateau.getCases()[i][nbColumn]->pion == NULL) {
						libre = true;
						break;
					}
				}
				if (libre == true) {
					positionsPossible[2] = nbLigneColum;
				} else {
					positionsPossible[2] = -1;
				}
				/* Ligne */
			} else {
				cout << "Ligne" << endl; //for test
				/* string -> int */
				int nbLigne = nomLigneColumn[1] - 48;
				cout << "nbLigne : " << nomLigneColumn[1] << endl; //for test
				cout << "nbLigne : " << nbLigne << endl; //for test
				/* verifier y a case libre pour pion dans column ou pas */
				bool libre = false;
				for (int i = 0; i < 6; i++) {
					if (plateau.getCases()[nbLigne][i]->pion == NULL) {
						libre = true;
						break;
					}
				}
				if (libre == true) {
					positionsPossible[2] = nbLigneColum;
				} else {
					positionsPossible[2] = -1;
				}
			}
		}

		/* Tous les 3 lignes ou columns sont occupes */
		if (positionsPossible[0] == -1 && positionsPossible[1] == -1
				&& positionsPossible[2] == -1) {
			int nbBoucle = 0;
			string nomLigneColumn;
			int nbLigneColum = position + 4;
			while (nbBoucle < 22 - 3) {
				if (nbLigneColum > 21) {
					nbLigneColum = nbLigneColum - 22;
				}
				nomLigneColumn = plateau.getImpalaPositions(nbLigneColum);
				/* Column */
				if (nomLigneColumn[0] == 'C') {
					cout << "column" << endl; //for test
					/* string -> int */
					int nbColumn = nomLigneColumn[1] - 48;
					cout << "nbColumn : " << nomLigneColumn[1] << endl; //for test
					cout << "nbColumn : " << nbColumn << endl; //for test
					/* verifier y a case libre pour pion dans column ou pas */
					bool libre = false;
					for (int i = 0; i < 5; i++) {
						if (plateau.getCases()[i][nbColumn]->pion == NULL) {
							libre = true;
							break;
						}
					}
					if (libre == true) {
						positionsPossible[2] = nbLigneColum;
						break;
					} else {
						positionsPossible[2] = -1;
					}
					/* Ligne */
				} else {
					cout << "Ligne" << endl; //for test
					/* string -> int */
					int nbLigne = nomLigneColumn[1] - 48;
					cout << "nbLigne : " << nomLigneColumn[1] << endl; //for test
					cout << "nbLigne : " << nbLigne << endl; //for test
					/* verifier y a case libre pour pion dans column ou pas */
					bool libre = false;
					for (int i = 0; i < 6; i++) {
						if (plateau.getCases()[nbLigne][i]->pion == NULL) {
							libre = true;
							break;
						}
					}
					if (libre == true) {
						positionsPossible[2] = nbLigneColum;
						break;
					} else {
						positionsPossible[2] = -1;
					}
				}
			nbLigneColum++;
			nbBoucle++;
			}
		}

		cout <<"positionsPossible[0] : "<< positionsPossible[0] << endl;//for test
		cout <<"positionsPossible[1] : " <<positionsPossible[1] << endl;//for test
		cout <<"positionsPossible[2] : " <<positionsPossible[2] << endl;//for test
		return positionsPossible;
	}

	void setPosition(int position) {
		this->position = position;
	}

	int getPosition() const {
		return position;
	}

protected:
private:
	int position;

};

#endif
