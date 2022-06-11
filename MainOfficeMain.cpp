#include <iostream>
#include "Branch.h"
#include "Computer.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Webcam.h"
#include "MainOffice.h"
#define TEST_MAIN_SIZE 4 // not related to STORE_SIZE , only here for the main test

int main()
{
	Item* items[TEST_MAIN_SIZE]; //the array is only here for code organization
	items[0] = new Computer(60, "Dell", "Intel", true, 3);
	items[0]->setPrice(70);
	items[1] = new Computer(100, "Apple", "AMD", false, 2);
	items[2] = new Mouse(5, "Pilot", "Red", true, 100);
	items[3] = new Keyboard(10, "Casio", "Silver", false, 26);
	MainOffice::getInstance().addBranch("Haifa", 14);
	try
	{
		for (int i = 0; i < TEST_MAIN_SIZE; i++)
		{

			MainOffice::getInstance().getBranches()["Haifa"].addItem(items[i]);
		}

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	MainOffice::getInstance().getBranches()["Haifa"].print_catalog_by_id();
	std::cout << std::endl;
	MainOffice& mo = MainOffice::getInstance();
	Branch& haifaBranch = mo.getBranches()["Haifa"];
	haifaBranch.print_catalog_by_price();
	std::cout << std::endl;
	try
	{
		mo.addBranch("Haifa", 100000);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		mo.deleteBranch("Tel-Aviv");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		mo.deleteBranch("Haifa");
		mo.addBranch("Tel-Aviv", 1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	mo.printByLocation();
	
	std::cout << "End of main" << std::endl;

}