#pragma once
#include <iostream>
using std::string;
class HWExceptions : public std::exception 
{
    string error;
public:

    /**
     * @brief Set error to ExistingItemError.
     */
    void ExistingItemError() 
    {
        this->error = "Trying to add an item with an id already in the catalog"; 
    }

    /**
     * @brief Set error to FullCatalogError.
     */
    void FullCatalogError() 
    {
        this->error = "Trying to add an item to a full catalog";
    }

    /**
     * @brief Set error to NonExistingItemError.
     */
    void NonExistingItemError() 
    {
        this->error = "Trying to delete an item with a non existing id";
    }

    /**
     * @brief Set error to NoneExistingItemTypeError.
     */
    void NoneExistingItemTypeError() 
    {
        this->error = "Trying to get an item with a non existing type";  
    }

    /**
    * @brief Set error to ConnectError.
    */
    void ConnectError() 
    {
        this->error = "Failed connection attempt";
    }

    /**
     * @brief Get what heppend.
     *
     * @return char - error description
     */
    char const* what() const
    {
        return this->error.c_str();
    }
};