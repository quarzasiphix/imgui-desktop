// Dear ImGui: standalone example application for DirectX 11
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs
#include <common.hpp>
// Main code
int main(int, char**) {
	app* my_app = new app();
	while (glfwWindowShouldClose(my_app->window)) {
		my_app->loop();
	}
	delete my_app;
}
