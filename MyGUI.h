#pragma once
//-----------------------------------------------------------------------------
//	Dear GUI
//-----------------------------------------------------------------------------
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"

#include <Windows.h>
#include <string>

#include "Application.h"
#include "CDirectxGraphics.h"


extern  LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class MyGUI
{
public:
	static MyGUI* GetInstance()
	{
		static MyGUI m_instance;
		return &m_instance;
	}

	//��������������������������������������������������������
	//
	//	IO���͌n
	//
	//	WindowProc�ŏ���������
	//
	//��������������������������������������������������������
	LRESULT Win32Proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


	//��������������������������������������������������������
	//
	//	����������
	//
	//	MyGUI������������
	//
	//��������������������������������������������������������
	void Init();


	//��������������������������������������������������������
	//
	//	�`�悷��i�O�̐ݒu�j
	//
	//	
	//
	//��������������������������������������������������������
	void StartDraw();

	//��������������������������������������������������������
	//
	//	�`�悷��i��̐ݒu�j
	//
	//	
	//
	//��������������������������������������������������������
	void EndDraw();


	//��������������������������������������������������������
	//
	//	�`�悷����e
	//	
	//
	//��������������������������������������������������������
	void Window(std::string);


	//��������������������������������������������������������
	//
	//	Demo Window
	//	
	//
	//��������������������������������������������������������
	void ShowDemoWindow(bool showFlag);

};

