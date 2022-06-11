//Student1 Daniel Penkov, penkovdany@gmail.com, 207925504
//Student2 Itay Olivcovitz, Itay.olivcovitz@gmail.com, 207745639

#include "MainOffice.h"

// c'tor
MainOffice::MainOffice() {}

// d'tor
MainOffice::~MainOffice() {}

/**
 * @brief Get the instance of MainOffice
 * 
 * @return MainOffice& 
 */
MainOffice& MainOffice::getInstance()
{
    // Create the one and only main office
    static MainOffice instance;

    return instance;
}

/**
 * @brief Add new branch to the MainOffice
 * 
 * @param location - branch's location
 * @param capacity - branch's capacity
 */
void MainOffice::addBranch(const string& location, const int capacity)
{
    // Check if branch already in MainOffice
    if (branches.find(location) != branches.end())
        throw ExistingBranchError();
    
    // Add the new branch (use the copy c'tor of branch)
    branches.insert (branches.begin(), std::pair<string, Branch>(location, Branch(location, capacity)));
}

/**
 * @brief Delete branch from the MainOffice
 * 
 * @param location - branch's location
 */
void MainOffice::deleteBranch(const string& location)
{
    // Check if branch not in MainOffice
    if (branches.find(location) == branches.end())
        throw NonExistingBranchError();
    
    // remove the branch
    branches.erase (location);
}

/**
 * @brief print branches by location
 * 
 */
void MainOffice::printByLocation() const
{
    // Print header
    cout << "There are " << branches.size() << " KSP branches" << endl;

    // Print all the branches by location
    for (std::pair<string, Branch> branch : branches)
        branch.second.print_catalog_by_id();    // Doesn't specify the order to print
}

/**
 * @brief Get the Branches
 * 
 * @return map<string, Branch> - Map of the branches
 */
map<string, Branch>& MainOffice::getBranches()
{
    return branches;
}