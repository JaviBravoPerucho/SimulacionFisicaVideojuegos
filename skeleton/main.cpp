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

#include <iostream>

std::string display_text = "This is a test";


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

std::vector <SolidoRigido*>	pelotas;
SistemaParticulas*		sp				= NULL;
SistemaFuerzas*			sf				= NULL;
ExplosionForceGenerator* efg			 = NULL;
GeneradorSolidosRigidos* gsr            = NULL;
GeneradorFuerzasSolidos* gfs            = NULL;

void shoot(const PxTransform &camera) {
	PxGeometry* sphere = new PxSphereGeometry(5);
	Vector3 direction = GetCamera()->getDir();
	direction.normalize();
	pelotas.push_back(new SolidoRigido(PxTransform(camera.p), sphere, Vector3(direction*100), Vector3(0), 0.15,{1, 0.5,0, 1}, gPhysics, gScene, {25,25,25}));
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
	sceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);

	PxRigidStatic* suelo = gPhysics->createRigidStatic(PxTransform({ 0,0,0 }));
	PxShape* shape = CreateShape(PxBoxGeometry(1000, 0.1, 1000));
	suelo->attachShape(*shape);
	gScene->addActor(*suelo);

	RenderItem* item;
	item = new RenderItem(shape, suelo, { 0.8,0.8,0.8,1 });

	/*PxGeometry* sphere = new PxSphereGeometry(5);

	gsr = new GeneradorSolidosRigidos(PxVec3(0, 50, 0), 50, sphere, { 0,0,0 }, { 0,0,0 }, 0.15, { 0.8,0.8,0.8,1 }, gPhysics, gScene);

	
	PxReal inertia = 25;
	PxVec3 inertiaTensor(inertia, inertia, inertia);

	PxGeometry* box = new PxBoxGeometry(5, 5, 5);

	SolidoRigido* sr = 
		new SolidoRigido(PxTransform({ -10,5,-10 }),box, { 0,5,0 }, { 0,0,0 }, 0.15, { 0.8,0.8,0.8,1 }, gPhysics,gScene, inertiaTensor);

	SolidoRigido* sr2 =
		new SolidoRigido(PxTransform({ 10,5,10 }), box, { 0,5,0 }, { 0,0,0 }, 1, { 0.8,0.8,0.8,1 }, gPhysics, gScene, inertiaTensor);

	SolidoRigido* sr3 =
		new SolidoRigido(PxTransform({ 25,5,0 }), box, { 0,5,0 }, { 0,0,0 }, 0.05, { 0.8,0.8,0.8,1 }, gPhysics, gScene, inertiaTensor);

	PxVec3 fuerza = PxVec3(0, -900.8, 0);
	gfs = new GeneradorFuerzasSolidos(gsr, fuerza, { 0,0,0 }, { 1000,1000,1000 });*/
	//sp = new SistemaParticulas();
	//sf = new SistemaFuerzas(sp);

	//sf->addGenerator(new GravitationalForce(Vector3(0, 0, 0), Vector3(10, 10, 10)));
	//sf->addGenerator(new VientoForceGenerator(Vector3(0, 0, 0), Vector3(10, 10, 10), Vector3(100,100,100)));
	//sf->addGenerator(new TorbellinoForceGenerator(Vector3(0, 0, 0), Vector3(10, 10, 10)));
	//efg = new ExplosionForceGenerator(Vector3(0, 0, 0), Vector3(10, 10, 10), 100000, 500);
	//sf->addGenerator(efg);
	//sf->generateSpringDemo();
	//sf->generateBuoyancyDemo();
}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	gScene->simulate(t);
	gScene->fetchResults(true);

	//for(auto p : bullets)
	//	p->integrate(t);

	//sp->update(t);
	//sf->update(t);

	//gsr->integrate(t);
	//gfs->applyForces();
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
	//case 'B': break;
	//case ' ':	break;
	case 'B':
	{
		shoot(camera);
		break;
	}
	case 'E':
		efg->setExplode();
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