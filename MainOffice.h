//Student1 Daniel Penkov, penkovdany@gmail.com, 207925504
//Student2 Itay Olivcovitz, Itay.olivcovitz@gmail.com, 207745639

#ifndef MAINOFFICE_H
#define MAINOFFICE_H

#include <map>
#include <string>
#include <iostream>
#include "Branch.h"

using std::map;
using std::string;
using std::cout;
using std::endl;

class MainOffice
{
private:
    map<string, Branch> branches;

    // Hide all c'tors & d'tors for singleton
    MainOffice();
    MainOffice(const MainOffice&);
    ~MainOffice();

public:

    /**
     * @brief Get the instance of MainOffice
     * 
     * @return MainOffice& 
     */
    static MainOffice& getInstance();

    /**
     * @brief Add new branch to the MainOffice
     * 
     * @param location - branch's location
     * @param capacity - branch's capacity
     */
    void addBranch(const string& location, const int capacity);

    /**
     * @brief Delete branch from the MainOffice
     * 
     * @param location - branch's location
     */
    void deleteBranch(const string& location);

    /**
     * @brief print branches by location
     * 
     */
    void printByLocation() const;

    /**
     * @brief Get the Branches
     * 
     * @return map<string, Branch> - Map of the branches
     */
    map<string, Branch>& getBranches();
};

/**
 * @brief Adding branch with existing location
 * 
 * Thrown by MainOffice::addBranch
 */
class ExistingBranchError : public exception
{
    virtual const char* what() const throw()
    {
        return "Trying to add a branch with an already existing location";
    }
};

/**
 * @brief Removing non existing branch
 * 
 * Thrown by MainOffice::deleteBranch
 */
class NonExistingBranchError : public exception
{
    virtual const char* what() const throw()
    {
        return "Trying to delete a branch with an non existing location";
    }
};

#endif /* MAINOFFICE_H */