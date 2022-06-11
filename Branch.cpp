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
			
			throw FullCatalogError();
		}
		for (auto i : this->catalog)
		{
			if ( i == item)
			{
				
				throw ExistingItemError();
			}
		}
    }

	this->catalog.push_back(item);
}

/**
	 * @brief Delete item from the catalog.
	 *
	 * @param ID - the ID
	 * @return Item* - ptr to the ID
	 */
Item* Branch::deleteItem(const int ID) const
{
	Item* ptr = NULL;
	for (auto itr : this->catalog)
	{
		if (itr->getId() == ID)
		{
			ptr = itr;
		}
	}
	if (ptr)
	{
		throw NonExistingItemError();
	}
	return ptr;
}

/**
	 * @brief evaluate the catalog.
	 *
	 *
	 * @return int - that represent the price of all the item in the catalog
	 */
Branch::operator int()
  {
	int value = 0;
	for (auto itr : this->catalog)
	{
		value += itr->getPrice();
	}
	return value;
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
	
	std::cout << "Printing KSF branch in " << this->getLocation() << std::endl;
	std::cout << "There are " << this->catalog.size() <<" item in the catalog"<< std::endl;
	std::cout << "Catalog value is: " << int(*this) << std::endl;

	vector<Item*> vector_By_Price;
	vector_By_Price.assign(this->catalog.begin(), this->catalog.end());
	std::stable_sort(vector_By_Price.begin(), vector_By_Price.end(), compare_ID);

	for (auto it = vector_By_Price.cbegin(); it != vector_By_Price.cend(); it++)
	{
		std::cout << string(**it) << std::endl;
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
 * @brief help to sort the vector
 *
 * @return bool - if Item i< Item j return true
 */
bool Branch::compare_ID(const Item* i, const Item* j)
{
	return (i->getId() < j->getId());
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
