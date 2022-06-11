//Student1 Daniel Penkov, penkovdany@gmail.com, 207925504
//Student2 Itay Olivcovitz, Itay.olivcovitz@gmail.com, 207745639

#include "Branch.h"
#include <iostream>

/**
 * @brief help to sort the vector by price
 *
 * @return bool - i.price < j.price
 */
bool Branch::compare_Price(const Item* i, const Item* j)
{
	return i->getPrice() < j->getPrice();
}

/**
 * @brief help to sort the vector by ID
 *
 * @return bool - i.ID < j.ID
 */
bool Branch::compare_ID(const Item* i, const Item* j)
{
	return i->getId() < j->getId();
}

/**
 * @brief Construct a new Branch object
 * 
 * @param location and capacity of Branch
 */
Branch::Branch(const string& location,const int capacity)
	: location(location), capacity(capacity)
{}

/**
 * @brief Construct a new Branch with parameters of existing one
 * 
 * @param other - branch to use the parameters 
 */
Branch::Branch(const Branch& other)
	: location(other.location), capacity(other.capacity)
{}

/**
 * @brief Add item to the branch.
 * 
 * @param item - item to be added
 */
void Branch::addItem(Item* item)
{
	// Capacity at max
	if (this->catalog.size() >= this->capacity)
	{
		throw FullCatalogError();
	}

	// Item in catalog
	for (Item* i : this->catalog)
	{
		if (*i == *item)
		{
			throw ExistingItemError();
		}
	}

	// Add the item
	this->catalog.push_back(item);
}

/**
 * @brief Delete item from the catalog.
 *
 * @param ID - the ID
 * @return Item* - pointer to removed item
 */
Item* Branch::deleteItem(const int id)
{
	// Iterate throw the items in the catalog
	for (auto iter = this->catalog.begin(); iter != this->catalog.end(); ++iter)
	{
		// If found the id
		if ((*iter)->getId() == id)
		{
			Item* ptr = *iter;
			this->catalog.erase (iter);	// Remove the item from the vector
			return ptr;		// Return the removed item
		}
	}

	// If got to here - no items found
	throw NonExistingItemError();
}

/**
 * @brief evaluate the catalog.
 *
 * @return int - that represent the price of all the item in the catalog
 */
Branch::operator int() const
{
	int value = 0;	// Sum starts from zero

	// Sum all item's prices
	for (Item* itr : this->catalog)
		value += itr->getPrice();
	
	return value;
}

/**
 * @brief Get the Catalog
 * 
 * @return vector<Item*> - the catalog
 */
vector<Item*> Branch::getCatalog()  
{
	return this->catalog;
}

/**
 * @brief Gets the max capacity of this branch
 * 
 * @return int - max capacity
 */
int Branch::getCapacity() const
{
	return this->capacity;
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
 * 
 */
void Branch::print_catalog_by_id() const
{
	// Copy all the items to new vector
	vector<Item*> items;
	items.assign(this->catalog.begin(), this->catalog.end());

	// Sort by ID
	std::stable_sort(items.begin(), items.end(), compare_ID);

	// Print the items
	print_branch(items);
}


/**
 * @brief Print the catalog by price
 * 
 */
void Branch::print_catalog_by_price() const
{
	// Copy all the items to new vector
	vector<Item*> items;
	items.assign(this->catalog.begin(), this->catalog.end());

	// Sort by price
	std::stable_sort(items.begin(), items.end(), compare_Price);

	// Print the items
	print_branch(items);
}

/**
 * @brief Print vector of items
 * 
 */
void Branch::print_branch(const vector<Item*>& items) const
{
	// Print title
    cout << "Printing KSF branch in " << this->getLocation() << endl;
    cout << "There are " << this->catalog.size() << " item in the catalog" << endl;
    cout << "Catalog value is: " << int(*this) << endl;

	for (Item* item : items)
		cout << string(*item) << endl;
}

/**
 * @brief Destroy the Branch object
 * 
 */
Branch::~Branch()
{
	// Delete all items in catalog
	for (Item* item : this->catalog)
		delete item;
}
