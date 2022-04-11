#include <iostream>
using namespace std;

struct node{											
	int data;
	node *prev;
	node *next;
};

node *head, *tail, *cur, *newNode, *del, *afterNode;

void createCircularDoubleLinkedList(int data){
	head = new node();
	head->data = data;
	head->prev = head;
	head->next = head;
	tail = head;
}

void addFirst(int data){
	if (head == NULL){
    	cout << "Circular Double Linked List belum dibuat!";
	}else{
		newNode = new node();
	    newNode->data = data;
	    newNode->prev = tail;
	    newNode->next = head;
	    head->prev = newNode;
	    tail->next = newNode;
		head = newNode;
  }
}

void addLast(int data){
	if (head == NULL){
		cout << "Circular Double Linked List belum dibuat!";
	}else{
	    newNode = new node();
	    newNode->data = data;
	    newNode->prev = tail;
	    newNode->next = head;
	    tail->next = newNode;
	    head->prev = newNode;
	    tail = newNode;
	}
}

void addMiddle( int data, int posisi ){
	if (head == NULL){
    	cout << "Circular Double Linked List belum dibuat!";
	}else{

    if (posisi == 1){
      cout << "Posisi bukan posisi tengah!" << endl;
    }else if (posisi < 1){
      cout << "Posisi diluar jangkauan!" << endl;
    }else{
    	newNode = new node();
    	newNode->data = data;
    	cur = head;
    	int nomor = 1;
    	while( nomor <  posisi - 1){
    		cur = cur->next;
        	nomor++;
      	}

    	afterNode = cur->next;
    	newNode->prev = cur;
    	newNode->next = afterNode;
    	cur->next = newNode;
    	afterNode->prev = newNode;
    }
  }
}

void removeFirst(){
	if (head == NULL){
    	cout << "Circular Double Linked List belum dibuat!";
	}else{
		del = head;
    	head = head->next;
    	tail->next = head;
    	head->prev = tail;
    	delete del;
	}
}

void removeLast(){
	if (head == NULL){
		cout << "Circular Double Linked List belum dibuat!";
	}else{
    	del = tail;
    	tail = tail->prev;
    	tail->next = head;
    	head->prev = tail;
    	delete del;
	}
}

void removeMiddle(int posisi){
	if (head == NULL){
		cout << "Circular Double Linked List belum dibuat!";
  }else{
    if (posisi == 1){
    	cout << "Posisi bukan posisi tegah!" << endl;
    }else if (posisi < 1){
    	cout << "Posisi diluar jangkauan!" << endl;
    }else{
    	int nomor = 1;
    	cur = head;
		while(nomor < posisi - 1){
        	cur = cur->next;
        	nomor++;
    	}
    	del = cur->next;
    	afterNode = del->next;
    	cur->next = afterNode;
    	afterNode->prev = cur;
    	delete del;
    }
  }
}

void printNode()
{
	if (head == NULL){
    	cout << "Circular Double Linked List belum dibuat!";
	}else{
    	cout << "INFO DATA" << endl;
    	cur = head;
    	while (cur->next != head){
    		cout << "Data : " << cur->data << endl;
    		cur = cur->next;
    	}
    cout << "Data : " << cur->data << endl;
  }
}

void searchNode(node **head, int id){
    int currentID = 1;
    node *cur = *head;
    while (cur->next != 0 && currentID != id){
        cur = cur->next;
        currentID++;
    }
    cout << cur->data << " ditemukan pada data ke " << currentID;
}

int main(){
	cout << "Membuat Data Circular Double Linked List" << endl;
	createCircularDoubleLinkedList(1);
	printNode();
	
	cout << "\nInsert First" << endl;
	addFirst(9);
	printNode();
	
	cout << "\nInsert Last" << endl;
	addLast(20);
	printNode();
	
	cout << "\nDelete First" << endl;
	removeFirst();
	printNode();
	
	cout << "\nInsert Last" << endl;
	addLast(14);
	printNode();
	
	cout << "\nDelete Last" << endl;
	removeLast();
	printNode();
	
	cout << "\nInsert Before" << endl;
	addMiddle(27, 2);
	printNode();
	
	cout << "\nDelete Before data ke 3" << endl;
	removeMiddle(2);
	printNode();
	
	cout << "\nSearching data : 20" << endl;  
	searchNode(&head, 2);
}
