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
protected:
private:
	int position;
	string positions[22] = { "C1", "C2", "C3", "C4", "C5", "C6", "L1","L2","L3","L4","L5","C6","C5","C4","C3","C2","C1","L5","L4","L3","L2","L1" };
};

#endif
