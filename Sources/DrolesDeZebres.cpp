/*
 * DrolesDeZebres.cpp
 *
 *  Created on: 31 janv. 2015
 *      Author: Yasser RABI & Zheng ZHANG
 */

#include <iostream>
#include <map>

#include "../Headers/Case.h"
#include "../Headers/JeuxFabrique.h"
#include "../Headers/Partie.h"
#include "../Headers/Plateau.h"

using namespace std;
enum TypeJeux {
	chargerPartie = 0, nouvellePartie = 1
};
int main(int argc, char **argv) {
	Plateau plateau(Plateau::CONFIGURATIONSTANDARD);
	map<char, int> impalaPositions;
	Partie* partie = JeuxFabrique::init();
	partie->start();
	/*Elephant* elephant = new Elephant();
	cout<<*elephant<<endl;*/
	cout << "cases[0][0] = " << plateau.getCases()[0][0]->getIdSecteur()
			<< endl;
	//cout << "cases[0][0] = "<<conf[1][1].getIdSecteur()<<endl;
}
