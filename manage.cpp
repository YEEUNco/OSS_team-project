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
    Node(string n = "name", string g = "gu", string ty = "type", string ti = "time", string o = "off",string ra = "rating", int re = 0, string bo = "book", string bre = "break",Node* p = nullptr, Node* x = nullptr){
		name = n;
		gu = g;
		type = ty;
		time = ti;
		off = o;
		rating = ra;
		reviewNum = re;
		book = bo;
		breakTime = bre;
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


pNode findName(pList p, string str){

    pNode curr = begin(p);
    while(curr != end(p) && curr->name != str)
        curr = curr->next;

	return curr;
}

bool empty(pList p) {
	return begin(p) == end(p);
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
void insert(pNode x, string namex, string gux, string typex, string timex, string offx, string ratingx, int reviewNumx, string bookx, string breakTimex) {
	pNode node = new Node{ namex,gux, typex, timex, offx, ratingx, reviewNumx, bookx,  breakTimex , x->prev, x };
	x->prev = x->prev->next = node;

}
//delete기능
void erase(pList p, pNode x) {	// checks if x is tail or not
	if (x == end(p)) return;
	erase(x);
}

//crude의 delete 기능
void pop_front(pList p) {
	
	if (!empty(p)) erase(begin(p));
}

// crude의 delete기능
void pop_back(pList p) {
	if (!empty(p)) erase(end(p)->prev);
}

//crud의 delete기능
void pop(pList p, string str) {
	//cout << "your code here\n";
	erase(p, findName(p, str));
}
//모두 delete
void pop_all(pList p, string str) {
	for (pNode c = begin(p); c != end(p); c = c->next) {
		if(c->name == str) {
			pNode n = c->prev;
			erase(p,c);
			c = n;
		}
	} 	// O(n) 
} // faster version

/*
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
*/

void push_back(pList p, string namex, string gux, string typex, string timex, string offx, string ratingx, int reviewNumx, string bookx, string breakTimex) {
	insert(end(p), namex, gux, typex,timex, offx, ratingx, reviewNumx,bookx, breakTimex );
}
/* 굳이 필요없는 기능..
void push(pList p, string namex, string gux, string typex, string timex, string offx, string ratingx, int reviewNumx, string bookx, string breakTimex, int x) {
	
	//cout << "your code here: use find()\n";
	if(findName(p,namex)==end(p)) return;
	insert(findName(p,namex),namex,gux, typex, timex, offx, ratingx, reviewNumx, bookx, breakTimex );

}
*/

void show(pList p){
	if (empty(p)) {
		cout << "\n\t정보가 없습니다.\n";
		return;
	}

	pNode curr=begin(p);
	while(curr!=end(p)){
		cout << curr->name << "\t" << curr->gu << "\t" << curr->type << "\t" << curr->time <<"\t"<<curr->breakTime<< "\t" << curr->off<<"\t" << curr->rating << "\t" << curr->book <<"\n";
		curr = curr->next;
	}



}

void FileLoad(pList p){

}

void FileSave(pList p){
	
}

int main(){
	
}