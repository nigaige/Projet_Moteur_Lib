#pragma once
#include "Utils.h"

void Collider::isColliding(Collider* other, D3DXVECTOR3* distance)
{
	RigidBody* rb = gameobject_->rb();
	if (rb == nullptr)return;
	if (rb->isKinematic()) return;
	D3DXVECTOR3 speed = *rb->speed();
	D3DXVECTOR3 dist = *distance;

	transform_->position(transform_->position() + dist);

	D3DXVECTOR3 offset =  speed + dist;
	rb->speed(&offset);
	int a = 0;
}
