/*
 * DrolesDeZebres.cpp
 *
 *  Created on: 31 janv. 2015
 *      Author: Yasser RABI & Zheng ZHANG
 */

#include <iostream>
#include <vector>
#include "../Headers/Plateau.h"
#include "../Headers/Case.h"

using namespace std;

int main(int argc, char **argv) {
	Plateau plateau(Plateau::CONFIGURATIONSTANDARD);
	map<char, int> impalaPositions;

	cout << "cases[0][0] = "<<plateau.getCases()[0][0]->getIdSecteur() << endl;
	//cout << "cases[0][0] = "<<conf[1][1].getIdSecteur()<<endl;
}
