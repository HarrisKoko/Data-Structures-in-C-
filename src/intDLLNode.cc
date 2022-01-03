#include <intDLLNode.h>
//constructor for DLL node
intDLLNode::intDLLNode(int el,intDLLNode *nextPtr,intDLLNode *prevPtr){
	info=el;
	next=nextPtr;
	prev=prevPtr;
}
