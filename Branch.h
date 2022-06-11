//Student1 Daniel Penkov, penkovdany@gmail.com, 207925504
//Student2 Itay Olivcovitz, Itay.olivcovitz@gmail.com, 207745639

#ifndef BRANCH_H
#define BRANCH_H

#include "Item.h"
#include "HWExceptions.h"
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::exception;
using std::cout;
using std::endl;

class Branch 
{
private:
	// Private variables
	string location;
	vector<Item*> catalog;
	int capacity;	// Not representing how much items in brunch !

	/**
	 * @brief help to sort the vector by price
	 *
	 * @return bool - i.price < j.price
	 */
	static bool compare_Price(const Item* i, const Item* j);

	/**
	 * @brief help to sort the vector by ID
	 *
	 * @return bool - i.ID < j.ID
	 */
	static bool compare_ID(const Item* i, const Item* j);
	
public:
	/**
	 * @brief Construct a new Branch
	 * 
	 * @param location - branch location
	 * @param capacity - branch max capacity
	 */
	Branch(const string& location = "~", const int capacity = 0);

	/**
	 * @brief Construct a new Branch with parameters of existing one
	 * 
	 * @param other - branch to use the parameters 
	 */
	Branch(const Branch& other);

	/**
	 * @brief retrieve the most expensive item of type T
	 *
	 * @param obj - the define the type
	 */
	template<class T>
	T* retrieveFinest(T* obj)
	{
		Item* highest_Price = NULL;	// Will store the expensivest item

		// Iterate throw all items in catalog
		for (Item* item : this->catalog)
		{
			// If item is of type T
			if ( dynamic_cast<T*>(item) )
			{
				// First item to find
				if (highest_Price == NULL)
					highest_Price = item;
				
				// Update if expensiver
				else if(highest_Price->getPrice() < item->getPrice())
					highest_Price = item;
			}
		}

		// No such item of such type in the branch
		if ( !highest_Price )
			throw NonExistingItemError();

		return dynamic_cast<T*>(highest_Price);	// Will allways succeed
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
	 * @return Item* - pointer to removed item
	 */
	Item* deleteItem(const int ID);
	
	/**
	 * @brief Evaluate the branch
	 * 
	 * @return int - branch value
	 */
	operator int() const;

	/**
	 * @brief Get the Catalog
	 * 
	 * @return vector<Item*> - the catalog
	 */
	vector<Item*> getCatalog();
	
	/**
	 * @brief Gets the max capacity of this branch
	 * 
	 * @return int - max capacity
	 */
	int getCapacity() const;
	
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
	* 
    */
	void print_catalog_by_id() const;

	/**
	* @brief Print the catalog by price
	*
	*/
	void print_catalog_by_price() const;
	
	/**
	 * @brief Print vector of items
	 * 
	 */
	void print_branch(const vector<Item*>& items) const;

	/**
	 * @brief Destroy the Branch object
	 * 
	 */
	~Branch();
};

#endif /* BRANCH_H */