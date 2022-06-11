//Student1 Daniel Penkov, penkovdany@gmail.com, 207925504
//Student2 Itay Olivcovitz, Itay.olivcovitz@gmail.com, 207745639

#include "Webcam.h"

/**
 * @brief Construct a new Webcam object
 * 
 * @param price - webcam's price
 * @param manufacturer - webcam's manufacturer
 * @param color - webcam's color
 * @param isWireless - true if webcam wireless
 * @param resultion - webcam's resolution
 */
Webcam::Webcam(const int price, const string& manufacturer, const string& color, const bool isWireless,const string& resultion)
	: PeripheralDevice(price, manufacturer, color, isWireless), resultion(resultion)
{}

/**
 * @brief Get the webcam resultion
 * 
 * @return string - resolution
 */
string Webcam::getResultion() const
{
	return this->resultion;
}

/**
 * @brief Set the resulution of the webcam
 * 
 * @param resulution 
 */
void Webcam::setResulution(const string& resultion)
{
	this->resultion = resultion;
}

/**
 * @brief Return string representing the webcam.
 * 
 * @return string 
 */
Webcam::operator string() const
{
	string s_res = "Webcam with " + resultion + " resolution";

	return PeripheralDevice::operator string() + ", " + s_res;
}

/**
 * @brief Print 'connecting to computer' message.
 * 
 * @param computer - to connect to
 */
void Webcam::connect(Computer* computer)
{
	cout << "Connecting a webcam" << endl;
	PeripheralDevice::connect (computer);
}