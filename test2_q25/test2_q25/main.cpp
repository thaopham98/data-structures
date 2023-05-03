#include <iostream>
#include <stack>
#define MAX 10
using namespace std;

class myStack
{
    private:
        int array[MAX];
        int top;
    public:
        myStack(){top=0;}//constructor function

        void push(int newValue)
        {
            if(top < MAX)
            {
                array[top] = newValue;
                top++;
            }
            else
                cout << "Stack is Full!" << endl;
        }

        void pop()
        {
            if(top > 0)
                top--;
            else
                cout << "Stack is Empty!" << endl;
        }
        
        int peek()
        {
            if(top > 0)
                return array[top-1];
            else
                return -1;
        }
        
        void print()
        {
            for(int i=0; i<top; i++)
                cout << array[i] << " ";
            cout << endl;
        }
};

int main()
{
        
    myStack s1;

    s1.push(3);
    s1.push(5);
    s1.push(1);
    s1.print();
    
//    s1.push(10);
//    s1.push(15);
//    s1.print();
//
//    s1.pop();
//    s1.print();
//
//    s1.pop();
//    s1.pop();
//    s1.print();
//
//    s1.push(8);
//    s1.print();
//
//    int topElement = s1.peek();
//    cout << "Top Element: " << topElement << endl;
//
    s1.pop();
    s1.push(4);
    s1.push(10);
    s1.pop();
    s1.push(2);
    s1.print();

  return 0;
}
