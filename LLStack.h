#ifndef __LLSTACK_H
#define __LLSTACK_H
class Node {
	int nodeData;
	Node* nextNode;

public:
	Node() {};

	void setData( int d ) {
		nodeData = d;
	};

	void setNext( Node* n ){
		nextNode = n;
	};

	int getData(){
		return nodeData;
	};

	Node* getNext(){
		return nextNode;
	};

};

class LLStack {
	Node *head;
	public:
		LLStack() {head = NULL;}
		void Print();
		void Push( int data );
		int Pop();
		bool isEmpty();
		int Peek();
};


void LLStack::Push( int data ){
	Node* newNode = new Node();
	newNode->setData(data);
	newNode->setNext(NULL);

	Node *tmp = head;

	if( tmp != NULL){
		while( tmp->getNext() != NULL){
			tmp = tmp->getNext();
		}

	tmp->setNext( newNode );
	}else{
		head = newNode;
	} 
}

int LLStack::Pop(){
	if(!isEmpty()){
		/*Check for a single element*/
		Node *tmp = head;

		if(tmp->getNext() == NULL){
			head = NULL;
			return tmp->getData();
		}else{
			while(tmp->getNext()->getNext() != NULL){
				tmp = tmp->getNext();
			}
		}

		int r = tmp->getNext()->getData();
		tmp->setNext(NULL);
		return r;
	}else{
		return -1;
	}
}

bool LLStack::isEmpty(){
	return (head == NULL);
}

/*void LLStack::Print(){
	Node *tmp = head;

	if(tmp == NULL){
		cout << "EMPTY" << endl;
		return;
	}else{
		if(tmp->getNext() == NULL){
			cout << tmp->getData();
			cout << "--> NULL" << endl;
		}else{
			while(tmp != NULL){
				cout << tmp->getData();
				cout << "-->";
				tmp = tmp->getNext();
			}
			cout << "NULL" << endl;
		}
	}
}*/

int LLStack::Peek(){
	if(!isEmpty()){
		Node *tmp = head;

		while(tmp->getNext() != NULL){
			tmp = tmp->getNext();
		}

		return tmp->getData();
	}
}
#endif