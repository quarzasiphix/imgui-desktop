#pragma once
#include <common.hpp>
class gui {
public:
	gui(app& app_object);
	~gui();
	void run();
	void face();
private:
	std::unique_ptr<app> my_app;
};

