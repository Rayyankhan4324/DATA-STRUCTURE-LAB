#include <iostream>
#include <string>     
using namespace std;

#define MAX 50

class Stack
{
private:
    int top;
    char arr[MAX];
public:
    Stack() 
    {
        top = -1;
    }

    bool isEmpty() 
    {
        return (top < 0);
    }

    bool isFull() 
    {
        return (top >= MAX - 1);
    }

    void push(char x) 
    {
        if (isFull()) 
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    void display() 
        {
            if (top < 0) 
            {
                cout << "Stack is empty" << endl;
                return;
            }
            for (int i = top; i >= 0; i--) 
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

    char pop() 
    {
        if (top < 0) 
        {
            cout << "Stack Underflow" << endl;
            return'\0';
        }
        return arr[top--];
    }

    bool areBracketsBalanced(string expression)
    {
        for (int i = 0;i < expression.length() ; i++)
        {
            char bracket = expression[i];

            if ( bracket == '{' || bracket == '[' || bracket == '(')
            {
                push(bracket);
            }
        
            else if ( bracket == '}' || bracket == ']' || bracket == ')')
            {
                if (isEmpty())
                {
                    cout<<"Brackets are not balanced...!"<<endl;
                    return false;
                }
                
                char open = pop();

                if ((bracket == '}' && open != '{') ||
                    (bracket == ']' && open != '[') ||
                    (bracket == ')' && open != '(')) 
                {
                    cout << "Mismatched brackets: " << open << " and " << bracket << endl;
                    return false;
                }

            }
        }

        if (!isEmpty()) 
        {
            cout << "Unclosed opening bracket(s) remaining!" << endl;
            return false;
        }
        return true;
    }

};


int main() 
{
    Stack obj;
    string expression = "){}";

    obj.areBracketsBalanced(expression);
    return 0;
}
