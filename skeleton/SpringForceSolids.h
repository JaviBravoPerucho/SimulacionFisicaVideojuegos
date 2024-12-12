#pragma once
#include "GeneradorFuerzasSolidos.h"
#include "SolidoRigido.h"
#include "core.hpp"

class SpringForceSolids : public GeneradorFuerzasSolidos
{
public:
	SpringForceSolids(PxVec3 f, PxVec3 init, PxVec3 v, double k, double resting_length, SolidoRigido* other) :
		GeneradorFuerzasSolidos(nullptr, f, init, v), _k(k), _resting_length(resting_length), _other(other) {};

	void setForce(SolidoRigido* solid);

	inline void setK(double k) { _k = k; }

	virtual ~SpringForceSolids() {};
	void update(float t) {};

protected:
	double _k; //Elastic Coeff.
	double _resting_length;
	SolidoRigido* _other;
};

