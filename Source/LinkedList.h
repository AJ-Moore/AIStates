/*
	Linked List "LinkList" Class Declaration
	Dev By Allan Moore 22/01/2014
	21017984
	Buckinghamshire New University 
*/

#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER



template <class T>
class LinkedList{
public:
	/// Constructors/ Destructors
	LinkedList();
	~LinkedList();

	void display(); 
	inline void insert(T* NewLink);

	T* find(T* Object);
	T* find(int Key); 

	//Note:: delete is a reserved word... And remove seems more accurate 
	T* remove(T* Object);
	T* remove(int Key);

	bool destroy();
	bool destroy(T* Object);
	bool destroy(int Key); 

	inline bool isEmpty();

	//returns the number of elements in the list.
	inline int getSize(); 

	//Operator Overloads 
	T * operator[](const int &Key);

	T* first; 
private:
	///How many elements/items in the list
	int elements; 
};

//================================INLINE=========================
//===============================================================
///Will return true if list is empty -- No first link -- Atrribute set to nullptr
template <class T>
bool LinkedList<T>::isEmpty(){
	return (this->first == nullptr);
}

//Effictively inserts new link at top of linked-list
template <class T>
void LinkedList<T>::insert(T* NewLink){
	NewLink->next = this->first; 
	this->first = NewLink;
	this->elements++;
}

template <class T>
int LinkedList<T>::getSize(){
	return this->elements;
}
//================================================================

template <class T>
LinkedList<T>::LinkedList(){
	this->first = nullptr; 
	this->elements = 0; 
}

template <class T>
LinkedList<T>::~LinkedList(){
	while (!this->isEmpty())
	{
		this->destroy();
	}
}

template <class T>
void LinkedList<T>::display(){
	//Itterates through all links in the list
	T *CurrentLink = this->first;
	while (CurrentLink != nullptr){
		CurrentLink->display();
		CurrentLink = CurrentLink->next;
	}
}

///Itterates through linked-list until corresponding link is found
template <class T>
T* LinkedList<T>::find(T* Object){
	if (this->isEmpty()){return nullptr;}

	T* CurrentLink = this->first;
	while (*CurrentLink != *Object){
		if (CurrentLink->next == nullptr){
			return nullptr;
		}
		else{
			CurrentLink = CurrentLink->next;
		}
	}
	return CurrentLink;
}

template <class T>
T* LinkedList<T>::find(int key){
	int count = 0; 
	T* CurrentLink = first; 
	while (CurrentLink != nullptr){
		if (count == key) return CurrentLink; 
		count++;
		CurrentLink = CurrentLink->next; 
	}
	return nullptr; 
}

///Removes link from list and returns link
template <class T>
T* LinkedList<T>::remove(T* Object){
	//if list is empty return 
	if (this->isEmpty()){ return nullptr;}

	T* CurrentLink = this->first; 
	T* PreviousLink = this->first; 

	while (*CurrentLink != *Object){
		if (CurrentLink->next == nullptr){
			return nullptr; 
		}
		else{
			PreviousLink = CurrentLink; 
			CurrentLink = CurrentLink->next;
		}
	}
	//Link Found  

	if (CurrentLink == this->first){
		this->first = this->first->next;
	}
	else{
		PreviousLink->next = CurrentLink->next;
	}
	this->elements--;
	return CurrentLink; 

}

template <class T>
T* LinkedList<T>::remove(int Key){
	int count = 0; 
	T* CurrentLink = first; 
	while (CurrentLink != nullptr){
		if (count == key) break; 
		count++;
		current = current->next; 
	}
	if (CurrentLink == nullptr) return nullptr; 

	if (CurrentLink == this->first){
		this->first = this->first->next;
	}
	else{
		PreviousLink->next = CurrentLink->next;
	}
	this->elements--;
	return CurrentLink; 

}

///Destroys the first element in the list.
template <class T>
bool LinkedList<T>::destroy(){
	//if list is empty return 
	if (this->first == nullptr){return false;}
	T* temp = this->first; 
	this->first = this->first->next;
	delete temp; temp = nullptr; 
	return true; 
}

//Note:: delete is a reserved word... Delete is okay but... 
///Removes And Destroys/ "delete"s link 
///returns true on successfully finding + destroying link
///returns false if link isn't found.
template <class T>
bool LinkedList<T>::destroy(T* Object){
	T* obj = this->remove(Object);
	if (obj != nullptr){
		delete obj; 
		obj = nullptr; 
		return true; 
	}

	return false; 
}

template <class T>
bool LinkedList<T>::destroy(int Key){
	T* obj = this->remove(key);
	if (obj != nullptr){
		delete obj; 
		obj = nullptr; 
		return true; 
	}

	return false; 
}

template <class T>
T* LinkedList<T>::operator[](const int &Key){
	return this->find(Key);
}

#endif
