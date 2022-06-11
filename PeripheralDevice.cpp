//Student1 Daniel Penkov, penkovdany@gmail.com, 207925504
//Student2 Itay Olivcovitz, Itay.olivcovitz@gmail.com, 207745639

#include "PeripheralDevice.h"

/**
 * @brief Construct a new Peripheral Device.
 * 
 * @param price - device's price
 * @param manufacturer - device's brand
 * @param color - device's color
 * @param isWireless - is the device wireless
 */
PeripheralDevice::PeripheralDevice (const int price, const string& manufacturer, const string& color, const bool isWireless)
    : Item(price, manufacturer), color(color), isWireless(isWireless), connectedComputer(NULL)
{}

/**
 * @brief Get device's color.
 * 
 * @return string
 */
string PeripheralDevice::getColor () const
{
    return this->color;
}

/**
 * @brief Set device's color.
 * 
 * @param color - device's new color
 */
void PeripheralDevice::setColor (const string& color)
{
    this->color = color;
}

/**
 * @brief Check if the device wireless.
 * 
 * @return true - the device wireless
 * @return false - the device wired
 */
bool PeripheralDevice::getIsWireless () const
{
    return this->isWireless;
}

/**
 * @brief Set if the the device wireless.
 * 
 * @param isWireless - True to set the device wireless
 */
void PeripheralDevice::setIsWireless (const bool isWireless)
{
    this->isWireless = isWireless;
}

/**
 * @brief Return string representing this peripheral device.
 * 
 * @return string 
 */
PeripheralDevice::operator string() const
{
    string s_wire = isWireless ? "Wireless" : "Wired";
    
    return Item::operator string() + ", " + s_wire + ", " + color;
}

/**
 * @brief Connecting this device to computer.
 * 
 * @param computer - to be connected into
 */
void PeripheralDevice::connect (Computer* computer)
{
    // Already connected
    if (connectedComputer != NULL && connectedComputer == computer)
        return;

    // Connected to other computer
    if (connectedComputer != NULL && connectedComputer != computer)
        throw ConnectError();

    // Print 'connecting to' message
    cout << string(*this) << " is Connecting to computer: " << string(*computer) << endl;

    // Get computer connected list
    list<PeripheralDevice*>& connectedDevices = computer->getConnectedDevices();

    // Check if available ports
    if (connectedDevices.size() == computer->getPorts())
        throw ConnectError();
    
    // Check if device of same type connected
    for (PeripheralDevice* device : connectedDevices)
    {
        if (typeid(device) == typeid(this))
        {
            throw ConnectError();
        }
    }
    
    // Make the connection
    connectedDevices.push_back(this);
    connectedComputer = computer;
}

/**
 * @brief Disconnects from computer (if connected).
 * 
 */
void PeripheralDevice::disconnect ()
{
    // Check wheter was connected
    if (this->connectedComputer == NULL)
        return;
    
    // Get computer connected list and remove itself
    connectedComputer->getConnectedDevices().remove(this);
    
    // Clear connected computer
    connectedComputer = NULL;
}

/**
 * @brief Destroy the Peripheral Device object
 * 
 */
PeripheralDevice::~PeripheralDevice ()
{
    disconnect();
}
