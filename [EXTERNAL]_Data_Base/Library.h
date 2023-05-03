#include <iostream>


#include <string>

using namespace std;



class Textbook{
public:
	
	string title;
	
	string author;
	
	string ISBN;
	
	Textbook *next;   //Next Pointer
	
		
};
					
			
class Library{
		
		Textbook* head;
		
		public:

Library();
					
void addBook(string title, string author, string ISBN);

void removeBook(string ISBN);

void print();

void print(char startingLetter);

void print(string author);

Textbook at(int index);

int getSize();
	
bool isEmpty();
			
			
			
			
};
