#include <iostream>
#include <fstream>
#include <string>
#include "Store.h"

using namespace std;

Store myStore;

//Read the dataset file and loads myStore list
void loadDataset(string fileName){
	ifstream inFile;
    string fullPath = "/Applications/Studying/Github/data-structures/homework4_CSCI3400";
    
	inFile.open((fullPath + fileName).c_str());
    cout << fullPath + fileName<<endl;
    
    //check if file is successfully opened
    if(inFile.is_open())
        cout<<"File is opened"<<endl;
    else
        cout<<"Failed to open file"<<endl;

	string line;

	while(getline(inFile,line)){
		int ind1 = line.find("#");
		int ind2 = line.find("#",ind1+1);
		int ind3 = line.find("#",ind2+1);

		string title = line.substr(0,ind1);
		string author = line.substr(ind1+1, ind2-ind1-1);
		string ISBN = line.substr(ind2+1,ind3-ind2-1);
		float price = stof(line.substr(ind3+1));


		//Here we add the new book. Please make sure your function name matches
		myStore.addBook(title,author,ISBN,price);
            
	}
    
    inFile.close();
}

//Just for convenience...
void continueMessage(string message){
	cout << message << endl;
	cout << "Press Enter to continue.." << endl; cin.get();
}

int main() {
	string fileName = "dataset.txt";
	loadDataset(fileName);

	continueMessage("Dataset file is loaded to the program!");

	//---------------------------------------------------------------------------
	myStore.print();
	continueMessage("All books in the store are listed!");

	//---------------------------------------------------------------------------
	string title = "Total Recall: How the E-Memory Revolution Will Change Everything";
	string author = "C. Gordon Bell";
	string ISBN = "592968760-9";
	float price = 44.44;
	myStore.addBook(title,author,ISBN,price);

	continueMessage("New book, with " + ISBN + " ISBN is added to the store.");
	//---------------------------------------------------------------------------

	myStore.print(title[0]); string s(1, title[0]);
	continueMessage("All books, whose title starts with "+s+", are listed.");
	//---------------------------------------------------------------------------

	author = "W. Richard Stevens";
	myStore.print(author);
	continueMessage("All books, whose author is "+author+", are listed.");
	//---------------------------------------------------------------------------
    string ISBN1 = "539224508-0";
    myStore.removeBook(ISBN);
    
    continueMessage("The book, with " + ISBN + " ISBN is removed from the store.");
    
    cout << "Removing ISBN 1 ";
    myStore.removeBook(ISBN1);
    
	//---------------------------------------------------------------------------

	myStore.print();
	continueMessage("All books in the store are listed!");
	//---------------------------------------------------------------------------

	int size = myStore.getSize();
	cout << "There are currently " << size << " books in the store." << endl;

	return 0;
}
