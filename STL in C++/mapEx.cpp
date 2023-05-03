#include <iostream>
#include <fstream>
#include <map>

#include <iomanip>

using namespace std;

int main(){

  map<string,string> myPhoneBook;

  ifstream inFile;
  inFile.open("phoneBook.txt");

  string name, phoneNumber;
  while(inFile >> name >> phoneNumber){

    //load the map. Name is the key, and number is value
    myPhoneBook[name] = phoneNumber;

    //cout << left << setw(12) << name << setw(15) << phoneNumber << endl;
  }

  myPhoneBook["Semih"] = "123-123-1234";


  string searchKey;
  cout << "Please enter name: ";
  cin >> searchKey;

  //not efficient. Linear Search O(n)
  for(auto record:myPhoneBook){
    if(record.first == searchKey){
      cout << "The number of " << searchKey << " is " << record.second << endl;
    }
  }

  //Efficient. Binary Search O(logn)
  auto it = myPhoneBook.find(searchKey);

  if(it == myPhoneBook.end()){
    cout << searchKey << " has no number in the phonebook" << endl;
  }
  else{
    cout << "The number of " << searchKey << " is " << it->second << endl;
  }


  return 0;
}
