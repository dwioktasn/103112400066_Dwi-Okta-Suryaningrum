#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; //array untuk menyimpan elemen stack
    int top; //indeks top stack
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X); //menambahkan elemen ke stack
infotype pop(Stack &S); //mengambil elemen teratas dari stack
void printInfo(Stack S); //menampilkan isi stack
void balikStack(Stack &S); //membalik urutan elemen stack
#endif