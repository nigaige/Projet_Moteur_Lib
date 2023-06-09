#pragma once

#include <windows.h>
#include <windowsx.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>  
#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include <chrono>
#include <map>
#include <string>
#include <sstream>  

#include <d3d9.h>
#include <d3dx9.h>
#include <DXFile.h>

#define CUSTOMFVF (D3DFVF_XYZ  | D3DFVF_DIFFUSE)
struct CUSTOMVERTEX { FLOAT X, Y, Z; DWORD COLOR; };

struct triangle {
	D3DXVECTOR3 A, B, C;
};

// define the screen resolution
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define DEGTORAD (M_PI / 180)
#define RADTODEG (180 / M_PI)

#define GRAVITY 1

#define EPSILON (FLT_EPSILON * 2)
#define MESHFILE 
#define TEXTFILE "./Texture/"

enum States
{
	NOTPRESS,
	HOLD,
	PRESSED,
	RELEASED
};

enum ComponentType {
	COMPONENT,
	RIGIDBODY

};






class GameObject;
class Component;
class Mesh;
class Transform;
class Input;
class Camera;
class Moteur;
class Shader;
class Material;
class Text;
class InitText;
class BaseStates;
class ObjectState;
class StateMachine;
class RigidBody;
class Collider;
class ColliderSphere;
class ColliderCube;
class ColliderManager;
class Ui;

class Parser;








#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "Input.h"
 #include "Moteur.h"
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"
#include "Text.h"
#include "InitText.h"
#include "BaseStates.h"
#include "ObjectState.h"
#include "StateMachine.h"
#include "RigidBody.h"
#include "Collider.h"
#include "ColliderSphere.h"
#include "ColliderCube.h"
#include "ColliderManager.h"
#include "Ui.h"

#include "Parser.h"

// include the Direct3D Library files
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")



class Utils
{
public:
	static void DebugLogMessage(const char* message);
	static void DebugLogMessage(std::string* message);
	static void DebugLogMessage(int* message);
	static void DebugLogMessage(int message);


	static float DegToRad(float Angle);
	static float RadToDeg(float Rad);


	static D3DXVECTOR3* clamp(D3DXVECTOR3* vect, float max);

    template <class T>
    static void DeleteVector(std::vector<T*> );

	template <typename T>
	static bool isOfType(void* val);
	template <typename T>
	static T* castToType(void* val);


	static float distance(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2);


	static float raycast(D3DXVECTOR3* pPoint, D3DXVECTOR3* pDir, triangle* pTri, D3DXVECTOR3* pIntersect, D3DXVECTOR3* pBary, FLOAT* pT, bool isPlane);

	static triangle* offsetTirangle(triangle tri, D3DXVECTOR3 offset);

	static D3DXVECTOR3* triangleNormal(triangle* T);

	static std::vector<std::string> split(std::string s, std::string delimiter);

	template <typename T>
	static int GetKeyViaValue(std::map<int, T*>, T* value);

};

template<typename T>
inline void Utils::DeleteVector(std::vector<T*> vect)
{
    for (int i = 0; i < vect.size(); i++) {
        vect[i]->~T();
    }
	vect.clear();
}

template<typename T>
inline bool Utils::isOfType(void* val)
{
	return dynamic_cast<T*>(val) != nullptr;	
}

template<typename T>
inline T* Utils::castToType(void* val)
{
	return static_cast<T*>(val);
}
template <typename T>
inline int Utils::GetKeyViaValue(std::map<int, T*> mappy, T* value)
{
	int key;
	for (auto& i : mappy) {
		if (i.second == value) {
			key = i.first;
			break; // to stop searching
		}
	}
	return key;

}

// Functor for deleting pointers in vector.
template<class T> class DeleteVector
{
public:
	// Overloaded () operator.
	// This will be called by for_each() function.
	bool operator()(T x) const
	{
		// Delete pointer.
		delete x;
		return true;
	}
};