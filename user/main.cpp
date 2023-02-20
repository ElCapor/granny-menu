// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Custom injected code entry point

#include "pch-il2cpp.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include "il2cpp-appdata.h"
#include "helpers.h"
#include "il2cpp-init.h"
using namespace app;

// Set the name of your log file here
extern const LPCWSTR LOG_FILE = L"il2cpp-log.txt";

/*// Custom injected code entry point
void Run()
{
    // Initialize thread data - DO NOT REMOVE
    il2cpp_thread_attach(il2cpp_domain_get());

    // If you would like to write to a log file, specify the name above and use il2cppi_log_write()
    // il2cppi_log_write("Startup");

    // If you would like to output to a new console window, use il2cppi_new_console() to open one and redirect stdout
    // il2cppi_new_console();

    // Place your custom code here
}*/

#include "pch-il2cpp.h"
#pragma once
#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include "../kiero/kiero.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_win32.h"
#include "../imgui/imgui_impl_dx11.h"
#include <thread>
#include <vector>
#include "../kiero/minhook/include/MinHook.h"
typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
namespace ImGui {
	void BeginGroupPanel(const char* name, const ImVec2& size = ImVec2(0.0f, 0.0f));
	void EndGroupPanel();
}

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool init = false;
#define fixstr(text) reinterpret_cast<String*>(il2cpp_string_new(text))
template <typename T>
std::string getClassName()
{
	std::string rtti_name = typeid(T).name();
	std::string class_name = rtti_name.substr(12); // remove "struct app::"
	return class_name;
}


enum GuiState {
	INTRO,
	HOME
};

void copyf3(float f3[3], float f3_2[3])
{
	f3[0] = f3_2[0];
	f3[1] = f3_2[1];
	f3[2] = f3_2[2];
}

void copyf4(float f3[4], float f3_2[4])
{
	f3[0] = f3_2[0];
	f3[1] = f3_2[1];
	f3[2] = f3_2[2];
	f3[3] = f3_2[3];

}

class Granny
{
public:
	GameObject* pObject;
	Transform* pTransform;
	EnemyAIGranny* pGranny;

	float userPos[3];
	float userScale[3];
	float userRot[3];
	bool isSpinMod;
	Granny()
	{

	}

	void init()
	{
		this->pObject = GameObject_Find(fixstr("GrannyParent"), nullptr);
		this->pTransform = GameObject_get_transform(this->pObject, nullptr);
		this->pGranny = reinterpret_cast<EnemyAIGranny*>(GameObject_GetComponentByName(this->pObject, fixstr("EnemyAIGranny"), nullptr));
	}

	Vector3 Position()
	{
		return Transform_get_position(this->pTransform, nullptr);
	}

	Vector3 Rotation()
	{
		return Transform_get_eulerAngles(this->pTransform, nullptr);
	}

	Vector3 localScale()
	{
		return Transform_get_localScale(this->pTransform, nullptr);
	}

	float* fPosition()
	{
		float pos[3];
		pos[0] = Position().x;
		pos[1] = Position().y;
		pos[2] = Position().z;
		return pos;
	}

	float* fScale()
	{
		float pos[3];
		pos[0] = localScale().x;
		pos[1] = localScale().y;
		pos[2] = localScale().z;
		return pos;
	}


	float* fRotation()
	{
		float rot[3];
		rot[0] = Rotation().x;
		rot[1] = Rotation().y;
		rot[2] = Rotation().z;
		

		return rot;

	}

	void setPosition(float position[3])
	{
		Vector3 realpos;
		realpos.x = position[0];
		realpos.y = position[1];
		realpos.z = position[2];
		Transform_set_position(this->pTransform, realpos, nullptr);
	}

	void setScale(float position[3])
	{
		Vector3 realpos;
		realpos.x = position[0];
		realpos.y = position[1];
		realpos.z = position[2];
		Transform_set_localScale(this->pTransform, realpos, nullptr);
	}


	void setRotation(float position[3])
	{
		Vector3 realpos;
		realpos.x = position[0];
		realpos.y = position[1];
		realpos.z = position[2];
		Transform_set_eulerAngles(this->pTransform, realpos, nullptr);
	}

};

class Player
{
public:
	GameObject* pObject;
	Transform* pTransform;
	FPSControllerNEW* pPlayer;
	Camera* cam;
	float userPos[3];
	float userScale[3];
	float userRot[3];
	float userFov = 60;
	bool isSpinMod;
	Player()
	{

	}

	void init()
	{
		this->pObject = GameObject_Find(fixstr("Player"), nullptr);
		this->pTransform = GameObject_get_transform(this->pObject, nullptr);
		this->pPlayer = reinterpret_cast<FPSControllerNEW*>(GameObject_GetComponentByName(this->pObject, fixstr("FPSControllerNEW"), nullptr));
		//this->cam = reinterpret_cast<Camera*>(GameObject_GetComponentByName(this->pPlayer->fields.mainCam, fixstr("Camera"), nullptr));
		

	}

	Vector3 Position()
	{
		return Transform_get_position(this->pTransform, nullptr);
	}

	Vector3 Rotation()
	{
		return Transform_get_eulerAngles(this->pTransform, nullptr);
	}

	Vector3 localScale()
	{
		return Transform_get_localScale(this->pTransform, nullptr);
	}

	float* fPosition()
	{
		float pos[3];
		pos[0] = Position().x;
		pos[1] = Position().y;
		pos[2] = Position().z;
		return pos;
	}

	float* fScale()
	{
		float pos[3];
		pos[0] = localScale().x;
		pos[1] = localScale().y;
		pos[2] = localScale().z;
		return pos;
	}


	float* fRotation()
	{
		float rot[3];
		rot[0] = Rotation().x;
		rot[1] = Rotation().y;
		rot[2] = Rotation().z;


		return rot;

	}

	void setPosition(float position[3])
	{
		Vector3 realpos;
		realpos.x = position[0];
		realpos.y = position[1];
		realpos.z = position[2];
		Transform_set_position(this->pTransform, realpos, nullptr);
	}

	void setScale(float position[3])
	{
		Vector3 realpos;
		realpos.x = position[0];
		realpos.y = position[1];
		realpos.z = position[2];
		Transform_set_localScale(this->pTransform, realpos, nullptr);
	}


	void setRotation(float position[3])
	{
		Vector3 realpos;
		realpos.x = position[0];
		realpos.y = position[1];
		realpos.z = position[2];
		Transform_set_eulerAngles(this->pTransform, realpos, nullptr);
	}

};

namespace globals {
	Player player;
	Granny granny;
	bool isEsp;
	bool isSceneLoaded;
	GuiState state = GuiState::INTRO;
	bool hasCloned;
	std::vector<GameObject*> cloned_granny;
	
}


void waitForSceneLoad()
{
	while (globals::isSceneLoaded != true)
	{
		Scene current = SceneManager_GetActiveScene(nullptr);
		std::string scene_name = il2cppi_to_string(Scene_GetNameInternal(current.m_Handle, nullptr));

		if (scene_name == "Scene")
		{
			std::cout << "loaded" << std::endl;
			Sleep(10000); //
			globals::isSceneLoaded = true;
			
		}
		Sleep(1000);
	}
}


HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
			init_il2cpp();
			il2cpp_thread_attach(il2cpp_domain_get()); // initialize
			il2cppi_new_console();
			std::cout << ">> Started <<" << std::endl;
			std::cout << getClassName<EnemyAIGranny>() << std::endl;
			std::cout << getClassName<FPSControllerNEW>() << std::endl;
			std::cout << getClassName<Transform>() << std::endl;
			std::cout << getClassName<SceneManager>() << std::endl;
			std::cout << getClassName<HandObjectFalls>() << std::endl;
			std::thread(waitForSceneLoad).detach();
			
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("ImGui Window");
	ImGui::Text("Granny 3 PC Mod menu by mogus#2891");
	if (globals::state == GuiState::INTRO)
	{
		if (globals::isSceneLoaded == false)
		{
			ImGui::Text("Waiting for scene to load");
		}
		else {
			ImGui::Text("Scene Loaded , ready to start !");
			if (ImGui::Button("Start"))
			{
				globals::state = GuiState::HOME;
				globals::granny.init();
				globals::player.init();
				
			}
		}
		
	}
	else if (globals::state == GuiState::HOME)
	{
		if (globals::isSceneLoaded)
		{
			
			copyf3(globals::granny.userPos, globals::granny.fPosition());
			copyf3(globals::granny.userScale, globals::granny.fScale());
			copyf3(globals::granny.userRot, globals::granny.fRotation());
			if (globals::granny.isSpinMod)
			{
				float newrot[3];
				newrot[0] = globals::granny.fRotation()[0] + 0;
				newrot[1] = globals::granny.fRotation()[1] + 100;
				
				newrot[2] = globals::granny.fRotation()[2] + 0;
				
				globals::granny.setRotation(newrot);
				
			}

			if (ImGui::BeginTabBar("Modifications"))
			{
				if (ImGui::BeginTabItem("Player"))
				{
					ImGui::BeginGroupPanel("Movement");
					ImGui::SliderFloat("Walkspeed ", &globals::player.pPlayer->fields.forwardSpeed, 0, 100, "%.1f");
					
					ImGui::EndGroupPanel();
					ImGui::BeginGroupPanel("Behaviour");
					if (ImGui::SliderFloat("Field Of View ", &globals::player.userFov, 0, 200, "%f"))
					{
						//Camera_set_fieldOfView(globals::player.cam, globals::player.userFov, nullptr);
					}

					
					ImGui::EndGroupPanel();
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Granny"))
				{
					ImGui::BeginGroupPanel("Movement");
					ImGui::SliderFloat("Granny Walkspeed", &globals::granny.pGranny->fields.walkSpeed, 0, 100, "%.1f");
					ImGui::SliderFloat("Granny Follow Speed", &globals::granny.pGranny->fields.grannysFollowSpeed, 0, 100, "%.1f");
					ImGui::SliderFloat("Granny WalkAnim Speed", &globals::granny.pGranny->fields.walkAnimSpeed, 0, 100, "%.1f");
					ImGui::SliderFloat("Granny WalkAnim Follow Speed", &globals::granny.pGranny->fields.grannysAnimFollowSpeed, 0, 100, "%.1f");
					ImGui::EndGroupPanel();
					ImGui::BeginGroupPanel("Behaviour");
					if (ImGui::Button("Kill Granny (GUN)"))
					{
						//globals::granny.pGranny->fields.hitByGun = true;
						EnemyAIGranny_grannyHitByGun(globals::granny.pGranny, nullptr);
					}
					if (ImGui::Button("Stun Granny"))
					{
						
						globals::granny.pGranny->fields.getStunned = true;
					}
					ImGui::EndGroupPanel();
					ImGui::BeginGroupPanel("Transforms");
					if (ImGui::SliderFloat3("Position", globals::granny.userPos, -30, 30, "%.1f"))
					{
						globals::granny.setPosition(globals::granny.userPos);
					}
					if (ImGui::SliderFloat3("Scale", globals::granny.userScale, -10, 10, "%.1f"))
					{
						globals::granny.setScale(globals::granny.userScale);
					}
					if (ImGui::SliderFloat3("Rotation", globals::granny.userRot, -360, 360, "%.1f"))
					{
						globals::granny.setRotation(globals::granny.userRot);
					}
					ImGui::EndGroupPanel();

					ImGui::BeginGroupPanel("Visuals");
					ImGui::Checkbox("Tracers", &globals::isEsp);
					ImGui::EndGroupPanel();

					ImGui::BeginGroupPanel("Fun");
					ImGui::Checkbox("Spin", &globals::granny.isSpinMod);
					ImGui::EndGroupPanel();
					ImGui::EndTabItem();
				}
				ImGui::EndTabBar();
			}
		}
		

	}
	ImGui::End();

	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);
	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}

#define IMGUI_DEFINE_MATH_OPERATORS
#include "../imgui/imgui_internal.h"

static ImVector<ImRect> s_GroupPanelLabelStack;

void ImGui::BeginGroupPanel(const char* name, const ImVec2& size)
{
	ImGui::BeginGroup();

	auto cursorPos = ImGui::GetCursorScreenPos();
	auto itemSpacing = ImGui::GetStyle().ItemSpacing;
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f));
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 0.0f));

	auto frameHeight = ImGui::GetFrameHeight();
	ImGui::BeginGroup();

	ImVec2 effectiveSize = size;
	if (size.x < 0.0f)
		effectiveSize.x = ImGui::GetContentRegionAvail().y;
	else
		effectiveSize.x = size.x;
	ImGui::Dummy(ImVec2(effectiveSize.x, 0.0f));

	ImGui::Dummy(ImVec2(frameHeight * 0.5f, 0.0f));
	ImGui::SameLine(0.0f, 0.0f);
	ImGui::BeginGroup();
	ImGui::Dummy(ImVec2(frameHeight * 0.5f, 0.0f));
	ImGui::SameLine(0.0f, 0.0f);
	ImGui::TextUnformatted(name);
	auto labelMin = ImGui::GetItemRectMin();
	auto labelMax = ImGui::GetItemRectMax();
	ImGui::SameLine(0.0f, 0.0f);
	ImGui::Dummy(ImVec2(0.0, frameHeight + itemSpacing.y));
	ImGui::BeginGroup();

	//ImGui::GetWindowDrawList()->AddRect(labelMin, labelMax, IM_COL32(255, 0, 255, 255));

	ImGui::PopStyleVar(2);

#if IMGUI_VERSION_NUM >= 17301
	ImGui::GetCurrentWindow()->ContentRegionRect.Max.x -= frameHeight * 0.5f;
	ImGui::GetCurrentWindow()->WorkRect.Max.x -= frameHeight * 0.5f;
	ImGui::GetCurrentWindow()->InnerRect.Max.x -= frameHeight * 0.5f;
#else
	ImGui::GetCurrentWindow()->ContentsRegionRect.Max.x -= frameHeight * 0.5f;
#endif
	ImGui::GetCurrentWindow()->Size.x -= frameHeight;

	auto itemWidth = ImGui::CalcItemWidth();
	ImGui::PushItemWidth(ImMax(0.0f, itemWidth - frameHeight));

	s_GroupPanelLabelStack.push_back(ImRect(labelMin, labelMax));
}

void ImGui::EndGroupPanel()
{
	ImGui::PopItemWidth();

	auto itemSpacing = ImGui::GetStyle().ItemSpacing;

	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f));
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 0.0f));

	auto frameHeight = ImGui::GetFrameHeight();

	ImGui::EndGroup();

	//ImGui::GetWindowDrawList()->AddRectFilled(ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), IM_COL32(0, 255, 0, 64), 4.0f);

	ImGui::EndGroup();

	ImGui::SameLine(0.0f, 0.0f);
	ImGui::Dummy(ImVec2(frameHeight * 0.5f, 0.0f));
	ImGui::Dummy(ImVec2(0.0, frameHeight - frameHeight * 0.5f - itemSpacing.y));

	ImGui::EndGroup();

	auto itemMin = ImGui::GetItemRectMin();
	auto itemMax = ImGui::GetItemRectMax();
	//ImGui::GetWindowDrawList()->AddRectFilled(itemMin, itemMax, IM_COL32(255, 0, 0, 64), 4.0f);

	auto labelRect = s_GroupPanelLabelStack.back();
	s_GroupPanelLabelStack.pop_back();

	ImVec2 halfFrame = ImVec2(frameHeight * 0.25f, frameHeight) * 0.5f;
	ImRect frameRect = ImRect(itemMin + halfFrame, itemMax - ImVec2(halfFrame.x, 0.0f));
	labelRect.Min.x -= itemSpacing.x;
	labelRect.Max.x += itemSpacing.x;
	for (int i = 0; i < 4; ++i)
	{
		switch (i)
		{
			// left half-plane
		case 0: ImGui::PushClipRect(ImVec2(-FLT_MAX, -FLT_MAX), ImVec2(labelRect.Min.x, FLT_MAX), true); break;
			// right half-plane
		case 1: ImGui::PushClipRect(ImVec2(labelRect.Max.x, -FLT_MAX), ImVec2(FLT_MAX, FLT_MAX), true); break;
			// top
		case 2: ImGui::PushClipRect(ImVec2(labelRect.Min.x, -FLT_MAX), ImVec2(labelRect.Max.x, labelRect.Min.y), true); break;
			// bottom
		case 3: ImGui::PushClipRect(ImVec2(labelRect.Min.x, labelRect.Max.y), ImVec2(labelRect.Max.x, FLT_MAX), true); break;
		}

		ImGui::GetWindowDrawList()->AddRect(
			frameRect.Min, frameRect.Max,
			ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)),
			halfFrame.x);

		ImGui::PopClipRect();
	}

	ImGui::PopStyleVar(2);

#if IMGUI_VERSION_NUM >= 17301
	ImGui::GetCurrentWindow()->ContentRegionRect.Max.x += frameHeight * 0.5f;
	ImGui::GetCurrentWindow()->WorkRect.Max.x += frameHeight * 0.5f;
	ImGui::GetCurrentWindow()->InnerRect.Max.x += frameHeight * 0.5f;
#else
	ImGui::GetCurrentWindow()->ContentsRegionRect.Max.x += frameHeight * 0.5f;
#endif
	ImGui::GetCurrentWindow()->Size.x += frameHeight;

	ImGui::Dummy(ImVec2(0.0f, 0.0f));

	ImGui::EndGroup();
}