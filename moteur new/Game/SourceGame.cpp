

#ifdef _DEBUG
#include <crtdbg.h>
#endif

#include "Utils.h"


const int FIXED_UPDATE_INTERVAL = 16; // 16ms, equivalent to 60fps

#pragma region test area

void triggerHapened(Collider* other) { Utils::DebugLogMessage("Weeeeee"); }

#pragma endregion

void calltest() { Utils::DebugLogMessage("Reussi"); };

#pragma endregion

int main(Moteur* moteur)
{	

#pragma region Init




	GameObject* Ui = new GameObject();
	buttonLaunchGame* buttonStart = new buttonLaunchGame(moteur);
	Ui->addComponent(buttonStart);
	moteur->addGameObject(Ui);
	moteur->addUiComponent(buttonStart);
	
#pragma endregion


#pragma region GameInit

	

#pragma endregion

	


	moteur->gameLoop();




#pragma region end game



	std::this_thread::sleep_for(std::chrono::milliseconds(1));

	return 0;
#pragma endregion


}



float Moteur::s_deltaTime_;
ID3DXFont* Moteur::font;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
#ifdef _DEBUG
	_CrtMemState memStateInit;
	_CrtMemCheckpoint(&memStateInit);
#endif
	
	
	Moteur::inputManager_ = new Input();
	Moteur::s_deltaTime_ = 0.01f;
	Moteur::font = nullptr;

	Moteur* moteur;


	Utils util;
	

	moteur = new Moteur(hInstance,
		hPrevInstance,
		lpCmdLine,
		nCmdShow);
	moteur->Init();

	main(moteur);
		
	delete moteur;

#ifdef _DEBUG
	_CrtMemState memStateEnd, memStateDiff;
	_CrtMemCheckpoint(&memStateEnd);
	if (_CrtMemDifference(&memStateDiff, &memStateInit, &memStateEnd))
	{
		MessageBoxA(NULL, "MEMORY LEAKS", "DISCLAIMER", 0);
	}
#endif 

	return 0;
}


