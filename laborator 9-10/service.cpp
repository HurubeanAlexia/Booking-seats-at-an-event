#include "service.h"
#include <iostream>

Service::Service(Repo& repo) : repo(repo) {};

Service::~Service()
{
}

void Service::add_item(int seats_avai_up, const char* nume, int seats_avai_down)
{
	Entity e(seats_avai_up, nume, seats_avai_down);
	repo.add_item(e);
}

void Service::update_item(std::string nume, const Entity& e)
{
	int pos;
	for (int i = 0; i < repo.no_elems(); i++)
		if (repo.elemAt(i).get_nume() == nume)
			pos = i;
	repo.modify_item(pos, e);
}

void Service::delete_item(int pos)
{
	repo.delete_item(pos);
}

int Service::no_entities()
{
	return repo.no_elems();
}

void Service::delete_item_by_name(string name)
{
	for (size_t i = 0; i < repo.no_elems(); i++) {
		string name_to_compare = repo.elemAt(i).get_nume();
		if (name_to_compare == name)
			repo.delete_item(i);
	}
}

std::vector<Entity> Service::get_all_entities()
{
	return repo.get_all();
}

Entity Service::search_event_by_name(string name)
{
	for (int i = 0; i < repo.no_elems(); i++)
		if (repo.elemAt(i).get_nume() == name)
			return repo.elemAt(i);
}

void Service::transfer_seats_from_up_to_down(int seats_to_transfer, string name)
{
	for (int i = 0; i < repo.no_elems(); i++)
		if (repo.elemAt(i).get_nume() == name) {
			int seats_up = repo.elemAt(i).get_seats_avai_up();
			int seats_down = repo.elemAt(i).get_seats_avai_down();

			seats_down = seats_down + seats_to_transfer;
			seats_up = seats_up - seats_to_transfer;

			repo.get_all()[i].set_seats_avai_up(seats_up);
			repo.get_all()[i].set_seats_avai_down(seats_down);
		}
}

void Service::book_seats(int seats_u, int seats_d, string name)
{
	for (int i = 0; i < repo.no_elems(); i++)
		if (repo.elemAt(i).get_nume() == name) {
			int seats_up = repo.elemAt(i).get_seats_avai_up();
			int seats_down = repo.elemAt(i).get_seats_avai_down();

			seats_down = seats_down - seats_d;
			seats_up = seats_up - seats_u;

			repo.get_all()[i].set_seats_avai_up(seats_up);
			repo.get_all()[i].set_seats_avai_down(seats_down);
		}
}
