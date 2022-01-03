#include <iostream>
using namespace std;

#ifndef _intDLLNode
#define _intDLLNode
class intDLLNode{	    

	friend class intDLList;
	
	protected:
		int info;
		intDLLNode *next;
		intDLLNode *prev;
	public:
		intDLLNode(int el=0,intDLLNode *nextPtr=nullptr,intDLLNode *prevPtr=nullptr);   

};	
#endif
