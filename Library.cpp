#include <bits/stdc++.h>
using namespace std;

// class representing book details
class Book
{
public:
    string title;
    string author;
    string ISBN;
    string status;
};


//catalog for storing all the book details
vector<Book> catalog;


//this utility function will validate ISBN number 
string CheckISBN(string isbn)
{
    string is = isbn;
    if (is.length() != 13)
    {
        do
        {
            cout << "incorrect ISBN, Enter 13 digits" << endl;
            cin >> is;
        } while (is.length() != 13);
    }
    return is;
}

//function to  display the catalog
void Display()
{

    for (int i = 0; i < catalog.size(); i++)
    {
        cout << " | TITLE : " << catalog[i].title;
        cout << " | AUTHOR : " << catalog[i].author;
        cout << " | ISBN   : " << catalog[i].ISBN;
        cout << " | Status : " << catalog[i].status << " | ";
        cout << endl;
    }
}

// function which will add books in catalog
void AddBooks()
{
    cout << "Title  : ";
    string title;
    fflush(stdin);
    getline(cin, title);

    cout << "Author : ";
    string author;
    getline(cin, author);

    cout << "ISBN: ";
    string ISBN;
    cin >> ISBN;
    ISBN = CheckISBN(ISBN);

    Book temp;
    temp.title = title;
    temp.author = author;
    temp.status = "YES";
    temp.ISBN = ISBN;
    catalog.push_back(temp);
}

// function to remove the book from catalog
void RemoveBook()
{
    int select;
    do
    {
        try
        {
            cout << "1.  Remove with Title" << endl;
            cout << "2.  Remove with ISBN " << endl;
            cin >> select;
            if (cin.fail())
            {
                throw runtime_error("NOT VALID INPUT");
            }
        }
        catch (const std::runtime_error &e)
        {
            cout << e.what() << '\n';
            break;
        }
        if (select == 1)
        {
            cout << "Enter Title : ";
            string T;
            fflush(stdin);
            getline(cin, T);
            bool found = false;
            for (int i = 0; i < catalog.size(); i++)
            {
                if (catalog[i].title == T)
                {
                    found = true;
                    catalog.erase(catalog.begin() + i);
                }
            }
            if (!found)
            {
                cout << "Book Not Found :( " << endl;
            }
        }
        else if (select == 2)
        {
            cout << "Enter ISBN : ";
            string T;
            cin >> T;
            T = CheckISBN(T);
            bool found = false;
            for (int i = 0; i < catalog.size(); i++)
            {
                if (catalog[i].ISBN == T)
                {
                    found = true;
                    catalog.erase(catalog.begin() + i);
                }
            }
            if (!found)
            {
                cout << "Book Not Found :( " << endl;
            }
        }
        else
        {
            cout << "Select 1 or 2 : ";
        }

    } while (select > 2 || select <= 0);
}


//  function to check the availability of a book by its title or ISBN
void BookAvailable()
{
    int select;
    do
    {
        try
        {
            /* code */
            cout << "1.  Check with Title" << endl;
            cout << "2.  Check with ISBN " << endl;
            cin >> select;
            if (cin.fail())
            {
                throw runtime_error("NOT VALID INPUT");
            }
        }
        catch (const std::runtime_error &e)
        {
            cout << e.what() << '\n';
            break;
        }

        if (select == 1)
        {
            cout << "Enter Title : ";
            string T;
            fflush(stdin);
            getline(cin, T);
            bool found = false;
            for (int i = 0; i < catalog.size(); i++)
            {
                if (catalog[i].title == T)
                {
                    found = true;
                    cout << "Availability Status : " << catalog[i].status;
                    if (catalog[i].status == "YES")
                    {
                        cout << "    Borrow ? (Y/N)" << endl;
                        char ch;
                        cin >> ch;
                        ch = toupper(ch);
                        if (ch == 'Y')
                        {
                            catalog[i].status = "NO";
                            cout << "Borrowed Successfully !";
                        }
                    }
                    else
                    {
                        cout << "    Return ? (Y/N)" << endl;
                        char ch;
                        cin >> ch;
                        ch = toupper(ch);
                        if (ch == 'Y')
                        {
                            catalog[i].status = "YES";
                            cout << "Book Returned !" << endl;
                        }
                    }
                }
            }
            if (!found)
            {
                cout << "Book Not Found :( " << endl;
            }
        }
        else if (select == 2)
        {
            cout << "Enter ISBN : ";
            string T;
            cin >> T;
            T = CheckISBN(T);
            bool found = false;
            for (int i = 0; i < catalog.size(); i++)
            {
                if (catalog[i].ISBN == T)
                {
                    found = true;
                    cout << "Availability Status : " << catalog[i].status;
                    if (catalog[i].status == "YES")
                    {
                        cout << "    Borrow ? (Y/N)" << endl;
                        char ch;
                        cin >> ch;
                        ch = toupper(ch);
                        if (ch == 'Y')
                        {
                            catalog[i].status = "NO";
                            cout << "Borrowed Successfully !";
                        }
                    }
                    else
                    {
                        cout << "    Return ? (Y/N)" << endl;
                        char ch;
                        cin >> ch;
                        ch = toupper(ch);
                        if (ch == 'Y')
                        {
                            catalog[i].status = "YES";
                            cout << "Book Returned !" << endl;
                        }
                    }
                }
            }
            if (!found)
            {
                cout << "Book Not Found :( " << endl;
            }
        }
        else
        {
            cout << "Select 1 or 2 : " << endl;
        }

    } while (select > 2 || select <= 0);
}


//main function
int main()
{


    cout << endl
         << "WELCOME TO THE LIBRARY !!!" << endl;

    int choice;
    do
    {

        cout << "\n\n    MENU : " << endl;
        cout << " 1. Add Book \n 2. Remove Book \n 3. Book Availability \n 4. Display Catalog \n";
        try
        {
            cin >> choice;
            if (cin.fail())
            {
                throw runtime_error("NOT VALID INPUT");
            }
        }
        catch (const std::runtime_error &e)
        {
            cout << e.what() << '\n';
            break;
        }

        switch (choice)
        {
        case 1:
            AddBooks();
            break;
        case 2:
            RemoveBook();
            break;
        case 3:
            BookAvailable();
            break;
        case 4:
            Display();
            break;
        }
    } while (choice <= 4);

    return 0;
}