#ifndef FOLD
#define FOLD

#include "bigBlock.h"
#include "block.h"

class fold : public bigBlock {
protected:
    block* tleft;
    block* tright;
    block* left;
    block* right;
public:
    fold(int c1, int c2, int c3);
    ~fold();
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