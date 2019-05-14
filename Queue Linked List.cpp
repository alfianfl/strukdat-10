#include <iostream>
using namespace std;

struct ElemenQueue
{
    char info;
    ElemenQueue *next;
};
typedef ElemenQueue *pointer;
typedef pointer List;

struct Queue
{
    List Head;
    List Tail;
};

Queue Q;

void createList(Queue& Q){
    Q.Head = NULL;
    Q.Tail = NULL;
}

void createElement(pointer& pBaru){
    pBaru = new ElemenQueue;
    cout << "Char : "; cin >> pBaru->info;
    pBaru->next = NULL;
}

void insertQueue(pointer pBaru)
{
    if (Q.Head == NULL && Q.Tail == NULL)
    { // kosong
        Q.Head = pBaru;
        Q.Tail = pBaru;
    }
    else
    { // ada isi
        Q.Tail->next = pBaru;
        Q.Tail = pBaru;
    }
}

void deleteQueue(pointer &pHapus)
{
    cout << "Delete Queue" << endl;
    if (Q.Head == NULL && Q.Tail == NULL)
    { //kasus kosong
        pHapus = NULL;
        cout << "List Queue kosong " << endl;
    }
    else if (Q.Head->next == NULL)
    { // kasus isi 1 elemen
        pHapus = Q.Head;
        Q.Head = NULL;
        Q.Tail = NULL;
    }
    else
    { // kasus > 1 elemen
        pHapus = Q.Head;
        Q.Head = Q.Head->next;
        pHapus->next = NULL;
    }
}

void traversal(){
    pointer pBantu = Q.Head;
    if (Q.Head == NULL && Q.Tail == NULL)
    {
        cout << "DATA KOSONG!" << endl;
    }
    else
    {
        while (pBantu != NULL)
        {
            cout << pBantu->info << " ";
            pBantu = pBantu->next;
        }
    }
    cout << endl;
}

int main(){
    pointer p;

    createList(Q);

    createElement(p);
    insertQueue(p);
    traversal();

    createElement(p);
    insertQueue(p);
    traversal();
}
