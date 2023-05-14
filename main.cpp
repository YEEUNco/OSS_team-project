#include <iostream>
#include <algorithm>
#include <cassert>
#include <iomanip>

using namespace std;

struct Node{
    string name;
    string gu;
    string type;
    string time;
    string off;
    string rating;
	int reviewNum;
	string book;
	string breakTime;
    vector<string> review;
    Node* prev;
    Node* next;
    Node(Node* p = nullptr, Node* x = nullptr){
        prev = p; next = x;
    }
};

struct List{
    Node* head;
    Node* tail;
    List(){
        head = new Node{}; tail = new Node{};
        head->next = tail; tail->prev = head;
    }
};

using pNode = Node*;
using pList = List*;

pNode begin(pList p) {
	return p->head->next;
}

pNode end(pList p) {
	return p->tail;          // not tail->next
}

pNode last(pList p) {
	return p->tail->prev;
}

pNode findGu(pList p, string str) {
	
	pNode curr = begin(p);
	while(curr!=end(p) && curr->gu != str){
		curr=curr->next;
	}

	return curr;
}

pNode findType(pList p, string str) {
	
	pNode curr = begin(p);
	while(curr!=end(p) && curr->type != str){
		curr=curr->next;
	}

	return curr;
}

pNode findType(pList p, string str) {
	
	pNode curr = begin(p);
	while(curr!=end(p) && curr->type != str){
		curr=curr->next;
	}

	return curr;
}

pNode findName(pList p, string str){

    pNode curr = begin(p);
    while(curr != end(p) && curr->name != str)
        curr = curr->next;
}

void clear(pList p) {
	if (empty(p)) return;

	//DPRINT(cout << ">clear: ";);
	pNode curr = begin(p);
	while (curr != end(p)) {
		pNode prev = curr;
		curr = curr->next;
		delete prev;
	}

	p->head->next = p->tail;			// set tail at head
	p->tail->prev = p->head;			// set head at tail
	cout << "\n\tCleared...\n";
}

bool empty(pList p) {
	return begin(p) == end(p);
}

int size(pList p) {
	int count = 0;
	for (pNode c = begin(p); c != end(p); c = c->next)
		count++;
	return count;
}


void erase(pNode x) {
	x->prev->next = x->next;
	x->next->prev = x->prev;
	delete x;
}
//이부분도 고칠 것!!
void insert(pNode x, ) {
	pNode node = new Node{ val, x->prev, x };
	x->prev = x->prev->next = node;

}

void erase(pList p, pNode x) {	// checks if x is tail or not
	if (x == end(p)) return;
	erase(x);
}

void pop_front(pList p) {
	
	if (!empty(p)) erase(begin(p));
}

// removes the last node in the list. O(1)
void pop_back(pList p) {
	if (!empty(p)) erase(end(p)->prev);
}

void pop(pList p, string str) {
	//cout << "your code here\n";
	erase(p, findName(p, str));
}

void pop_all(pList p, string str) {
	for (pNode c = begin(p); c != end(p); c = c->next) {
		if(c->name == str) {
			pNode n = c->prev;
			erase(p,c);
			c = n;
		}
	} 	// O(n) 
} // faster version

void pop_backN(pList p, int N) {

	int psize = size(p);
	if (N <= 0 || N > psize) N = psize;
	for (int i = 0; i < N; i++) {
		if (i % 10000 == 0)
			cout << setw(7) << "\r\tpopping [" << psize - i - 1 << "]        ";
		pop_back(p);
	}
	cout << "\n";

}

void push_back(pList p, int val) {
	insert(end(p), val);
}
//push 이 부분 고치기!!!
void push(pList p, int val, int x) {
	
	//cout << "your code here: use find()\n";
	if(find(p,x)==end(p)) return;
	insert(find(p,x), val);

}

int main(){
    
}