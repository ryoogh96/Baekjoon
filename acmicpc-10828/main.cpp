#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

class Stack {

private:
    int top,maxSize;
    int *sstack;

public:
    Stack();
    bool isFull(), isEmpty();
    int pop();
    void push(int element);
    int Size();
    int numtop();
};

Stack::Stack() {
    maxSize = 10000;
    sstack = new int[maxSize];
    top = -1;
}

bool Stack::isFull() {
    if(top==maxSize-1) return true;
    else return false;
}

bool Stack::isEmpty() {
    if(top==-1) return true;
    else return false;
}

int Stack::pop() {
    if(isEmpty() == true) return -1;
    else return sstack[top--];
}

void Stack::push(int element){
    if(isFull() != true) sstack[++top] = element;
}

int Stack::Size() {
    return top + 1;
}

int Stack::numtop() {
    if(isEmpty() == true) return -1;
    else return sstack[top];
}



int main()
{
    Stack insStack;

    int instructionNum, tmp;
    string instruction;

    scanf("%d", &instructionNum);

    for(int i = 0; i < instructionNum; i++) {
        cin >> instruction;
        if(instruction == "push") { scanf("%d", &tmp); insStack.push(tmp); }
        else if(instruction == "pop") printf("%d\n", insStack.pop());
        else if(instruction == "top") printf("%d\n", insStack.numtop());
        else if(instruction == "size") printf("%d\n", insStack.Size());
        else if(instruction == "empty") printf("%d\n", insStack.isEmpty());
    }

    return 0;
}
