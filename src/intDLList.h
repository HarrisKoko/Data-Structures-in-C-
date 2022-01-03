#include <iostream>
using namespace std;
#include <intDLLNode.h>
#define EMPTY_LIST 1
#define NOT_IN_LIST 2

#ifndef _intDLList
#define _intDLList
class intDLList{
	
	public:
		intDLList();
		~intDLList();
		bool isEmpty();
		void addToHead(int el);
		void addToTail(int el);
		int deleteFromHead();
		int deleteFromTail();
		void deleteNode(int el);
		bool isInList(int el) const;
		void addSorted(int el);
		void printlist();


	private:
			intDLLNode *head,*tail;
		
};
#endif
