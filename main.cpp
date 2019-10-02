#include <iostream>
#include <string>
#include "website.h"
using namespace std;

int main(){
	string title;
	cout << "Enter a title for your website: ";
	cin >> title;
	generateWebsite(title);
}