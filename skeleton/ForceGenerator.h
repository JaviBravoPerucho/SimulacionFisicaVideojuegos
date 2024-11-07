#pragma once
#include "Particle.h"


const float G = 9.8;

using namespace physx;
using namespace std;

class ForceGenerator
{
public:
	ForceGenerator(Vector3 p, Vector3 v) : initPos(p), volumen(v) {};

	virtual Vector3 setForce(Particle* p) = 0;

protected:
	Vector3 initPos, volumen;
};

