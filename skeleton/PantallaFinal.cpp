#include "PantallaFinal.h"

PantallaFinal::PantallaFinal(Vector3 posBasket, PxPhysics* phys, PxScene* scene, int niv) : Nivel::Nivel(posBasket, phys, scene, niv) {
	PxVec3 fuerza = PxVec3(0, -10, 0);
	gfs = new GeneradorFuerzasSolidos(nullptr, fuerza, { 0,0,0 }, { 1000,1000,1000 });

	PxMaterial* material = phys->createMaterial(0.5f, 0.5f, 0.5f);

	PxRigidStatic* staticActor = phys->createRigidStatic(PxTransform(PxVec3(-200, 400, -400)));
	PxShape* shape = staticActor->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor);

	RenderItem* item = new RenderItem(shape, staticActor, { 0,1,0,1 });

	PxRigidStatic* staticActor2 = phys->createRigidStatic(PxTransform(PxVec3(-160, 440, -400)));
	PxShape* shape2 = staticActor2->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor2);

	RenderItem* item2 = new RenderItem(shape2, staticActor2, { 0,1,0,1 });

	PxRigidStatic* staticActor3 = phys->createRigidStatic(PxTransform(PxVec3(-120, 480, -400)));
	PxShape* shape3 = staticActor3->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor3);

	RenderItem* item3 = new RenderItem(shape3, staticActor3, { 0,1,0,1 });

}
