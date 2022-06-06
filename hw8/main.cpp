#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node(int n) {
			data = n;
			next = NULL;
		}
};

class LinkedList {
	private:
		Node* head;
		
	public:
		LinkedList() {
			head = NULL;
		}
		
		~LinkedList() {
			Node* p;
			while(head != NULL) {
				p = head;
				head = head -> next;
				cout << "free([" << p->data << "])->";
				delete p;
			}
			cout << "null" << endl;
		}
		
		void append_node(int newData) {
			Node* A_node = new Node(newData);
			if(head != NULL) {
			    Node* list = head;
			    while(list->next != NULL) {
				    list = list->next;
			    }
			    list->next = A_node;
			    
			    Node* current = head;
			    for(;current != NULL;current = current->next) {
				    cout << "[" << current->data << "]->";
			    }
				cout << "null" << endl;
			} else {
				head = A_node;
				cout << "[" << head->data << "]->null" << endl;
			}
		}
		
		void del_node(int n) {
			Node* new_head = new Node(0);
			new_head->next = head;
			
			Node* p = new_head;
			for(int i = 0;i < n;i++) {
				p = p->next;
			}
			Node* D_node = p->next;
			p->next = D_node->next;
			delete D_node;
			
			Node* current = head;
			for(;current != NULL;current = current->next) {
				cout << "[" << current->data << "]->";
			}
			cout << "null" << endl;
		}
};

int main() {
	LinkedList mylink;
	mylink.append_node(0);
	mylink.append_node(1);
	mylink.append_node(2);
	mylink.append_node(3);
	mylink.del_node(1);
	return 0;
}