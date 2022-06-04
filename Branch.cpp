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
			e.FullCatalogError();
			throw e;
		}
		for (auto i : this->catalog)
		{
			if ( i == item)
			{
				HWExceptions e;
				e.ExistingItemError();
				throw e;
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
 * @brief Print the catalog by price
 */
void Branch::print_catalog_by_price()
{
	map<int, vector<Item*>> map_By_Price;
	map_By_Price = createMap(this->catalog);

	for (auto i : map_By_Price)
	{
		for (auto j : i.second)
		{
			std::cout << string(*j) << std::endl;
		}
	}
}

/**
 * @brief Create map <price,vector>.
 *
 * @param Vector - The catalog
 * @return map<price,vector> - A map when the key is price
 */
map<int, vector<Item*>> Branch::createMap(const vector<Item*> vec) const
{
	map<int, vector<Item*>> new_Map;
	for (auto i : vec)
	{
		vector<Item*> new_Vector;
		new_Vector.push_back(i);
		for (auto j : vec)
		{
			if (i->getPrice() == j->getPrice() && i != j)
			{
				new_Vector.push_back(j);
			}
		}
		new_Map[i->getPrice()] = new_Vector;
	}
	return new_Map;
}

// Destractor
Branch::~Branch()
{
	
	
}
