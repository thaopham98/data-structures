#include <iostream>

using namespace std;

class ListNode{
	public:
		int value;
		ListNode* next;
	
	public:
		ListNode(int newValue){
			value = newValue;
			next = NULL;
		}
};

int main(){
	
	int a = 5;
	
	ListNode* head;
	head = new ListNode(5);
	
	head->next = new ListNode(7);
	
	
	
	return 0;
}