#include "entitate.h"
#include "repo.h"
#include "service.h"
#include "tests.h"
#include <assert.h>
#include <iostream>

void test_entity() {
	Entity e1(10, "Opera", 11);
	Entity e2(14, "Casa", 5);
	Entity e3(8, "Culture", 7);

	Repo repo;

	repo.add_item(e1);
	repo.add_item(e2);
	repo.add_item(e3);

	assert(repo.no_elems() == 3);

	e1 = e2;

	assert(e1.get_nume() == "Casa");
	assert(repo.no_elems() == 3);
}

void test_repo() {
	Repo repo;
	assert(repo.no_elems() == 0);

	Entity et1(24, "Otello", 45);
	repo.add_item(et1);
	assert(repo.no_elems() == 1);
	assert(repo.get_all()[0] == et1);

	Entity et2(45, "Gogh", 12);
	Entity et3;
	repo.add_item(et2);
	repo.add_item(et3);
	assert(repo.no_elems() == 3);
	assert(repo.get_all()[0] == et1);
	assert(repo.get_all()[1] == et2);
	assert(repo.get_all()[2] == et3);

	repo.delete_item(1);
	assert(repo.no_elems() == 2);

	repo.modify_item(1, et1);

	assert(et1 == repo.get_all()[1]);

	assert(repo.elemAt(0).get_seats_avai_up() == 24);
}

void test_service() {
	Repo repo;
	Service service(repo);

	Entity e2(45, "Gogh", 12);

	service.add_item(67, "Otello", 45);
	assert(service.no_entities() == 1);

	service.add_item(45, "Gogh", 12);
	assert(service.no_entities() == 2);

	service.add_item(16, "Spada", 5);

	assert(service.get_all_entities()[1] == e2);

	Entity e4(260, "Castana", 100);
	service.update_item("Gogh", e4);
	assert(service.get_all_entities()[2].get_nume() == "Spada");

	service.delete_item(1);
	assert(service.no_entities() == 2);

	service.transfer_seats_from_up_to_down(10, "Otello");
	assert(service.get_all_entities()[0].get_seats_avai_down() == 55);

	service.book_seats(10, 4, "Spada");
	assert(service.get_all_entities()[1].get_seats_avai_up() == 6);
	assert(service.get_all_entities()[1].get_seats_avai_down() == 1);
}

void tests() {
	test_entity();
	test_repo();
	test_service();
}