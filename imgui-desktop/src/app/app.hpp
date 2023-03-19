#pragma once
#include <common.hpp>
#include <app/gui/gui.hpp>

class app {
public:
	GLFWwindow* window;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	std::unique_ptr<gui> my_gui;
	bool running = true;
	app(std::unique_ptr<gui> gui_ptr);
	~app();
	bool init();
	void loop();
};

