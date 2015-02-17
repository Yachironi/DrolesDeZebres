
/***********************************************************************
 * Module:  Elephant.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: vendredi 30 janvier 2015 12:04:16
 * Purpose: Declaration of the class Elephant
 ***********************************************************************/

#if !defined(__ImpalaJones_Elephant_h)
#define __ImpalaJones_Elephant_h

#include "Type.h"

using namespace std;

#include "Animal.h"

class Elephant : public Animal
{
public:
	Elephant(int idJoueur):Animal(false,4,idJoueur,NEUTRE,"Elephant"){
	}
	~Elephant(){};
    friend ostream& operator<<(ostream& os, const Elephant& elephant){
    	elephant.isCache()?os << "#":os << "E";
    	 return os;
    }

protected:
private:

};

#endif
