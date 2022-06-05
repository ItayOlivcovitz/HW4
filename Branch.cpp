//Student1 Daniel Penkov, penkovdany@gmail.com, 207925504
//Student2 Itay Olivcovitz, Itay.olivcovitz@gmail.com, 207745639

#include "Branch.h"
#include <iostream>



/**
 * @brief Construct a new Branch object
 * 
 * @param location and capacity of Branch
 */
Branch::Branch(const string& location,const int capacity)
	: location(location), capacity(capacity)
{
}

/**
 * @brief Add item to the branch.
 * 
 * @param item - item to be added
 */
void Branch::addItem(Item* item)
{

	if (!this->catalog.empty())
	{
		if (this->catalog.capacity() >= this->capacity)
		{
			HWExceptions e;
			throw e.FullCatalogError;
		}
		for (auto i : this->catalog)
		{
			if ( i == item)
			{
				HWExceptions e;
				throw e.ExistingItemError;
			}
		}
    }

	this->catalog.push_back(item);
}

/**
 * @brief Get array for Item pointers inside this branch.
 * 
 * @param num - how much items int returned array
 * @return Item** - array of brunch items
 */
vector<Item *> Branch::getCatalog(int &size)  
{
	return this->catalog;
}

/**
	 * @brief Delete Item from catalog by ID.
	 *
	 * @param ID - The ID of the item
	 * @return *Item - ptr to the Item
	 */
Item* Branch::deleteItem(const int ID)
{
	//this->catalog.erase[1]
	return this->catalog[1];
}

/**
 * @brief Set the brunch location.
 * 
 * @param location - new location to set
 */
void Branch::setLocation(const string& location)
{
	this->location = location;
}

/**
 * @brief Get the brunch location
 * 
 * @return std::string - brunch's location
 */
std::string Branch::getLocation() const
{
	return this->location;
}

/**
 * @brief Print the catalog by ID
 */
void Branch:: print_catalog_by_id()
{
	map<int, Item*> map_By_Id;

	for (auto i : this->catalog)
	{
		int item_ID =i->getId();
		map_By_Id[item_ID] = i;
	}
	
	for (auto i : map_By_Id)
	{
		std::cout << string(*i.second) << std::endl;
	}
}

/**
 * @brief help to sort the vector
 *
 * @return bool - if Item i< Item j return true
 */
bool Branch::compare_Price(const Item* i, const Item* j)
{
	
	return (i->getPrice() < j->getPrice());
}


/**
 * @brief Print the catalog by price
 */
void Branch::print_catalog_by_price()
{
	vector<Item*> vector_By_Price;
	vector_By_Price.assign(this->catalog.begin(), this->catalog.end());
	std::stable_sort(vector_By_Price.begin(), vector_By_Price.end(),compare_Price);

	for (auto it = vector_By_Price.cbegin(); it != vector_By_Price.cend(); it++)
	{
		std::cout << string(**it) << std::endl;
	}

}

// Destractor
Branch::~Branch()
{
	
	
}
