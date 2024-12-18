#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"
#include "Vector3D.h"
#include "Proyectil.h"
#include "SistemaParticulas.h"
#include "SistemaFuerzas.h"
#include "GravitationalForce.h"
#include "VientoForceGenerator.h"
#include "TorbellinoForceGenerator.h"
#include "ExplosionForceGenerator.h"
#include "SolidoRigido.h"
#include "GeneradorSolidosRigidos.h"
#include "GeneradorFuerzasSolidos.h"
#include "Basket.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"
#include "Nivel4.h"
#include "PantallaFinal.h"

#include <iostream>

std::string display_text = "Proyecto Final - Javier Bravo Perucho";
std::string puntos_text = "Puntos: " + std::to_string(puntos) + "/5";
std::string nivel_text = "Nivel: " + std::to_string(nivel) + "/4";
std::string viento_text = "Viento: " + std::to_string(viento) + " m/s";
int puntos = 0;
int nivel = 1;
int viento = 0;
const int LON = 10;
const int FLECHA_X = -11;
const int FLECHA_Y = -10;
const int FLECHA_Z = 100;
const PxVec3 POS_BASKET = { 0,30,-3 };
using namespace physx;

PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;

PxFoundation*			gFoundation = NULL;
PxPhysics*				gPhysics	= NULL;


PxMaterial*				gMaterial	= NULL;
PxPvd*                  gPvd        = NULL;

PxDefaultCpuDispatcher*	gDispatcher = NULL;
PxScene*				gScene      = NULL;
ContactReportCallback gContactReportCallback;

std::vector <std::pair<SolidoRigido*, bool>>	pelotas;
SistemaParticulas*		sp				= NULL;
SistemaFuerzas*			sf				= NULL;
ExplosionForceGenerator* efg			 = NULL;
GeneradorSolidosRigidos* gsr            = NULL;
Nivel* nivel1						= NULL;
Nivel* nivel2						= NULL;
Nivel* nivel3						= NULL;
Nivel* nivel4						= NULL;
Nivel* nivelActual					= NULL;
Nivel* pantallaFinal = NULL;

PxTransform tFlecha;
bool rotarDerecha = false;

void shoot(const PxTransform &camera) {
	PxGeometry* sphere = new PxSphereGeometry(5);
	Vector3 direction = GetCamera()->getDir();
	direction.y += 0.7;
	direction.x = (tFlecha.p.x + 11)/11;
	direction.normalize();
	SolidoRigido* pelota = new SolidoRigido(PxTransform(camera.p), sphere, Vector3(direction * 110), Vector3(0), 0.17, { 1, 0.5,0, 1 }, gPhysics, gScene, { 25,25,25 });
	pelotas.push_back({ pelota, false });
	nivelActual->addSolid(pelota);
}


// Initialize physics engine
void initPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport,PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(),true,gPvd);

	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);

	sp = new SistemaParticulas();
	sf = new SistemaFuerzas(sp);

	nivel1 = new Nivel1(POS_BASKET, gPhysics, gScene, 1);

	nivelActual = nivel1;

	tFlecha = PxTransform({ FLECHA_X,  FLECHA_Y, FLECHA_Z });
	RenderItem* flecha = new RenderItem(CreateShape(PxBoxGeometry(1, 10, 1)), &tFlecha, Vector4(1, 1, 1, 1));
}

void rotarFlecha(float radianes) {
	if (tFlecha.q.getAngle() > PxPi / 4 && tFlecha.q.getImaginaryPart().z > 0 && !rotarDerecha) {
		rotarDerecha = true;
		return;
	}
	else if (tFlecha.q.getAngle() > PxPi / 4 && tFlecha.q.getImaginaryPart().z < 0 && rotarDerecha) {
		rotarDerecha = false;
		return;
	}
	PxTransform oldTransform = tFlecha;

	PxQuat rotation(radianes, PxVec3(0, 0, 1));

	PxVec3 offset = PxVec3(0, 5, 0);
	PxVec3 rotatedOffset = rotation.rotate(offset);
	PxVec3 newCenter = tFlecha.p - offset + rotatedOffset;

	PxTransform newTransform(newCenter, rotation * tFlecha.q);

	tFlecha = newTransform;
	tFlecha.p.y = oldTransform.p.y;
}

void gestionaNivel(int niv) {
	nivel++;
	switch (niv) {
	case 1:
		nivel2 = new Nivel2(POS_BASKET, gPhysics, gScene, 2, sp, sf);
		viento = nivel2->getVientoValue();
		nivelActual = nivel2;
		delete nivel1;
		break;
	case 2:
		nivel3 = new Nivel3(POS_BASKET, gPhysics, gScene, 3);
		nivelActual = nivel3;
		viento = 0;
		delete nivel2;
		break;
	case 3:
		nivel4 = new Nivel4(POS_BASKET, gPhysics, gScene, 4);
		nivelActual = nivel4;
		delete nivel3;
		break;
	case 4:
		pantallaFinal = new PantallaFinal(POS_BASKET+Vector3(1000,0,0), gPhysics, gScene, 5);
		tFlecha.p.x += 1000;
		nivelActual = pantallaFinal;
		delete nivel4;
	}


	puntos = 0;
	for (auto& p : pelotas) {
		p.first->~SolidoRigido();
	}
	pelotas.clear();
}



void sumaPuntos() {
	puntos++;

	Vector3 pos = { nivelActual->getBasketPos().x - LON-2,  nivelActual->getBasketPos().y - LON, nivelActual->getBasketPos().z + LON / 2 };
	sp->aņadirEmisor(new EmisorDistribucionUniforme(pos, 2, 20, 20, 2.0f, 1.0f));

	nivelActual->addObstacle((ObstacleType)(puntos-1));
	nivelActual->setDif((Difficulty)(puntos-1));
	nivelActual->nuevoViento();
	viento = nivelActual->getVientoValue();

	if (puntos == 5)gestionaNivel(nivel);
}

bool isInside(SolidoRigido* p) {
	return p->getRigidDynamic()->getGlobalPose().p.x > nivelActual->getBasketPos().x - LON*2 && p->getRigidDynamic()->getGlobalPose().p.x < nivelActual->getBasketPos().x
		&& p->getRigidDynamic()->getGlobalPose().p.y < nivelActual->getBasketPos().y&&
		p->getRigidDynamic()->getGlobalPose().p.z >nivelActual->getBasketPos().z - LON / 2 && p->getRigidDynamic()->getGlobalPose().p.z < nivelActual->getBasketPos().z + LON / 2;
}

// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	gScene->simulate(t);
	gScene->fetchResults(true);

	sp->update(t);
	sf->update(t);
	nivelActual->applyForces();

	for (auto & p : pelotas) {
		if (p.first != nullptr) {
			if (isInside(p.first) && !p.second) {
				sumaPuntos();
				p.second = true;
			}
		}
	}
	if(!rotarDerecha)	rotarFlecha((PxPi / 90)*t*30);
	else rotarFlecha((- PxPi / 90)*t*30);

	nivelActual->updateObstacles();
	nivelActual->updateMuelles();
	if (nivel < 5) {
		puntos_text = "Puntos: " + std::to_string(puntos) + "/5";
		nivel_text = "Nivel: " + std::to_string(nivel) + "/4";
		viento_text = "Viento: " + std::to_string(viento*3) + " m/s";
	}
	else {
		puntos_text = "";
		viento_text = "";
		nivel_text = "";
	}
}

// Function to clean data
// Add custom code to the begining of the function
void cleanupPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	// Rigid Body ++++++++++++++++++++++++++++++++++++++++++
	gScene->release();
	gDispatcher->release();
	// -----------------------------------------------------
	gPhysics->release();	
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();
	
	gFoundation->release();
	}

// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	PX_UNUSED(camera);

	switch(toupper(key))
	{
	case ' ':
	{
		shoot(camera);
		break;
	}
	case 'E':
		efg->setExplode();
		break;
	case 'A':
		break;
	case 'D':

		break;
	default:
		break;
	}
}

void onCollision(physx::PxActor* actor1, physx::PxActor* actor2)
{
	PX_UNUSED(actor1);
	PX_UNUSED(actor2);
}


int main(int, const char*const*){
#ifndef OFFLINE_EXECUTION 
	extern void renderLoop();
	renderLoop();
#else
	static const PxU32 frameCount = 100;
	initPhysics(false);
	for(PxU32 i=0; i<frameCount; i++)
		stepPhysics(false);
	cleanupPhysics(false);
#endif

	return 0;
}