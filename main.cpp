#include<iostream>
#include<conio.h>

#define NEWSINK 1
// macro
#define swap(x,y) {\
	x = x^y;\
	y = x^y;\
	x = x^y;\
	}while(0)

// smaller
#define small(x,y) (x)>(y)?y:x

using namespace std;

/* Implementing Min Heap */
class pQueue{
public:
	pQueue(){};
	pQueue(int, char*);
	~pQueue(){};
	// variable
	int qLength;
	// helper functions
	void push(int );
	int pop();
	void heapify();
	void printq();
private:
	int *heap;
	int occupancy;
	int vacIdx;
	bool priorityFlag;		// 0 for min heap and 1 for max heap
	// methods
	void swim(int);
	void sink(int);
};

// priority = "min" for min heap and "max" for max heap
pQueue::pQueue(int length , char *priority){
	heap = new int[length + 1];
	occupancy = 0;
	vacIdx = 1;
	qLength = length;
	priorityFlag = (priority == "min") ? 0 : 1 ;
	//cout<< (priorityFlag ? "max":"min")<<endl;
}

void pQueue::printq(){
	for(int i = 1 ; i <= occupancy ; i++){
		cout<<"HEAP is: "<<heap[i]<<endl;
	}
}

void pQueue::push(int member){
	if(occupancy == qLength){
		cout<<"Queue is full. Unable to perform push op"<<endl;
		return;
		//exit(1);
	}
	heap[vacIdx] = member;
	occupancy++;
	// balance heap : Insertion case
	swim(vacIdx);
	vacIdx++;
}

/* Every node check if its greater than its parent
	child node Idx = k => Parent node Idx = k/2
*/
void pQueue::swim(int idx){
	if(priorityFlag == 0){ // Min heap
		while(idx >1){
			if(heap[idx]<heap[idx/2]){
				swap(heap[idx] , heap[idx/2]);
			}
			else
				break;
			idx = idx/2;
		}
	}

	else{				// Max heap
		while(idx >1){
			if(heap[idx]>heap[idx/2]){
				swap(heap[idx] , heap[idx/2]);
			}
			else
				break;
			idx = idx/2;
		}
	}
}

int pQueue::pop(){
	if(occupancy == 0){
		cout<<"Queue is empty. Unable to perform pop op"<<endl;
		return NULL;
		//exit(1);
	}

	int member = heap[1];
	occupancy--;
	vacIdx--;
	swap(heap[1] , heap[vacIdx]);
	// balance heap : Deletion case
	sink(1);
	heap[vacIdx] = NULL;
	return member;
}

/* We exchange with larger of its 2 childeren*/
void pQueue::sink(int idx){
	if(priorityFlag == 0){ // Min heap
		int smallerChildId = 2*idx;
		while(2*idx <= occupancy){
			if(heap[2*idx] > heap[2*idx+1] && smallerChildId<occupancy)
				smallerChildId = 2*idx +1 ;
			if(heap[idx]>heap[smallerChildId]){
				swap(heap[idx] , heap[smallerChildId]);
			}
			else
				break;
			idx = smallerChildId;
			smallerChildId = 2*idx;
		}
	}
	else{					// Max heap
		int smallerChildId = 2*idx;
		while(2*idx <= occupancy){
			if(heap[2*idx] < heap[2*idx+1] && smallerChildId<occupancy)
				smallerChildId = 2*idx +1 ;
			if(heap[idx]<heap[smallerChildId]){
				swap(heap[idx] , heap[smallerChildId]);
			}
			else
				break;
			idx = smallerChildId;
			smallerChildId = 2*idx;
		}
	}
}


void pQueue::heapify(){
	for(int k= (occupancy)/2 ; k>=1 ; k--)
		sink(k);
}

int main(int argc , char **argv){
	pQueue q(10 , "min");
	q.push(5);
	q.push(3);
	q.push(1);
	q.push(4);
	q.push(2);
	q.push(2);
	/*
	cout<<(cmp(1,2))<<endl;
	int a = 10;
	int b = 20;
	swap(a,b);
	cout<<a<<b<<endl;
	*/
	//q.heapify();
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;

	q.push(7);
	q.push(3);
	q.push(1);
	q.push(5);
	q.push(2);
	q.push(2);
	//q.heapify();
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	getch();
}