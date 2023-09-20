#include <iostream>
using namespace std;

class employee
{
    protected:
    int id;
    float salary;
    public:
    employee():id(0), salary(0)
    {
    }
    employee(int id, float salary)
    {
        this->id = id;
        this->salary = salary;
    }
    int get_id()
    {
        return this->id;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    float get_sal()
    {
        return this->salary;
    }
    void set_sal(float salary)
    {
        this->salary = salary;
    }
    virtual void display()
    {
        cout << "ID : " << this->id << endl;
        cout << "Salary: " << this->salary << endl;
    }
    virtual void accept()
    {
        cout << "Please enter employee ID :";
        cin >> this->id;
        cout << "Please enter salary :";
        cin >> this->salary;
    }
    virtual ~employee()
    {
    }
};
class manager : virtual public employee
{
    protected:
    float bonus;
    void accept_manager()
    {
        cout << "Please enter bonus: ";
        cin >> this->bonus;
    }
    void display_manager()
    {
        cout << "Bonus: " << this->bonus << endl;
    }
    public:
    manager(): employee()
    {
        this->bonus = 0;
    }
    manager(int id, float salary, float bonus) : employee(id, salary)
    {
        this->bonus;
    }
    float get_bonus()
    {
        return this->bonus;
    }
    void set_bonus(float bonus)
    {
        this->bonus = bonus;
    }
    void display()
    {
        employee::display();
        this->display_manager();    
    }
    void accept()
    {
        employee::accept();
        this->accept_manager(); 
    }

};
class salesman : virtual public employee
{
    protected:
    float comm;
    void accept_salesman()
    {
        cout << "Please enter comm: ";
        cin >> this->comm;  
    }
    void display_salesman()
    {
        cout << "Comm: " << this->comm << endl;
    }
    public:
    salesman() : employee()
    {
        this->comm = 0;
    }
    salesman(int id, float salary, float comm) : employee(id, salary)
    {
        this->comm = comm;
    }
    float get_comm()
    {
        return this->comm;
    }
    void set_comm(float comm)
    {
        this->comm = comm;
    }
    void display()
    {
        employee::display();
        this->display_salesman();
    }
    void accept()
    {
        employee::accept();
        this->accept_salesman();  
    }
};
class sales_manager :  public manager,  public salesman
{
    public:
    sales_manager() : manager(), salesman()
    {
    }
    sales_manager(int id, float salary, float bonus, float comm) : manager(id, salary, bonus), salesman(id, salary, comm)
    {
    }
    void display()
    {
        employee::display();
        this->display_manager();
        this->display_salesman();
    }
    void accept()
    {
        employee::accept();
        this->accept_manager();
        this->accept_salesman();
    }
};
int menu()
{
    int choice;
    cout << "---------------------" << endl;
    cout << "Please enter your choice: " << endl;
    cout << "0. Exit" << endl;
    cout << "1. Add employee" << endl;
    cout << "2. Display all employees" << endl;
    cout << "3. Add manager" << endl;
    cout << "4. Display all managers" << endl;
    cout << "5. Add salesman" << endl;
    cout << "6. Display all salesmen" << endl;
    cout << "7. Add sales manager" << endl;
    cout << "8. Display all sales managers" << endl;
    cout << "9. Display count of all employees as per designation" << endl;
    cin >> choice;
    cout << "---------------------" << endl;
    return choice;
}
void display_count(employee **arr, int index)
{
    int employee_count = 0, manager_count = 0, salesman_count = 0, sales_manager_count = 0;
    for (int i = 0; i < index; i++)
    {
        if (typeid(*arr[i]) == typeid(employee))
        employee_count++;
        if (typeid(*arr[i]) == typeid(manager))
        manager_count++;
        if (typeid(*arr[i]) == typeid(salesman))
        salesman_count++;
        if (typeid(*arr[i]) == typeid(sales_manager))
        sales_manager_count++;
    }
    cout << "---------------------" << endl;
    cout << "Employee count is as per given below: " << endl;
    cout << "Employee count: " << employee_count << endl;
    cout << "Manager count: " << manager_count << endl;
    cout << "Salesman count: " << salesman_count << endl;
    cout << "Salesmanager count: " << sales_manager_count << endl;
    cout << "---------------------" << endl;
}
int main()
{
    int index = 0;
    employee *e1 = NULL;
    employee **arr = new employee*[10];
    int choice;
    while((choice = menu()) != 0)
    {
        int count = 0;
        switch(choice)
        {
            case 1:
            arr[index] = new employee();
            break;
            case 2:
            for(int i = 0; i < index; i++)
            {
                if(typeid(*arr[i]) == typeid(employee))
                {
                    arr[i]->display();
                    count++;
                }
            }
            if(count == 0)
            cout << "No record exist for employees." << endl;
            break;
            case 3:
            arr[index] = new manager();
            break;
            case 4:
            for(int i = 0; i < index; i++)
            {
                if(typeid(*arr[i]) == typeid(manager))
                {
                    arr[i]->display();
                    count++;
                }
            }
            if(count == 0)
            cout << "No record exist for managers." << endl;
            break;
            case 5:
            arr[index] = new salesman();
            break;
            case 6:
            for(int i = 0; i < index; i++)
            {
                if(typeid(*arr[i]) == typeid(salesman))
               {
                    arr[i]->display();
                    count++;
                }
            }
            if(count == 0)
            cout << "No record exist for salesmen." << endl;
            break;
            case 7:
            arr[index] = new sales_manager();
            break;
            case 8:
            for(int i = 0; i < index; i++)
            {
                if(typeid(*arr[i]) == typeid(sales_manager))
                {
                    arr[i]->display();
                    count++;
                }
                
            }
            if(count == 0)
            cout << "No record exist for sales managers." << endl;
            break;
            case 9:
            display_count(arr, index);
            break;
            default:
            cout << "Invalid choice!" << endl;
            cout << "---------------------" << endl;
        }
        if(arr[index] !=  NULL)
        {
            if(index < 10)
            {
                arr[index]->accept();
                index++;
            }
            else if(choice == 1 || choice == 3 || choice == 5 || choice == 7)
            {
                cout << "---------------------" << endl;
                cout << "Array is full! :(" << endl;
                cout << "---------------------" << endl;
            }  
        }
    }
    delete [] arr;
    return 0;
}