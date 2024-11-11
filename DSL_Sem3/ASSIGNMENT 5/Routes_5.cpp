// Name       : Mayuresh Shailesh Rane
// PRN        : 123B1B241
// Assignment : 5
/*  TITLE     : Implement a navigation system for a delivery service using a circular linked list to represent routes.
   The navigation system should support the following functionalities: a. Add route b. Remove route
   c. Display route. */

#include <iostream>
#include <string>
using namespace std;

// Route class to represent a route between a source and destination
class Route {
public:
    string source;
    string destination;
    float distance;
    Route* next;

    // Constructor to initialize next pointer as NULL
    Route() {
        next = NULL;
    }

    // Function to read route details from the user
    void read() {
        cout << "Enter source: ";
        cin >> source;
        cout << "Enter destination: ";
        cin >> destination;
        cout << "Enter distance: ";
        cin >> distance;
    }

    // Function to display the route details
    void display() {
        cout << "Source: " << source << ", Destination: " << destination << ", Distance: " << distance << endl;
    }
};

// Navigation class to manage a circular linked list of routes
class Navigation {
    Route* tail;
public:
    // Constructor to initialize tail as NULL (empty list)
    Navigation() {
        tail = NULL;
    }

    // Function to insert a new route at the end of the list
    void insertAtEnd() {
        Route* cn = new Route();
        cn->read();
        if (tail == NULL) {
            tail = cn;
            cn->next = cn;
        } else {
            cn->next = tail->next;
            tail->next = cn;
            tail = cn;
        }
    }

    // Function to insert a new route at the head of the list
    void insertAtHead() {
        Route* cn = new Route();
        cn->read();
        if (tail == NULL) {
            tail = cn;
            cn->next = cn;
        } else {
            cn->next = tail->next;
            tail->next = cn;
        }
    }

    // Function to display all the routes in the list
    void displayRoutes() {
        if (tail == NULL) {
            cout << "No routes to display." << endl;
            return;
        }
        Route* t = tail->next;
        do {
            t->display();
            t = t->next;
        } while (t != tail->next);
    }

    // Function to delete a route by source name
    void deleteRoute(string src) {
        if (tail == nullptr) {
            cout << "No routes to delete." << endl;
            return;
        }

        Route* current = tail->next;
        Route* previous = tail;

        do {
            if (current->source == src) {
                if (current == tail) {
                    if (tail->next == tail) {
                        delete tail;
                        tail = nullptr;
                    } else {
                        previous->next = current->next;
                        tail = previous;
                        delete current;
                    }
                } else {
                    previous->next = current->next;
                    if (current == tail->next) {
                        tail->next = current->next;
                    }
                    delete current;
                }
                cout << "Route " << src << " deleted." << endl;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != tail->next);

        cout << "Route " << src << " not found." << endl;
    }
};

// Main function to provide a menu for user interaction
int main() {
    Navigation Nav;
    int choice;

    cout << "1. Add route at the end.\n";
    cout << "2. Add route at the head.\n";
    cout << "3. Display routes.\n";
    cout << "4. Delete route.\n";
    cout << "5. Exit." << endl;

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Nav.insertAtEnd();
                break;
            case 2:
                Nav.insertAtHead();
                break;
            case 3:
                Nav.displayRoutes();
                break;
            case 4: {
                string src;
                cout << "Enter source of route to delete: ";
                cin >> src;
                Nav.deleteRoute(src);
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}
