#include <iostream>
#include "LinkedList.h"

// Bool that will run all our link list tests
bool test_linklist();

int main()
{
	// Creates a linked list and insters 5 integers from 1-5
	LinkedList<int> LinkedList_A;
	LinkedList_A.insert(1);
	LinkedList_A.insert(2);
	LinkedList_A.insert(3);
	LinkedList_A.insert(4);
	LinkedList_A.insert(5);
	
	std::cout << "Insert node 1, 2, 3 , 4 , 5 " << std::endl;

	// Prints out the maximum value from the 5 nodes inserted
	std::cout << "\nMaximum value in the list is: " << LinkedList_A.maximum()->get_data() << std::endl;

	// Prints out the minimum value from the 5 nodes inserted
	std::cout << "Minimum value in the list is: " << LinkedList_A.minimum()->get_data() << std::endl;

	// Finds 1 at the head node, removes it and displays 2 as the new head
	std::cout << "\nHead found at node " << LinkedList_A.get_head()->get_data() << std::endl;
	std::cout << "Remove head " << std::endl;
	LinkedList_A.remove(LinkedList_A.get_head()->get_data());
	std::cout << "New head: " << LinkedList_A.get_head()->get_data() << std::endl;


	// Finds the node storing 3, removes it, displays it as removed then displays the new next node
	std::cout << "\n3 found at node: " << LinkedList_A.find(3) << std::endl;
	LinkedList_A.remove(3);
	std::cout << "Remove node " << std::endl;
	std::cout << "3 found at node: " << LinkedList_A.find(3) << std::endl;
	std::cout << "New next node: " << LinkedList_A.find(2)->get_next()->get_data() << std::endl;


	// Finds 5 at the tail, removes it and displays the new tail
	std::cout << "\nTail found at node " << LinkedList_A.get_tail()->get_data() << std::endl;
	LinkedList_A.remove(LinkedList_A.get_tail()->get_data());
	std::cout << "Remove tail" << std::endl;
	std::cout << "New tail: " << LinkedList_A.get_tail()->get_data() << std::endl;

	std::cout << "\nCurrent nodes:" << std::endl;
	// Auto decides what the data type is for us
	// Current will be head
	auto current = LinkedList_A.get_head();
	
	// While loop that checks if current is not null pointer, if it's not, current will equal next
	while (current != nullptr)
	{
		std::cout << current->get_data() << std::endl;
		current = current->get_next();
	}

	// Prints what the tail node is, removes it and then prints the new tail node
	std::cout << "\nTail found at node: " << LinkedList_A.get_tail()->get_data() << std::endl;
	LinkedList_A.remove(4);
	std::cout << "Remove tail" << std::endl;
	std::cout << "New tail: " << LinkedList_A.get_tail()->get_data() << std::endl;

	// Prints what the last node left on the list is, removes it, then prints the empty head and tail
	std::cout << "\nLast node: " << LinkedList_A.get_head()->get_data() << std::endl;
	LinkedList_A.remove(2);
	std::cout << "Remove last node" << std::endl;
	std::cout << "New head: " << LinkedList_A.get_head() << std::endl;
	std::cout << "New tail: " << LinkedList_A.get_tail() << std::endl;

	std::cout << "\n\n\n###############################" << std::endl;
	std::cout << "Linked List Testing" << std::endl;
	std::cout << "###############################" << std::endl;

	// Function that runs all our tests
	test_linklist();

	system("pause");
	return 0;

}

// Code testing
bool test_linklist()
{
	// The bool will = pass if it is true
	bool pass = true;
	LinkedList<int> test_list;

	// Tests to see if the head is a null pointer, if not, it will fail
	if (test_list.get_head() == nullptr)
	{
		std::cout << "\nIs the head a null pointer?: " << std::endl;
		std::cout << "Test passed! " << std::endl;
	}
	else
	{
		std::cout << "\nIs the head a null pointer?: " << std::endl;
		std::cout << "Test failed! " << std::endl;
		pass = false;
	}

	// Tests to see if the tail is a null pointer, if not, it will fail 
	if (test_list.get_tail() == nullptr)
	{
		std::cout << "\nIs the tail a null pointer?: " << std::endl;
		std::cout << "Test passed! " << std::endl;
	}
	else
	{
		std::cout << "\nIs the tail a null pointer?: " << std::endl;
		std::cout << "Test failed! " << std::endl;
		pass = false;
	}

	// Inserts a 6 to the linked list, checks to see if 6 is not a null pointer, if it is, test failed
	test_list.insert(6);
	if (test_list.find(6) != nullptr)
	{
		std::cout << "\nInsert 6, is 6 not a null pointer now?: " << std::endl;
		std::cout << "Test passed! " << std::endl;
	}
	else
	{
		std::cout << "\nInsert 6, is 6 not a null pointer now?: " << std::endl;
		std::cout << "Test failed! " << std::endl;
		pass = false;
	}

	// Test to see if the first node inserted to the linked list is set to head, if not, test failed
	if (test_list.get_head() != nullptr && test_list.get_head()->get_data() == 6)
	{
		std::cout << "\nIs 6 set as the head?: " << std::endl;
		std::cout << "Test passed! " << std::endl;
	}
	else
	{
		std::cout << "\nIs 6 set as the head?: " << std::endl;
		std::cout << "Test failed! " << std::endl;
		pass = false;
	}

	// Inserts a 7 to the linked list, checks to see if 7 is not a null pointer, if it is, test failed
	test_list.insert(7);
	if (test_list.find(7) != nullptr)
	{
		std::cout << "\nInsert 7, is 7 not a null pointer now?: " << std::endl;
		std::cout << "Test passed! " << std::endl;
	}
	else
	{
		std::cout << "\nInsert 7, is 7 not a null pointer now?: " << std::endl;
		std::cout << "Test failed! " << std::endl;
		pass = false;
	}
	// Test to see if the after the first node inserted, do the next nodes get set to tail, if not, test failed
	if (test_list.get_tail() != nullptr && test_list.get_tail()->get_data() == 7)
	{
		std::cout << "\nIs 7 inserted into the tail and not the head?: " << std::endl;
		std::cout << "Test passed! " << std::endl;
	}
	else
	{
		std::cout << "\nIs 7 inserted into the tail and not the head?: " << std::endl;
		std::cout << "Test failed! " << std::endl;
		pass = false;
	}


	// Adds 3 new nodes
	test_list.insert(8);
	test_list.insert(9);
	test_list.insert(10);

	// Check if new node can be found in the list
	// Check if new node inserted at the tail
	if (test_list.get_tail()->get_data() == 10)
	{
		std::cout << "\nInsert 8, 9, then 10. Is 10 the tail now?: " << std::endl;
		std::cout << "Test passed! " << std::endl;
	}
	else 
	{
		std::cout << "\nInsert 8, 9, then 10. Is 10 the tail now?: " << std::endl;
		std::cout << "Test failed! " << std::endl;
		pass = false;
	}

	// Checks if 8 was inserted properly
	if (test_list.find(8) != nullptr)
	{
		std::cout << "\nIs 8 not a null pointer?: " << std::endl;
		std::cout << "Test passed! " << std::endl;
	}
	else
	{
		std::cout << "\nIs 8 not a null pointer?: " << std::endl;
		std::cout << "Test failed! " << std::endl;
		pass = false;
	}

	// Checks if 9 was inserted properly
	if (test_list.find(9) != nullptr)
	{
		std::cout << "\nIs 9 not a null pointer?: " << std::endl;
		std::cout << "Test passed! " << std::endl;
	}
	else
	{
		std::cout << "\nIs 9 not a null pointer?: " << std::endl;
		std::cout << "Test failed! " << std::endl;
		pass = false;
	}

	// Checks if the minimum function finds the real minimum value
	if (test_list.minimum()->get_data()==6)
	{
		std::cout << "\nIs the minimum value 6?: " << std::endl;
		std::cout << "Test passed! " << std::endl;
	}
	else
	{
		std::cout << "\nIs the minimum value 6?: " << std::endl;
		std::cout << "Test failed! " << std::endl;
		pass = false;
	}

	// Checks if the maximum function finds the real maximum value
	if (test_list.maximum()->get_data()==10)
	{
		std::cout << "\nIs the maximum value 6?: " << std::endl;
		std::cout << "Test passed! " << std::endl;
	}
	else
	{
		std::cout << "\nIs the maximum value 6?: " << std::endl;
		std::cout << "Test failed! " << std::endl;
		pass = false;
	}


	// Remove at the middle
	test_list.remove(7);

	if (test_list.get_head()->get_next()->get_data() != 7)
	{
		std::cout << "\nRemoves 7 in the middle, is 7 properly removed?: " << std::endl;
		std::cout << "Test passed! " << std::endl;
	}

	else
	{
		std::cout << "\nRemoves 7 in the middle, is 7 properly removed?: " << std::endl;
		std::cout << "Test failed! " << std::endl;
		pass = false;
	}

	// Removes at the head
	test_list.remove(test_list.get_head()->get_data());
	
	if (test_list.get_head()->get_data() != 6)
	{
		std::cout << "\nRemoves 6 at the head, is 6 properly removed?: " << std::endl;
		std::cout << "Test passed! " << std::endl;
	}
	else 
	{
		std::cout << "\nRemoves 6 at the head, is 6 properly removed?: " << std::endl;
		std::cout << "Test failed! " << std::endl;
		pass = false;
	}

	// Removes at the tail
    test_list.remove(test_list.get_tail()->get_data());

	if (test_list.get_tail()->get_data() != 10)
	{
		std::cout << "\nRemoves 10 at the tail, is 10 properly removed?: " << std::endl;
		std::cout << "Test passed! " << std::endl;
	}
	else
	{
		std::cout << "\nRemoves 10 at the tail, is 10 properly removed?: " << std::endl;
		std::cout << "Test failed! " << std::endl;
		pass = false;
	}

	// Removes the last nodes
	test_list.remove(test_list.get_tail()->get_data());
	test_list.remove(test_list.get_head()->get_data());

	if (test_list.get_head() == nullptr && test_list.get_tail() == nullptr)
	{
		std::cout << "\nRemoves the last nodes, are the last nodes properly removed? " << std::endl;
		std::cout << "Test passed!" << std::endl;
	}
	else
	{
		std::cout << "\nRemoves the last nodes, are the last nodes properly removed? " << std::endl;
		std::cout << "Test failed! " << std::endl;
		pass = false;
	}

	return pass;

}