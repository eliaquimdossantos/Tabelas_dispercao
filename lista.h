#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <typename T>
struct node {
	T content;
	struct node * next;
	int cont_repeat = 0;
};

// List with head
template <typename T>
class LinkedList {
	struct node<T> * head;
	struct node<T> * tail;
	int length;
	int VerifyRepeat(T content);

public:
	LinkedList();
	~LinkedList();

	void PushBack(T content);
	void PushFront(T content);
	int  Search(T content);
	T    GetElement(int index);
	void Remove(int index);
	void Erase();
	int  Length();
	bool IsEmpty();
	void Print();
	void PrintRepeats();
};

template <typename T>
LinkedList<T>::LinkedList() {
	head = new struct node<T>;
	head->next = nullptr;

	tail = new struct node<T>;
	tail->next = nullptr;

	length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {

}

template <typename T>
bool LinkedList<T>::IsEmpty() {
	return length == 0;
}

template <typename T>
int LinkedList<T>::VerifyRepeat(T content) {
	int cont_repeat = 0;

	struct node<T> * newNode = new struct node<T>;
	newNode->next = head->next;

	for(int i = 0; i < Length(); i++){	
		newNode = newNode->next;		
		if(GetElement(i) == content){									
			cont_repeat++;		
			newNode->cont_repeat += cont_repeat;						
		}			
	}

	return cont_repeat;
}

template <typename T>
void LinkedList<T>::PushFront(T content) {
	struct node<T> * newNode = new struct node<T>;
	if(VerifyRepeat(content) == 0){
		newNode->content = content;
		newNode->next = head->next;	
		head->next = newNode;

		if(IsEmpty())
			tail->next = newNode;

		length++;
	}
}

template <typename T>
void LinkedList<T>::PushBack(T content) {
	struct node<T> * newNode = new struct node<T>;
	if(VerifyRepeat(content) == 0){
		newNode->content = content;
		newNode->cont_repeat = VerifyRepeat(content);
		newNode->next = nullptr;

		if(!IsEmpty())
			tail->next->next = newNode;
		
		tail->next = newNode;

		if(IsEmpty())
			head->next = newNode;

		length++;
	}
}

template <typename T>
int LinkedList<T>::Search(T content){
	int position = 0;
	bool found = false;
	struct node<T> * newNode = new struct node<T>;
	newNode = head;	

	while(!found && position < length){
		newNode = newNode->next;	
		if(newNode->content == content){						
			found = true;
		}
		position++;
		
	}
	//retorno do indice
	return position-1;
}

template <typename T>
T LinkedList<T>::GetElement(int index){	
	struct node<T> * newNode = new struct node<T>;
	int position = 0;
	newNode = head;

	while(position-1 < index){
		newNode = newNode->next;
		position++;
	}

	return newNode->content;
}

template <typename T>
void LinkedList<T>::Remove(int index){
	struct node<T> * newNode = new struct node<T>;
	newNode = head;

	for(int i = 0; i <= index-1; i++){
		newNode = newNode->next;
		if(i == index-1){			
			newNode->next = newNode->next->next;			
		}
	}

	if(length > 0){
		length--;
	}
}

template <typename T>
void LinkedList<T>::Erase(){		
	head->next = nullptr;	
	length = 0;
}

template <typename T>	
int LinkedList<T>::Length(){
	return this->length;
}

template <typename T>
void LinkedList<T>::Print() {
	struct node<T> * aux = head->next;

	while(aux != nullptr) {
		std::cout << "(" << aux->content << ")" << " ";
		aux = aux->next;
	}

	std::cout << std::endl;
}

template <typename T>
void LinkedList<T>::PrintRepeats(){
	struct node<T> * aux = head->next;
	LinkedList<T> list;
	int last_aux = 0;
	bool printed = false;

	while(aux != nullptr) {				
		if(aux->cont_repeat > 0){
			std::cout << ">'" << aux->content << "' repete " << aux->cont_repeat << "x" << std::endl;
			printed = true;
		}
		aux = aux->next;
	}
}

#endif