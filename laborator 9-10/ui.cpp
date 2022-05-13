#include "ui.h"
#include <Windows.h>
#include <iostream>

UI::UI(Service& service) : service(service) {};

void UI::print_menu()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 6);
	std::cout << "1. Adauga eveniment" << std::endl;
	std::cout << "2. Modifica eveniment" << std::endl;
	std::cout << "3. Sterge eveniment" << std::endl;
	std::cout << "4. Afiseaza numarul de evenimente" << std::endl;
	std::cout << "5. Afiseaza evenimentele " << std::endl;
	std::cout << "6. Afiseaza eveniment dupa nume " << std::endl;
	std::cout << "7. Transferati locuri " << std::endl;
	std::cout << "8. Rezervati locuri " << std::endl;
	std::cout << "-1. Iesire" << std::endl;
}

void UI::run()
{
	while (true) {
		int input;

		this->print_menu();

		std::cout << "Alegerea ta: ";
		std::cin >> input;
		std::cout << std::endl;

		if (input != -1) {
			switch (input)
			{
			case 1:
			{
				string name;
				int seats_avai_up{ 0 };
				int seats_avai_down{ 0 };

				std::cout << "Tastati numele evenimentului: ";
				std::cin >> name;
				std::cout << std::endl;

				std::cout << "Tastati locuri disponibile pe scaun: ";
				std::cin >> seats_avai_up;
				std::cout << std::endl;

				std::cout << "Tastati locuri disponibile in picioare: ";
				std::cin >> seats_avai_down;
				std::cout << std::endl;

				service.add_item(seats_avai_up, name.c_str(), seats_avai_down);
			}
			break;
			case 2:
			{
				string name;
				int seats_avai_up{ 0 };
				int seats_avai_down{ 0 };

				std::cout << "Tastati numele evenimentului pe care doriti sa-l modificati: ";
				std::cin >> name;
				std::cout << std::endl;

				std::cout << "Tastati locuri disponibile pe scaun: ";
				std::cin >> seats_avai_up;
				std::cout << std::endl;

				std::cout << "Tastati locuri disponibile in picioare: ";
				std::cin >> seats_avai_down;
				std::cout << std::endl;

				Entity e(seats_avai_up, name, seats_avai_down);

				service.update_item(name, e);
			}
			break;
			case 3:
			{
				string name;
				std::cout << "Dati numele evenimentului pe care doriti sa il stergeti: ";
				std::cin >> name;
				std::cout << std::endl;

				service.delete_item_by_name(name);
			}
			break;
			case 4:
			{
				std::cout << "Numarul de evenimente disponibile: " << service.no_entities();
				std::cout << std::endl;
			}
			break;
			case 5:
			{
				std::cout << "Afisarea evenimentelor: " << std::endl;
				for (int i = 0; i < service.no_entities(); i++) {
					std::cout << service.get_all_entities()[i].get_nume() << std::endl;
					std::cout << service.get_all_entities()[i].get_seats_avai_up() << std::endl;
					std::cout << service.get_all_entities()[i].get_seats_avai_down() << std::endl;
				}
			}
			break;
			case 6:
			{
				string name;
				std::cout << "Afisarea evenimentului cu numele: " << std::endl;
				std::cin >> name;
				std::cout << std::endl;

				std::cout << service.search_event_by_name(name).get_nume() << std::endl;

			}
			break;
			case 7:
			{
				string name;
				std::cout << "Dati numele evenimentului caruia vreti sa ii transferati locurile: " << std::endl;
				std::cin >> name;
				std::cout << std::endl;

				int seats_to_transfer;
				std::cout << "Dati numarul locurilor: " << std::endl;
				std::cin >> seats_to_transfer;
				std::cout << std::endl;

				service.transfer_seats_from_up_to_down(seats_to_transfer, name);

			}
			break;
			case 8:
			{
				string name;
				std::cout << "Dati numele evenimentului caruia vreti sa ii rezervati locurile: " << std::endl;
				std::cin >> name;
				std::cout << std::endl;

				int seats_up;
				std::cout << "Dati numarul locurilor pe care vreti sa le rezervati in picioare: " << std::endl;
				std::cin >> seats_up;
				std::cout << std::endl;

				int seats_down;
				std::cout << "Dati numarul locurilor pe care vreti sa le rezervati jos: " << std::endl;
				std::cin >> seats_down;
				std::cout << std::endl;

				service.book_seats(seats_up, seats_down, name);
			}
			break;
			}
		}
		else return;
	}
}