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

int main(){
	pList p= new List();

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
			getline(cin,namex);
			cout << "맛집의 구를 입력해주세요 ";
			getline(cin,gux);
			cout << "맛집의 음식 종류를 입력해주세요 ";
			getline(cin,typex);
			cout << "맛집의 영업시간을 입력해주세요 ";
			getline(cin,timex);
			cout << "맛집의 브레이크 타임을 입력해주세요 ";
			getline(cin,breakTimex );
			cout << "맛집의 휴무일을 입력해주세요 ";
			getline(cin,offx);
			cout << "맛집의 별점을 현황을 알려주세요 ";
			getline(cin, ratingx);
			cout << "맛집의 예약 유무를 알려주세요 ";
			getline(cin,bookx);

			push_back(p, namex, gux, typex, timex, breakTimex, offx, ratingx, bookx);
		}
		else if(menu == 2){
			printf("이름\t지역\t종류\t영업시간\t브레이크타임\t휴무일\t별점\t예약유무\n");
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

			cout << "업데이트 할 맛집 이름을 입력해주세요 ";
			getline(cin,namex);
			cout << "맛집의 구를 입력해주세요 ";
			getline(cin,gux);
			cout << "맛집의 음식 종류를 입력해주세요 ";
			getline(cin,typex);
			cout << "맛집의 영업시간을 입력해주세요 ";
			getline(cin,timex);
			cout << "맛집의 브레이크 타임을 입력해주세요 ";
			getline(cin,breakTimex );
			cout << "맛집의 휴무일을 입력해주세요 ";
			getline(cin,offx);
			cout << "맛집의 별점을 현황을 알려주세요 ";
			getline(cin, ratingx);
			cout << "맛집의 예약 유무를 알려주세요 ";
			getline(cin,bookx);

			update(p, namex, gux, typex, timex, breakTimex, offx, ratingx, bookx);
		}
		else if(menu == 4){
			string namex;
			cout << "삭제할 맛집 이름을 입력해주세요 ";
			getline(cin,namex);
			pop(p, namex);
		}
		else if(menu == 5){
    		FileLoad(p);
		}
		else if(menu == 6){
			string filename;
			cout << "저장할 파일명을 입력하세요: ";
			cin >> filename;
			FileSave(p, filename);
		}
		else if(menu == 7){
			string namex;

			cout << "리뷰를 입력하고 싶은 맛집의 이름을 입력해주세요 ";
			getline(cin,namex);
			insertReview(p,namex);
			
			
		}
		else if(menu == 8){
			string namex;
			cout << "리뷰를 보고 싶은 맛집의 이름을 입력해주세요 ";
			getline(cin, namex);
			readReview(p, namex);
		}
		else if(menu == 9){
			string namex;
			cout << "조회할 이름을 입력하세요 ";
			getline(cin,namex);
			search(p,namex,findName);
		}
		else if(menu == 10){
			string gux;
			cout << "조회할 구을 입력하세요 ";
			getline(cin,gux);
			search(p,gux,findGu);
			
		}
		else if(menu == 11){
			string typex;
			cout << "조회할 종류을 입력하세요 ";
			getline(cin,typex);
			search(p,typex,findType);
		}
	}
}