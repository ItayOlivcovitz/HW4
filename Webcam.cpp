#include "Webcam.h"
#include <string>
#include <iostream>

/**
 * @brief Construct a new Webcam object.
 *
 * @param resultion - Item's price, manufacturer, color, is Wireless,resultion
 */
Webcam::Webcam(const int price, const string& manufacturer, const string& color, const bool isWireless,const string& resultion)
	: PeripheralDevice(price, manufacturer, color, isWireless),resultion(resultion)
{

}
/**
 * @brief Get webcam Resultion.
 *
 * @return string
 */
string Webcam::getResultion() const
{
	return this->resultion;
}

/**
 * @brief set webcam Resultion.
 *
 * @return resultion
 */
void Webcam::setResulution(string resultion)
{
	this->resultion = resultion;
}
