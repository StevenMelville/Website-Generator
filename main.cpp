#include <iostream>
#include <string>
#include "website.h"
#include "color.h"
using namespace std;

int main(){
	string title;
	cout << "Enter a title for your website: ";
	cin >> title;
	Website site(title);
	site.generateWebsite();
}