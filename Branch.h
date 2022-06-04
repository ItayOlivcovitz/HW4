//Student1 Daniel Penkov, penkovdany@gmail.com, 207925504
//Student2 Itay Olivcovitz, Itay.olivcovitz@gmail.com, 207745639

#ifndef BRANCH_H
#define BRANCH_H

#include "Item.h"
#include "HWExceptions.h""
#include <string>
#include <vector>
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
	 * @brief Create map <price,vector>.
	 *
	 * @param Vector - The catalog
	 * @return map<price,vector> - A map when the key is price
	 */
	map<int, vector<Item*>> createMap(const vector<Item*>vec) const;

public:
	/**
	 * @brief Construct a new Branch object.
	 *
	 * @param location - location and capacity of Branch
	 */
	Branch(const string& location, const int capacity);


	/**
	 * @brief Add item to the branch.
	 *
	 * @param item - item to be added
	 */
	void addItem(Item* item);

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