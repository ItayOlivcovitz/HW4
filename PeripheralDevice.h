//Student1 Daniel Penkov, penkovdany@gmail.com, 207925504
//Student2 Itay Olivcovitz, Itay.olivcovitz@gmail.com, 207745639

#ifndef PERIPHERALDEVICE_H
#define PERIPHERALDEVICE_H

#include "Item.h"
#include <iostream>
#include <string>
#include <list>
#include "HWExceptions.h"

#include "Computer.h"

class Computer;

using std::string;
using std::cout;
using std::endl;

class PeripheralDevice : public Item
{
private:
    string color;
    bool isWireless;

    Computer* connectedComputer;

public:

    /**
     * @brief Construct a new Peripheral Device.
     * 
     * @param price - device's price
     * @param manufacturer - device's brand
     * @param color - device's color
     * @param isWireless - is the device wireless
     */
    PeripheralDevice (const int price, const string& manufacturer, const string& color, const bool isWireless);

    /**
     * @brief Get device's color.
     * 
     * @return string
     */
    string getColor () const;

    /**
     * @brief Set device's color.
     * 
     * @param color - device's new color
     */
    void setColor (const string& color);

    /**
     * @brief Check if the device wireless.
     * 
     * @return true - the device wireless
     * @return false - the device wired
     */
    bool getIsWireless () const;

    /**
     * @brief Set if the the device wireless.
     * 
     * @param isWireless - True to set the device wireless
     */
    void setIsWireless (const bool isWireless);

    /**
     * @brief Return string representing this peripheral device.
     * 
     * @return string 
     */
    virtual operator string() const override = 0;

    /**
     * @brief Connecting this device to computer.
     * 
     * @param computer - to be connected into
     */
    virtual void connect (Computer* computer) = 0;

    /**
     * @brief Disconnects from computer (if connected).
     * 
     */
    void disconnect ();

    /**
     * @brief Destroy the Peripheral Device object
     * 
     */
    virtual ~PeripheralDevice ();
};

#endif /* PERIPHERALDEVICE_H */