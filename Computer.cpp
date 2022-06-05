//Student1 Daniel Penkov, penkovdany@gmail.com, 207925504
//Student2 Itay Olivcovitz, Itay.olivcovitz@gmail.com, 207745639

#include "Computer.h"

/**
 * @brief Construct a new Computer object.
 * 
 * @param price - computer's price
 * @param manufacturer - computer's brand
 * @param cpu - computer's cpu brand
 * @param isLaptop - is laptop / desktop
 * @param ports - number of USB ports
 */
Computer::Computer(const int price, const string& manufacturer, const string& cpu, const bool isLaptop, const int ports)
	: Item(price, manufacturer), cpu(cpu), isLaptop(isLaptop), ports(ports)
{}

/**
 * @brief Set computer's CPU.
 * 
 * @param cpu - cpu's brand
 */
void Computer::setCpu(const string& cpu)
{
	this->cpu = cpu;
}

/**
 * @brief Get computer's cpu
 * 
 * @return string - cpu's brand
 */
string Computer::getCpu() const
{
	return this->cpu;
}

/**
 * @brief Set if the computer is laptop ot not
 * 
 * @param isLaptop - True if laptop
 */
void Computer::setIsLaptop(const bool isLaptop)
{
	this->isLaptop = isLaptop;
}

/**
 * @brief Return true if the computer is laptop
 * 
 * @return true if laptop
 * @return false if desktop
 */
bool Computer::getIsLaptop() const
{
	return this->isLaptop;
}

/**
 * @brief Get number of USB ports
 * 
 * @return int - number of ports
 */
int Computer::getPorts() const
{
	return this->ports;
}

/**
 * @brief Prints connected devices to the computer
 * 
 */
void Computer::print_connected () const
{
	// Print header
	cout << "There are " << this->connectedDevices.size() << " connection to " << string(*this) << endl;

	// Print all connected devices
	for (PeripheralDevice* device : connectedDevices)
		cout << string(*device) << endl;
}

/**
 * @brief Return string representing the computer
 * 
 * @return string
 */
Computer::operator std::string() const
{
	string s_isLaptop;
	string s_cpu;

	s_isLaptop = (isLaptop) ? "Laptop" : "Desktop";
	s_cpu = this->getCpu();

	// Append to the original Item's string
	return Item::operator string() + ", " + s_isLaptop + ", " + s_cpu;
}

/**
 * @brief Get the Connected Devices.
 * 
 * @return list<PeripheralDevice*> - list of connected devices
 */
list<PeripheralDevice*>& Computer::getConnectedDevices ()
{
	return this->connectedDevices;
}

