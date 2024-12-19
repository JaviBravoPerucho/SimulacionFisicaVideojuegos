#include "PantallaFinal.h"

void PantallaFinal::createSolid(PxScene* s, PxPhysics* p, PxTransform t, PxMaterial* m)
{
	PxRigidStatic* staticActor = p->createRigidStatic(t);
	PxShape* shape = staticActor->createShape(PxBoxGeometry(20, 20, 10), *m);
	s->addActor(*staticActor);

	RenderItem* item = new RenderItem(shape, staticActor, { 0,1,0,1 });
}


PantallaFinal::PantallaFinal(Vector3 posBasket, PxPhysics* phys, PxScene* scene, int niv) : Nivel::Nivel(posBasket, phys, scene, niv) {
	PxVec3 fuerza = PxVec3(0, -10, 0);
	gfs = new GeneradorFuerzasSolidos(nullptr, fuerza, { 0,0,0 }, { 1000,1000,1000 });

	PxMaterial* material = phys->createMaterial(0.5f, 0.5f, 0.5f);

	for(int i = 0; i < posGG.size(); i++)
		createSolid(scene, phys, PxTransform(posGG[i]), material);

}

