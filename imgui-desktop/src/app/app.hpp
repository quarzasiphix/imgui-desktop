#pragma once
#include <common.hpp>
class app {
public:
	GLFWwindow* window;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	gui my_gui;
	bool running = true;
	app();
	~app();

	void loop();
};

