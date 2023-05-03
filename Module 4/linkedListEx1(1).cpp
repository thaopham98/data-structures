#include <iostream>
using namespace std;
class ListNode
{
	private:
		int value;
		ListNode* next;
	
	public:
		ListNode(int newValue){
			value = newValue;
			next = NULL;
		}
	friend class SingleLinkedList;
};

class SingleLinkedList
{
	private:
		ListNode* head;
		int size;
	
	public:
		SingleLinkedList()
        {
			head = NULL;
			size = 0;
		}
		void push_back(int newValue)
        {
			ListNode* newNodePtr = new ListNode(newValue);
			if(head == NULL)
				head = newNodePtr;
			else{
				ListNode* current = head;
				for(int i=0; i<size-1; i++)
					current = current->next;
				current->next = newNodePtr;
			}
			size++;
		}
};
int main()
{
	SingleLinkedList myList; //Create an empty linked list.
	myList.push_back(5);
	myList.push_back(1);
	myList.push_back(7);
	myList.push_back(4);
	return 0;
}
