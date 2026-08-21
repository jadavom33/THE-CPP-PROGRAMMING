#include "LIBRARY.CPP"

int main()
{
    LibraryItem *items[MAX_ITEMS];

    int count = 0;
    int choice;
    int id;

    items[count] = new Book("CPP", "Bjarne Stroustrup", "101");
    count++;
    items[count] = new DVD("Inception", "Christopher Nolan", 102);
    count++;
    items[count] = new Magazine("C", "Dennis Ritchie", 103);
    count++;

    for (;;)
    {
        cout << "========== LIBRARY SYSTEM ==========" << endl;
        cout << "1. Display All Items" << endl;
        cout << "2. Search Item" << endl;
        cout << "3. Check Out Item" << endl;
        cout << "4. Return Item" << endl;
        cout << "5. Add Book" << endl;
        cout << "6. Add DVD" << endl;
        cout << "7. Add Magazine" << endl;
        cout << "8. Remove Item" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            displayAll(items, count);
        }

        else if (choice == 2)
        {
            searchItem(items, count);
        }

        else if (choice == 3)
        {
            displayAll(items, count);
            cout << endl
                 << "Enter Item ID: ";
            cin >> id;

            if (id >= 1 && id <= count)
            {
                items[id - 1]->checkOut();
            }
            else
            {
                cout << "Invalid Item ID.\n";
            }
        }

        else if (choice == 4)
        {
            displayAll(items, count);

            cout << endl
                 << "Enter Item ID: ";
            cin >> id;

            if (id >= 1 && id <= count)
            {
                items[id - 1]->returnItem();
            }
            else
            {
                cout << "Invalid Item ID.\n";
            }
        }

        else if (choice == 5)
        {
            char title[20];
            char author[20];
            char isbn[20];

            fflush(stdin);
            cout << "Enter title: ";
            gets(title);

            fflush(stdin);
            cout << "Enter author: ";
            gets(author);

            fflush(stdin);
            cout << "Enter ISBN: ";
            gets(isbn);

            if (count < MAX_ITEMS)
            {
                items[count] = new Book(title, author, isbn);
                count++;
                cout << "Book added." << endl;
            }
            else
            {
                cout << "Library is full." << endl;
            }
        }

        else if (choice == 6)
        {
            char title[20];
            char director[20];
            int duration;

            fflush(stdin);
            cout << "Enter title: ";
            gets(title);

            fflush(stdin);
            cout << "Enter director: ";
            gets(director);

            cout << "Enter duration: ";
            cin >> duration;

            if (count < MAX_ITEMS)
            {
                items[count] = new DVD(title, director, duration);
                count++;
                cout << "DVD added." << endl;
            }
            else
            {
                cout << "Library is full." << endl;
            }
        }

        else if (choice == 7)
        {
            char title[20];
            char publisher[20];
            int issue;

            fflush(stdin);
            cout << "Enter title: ";
            gets(title);

            fflush(stdin);
            cout << "Enter publisher: ";
            gets(publisher);

            cout << "Enter issue number: ";
            cin >> issue;

            if (count < MAX_ITEMS)
            {
                items[count] = new Magazine(title, publisher, issue);
                count++;

                cout << "Magazine added.\n";
            }
            else
            {
                cout << "Library is full.\n";
            }
        }

        else if (choice == 8)
        {
            displayAll(items, count);
            cout << "\nEnter Item ID: ";
            cin >> id;

            if (id >= 1 && id <= count)
            {
                delete items[id - 1];

                for (int i = id - 1; i < count - 1; i++)
                {
                    items[i] = items[i + 1];
                }
                count--;
                cout << "Item removed.\n";
            }
            else
            {
                cout << "Invalid Item ID.\n";
            }
        }

        else if (choice == 9)
        {
            cout << endl << "EXIT.";
            if (choice == 9)
            {
                return 0;
            }
        }

        else
        {
            cout << endl << "Invalid choice.";
        }
    }

    for (int i = 0; i < count; i++)
    {
        delete items[i];
    }

    return 0;
}