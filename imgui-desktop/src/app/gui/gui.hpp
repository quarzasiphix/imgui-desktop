#pragma once
#include <common.hpp>

class gui {
public:
	GLFWwindow* window;
	~gui();
	bool init();
	void run();
	void face();
};