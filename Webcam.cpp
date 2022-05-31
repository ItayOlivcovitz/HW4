#include "Webcam.h"
#include <string>
#include <iostream>

/**
 * @brief Construct a new Webcam object.
 *
 * @param resultion - Item's resultion
 */
Webcam::Webcam(string resultion)
	: resultion(resultion)
{

}

string Webcam::getResultion()
{
	return this->resultion;
}

void Webcam::setResulution(string resultion)
{
	this->resultion = resultion;
}
