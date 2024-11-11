// Name       : Mayuresh Shailesh Rane
// PRN No     : 123B1B241
// Assignment : 2(A)
// Title      : Arrange list of employees according to EMP-ID in ascending order using Quick Sort

#include <iostream>
#include <string>
using namespace std;

class Employee       //class  Employee
{
    string name;
    int id;
    int salary;

public:
    void read()              // Input employee details
    {
        cout << "Enter Employee Id: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin>>name;
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }
    void display()  //display employee details
    {
        cout << "Employee Name: " << name << " ";
        cout << "Employee Id: " << id << " ";
        cout << "Employee Salary: " << salary << endl;
    }

    // Declare friend functions
    friend void swap(Employee &a, Employee &b);
    friend int partition(Employee A[], int low, int high);
    friend void QS(Employee A[], int low, int high);
};

// Swap two Employee objects
void swap(Employee &a, Employee &b)
{
    Employee temp = a;
    a = b;
    b = temp;
}

// Partition function for Quick Sort
int partition(Employee A[], int low, int high)
{
    double pivot = A[high].id;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (A[j].id < pivot)
        {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[high]);
    return i + 1;
}

// Quick Sort function
void QS(Employee A[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(A, low, high);
        QS(A, low, pivot - 1);
        QS(A, pivot + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter the number of Employees: ";
    cin >> n;
    Employee employee[n];       //array of Employee objects
    
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Employee Details: " << endl;
        employee[i].read(); 
    }

    // Sort the employees using Quick Sort
    QS(employee, 0, n - 1);

    // Display sorted employees
    cout << "\nEmployees sorted by Employee Id in ascending order:" << endl;
    for (int i = 0; i < n; i++)
    {
        employee[i].display();
    }

    return 0;
}