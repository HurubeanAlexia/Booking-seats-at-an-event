#pragma once
#include "entitate.h"
#include <vector>
using namespace std;


class Repo {
private:
	vector<Entity> elems;
public:
	Repo();

	int no_elems();
	void add_item(const Entity& e);
	void delete_item(int pos);
	void modify_item(int pos, const Entity& e);

	Entity elemAt(int pos);
	vector<Entity>& get_all();

	~Repo();
};