#include <iostream>
#include <queue>
using namespace std;
class Email {
    string sender;
    string subject;
    string content;
};
void composeEmail(queue<Email>& inbox) {
    Email newEmail;
    cout << "Compose New Email:" << endl;
    cout << "Sender: ";
    cin >> newEmail.sender;
    cout << "Subject: ";
    cin >> newEmail.subject;
    cout << "Content: ";
    cin >> newEmail.content;
    inbox.push(newEmail);
    cout << "Email sent successfully!" << endl;
}

// Function to read the next email in the inbox
void readNextEmail(queue<Email>& inbox) {
    if (inbox.empty()) {
        cout << "Inbox is empty. No emails to read." << endl;
        return;
    }
    Email nextEmail = inbox.front();
    cout << "From: " << nextEmail.sender << endl;
    cout << "Subject: " << nextEmail.subject << endl;
    cout << "Content: " << nextEmail.content << endl;
    inbox.pop();
}

// Function to display the number of emails in the inbox
void displayInboxSize(queue<Email>& inbox) {
    cout << "Number of emails in inbox: " << inbox.size() << endl;
}

int main() {
    queue<Email> inbox;

    int choice;
    do {
        cout << "\n------ Email Application ------" << endl;
        cout << "1. Compose Email" << endl;
        cout << "2. Read Next Email" << endl;
        cout << "3. Display Inbox Size" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                composeEmail(inbox);
                break;
            case 2:
                readNextEmail(inbox);
                break;
            case 3:
                displayInboxSize(inbox);
                break;
            case 4:
                cout << "Exiting the email application. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
