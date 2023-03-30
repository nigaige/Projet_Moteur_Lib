#pragma once


class Moteur
{
private:

    LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
    LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class

	HWND hWnd;
	WNDCLASSEX wc;

	int nCmdShow;

	//Mesh* triangle;
	std::vector<GameObject*> GOList;
	std::vector<Mesh*> MeList;

	ColliderManager* colliderManager_;

	GameObject* camera_;
	Camera* cameraComponent;

	InitText* initText;
	static ID3DXFont* font;

public:

    Moteur(HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPWSTR lpCmdLine,
		int nCmdShow);
	~Moteur();

	//Input* inputManager() { return inputManager_; }

	ColliderManager* colliderManager() { return colliderManager_; }



	void Init();
	void loadMeshInScene(Mesh* MeshToLoad);
	void initD3D();
	void cleanD3D(void);

	void setUpCamera();
	GameObject* camera();

	void addGameObject(GameObject* go);
	void rmGamObject(GameObject* go);
	void addMesh(Mesh* me);
	void rmMesh(Mesh* me);

	void setGoList(std::vector<GameObject*> list);
	void setMeList(std::vector<Mesh*> list);

	static ID3DXFont* getFont() { return font;  };

	//---------------GAMELOOOP
	void gameLoop();															
	void render(void);
	void update(void);															
	void fixedUpdate(void);															
	void updateTransform(void);

	Shader* LoadShader(std::string* shaderPath);	
	void renderMaterial(GameObject* go,Mesh* mesh);										//TODO MANAGE GLOBAL TIME


	Mesh* ImportingModel(std::string path);

	static float s_deltaTime_;
	static Input* inputManager_;
};

