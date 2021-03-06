/* Written by Haralambos D. Kokkinakos
 * 
 * This program creates classes for doubly linked nodes and lists.
 * When ran, the main file prompts user to create a list, sorted list, queue, or stack.
 * Each data structure has their own unique functions which the user can select.
 * Trying to print an empty list or delete a value that does not exist will force a crash.
 * It is recommended to exit the program before re-executing the program.
 * 
 * If you have any questions, please email me at hkokkina@villanova.edu
 */

#include <intDLLNode.h>
#include <intDLList.h>

int main()
{
	int num,a,b;
	intDLList list1 = intDLList();

	while(1) 
//loop for asking user which list type to make. This is probably not necessary but just in case
//the program falls through the switch statements, it will help debug.
		
	{
		//ask user which list to make and enter first switch
		cout << "(1) Create simple (unsorted) list." << endl;
		cout << "(2) Create sorted list." << endl;
		cout << "(3) Create queue (FIFO)." << endl;
		cout << "(4) Create Stack (LIFO)." << endl;
		cout << "(5) Exit." << endl;
		cin >> a;
	
		
		switch(a)
		{

			case 1:
				//simple list
				while(1){ //loop to stay within simple list
				//options for simple list
				cout << "(1) Enter integer for insertion at head of list." << endl;
				cout << "(2) Enter integer for insertion at tail of list." << endl;
				cout << "(3) Display and delete integer from head of list." << endl;
				cout << "(4) Display and delete integer from tail of list." << endl;
				cout << "(5) Search for integer in list, and delete that node." << endl;
				cout << "(6) Display contents of list from head to tail, in order." << endl;
				cout << "(7) Exit program." << endl;
				cin >> b;
				

				switch(b)
				{
					
					case 1:
						//ask for number to add to head
						cout << "Enter a number: ";
						cin >> num;
						list1.addToHead (num);
						break;
					case 2:
						//ask for number to add to tail
						cout << "Enter a number: ";
						cin >> num;
						list1.addToTail (num);
						break;
					case 3:
						//try to delete from head and catch incase error. errors defined in list header file.
						try{ num = list1.deleteFromHead (); }
						catch(int error)
						{
							if(error==1){
								cerr << "Empty List." << endl;
								return 0;
							}
							if(error==2){
								cerr << "Number not in list, cannot delete." << endl;
								return 0;
							}

						}
						cout << "Deleted " << num << " from the list." << endl;
							break;
					case 4:
						//try to delete from tail and catch incase error. 
						try{ num = list1.deleteFromTail (); }
						catch(int error)
						{
							if(error==1){
								cerr << "Empty List." << endl;
								return 0;
							}
							if(error==2){
								cerr << "Number not in list, cannot delete." << endl;
								return 0;
							}

						}
						cout << "Deleted " << num << " from the list." << endl;


						break;
					case 5:
						//try to find and delete node. catch if node not in list.
						cout << "What number would you like to delete?" << endl;
						cin >> num;
						try{ list1.deleteNode (num); } 
						catch(int error)
						{
							if(error==1){
								cerr << "Empty List." << endl;
								return 0;
							}
							if(error==2){
								cerr << "Number not in list, cannot delete." << endl;
								return 0;
							}

						}
						break;
					case 6:
						//print list 
						try{ list1.printlist ();}
						catch(int error)
						{
							if(error==1){
								cerr << "Empty List." << endl;
								return 0;
							}
							if(error==2){
								cerr << "Number not in list, cannot print." << endl;
								return 0;
							}

						}
						break;
					case 7:
						return 0; break;
				}
				}
				break;
			case 2:
				//sorted list switch case
				while(1){ //loop to stay within sorted list
				//ask user what to do and store for switch
				cout << "(1) Enter integer for sorted insertion (increasing order) into list." << endl;
				cout << "(2) Search and delete integer, if present in list." << endl;
				cout << "(3) Display contents of sorted list of integers, in increasing order." << endl;
				cout << "(4) Exit program." << endl;
				cin >> b;
								
				switch(b)
				{

					case 1: //add number
						cout << "What number would you like to add?" << endl;
						cin >> num;
						list1.addSorted (num);
						break;
					case 2: //remove number. If not in list, catch and throw error.
						cout << "What number would you like to remove?" <<endl;
						cin >> num;
						try{ list1.deleteNode (num);}
						catch(int error)
						{
							if(error==1){
								cerr << "Empty List." << endl;
								return 0;
							}
							if(error==2){
								cerr << "Number not in list, cannot delete." << endl;
								return 0;
							}

						}

				
						break;
					case 3: //print list
						try{ list1.printlist ();}
						catch(int error)
						{
							if(error==1){
								cerr << "Empty List." << endl;
								return 0;
							}
							if(error==2){
								cerr << "Number not in list, cannot print." << endl;
								return 0;
							}

						}
						break;
					case 4:
						return 0;break;

				}
					
				}
				
				break;
			case 3:
				//queue
				while(1){ //loop to stay within queue
				cout << "(1) Enqueue." << endl;
				cout << "(2) Dequeue." << endl;
				cout << "(3) Print Queue." << endl;
				cout << "(4) Exit program." << endl;				
				cin >> b;
				switch(b)
				{
					int num;
					case 1: //enqueue
						cout << "what number would you like to queue?" << endl;
						cin >> num;
						list1.addToTail (num);


						break;
					case 2: //dequeue
						try{ num = list1.deleteFromHead ();}
						catch(int error)
						{
							if(error==1){
								cerr << "Empty List." << endl;
								return 0;
							}
							if(error==2){
								cerr << "Number not in list, cannot delete." << endl;
								return 0;
							}

						}
						cout << "dequeued " << num << endl;
						
						break;
					case 3: //print
						try{ list1.printlist ();}
						catch(int error)
						{
							if(error==1){
								cerr << "Empty List." << endl;
								return 0;
							}
							if(error==2){
								cerr << "Number not in list, cannot print." << endl;
								return 0;
							}

						}

						break;
					case 4: 
						return 0; break;
				}
				}
				break;
			case 4:
				//stack
				while(1){ //loop to stay within stack
				cout << "(1) Push." << endl;
				cout << "(2) Pop." << endl;
				cout << "(3) Print stack." << endl;
				cout << "(4) Exit program." << endl;				
				cin >> b;
				switch(b)
				{

					case 1: //push
						cout << "what number would you like to push?" << endl;
						cin >> num;
						list1.addToHead (num);
						break;
					case 2: //pop
						try{ num = list1.deleteFromHead ();}
						catch(int error)
						{
							if(error==1){
								cerr << "Empty List." << endl;
								return 0;
							}
							if(error==2){
								cerr << "Number not in list, cannot delete." << endl;
								return 0;
							}

						}
						cout << "popped " << num << endl;
						

						break;
					case 3: //print
						try{ list1.printlist ();}
						catch(int error)
						{
							if(error==1){
								cerr << "Empty List." << endl;
								return 0;
							}
							if(error==2){
								cerr << "Number not in list, cannot print." << endl;
								return 0;
							}

						}


						break;
					case 4:
						return 0; break;



				}
				}
				break;		
				
			case 5:
				return 0;break;
		}
	}
	
}

