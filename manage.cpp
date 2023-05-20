#include <iostream>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <string>

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

//첫번째 노드를 찾는 함수
pNode begin(pList p) {
	return p->head->next;
}

//tail을 찾아주는 함수
pNode end(pList p) {
	return p->tail;          // not tail->next
}

//마지막 노드를 찾는 함수
pNode last(pList p) {
	return p->tail->prev;
}

//구를 찾는 함수
pNode findGu(pList p, string str) {
	
	pNode curr = begin(p);
	while(curr!=end(p) && curr->str != str){
		curr=curr->next;
	}

	return curr;
}

//일부 문자열이 일치하는 구를 찾는 함수
pNode findGu(pList p, pNode curr, string str) {
	
	while((curr->name).find(str) == string::npos && curr != end(p)){
		curr=curr->next;
	}

	return curr;
}

//
pNode findType(pList p, string str) {
	
	pNode curr = begin(p);
	while(curr!=end(p) && curr->str != str){
		
		curr=curr->next;
	}

	return curr;
}

//일부 문자열이 일치하는 음식 타입을 찾는 함수
pNode findType(pList p, pNode curr, string str) {
	
	while((curr->name).find(str) == string::npos && curr != end(p)){
		curr=curr->next;
	}

	return curr;
}


pNode findName(pList p, string str){
    pNode curr = begin(p);
    while(curr != end(p) && curr->str != str ){
		curr = curr->next;
	}
        

	return curr;
}

//일부 문자열이 일치하는 음식점 이름을 찾는 함수
pNode findName(pList p ,pNode curr, string str) {
	
	while((curr->name).find(str) == string::npos && curr != end(p)){
		curr=curr->next;
	}

	return curr;
}
//노드가 0개인지 확인해주는 함수
bool empty(pList p) {
	return begin(p) == end(p);
}
//모든 노드를 지우는 함수
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
//노드의 개수를 찾는 함수
int size(pList p) {
	int count = 0;
	for (pNode c = begin(p); c != end(p); c = c->next)
		count++;
	return count;
}

//실질적으로 노드 지우는 함수
void erase(pNode x) {
	x->prev->next = x->next;
	x->next->prev = x->prev;
	delete x;
}

//노드를 삽입해주는 함수
void insert(pNode x, string namex, string gux, string typex, string timex, string offx, string ratingx, int reviewNumx, string bookx, string breakTimex) {
	pNode node = new Node{ namex,gux, typex, timex, offx, ratingx, reviewNumx, bookx,  breakTimex , x->prev, x };
	x->prev = x->prev->next = node;

}
//delete기능
void erase(pList p, pNode x) {	// checks if x is tail or not
	if (x == end(p)){ 
		return;
	}
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
//끝에 노드를 추가하는 함수
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
//정보를 보여주는 함수
void show(pList p){
	if (empty(p)) {
		cout << "\n정보가 없습니다.\n";
		return;
	}

	pNode curr=begin(p);
	while(curr!=end(p)){
		cout << curr->name << "\t" << curr->gu << "\t" << curr->type << "\t" << curr->time <<"\t"<<curr->breakTime<< "\t" << curr->off<<"\t" << curr->rating << "\t" << curr->book <<"\n";
		curr = curr->next;
	}
//update해주는 함수
void update(pList p, string namex, string gux, string typex, string timex, string offx, string ratingx, int reviewNumx, string bookx, string breakTimex){
	pNode = N;
	forUpdate = findName(p, namex);
	N->name = namex;
	N->gu = gux;
	N->type = typex;
	N->time = timex;
	N->off = offx;
	N->rating = ratingx;
	N->reviewNum = reviewNumx;
	N->book = bookx;
	N->breakTime = breakTimes;

}



}
//메뉴 선택할 수 있는 함수
int selectmenu(){
    int menu;
    printf("\n*** 맛집 리스트 ***\n");
    cout << "1.  맛집 등록하기\n";
	cout << "2.  맛집 리스트 보기\n";
	cout << "3.  맛집 정보 업데이트 하기\n";
	cout << "4.  맛집 지우기\n";
	cout << "5.  맛집 불러오기\n";
	cout << "6.  맛집 파일로 만들기\n";
	cout << "7.  맛집 별점과 후기 작성하기\n";
	cout << "8.  맛집 후기 조회하기\n";
	cout << "9.  맛집 이름으로 검색하기\n";
	cout << "10. 맛집 지역으로 검색하기\n";
	cout << "11. 맛집 종류로 검색하기\n";
	cout << "0. 종료";
    cin >> menu;
    return menu;
}

void FileLoad(pList p){

}

void FileSave(pList p){
	
}

int main(){
	pList p;


	while(1){
		int menu = selectmenu();
		if(menu==0){
			break;
		}
		else if(menu == 1){
			string namex;
			string gux;
			string typex;
			string timex;
			string offx;
			string ratingx;
			string bookx;
			string breakTimex;
			int num = 0;

			cout << "맛집 이름을 입력해주세요 ";
			cin >> namex;
			cout << "맛집의 구를 입력해주세요 ";
			cin >> gux;
			cout << "맛집의 음식 종료를 입력해주세요 ";
			cin >> typex;
			cout << "맛집의 영업시간을 입력해주세요 ";
			cin >> timex;
			cout << "맛집의 브레이크 타임을 입력해주세요 ";
			cin >> breakTimex;
			cout << "맛집의 휴무일을 입력해주세요 ";
			cin >> offx;
			cout << "맛집의 별점을 현황을 알려주세요 ";
			cin >> ratingx;
			cout << "맛집의 예약 유무를 알려주세요 ";
			cin >> bookx;

			push_back(p, namex, gux, typex, timex, offx, ratingx, num, bookx, breakTimex);
		}
		else if(menu == 2){
			printf("이름\t지역\t종류\t영업시간\t브레이크타임\t휴무일\t예약유무\t별점");
			show(p);
		}
		else if(menu == 3){
			string namex;
			string gux;
			string typex;
			string timex;
			string offx;
			string ratingx;
			string bookx;
			string breakTimex;
			int num = 0;

			cout << "맛집 이름을 입력해주세요 ";
			cin >> namex;
			cout << "맛집의 구를 입력해주세요 ";
			cin >> gux;
			cout << "맛집의 음식 종료를 입력해주세요 ";
			cin >> typex;
			cout << "맛집의 영업시간을 입력해주세요 ";
			cin >> timex;
			cout << "맛집의 브레이크 타임을 입력해주세요 ";
			cin >> breakTimex;
			cout << "맛집의 휴무일을 입력해주세요 ";
			cin >> offx;
			cout << "맛집의 별점을 현황을 알려주세요 ";
			cin >> ratingx;
			cout << "맛집의 예약 유무를 알려주세요 ";
			cin >> bookx;

			update(p, namex, gux, typex, timex, offx, ratingx, num, bookx, breakTimex);
		}
		else if(menu == 4){
			string namex;
			cout << "삭제할 맛집 이름을 입력해주세요";
			cin >> namex;
			pop(p, namex);
		}
		else if(menu == 5){

		}
		else if(menu == 6){

		}
		else if(menu == 7){

		}
		else if(menu == 8){

		}
		else if(menu == 9){
			string namex;
			cout << "조회할 이름을 입력하세요 ";
			cin >> namex;
			printf("이름\t지역\t종류\t영업시간\t브레이크타임\t휴무일\t예약유무\t별점");
			pNode node=begin(p);
			while(node != end(p)){
				node = findName(node, namex);
				cout << curr->name << "\t" << curr->gu << "\t" << curr->type << "\t" << curr->time <<"\t"<<curr->breakTime<< "\t" << curr->off<<"\t" << curr->rating << "\t" << curr->book <<"\n";
				curr = curr->next;
			}
		}
		else if(menu == 10){
			string gux;
			cout << "조회할 구을 입력하세요 ";
			cin >> gux;
			printf("이름\t지역\t종류\t영업시간\t브레이크타임\t휴무일\t예약유무\t별점");
			pNode node=begin(p);
			while(node != end(p)){
				node = findGu(node, gux);
				cout << curr->name << "\t" << curr->gu << "\t" << curr->type << "\t" << curr->time <<"\t"<<curr->breakTime<< "\t" << curr->off<<"\t" << curr->rating << "\t" << curr->book <<"\n";
				curr = curr->next;
			}
		}
		else if(menu == 11){
			string typex;
			cout << "조회할 종류을 입력하세요 ";
			cin >> typex;
			printf("이름\t지역\t종류\t영업시간\t브레이크타임\t휴무일\t예약유무\t별점");
			pNode node=begin(p);
			while(node != end(p)){
				node = findType(node, typex);
				cout << curr->name << "\t" << curr->gu << "\t" << curr->type << "\t" << curr->time <<"\t"<<curr->breakTime<< "\t" << curr->off<<"\t" << curr->rating << "\t" << curr->book <<"\n";
				curr = curr->next;
			}
		}
	}
}