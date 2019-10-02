#include "website.h"
#include <iostream>
#include <fstream>
using namespace std;

void generateWebsite(string title){
	ofstream myfile ("index.html");
	if (myfile.is_open())
	{
		myfile << "<html><head><title>" + title + "</title></head></html>";
		myfile.close();
	}
	else cout << "Unable to open file";
}