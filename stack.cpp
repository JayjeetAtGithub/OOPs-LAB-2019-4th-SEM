#include <bits/stdc++.h>
#define int long long
using namespace std;

class Stack
{
    int top;
    int size;
    int *mem;

  public:
    Stack(int size)
    {
        this->size = size;
        this->top = 0;
        this->mem = new int[size];
    }

    void push(int data)
    {
        if (top < size - 1)
        {
            mem[++top] = data;
        }
        else
        {
            cout << "Overflow\n";
        }
    }

    void pop()
    {
        if (top > 0)
        {
            top--;
        }
        else
        {
            cout << "Underflow\n";
        }
    }
};

int32_t main(int32_t argc, char const *argv[])
{

    Stack *s = new Stack(10);
    s->push(10);
    s->push(20);
    s->push(12);
    s->pop();
    s->pop();
    s->pop();
    s->pop();
    return 0;
}
