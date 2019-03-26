#include <iostream>
using namespace std ;
struct pembalap{
	int nomor ;
	char nama[20] ;
	int waktu ;
	pembalap* next ;
	pembalap* prev ;
};

typedef pembalap* pointer ;
typedef pembalap* list ;

void createlist(list& first){
	first = NULL ;
}

void create(list& first , pointer& pBaru){
	pBaru = new pembalap ;
	cout << "nama	: " ;cin >> pBaru->nama ;
	cout << "nomor	: " ;cin >> pBaru->nomor;
	cout << "waktu	: " ;cin >> pBaru->waktu ;
	pBaru->next = NULL ;
	pBaru->prev = NULL ;
	cout << endl ;
	
}

void insertfirst(list& first , pointer pBaru) {
	if (first == NULL){
		first = pBaru ;
	}
	else {
		pBaru->next = first ;
		first->prev = pBaru ;
		first = pBaru ;
	}
}
 
void ifnsert (list& first , pointer pBaru){
	pointer last ;
	last = first ;
	if (first == NULL){
		first = pBaru ;
	}
	else {
		while (last->next != NULL){
			last = last->next ;
		}
		last->next = pBaru ;
		pBaru->prev = last ;
	}
} 



void trav(list first){
	pointer p ;
	p = first ;
	cout << "nama	nomor	waktu\n" ;
	while(p != NULL) {
		cout << p->nama << "	" << p->nomor << "	" << p->waktu <<endl ;
		p = p->next ; 
	}
}

void deletefi(list& first , pointer pHapus){
	if (first == NULL){
		first = NULL ;
	}
	else{
		pHapus->next = first ;
		first = first->next ;
		pHapus->next = NULL ;
	}
}

void deletelast (list& first , pointer pHapus){
	pointer last ;
	last = first ;
	if (first == NULL){
		first =  NULL ;
	}
	else {
		while(last->next != NULL){
			last = last->next ;
		}
		pHapus = last ;
		last->prev->next = NULL ;
		pHapus->prev = NULL ;
	}
}

void search (list first, int key , int& found , pointer& pC) {
	cout << "\ncari ? " ; cin >> key ;
	pointer p ;
	found = 0 ;
	pC = first ;
	while (found == 0 && pC != NULL) {
		if (pC->nomor == key) {
			p = pC ;
		}
		else {
			pC = pC->next ;
		}
	}
}

void insertbefore(list& first, int key , pointer pBaru) {
	cout << "cari ? " ;
	cin >> key ;
	pointer p ;
	p = first ;
	
	while (key != p->nomor) {
		p = p->next ;
	}
	pBaru->next = p ;
	pBaru->prev = p->prev;
	p->prev->next = pBaru ;
	p->prev = pBaru ; 
	
}




int main () {
	pointer p ;list f ; int k ;
	createlist(f) ;
	for(int i = 0 ; i < 4; i++){
		create(f,p) ;
		insertfirst(f,p) ;
	}	
	cout << "\nLIST\n" ;
	trav(f) ;
	cout << endl ;
	cout << "insert before\n" ;		
	create(f,p) ;
	insertbefore(f,k,p) ;
	trav(f) ;

}
