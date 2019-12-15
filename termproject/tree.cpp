#include "tree.h"

extern int b[14][7];

tree::tree(int c1, int c2, int c3){
    state = 0;
    top = new block(c1, 3, 1);
    mid = new block(c2, 3, 2);
    bot = new block(c3, 3, 3);
    left = new block(0, 2, 2);
    right = new block(0, 4, 2);
    b[1][3] = c1;
    b[2][3] = c2;
    b[3][3] = c3;
}

tree::~tree(){
    delete(top);
    delete(mid);
    delete(bot);
}

bool tree::canLeft(){
    bool ret = 1;
    switch (state){
        case 0:
            if(b[top->getY()][top->getX()-1] != 0)
				ret = 0;
            if(b[mid->getY()][mid->getX()-1] != 0)
				ret = 0;
            if(b[bot->getY()][bot->getX()-1] != 0)
				ret = 0;
            break;
        case 1:
            if(b[left->getY()][left->getX()-1] != 0)
				ret = 0;
       /* default:
            break;*/
    }

    return ret;
}

bool tree::canRight(){
    bool ret = 1;
    switch (state){
        case 0:
            if(b[top->getY()][top->getX()+1] != 0)
				ret = 0;
            if(b[mid->getY()][mid->getX()+1] != 0)
				ret = 0;
            if(b[bot->getY()][bot->getX()+1] != 0)
				ret = 0;
            break;
        case 1:
            if(b[right->getY()][right->getX()+1] != 0)
				ret = 0;
        /*default:
            break;*/
    }

    return ret;
}

bool tree::canDown(){
    bool ret = 1;
    switch (state){
        case 0:
            if(b[bot->getY()+1][bot->getX()] != 0)
				ret = 0;
            break;
        case 1:
            if(b[left->getY()+1][left->getX()] != 0)
				ret = 0;
            if(b[mid->getY()+1][mid->getX()] != 0)
				ret = 0;
            if(b[right->getY()+1][right->getX()] != 0)
				ret = 0;
        /*default:
            break;*/
    }

    return ret;
}

void tree::Left(){
    if(canLeft()){
        switch (state){
            case 0:
                b[top->getY()][top->getX()-1] = b[top->getY()][top->getX()];
                b[top->getY()][top->getX()] = 0;
                b[mid->getY()][mid->getX()-1] = b[mid->getY()][mid->getX()];
                b[mid->getY()][mid->getX()] = 0;
                b[bot->getY()][bot->getX()-1] = b[bot->getY()][bot->getX()];
                b[bot->getY()][bot->getX()] = 0;
                break;
            case 1:
                b[left->getY()][left->getX()-1] = b[left->getY()][left->getX()];
                b[left->getY()][left->getX()] = 0;
                b[mid->getY()][mid->getX()-1] = b[mid->getY()][mid->getX()];
                b[mid->getY()][mid->getX()] = 0;
                b[right->getY()][right->getX()-1] = b[right->getY()][right->getX()];
                b[right->getY()][right->getX()] = 0;
                break;
            /*default:
                break;*/
        }
        top->left();
        bot->left();
        mid->left();
        left->left();
        right->left();
    }
}

void tree::Right(){
    if(canRight()){
        switch (state){
            case 0:
                b[top->getY()][top->getX()+1] = b[top->getY()][top->getX()];
                b[top->getY()][top->getX()] = 0;
                b[mid->getY()][mid->getX()+1] = b[mid->getY()][mid->getX()];
                b[mid->getY()][mid->getX()] = 0;
                b[bot->getY()][bot->getX()+1] = b[bot->getY()][bot->getX()];
                b[bot->getY()][bot->getX()] = 0;
                break;
            case 1:
                b[right->getY()][right->getX()+1] = b[right->getY()][right->getX()];
                b[right->getY()][right->getX()] = 0;
                b[mid->getY()][mid->getX()+1] = b[mid->getY()][mid->getX()];
                b[mid->getY()][mid->getX()] = 0;
                b[left->getY()][left->getX()+1] = b[left->getY()][left->getX()];
                b[left->getY()][left->getX()] = 0;
                break;
            /*default:
                break;*/
        }
        
        top->right();
        bot->right();
        mid->right();
        left->right();
        right->right();
    }
}

int tree::Down(){
    if(canDown()){
        for(int i=11; i>0; i--)
            for(int j=1; j<6; j++)
                if(b[i+1][j] == 0){
                    b[i+1][j] = b[i][j];
                    b[i][j] = 0;
                }

        top->down();
        mid->down();
        bot->down();
        left->down();
        right->down();
    }

    if(!canDown())
        return DownAll();

    return 0;
}

int tree::DownAll(){
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

void tree::rightRotate() {
	if (state == 0)
		if (b[left->getY()][left->getX()] != 0 || b[right->getY()][right->getX()] != 0)
			return;
	block* t_top = new block(left->getColor(), top->getX(), top->getY());
	block* t_bot = new block(right->getColor(), bot->getX(), bot->getY());
	block* t_left = new block(bot->getColor(), left->getX(), left->getY());
	block* t_right = new block(top->getColor(), right->getX(), right->getY());

	b[t_top->getY()][t_top->getX()] = t_top->getColor();
	b[t_bot->getY()][t_bot->getX()] = t_bot->getColor();
	b[t_left->getY()][t_left->getX()] = t_left->getColor();
	b[t_right->getY()][t_right->getX()] = t_right->getColor();

	delete(top);
	delete(bot);
	delete(left);
	delete(right);

	top = t_top;
	bot = t_bot;
	left = t_left;
	right = t_right;

	state = (state + 1) % 2;
}