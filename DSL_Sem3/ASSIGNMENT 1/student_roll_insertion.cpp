// Name       : Mayuresh Shailesh Rane
// PRN No     : 123B1B241
// Assignment : 1(A)
// Title      : Design a roll call list, arrange list of students according to roll numbers in ascending order using Insertion Sort

#include <iostream>
#include <string>
using namespace std;

class Student                 // Class Student to hold student details
{   string name;
    int roll;
    float sgpa;

public:
        void read(Student A[], int n)   //Input student details
        {
            for(int i = 0; i < n; ++i)
            {
                cout << "Student name: ";
                cin>>A[i].name; // Input Student Name
                cout << "Student Roll number: ";
                cin >> A[i].roll; // Input Roll number
                cout << "Student SGPA: ";
                cin >> A[i].sgpa; // Input Student SGPA
            }
        }

    void display(Student A[], int n)     // Display student details
    {
        for(int i = 0; i < n; i++)
        {
            cout << "Student Name: " << A[i].name << " ";
            cout << "Student Roll number: " << A[i].roll << " ";
            cout << "Student SGPA: " << A[i].sgpa << endl;
        }
    }

    friend void insertionSort(Student A[], int n); // InsertionSort as a friend function
};

// Function to sort students based on roll numbers using Insertion Sort
void insertionSort(Student A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Student key = A[i]; // Store the current student to be inserted
        int j = i - 1;

        // Move elements of A[0..i-1], that are greater than key.roll, to one position ahead
        while (j >= 0 && A[j].roll > key.roll)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key; // Insert the key (current student) at the correct position
    }
}

int main()
{
    int n;  //Number of students
    int i;

    cout << "Number of Students: ";
    cin >> n;
    Student A[n]; // Create an array of Student objects

    // Read student details
    A[i].read(A, n);
    cout << endl;
    cout << "Student Database before sorting: " << endl;
    //Before sorting
    A[i].display(A, n);
    cout << endl;

    insertionSort(A, n);

    cout << "Student Database after sorting: " << endl;
    //After sorting
    A[i].display(A, n);

    return 0;
}