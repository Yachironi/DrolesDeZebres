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
	static int configuration;

	static vector<vector<Case*>> getConfigurationDuPresident();

	static vector<vector<Case*>> getConfigurationStandard();

	Plateau(vector<vector<Case*>> configuration);

	const vector<vector<Case*> >& getCases() const;

	void setCases(int i, int j, Pion* pion);
	int saisirImpalaJonesPosition();
	int* saisirPositionPion();
	bool isImpalaPositionDisponnible(int positionImpalaJones,
			int* positionImpalaPossible);
	string getImpalaJonesPossibleString();
	void updateSelonReglesDeJeux(int i, int j);
	void updateEFFRAYANT(int i, int j);
	void updateEFFRAYE(int i, int j);
	void updateSAUTEUR(int i, int j);
	friend ostream& operator<<(ostream& os, const Plateau& plateau);
	static void afficherImpalaJones(int position, string cases[17][40]);
	string getImpalaPositions(int position) const;
	ImpalaJones* getImpalaJones();
	bool estPossible(int i, int j);

protected:
private:
	vector<vector<Case*>> cases;
	ImpalaJones* impalaJones;
	string impalaPositions[22] = { "C0", "C1", "C2", "C3", "C4", "C5", "L0",
			"L1", "L2", "L3", "L4", "C5", "C4", "C3", "C2", "C1", "C0", "L4",
			"L3", "L2", "L1", "L0" };
};

#endif
