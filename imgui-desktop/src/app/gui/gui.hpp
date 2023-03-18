#pragma once
#include <common.hpp>
#include "../app.hpp"
class gui {
public:
	ImGuiIO& io = ImGui::GetIO();
	app& my_app;
	gui(app& app_object);
	void run();
	void face();
};

