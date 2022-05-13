#include "entitate.h"
#include <string.h>

Entity::Entity()
{
	seats_avai_down = -1;
	seats_avai_up = -1;
	nume = "";
}

Entity::Entity(int seats_avai_up, std::string nume, int seats_avai_down)
{
	this->seats_avai_down = seats_avai_down;
	this->seats_avai_up = seats_avai_up;
	this->nume = nume;
}

Entity::Entity(const Entity& e)
{
	seats_avai_down = e.seats_avai_down;
	seats_avai_up = e.seats_avai_up;
	nume = e.nume;
}

void Entity::set_nume(std::string nume)
{
	this->nume = nume;
}

void Entity::set_seats_avai_up(int seats_avai_up)
{
	this->seats_avai_up = seats_avai_up;
}

void Entity::set_seats_avai_down(int seats_avai_down)
{
	this->seats_avai_down = seats_avai_down;
}

std::string Entity::get_nume() const
{
	return nume;
}

int Entity::get_seats_avai_up() const
{
	return seats_avai_up;
}

int Entity::get_seats_avai_down() const
{
	return seats_avai_down;
}

Entity& Entity::operator=(const Entity& e)
{
	if (this != &e) {
		set_nume(e.nume);
		set_seats_avai_down(e.seats_avai_down);
		set_seats_avai_up(e.seats_avai_up);
	}

	return *this;
}

bool Entity::operator==(const Entity& e)
{
	return (seats_avai_up == e.seats_avai_up) && (seats_avai_down == e.seats_avai_down) && (nume == e.nume);
}

Entity::~Entity()
{
}
