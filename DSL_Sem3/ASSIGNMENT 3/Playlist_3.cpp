// NAME       : Mayuresh Shailesh Rane
//PRN         : 123B1B241
// ASSIGNMENT : 3
/* TITLE      : Consider the playlist in a music player. Implement a playlist feature in music player application using singly linked list.
Each song in the playlist is represented as a node in the linked list. Each node contains information about the song (such as title or artist or duration, etc.).
The playlist should allow users to: a. Add songs b. Remove songs c. Display the entire playlist d. Play specific songs. */

#include <iostream>
#include <string>

using namespace std;


class Song {                   //SONG CLASS
public:
    string title;             // Song title
    string artist;            // Song artist
    Song* next;               // Pointer to the next song in the playlist

    // Constructor to initialize a song with title and artist 
    Song(string t, string a) {
        title=t;
        artist=a;
        next=nullptr;
    }
    
};

class Playlist {             //CLASS PLAYLIST

    Song* head;  // Pointer to the head (first) song in the playlist

public:
    // Constructor to initialize an empty playlist
    Playlist() { 
        head=nullptr; 
    }

    // Add a song at the beginning of the playlist
    void addSongAtBeginning(string title, string artist)
    {
        Song* nn = new Song(title, artist); // Create a new song
        nn->next = head;  // Link the new song to the current head
        head = nn;        // Update head to point to the new song
    }

    // Add a song at the end of the playlist
    void addSongAtEnd(string title, string artist)
    {
        Song* nn = new Song(title, artist); // Create a new song

        if (head == nullptr) { // If the playlist is empty
            head = nn;    // Set the new song as the head
        } else {
            Song* temp = head;
            for(temp ; temp->next!=NULL ; temp=temp->next){}
            temp->next = nn; // Add the new song at the end
        }
    }

    // Add a song at a specific position in the playlist
    void addSongAtMiddle(string title, string artist , int position)
    {
        Song* nn = new Song(title, artist); // Create a new song
        if (position == 0) // If position is 0, add at the beginning
        {
            addSongAtBeginning(title, artist);
            return;
        }
        Song* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) // Traverse to the position
        {
            temp = temp->next;
        }
        if (temp == nullptr) // If position is out of bounds
        {
            cout << "Position out of bounds." << endl;
            delete nn; // Clean up memory
        }
        else
        {
            nn->next = temp->next; // Insert the new song at the position
            temp->next = nn;
        }
    }

    // Remove a song by title from the playlist
    void removeSong(string title)
    {
        if (head == nullptr) return; // If playlist is empty, return
        if (head->title == title) // If the song to remove is the first song
        {
            Song* temp = head;    // Store the current head
            head = head->next;    // Update head to the next song
            delete temp;          // Delete the removed song
            return;
        }
        Song* temp = head;
        while (temp->next != nullptr && temp->next->title != title) // Traverse the playlist
        {
            temp = temp->next;
        }
        if (temp->next == nullptr) // If song is not found
        {
            cout << "Song not found" << endl;
        }
        else
        {
            Song* toDelete = temp->next; // Store the song to be deleted
            temp->next = temp->next->next; // Link previous song to the next one
            delete toDelete; // Delete the song
        }
    }

    // Display all songs in the playlist
    void displayPlaylist()
    {
        Song* temp = head;
        while (temp != nullptr) // Traverse and print each song
        {
            cout << "Title: " << temp->title << ", Artist: " << temp->artist <<endl;
            temp = temp->next;
        }
    }

    // Play a specific song by title
    void playSong(string title)
    {
        Song* temp = head;
        while (temp != nullptr && temp->title != title) // Search for the song
        {
            temp = temp->next;
        }
        if (temp == nullptr) // If song is not found
        {
            cout << "Song not found" << endl;
        }
        else
        {
            cout << "Playing: " << temp->title << " by " << temp->artist << endl;
        }
    }
};

int main()
{
    Playlist myPlaylist;
    int choice;
    string title, artist;
    double duration;
    int position;

    // Display the menu once at the beginning
    cout << "\nMenu\n";
    cout << "1. Add Song at the beginning\n";
    cout << "2. Add Song in the Middle\n";
    cout << "3. Add Song at the End\n";  // New option for adding song at the end
    cout << "4. Remove Song\n";
    cout << "5. Display playlist\n";
    cout << "6. Play specific song\n";
    cout << "7. Exit\n";

    do
    {
        // Ask for user's choice
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                // Add a song at the beginning
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                myPlaylist.addSongAtBeginning(title, artist);
                break;
            case 2:
                // Add a song in the middle at a specified position
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                cout << "Enter position to add song: ";
                cin >> position;
                myPlaylist.addSongAtMiddle(title, artist, position);
                break;
            case 3:
                // Add a song at the end
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                myPlaylist.addSongAtEnd(title, artist);  // Call to the new function
                break;
            case 4:
                // Remove a song by title
                cout << "Enter song to remove: ";
                cin.ignore();
                getline(cin, title);
                myPlaylist.removeSong(title);
                break;
            case 5:
                // Display the entire playlist
                myPlaylist.displayPlaylist();
                break;
            case 6:
                // Play a specific song by title
                cout << "Enter song to play: ";
                cin.ignore();
                getline(cin, title);
                myPlaylist.playSong(title);
                break;
            case 7:
                // Exit the program
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7); // Keep running the menu until the user exits

    return 0;
}
