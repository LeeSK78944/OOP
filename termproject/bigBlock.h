#ifndef BIGBLOCK
#define BIGBLOCK

class bigBlock {
protected:
    int state;
public:
    virtual bool canLeft() = 0;
    virtual bool canRight() = 0;
    virtual bool canDown() = 0;
    virtual void Left() = 0;
    virtual void Right() = 0;
    virtual int Down() = 0;
    virtual int DownAll() = 0;
	virtual void rightRotate() = 0;
};

#endif