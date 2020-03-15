#include <iostream>
#include "ADTStackLList.h"

using namespace std;

void menu();


int main() {

    stack<int> s;
    int choice;

    do {
        menu();
        cin >> choice;
        switch (choice) {
            case 1:
                int input;
                cout << "Enter an item to be pushed:";
                cin >> input;
                s.push(input);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid option..." << endl;
        }
    } while (choice != 4);

    return 0;
}

void menu() {
    cout << "\n*** Menu for Stack operations ***\n\n";
    cout << "1.PUSH (insert)\n";
    cout << "2.POP (remove)\n";
    cout << "3.DISPLAY\n";
    cout << "4.EXIT\n";
    cout << "\nEnter choice:";
}