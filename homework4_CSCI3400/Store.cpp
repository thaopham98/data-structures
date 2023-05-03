#include <iostream>
#include "Store.h"
using namespace std;

/*MARK: Store() constructor*/
Store::Store()
{
    head = NULL;
    size = 0;
}

/*MARK: addBook()*/
void Store::addBook(string title, string author, string ISBN, float price)
{
    Textbook *newTextbook = new Textbook( title,  author,  ISBN,  price); //new Textbook
    
    if(Store::isEmpty())
    {
        head = newTextbook;
//        cout << "\nThe list is empty. Assigning new textbooks\n";
    }
    else if(price < head->price)
    {
        newTextbook-> next = head;
        head = newTextbook;
    }
    else if (size == 1)
    {
        head -> next = newTextbook;
    }
    else
    {
        Textbook* current = head;
        for (int i = 0; i < size ; i++)
        {
            if(price >= current->price)
            {
                if (current->next == NULL)
                {
                    current->next = newTextbook;
                }
                else if (price <= current->next->price)
                {
                    newTextbook->next = current->next;
                    current->next = newTextbook;
                    break;
                }
            }
            current = current -> next;
        }
    }
    size++; // Increasing the size
}

/*MARK: removeBook*/
void Store::removeBook(string ISBN)
{//Removing book using ISBN
    Textbook *current = head;
    Textbook *isbn = NULL;
    while (current != NULL)
    {
        if (current -> ISBN.compare(ISBN) == 0)
        {
            cout << "\n isbn match \n";
            if (current != NULL)
            {
                isbn -> next = current -> next;
                current -> next = NULL;
                delete current; // frees the memory and also calls the Destructor if the class.
                /* free(current); // only free memory */
                size--; // Reducing the size after remove a newTextbook
                break;
            }
            else if (current == head)
            {
                head = head->next;
                delete current;
                size--;
                cout << "current == head \n";
                break;
            }
        }
        else
            cout << "\n ibsn NOT match \n";
        isbn = current;
        current = current -> next;
    }
    
}

/*MARK: print()*/
void Store::print()
{//Printing all books in order from beginning to end
    
    Textbook *current = head;
    
    if (Store::isEmpty())
    {// Checking is Store is EMPTY
        cout << "\nStore print() is EMPTY\n";
    }
    else
    {
        if (current != NULL)
        {
            int book = 1;
            for (int i = 0; i<size; i++)
            {
                cout << "\nBook number: " << book++;
                cout << "\n Title:  " << current -> title
                     << "\n Author: " << current -> author
                     << "\n ISBN:   " << current -> ISBN
                     << "\n Price:  $" << current -> price << endl;
                current = current -> next;
            }
            cout << endl;
        }
        else
            cout << "\n--- print() is NOT working\n" ;
    }
}

/*MARK: print(char startingLetter)*/
void Store::print(char startingLetter)
{//Printing all books whose title starts with the input character
    
    Textbook * current = head;
    
    if (current != NULL)
    {
        int bookCount = 0;
        for (int i = 0; i < size; i++)
        {
            if(current->title[0] == startingLetter)
            {
                bookCount++;
                cout << "Book number: " << bookCount << endl ;
                cout << "\n Title:  " << current -> title
                     << "\n Author: " << current -> author
                     << "\n ISBN:   " << current -> ISBN
                     << "\n Price:  $" << current -> price << endl;
            }
            current = current -> next;
        }
        cout << endl;
    }
    else
        cout <<"\n--- print(char startingLetter) is NOT working\n";
}

/*MARK: print(string author)*/
void Store::print(string author)
{//Printing all books of an author
    Textbook *current = head;

    if (current != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            if(current -> author.compare(author) == 0)
            {
                cout<< "\n Title:  " << current -> title
                    << "\n ISBN:   " << current -> ISBN
                    << "\n Price:  $" << current -> price << endl ;
            }
            current = current -> next;
        }
        cout << endl;
    }
    else
        cout << "\n--- print(string author) is NOT wokring\n";
}

/*MARK: getSize()*/
int Store::getSize()
{
    Textbook *current = head;

    int count = 0; // The number of books in the list

    while(current != NULL)
    {
        count++;
        current = current -> next;
    }
    return count; //returning the number of books in the list
}

/*MARK: isEmpty()*/
bool Store::isEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}
