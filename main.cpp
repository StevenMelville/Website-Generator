#include <iostream>
#include <string>
#include "website.h"
#include "color.h"
using namespace std;

int main(){
	string title;
	cout << "Enter a title for your website: ";
	getline(cin, title);
	cout << "How many articles do you want?" << endl;
	int num;
	cin >> num;
	Website site;
	site.setTitle(title);
	site.setNumArticles(num);
	site.generateWebsite();
}