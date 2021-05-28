#include "MyGUI.h"
using namespace std;

LRESULT MyGUI::Win32Proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (!ImGui_ImplWin32_WndProcHandler(hWnd,  msg,  wParam,  lParam))
	{
		return false;
	}

	return true;
}

void MyGUI::Init()
{
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

	// Setup Platform/Renderer backends
	ImGui_ImplWin32_Init(Application::Instance()->GetHWnd());

	// Setup Platform/Renderer backends
	ImGui_ImplDX11_Init(CDirectXGraphics::GetInstance()->GetDXDevice(), CDirectXGraphics::GetInstance()->GetImmediateContext());

}

void MyGUI::StartDraw()
{
	// Start the Dear ImGui frame
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}

void MyGUI::EndDraw()
{
	// Rendering
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void MyGUI::Window(string wndName)
{

	ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

	ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)

	ImGui::End();
}

void MyGUI::ShowDemoWindow(bool showFlag)
{
	if (showFlag)
	{
		ImGui::ShowDemoWindow(&showFlag);
	}
}
