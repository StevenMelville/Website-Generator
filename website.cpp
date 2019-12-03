#include "website.h"
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;

Website::Website(string title = "website"){
	try{
		this->title = title;
		primary.setColor(getColor());
		secondary.setColor(getColor());
		thirdary = primary + secondary;
		bgColor = primary;
		textColor = thirdary;
		createIcon();
	}catch(exception e){
		
	}
}
void Website::generateWebsite(){
	ofstream myfile ("index.html");
	if (myfile.is_open())
	{
		myfile  << "<html><head><title>" + title + "</title></head><body style= 'background-color: " + bgColor.getColor()
				<<"; color: " + textColor.getColor() + "'>Hello, this is default text</body></html>";
		myfile.close();
	}
	else cout << "Unable to open file";
}

void printColors(){
	cout << RED << ". Red\n"	
		<< BLUE << ". Blue\n"
		<< GREEN << ". Green\n" 
		<< ORANGE << ". Orange\n"
		<< YELLOW << ". Yellow\n"
		<< WHITE << ". White\n"
		<< BLACK << ". Black\n" 
		<< PURPLE << ". Purple\n"
		<< GRAY << ". Gray\n" 
        << TEAL << ". Teal\n"
		<< LIME << ". Lime\n" 
		<< BROWN << ". Brown\n"
		<< TAN << ". Tan\n";
}

int Website::getColor(){
	cout <<  "Enter the number of the color you want." << endl;
	int color;
	printColors();
	cin >> color;
	if(color <= 13 && color >= 0) return color;
	else{
		cout << "That was not a valid choice." << endl;
		return getColor();
	}
}

void Website::createIcon(){
	string fileName = "iconTemplate.bmp";
	unsigned char header[54];
 	ifstream inf(fileName);
 	
 	if (!inf)
 	{cerr <<"unable to open file for reading!" << endl; exit(1);}

 	for(int i = 0; i < 54; i++) inf >> header[i];
	
	if(header[0] != 'B'){
		cout << "invalid file" << endl;
		exit(1);
	}
	if(header[1] != 'M'){
		cout << "invalid file" << endl;
		exit(1);
	}
	
	string outFileName = "icon.bmp";
	
	ofstream outf(outFileName);
 	
 	if (!outf)
 	{cerr <<"unable to open file for writing!" << endl; exit(1);}
 	
	for(int i = 0; i < 54; i++) outf << header[i];
	int alpha = *(int*)&header[28];
	int width = *(int*)&header[18];
    int height = *(int*)&header[22];
	
	unsigned int size = width * height;
	unsigned int padding = width % 3;
	unsigned char result;
	
	unsigned char data[3];
	unsigned char * color;
	unsigned char * prim = primary.getArray(), * sec = secondary.getArray(), * thir = thirdary.getArray();
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			
				inf >> data[0]; //Blue
				inf >> data[1]; //Green
				inf >> data[2]; //Red
				
				if(data[0] == 0){
					color = prim;
				}else if(data[0] == 255){
					color = sec;
				}else{
					color = thir;
				}
				
				data[0] = color[2];
				data[1] = color[1];
				data[2] = color[0];
				
				outf << data[0];
				outf << data[1];
				outf << data[2];
			
		}
	}
 	
	unsigned char temp;
	while(inf){
		inf >> temp;
		outf << temp;
	}
	
   	inf.close();
 	outf.close();	
}