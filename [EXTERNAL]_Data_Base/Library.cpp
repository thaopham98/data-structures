#include <iostream>
#include "Library.h"


using namespace std;

Library::Library(){ ///start with default constructor
	head == NULL;
}

void Library::addBook(string title, string author, string ISBN){					///curr unif idev

Textbook *curr, *unif, *idev;             // three s so we can go through the linked list

int set= 0;

curr= new Textbook();

curr-> author = author;

curr-> title = title;

curr-> ISBN= ISBN;
 
curr-> next = NULL;

if(head == NULL){
	head=curr;
}
else{
	unif=head;
	while(unif != NULL){
	if(unif -> title.compare(title)>=0)	{
		if(unif == head){
			
		curr -> next = unif;
		head = curr;
		}
		

    else { 
    curr->next=unif;
    idev->next=curr;
	}
	
	set=1;
	break;
}
idev=unif;
unif=unif->next;
}
if(set==0)
	idev->next= curr;

else 
set=0;
}
}
void Library::removeBook(string ISBN){
	Textbook *curr, *idev;
	curr = head;
	idev = NULL;
	while(curr != NULL){
		if(curr ->ISBN.compare(ISBN)==0){
			if(idev==NULL){
				head=head->next;
				curr->next = NULL;
				delete(curr);
				break;
			}
else{
	
	idev->next=curr->next;
	curr->next=NULL;
	delete(curr); // delete so we can save space in memory 
		break;
	
}
}

idev=curr;
curr= curr->next;

}
}
void Library::print(){
	Textbook *curr;
	curr=head;
	while(curr != NULL)
	{
		cout<<"Title : "<<curr->title<< "\n Author : " <<curr->author <<"\n ISBN :"<<curr->ISBN<< endl;
		curr=curr->next;
	}
}

void Library::print(char startingLetter)
{
	Textbook*curr;
	
	curr = head;
	
	while(curr != NULL){
		if(curr->title[0]= startingLetter)
	{
		cout<<"The Title is found :" << curr -> title<<"\n Author :"<< curr -> author<<"\n ISBN : "<< curr -> ISBN<< endl;
	}   
		curr= curr->next;
		}	
		}
	//All novel of author printed out.
	
	void Library::print(string author)
	{
		Textbook *curr;
		curr=head;
		while(curr != NULL)
		{
			if(curr->author.compare(author)==0)
			{
				cout<< "Found Title: "<<curr->title<<"\n Author: "<< curr->author<<"\n ISBN : "<< curr->ISBN <<endl;
				break;
			}
			curr= curr->next;
			
			}
}
		
		//return book at given index
		Textbook Library::at(int index){
			Textbook *curr;
			int count =0;
			curr= head;
		
		while(curr != NULL && count !=index)
		{
			curr= curr->next;
			count++;
		}
		return *curr;
}   


	int Library::getSize(){
		Textbook*curr;
		int count= 0;
		curr=head;
		while(curr != NULL)
		{
			count++;
			curr= curr->next;
		}
		return count;
	}
	// True if empty, returns false otherwise
	bool Library::isEmpty(){
		if(head==NULL){
		
		return true;
		
		return false;
	   }
	   else(cout<< "Thank you for using"<<endl);
	   return 0;
}




