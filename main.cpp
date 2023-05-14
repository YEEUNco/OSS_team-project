#include <iostream>
#include <algorithm>

struct Node{
    string name;
    string gu;
    string type;
    string time;
    string off;
    string rating;
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
}

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
	DPRINT(cout << ">find val=" << val << endl;);
	
	pNode curr = begin(p);
	while(curr!=end(p) && curr->gu != str){
		curr=curr->next;
	}

	return curr;
}

pNode findType(pList p, string str) {
	DPRINT(cout << ">find val=" << val << endl;);
	
	pNode curr = begin(p);
	while(curr!=end(p) && curr->type != str){
		curr=curr->next;
	}

	return curr;
}

pNode findType(pList p, string str) {
	DPRINT(cout << ">find val=" << val << endl;);
	
	pNode curr = begin(p);
	while(curr!=end(p) && curr->Type != str){
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

	DPRINT(cout << ">clear: ";);
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

void erase(pList p, pNode x) {	// checks if x is tail or not
	if (x == end(p)) return;
	erase(x);
}

void pop_front(pList p) {
	DPRINT(cout << ">pop_front\n";);
	if (!empty(p)) erase(begin(p));
	DPRINT(cout << "<pop_front\n";);
}

// removes the last node in the list. O(1)
void pop_back(pList p) {
	DPRINT(cout << ">pop_back\n";);
	if (!empty(p)) erase(end(p)->prev);
	DPRINT(cout << "<pop_back\n";);
}

void pop(pList p, string str) {
	DPRINT(cout << ">pop val=" << val << endl;);
	//cout << "your code here\n";
	erase(p, findName(p, str));
	DPRINT(cout << "<pop\n";);
}

void pop_all(pList p, int val) {
	DPRINT(cout << ">pop_all val=" << val << endl;);

	for (pNode c = begin(p); c != end(p); c = c->next) {
		if(c->data == val) {
			pNode n = c->prev;
			erase(p,c);
			c = n;
		}
	} 	// O(n) 
} // faster version

void pop_backN(pList p, int N) {
	DPRINT(cout << ">pop_backN N=" << N << endl;);
	int psize = size(p);
	if (N <= 0 || N > psize) N = psize;
	for (int i = 0; i < N; i++) {
		if (i % 10000 == 0)
			cout << setw(7) << "\r\tpopping [" << psize - i - 1 << "]        ";
		pop_back(p);
	}
	cout << "\n";
	DPRINT(cout << "<pop_backN\n";);
}

void push_back(pList p, int val) {
	DPRINT(cout << ">push_back val=" << val << endl;);
	insert(end(p), val);
	DPRINT(cout << "<push_back\n";);
}
//push 이 부분 고치기!!!
void push(pList p, int val, int x) {
	DPRINT(cout << ">push val=" << val << endl;);
	//cout << "your code here: use find()\n";
	if(find(p,x)==end(p)) return;
	insert(find(p,x), val);
	DPRINT(cout << "<push\n";);
}

int main(){
    
}