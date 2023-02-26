
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include "il2cpp-appdata.h"
#include "helpers.h"
#include "il2cpp-init.h"
#include <string>
using namespace app;

template <class T>
class pComponent
{
private:
	std::string getClassName();
public:
	T* m_pComponent;
	std::string m_pClassName;
	pComponent();
	void init_component(GameObject* object);
};

class pGameObject
{
public:

	GameObject* m_pGameObject;
	Transform* m_pTransform;
	std::string m_pName;

	pGameObject(std::string name);

	void init_object();

};

class pPlayer : public pGameObject, public pComponent<FPSControllerNEW> {
public:
	using pGameObject::pGameObject;
	using pComponent::pComponent;
	pPlayer();
	void create();
};