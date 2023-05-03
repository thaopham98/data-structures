#ifndef Store_h
#define Store_h

#include <iostream>
#include <string>

using namespace std;

/*MARK: class Textbook*/
class Textbook
{
private:
    string title;
    string author;
    string ISBN;
    float price;
    Textbook* next;
public:
    Textbook(string newtitle, string newauthor, string newISBN, float newprice)
    {
        title = newtitle;
        author = newauthor;
        ISBN = newISBN;
        price = newprice;
        next = NULL;
    }
    void print();
    friend class Store;
};

/*MARK: class Store*/
class Store
{
private:
    Textbook* head;
    int size ;
public:
    Store();//Constructor
    
    void addBook(string title, string author, string ISBN, float price);

    void removeBook(string ISBN);
    
    void print();
    
    void print(char startingLetter);

    void print(string author);

    int getSize();

    bool isEmpty();
};
#endif /* Store_h */
