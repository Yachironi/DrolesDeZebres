/***********************************************************************
 * Module:  Lion.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: vendredi 30 janvier 2015 12:04:25
 * Purpose: Declaration of the class Lion
 ***********************************************************************/

#if !defined(__ImpalaJones_Lion_h)
#define __ImpalaJones_Lion_h

using namespace std;

#include "Animal.h"

class Lion: public Animal {
public:
	Lion() :
			Animal(false, 1, -1, EFFRAYANT) {
	}
	~Lion() {

	}
	friend ostream& operator<<(ostream& os, const Lion& lion) {
		lion.isCache() ? os << "#" : os << "L";
		return os;
	}
protected:
private:

};

#endif
