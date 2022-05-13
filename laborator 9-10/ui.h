#pragma once
#include "Service.h"

class UI {
private:
	Service& service;
public:
	UI(Service& service);

	void print_menu();
	void run();

	~UI() = default;
};