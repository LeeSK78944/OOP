#ifndef BOARD
#define BOARD

#include <map>
#include <vector>
#include "fold.h"
#include "cross.h"
#include "tree.h"

class board {
protected:
    fold* f;
    cross* c;
    tree* t;
    int type;
    int cur;
    int score;
    std::map<std::string, std::vector<std::string>* > blocks;
public:
    board();
    void printBoard();
    bool canExplode(int color);
    void deleteBlock(int color, std::vector<std::string> visit);
    void explode();
    void defeat();
    void create();
    int move(char d);
    bool fall();
    int getScore();
    void merge();
};

#endif