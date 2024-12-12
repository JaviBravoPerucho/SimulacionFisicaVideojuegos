#include "Nivel3.h"

void Nivel3::addObstacle(ObstacleType tipo)
{
	PxGeometry* box = new PxBoxGeometry(BOX_DIM.x, BOX_DIM.y, BOX_DIM.z);

	switch (tipo) {
	case DERIZQ:
		obs1 = new SolidoRigido(PxTransform(POS_OBS1), box, Vector3(-30, 0, 0), Vector3(0), 100000.0f, Vector4(1, 0, 0, 1), gPhysics, gScene, PxVec3(0));
		break;
	case DERIZQ2:
		obs2 = new SolidoRigido(PxTransform(POS_OBS2), box, Vector3(30, 0, 0), Vector3(0), 100000.0f, Vector4(0, 1, 0, 1), gPhysics, gScene, PxVec3(0));

		break;
	case ARRABA:
		obs3 = new SolidoRigido(PxTransform(POS_OBS3), box, Vector3(0, 30, 0), Vector3(0), 100000.0f, Vector4(0, 0, 1, 1), gPhysics, gScene, PxVec3(0));

		break;
	case DIAGONAL:
		obs4 = new SolidoRigido(PxTransform(POS_OBS4), box, Vector3(-30, -30, 0), Vector3(0), 100000.0f, Vector4(1, 1, 0, 1), gPhysics, gScene, PxVec3(0));

		break;
	}
}

void Nivel3::updateObstacles()
{
	if (obs1 != nullptr) {
		if (obs1->getRigidDynamic()->getGlobalPose().p.x < -30)obs1->setVelocity(Vector3(30, 0, 0));
		else if (obs1->getRigidDynamic()->getGlobalPose().p.x > 30)obs1->setVelocity(Vector3(-30, 0, 0));
	}

	if (obs2 != nullptr) {
		if (obs2->getRigidDynamic()->getGlobalPose().p.x < -30)obs2->setVelocity(Vector3(30, 0, 0));
		else if (obs2->getRigidDynamic()->getGlobalPose().p.x > 30)obs2->setVelocity(Vector3(-30, 0, 0));
	}

	if (obs3 != nullptr) {
		if (obs3->getRigidDynamic()->getGlobalPose().p.y > 50)obs3->setVelocity(Vector3(0,-30, 0));
		else if (obs3->getRigidDynamic()->getGlobalPose().p.y < -30)obs3->setVelocity(Vector3(0, 30, 0));
	}

	if (obs4 != nullptr) {
		if (obs4->getRigidDynamic()->getGlobalPose().p.x < -60 && obs4->getRigidDynamic()->getGlobalPose().p.y < -10)obs4->setVelocity(Vector3(30, 30, 0));
		else if (obs4->getRigidDynamic()->getGlobalPose().p.x > 0 && obs4->getRigidDynamic()->getGlobalPose().p.y > 50)obs4->setVelocity(Vector3(-30, -30, 0));
	}
}
