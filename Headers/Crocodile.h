
/***********************************************************************
 * Module:  Crocodile.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: vendredi 30 janvier 2015 12:03:15
 * Purpose: Declaration of the class Crocodile
 ***********************************************************************/

#if !defined(__ImpalaJones_Crocodile_h)
#define __ImpalaJones_Crocodile_h

using namespace std;

#include "Animal.h"

class Crocodile: public Animal {
public:
	Crocodile() :
			Animal(false, 0, -1, SAUTEUR,"Crocodile") {
	}
	~Crocodile() {

	}
	friend ostream& operator<<(ostream& os, const Crocodile& crocodile) {
		crocodile.isCache() ? os << "#" : os << "C";
		return os;
	}

protected:
private:

};

#endif
