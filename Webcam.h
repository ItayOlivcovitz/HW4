//Student1 Daniel Penkov, penkovdany@gmail.com, 207925504
//Student2 Itay Olivcovitz, Itay.olivcovitz@gmail.com, 207745639

#ifndef WEBCAM_H
#define WEBCAM_H

#include "PeripheralDevice.h"
#include "Computer.h"
#include <string>
#include <iostream>

using std::string;
using std::to_string;
using std::cout;
using std::endl;

class Webcam : public PeripheralDevice
{
private:
	string resultion;

public:

	/**
	 * @brief Construct a new Webcam object
	 * 
	 * @param price - webcam's price
	 * @param manufacturer - webcam's manufacturer
	 * @param color - webcam's color
	 * @param isWireless - true if webcam wireless
	 * @param resultion - webcam's resolution
	 */
	Webcam(const int price, const string& manufacturer, const string& color, const bool isWireless, const string& resultion);

	/**
	 * @brief Get the webcam resultion
	 * 
	 * @return string - resolution
	 */
	string getResultion() const;

	/**
	 * @brief Set the resulution of the webcam
	 * 
	 * @param resulution 
	 */
	void setResulution(const string& resulution);
	
	/**
	 * @brief Return string representing the webcam.
	 * 
	 * @return string 
	 */
	operator string() const override;

	/**
	 * @brief Print 'connecting to computer' message.
	 * 
	 * @param computer - to connect to
	 */
	void connect(Computer* computer) override;
};

#endif /* WEBCAM_H */