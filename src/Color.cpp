#include "Color.h"

double Color::FMIN_INTENSITY = 0.0;
double Color::FMAX_INTENSITY = 1.0;
byte Color::BMIN_INTENSITY = 0;
byte Color::BMAX_INTENSITY = 255;


byte Color::mapDoubleColorVal (double value) {
	return value * BMAX_INTENSITY;
}

double Color::mapByteColorVal (byte value) {
	return (double)value / BMAX_INTENSITY;
}



Color::Color() {
	red = 1.0;
	green = 1.0;
	blue = 1.0;
}

Color::Color (double redVal, double greenVal, double blueVal) {
	setRedValue(redVal);
	setGreenValue(greenVal);
	setBlueValue(blueVal);
}

Color::Color (int redVal, int greenVal, int blueVal) {
	setRedValue(redVal);
	setGreenValue(greenVal);
	setBlueValue(blueVal);
}

Color::Color (const Color& color) {
	setRedValue(color.getDRed());
	setGreenValue(color.getDGreen());
	setBlueValue(color.getDBlue());
}



void Color::setColor (double redValue, double greenValue, double blueValue) {
	setRedValue(redValue);
	setGreenValue(greenValue);
	setBlueValue(blueValue);
}

void Color::getRGBDoubleArray (double array[3]) const {
	array[0] = red;
	array[1] = green;
	array[2] = blue;
}

void Color::getRGBIntArray (int array[3]) const {
	array[0] = mapDoubleColorVal(red);
	array[1] = mapDoubleColorVal(green);
	array[2] = mapDoubleColorVal(blue);
}



void Color::setRedValue (double value) {
	if (value < 0) value = 0.0;
	if (value > 1) value = 1.0;
	red = value;
}

void Color::setRedValue (int value) {
	if (value < 0) value = 0;
	if (value > 255) value = 255;
	red = mapByteColorVal(value);
}

double Color::getDRed() const {
	return red;
}

int Color::getIRed() const {
	return mapDoubleColorVal(red);
}



void Color::setGreenValue (double value) {
	if (value < 0) value = 0.0;
	if (value > 1) value = 1.0;
	green = value;
}

void Color::setGreenValue (int value) {
	if (value < 0) value = 0;
	if (value > 255) value = 255;
	green = mapByteColorVal(value);
}

double Color::getDGreen() const {
	return green;
}

int Color::getIGreen() const {
	return mapDoubleColorVal(green);
}



void Color::setBlueValue (double value) {
	if (value < 0) value = 0.0;
	if (value > 1) value = 1.0;
	blue = value;
}

void Color::setBlueValue (int value) {
	if (value < 0) value = 0;
	if (value > 255) value = 255;
	blue = mapByteColorVal(value);
}

double Color::getDBlue() const {
	return blue;
}

int Color::getIBlue() const {
	return mapDoubleColorVal(blue);
}



Color& Color::operator= (const Color& color) {
	setRedValue(color.getDRed());
	setGreenValue(color.getDGreen());
	setBlueValue(color.getDBlue());

	return *this;
}




