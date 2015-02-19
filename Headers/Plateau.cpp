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
		cout << i << " , " << j << endl;
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

					cout << "EFFRAYE !!! " << endl;
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
	cout<<"EFFRAYE APPEL"<<endl;
	cout << "i,j = " << i << " ," << j << endl;
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
						cout << "x,y = " << x << " ," << y << endl;
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
			cout<<"choix="<<choix<<endl;
			while((choix-1)<0||(choix-1)>choixDeSaute.size()){
				cin>>choix;
				cout<<"choix REPETE ="<<endl;
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
