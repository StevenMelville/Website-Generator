#ifndef COLOR
#define COLOR
#include <string>
using namespace std;

enum Colors {
	RED, BLUE, GREEN, ORANGE, YELLOW, WHITE, BLACK, PURPLE, GRAY, TEAL, LIME, BROWN, TAN
};

class Color{
	private:
		unsigned char R, G, B;
		unsigned char array[3];
	public:
		friend class Color;
		Color();
		void setColor(int);
		void setColor(unsigned char, unsigned char, unsigned char);
		string getColor();
		unsigned char * getArray();
		void operator=(const Color&);
		friend Color operator+(const Color &, const Color &);
};

#endif