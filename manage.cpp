#include <iostream>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "matzip.h"
using namespace std;

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
	while(curr!=end(p) && curr->gu != str){
		curr=curr->next;
	}

	return curr;
}

//일부 문자열이 일치하는 구를 찾는 함수
pNode findGu(pList p, pNode curr, string str) {
	
	while((curr->gu).find(str) == string::npos && curr != end(p)){
		curr=curr->next;
	}

	return curr;
}

//
pNode findType(pList p, string str) {
	
	pNode curr = begin(p);
	while(curr!=end(p) && curr->type != str){
		
		curr=curr->next;
	}

	return curr;
}

//일부 문자열이 일치하는 음식 타입을 찾는 함수
pNode findType(pList p, pNode curr, string str) {
	
	while((curr->type).find(str) == string::npos && curr != end(p)){
		curr=curr->next;
	}

	return curr;
}


pNode findName(pList p, string str){
    pNode curr = begin(p);
    while(curr != end(p) && curr->name != str ){
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
void insert(pNode x, string namex, string gux, string typex, string timex, string breakTimex, string offx, string ratingx, string bookx) {
	pNode node = new Node{ namex, gux, typex, timex, breakTimex, offx, ratingx, bookx , x->prev, x };
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


//끝에 노드를 추가하는 함수
void push_back(pList p, string namex, string gux, string typex, string timex, string breakTimex, string offx, string ratingx, string bookx) {
	insert(end(p), namex, gux, typex, timex, breakTimex, offx, ratingx, bookx);
}

//정보를 보여주는 함수
void show(pList p){
	if (empty(p)) {
		cout << "\n정보가 없습니다.\n";
		return;
	}

	pNode curr=begin(p);
	while(curr!=end(p)){
		cout << curr->name << "\t" << curr->gu << "\t" << curr->type << "\t" << curr->time <<"\t"<<curr->breakTime<< "\t" << curr->off<<"\t" << curr->rating << "\t" << curr->book <<"\n";
		//printf("%-40s %-20s %-8s %-11s   %-2s   %-4s   %-s   %-11s\n", (curr->name).c_str(), (curr->gu).c_str(), (curr->type).c_str(), (curr->time).c_str(), (curr->breakTime).c_str(), (curr->off).c_str(), (curr->rating).c_str(), (curr->book).c_str());
		curr = curr->next;
	}
}

//update해주는 함수
void update(pList p, string namex, string gux, string typex, string timex, string breakTimex , string offx, string ratingx, string bookx){
	
	pNode N = findName(p, namex);
	N->name = namex;
	N->gu = gux;
	N->type = typex;
	N->time = timex;
	N->off = offx;
	N->rating = ratingx;
	N->book = bookx;
	N->breakTime = breakTimex;

	return;
}

//review를 입력하는 함수
void insertReview(pList p, string namex){
	pNode curr;
	curr = findName(p, namex);
	if(curr == end(p)) cout << "맛집이 존재하지 않습니다\n\n";
	else {
		string revi;
		cout << "리뷰를 입력해주세요 ";
		getline(cin, revi);
		(curr->review).push_back(revi);
		curr->reviewNum=(curr->review).size();
	}

}

//구, 맛집 이름, 음식 종류로 찾아서 출력하는 함수
void search(pList p, string str, pNode (*find)(pList, pNode, string)){
	printf("이름\t지역\t종류\t영업시간\t브레이크타임\t휴무일\t별점\t예약유무\n");
	pNode node=begin(p);
	while(node != end(p)){
		node = find(p, node, str);
		if(node == end(p)) break;
		cout << node->name << "\t" << node->gu << "\t" << node->type << "\t" << node->time <<"\t"<<node->breakTime<< "\t" << node->off<<"\t" << node->rating << "\t" << node->book <<"\n";
		//printf("%-40s %-20s %-8s %-11s   %-2s   %-4s   %-s   %-11s\n", (node->name).c_str(), (node->gu).c_str(), (node->type).c_str(), (node->time).c_str(), (node->breakTime).c_str(), (node->off).c_str(), (node->rating).c_str(), (node->book).c_str());
		node = node->next;
	}
}

//맛집 리뷰를 보는 함수
void readReview(pList p, string namex){
	pNode curr =findName(p,namex);
	if(curr!=end(p)){
		for(int i=0; i<(curr->review).size(); i++){
			cout << "*" << (curr->review)[i] << "\n";
		}
	}
	else
		cout << "맛집을 찾을 수 없습니다\n\n";

	return;
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
	cout << "0.  종료";
	cout << "\n\n원하는 메뉴의 번호를 입력해주세요 ";
    cin >> menu;
	cin.ignore();
    return menu;
}

void FileLoad(pList p){
    ifstream file("matziplist.csv");
    if (file.is_open()) {
        pNode curr = begin(p);

        string line;
        while (getline(file, line)) {
            
            vector<string> values;
            stringstream ss(line);
            string value;
            while (getline(ss, value, ',')) {
                values.push_back(value);
            }

            push_back(p, values[0], values[1], values[2], values[3], values[7], values[4],values[5], values[6]);
        }

        file.close();
        cout << "파일 로딩 성공." << endl;
    } else {
        cout << "파일 로딩 오류." << endl;
    }
}

void FileSave(pList p, string filename){
	ofstream file(filename);
    if (file.is_open()) {
        pNode curr = begin(p);
        while (curr != end(p)) {

            file << curr->name << ",";
            file << curr->gu << ",";
            file << curr->type << ",";
            file << curr->time << ",";
            file << curr->off << ",";
            file << curr->rating << ",";
            file << curr->book << ",";
            file << curr->breakTime << endl;

            curr = curr->next;
        }

        file.close();
        cout << "파일 저장 성공." << endl;
    } else {
        cout << "파일 저장 오류." << endl;
    }
}
