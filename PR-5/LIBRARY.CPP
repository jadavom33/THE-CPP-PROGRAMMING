#include <iostream>
#include <string>
using namespace std;
#define MAX_ITEMS 100

class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

protected:
    int status;

public:
    LibraryItem()
    {
        title = "";
        author = "";
        dueDate = "Not Set";
        status = 0;
    }
    ~LibraryItem()
    {
    }
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    string getDueDate()
    {
        return dueDate;
    }
    void setTitle(string t)
    {
        title = t;
    }
    void setAuthor(string a)
    {
        author = a;
    }
    void setDueDate(string d)
    {
        dueDate = d;
    }
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;
};

class Book : public LibraryItem
{
private:
    string isbn;

public:
    Book(string t, string a, string i)
    {
        setTitle(t);
        setAuthor(a);
        isbn = i;

        if (isbn == "")
        {
            throw "ISBN cannot be empty.";
        }
    }

    void checkOut()
    {
        if (status == 1)
        {
            cout << "Book is already checked out.\n";
        }
        else
        {
            status = 1;
            setDueDate("30-Aug-2026");
            cout << "Book checked out successfully.\n";
        }
    }

    void returnItem()
    {
        if (status == 0)
        {
            cout << "Book is not checked out.\n";
        }
        else
        {
            status = 0;
            setDueDate("Not Set");
            cout << "Book returned successfully.\n";
        }
    }

    void displayDetails()
    {
        cout << "=======BOOK========";
        cout << "Title    : " << getTitle() << endl;
        cout << "Author   : " << getAuthor() << endl;
        cout << "ISBN     : " << isbn << endl;
        cout << "Due Date : " << getDueDate() << endl;

        if (status == 0)
            cout << "Status   : Available\n";
        else
            cout << "Status   : Checked Out\n";
    }
};

class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string t, string a, int d)
    {
        setTitle(t);
        setAuthor(a);
        duration = d;

        if (duration <= 0)
        {
            throw "DVD duration must be positive.";
        }
    }

    void checkOut()
    {
        if (status == 1)
        {
            cout << "DVD is already checked out.\n";
        }
        else
        {
            status = 1;
            setDueDate("30-Aug-2026");
            cout << "DVD checked out successfully.\n";
        }
    }

    void returnItem()
    {
        if (status == 0)
        {
            cout << "DVD is not checked out.\n";
        }
        else
        {
            status = 0;
            setDueDate("Not Set");
            cout << "DVD returned successfully.\n";
        }
    }

    void displayDetails()
    {
        cout << "========DVD========";
        cout << "Title    : " << getTitle() << endl;
        cout << "Director : " << getAuthor() << endl;
        cout << "Duration : " << duration << " minutes" << endl;
        cout << "Due Date : " << getDueDate() << endl;

        if (status == 0)
            cout << "Status   : Available\n";
        else
            cout << "Status   : Checked Out\n";
    }
};

class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(string t, string a, int i)
    {
        setTitle(t);
        setAuthor(a);
        issueNumber = i;
        if (issueNumber <= 0)
        {
            throw "Issue number must be positive.";
        }
    }

    void checkOut()
    {
        if (status == 1)
        {
            cout << "Magazine is already checked out.\n";
        }
        else
        {
            status = 1;
            setDueDate("30-Aug-2026");
            cout << "Magazine checked out successfully.\n";
        }
    }

    void returnItem()
    {
        if (status == 0)
        {
            cout << "Magazine is not checked out.\n";
        }
        else
        {
            status = 0;
            setDueDate("Not Set");
            cout << "Magazine returned successfully.\n";
        }
    }

    void displayDetails()
    {
        cout << endl << "=======MAGAZINE======";
        cout << "Title       : " << getTitle() << endl;
        cout << "Publisher   : " << getAuthor() << endl;
        cout << "Issue No.   : " << issueNumber << endl;
        cout << "Due Date    : " << getDueDate() << endl;

        if (status == 0)
            cout << "Status : Available\n";
        else
            cout << "Status : Checked Out\n";
    }
};

void displayAll(LibraryItem *items[], int count)
{
    if (count == 0)
    {
        cout << "\nNo items in library.\n";
        return;
    }

    cout << endl << "========== LIBRARY ==========";

    for (int i = 0; i < count; i++)
    {
        cout << endl << "Item ID: " << i + 1;
        items[i]->displayDetails();
    }
}

void searchItem(LibraryItem *items[], int count)
{
    string title;
    bool found = false;

    cout << endl << "Enter title: ";
    cin >> title;

    for (int i = 0; i < count; i++)
    {
        if (items[i]->getTitle() == title)
        {
            items[i]->displayDetails();
            found = true;
        }
    }

    if (!found)
    {
        cout << "\nItem not found.\n";
    }
}