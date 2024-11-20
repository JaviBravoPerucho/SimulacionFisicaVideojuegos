#pragma once
#include "ForceGenerator.h"
#include "core.hpp"

class SpringForceGenerator : public ForceGenerator
{
public:
	SpringForceGenerator(Vector3 p, Vector3 v, double k, double resting_length, Particle* other) :
		ForceGenerator(p,v), _k(k), _resting_length(resting_length), _other(other) {};

	virtual Vector3 setForce(Particle* particle);

	inline void setK(double k) { _k = k; }

	virtual ~SpringForceGenerator() {};
	void update(float t) {};

protected:
	double _k; //Elastic Coeff.
	double _resting_length;
	Particle* _other;
};

