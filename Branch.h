//Student1 Daniel Penkov, penkovdany@gmail.com, 207925504
//Student2 Itay Olivcovitz, Itay.olivcovitz@gmail.com, 207745639

#ifndef BRANCH_H
#define BRANCH_H

#include "Item.h"
#include "HWExceptions.h""
#include <string>
#include <vector>
#include <algorithm>
#include <map>


#define STORE_SIZE 10
#define INITIAL_SIZE 0

using std::string;
using std::vector;
using std::map;
using std::exception;


class Branch 
{
private:
	// Private variables
	string location;
	vector<Item*> catalog;
	int capacity;	// Not representing how much items in brunch !

	/**
 * @brief help to sort the vector
 *
 * @return bool - if Item i< Item j return true
 */
	static bool compare_Price(const Item* i, const Item* j) ;

	/**
 * @brief help to sort the vector
 *
 * @return bool - if Item i< Item j return true
 */
	static bool compare_ID(const Item* i, const Item* j);
	

public:
	/**
	 * @brief Construct a new Branch object.
	 *
	 * @param location - location and capacity of Branch
	 */
	Branch(const string& location, const int capacity);

	/**
	 * @brief retrieve the most expensive obj
	 *
	 * @param obj - the define the type
	 */
	template<class T>
	T* retrieveFinest(T* obj)
	{
		T* ptr;
		Item* highest_Price;

		for (auto itr : this->catalog)
		{
			if (dynamic_cast<T*>(itr))
			{
				if (highest_Price == NULL)
				{
					highest_Price = itr;
				}

				else if(highest_Price->getPrice() < itr->getPrice())
				{
					highest_Price = itr;
				}
			}
		}

		return dynamic_cast<T*>(highest_Price);
	}
	/**
	 * @brief Add item to the branch.
	 *
	 * @param item - item to be added
	 */
	void addItem(Item* item);

	/**
	 * @brief Delete item from the catalog.
	 *
	 * @param ID - the ID
	 * @return Item* - ptr to the ID
	 */
	Item* deleteItem(const int ID) const;
	
	/**
	 * @brief evaluate the catalog.
	 *
	 *
	 * @return int - that represent the price of all the item in the catalog
	 */
	operator int();

	/**
	 * @brief Get array for Item pointers inside this branch.
	 *
	 * @param num - how much items int returned array
	 * @return Item** - array of brunch items
	 */
	vector<Item*> getCatalog(int& size);

	/**
	 * @brief Delete Item from catalog by ID.
	 *
	 * @param ID - The ID of the item
	 * @return *Item - ptr to the Item
	 */
	Item* deleteItem(const int ID);
	

	/**
     * @brief Set the brunch location.
     *
     * @param location - new location to set
     */
	void setLocation(const string & location);

	/**
	 * @brief Get the brunch location
	 *
	 * @return std::string - brunch's location
     */
	std::string getLocation() const;

	/**
    * @brief Print the catalog by ID
    */
	void print_catalog_by_id();

	/**
	* @brief Print the catalog by price
	*/
	void print_catalog_by_price();
	
	// Destractor
	~Branch();
};

#endif /* BRANCH_H */