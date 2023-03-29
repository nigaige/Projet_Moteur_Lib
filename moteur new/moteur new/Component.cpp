#include "Utils.h"



Component::Component(bool isActive)
{
	transform_ = new Transform();
	active = isActive;
	
}


Component::~Component()
{
}

void Component::gameObject(GameObject* go)
{
	transform_ = go->transform();
	gameobject_ = go;

}

GameObject* Component::gameObject()
{
	return gameobject_;
}

void Component::transform(Transform* trans)
{
	transform_ = trans;
}

