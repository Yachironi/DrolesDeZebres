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
	ImpalaJones();
	~ImpalaJones();
	/* Je utilise pas cette fonction */
	/**
	 * if getPositionPossible()==(-1,-1,-1) => false else true
	 */
	bool isPositionPossibleExist(Plateau* plateau);
	int* getPositionPossible(Plateau* plateau);
	void setPosition(int position);

	int getPosition() const;
	bool mouvementEstPossible(int i, int j);
protected:
private:
	int position;

};

#endif
