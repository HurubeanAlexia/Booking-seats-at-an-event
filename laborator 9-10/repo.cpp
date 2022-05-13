#include "repo.h"

Repo::Repo()
{
}

int Repo::no_elems()
{
	return elems.size();
}

void Repo::add_item(const Entity& e)
{
	elems.push_back(e);
}

void Repo::delete_item(int pos)
{
	elems.erase(elems.begin() + pos);
}

void Repo::modify_item(int pos, const Entity& e)
{
	elems.at(pos) = e;
}

Entity Repo::elemAt(int pos)
{
	return elems.at(pos);
}

vector<Entity>& Repo::get_all()
{
	return elems;
}

Repo::~Repo()
{
}
