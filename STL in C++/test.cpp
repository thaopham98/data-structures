#include<iostream>
#include<vector>
#include<deque> //double ended queue

#include<list> //double linked list
#include<forward_list> //single linked list

using namespace std;

int main(){

	
	//not costly
	list<int> myList = {8,9,10,5,1,3,7};
	myList.push_back(15);
	

	for(auto iter=myList.end(); iter != myList.begin(); iter--){
		cout << *iter << " ";
	}
	cout << endl;

	for(auto number:myList){
		cout << number << " ";
	}
	cout << endl;



	//costly
	vector<int> myVec = {8,9,10,5,1,3,7};
	myVec.push_back(15);

	cout << myVec[3] << endl;


	/*	
	//size of myArr[] is always 7
	int myArr[7] = {8,9,10,5,1,3,7};
	
	//capacity of myVec is flexible
	vector<int> myVec = {8,9,10};
	
	myVec.push_back(5);
	myVec.push_back(1);
	myVec.push_back(3);
	myVec.push_back(7);
		
	for(int i=0;i<myVec.size(); i++){
		cout << myVec[i] << " ";
	}
	cout << endl;
	
	myVec.insert(myVec.begin()+3,15);
	
	for(auto number:myVec){
		cout << number << " ";
	}
	cout << endl;
	
	myVec.erase(myVec.begin()+5);
	
	//accessing elements of a container by an iterator object
	for(auto iter=myVec.begin(); iter!=myVec.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
	*/
	return 0;
}