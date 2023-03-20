#pragma once
#include <common.hpp>

class gui {
public:
	GLFWwindow* window;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	int display_w, display_h;
	~gui();
	bool init();
	void run();
	void face();
	void dock();
};