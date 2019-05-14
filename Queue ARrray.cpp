/*
Nama Program		: Exercise Array Queue 
Nama				: Alfian Fadhil Labib
NPM					: 140810180055
Tanggal Pembuatan	: Senin, 14 Mei 2019

*/
#include<iostream>
using namespace std;

const int maxElemen = 255;

	struct Queue{
	char isi[maxElemen];
	int head; // depan
	int tail; // belakang
};

void createQueue (Queue& Q){
	Q.head = 0;
	Q.tail = -1;
}

void insertQueue(Queue& Q, char elemen) {
	cout<<"Insert Queue (Antrian) "<<endl;
	if (Q.tail==maxElemen-1){
		cout<<"Antrian sudah penuh"<<endl;
	}
	else {
		Q.tail=Q.tail + 1;
		Q.isi[Q.tail] = elemen;
	}
}

void deleteQueue(Queue& Q, char& elemenHapus){
	cout<<"Delete Queue (Antrian) "<<endl;
	if (Q.head>Q.tail){ // atau Q.tail=-1
		cout<<"Antrian kosong"<<endl;
	}
	else {
		elemenHapus= Q.isi[Q.head]; //Q.head=0
		for (int i=0;i<Q.tail;i++){ // Geser ke depan
			Q.isi[i]=Q.isi[i+1];
		}
		Q.tail=Q.tail-1;
	}
}

void printQueue(Queue& Q){
	if(Q.head == -1){
		cout<<"Queue Kosong"<<endl;
	}
	else{
		cout<<"Queue : ";
		for(int i = Q.head; i<=Q.tail; i++){
			cout<<Q.isi[i]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	Queue Q;
	char c;
	
	createQueue(Q);
	for(int i=1; i<=5; i++){
		cout<<"Input char : ";cin>>c;
		insertQueue(Q, c);
	}
	printQueue(Q);
}


