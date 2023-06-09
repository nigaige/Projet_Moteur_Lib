#pragma once

class Component
{
protected:
	bool active = false;
	
	GameObject* gameobject_ = nullptr;
	Transform* transform_ =nullptr;
	ComponentType type_ = COMPONENT;
public:
	Component(bool isActive = true);
	virtual ~Component();

	Transform* transform() { return transform_; }
	void transform(Transform* trans);

	void gameObject(GameObject* go);
	GameObject* gameObject();

	ComponentType type() { return type_; }

	void setActive(bool a = true) { active = a; };
	virtual void update() {};
	virtual void fixedUpdate() {};
};

