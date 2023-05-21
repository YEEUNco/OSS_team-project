#include <iostream>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
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
    Node(string n = "name", string g = "gu", string ty = "type", string ti = "time", string bre = "break", string o = "off", string ra = "rating", string bo = "book", Node* p = nullptr, Node* x = nullptr){
		name = n;
		gu = g;
		type = ty;
		time = ti;
		off = o;
		rating = ra;
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

pNode begin(pList p);
pNode end(pList p);
pNode last(pList p);
pNode findGu(pList p, string str);
pNode findGu(pList p, pNode curr, string str);
pNode findType(pList p, string str);
pNode findType(pList p, pNode curr, string str);
pNode findName(pList p, string str);
pNode findName(pList p ,pNode curr, string str);
bool empty(pList p);
void clear(pList p);
int size(pList p);
void erase(pNode x) ;
void insert(pNode x, string namex, string gux, string typex, string timex, string breakTimex, string offx, string ratingx, string bookx);
void erase(pList p, pNode x);
void pop_front(pList p);
void pop_back(pList p);
void pop(pList p, string str);
void pop_all(pList p, string str) ;
void push_back(pList p, string namex, string gux, string typex, string timex, string breakTimex, string offx, string ratingx, string bookx);
void show(pList p);
void update(pList p, string namex, string gux, string typex, string timex, string breakTimex , string offx, string ratingx, string bookx);
void insertReview(pList p, string namex);
void search(pList p, string str, pNode (*find)(pList, pNode, string));
void readReview(pList p, string namex);
int selectmenu();
void FileLoad(pList p);
void FileSave(pList p, string filename);