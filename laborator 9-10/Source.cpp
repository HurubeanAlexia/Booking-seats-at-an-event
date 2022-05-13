#include <iostream>
#include "entitate.h"
#include "repo.h"
#include "service.h"
#include "ui.h"
#include "tests.h"
using namespace std;


int main() {
	tests();

	Repo repo;
	Service service(repo);
	UI ui(service);

	ui.run();

	std::cout << "da";
}