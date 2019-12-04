#include "color.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdio.h>
using namespace std;


Color::Color(){
	//Do nothing
}

void Color::setColor(int color){
	switch(color){
		case RED: this->R = 255;
					this->G = 0;
					this->B = 0;
					break;
		case BLUE: this->R = 0;
					this->G = 0;
					this->B = 255;
					break;
		case GREEN: this->R = 0;
					this->G = 128;
					this->B = 0;
					break;
		case ORANGE: this->R = 255;
					this->G = 165;
					this->B = 0;
					break;
		case YELLOW: this->R = 255;
					this->G = 255;
					this->B = 0;
					break;
		case WHITE: this->R = 255;
					this->G = 255;
					this->B = 255;
					break;
		case BLACK: this->R = 0;
					this->G = 0;
					this->B = 0;
					break;
		case TEAL: this->R = 0;
					this->G = 128;
					this->B = 128;
					break;
		case TAN: this->R = 210;
					this->G = 180;
					this->B = 140;
					break;
		case GRAY: this->R = 128;
					this->G = 128;
					this->B = 128;
					break;
		case PURPLE: this->R = 128;
					this->G = 0;
					this->B = 128;
					break;
		case BROWN: this->R = 166;
					this->G = 74;
					this->B = 43;
					break;
		case LIME: this->R = 0;
					this->G =255;
					this->B = 0;
					break;
		default: this->R = 255;
				this->G = 255;
				this->B = 255;
				break;
	}
	
	
	array[0] = this->R;
	array[1] = this->G;
	array[2] = this->B;
}

void Color::setColor(unsigned char R, unsigned char G, unsigned char B){
	this->R = R;
	this->G = G;
	this->B = B;
	
	array[0] = R;
	array[1] = G;
	array[2] = B;
}


constexpr char hexmap[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                           '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

string Color::getColor(){
	string s(6, ' ');
	s[0] = hexmap[(R & 0xF0) >> 4];
	s[1] = hexmap[R & 0x0F];
	s[2] = hexmap[(G & 0xF0) >> 4];
	s[3] = hexmap[G & 0x0F];
	s[4] = hexmap[(B & 0xF0) >> 4];
	s[5] = hexmap[B & 0x0F];
	string color = '#' + s;
	return color;
}

unsigned char * Color::getArray(){
	return array;
}

void Color::operator=(const Color & color){
	this->R = color.R;
	this->G = color.G;
	this->B = color.B;
	
	array[0] = R;
	array[1] = G;
	array[2] = B;
}

Color operator+(const Color & color1 , const Color & color2){
	int R, G, B;
	Color color;
	R = (color1.R + color2.R) / 2;
	G = (color1.G + color2.G) / 2;
	B = (color1.B + color2.B) / 2;
	color.R = R; 
	color.G = G;
	color.B = B;
	return color;
}