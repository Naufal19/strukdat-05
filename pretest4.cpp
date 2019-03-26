// nama : naufal ariful amri
// Npm	: 140810180009

#include <iostream>
using namespace std ;
struct elemlist {
	char nama[40] ;
	char npm[14] ;
	float ipk ;
	elemlist* next ;
};

typedef elemlist* pointer ;
typedef elemlist* list ;

void createList(list& first ){
	first = NULL ;
}
void createElement(pointer& pBaru){
	pBaru = new elemlist ;
//	cout << "nama	: " ; cin >> pBaru->nama ;
//	cout << "npm	: " ; cin >> pBaru->npm ;
	cout << "ipk	: " ; cin >> pBaru->ipk ;
	pBaru->next = NULL  ; 
}

void insertSort (list& first , pointer pBaru) {
	
	pointer pB ;
	pB = first ;
	if (first == NULL) {
		first = pBaru ;
	}
	else {
		if (pBaru->ipk < first){
			
		}
		else{
			
		}
		
		pBaru->next = first ;
		first = pBaru ; 	
		while (pBaru->ipk < pBaru->next->ipk) {
			pBaru->next = first ;
		}	
	}
}

void traversal(list first){
	pointer pBantu ;
	pBantu = first ;
	while(pBantu != NULL) {
		cout << pBantu->npm << "	" << pBantu->nama << "	" << pBantu->ipk << endl ; 
		pBantu = pBantu->next ;
	}
}

int main () {
	pointer p ;
	list f ;
	createList (f) ;
	for(int i = 0 ; i<5 ; i++){
		createElement(p) ;
		insertSort(f,p) ;

	}


	traversal(f) ;
	
	
	
	
}
