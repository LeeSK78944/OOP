#include "fold.h"

extern int b[14][7];

fold::fold(int c1, int c2, int c3){
    state = 0;
    tright = new block(c1, 3, 1);
    tleft = new block(0, 2, 1);
    right = new block(c2, 3, 2);
    left = new block(c3, 2, 2);
    b[1][3] = c1;
    b[2][3] = c2;
    b[2][2] = c3;
}

fold::~fold(){
    delete(tleft);
    delete(tright);
    delete(left);
    delete(right);
}

bool fold::canLeft(){
    bool ret = 1;
    switch (state){
        case 0:
            if(b[tright->getY()][tright->getX()-1] != 0)
				ret = 0;
            if(b[left->getY()][left->getX()-1] != 0)
				ret = 0;
            break;
        case 1:
        case 2:
            if(b[left->getY()][left->getX()-1] != 0)
				ret = 0;
            if(b[tleft->getY()][tleft->getX()-1] != 0)
				ret = 0;
            break;
        case 3:
            if(b[tleft->getY()][tleft->getX()-1] != 0)
				ret = 0;
            if(b[right->getY()][right->getX()-1] != 0)
				ret = 0;
        /*default:
            break;*/
    }

    return ret;
}

bool fold::canRight(){
    bool ret = 1;
    switch (state){
        case 0:
            if(b[tright->getY()][tright->getX()+1] != 0)
				ret = 0;
            if(b[right->getY()][right->getX()+1] != 0)
				ret = 0;
            break;
        case 1://ㄴ
            if(b[right->getY()][right->getX()+1] != 0)
				ret = 0;
            if(b[tleft->getY()][tleft->getX()+1] != 0)
				ret = 0;
            break;
        case 2:
            if(b[tright->getY()][tright->getX()+1] != 0)
				ret = 0;
            if(b[left->getY()][left->getX()+1] != 0)
				ret = 0;
            break;
        case 3: //ㄱ
            if(b[right->getY()][right->getX()+1] != 0)
				ret = 0;
            if(b[tright->getY()][tright->getX()+1] != 0)
				ret = 0;
            /*break;
        default:
            break;*/
    }

    return ret;
}

bool fold::canDown(){
    bool ret = 1;
    switch (state){
        case 0:
        case 1:
            if(b[right->getY()+1][right->getX()] != 0)
				ret = 0;
            if(b[left->getY()+1][left->getX()] != 0)
				ret = 0;
            break;
        case 2:
            if(b[left->getY()+1][left->getX()] != 0)
				ret = 0;
            if(b[tright->getY()+1][tright->getX()] != 0)
				ret = 0;
            break;
        case 3:
            if(b[tleft->getY()+1][tleft->getX()] != 0)
				ret = 0;
            if(b[right->getY()+1][right->getX()] != 0)
				ret = 0;
            /*break;
        default:
            break;*/
    }

    return ret;
}
void fold::Left(){
    if(canLeft()){
        switch (state){
            case 0:
                b[tright->getY()][tright->getX()-1] = b[tright->getY()][tright->getX()];
                b[tright->getY()][tright->getX()] = 0;
                b[left->getY()][left->getX()-1] = b[left->getY()][left->getX()];
                b[left->getY()][left->getX()] = 0;
                b[right->getY()][right->getX()-1] = b[right->getY()][right->getX()];
                b[right->getY()][right->getX()] = 0;
                break;
            case 1:
                b[tleft->getY()][tleft->getX()-1] = b[tleft->getY()][tleft->getX()];
                b[tleft->getY()][tleft->getX()] = 0;
                b[left->getY()][left->getX()-1] = b[left->getY()][left->getX()];
                b[left->getY()][left->getX()] = 0;
                b[right->getY()][right->getX()-1] = b[right->getY()][right->getX()];
                b[right->getY()][right->getX()] = 0;
                break;
            case 2:
                b[tleft->getY()][tleft->getX()-1] = b[tleft->getY()][tleft->getX()];
                b[tleft->getY()][tleft->getX()] = 0;
                b[left->getY()][left->getX()-1] = b[left->getY()][left->getX()];
                b[left->getY()][left->getX()] = 0;
                b[tright->getY()][tright->getX()-1] = b[tright->getY()][tright->getX()];
                b[tright->getY()][tright->getX()] = 0;
                break;
            case 3:
                b[tleft->getY()][tleft->getX()-1] = b[tleft->getY()][tleft->getY()];
                b[tleft->getY()][tleft->getX()] = 0;
                b[tright->getY()][tright->getX()-1] = b[tright->getY()][tright->getX()];
                b[tright->getY()][tright->getX()] = 0;
                b[right->getY()][right->getX()-1] = b[right->getY()][right->getX()];
                b[right->getY()][right->getX()] = 0;
                /*break;
            default:
                break;*/
        }
        tleft->left();
        tright->left();
        left->left();
        right->left();
    }
}
void fold::Right(){
    if(canRight()){
        switch (state){
            case 0:
                b[tright->getY()][tright->getX()+1] = b[tright->getY()][tright->getX()];
                b[tright->getY()][tright->getX()] = 0;
                b[right->getY()][right->getX()+1] = b[right->getY()][right->getX()];
                b[right->getY()][right->getX()] = 0;
                b[left->getY()][left->getX()+1] = b[left->getY()][left->getX()];
                b[left->getY()][left->getX()] = 0;
                break;
            case 1:
                b[tleft->getY()][tleft->getX()+1] = b[tleft->getY()][tleft->getY()];
                b[tleft->getY()][tleft->getX()] = 0;
                b[right->getY()][right->getX()+1] = b[right->getY()][right->getX()];
                b[right->getY()][right->getX()] = 0;
                b[left->getY()][left->getX()+1] = b[left->getY()][left->getX()];
                b[left->getY()][left->getX()] = 0;
                break;
            case 2:
                b[tright->getY()][tright->getX()+1] = b[tright->getY()][right->getX()];
                b[tright->getY()][tright->getX()] = 0;
                b[tleft->getY()][tleft->getX()+1] = b[tleft->getY()][tleft->getX()];
                b[tleft->getY()][tleft->getX()] = 0;
                b[left->getY()][left->getX()+1] = b[left->getY()][left->getX()];
                b[left->getY()][left->getX()] = 0;
                break;
            case 3:
                b[tright->getY()][tright->getX()+1] = b[tright->getY()][tright->getX()];
                b[tright->getY()][tright->getX()] = 0;
                b[tleft->getY()][tleft->getX()+1] = b[tleft->getY()][tleft->getX()];
                b[tleft->getY()][tleft->getX()] = 0;
                b[right->getY()][right->getX()+1] = b[right->getY()][right->getX()];
                b[right->getY()][right->getX()] = 0;
                /*break;
            default:
                break;*/
        }
        tleft->right();
        tright->right();
        left->right();
        right->right();
    }
}

int fold::Down(){
    if(canDown()){
        for(int i=11; i>0; i--)
            for(int j=1; j<6; j++)
                if(b[i+1][j] == 0){
                    b[i+1][j] = b[i][j];
                    b[i][j] = 0;
                }

        tleft->down();
        tright->down();
        left->down();
        right->down();
    }
    if(!canDown())
        return DownAll();

    return 0;
}

int fold::DownAll(){
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

void fold::rightRotate() {

	block* t_tleft = new block(left->getColor(), tleft->getX(), tleft->getY());
	block* t_tright = new block(tleft->getColor(), tright->getX(), tright->getY());
	block* t_left = new block(right->getColor(), left->getX(), left->getY());
	block* t_right = new block(tright->getColor(), right->getX(), right->getY());

	b[t_tright->getY()][t_tright->getX()] = t_tright->getColor();
	b[t_tleft->getY()][t_tleft->getX()] = t_tleft->getColor();
	b[t_left->getY()][t_left->getX()] = t_left->getColor();
	b[t_right->getY()][t_right->getX()] = t_right->getColor();

	delete(tright);
	delete(tleft);
	delete(left);
	delete(right);

	tright = t_tright;
	tleft = t_tleft;
	left = t_left;
	right = t_right;

	state = (state + 1) % 4;
}