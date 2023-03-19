#pragma once
#include <common.hpp>
#include <app/app.hpp>
class app;
class gui {
	~gui();
	bool init(app* app_object);
	void run();
	void face();
private:
	std::unique_ptr<app> my_app{};
};

