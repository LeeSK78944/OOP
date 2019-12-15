#include "cross.h"

extern int b[14][7];

cross::cross(int c1, int c2, int c3, int c4, int c5){
    up = new block(c1, 3, 1);
    down = new block(c2, 3, 3);
    left = new block(c3, 2, 2);
    right = new block(c4, 4, 2);
    mid = new block(c5, 3, 2);
    b[1][3] = c1;
    b[3][3] = c2;
    b[2][2] = c3;
    b[2][4] = c4;
    b[2][3] = c5;
}

cross::~cross(){
    delete(mid);
    delete(up);
    delete(down);
    delete(left);
    delete(right);
}

bool cross::canLeft(){
    bool ret = 1;

    if(b[up->getY()][up->getX()-1] != 0)
		ret = 0;
    if(b[down->getY()][down->getX()-1] != 0)
		ret = 0;
    if(b[left->getY()][left->getX()-1] != 0)
		ret = 0;

    return ret;
}

bool cross::canRight(){
    bool ret = 1;

    if(b[up->getY()][up->getX()+1] != 0)
		ret = 0;
    if(b[right->getY()][right->getX()+1] != 0) 
		ret = 0;
    if(b[down->getY()][down->getX()+1] != 0)
		ret = 0;

    return ret;
}

bool cross::canDown(){
    bool ret = 1;

    if(b[down->getY()+1][down->getX()] != 0)
		ret = 0;
    if(b[left->getY()+1][left->getX()] != 0)
		ret = 0;
    if(b[right->getY()+1][right->getX()] != 0)
		ret = 0;

    return ret;
}

void cross::Left(){
    if(canLeft()){
        b[up->getY()][up->getX()-1] = b[up->getY()][up->getX()];
        b[up->getY()][up->getX()] = 0;
        b[down->getY()][down->getX()-1] = b[down->getY()][down->getX()];
        b[down->getY()][down->getX()] = 0;
        b[left->getY()][left->getX()-1] = b[left->getY()][left->getX()];
        b[left->getY()][left->getX()] = 0;
        b[mid->getY()][mid->getX()-1] = b[mid->getY()][mid->getX()];
        b[mid->getY()][mid->getX()] = 0;
        b[right->getY()][right->getX()-1] = b[right->getY()][right->getX()];
        b[right->getY()][right->getX()] = 0;
        
        up->left();
        down->left();
        mid->left();
        left->left();
        right->left();
    }
}

void cross::Right(){
    if(canRight()){
        b[up->getY()][up->getX()+1] = b[up->getY()][up->getX()];
        b[up->getY()][up->getX()] = 0;
        b[down->getY()][down->getX()+1] = b[down->getY()][down->getX()];
        b[down->getY()][down->getX()] = 0;
        b[right->getY()][right->getX()+1] = b[right->getY()][right->getX()];
        b[right->getY()][right->getX()] = 0;
        b[mid->getY()][mid->getX()+1] = b[mid->getY()][mid->getX()];
        b[mid->getY()][mid->getX()] = 0;
        b[left->getY()][left->getX()+1] = b[left->getY()][left->getX()];
        b[left->getY()][left->getX()] = 0;
        
        up->right();
        down->right();
        mid->right();
        left->right();
        right->right();
    }
}

int cross::Down(){
    if(canDown()){
        for(int i=11; i>0; i--)
            for(int j=1; j<6; j++)
                if(b[i+1][j] == 0){
                    b[i+1][j] = b[i][j];
                    b[i][j] = 0;
                }
        up->down();
        down->down();
        mid->down();
        left->down();
        right->down();
    }

    if(!canDown())
        return DownAll();
    return 0;
}

int cross::DownAll(){
    for(int n=0; n<11; n++)
        for(int i=11; i>0; i--)
            for(int j=1; j<6; j++)
                if(b[i+1][j] == 0){
                    b[i+1][j] = b[i][j];
                    b[i][j] = 0;
                }

    delete(this);
    return 1;
}

void cross::rightRotate(){
	block* t_up = new block(left->getColor(), up->getX(), up->getY());
	block* t_down = new block(right->getColor(), down->getX(), down->getY());
	block* t_left = new block(down->getColor(), left->getX(), left->getY());
	block* t_right = new block(up->getColor(), right->getX(), right->getY());

	b[t_up->getY()][t_up->getX()] = t_up->getColor();
	b[t_down->getY()][t_down->getX()] = t_down->getColor();
	b[t_left->getY()][t_left->getX()] = t_left->getColor();
	b[t_right->getY()][t_right->getX()] = t_right->getColor();

	delete(up);
	delete(down);
	delete(left);
	delete(right);

	up = t_up;
	down = t_down;
	left = t_left;
	right = t_right;
}