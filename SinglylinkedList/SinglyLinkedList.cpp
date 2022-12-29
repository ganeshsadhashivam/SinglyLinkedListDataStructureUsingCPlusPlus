/*
1 Understanding of What is Linked List & Singly Linked List
2. C++ Objects & Classes
3. Pointers in C++
4. Dynamic Memory allocation
DISCLAIMER: There are different ways to implement Linked List (& pretty much all other DS) so this is the way we will go ahead.

Singly Linked List Operations -
1. appendNode()
2. prependNode()
3. insertNodeAfter ()
4. deleteNodeByKey()
5. updateNodeByKey()
6. print ()
*/

#include<iostream>

using namespace std;



class Node {
public:
	int key;
	int data;
	Node* next;

	Node() {
		key = 0;
		data = 0;
		next = NULL;
	}

	Node(int k, int d) {
		key = k;
		data = d;
	}
};


class SinglyLinkedList {

public:
	Node* head;

	SinglyLinkedList() {
		head = NULL;
	}

	//node which takes address as an argument this is pass by address
	SinglyLinkedList(Node *n) {

		head = n;
	}

	//check if node exists using key value
	//Traversing the Linked List 
	Node* nodeExists(int k) {

		Node* temp = NULL;

		Node* ptr = head;
		while (ptr != NULL) {
			
			if (ptr->key == k) {
				temp = ptr;
			}

			ptr = ptr->next;
		}

		return  temp;
	}


	//Append node new node

	void appendNode(Node *n) {

		if (nodeExists(n->key)!=NULL) {

			cout << "Node already exists with key value : " << n->key << " Append another node with different key value" << endl;

		}
		else {
			if (head == NULL) {

				head = n;
				cout << "Node appended " << endl;
			}
			else {
				Node* ptr = head;
				while (ptr->next != NULL) {
					ptr = ptr->next;
				}

				ptr->next = n;

				cout << "Node Appended " << endl;

			}
		}

	}

	//prepend node Attach a node at the start

	void prependNode(Node* n) {
		
		if (nodeExists(n->key) != NULL) {

			cout << "Node already exists with key value : " << n->key << " Append another node with different key value" << endl;

		}
		else {
			n->next = head;
			head = n;
			cout << "Node Prepended" << endl;
		}
	}


	//Insert a node after a particular node in the list

	void insertNodeAfter(int k, Node  *n) {

		Node* ptr = nodeExists(k);

		if (ptr == NULL) {

			cout << "No node Exists with key value : " << k << endl;
		}
		else {
			if (nodeExists(n->key) != NULL) {
				cout << "Node already exists with key value : " << n->key << " Append another node with different key value" << endl;
			}
			else {
				n->next = ptr->next;
				ptr->next = n;
				cout << "Node Inserted" << endl;
			}
		}


	}

	//deleting a node with key

	void deleteNodeByKey(int k) {

		if (head == NULL) {

			cout << "Singly Linked List already Empty Cant Delete" << endl;
		}
		else if (head != NULL) {

			if (head->key == k) {
				head = head->next;
				cout << "Node UNLINKED with keys value : " << k << endl;
			}
			else {

				Node* temp = NULL;
				Node* prevptr = head;
				Node* currentptr = head->next;

				while (currentptr != NULL) {

					if (currentptr->key == k) {

						temp = currentptr;
						currentptr = NULL;
					}
					else {

						prevptr = prevptr->next;
						currentptr = currentptr->next;

					}
				}
				if (temp != NULL) {

					prevptr->next = temp->next;
					cout << "Node UNLINKED with keys value : " << k << endl;
				}
				else {
					cout << "Node Doessn't exists with the key value : " << k << endl;
				}
			}
		}
	}

	//update node in the Linked List
	void updateNodeByKey(int k, int d) {
		
		Node* ptr = nodeExists(k);
		if (ptr != NULL) {

			ptr->data = d;
			cout << "Node Data Updated Successfully" << endl;

		}
		else {
			cout << "Node doesn't exists with the key value : " << k << endl;
		}
	}

	//printting 
	void printList() {
		if (head == NULL) {
			cout << "No Nodes in Singly Linked List ";

		}
		else {
			cout << endl << "singly linked list values : ";
			Node* temp = head;

			while (temp != NULL) {
				cout << "(" << temp->key << "," << temp->data << ") --> ";
				temp = temp->next;
			}
		}
	}

};


int main() {

	SinglyLinkedList s;
	int option;
	int key1, k1, data1;

	do {
		cout << "\nWhat operation do you want to perform? Select Option number. Enter to exit." << endl;
		cout << "1. appendNode()" << endl;
		cout << "2. prependNode ()" << endl;
		cout << "3. insertNodeAfter ()" << endl;
		cout << "4. deleteNodeByKey()" << endl;
		cout << "5. updateNodeByKey()" << endl;
		cout << "6. print ()" << endl;
		cout << "7. Clear Screen" << endl << endl;
		cin >> option;
		//dynamic memory allocation stored in heap
		Node* n1 = new Node();
		switch (option)
		{
		case 0:
			break;
		case 1:
			cout << "Append Node Operation \nEnter kev & data of the Node to be Appended" << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s.appendNode(n1);

			break;

		case 2:
			cout << "Prepend Node Operations \nEnter key & data of the Node to be Prepended " << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s.prependNode(n1);
			break;

		case 3:
			cout << "Insert Node After Operation \n Enter key of existing Node after which you want to Insert this New node: " << endl;
			cin >> k1;
			cout << "Enter key & data of the New Node first: " << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s.insertNodeAfter(k1, n1);
			break;

		case 4:
			cout << "Delete Node By Key Opeartion - \n Enter key of the node to be deleted: " << endl;
			cin >> k1;
			s.deleteNodeByKey(k1);
			break;

		case 5:
			cout << "Update Node By Key Operation - \n Enter key  & New Data to be updated " << endl;
			cin >> key1;
			cin >> data1;
			s.updateNodeByKey(key1, data1);
			break;

		case 6:
			s.printList();
			break;

		case 7:
			system("cls");
			break;

		default:
			cout << "Enter Proper option number " << endl;

		}

	}while (option != 0);

	return 0;
}