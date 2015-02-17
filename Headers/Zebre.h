
/***********************************************************************
 * Module:  Zebre.h
 * Author:  yachironi
 * Modified: vendredi 30 janvier 2015 12:03:34
 * Purpose: Yasser RABI & Zheng ZHANG
 ***********************************************************************/

#if !defined(__ImpalaJones_Zebre_h)
#define __ImpalaJones_Zebre_h

#include "Animal.h"

class Zebre: public Animal {
public:
	Zebre() :
			Animal(false, 6, -1, EFFRAYE,"Zebre") {
	}
	~Zebre() {

	}
	friend ostream& operator<<(ostream& os, const Zebre& zebre) {
		zebre.isCache() ? os << "#" : os << "Z";
		return os;
	}
protected:
private:

};

#endif
