#include "block.h"

block::block(int color, int centerX, int centerY){
    this->centerX = centerX;
    this->centerY = centerY;
    this->color = color;
}

int block::getX(){
    return this->centerX;               
}

int block::getY(){
    return this->centerY;
}

int block::getColor(){
    return this->color;
}

void block::left(){
    this->centerX = centerX-1;
}

void block::right(){
    this->centerX = centerX+1;
}

void block::down(){
    this->centerY = centerY+1;
}