#pragma once
#include "Emisor.h"

class EmisorDistribucionNormal : public Emisor
{
public:
	EmisorDistribucionNormal(Vector3 pos, double t, double dt, float limite) : Emisor(pos, t, limite), desviacion(dt) {};

	float distribucionNormal(float media, float dt);

	void createParticle() override;

private:
	float desviacion;
};

