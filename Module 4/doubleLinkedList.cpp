#include <iostream>
using namespace std;
class DListNode
{
  private:
    int value;
    DListNode* next;
    DListNode* prev;
  public:
    DListNode(int newValue)
    {
      value = newValue;
      prev = next = NULL;
    }
  friend class DoubleLinkedList;
};

class DoubleLinkedList
{
  private:
    DListNode* head;
    int size;
    
  public:
    DoubleLinkedList()
    {
      head = NULL;
      size = 0;
    }

    void push_back(int newValue)
    {
      DListNode* newNode = new DListNode(newValue);
      if(size == 0)
      {
        head = newNode;
      }
      else
      {
        DListNode* current = head;
        for(int i=0; i<size-1; i++)
          current = current->next;
        newNode->prev = current;
        current->next = newNode;
      }
      size++;
    }

    void push_front(int newValue)
    {
      DListNode* newNode = new DListNode(newValue);
      if(size == 0)
      {
        head = newNode;
      }
      else
      {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
      }
      size++;
    }

    void print()
    {
      DListNode* current = head;
      for(int i=0; i<size; i++)
      {
        cout << current->value << " ";
        current = current->next;
      }
      cout << endl;
    }

     void printBackward()
    {
       DListNode* current = head;
       for(int i=0; i<size-1; i++)
       {
         current = current->next;
       }
       for(int i=0; i<size; i++)
       {
         cout << current->value << " ";
         current = current->prev;
       }
       cout << endl;
     }
};

int main()
{

  DoubleLinkedList myDList; //this is the object of DoubleLinkedList

  myDList.push_back(5);
  myDList.push_back(1);

  myDList.print();

  myDList.push_front(7);
  myDList.push_front(6);

  myDList.print();
  myDList.printBackward();

  return 0;
}
