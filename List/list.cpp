/**
	Thank you to
	A Comprehensive Guide To Singly Linked List Using C++
**/

#include <iostream>

struct node{
	int data;
	node *next;
};

class list{
	node *head, *tail;
	public:
		list(){
			//empty list
			head = NULL;
			tail = NULL;
		}

		void create_node(int value){
			node *newNode = new node;
			newNode->data = value;
			newNode->next = NULL;

			//if empty, head and tail point to new node
			if(head == NULL){
				head = newNode;
				tail = newNode;
			}
			else{
				//step 1: set old tail's next to newNode
				tail->next = newNode;
				tail = newNode;
			}
		}

		void display(){
			node *newNode = new node;
			newNode = head;
			while(newNode != NULL){
				std::cout << newNode->data << '\t';
				newNode = newNode->next;
			}
			std::cout << '\n';
		}

		void insert_start(int value){
			node *newNode = new node;
			newNode->data = value;
			newNode->next = head;
			head = newNode;
		}

		void insert_pos(int pos, int value){
			if(pos == 0){
				insert_start(value);
				return;
			}
			//50 -> 23 -> 10
			//determine the two nodes we will insert between
			node *prev;
			node *cur;
			node *newNode = new node;
			newNode->data = value;
			cur = head;
			//traverse to pos   
			                   //3
			for(int i = 0; i < pos; i++){
				prev = cur;
				if(cur->next != NULL){
					cur = cur->next;
				}
				else{
					//out of bounds
					return;
				}
			}

			prev->next = newNode;
			newNode->next = cur;

			if(newNode->next == NULL){
				tail = newNode;
			}
		}

		void delete_start(){
			node *deleted = head;
			head = head->next;
			delete deleted;
			deleted = NULL;
		}

		void delete_last(){
			node *prev;
			node *cur;
			cur = head;
			while(cur->next != NULL){
				prev = cur;
				cur = cur->next;
			}

			tail = prev;
			tail->next = NULL;
			delete cur;
			cur = NULL;
		}

		void delete_pos(int pos){
			node *prev = head;
			node *cur = head;
			for(int i = 0; i < pos; i++){
				prev = cur;
				cur = cur->next;
			}
			prev->next = cur->next;
			delete cur;
			cur = NULL;
		}

};

int main(){
	list test;
	test.create_node(34);
	test.create_node(40);
	test.create_node(56);
	test.display();
	test.delete_pos(1);
	test.delete_pos(1);
	test.display();


}