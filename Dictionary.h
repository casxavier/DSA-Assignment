// Dictionary.h - - Specification of Dictionary ADT
#include<string>
#include<iostream>
using namespace std;

const int MAX_SIZE = 101;
typedef string KeyType;
typedef string ItemType;

struct Node
{
	KeyType  key;   // search key
	string item;	// data item
	Node* next;	// pointer pointing to next item
};

class Dictionary
{
private:
	Node* items[MAX_SIZE];
	int size; // number of items in the Dictionary

public:
	// constructor
	Dictionary();

	// destructor
	~Dictionary();

	int hash(KeyType key);

	// add a new item with the specified key to the Dictionary
	bool add(KeyType newKey, ItemType newItem);

	//// remove an item with the specified key in the Dictionary
	//void remove(KeyType key);

	// get an item with the specified key in the Dictionary (retrieve)
	ItemType get(KeyType key);

	ItemType getUser(KeyType key);

	// check if the Dictionary is empty
	bool isEmpty();

	// check the size of the Dictionary
	int getLength();

	int charvalue(char c);
	bool isExist(KeyType key);
};








