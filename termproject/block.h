#ifndef BLOCK
#define BLOCK

class block {
protected:
    int centerX;//블럭생성 좌표
    int centerY;
    int color;//블럭 색
public:
    block(int centerX, int centerY, int color);//생성자
    int getX();
    int getY();
    void left();
    void right();
    void down();
    int getColor();
};

#endif