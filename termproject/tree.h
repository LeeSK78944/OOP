#ifndef TREE
#define TREE

#include "bigBlock.h"
#include "block.h"

class tree :public bigBlock {
protected:
    block* top;
    block* mid;
    block* bot;
    block* left;
    block* right;
public:
    tree(int c1, int c2, int c3);
    ~tree();
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