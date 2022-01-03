#include <intDLList.h>

//constructor
intDLList::intDLList(){
	head=tail=nullptr;
}

//destructor
intDLList::~intDLList(){
	while(head!=nullptr){ //loop through list, move head up one, and delete the previous head
		intDLLNode* tmp=head;
		head=head->next;
		delete tmp;
	}
}

//is Empty function
bool intDLList::isEmpty() {
	return (head==nullptr); //if head is null, return true. else false.
}

void intDLList::addToHead(int el) {
	if(isEmpty()){ //if list is empty, add a new node and set it to head and tail.
		head = new intDLLNode(el);
		tail=head;
	}
	else{ //when there is already something in the list, add a node to head.
		intDLLNode* tmp = head;
		head= new intDLLNode(el,tmp);
		tmp->prev=head; //set the old head's previous to the new head.
	}
}

void intDLList::addToTail(int el){
	if(isEmpty()){ //if the list is empty, add a new node and set head and tail to point to it.
		tail = new intDLLNode(el);
		head =tail;
	}
	else{ //otherwise, add a new node and set it to head, then update the old tail's next ptr.
		intDLLNode* tmp=tail;
		tail = new intDLLNode(el,nullptr,tmp);
		tmp->next=tail;
	}
}

int intDLList::deleteFromHead(){
	int val;
	if(isEmpty()){ //exception for trying to delete in empty list
		throw(EMPTY_LIST);
	}
	if(head->next==nullptr){ //if theres only one node, delete it and update head/tail.
		val=head->info;
		delete head; head = tail = nullptr;
	}
	else{ //when theres more than one node, delete the head then update the head to be the next node.
		val=head->info;
		intDLLNode* tmp = head;
		head = head->next;
		delete tmp;
	} 
	return val;
}

int intDLList::deleteFromTail(){
	int val;
	if(isEmpty()){ //empty list exception
		throw(EMPTY_LIST);
	}
	if(tail->prev==nullptr){ //if only one node, delete it.
		val=tail->info;
		delete tail; head = tail = nullptr;

	}
	else{ //when theres more than one node, delete tail and update necessary pointers.
		val = tail->info;
		intDLLNode* tmp = tail;
		tail = tail->prev;
		tail->next=nullptr;
		delete tmp;
	} 
	return val;
}


bool intDLList::isInList(int el) const{
	intDLLNode* tmp;
	//positioning for loop to get node thats equal to el.
	for(tmp=head;tmp!=nullptr && tmp->info!=el;tmp=tmp->next){cout << tmp->info << endl;}
	return(tmp!=nullptr);
}

void intDLList::deleteNode(int el){
	intDLLNode* tmp;
	if(isInList(el)){ //if the number is in the list...
		for(tmp=head;tmp!=nullptr && tmp->info!=el;tmp=tmp->next); //positioning loop to get node with el.
		if(head==tail){ //if list is 1 long, delete node and set to nullptr.
			head = tail = nullptr;
		}
		else if(tmp==tail){ //if the node is at the tail, delete it and update tail pointers
			tmp->prev->next=nullptr;
			tail=tmp->prev;
		}
		else if(tmp == head){ //if the node is at the head, delete it and update head ptr
			tmp->next->prev=nullptr;
			head = tmp->next;
		} 
		else{ //normal case where node in middle of list
			
			tmp->prev->next=tmp->next;//update pointers to go over the node.
			tmp->next->prev=tmp->prev;
		} 
	}
	else{
		throw(NOT_IN_LIST);
	} 
	delete tmp;

}


void intDLList::addSorted(int el){
	intDLLNode* tmp; 
	if(isEmpty()){ //if list empty, add node and update head and tail
		head = tail = new intDLLNode(el);
	}
	else{ 
		for(tmp=head;tmp->next!=nullptr && tmp->info<el;tmp=tmp->next);
		//this positions tmp at the number that is greater than el.
		//therefore, we must insert the new node before tmp.
		if(tmp==head && tmp->info >= el){ //if tmp is at head, insert before head and update head ptr.
			addToHead (el);
			tmp->prev=head;

		}
		else if(tmp==tail){ //when tmp is at tail, add to tail and update.
			addToTail(el);
			tmp->next=tail;
		}
		else{ //otherwise, look through list and add node without updating head or tail.
			intDLLNode* tmp2=tmp->prev;
			tmp2->next= new intDLLNode(el,tmp,tmp2);
			tmp->prev=tmp2->next;
		}

	}

} 

void intDLList::printlist(){
	intDLLNode* tmp;
	//loop through list and print all numbers so long as list not empty.
	if(isEmpty()){ throw(EMPTY_LIST); } 
	for(tmp=head;tmp!=nullptr;tmp=tmp->next){
		cout << tmp->info << " ";
	}
	cout << endl;
	delete tmp;
	
}










