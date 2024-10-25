#include "EmisorDistribucionNormal.h"
#include "EmisorDistribucionUniforme.h"


class SistemaParticulas
{
public:
	SistemaParticulas();

	void update(double t);
private:
	std::vector<Emisor*> sistemaDeParticulas;
};

