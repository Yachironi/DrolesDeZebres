/***********************************************************************
 * Module:  Ordinateur.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 10:56:34
 * Purpose: Declaration of the class Ordinateur
 ***********************************************************************/

#if !defined(__ImpalaJones_Ordinateur_h)
#define __ImpalaJones_Ordinateur_h

#include "Joueur.h"

using namespace std;


class Ordinateur : public Joueur
{
public:
	Ordinateur() :Joueur("Ordinateur"){
		}
protected:
private:

};

#endif
