
#pragma once
#include "repo.h"
#include "entitate.h"
#include <string>

class Service {
private:
	Repo& repo;
public:
	Service(Repo& repo);
	~Service();

	void add_item(int seats_avai_up, const char* nume, int seats_avai_down);
	void update_item(std::string nume, const Entity& e);
	void delete_item(int pos);
	void delete_item_by_name(string name);
	Entity search_event_by_name(string name);
	void transfer_seats_from_up_to_down(int seats_to_transfer, string name);
	void book_seats(int seats_up, int seats_down, string name);
	int no_entities();

	std::vector<Entity> get_all_entities();
};