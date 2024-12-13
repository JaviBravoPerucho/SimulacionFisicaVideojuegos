#include "PantallaFinal.h"

PantallaFinal::PantallaFinal(Vector3 posBasket, PxPhysics* phys, PxScene* scene, int niv) : Nivel::Nivel(posBasket, phys, scene, niv) {
	PxVec3 fuerza = PxVec3(0, -10, 0);
	gfs = new GeneradorFuerzasSolidos(nullptr, fuerza, { 0,0,0 }, { 1000,1000,1000 });

	PxMaterial* material = phys->createMaterial(0.5f, 0.5f, 0.5f);

	PxRigidStatic* staticActor = phys->createRigidStatic(PxTransform(PxVec3(-200, 300, -400)));
	PxShape* shape = staticActor->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor);

	RenderItem* item = new RenderItem(shape, staticActor, { 0,1,0,1 });

	PxRigidStatic* staticActor2 = phys->createRigidStatic(PxTransform(PxVec3(-160, 340, -400)));
	PxShape* shape2 = staticActor2->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor2);

	RenderItem* item2 = new RenderItem(shape2, staticActor2, { 0,1,0,1 });

	PxRigidStatic* staticActor3 = phys->createRigidStatic(PxTransform(PxVec3(-120, 380, -400)));
	PxShape* shape3 = staticActor3->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor3);

	RenderItem* item3 = new RenderItem(shape3, staticActor3, { 0,1,0,1 });

	PxRigidStatic* staticActor4 = phys->createRigidStatic(PxTransform(PxVec3(-80, 380, -400)));
	PxShape* shape4 = staticActor4->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor4);

	RenderItem* item4 = new RenderItem(shape4, staticActor4, { 0,1,0,1 });

	PxRigidStatic* staticActor5 = phys->createRigidStatic(PxTransform(PxVec3(-40, 380, -400)));
	PxShape* shape5 = staticActor5->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor5);

	RenderItem* item5 = new RenderItem(shape5, staticActor5, { 0,1,0,1 });

	PxRigidStatic* staticActor6 = phys->createRigidStatic(PxTransform(PxVec3(-200, 260, -400)));
	PxShape* shape6 = staticActor6->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor6);

	RenderItem* item6 = new RenderItem(shape6, staticActor6, { 0,1,0,1 });

	PxRigidStatic* staticActor7 = phys->createRigidStatic(PxTransform(PxVec3(-200, 220, -400)));
	PxShape* shape7 = staticActor7->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor7);

	RenderItem* item7 = new RenderItem(shape7, staticActor7, { 0,1,0,1 });

	PxRigidStatic* staticActor8 = phys->createRigidStatic(PxTransform(PxVec3(-160, 180, -400)));
	PxShape* shape8 = staticActor8->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor8);

	RenderItem* item8 = new RenderItem(shape8, staticActor8, { 0,1,0,1 });

	PxRigidStatic* staticActor9 = phys->createRigidStatic(PxTransform(PxVec3(-120, 140, -400)));
	PxShape* shape9 = staticActor9->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor9);

	RenderItem* item9 = new RenderItem(shape9, staticActor9, { 0,1,0,1 });

	PxRigidStatic* staticActor10 = phys->createRigidStatic(PxTransform(PxVec3(-80, 140, -400)));
	PxShape* shape10 = staticActor10->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor10);

	RenderItem* item10 = new RenderItem(shape10, staticActor10, { 0,1,0,1 });

	PxRigidStatic* staticActor11 = phys->createRigidStatic(PxTransform(PxVec3(-40, 180, -400)));
	PxShape* shape11 = staticActor11->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor11);

	RenderItem* item11 = new RenderItem(shape11, staticActor11, { 0,1,0,1 });

	PxRigidStatic* staticActor12 = phys->createRigidStatic(PxTransform(PxVec3(0, 220, -400)));
	PxShape* shape12 = staticActor12->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor12);

	RenderItem* item12 = new RenderItem(shape12, staticActor12, { 0,1,0,1 });

	PxRigidStatic* staticActor14 = phys->createRigidStatic(PxTransform(PxVec3(-40, 260, -400)));
	PxShape* shape14 = staticActor14->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor14);

	RenderItem* item14 = new RenderItem(shape14, staticActor14, { 0,1,0,1 });

	PxRigidStatic* staticActor15 = phys->createRigidStatic(PxTransform(PxVec3(-80, 260, -400)));
	PxShape* shape15 = staticActor15->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor15);

	RenderItem* item15 = new RenderItem(shape15, staticActor15, { 0,1,0,1 });

	PxRigidStatic* staticActor16 = phys->createRigidStatic(PxTransform(PxVec3(100, 300, -400)));
	PxShape* shape16 = staticActor16->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor16);

	RenderItem* item16 = new RenderItem(shape16, staticActor16, { 0,1,0,1 });

	PxRigidStatic* staticActor17 = phys->createRigidStatic(PxTransform(PxVec3(140, 340, -400)));
	PxShape* shape17 = staticActor17->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor17);

	RenderItem* item17 = new RenderItem(shape17, staticActor17, { 0,1,0,1 });

	PxRigidStatic* staticActor18 = phys->createRigidStatic(PxTransform(PxVec3(180, 380, -400)));
	PxShape* shape18 = staticActor18->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor18);

	RenderItem* item18 = new RenderItem(shape18, staticActor18, { 0,1,0,1 });

	PxRigidStatic* staticActor19 = phys->createRigidStatic(PxTransform(PxVec3(220, 380, -400)));
	PxShape* shape19 = staticActor19->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor19);

	RenderItem* item19 = new RenderItem(shape19, staticActor19, { 0,1,0,1 });

	PxRigidStatic* staticActor20 = phys->createRigidStatic(PxTransform(PxVec3(260, 380, -400)));
	PxShape* shape20 = staticActor20->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor20);

	RenderItem* item20 = new RenderItem(shape20, staticActor20, { 0,1,0,1 });

	PxRigidStatic* staticActor21 = phys->createRigidStatic(PxTransform(PxVec3(100, 260, -400)));
	PxShape* shape21 = staticActor21->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor21);

	RenderItem* item21 = new RenderItem(shape21, staticActor21, { 0,1,0,1 });

	PxRigidStatic* staticActor22 = phys->createRigidStatic(PxTransform(PxVec3(100, 220, -400)));
	PxShape* shape22 = staticActor22->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor22);

	RenderItem* item22 = new RenderItem(shape22, staticActor22, { 0,1,0,1 });

	PxRigidStatic* staticActor23 = phys->createRigidStatic(PxTransform(PxVec3(140, 180, -400)));
	PxShape* shape23 = staticActor23->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor23);

	RenderItem* item23 = new RenderItem(shape23, staticActor23, { 0,1,0,1 });

	PxRigidStatic* staticActor24 = phys->createRigidStatic(PxTransform(PxVec3(180, 140, -400)));
	PxShape* shape24 = staticActor24->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor24);

	RenderItem* item24 = new RenderItem(shape24, staticActor24, { 0,1,0,1 });

	PxRigidStatic* staticActor25 = phys->createRigidStatic(PxTransform(PxVec3(220, 140, -400)));
	PxShape* shape25 = staticActor25->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor25);

	RenderItem* item25 = new RenderItem(shape25, staticActor25, { 0,1,0,1 });

	PxRigidStatic* staticActor26 = phys->createRigidStatic(PxTransform(PxVec3(260, 180, -400)));
	PxShape* shape26 = staticActor26->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor26);

	RenderItem* item26 = new RenderItem(shape26, staticActor26, { 0,1,0,1 });

	PxRigidStatic* staticActor27 = phys->createRigidStatic(PxTransform(PxVec3(300, 220, -400)));
	PxShape* shape27 = staticActor27->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor27);

	RenderItem* item27 = new RenderItem(shape27, staticActor27, { 0,1,0,1 });

	PxRigidStatic* staticActor28 = phys->createRigidStatic(PxTransform(PxVec3(260, 260, -400)));
	PxShape* shape28 = staticActor28->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor28);

	RenderItem* item28 = new RenderItem(shape28, staticActor28, { 0,1,0,1 });

	PxRigidStatic* staticActor29 = phys->createRigidStatic(PxTransform(PxVec3(220, 260, -400)));
	PxShape* shape29 = staticActor29->createShape(PxBoxGeometry(20, 20, 10), *material);
	scene->addActor(*staticActor29);

	RenderItem* item29 = new RenderItem(shape29, staticActor29, { 0,1,0,1 });
}
