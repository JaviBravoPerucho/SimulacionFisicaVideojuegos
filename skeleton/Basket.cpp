#include "Basket.h"
#include <iostream>

void Basket::addBasketToScene(PxPhysics* physics, PxScene* scene)
{
    PxMaterial* material = physics->createMaterial(0.5f, 0.5f, 0.5f);
    PxRigidStatic* staticActor = physics->createRigidStatic(PxTransform(PxVec3(0, 0, 0)+initPos));
    PxShape* shape = staticActor->createShape(PxBoxGeometry(0.5f, 1, 10), *material);
    scene->addActor(*staticActor);

    RenderItem* item = new RenderItem(shape, staticActor, { 1,0,0,1 });

    PxRigidStatic* staticActor2 = physics->createRigidStatic(PxTransform(PxVec3(-10, 0,10)+initPos));
    PxShape* shape2 = staticActor2->createShape(PxBoxGeometry(10, 1, 0.5f), *material);
    scene->addActor(*staticActor2);

    RenderItem* item2 = new RenderItem(shape2, staticActor2, { 1,0,0,1 });

    PxRigidStatic* staticActor3 = physics->createRigidStatic(PxTransform(PxVec3(-10, 0, -10)+initPos));
    PxShape* shape3 = staticActor3->createShape(PxBoxGeometry(10, 1, 0.5f), *material);
    scene->addActor(*staticActor3);

    RenderItem* item3 = new RenderItem(shape3, staticActor3, { 1,0,0,1 });

    PxRigidStatic* staticActor4 = physics->createRigidStatic(PxTransform(PxVec3(-20, 0, 0)+initPos));
    PxShape* shape4 = staticActor4->createShape(PxBoxGeometry(0.5f, 1, 10), *material);
    scene->addActor(*staticActor4);

    RenderItem* item4 = new RenderItem(shape4, staticActor4, { 1,0,0,1 });

    PxMaterial* materialBoard = physics->createMaterial(0.5f, 0.5f, 0.5f);
    PxRigidStatic* boardActor = physics->createRigidStatic(PxTransform(PxVec3(-10, 10, -20) + initPos));
    PxShape* boardShape = boardActor->createShape(PxBoxGeometry(20, 20, 0.5f), *materialBoard);
    scene->addActor(*boardActor);

    RenderItem* itemBoard = new RenderItem(boardShape, boardActor, { 1, 1, 1, 1 });
}
