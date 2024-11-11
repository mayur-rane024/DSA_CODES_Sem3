// Name       : Mayuresh Shailesh Rane
// PRN No     : 123B1B241
// Assignment : 9(A)
// Title      : a] Implement a restaurant waitlist system using the queue data structure. Restaurant waitlist provide following facility: a. Add Party to Waitlist b. Seat Party c. Display Waitlist


#include<iostream>
using namespace std;

// Class representing a Party in the waiting list
class Party{
  string name; // Name of the party
  int number;  // Contact number of the party
  public :
  Party* next; // Pointer to the next party in the queue (linked list structure)
  
  // Function to read input details of the party
  void read(){
      cout<<"ENTER THE NAME:"<<endl;
      cin>>name;
      cout<<"ENTER CONTACT NUMBER:"<<endl;
      cin>>number;
  }
  
  // Function to display the details of the party
  void display(){
      cout<<"Name: "<<name<<endl;
      cout<<"Number: "<<number<<endl<<endl;
  }
};

// Class representing the Queue for the waiting list
class Queue{
  Party* front; // Pointer to the front (first) party in the queue
  Party* rear;  // Pointer to the rear (last) party in the queue
  
  public:
  // Constructor to initialize an empty queue
  Queue(){
      front = rear = NULL;
  }
  
  // Function to add a new party to the queue (end of the list)
  void add_party(){
     Party* nn = new Party; // Create a new party
     nn->read(); // Read the details of the party
     nn->next = NULL; // The new party doesn't point to any next party yet
     
     // If the queue is empty, make the new party both front and rear
     if(rear == NULL){
          front = rear = nn;
      }
      else{
          // If not, add the new party at the end and update the rear pointer
          rear->next = nn;
          rear = nn;
      }
  }
  
  // Function to remove a party from the front (simulate seating them)
  void seat(){
     if(front == NULL){
         cout<<"WAITING LIST EMPTY NOW!!"; // Queue is empty, no party to remove
     } else {
      Party* temp = front; // Store the front party temporarily
      front = front->next; // Move the front pointer to the next party
     
       // If the front becomes NULL, also set rear to NULL (queue is now empty)
       if (front == nullptr) {
            rear = nullptr;
        }
       
      delete temp; // Free memory allocated to the removed party
      }
  }
  
  // Function to display all parties currently in the queue (waiting list)
  void display(){
      if(front == NULL){
         cout<<"WAITING LIST EMPTY NOW!!"; // No parties in the queue
      }
      for(Party* cn = front; cn != NULL; cn = cn->next){ // Traverse the queue
          cn->display(); // Display each party's details
      }
  }
};

int main(){
    Queue q; // Create an instance of Queue
    int a; // Variable to store the user's choice
    
    while(true){ // Infinite loop for continuous interaction
    // Display menu options for the user
    cout << "Menu Options:\n";
    cout << "1. Add Customer\n";
    cout << "2. Remove Customer\n";
    cout << "3. Display waiting list:\n";
    cout << "4. Exit\n";
    cout << "Choose an option (1-4): ";
    cin >> a;
   
    // Execute the corresponding function based on the user's choice
    switch(a){
        case 1: q.add_party(); break; // Add a party to the queue
        case 2: q.seat(); break;      // Remove a party from the front (seat them)
        case 3: q.display(); break;   // Display all parties in the waiting list
        case 4: 
            cout << "Exiting the program." << endl;
            return 0; // Exit the program
        default: 
            cout << "Invalid option, please try again." << endl; // Handle invalid input
    }
    }
    
    return 0;
}
