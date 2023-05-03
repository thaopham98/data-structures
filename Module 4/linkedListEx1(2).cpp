#include <iostream>
using namespace std;
class ListNode
{
	private:
		int value;
		ListNode* next;
	public:
		ListNode(int newValue)
        {
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

		void insertAt(int newValue, int index)
        {
			ListNode* newNodePtr = new ListNode(newValue);
			if(index == 0){
				newNodePtr->next = head;
				head = newNodePtr;
			}
            else
            {
				ListNode* current = head;
				for(int i=0; i<index-1; i++)
                {
					current = current->next;
				}
				newNodePtr->next = current->next;
				current->next = newNodePtr;
			}
			size++;
		}
		void print()
        {
			ListNode* current = head;
			for(int i=0; i<size; i++)
            {
				cout << current->value << " ";
				current = current->next;
			}
			cout << endl;
		}
};

int main(){
	SingleLinkedList myList; //Create an empty linked list.
	myList.push_back(5);
	myList.push_back(1);
	myList.push_back(7);
	myList.push_back(4);
	myList.print();

	myList.push_back(6);
	myList.push_back(2);
	myList.print();

	myList.insertAt(9,4);
	myList.print();

	myList.insertAt(8,0);
	myList.print();

	return 0;
}
