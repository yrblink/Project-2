//  ifeanyi ugwuoke
//  convert.cpp
//  Project 2
#include "convert.h"
#include <stdio.h>
#include <iostream>
using namespace std;
#include "convert.h"


Convert::Convert() : head(nullptr), front(nullptr), rear(nullptr) {}


Convert::~Convert()
{
    while (!isStackEmpty())
        pop();
    while (!isQueueEmpty())
        dequeue();
}


void Convert::push(int val)
{
    sNode *newNode = new sNode{val, head};
    head = newNode;
}

int Convert::pop()
{
    if (isStackEmpty())
        throw runtime_error("Stack is empty");

    int val = head->val;
    sNode *temp = head;
    head = head->next;
    delete temp;
    return val;
}

bool Convert::isStackEmpty() const
{
    return head == nullptr;
}


void Convert::enqueue(int val)
{
    qNode *newNode = new qNode{val, nullptr};
    if (isQueueEmpty())
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
int Convert::dequeue()
{
    if (isQueueEmpty())
        throw runtime_error("Queue is empty");

    int val = front->val;
    qNode *temp = front;
    front = front->next;
    if (!front)
        rear = nullptr;
    delete temp;
    return val;
}

bool Convert::isQueueEmpty() const
{
    return front == nullptr;
}


void Convert::convertIntPart(int intPart)
{
    while (intPart > 0)
    {
        push(intPart % 2);
        intPart /= 2;
    }
}
void Convert::convertFracPart(double fracPart)
{
    const int maxPrec = 10;
    int count = 0;

    while (fracPart > 0 && count < maxPrec)
    {
        fracPart *= 2;
        int bit = static_cast<int>(fracPart);
        enqueue(bit);
        fracPart -= bit;
        count++;
    }
}

void Convert::displayBinary()
{
    cout << "Binary: ";
    while (!isStackEmpty())
        cout << pop();
    if (!isQueueEmpty())
    {
        cout << ".";
        while (!isQueueEmpty())
            cout << dequeue();
    }
    cout << endl;
}
