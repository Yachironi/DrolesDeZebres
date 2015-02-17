
/***********************************************************************
 * Module:  ImpalaJones.h
 * Author:  Yasser RABI & Zheng ZHANG
 * Modified: samedi 31 janvier 2015 00:21:31
 * Purpose: Declaration of the class ImpalaJones
 ***********************************************************************/

#if !defined(__ImpalaJones_ImpalaJones_h)
#define __ImpalaJones_ImpalaJones_h
using namespace std;

class ImpalaJones {
public:
	ImpalaJones(){
		this->position=-1;
	}
	~ImpalaJones(){}
	int* getPosition()  {
		//TODO (2,-1,-1)
		int* positionsPossible= new int[3];

		return positionsPossible;
	}

	void setPosition(int position) {
		this->position = position;
	}

protected:
private:
	int position;

};

#endif
