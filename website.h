#ifndef WEBSITE
#define WEBSITE
#include <string>
#include "color.h"
using namespace std;
class Website{
	private:
		string title;
		Color bgColor, textColor, primary, secondary, thirdary;
	public:
		Website(string);
		void generateWebsite();
		int getColor();
		void createIcon();
};
#endif