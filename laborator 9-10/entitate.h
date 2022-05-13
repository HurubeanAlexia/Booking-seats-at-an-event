#pragma once
#include <string>

class Entity {
private:
	int seats_avai_up;
	int seats_avai_down;
	std::string nume;
public:
	Entity();
	Entity(int seats_avai_up, std::string nume, int seats_avai_down);
	Entity(const Entity& e);

	//setteri

	void set_nume(std::string nume);
	void set_seats_avai_up(int seats_avai_up);
	void set_seats_avai_down(int seats_avai_down);

	//getteri

	std::string get_nume() const;
	int get_seats_avai_up() const;
	int get_seats_avai_down() const;

	Entity& operator=(const Entity& e);
	bool operator==(const Entity& e);

	//destructor
	~Entity();
};