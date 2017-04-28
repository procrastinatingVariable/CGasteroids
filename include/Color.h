#ifndef COLOR_INCLUDED
#define COLOR_INCLUDED

typedef unsigned char byte;

class Color {
	private:
		double red;
		double green;
		double blue;

		static double FMAX_INTENSITY;
		static double FMIN_INTENSITY;
		static byte BMAX_INTENSITY;
		static byte BMIN_INTENSITY;


	public:
		static byte mapDoubleColorVal(double value);
		static double mapByteColorVal(byte value);
		Color();
		// values from 0 to 1
		Color(double redVal,
					double greenVal,
					double blueVal);
		// values from 0 to 255
		Color(int redVal,
					int greenVal,
					int blueVal);
		Color(const Color& color);
		
		void setColor (double redValue, double greenValue, double blueValue);
		void getRGBDoubleArray (double array[3]) const;
		void getRGBIntArray (int array[3]) const;

		void setRedValue(double value);
		void setRedValue(int value);
		double getDRed() const;
		int getIRed() const;

		void setGreenValue(double value);
		void setGreenValue(int value);
		double getDGreen() const;
		int getIGreen() const;

		void setBlueValue(double value);
		void setBlueValue(int value);
		double getDBlue() const;
		int getIBlue() const;

		Color& operator=(const Color& color);


	
};

#endif
