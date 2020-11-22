#include <iostream>
using namespace std;

struct node
{
    char data;
    node *next = nullptr;
};
class stack
{
    public:
    node*top = nullptr;
    void push(char x);
    bool isEmpty();
    char pop();
    bool isBalanced(char * exp);
};
bool stack::isEmpty()
{
    if (top == nullptr)
        {return true;}
    return false;
}
void stack::push(char x)
{
    node * temp = new node;
    temp->data = x;
    if ( isEmpty() )
    {
        top = temp;
        temp -> next = nullptr;
    }
    else 
    {
        temp->next = top;
        top = temp;
    }
}
char stack::pop()
{
    node* t = new node;
    char x = '1';
    if (!isEmpty())
        {
            t = top;
            top = top->next;
            x = t->data;
            delete top;
        }
    else 
    {
        cout << "Stack underflow\n";
    }
    return x;
}

bool stack::isBalanced(char *exp)
{
    char x;
    for (int i =0; exp[i] != '\0';i++)
    {
        if(exp[i] == '(' or exp[i] == '{' or exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' or exp[i] == '}' or exp[i] == ']')
        {
            if (isEmpty())
                {
                return false;}

            else
                {
                x = pop();
                if ( 
                    (exp[i] == ')' && x == '(' )
                    ||
                    (exp[i] == '}' && x == '{')
                    ||
                    (exp[i] == ']' && x == '[')
                    )
                    {
                        continue;
                    }
                else
                {   cout << "X is, " << x <<" i is: " << exp[i];
                    return false;}
                }
        }
    }
    if (isEmpty())
        {return true;}

    return false;
}

int main()
{
    stack st;
    char exp[] = "{(a+b)*(c-d)}"; 
    
    if (st.isBalanced(exp))
    {
        cout << "Its balanced";
    }
    else 
    { cout << "Its not balanced"; }
    return 0;
}