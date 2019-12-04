#ifndef WEBSITE
#define WEBSITE
#include <string>
#include "color.h"
using namespace std;
class Website{
	private:
		string title;
		Color bgColor, textColor, primary, secondary, thirdary;
		int numArticles;
	public:
		Website();
		void generateWebsite();
		int getColor();
		void createIcon();
		void setTitle(string);
		void setNumArticles(int);
};
#endif