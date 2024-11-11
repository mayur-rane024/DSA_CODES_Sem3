// Name       : Mayuresh Shailesh Rane
// PRN No     : 123B1B241
// Assignment : 1(B)
//Title      : Arrange list of students alphabetically using shell sort

#include <iostream>
#include <string>
using namespace std;

class Student   // class Student to hold student details 
{
    string name;
    int roll;
    float sgpa;

public:

    void read(Student A[], int n) // Input student details
    {
        for(int i = 0; i < n; ++i)
       {
            cout << "Student name: ";
            cin>>A[i].name;         // Input Student Name
            cout << "Student Roll number: ";
            cin >> A[i].roll;        // Input Roll number
            cout << "Student SGPA: ";
            cin >> A[i].sgpa;       // Input Student SGPA
       }

    }

    void display(Student A[], int n)    // Display student details
    {
        for(int i = 0; i < n; i++)
        {
            cout << "Student Name: " << A[i].name << " ";
            cout << "Student Roll number: " << A[i].roll << " ";
            cout << "Student SGPA: " << A[i].sgpa << endl;
        }

    }

    friend void shellSort(Student A[], int n);   // Declare shellSort as a friend function
};

// Function to sort students alphabetically by name using Shell Sort
void shellSort(Student A[], int n)
{
    // Start with a big gap, then reduce the gap
    for(int gap = n/2; gap > 0; gap /= 2)
    {
        // Perform a gapped insertion sort for this gap size
        for(int i = gap; i < n; i++)
        {
            Student temp = A[i]; // Store the current student to be inserted
            int j;

            // Shift earlier gap-sorted elements up until the correct location for A[i] is found
            for(j = i; j >= gap && A[j - gap].name > temp.name; j -= gap)
            {
                A[j] = A[j - gap];// Shift element to the right
            }
            A[j] = temp; // Insert the current student at the correct position
        }
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

    shellSort(A, n); // Sort the students by name using Shell Sort

    cout << "Student Database after sorting: " << endl;
    //After sorting
    A[i].display(A, n);

    return 0;

}