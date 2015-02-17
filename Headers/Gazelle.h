/***********************************************************************
 * Module:  Gazelle.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: vendredi 30 janvier 2015 12:03:54
 * Purpose: Declaration of the class Gazelle
 ***********************************************************************/

#if !defined(__ImpalaJones_Gazelle_h)
#define __ImpalaJones_Gazelle_h

using namespace std;

#include "Animal.h"

class Gazelle : public Animal
{
public:
	Gazelle() :
			Animal(false, 2, -1, EFFRAYE) {
	}
	~Gazelle() {

	}
	friend ostream& operator<<(ostream& os, const Gazelle& gazelle) {
		gazelle.isCache() ? os << "#" : os << "G";
		return os;
	}
protected:
private:

};

#endif
