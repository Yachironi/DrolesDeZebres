/***********************************************************************
 * Module:  Pion.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 10:52:26
 * Purpose: Declaration of the class Pion
 ***********************************************************************/

#if !defined(__ImpalaJones_Pion_h)
#define __ImpalaJones_Pion_h

typedef struct {
	int x;
	int y;
}Position;
using namespace std;

class Pion
{
public:
	bool isCache() const {
		return cache;
	}

	void setCache(bool cache) {
		this->cache = cache;
	}

	int getXPosition() const {
		return position.x;
	}
	int getYPosition() const {
			return position.y;
		}

	void setPosition(int x,int y) {
		this->position.x=x;
		this->position.y=y;
	}

	int getValeur() const {
		return valeur;
	}

protected:
	 bool cache; /* Pion cache ou pas {True , False}*/
	 int valeur; /* Le nombre de points du pion */
	 Position position; /* Position du pion sur le plateau */

private:



};

#endif
