/*
 * Plateau.cpp
 *
 *  Created on: 18 févr. 2015
 *      Author: yachironi
 */

#include "Plateau.h"

#include <string>

#include "Animal.h"
#include "ImpalaJones.h"
#include "Type.h"

vector<vector<Case*>> Plateau::CONFIGURATIONDUPRESIDENT =
		Plateau::getConfigurationDuPresident();
vector<vector<Case*>> Plateau::CONFIGURATIONSTANDARD =
		Plateau::getConfigurationStandard();
int Plateau::configuration;
vector<vector<Case*>> Plateau::getConfigurationDuPresident() {
	// TODO Verification de la configuration
	vector<vector<Case*>> configurationDuPresident = { { new Case(0), new Case(
			3), new Case(3), new Case(3), new Case(5), new Case(5) }, {
			new Case(0), new Case(1), new Case(1), new Case(3), new Case(3),
			new Case(5) }, { new Case(0), new Case(1), new Case(2), new Case(2),
			new Case(3), new Case(3) }, { new Case(1), new Case(1), new Case(2),
			new Case(4), new Case(4), new Case(3) }, { new Case(2), new Case(2),
			new Case(2), new Case(2), new Case(4), new Case(3) } };
	configuration = 1;
	return configurationDuPresident;
}

vector<vector<Case*>> Plateau::getConfigurationStandard() {
	// TODO Verification de la configuration
	vector<vector<Case*>> configurationStandard = { { new Case(0), new Case(2),
			new Case(3), new Case(3), new Case(3), new Case(3) }, { new Case(0),
			new Case(2), new Case(2), new Case(3), new Case(5), new Case(5) }, {
			new Case(0), new Case(0), new Case(2), new Case(3), new Case(3),
			new Case(5) }, { new Case(1), new Case(0), new Case(2), new Case(2),
			new Case(2), new Case(4) }, { new Case(1), new Case(1), new Case(4),
			new Case(4), new Case(4), new Case(4) } };
	configuration = 0;
	return configurationStandard;
}

Plateau::Plateau(vector<vector<Case*>> configuration) {
	cases = configuration;
	impalaJones = new ImpalaJones;
}

const vector<vector<Case*> >& Plateau::getCases() const {
	return cases;
}

void Plateau::setCases(int i, int j, Pion* pion) {
	this->cases[i][j]->pion = pion;
}

string Plateau::getImpalaPositions(int position) const {
	return impalaPositions[position];
}
ImpalaJones* Plateau::getImpalaJones() {
	return impalaJones;
}

bool Plateau::estPossible(int i, int j) {
	int lignes = cases.size();
	int colonnes = cases[0].size();
	if ((i > -1) && (i < lignes) && (j > -1) && (j < colonnes)) {
		//cout << i << " , " << j << endl;
		if (cases[i][j]->pion == NULL) {
			return impalaJones->mouvementEstPossible(i, j);
		} else {
			cout << "La case est pleine" << endl;
			return false;
		}
	} else {
		cout << "Position Invalide" << endl;
		return false;
	}
}

int Plateau::saisirImpalaJonesPosition() {

	int positionImpalaJones = -1;
	//cout << "ImpalaPosition =" << this->impalaJones->getPosition() << endl;
	if (this->impalaJones->getPosition() == -1) {
	//	cout << "ImpalaPosition =" << this->impalaJones->getPosition() << endl;

		cout << "Veuillez choisir la position de ImpalaJones entre 0 et 21 "
				<< endl;
		cin >> positionImpalaJones;
		while (positionImpalaJones < 0 || positionImpalaJones > 21) {
			cin >> positionImpalaJones;
		}
	//	cout << "La Position choisit pour Impala est " << positionImpalaJones	<< endl;
		//this->getImpalaJones()->setPosition(positionImpalaJones);
	} else {
		//cout << "ImpalaPosition =" << this->impalaJones->getPosition() << endl;

		int* positionImpalaPossible =
				this->getImpalaJones()->getPositionPossible(this);
		cout << "Veuillez choisir la position de ImpalaJones :" << endl;
		cout << getImpalaJonesPossibleString();
		cin >> positionImpalaJones;
		while (!isImpalaPositionDisponnible(positionImpalaJones,
				positionImpalaPossible)) {
			cin >> positionImpalaJones;
		}
		//cout << "La Position choisit pour Impala est " << positionImpalaJones	<< endl;
		//this->getImpalaJones()->setPosition(positionImpalaJones);
	}
	return positionImpalaJones;
}

int* Plateau::saisirPositionPion(){
	int* positionPion = new int[2];
	cout << "Veillez saisir votre movement [i,j]:" << endl;
	cout<<"N° Ligne   = ";
	cin >> positionPion[0];
	cout<<"N° Colonne = ";
	cin >> positionPion[1];
	while (!this->estPossible(positionPion[0], positionPion[1])) {
		cout << "Veillez saisir votre movement [i,j]:" << endl;
		cout<<"N° Ligne   = ";
		cin >> positionPion[0];
		cout<<"N° Colonne = ";
		cin >> positionPion[1];
	}
	return positionPion;
}



string Plateau::getImpalaJonesPossibleString() {
	int* positionImpalaPossible = this->getImpalaJones()->getPositionPossible(
			this);
	string res = "[";
	if (positionImpalaPossible[0] >= 0) {
		res = res + "  " + to_string(positionImpalaPossible[0]);
	}
	if (positionImpalaPossible[1] >= 0) {
		res = res + "  " + to_string(positionImpalaPossible[1]);
	}
	if (positionImpalaPossible[2] >= 0) {
		res = res + "  " + to_string(positionImpalaPossible[2]);
	}
	res += " ]";
	return res;
}

bool Plateau::isImpalaPositionDisponnible(int positionImpalaJones,
		int* positionImpalaPossible) {
	if (positionImpalaJones >= 0) {
		if (positionImpalaJones != positionImpalaPossible[0]
				&& positionImpalaJones != positionImpalaPossible[1]
				&& positionImpalaJones != positionImpalaPossible[2]) {
			return false;
		} else {
			return true;
		}
	} else {
		return false;
	}
}

void Plateau::updateSelonReglesDeJeux(int i, int j) {
	TypeAnimal typeAnimal = ((Animal*) (cases[i][j]->pion))->getType();
	switch (typeAnimal) {
	case EFFRAYANT:
		updateEFFRAYANT(i, j);

		break;
	case EFFRAYE:
		updateEFFRAYE(i, j);
		break;
	case SAUTEUR:
		updateSAUTEUR(i, j);
		break;
	default:
		break;
	}
}

void Plateau::updateEFFRAYANT(int i, int j) {

	int listePionAtester[4][2] = { { i, j - 1 }, { i - 1, j }, { i, j + 1 }, { i
			+ 1, j } };
	int x, y;
	for (unsigned int c = 0; c < 4; c++) {
		x = listePionAtester[c][0];
		y = listePionAtester[c][1];
		//cout << "==> ICI <==" << endl;
		if (x < cases.size() && x >= 0 && y < cases[0].size() && y >= 0) {
			if ((cases[x][y]->pion != NULL)) {
				//cout<<"NON NULL !!! "<<endl;
				TypeAnimal typeAnimal =
						((Animal*) (cases[x][y]->pion))->getType();
				if (typeAnimal == EFFRAYE) {
					cout << "x,y = " << x << " ," << y << endl;

					//cout << "EFFRAYE !!! " << endl;
					cases[x][y]->pion->setCache(true);
				}
			}
		}
		//cout << "==> ICI <==" << endl;

	}
}
void Plateau::updateEFFRAYE(int i, int j) {
	int listePionAtester[4][2] = { { i, j - 1 }, { i - 1, j }, { i, j + 1 }, { i
			+ 1, j } };
	int x, y;
	//cout<<"EFFRAYE APPEL"<<endl;
	//cout << "i,j = " << i << " ," << j << endl;
	for (unsigned int c = 0; c < 4; c++) {
		x = listePionAtester[c][0];
		y = listePionAtester[c][1];
		//cout << "==> ICI <==" << endl;
		if (x < cases.size() && x >= 0 && y < cases[0].size() && y >= 0) {

			if ((cases[x][y]->pion != NULL)) {
				//cout<<"NON NULL !!! "<<endl;
				TypeAnimal typeAnimal =
						((Animal*) (cases[x][y]->pion))->getType();
				if (typeAnimal == EFFRAYANT) {
//					cout << "x,y = " << x << " ," << y << endl;
//					cout << "EFFRAYE !!! " << endl;
					cases[i][j]->pion->setCache(true);
					break;
				}
			}
		}
		//cout << "==> ICI <==" << endl;
	}
}
void Plateau::updateSAUTEUR(int i, int j) {
	int listePionAtester[4][2] = { { i, j - 1 }, { i - 1, j }, { i, j + 1 }, { i
				+ 1, j } };
		int x, y;
		vector<int*> choixDeSaute;
		for (unsigned int c = 0; c < 4; c++) {
			x = listePionAtester[c][0];
			y = listePionAtester[c][1];
			if (x < cases.size() && x >= 0 && y < cases[0].size() && y >= 0) {
				if ((cases[x][y]->pion != NULL)) {
					TypeAnimal typeAnimal =	((Animal*) (cases[x][y]->pion))->getType();
					if (cases[x][y]->pion->getIntitulePion()=="Gazelle"&&cases[i][j]->getIdSecteur()!=cases[x][y]->getIdSecteur()) {
						int* choix = new int[2];
						choix[0]=x;
						choix[1]=y;
						choixDeSaute.push_back(choix);
						//cout << "x,y = " << x << " ," << y << endl;
					}
				}
			}
		}
		if(choixDeSaute.size()>0){
			cout<<"Bonus : Choix de saute du crocodile ["<<i<<" , "<<j<<"] sur :"<<endl;
			cout<<"[";
			cout<<"  1=[PAS DE SAUTE]  ";
			for(unsigned int k=0;k<choixDeSaute.size();k++){
				cout<<"  "<<(k+2)<<"=["<<choixDeSaute[k][0]<<","<<choixDeSaute[k][1]<<"]  ";
			}
			cout<<"]"<<endl;
			int choix=-1;
			cin>>choix;
			//cout<<"choix="<<choix<<endl;
			while((choix-1)<0||(choix-1)>choixDeSaute.size()){
				cin>>choix;
				//cout<<"choix REPETE ="<<endl;
			}
			if((choix)>1){
				Pion* pionTMP;
				choix-=2;
				pionTMP=cases[choixDeSaute[choix][0]][choixDeSaute[choix][1]]->pion;
				cases[choixDeSaute[choix][0]][choixDeSaute[choix][1]]->pion=cases[i][j]->pion;
				cases[i][j]->pion=pionTMP;
				updateEFFRAYE(i,j);
			}
		}
}


ostream& operator<<(ostream& os, const Plateau& plateau) {
		string c[17][40];
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (plateau.cases[i][j]->getIdSecteur()
						!= plateau.cases[i][j + 1]->getIdSecteur()) {
					c[2 * i + 4][5 * j + 10] = '|';
				} else
					c[2 * i + 4][5 * j + 10] = ' ';
			}
		}

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 4; j++) {
				c[2 * j + 5][5 * i + 5] = ' ';
				if (plateau.cases[j][i]->getIdSecteur()
						!= plateau.cases[j + 1][i]->getIdSecteur()) {
					c[2 * j + 5][5 * i + 6] = "----";
				} else
					c[2 * j + 5][5 * i + 6] = "    ";
			}
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 6; j++) {
				if (plateau.cases[i][j]->pion == NULL) {
					c[2 * i + 4][5 * j + 6] = "    ";

				} else if (plateau.cases[i][j]->pion->isCache()) {
					c[2 * i + 4][5 * j + 6] = "####";
				} else {
					string pionType = plateau.cases[i][j]->pion->getIntitulePion();
					string pionNom = to_string(
							plateau.cases[i][j]->pion->getIdJoueur());
					//Le Zebre
					if (pionType == "Zebre") {
						string affichage = "Z( )";
						affichage[2] = pionNom[0];
						c[2 * i + 4][5 * j + 6] = affichage;
					}
					//La Gazelle
					else if (pionType == "Gazelle") {
						string affichage = "G( )";
						affichage[2] = pionNom[0];
						c[2 * i + 4][5 * j + 6] = affichage;
					}
					//Le Lion
					else if (pionType == "Lion") {
						string affichage = "L( )";
						affichage[2] = pionNom[0];
						c[2 * i + 4][5 * j + 6] = affichage;
					}
					//L'Elephant
					else if (pionType == "Elephant") {
						string affichage = "E( )";
						affichage[2] = pionNom[0];
						c[2 * i + 4][5 * j + 6] = affichage;
					}
					//Le Crocodile
					else if (pionType == "Crocodile") {
						string affichage = "C( )";
						affichage[2] = pionNom[0];
						c[2 * i + 4][5 * j + 6] = affichage;
					}
				}
			}
		}

		//afficher la frontiere interieur
		for (int i = 1; i < 11; i++) {
			c[i+2][5] = '|';
			c[i+2][35] = '|';
		}
		for (int i = 1; i < 31; i++) {
			c[3][i + 4] = "-";
			c[13][i + 4] = "-";
		}
		c[3][5] = '+';
		c[3][35] = '+';
		c[13][5] = '+';
		c[13][35] = '+';

		//afficher le chemin d'Impala Jones
		c[2][3] = ' ';
		c[2][37] = ' ';
		c[14][3] = ' ';
		c[14][37] = ' ';
		for (int i = 1; i < 34; i++) {
			c[2][i+3] = ' ';
			c[14][i+3] = ' ';
		}
		for (int i = 1; i < 12; i++) {
			c[i+2][3] = "  ";
			c[i+2][36] = "  ";
		}


		c[2][7] = '0';
		c[2][12] = '1';
		c[2][17] = '2';
		c[2][22] = '3';
		c[2][27] = '4';
		c[2][32] = '5';
		c[4][36] = "6 ";
		c[6][36] = "7 ";
		c[8][36] = "8 ";
		c[10][36] = "9 ";
		c[12][36] = "10";
		c[14][32] = '1';
		c[14][33] = '1';
		c[14][27] = '1';
		c[14][28] = '2';
		c[14][22] = '1';
		c[14][23] = '3';
		c[14][17] = '1';
		c[14][18] = '4';
		c[14][12] = '1';
		c[14][13] = '5';
		c[14][7] = '1';
		c[14][8] = '6';
		c[12][3] = "17";
		c[10][3] = "18";
		c[8][3] = "19";
		c[6][3] = "20";
		c[4][3] = "21";

		//afficher la frontiere intermediaire
		for (int i = 1; i < 14; i++) {
			c[i+1][2] = '|';
			c[i+1][38] = '|';
		}
		for (int i = 1; i < 36; i++) {
			c[1][i+2] = "-";
			c[15][i+2] = "-";
		}
		c[1][2] = '+';
		c[1][38] = '+';
		c[15][2] = '+';
		c[15][38] = '+';

		//afficher la coordonnee
		for (int i = 0; i < 17; i++) {
			c[i][0] = "  ";
			c[i][39] = ' ';
		}
		for (int i = 1; i < 38; i++) {
			c[0][i+1] = ' ';
			c[16][i+1] = ' ';
		}
		c[0][0] = '\\';
		c[0][3] = 'C';
		c[1][0] = "L ";
		c[0][8] = '0';
		c[0][13] = '1';
		c[0][18] = '2';
		c[0][23] = '3';
		c[0][28] = '4';
		c[0][33] = '5';
		c[4][0] = "0 ";
		c[6][0] = "1 ";
		c[8][0] = "2 ";
		c[10][0] = "3 ";
		c[12][0] = "4 ";

		//afficher la position d'ImpalaJones
		Plateau::afficherImpalaJones(plateau.impalaJones->getPosition(), c);

		// afficher la table de char
		for (int i = 0; i < 17; i++) {
			os << endl;
			for (int j = 0; j < 39; j++) {
				os << c[i][j];
			}
		}
		os << endl;
		return os;
	}

void Plateau::afficherImpalaJones(int position, string cases[17][40]){
			if((0 <=  position) && (position <= 21)){
				if((0 <= position) && (position<= 5)){
					cases[2][5*position+7] = 'X';
				}
				else if((6 <= position) && (position <= 9)){
					cases[(position-6)*2 + 4][36] = "X ";
				}
				else if(position == 10){
					cases[12][36] = "X ";
				}
				else if((11 <= position) && (position <= 16)){
					cases[14][32-5*(position-11)] = 'X';
					cases[14][33-5*(position-11)] = ' ';
				}
				else{
					cases[12-2*(position-17)][3] = "X ";
				}
			}
		}
