#include "../Utils.h"

LevelDesigner::LevelDesigner()
{
}

LevelDesigner::~LevelDesigner()
{
}

void LevelDesigner::GenerateLevel()
{
    GameObject* previousPrefab = nullptr;

   /* for (GameObject* prefab : prefabs)
    {
        if (previousPrefab != nullptr) 
        {
            prefab->transform()->posZ(previousPrefab->transform()->position().z + 10);
        }
    }*/
}

void LevelDesigner::CreateSection(std::string sectionPath)
{
    Parser* testParsing = new Parser();
    testParsing->Filename(sectionPath);
    testParsing->ParseAll();

    //GoList = testParsing->GOlist();
    addGoParent(testParsing->GOlist());
    addMeshList(testParsing->MElist());
    addShaderList(testParsing->SHlist());
    addColliderList(testParsing->COlist());
}

void LevelDesigner::addGoParent(std::vector<GameObject*> goImportedList)
{

    for (int i = 0; i < goImportedList.size(); i++)
    {
        if (goImportedList[i] == goImportedList[0]) 
        {
            prefabs.push_back(goImportedList[0]);
        }
        else
        {
            goImportedList[i]->parent(goImportedList[0]);
        }
    }

    GoList = goImportedList;
}

void LevelDesigner::addMeshList(std::vector<Mesh*> meImportedList)
{
    for(Mesh* meInLocList : meImportedList)
    {
        bool flag = true;

        for (Mesh* meInGloList : MeList)
        {
            if(meInLocList == meInGloList) flag = false;
        }

        if(flag) MeList.push_back(meInLocList);
    }
}

void LevelDesigner::addShaderList(std::vector<Shader*> shImportedList)
{
    for(Shader* shInLocList : shImportedList)
    {
        bool flag = true;

        for (Shader* shInGloList : ShList)
        {
            if(shInLocList == shInGloList) flag = false;
        }

        if(flag) ShList.push_back(shInLocList);
    }
}

void LevelDesigner::addColliderList(std::vector<Collider*> coImportedList)
{
    for(Collider* coInLocList : coImportedList)
    {
        bool flag = true;

        for (Collider* coInGloList : CoList)
        {
            if(coInLocList == coInGloList) flag = false;
        }

        if(flag) CoList.push_back(coInLocList);
    }
}
