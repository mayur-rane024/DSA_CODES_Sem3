// Name       : Mayuresh Shailesh Rane
// PRN No     : 123B1B241
// Assignment : 9(B)
// Title      : Implement a checkout system for a supermarket to efficiently manage customer queues during peak hours. The system should support the following operations using a circular queue data structure: a. Customer arrival b. Customer checkout c. Close Checkout Counter d. View customer.


#include<iostream>
using namespace std;

class Node{
    public:
    string customer_name;  // Stores customer name
    Node *next;  // Pointer to the next node in the queue
    Node(){
        next = NULL;
    }
    void read(){  // Take input for customer name
        cout << "Enter customer name: ";
        cin >> customer_name;
    }
    void display(){  // Display customer name
        cout << "Customer name: " << customer_name;
    }
};

class Queue{
    public:
    Node *front;  // Pointer to the front of the queue
    Node *rear;   // Pointer to the rear of the queue

    Queue(){
        front = rear = nullptr;  // Initialize an empty queue
    }

    // Function to handle customer arrival
    void customerArrival(){
        Node *nn = new Node;  // Create a new node
        cout << "--------------------------------" << endl;
        nn->read();  // Read customer details
        if(front == NULL){
            front = rear = nn;  // If queue is empty, set both front and rear
            rear->next = front;  // Make it circular
        }
        else{
            rear->next = nn;  // Add new customer at the rear
            rear = nn;
            rear->next = front;  // Maintain circular structure
        }
        cout << "Customer " << rear->customer_name << " arrived at the counter." << endl;
        cout << "--------------------------------" << endl;
    } 

    // Function to handle customer checkout (removal from the queue)
    void customerCheckout(){
        cout << "--------------------------------" << endl;
        if(front == NULL){
            cout << "No customer to checkout.";  // Queue is empty
            return;
        }
        else if(front == rear){  // Only one customer in the queue
            cout << "Customer " << front->customer_name << " checked out." << endl;
            delete front;  // Remove customer
            front = rear = NULL;  // Queue is now empty
        }
        else{
            Node *cn = front;  // Store front temporarily
            cout << "Customer " << front->customer_name << " checked out" << endl;
            front = front->next;  // Move front pointer to the next customer
            rear->next = front;  // Maintain circular structure
            delete cn;  // Remove the old front
        }
        cout << "--------------------------------" << endl;
    }

    // Function to display the queue
    void display_queue(){
        cout << "--------------------------------" << endl;
        if(front == NULL){
            cout << "Counter is closed";  // No customers in the queue
            return;
        }
        Node *cn = front;
        do{
            cout << cn->customer_name;  // Print each customer name
            if(cn->next != front){
                cout << endl;
            }
            cn = cn->next;  // Move to the next customer
        }
        while(cn != front);  // Stop when we reach the front again
        cout << endl << "--------------------------------" << endl;
    }

    // Function to close the checkout counter and remove all customers
    void closeCheckOut(){
        cout << "--------------------------------" << endl;
        if(front == NULL){
            cout << "Counter is closed";  // Already empty
            return;
        }
        while(front != rear){  // Remove all customers except the last one
            Node *cn = front;
            front = front->next;  // Move front pointer
            rear->next = front;  // Maintain circular structure
            delete cn;  // Delete customer
        }
        delete front;  // Delete the last customer
        front = rear = NULL;  // Queue is now empty
        cout << "Checkout counter is closed" << endl;
        cout << "--------------------------------" << endl;
    }
};

int main(){
    Queue q;  // Create a queue instance
    int choice;

    do{
        cout << endl << "Supermarket checkout counter:" << endl
             << "1. Customer arrival" << endl
             << "2. Customer Checkout" << endl
             << "3. Close Counter" << endl
             << "4. Display Queue" << endl
             << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                q.customerArrival();  // Handle new customer arrival
                break;
            case 2:
                q.customerCheckout();  // Handle customer checkout
                break;
            case 3:
                q.closeCheckOut();  // Close the counter and clear queue
                break;
            case 4:
                q.display_queue();  // Display all customers in the queue
                break;
            case 5:
                exit(0);  // Exit the program
                break;
        }
    }
    while(true);  // Loop until the user chooses to exit

    return 0;
}
