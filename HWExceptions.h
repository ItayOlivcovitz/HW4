//Student1 Daniel Penkov, penkovdany@gmail.com, 207925504
//Student2 Itay Olivcovitz, Itay.olivcovitz@gmail.com, 207745639

#ifndef HWEXCEPTION_H
#define HWEXCEPTION_H

#include <exception>

using std::exception;

/**
 * @brief Adding item that is already in the branch
 * 
 * Thrown by Branch::addItem
 */
class ExistingItemError : public exception
{
    virtual const char* what() const throw()
    {
        return "Trying to add an item with an id already in the catalog";
    }
};

/**
 * @brief No more space in the brunch.
 * 
 * Thrown by Branch::addItem
 */
class FullCatalogError : public exception
{
    virtual const char* what() const throw()
    {
        return "Trying to add an item to a full catalog";
    }
};

/**
 * @brief Trying to delete item that is not in the brunch
 * 
 * Thrown by Branch::DeleteItem
 */
class NonExistingItemError : public exception
{
    virtual const char* what() const throw()
    {
        return "Trying to delete an item  with a non existing id";
    }
};

/**
 * @brief The branch doesn't have items from the category.
 * 
 * Thrown by Branch::retrieveFinest
 */
class NoneExistingItemTypeError : public exception
{
    virtual const char* what() const throw()
    {
        return "Trying to get an item with a non existing type";
    }
};

/**
 * @brief Could not establish connection between computer and peripheral device.
 * 
 * Thrown by PeriphrelDevice::connect
 */
class ConnectError : public exception
{
    virtual const char* what() const throw()
    {
        return "Failed connection attempt";
    }
};

#endif /* HWEXCEPTION_H */