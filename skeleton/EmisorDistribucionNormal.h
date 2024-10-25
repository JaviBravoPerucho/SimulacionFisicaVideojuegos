#pragma once
#include "Emisor.h"

class EmisorDistribucionNormal : public Emisor
{
public:
	EmisorDistribucionNormal(Vector3 pos, double t, double dt) : Emisor(pos, t), desviacion(dt) {};

	float distribucionNormal(float media, float dt);

	void createParticle() override;

private:
	float desviacion;
};

