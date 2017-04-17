#ifndef COLOR_INCLUDED
#define COLOR_INCLUDED


class Color {
	public:
		typedef unsigned char sint; // small int that takes values from 0 to 255

		Color() = default;
		// values from 0 to 1
		Color(float red, float green, float blue);
		// values from 0 to 255
		Color(sint red,
					sint green,
					sint blue);

		// getters for each color
		float fGetRed();
		sint iGetRed();

		float fGetGreen();
		sint iGetGreen();

		float fGetBlue();
		sint iGetBlue();

		// setters for each color
		void fSetRed(float redValue);
		void iSetRed(sint redValue);

		void fSetGreen(float greenValue);
		void iSetGreen(sint greenValue);

		void fSetBlue(float blueValue);
		void iSetBlue(sint blueValue);

		// getters as array
		float* fvGetColor();
		sint* ivGetColor();

		// setters as array
		void fvSetColor(float color[3]);
		void ivSetColor(sint color[3]);

	private:
		static const int RED_INDEX = 0;
		static const int GREEN_INDEX = 1;
		static const int BLUE_INDEX = 2;
		
		float colorArray[3];

		// maps [0,1] to [0, 255]
		sint mapToInt(float v);
		// maps [0, 255] to [0, 1]
		float mapToFloat(sint v);
};

#endif
