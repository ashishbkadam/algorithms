#include "LinkedList.h"

#include <iostream>

using namespace std;

/*
	Algorithm insertNode(T value)
		pre: 'value' is the key to be added to the end of the existing linked list
    post: the node containing the key equal to 'value' will be the new tail of the list
		There are two cases:
		1. Adding a node to the empty list
		n = node(value)
		if head = NULL
      head <- n
			tail <- n
		else
			tail.next <- n
      tail <- n 
		end if
	end insertNode
*/
template <typename T>
ListNode<T>* LinkedList<T>::insertNode(T value)
{
	ListNode<T>* node = newNode(value);
	if(head == NULL)
	{
		head = tail = node;
	}
	else
	{
		tail->next = node;
		tail = node;
	}

	++count;
	return node;
}

/*
	Algorithm searchNode(value)
		pre: value is the key we need to search for in the list
    post: return address of the node if there is a node with key as value,
					else return NULL
    n <- head
		while n != NULL and n.key != value
			n <- n.next
		end while

		if n != NULL
			return true
		else 
			return false
		end if
	end searchNode
*/
template <typename T>
ListNode<T>* LinkedList<T>::searchNode(T value)
{
	ListNode<T>* node = head;
  while(node != NULL && node->key != value)
	{
		node = node->next;
	}

	if(node != NULL)
		return node;
	else 
		return NULL;
}

/*
	 There are 6 cases we need to account for when deleting an element from the list.
   	1. The list is empty.
		2. The element to be removed is the only node in the list.
		3. Removing the head node.
		4. Removing the tail node.
		5. Removing an element that is some where in the middle of the list.
		6. The value to remove doesn't exist in the list.


	Algorithm deleteNode(value)
		pre: value is the value to be removed from the list
		post: true, if the value removed from the list
					flase, else.

		if head = NULL
			//case 1
			return flase
    end if
    
		n <- head

    if(n.key = value)
			if(head = tail)
				//case 2
				head <- NULL
				tail <- NULL
			else
				//case 3
				head <- head.next
			end if
		
			return true
		end if

		while n.next != NULL and n.next.key != value
			n <- n.next
		end while

		if(n.next != NULL)
			if(n.next = tail)
				//case 5
				tail <- n
				n.next <- NULL
			else
				//case 6
				n.next <- n.next.next
			end if

			return true
		end if

		return false
	end deleteNode
*/
template <typename T>
bool LinkedList<T>::deleteNode(T value)
{
	if(head == NULL)
		return false;

	if(head->key == value)
	{
		if(head == tail)
		{
			head = tail = NULL;
		}
		else
		{
			head= head->next;
		}
		--count;
		return true;
	}
	
	ListNode<T>* node = head;

	while(node->next != NULL && node->next->key != value)
		node = node->next;
	if(node->next != NULL)
	{
		if(node->next == tail)
		{	
			tail = node;
			node->next = NULL;
		}
		else
			node->next = node->next->next;

		--count;
		return true;
	}

	return false;
}
//driver function

int main()
{
	LinkedList<int> list;
	cout<<list.insertNode(1)<<endl;
	cout<<list.head<<" "<<list.tail<<endl;
	cout<<list.insertNode(45)<<endl;
	cout<<list.head<<" "<<list.tail<<endl;
	cout<<list.insertNode(60)<<endl;
	cout<<list.head<<" "<<list.tail<<endl;
	cout<<list.insertNode(12)<<endl;
	cout<<list.head<<" "<<list.tail<<endl;
	cout<<list.insertNode(50)<<endl;
	cout<<list.head<<" "<<list.tail<<endl;
	cout<<list.getCount()<<endl;
  cout<<"***** Search ******"<<endl;
  cout<<list.searchNode(45)<<endl;
  cout<<list.searchNode(23)<<endl;
	cout<<"***** Delete ******"<<endl;
  cout<<list.deleteNode(50)<<endl;
  cout<<list.deleteNode(23)<<endl;
	cout<<list.getCount()<<endl;
	return 0;
}