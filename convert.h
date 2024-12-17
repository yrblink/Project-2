//  ifeanyi ugwuoke
//  convert.h
#ifndef convert_h
#define convert_h
#include "convert.h"
#include <iostream>
#include <iostream>
#include <cmath>
using namespace std;

class Convert
{
private:
    struct sNode
    {
        int val;
        sNode *next;
    };
    sNode *head;
    struct qNode
    {
        int val;
        qNode *next;
    };
    qNode *front, *rear;
    
public:
    Convert();
    ~Convert();
    void push(int val);
    int pop();
    bool isStackEmpty() const;
    void enqueue(int val);
    int dequeue();
    bool isQueueEmpty() const;
    void convertIntPart(int intPart);
    void convertFracPart(double fracPart);
    void displayBinary();
};


#endif /* convert_h */
