#include "pch-il2cpp.h"
#include "objects.h"
#define fixstr(text) reinterpret_cast<String*>(il2cpp_string_new(text))

template<class T>
std::string pComponent<T>::getClassName()
{
	return std::string();
}
template<class T>
pComponent<T>::pComponent()
{
	this->m_pClassName = this->getClassName();
	std::cout << "Loaded Component " << this->m_pClassName << std::endl;
}

template<class T>
void pComponent<T>::init_component(GameObject* object)
{
	std::cout << "Looking for component !" << std::endl;
	this->m_pComponent = reinterpret_cast<T*>(GameObject_GetComponentByName(object, fixstr(this->m_pClassName.c_str()), nullptr));
	std::cout << "Got it" << std::endl;
}




pGameObject::pGameObject(std::string name)
{
	this->m_pName = name;
	std::cout << "Searching for object : " << this->m_pName << std::endl;
}

void pGameObject::init_object()
{
	std::cout << "Searching... " << std::endl;
	this->m_pGameObject = GameObject_Find(fixstr(this->m_pName.c_str()), nullptr);
	std::cout << "Got It " << std::endl;
}


pPlayer::pPlayer() : pGameObject("Player"), pComponent()
{
	std::cout << " Player Constructor called " << std::endl;
}

void pPlayer::create()
{
	this->init_object();
	this->init_component(this->m_pGameObject);
}