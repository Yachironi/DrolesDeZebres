/***********************************************************************
 * Module:  Partie.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 00:20:03
 * Purpose: Declaration of the class Partie
 ***********************************************************************/

#if !defined(__ImpalaJones_Partie_h)
#define __ImpalaJones_Partie_h
#include "Plateau.h"
#include "ImpalaJones.h"
#include "Joueur.h"

using namespace std;


class Plateau;
class ImpalaJones;
class Joueur;

class Partie {
public:
	Plateau** plateau;
	ImpalaJones** impalaJones;
	Joueur** joueur;

protected:
private:

};

#endif
