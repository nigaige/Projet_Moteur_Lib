#pragma once


class GameObject
{
private:
	GameObject* parent_ = nullptr;
	Transform* transform_;
	std::vector<Component*> componentList;
	bool toDisplay_ = false;
	std::vector<Mesh*> MeshList;
	std::vector<Collider*> ColliderList;
	RigidBody* rb_ = nullptr;

public:
	GameObject();
	GameObject(Transform* T);
	GameObject(Transform* T, GameObject* parent);
	GameObject(GameObject* parent);
	~GameObject();

	void update();
	void fixedUpdate();

	//TODO DESTRUCTOR DELETE THE COMPONENT

	//	GET/SET
	Transform* transform() { return transform_; }
	void transform(Transform* trans) { transform_ = trans; }
	D3DXMATRIX worldMatrix();

	RigidBody* rb() { return rb_; }

	bool toDisplay()					{ return toDisplay_; }
	void toDisplay(bool display)		{ toDisplay_ = display; }

	void parent(GameObject* go) { parent_ = go; }
	GameObject* parent() { return parent_; }

	void addComponent(Component* comp);
	bool rmComponent(Component* comp);
	bool rmComponent(int index);

	Component* getComponent(int index);

	int countComponent();



	std::vector<Mesh*> meshToDraw();

	std::vector<Component*> findAllComponents(ComponentType type);


	template <typename T>
	T* findComponent();
	
	Component* findComponent(ComponentType type);

	template <typename T>
	bool isOfType(Component* comp);
	template <typename T>
	T* castToType(Component* comp);

	template<typename T>
	std::vector<T> findAllComponents();


};

/*
Call with:
gameobject.findcomponent<type>()
*/
template<typename T>
inline T* GameObject::findComponent()
{
	for (Component* comp : componentList)
	{
		//TODO IMPROVE CASTING, null ptr
		if (static_cast<T*>(comp) != nullptr) {
			return static_cast<T*>(comp);
		}
	}

	return nullptr;
}

template<typename T>
inline bool GameObject::isOfType(Component* comp) {

	T* a = static_cast<T*>(comp);
	return dynamic_cast<T*>(comp) != nullptr;	//TODO DYNAMIC...?
}

template<typename T>
inline T* GameObject::castToType(Component* comp)
{
	return dynamic_cast<T*>(comp);
}

template<typename T>
inline std::vector<T> GameObject::findAllComponents()
{
	std::vector<T> allComponentT;

	for (Component* component : componentList) 
	{
		if (static_cast<T>(*component) != nullptr)
		{
			allComponentT.push_back((T)(*component));
		}
	}

	return allComponentT;
}
