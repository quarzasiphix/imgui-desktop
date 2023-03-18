#pragma once
#include <common.hpp>
#include "gui/gui.hpp"
class app {
public:
	GLFWwindow* window;

	gui* my_gui;
	bool running = true;
	app();
	~app();
};

