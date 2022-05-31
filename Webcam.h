#pragma once

#ifndef WEBCAM_H
#define WEBCAM_H

#include <string>
#include <iostream>
#include "PeripheralDevice.h"

using std::string;
using std::to_string;

class Webcam : public PeripheralDevice
{
	string resultion;
public:
	Webcam(string resultion);

	string getResultion();
	void setResulution(string resulution);
	

};
#endif /* WEBCAM_H */