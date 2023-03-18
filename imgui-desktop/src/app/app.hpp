#pragma once
#include <common.hpp>
#include "gui/gui.hpp"
class app {
public:
	// Data
	ID3D11Device* g_pd3dDevice = NULL;
	ID3D11DeviceContext* g_pd3dDeviceContext = NULL;
	IDXGISwapChain* g_pSwapChain = NULL;
	ID3D11RenderTargetView* g_mainRenderTargetView = NULL;

	WNDCLASSEXW wc;
	HWND hwnd;
	gui* my_gui;
	bool running = true;
	app();
	~app();


	//helper functions
	bool CreateDeviceD3D(HWND hWnd);
	void CleanupDeviceD3D();
	void CreateRenderTarget();
	void CleanupRenderTarget();
	LRESULT CALLBACK wnd_proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

