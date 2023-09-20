#include<iostream>
using namespace std;
class Stack
{
    private:
    int size;
    int index;
    int *ptr;
    public:
    Stack(): size(5), index(-1)
    {
        this->ptr = new int[5];
    }
    Stack(int size): size(size), index(-1)
    {
        this->ptr = new int[size];
    }
    //copy constructor added
    Stack(Stack &obj)
    {
        this->size = obj.size;
        this->index = obj.index;
        this->ptr = new int[this->size];
    }
    //assignment operator overloaded
    void operator=(Stack &obj)
    {
        this->size = obj.size;
        this->index = obj.index;
    //no need to allocate memory in assignment operator, since it is allocated by the constructor when the object is instantiated
    }
    void push()
    {
        if(this->isFull())
        {
            cout << "--------------------------" << endl;
            cout << "Stack if full!" << endl;
            cout << "--------------------------" << endl;
        }
        else
        {
            this->index++;
            cout << "--------------------------" << endl;
            cout << "Please enter integer data: ";
            cin >> this->ptr[this->index];
            cout << "--------------------------" << endl;
        }         
    }
    void pop()
    {
        if(this->isEmpty())
        {
            cout << "--------------------------" << endl;
            cout << "Stack is empty!" << endl;
            cout << "--------------------------" << endl;
        }
        else
        {
            cout << "--------------------------" << endl;
            cout << "Poped data: " << this->ptr[this->index] << endl;
            cout << "--------------------------" << endl;
            index--;
        }
    }
    bool isFull()
    {
        if(this->index < this->size - 1)
        return false;
        else
        return true;
    }
    bool isEmpty()
    {
        if(this->index == -1)
        return true;
        else
        return false;
    }
    void peek()
    {
        if(this->isEmpty())
        {
            cout << "--------------------------" << endl;
            cout << "Stack is empty!" << endl;
            cout << "--------------------------" << endl;
        }
        else
        {
            cout << "--------------------------" << endl;
            cout << "Latest pushed data: " << this->ptr[this->index] << endl;
            cout << "--------------------------" << endl;
        }     
    }
    void print()
    {
        if(this->isEmpty())
        {
            cout << "--------------------------" << endl;
            cout << "Stack is empty!" << endl;
            cout << "--------------------------" << endl;
        }
        else
        {
            int temp = this->index;
            cout << "--------------------------" << endl;
            cout << "Current stack elements: " << endl;
            while(temp >= 0)
            {
                cout << this->ptr[temp] << endl;
                temp--;
            }
            cout << "--------------------------" << endl;
        } 
    }
    ~Stack()
    {
        delete this->ptr;
    }
};
int menu()
{
    int choice;
    cout << "Please select your choice: " << endl;
    cout << "0. Exit\n1. Push\n2. Pop\n3. Peek\n4. Print stack" << endl;
    cin >> choice;
    return choice;
}
int main()
{
    Stack s1(6);
    Stack s = s1; //copy constrcutor will be used
    Stack s2;
    s2 = s1; //assignment(overloaded) will be used
    int choice;
    while((choice = menu()) != 0)
    {
        switch(choice)
        {
            case 1:
            s.push();
            break;
            case 2:
            s.pop();
            break;
            case 3:
            s.peek();
            break;
            case 4:
            s.print();
            break;
            default:
            cout << "--------------------------" << endl;
            cout << "Invalid choice!" << endl;
            cout << "--------------------------" << endl;
        }
    }
    return 0;
}