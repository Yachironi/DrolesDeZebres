/*
 * Partie.cpp
 *
 *  Created on: 20 févr. 2015
 *      Author: yachironi
 */

#include "Partie.h"
#include <ctime>
void Partie::start() {
	std::srand(std::time(0));
	cout << "+-------------------------------------------+"<< endl;
	cout <<"             "<< joueurs[0]->getPseudo()<<"   VS   "<<joueurs[1]->getPseudo()<< endl;
	cout << "+-------------------------------------------+"<< endl;
	cout<<endl<<endl;
	//copy(inauguration.begin(), inauguration.end(), ostream_iterator<int>(cout, " "));
/*
	plateau->setCases(0, 0, new Gazelle(0));
	plateau->setCases(0, 1, new Zebre(0));
	plateau->setCases(0, 2, new Lion(0));
	plateau->setCases(0, 3, new Zebre(1));
	plateau->setCases(0, 4, new Zebre(1));
	plateau->setCases(0, 5, new Zebre(1));

	plateau->setCases(1, 0, new Gazelle(0));
	plateau->setCases(1, 1, new Zebre(0));
	plateau->setCases(1, 2, new Lion(0));
	plateau->setCases(1, 3, new Zebre(1));
	plateau->setCases(1, 4, new Zebre(1));
	plateau->setCases(1, 5, new Zebre(1));

	plateau->setCases(2, 0, new Gazelle(0));
	plateau->setCases(2, 1, new Zebre(0));
	plateau->setCases(2, 2, new Lion(0));
	plateau->setCases(2, 3, new Zebre(1));
	plateau->setCases(2, 4, new Zebre(1));
	plateau->setCases(2, 5, new Zebre(1));

	plateau->setCases(3, 0, new Gazelle(0));
	plateau->setCases(3, 1, new Zebre(0));
	plateau->setCases(3, 2, new Lion(0));
	plateau->setCases(3, 3, new Zebre(1));
	plateau->setCases(3, 4, new Zebre(1));
	plateau->setCases(3, 5, new Zebre(1));

	plateau->setCases(4, 0, new Gazelle(0));
	plateau->setCases(4, 1, new Zebre(0));
	plateau->setCases(4, 2, new Lion(0));
	plateau->setCases(4, 3, new Lion(0));*/

	/*plateau->setCases(0, 2, pionJoueur2);
	 plateau->setCases(1, 2, pionJoueur2);
	 plateau->setCases(2, 2, pionJoueur2);
	 plateau->setCases(3, 2, pionJoueur1);
	 plateau->setCases(4, 2, pionJoueur1);

	 plateau->setCases(0, 3, pionJoueur2);
	 plateau->setCases(1, 3, pionJoueur2);
	 plateau->setCases(2, 3, pionJoueur2);
	 plateau->setCases(3, 3, pionJoueur1);
	 plateau->setCases(4, 3, pionJoueur1);

	 plateau->setCases(0, 4, pionJoueur2);
	 plateau->setCases(1, 4, pionJoueur2);
	 plateau->setCases(2, 4, pionJoueur2);
	 plateau->setCases(3, 4, pionJoueur1);
	 plateau->setCases(4, 4, pionJoueur1);

	 plateau->setCases(0, 5, pionJoueur2);
	 plateau->setCases(1, 5, pionJoueur2);
	 plateau->setCases(2, 5, pionJoueur2);
	 plateau->setCases(3, 5, pionJoueur1);
	 plateau->setCases(4, 5, pionJoueur1);

	 plateau->setCases(1, 0, pionJoueur2);
	 plateau->setCases(2, 0, pionJoueur2);
	 plateau->setCases(3, 0, pionJoueur1);
	 plateau->setCases(4, 0, pionJoueur1);*/

	//cout << *plateau;

	int* positionImpalaPossible =
			plateau->getImpalaJones()->getPositionPossible(plateau);
	if (tour == -1)
		tour = 0;
	while (!isFinJeux(positionImpalaPossible)) {
		joueurs[tour]->jouer(plateau, this);
		tour = abs(tour - 1);
		continueOuQuitter();
		positionImpalaPossible = plateau->getImpalaJones()->getPositionPossible(
				plateau);
		if (!isFinJeux(positionImpalaPossible)) {
			joueurs[tour]->jouer(plateau, this);
			tour = abs(tour - 1);
			continueOuQuitter();
		} else {
			break;
		}
	}

	Joueur* gagnant = getGagnant();
	//Joueur* gagnant = getGagnantByIdSecteur(0);
	cout << joueurs[0]->getPseudo() << " = " << joueurs[0]->getScore() << " VS "
			<< joueurs[1]->getPseudo() << " = " << joueurs[1]->getScore()
			<< endl;
	cout << "Le gagnant est : " << gagnant->getPseudo() << endl;

}

void Partie::continueOuQuitter() {
	string commande;
	cout<< "[ \'C\' ] = Continuer | [ \'S\' ] = Sauvegarde : | [ \'Q\' ] = Quitter : "<<endl;
	cin.clear();
	//commande = cin.get();
	//commande = cin.get();
	cin >> commande;
	if ((commande.compare("c")!=0)&&(commande.compare("C")!=0)) {
		while ((commande.compare("s")!=0)&&(commande.compare("S")!=0)&&(commande.compare("q")!=0)&&(commande.compare("Q")!=0)&&(commande.compare("c")!=0)&&(commande.compare("C")!=0)) {
			commande = cin.get();
		}
		if ((commande.compare("q")==0)||(commande.compare("Q")==0)) {
			cout << "Sauvegarde ? [ o/n ] : ";
			char commande = cin.get();
			while (commande != 'o' && commande != 'n') {
				commande = cin.get();
			}
			if (commande == 'o' || commande == 'O') {
				enregistrer();
				cout << "Sauvegarde fait avec succes." << endl;
				cout << "Au revoir et a bientot..." << endl;
				exit(0);
			}else{
				cout << "Au revoir et a bientot..." << endl;
				exit(0);
			}
		} else if ((commande.compare("s")==0)||(commande.compare("S")==0)) {
			enregistrer();
			cout << "Sauvegarde fait avec succes." << endl;
			cout << "Continuer ? [ o/n ] : ";
			char commande = cin.get();
			while (commande != 'o' && commande != 'n') {
				commande = cin.get();
			}
			if (commande == 'n' || commande == 'N') {
				cout << "Au revoir et a bientot..." << endl;
				exit(0);
			}
		}
	}
}

bool Partie::isFinJeux(int *positionImpalaPossible) {
	if (positionImpalaPossible[0] == -1 && positionImpalaPossible[1] == -1
			&& positionImpalaPossible[2] == -1) {
		return true;
	} else {
		return false;
	}
}

Joueur* Partie::getGagnant() {
	/* On a que 6 secteurs*/
	int idSecteur = 0;
	;
	for (idSecteur = 0; idSecteur < 6; idSecteur++) {
		Joueur* gagnant = getGagnantByIdSecteur(idSecteur);
		/* Ajout de Points d'inauguration */
//			if (find(gagnant->getInauguration().begin(),
//					gagnant->getInauguration().end(), idSecteur)
//					!= gagnant->getInauguration().end()) {
//				gagnant->setScore(gagnant->getScore() + 5);
//			}
		/* Parcour du plateau pour calculer le score final sur le secteur */
		for (unsigned int i = 0; i < plateau->getCases().size(); i++) {
			for (unsigned int j = 0; j < plateau->getCases()[0].size(); j++) {
				if ((plateau->getCases()[i][j]->getIdSecteur() == idSecteur)
						&& (plateau->getCases()[i][j]->pion != NULL)) {
					if (!plateau->getCases()[i][j]->pion->isCache()) {
						gagnant->setScore(
								gagnant->getScore()
										+ plateau->getCases()[i][j]->pion->getValeur());
					}
				}
			}
		}
	}

	if (joueurs[0]->getScore() > joueurs[1]->getScore()) {

		return joueurs[0];
	} else {

		return joueurs[1];
	}
}
Joueur* Partie::getGagnantByIdSecteur(int idSecteur) {
	/* Parcours de t */

	int nbrPionsJoueurId1 = 0, nbrPionsJoueurId2 = 0;
	for (unsigned int i = 0; i < plateau->getCases().size(); i++) {
		for (unsigned int j = 0; j < plateau->getCases()[0].size(); j++) {
			int idSecteurTMP = plateau->getCases()[i][j]->getIdSecteur();
			if ((idSecteur == idSecteurTMP)
					&& (plateau->getCases()[i][j]->pion != NULL)) {
				int idJoeurTMP = plateau->getCases()[i][j]->pion->getIdJoueur();
				if (idJoeurTMP == 0) {
					nbrPionsJoueurId1++;
				} else if (idJoeurTMP == 1) {
					nbrPionsJoueurId2++;
				}
			}
		}
	}
	if (nbrPionsJoueurId1 > nbrPionsJoueurId2) {
		return joueurs[0];
	} else {
		return joueurs[1];
	}

}

void Partie::saisirImpalaJonesPosition() {
	int positionImpalaJones = -1;
	int* positionImpalaPossible =
			plateau->getImpalaJones()->getPositionPossible(plateau);
	if (!isFinJeux(positionImpalaPossible)) {
		cout << "Veuillez choisir la position de ImpalaJones :" << endl;
		cout << getImpalaJonesPossibleString(plateau);
		cin >> positionImpalaJones;
		while (!isImpalaPositionDisponnible(positionImpalaJones,
				positionImpalaPossible)) {
			cin >> positionImpalaJones;
		}
		cout << "La Position choisit pour Impala est " << positionImpalaJones
				<< endl;
	}
	plateau->getImpalaJones()->setPosition(positionImpalaJones);
}

string Partie::getImpalaJonesPossibleString(Plateau* plateau) {
	int* positionImpalaPossible =
			plateau->getImpalaJones()->getPositionPossible(plateau);
	string res = "[ ";
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

bool Partie::isImpalaPositionDisponnible(int positionImpalaJones,
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

/* enregistrer la partie */
void Partie::enregistrer() {
	string nomFichier;
	cout << "Veillez Saisir le nom du fichier de sauvgarde :" << endl;
	cin >> nomFichier;
	ofstream in;
	in.open(nomFichier.c_str(), ios::trunc);
	/* enregistrer typeParie(int) */
	in << typePartie << "\n";

	/* enregistrer plateau dans le fichier (5*6=30 lignes) */
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			Pion* pionTemp = plateau->getCases()[i][j]->pion;
			/* y a pas de pion dans la case, on met 0 dans la ligne */
			if (pionTemp == NULL) {
				in << "0" << "\n";
			}
			/* si y a pion, on met "1 type(char) idJoueur(int) cache(bool)" */
			else {
				in << "1 " << pionTemp->getIntitulePion()[0] << " "
						<< pionTemp->getIdJoueur() << " " << pionTemp->isCache()
						<< "\n";
			}
		}
	}
	/* 31eme ligne : position d'ImpalaJones */
	in << plateau->getImpalaJones()->getPosition() << "\n";
	/* 32eme ligne : enregistrer int tour */
	in << tour << "\n";
	/* enregistrer les 2 joueurs */
	for (int i = 0; i < 2; i++) {
		/* enregistrer idJouerur et Pseudo "idJoueur(int) pseudo(string)" */
		in << joueurs[i]->getIdJoueur() << " " << joueurs[i]->getPseudo()
				<< "\n";
		/* enregistrer le nombre des 5 types de pion "nbGazelle nbZebre nbElephant nbLion nbCrocodile" */
		for (int j = 0; j < 5; j++) {
			in << joueurs[i]->getPions()[j].size() << " ";
		}
		in << "\n";
	}
	/* enregistrer isInnaugure(bool) */
	in << isInnaugure << "\n";

	in.close();
	cout << "enregistrer fini" << endl;		//TODO supprimer apres test

}
