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
	Webcam(const int price, const string& manufacturer, const string& color, const bool isWireless,const string& resultion);

	string getResultion() const;
	void setResulution(const string resulution);
	

};
#endif /* WEBCAM_H */