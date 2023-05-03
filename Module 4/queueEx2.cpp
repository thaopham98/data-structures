#include <iostream>
#define MAX 10

using namespace std;

class myQueue{
	private:
		int array[MAX];
		int head;
		int tail;
		
		int size;
	
	public:
		myQueue(){
			head = tail = 0;
			size = 0;
		}
	
		void enqueue(int newValue){
			if(size < MAX){
				array[tail] = newValue;
				tail++;
				tail = tail % MAX;
				
				size++;
			}
			else{
				cout << "The queue is full!" << endl;
			}
		}
		
		void dequeue(){
			if(size > 0){
				head++;
				head = head % MAX;
				size--;
			}else{
				cout << "The queue is empty!" << endl;
			}
		}
		
		void print(){
			int ind = head;
			for(int i=0; i<size; i++){
				cout << array[ind] << " ";
				ind = (ind + 1)%MAX;
			}
			cout << endl;
		}
	
};


int main(){
	
	myQueue q1;
	
	q1.enqueue(3);
	q1.enqueue(1);
	q1.enqueue(7);
	q1.print();
	
	q1.enqueue(8);
	q1.enqueue(6);
	q1.print();
	
	q1.dequeue();
	q1.dequeue();
	q1.print();
	
	q1.enqueue(4);
	q1.dequeue();
	q1.print();

	return 0;
}
