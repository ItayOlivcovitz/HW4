#pragma once
#include <iostream>
using std::string;
class HWExceptions : public std::exception 
{
    
public:

    class ExistingItemError : public exception
    {
        /**
         * @brief Set error to ExistingItemError.
         */
        virtual const char* what() const throw()
        {
            return "Trying to add an item with an id already in the catalog";
        }
    }ExistingItemError;
    
    class FullCatalogError : public exception
    {
        /**
         * brief Set error to FullCatalogError.
         */
        virtual const char* what() const throw()
        {
            return "Trying to add an item to a full catalog";
        }
    }FullCatalogError;

    class NonExistingItemError : public exception
    {
        /**
         * brief Set error to NonExistingItemError.
         */
        virtual const char* what() const throw()
        {
            return "Trying to delete an item with a non existing id";
        }
    }NonExistingItemError;

    class NoneExistingItemTypeError : public exception
    {
        /**
         * brief Set error to NoneExistingItemTypeError.
         */
        virtual const char* what() const throw()
        {
            return "Trying to get an item with a non existing type";
        }
    }NoneExistingItemTypeError;
   
    class ConnectError : public exception
    {
        /**
         * brief Set error to ConnectError.
         */
        virtual const char* what() const throw()
        {
            return "Failed connection attempt";
        }
    }ConnectError;

    

};