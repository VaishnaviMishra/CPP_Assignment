#include<iostream>
using namespace std;
class matrix
{
    private:
    int r1;
    int c1;
    int r2;
    int c2;
    int **ptr1;
    int **ptr2;
    int **ptr3;
    public:
    matrix()
    {
        cout << "Please enter rows and columns for the first matrix: ";
        cin >> this->r1 >> this->c1;
        cout << "Please enter rows and columns for the second matrix: ";
        cin >> this->r2 >> this->c2;
        this->ptr1 = new int* [r1];
        this->ptr2 = new int* [r2];
        this->ptr3 = new int* [r1];
        for(int i = 0; i < r1; i++)
        {
            this->ptr1[i] = new int [c1];
        } 
        for(int i = 0; i < r2; i++)
        {
            this->ptr2[i] = new int [c2];
        }
        for(int i = 0; i < c2; i++)
        {
            this->ptr3[i] = new int [c2];
        } 
    }
    //copy constructor added
    matrix(matrix &obj)
    {
        this->r1 = obj.r1;
        this->c1 = obj.c1;
        this->r2 = obj.r2;
        this->c2 = obj.c2;
        this->ptr1 = new int* [this->r1];
        this->ptr2 = new int* [this->r2];
        this->ptr3 = new int* [this->r1];
        for(int i = 0; i < this->r1; i++)
        {
            this->ptr1[i] = new int [this->c1];
        } 
        for(int i = 0; i < r2; i++)
        {
            this->ptr2[i] = new int [this->c2];
        }
        for(int i = 0; i < c2; i++)
        {
            this->ptr3[i] = new int [this->c2];
        } 
    }
    //assignment operator overloaded
    void operator=(matrix &obj)
    {
        this->r1 = obj.r1;
        this->c1 = obj.c1;
        this->r2 = obj.r2;
        this->c2 = obj.c2;
    //no need to allocate memory in assignment operator, since it is allocated by the constructor when the object is instantiated
    }
    void acceptFirstMatrix()
    {
        cout << "Please enter elements of matrix" << "[" << this->r1 << "x" << this->c1 << "] :" << endl;
        for (int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c1; j++)
            cin >> this->ptr1[i][j];
        }
    }
    void acceptSecondMatrix()
    {
        cout << "Please enter elements of matrix" << "[" << this->r2 << "x" << this->c2 << "] :" << endl;
        for (int i = 0; i < r2; i++)
        {
            for(int j = 0; j < c2; j++)
            cin >> this->ptr2[i][j];
        }
    }
    void printThird()
    {
        cout << "----------------------" << endl;
        for (int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c2; j++)
            cout << this->ptr3[i][j] << " ";
            cout << endl;
        }
        cout << "----------------------" << endl;
    }
    void add()
    {
        for (int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c1; j++)
            this->ptr3[i][j] = this->ptr1[i][j] + this->ptr2[i][j];
        }
        cout << "----------------------" << endl;
        cout << "Addition result: " << endl;
    }
    void subtract()
    {
        for (int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c1; j++)
            this->ptr3[i][j] = this->ptr1[i][j] - this->ptr2[i][j];
        }
        cout << "----------------------" << endl;
        cout << "Subtraction result: " << endl;
    }
    int check_add_subtract()
    {
        if(this->r1 != this->r2 || this->c1 != this->c2 )
        {
            cout << "----------------------" << endl;
            cout << "Additon/Subtraction not possible!" << endl;
            cout << "Note: Number of rows and columns of the first matrix should be equal to that of the second one." <<endl;
            cout << "----------------------" << endl;
            return -1;
        }
        return 0;
    }
    void multiply()
    {
        for (int m = 0; m < r1; m++)
        {
            for (int i = 0; i < c2; i++)
            {
                int sum = 0;
                for (int j = 0; j < c1; j++)
                {
                    sum = sum + this->ptr1[m][j] * this->ptr2[j][i];
                }
                this->ptr3[m][i] = sum;
            }
        }
        cout << "----------------------" << endl;
        cout << "Multiplication result: " << endl;
    }
    int check_multiply()
    {
        if(this->c1 != this->r2)
        {
            cout << "----------------------" << endl;
            cout << "Multiplication not possible!" << endl;
            cout << "Note: Number of columns of the first matrix should be equal to number of rows of the second one." <<endl;
            cout << "----------------------" << endl;
            return -1;
        }
        return 0;
    }
    void transpose()
    {
        for (int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c1; j++)
            this->ptr3[i][j] = this->ptr1[j][i];
        }
        cout << "----------------------" << endl;
        cout << "Transpose: " << endl;
    }
    ~matrix()
    {
        for(int i = 0; i < r1; i++)
        {
            delete [] this->ptr1[i];
        } 
        for(int i = 0; i < r2; i++)
        {
            delete [] this->ptr2[i];
        }
        for(int i = 0; i < c2; i++)
        {
            delete [] this->ptr3[i];
        }
        delete [] this->ptr1;
        delete [] this->ptr2;
        delete [] this->ptr3;
    }
};
int menu()
{
    int choice;
    cout << "Please select your choice: " << endl;
    cout << "0. Exit\n1. Matrix addition\n2. Matrix subtraction\n3. Matrix multiplication\n4. Transpose" << endl;
    cin >> choice;
    cout << "----------------------" << endl;
    return choice;
}
int main()
{
    matrix m2;
    matrix m3 = m2; //copy constructor will be called
    matrix m4;
    m4 = m2; //overloaded assignment operator will be called
    int choice;
    while((choice = menu()) != 0)
    {
        matrix m1;
        switch(choice)
        {
            case 1:
            if(m1.check_add_subtract() != -1)
            {
                m1.acceptFirstMatrix();
                m1.acceptSecondMatrix();
                m1.add();
                m1.printThird();
            }
            break;
            case 2:
            if(m1.check_add_subtract() != -1)
            {
                m1.acceptFirstMatrix();
                m1.acceptSecondMatrix();
                m1.subtract();
                m1.printThird();
            }
            break;
            case 3:
            if(m1.check_multiply() != -1)
            {
                m1.acceptFirstMatrix();
                m1.acceptSecondMatrix();
                m1.multiply();
                m1.printThird();
            }
            break;
            case 4:
            m1.acceptFirstMatrix();
            m1.transpose();
            m1.printThird();
            break;
            default:
            cout << "----------------------" << endl;
            cout << "Invalid choice!" << endl;
            cout << "----------------------" << endl;
        }
    }
    return 0;
}
