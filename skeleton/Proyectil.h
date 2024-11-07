#pragma once
#include "Particle.h"
#define GRAV 9.8

class Proyectil
{
public: 
	Proyectil(Vector3 pos, Vector3 ini, double vel, double masa) : mr(masa), vr(vel) {
		vs = vr/10;
		masaSim(); gravedadSim();
		Vector3 direction = pos;
		direction.normalize();
		p = new Particle(ini, direction * vs, Vector3(0, -gs, 0), 5, 5.0f);
	}

	void masaSim() {
		ms = mr * ((vr * vr) / (vs * vs));
	}

	void gravedadSim() {
		gs = vs*vs * (GRAV / (vr*vr));
	}

	void integrate(double t) {
		p->integrate(t);
	}

private:
	double mr, ms, vr, vs, gs;
	Particle* p;
};

