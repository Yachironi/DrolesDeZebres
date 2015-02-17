/***********************************************************************
 * Module:  Case.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 00:08:39
 * Purpose: Declaration of the class Case
 ***********************************************************************/

#if !defined(__ImpalaJones_Case_h)
#define __ImpalaJones_Case_h
using namespace std;
#include <iostream>
#include "Pion.h"
class Pion;

class Case {
public:
	Pion* pion; /* pion positionne sur la case */

	Case(int idSecteur){
		this->idSecteur=idSecteur;
		this->pion=NULL;
	}
	~Case(){

	}

	int getIdSecteur() const {
		return idSecteur;
	}
	friend ostream& operator<<(ostream& os, const Case& cas) {
		if(cas.pion==NULL){
			 os << "NULL" ;
		}else if(cas.pion->isCache()){
			 os << "#" ;
		}else{
			os << cas.pion->getIntitulePion();
		}
		return os;
	}

protected:
private:
	int idSecteur; /* l'identifiant du secteur */

};

#endif
