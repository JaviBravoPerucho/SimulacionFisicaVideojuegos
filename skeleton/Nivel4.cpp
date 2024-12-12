#include "Nivel4.h"

void Nivel4::addMuelle(MuelleType tipo)
{
	PxGeometry* sphere = new PxSphereGeometry(BALL_DIM);

	switch (tipo) {
	case DOBLE1:
		muelle1 = new SolidoRigido(PxTransform(POS_MUE1), sphere, Vector3(0), Vector3(0), 100000.0f, Vector4(1, 0, 0, 1), gPhysics, gScene, PxVec3(0));
		muelle2 = new SolidoRigido(PxTransform(POS_MUE2), sphere, Vector3(0), Vector3(0), 100000.0f, Vector4(1, 0, 0, 1), gPhysics, gScene, PxVec3(0));
		break;
	case DOBLE2:
		muelle3 = new SolidoRigido(PxTransform(POS_MUE3), sphere, Vector3(0), Vector3(0), 100000.0f, Vector4(0, 1, 0, 1), gPhysics, gScene, PxVec3(0));
		muelle4 = new SolidoRigido(PxTransform(POS_MUE4), sphere, Vector3(0), Vector3(0), 100000.0f, Vector4(0, 1, 0, 1), gPhysics, gScene, PxVec3(0));

		break;
	case ANCHORED:
		muelle5 = new SolidoRigido(PxTransform(POS_MUE5), sphere, Vector3( 0), Vector3(0), 100000.0f, Vector4(0, 0, 1, 1), gPhysics, gScene, PxVec3(0));

		break;
	}
}
