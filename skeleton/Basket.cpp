#include "Basket.h"
#include <iostream>

void Basket::addBasketToScene(PxPhysics* physics, PxScene* scene)
{
    PxMaterial* material = physics->createMaterial(0.5f, 0.5f, 0.5f);
    actors.push_back(physics->createRigidStatic(PxTransform(PxVec3(0, 0, 0)+initPos)));
    PxShape* shape = actors[0]->createShape(PxBoxGeometry(0.5f, 1, 10), *material);
    scene->addActor(*actors[0]);

    renderItems.push_back(new RenderItem(shape, actors[0], { 1,0,0,1 }));

    actors.push_back(physics->createRigidStatic(PxTransform(PxVec3(-10, 0,10)+initPos)));
    PxShape* shape2 = actors[1]->createShape(PxBoxGeometry(10, 1, 0.5f), *material);
    scene->addActor(*actors[1]);

    renderItems.push_back(new RenderItem(shape2, actors[1], { 1,0,0,1 }));

    actors.push_back(physics->createRigidStatic(PxTransform(PxVec3(-10, 0, -10)+initPos)));
    PxShape* shape3 = actors[2]->createShape(PxBoxGeometry(10, 1, 0.5f), *material);
    scene->addActor(*actors[2]);

    renderItems.push_back(new RenderItem(shape3, actors[2], { 1,0,0,1 }));

    actors.push_back(physics->createRigidStatic(PxTransform(PxVec3(-20, 0, 0)+initPos)));
    PxShape* shape4 = actors[3]->createShape(PxBoxGeometry(0.5f, 1, 10), *material);
    scene->addActor(*actors[3]);

    renderItems.push_back(new RenderItem(shape4, actors[3], { 1,0,0,1 }));

    PxMaterial* materialBoard = physics->createMaterial(0.5f, 0.5f, 0.5f);
    actors.push_back(physics->createRigidStatic(PxTransform(PxVec3(-10, 10, -20) + initPos)));
    PxShape* boardShape = actors[4]->createShape(PxBoxGeometry(20, 20, 0.5f), *materialBoard);
    scene->addActor(*actors[4]);

    renderItems.push_back(new RenderItem(boardShape, actors[4], { 1, 1, 1, 1 }));
}
