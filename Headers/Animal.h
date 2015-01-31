/***********************************************************************
 * Module:  Animal.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 10:31:21
 * Purpose: Declaration of the class Animal
 ***********************************************************************/

#if !defined(__ImpalaJones_Animal_h)
#define __ImpalaJones_Animal_h

#include "Pion.h"

using namespace std;

class Animal: public Pion {
public:
	TypeAnimal getType() const {
		return type;
	}

	void setType(TypeAnimal type) {
		this->type = type;
	}

protected:
private:
	TypeAnimal type; /* {EFFRAYANT,EFFRAYE,SAUTEUR,NEUTRE} */
};

#endif
