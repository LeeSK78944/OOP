#ifndef CROSS
#define CROSS

#include "bigBlock.h"
#include "block.h"

class cross : public bigBlock {
protected:
    block* mid;
    block* up;
    block* down;
    block* left;
    block* right;
public:
    cross(int c1, int c2, int c3, int c4, int c5);
    ~cross();
    bool canLeft();
    bool canRight();
    bool canDown();
    void Left();
    void Right();
    int Down();
    int DownAll();
    void rightRotate();
};

#endif