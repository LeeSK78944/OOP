#ifndef BLOCK
#define BLOCK

class block {
protected:
    int centerX;//������ ��ǥ
    int centerY;
    int color;//�� ��
public:
    block(int centerX, int centerY, int color);//������
    int getX();
    int getY();
    void left();
    void right();
    void down();
    int getColor();
};

#endif