/***********************************************************************
 * Module:  Joueur.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 10:55:58
 * Purpose: Declaration of the class Joueur
 ***********************************************************************/

#if !defined(__ImpalaJones_Joueur_h)
#define __ImpalaJones_Joueur_h
#include "Pion.h"
using namespace std;

class Pion;

class Joueur
{
public:
   Pion** pion;

protected:
private:
   int score;


};

#endif
