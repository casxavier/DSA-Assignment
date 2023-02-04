#include "Dictionary.h"
#include <iomanip>
Dictionary::Dictionary() {
	size = 0;
	for (int i = 0; i < MAX_SIZE; i++)
		items[i] = NULL;
};
Dictionary::~Dictionary() {};

int Dictionary::charvalue(char c)
{
	if (isalpha(c))
	{
		if (isupper(c))
			return (int)c - (int)'A';
		else
			return (int)c - (int)'a' + 26;
	}
	else
		return c - '0';
}

int Dictionary::hash(KeyType key)
{
	int index = charvalue(key[0]);
	for (int i = 1; i < key.length(); i++)
	{
		index *= 52;
		index += charvalue(key[i]);
		index = index % MAX_SIZE;
	}
	return index;
}

bool Dictionary::add(KeyType key, ItemType item)
{

	int index = hash(key);

	if (items[index] == NULL)
	{
		Node* newNode = new Node;
		newNode->item = item;
		newNode->key = key;
		newNode->next = NULL;
		items[index] = newNode;
	}

	else
	{
		Node* current = items[index];
		if (current->key == key)
		{
			return false;
		}

		while (current->next != NULL)
		{
			current = current->next;

			if (current->key == key)
			{
				return false;
			}
		}
		Node* newNode = new Node;
		newNode->key = key;
		newNode->item = item;
		newNode->next = NULL;
		current->next = newNode;
	}
	size++;
	return true;
}

//void Dictionary::remove(KeyType key)
//{
//	int index = hash(key);
//	Node* current = new Node;
//	Node* temp = new Node;
//	if (items[index] != NULL)
//	{
//		current = items[index];
//		if (current->key == key)
//		{
//			if (current->next != NULL)
//			{
//				temp->key = current->next->key;
//				temp->item = current->next->item;
//				current->item = temp->item;
//				current->key = temp->key;
//				current->next = NULL;
//				delete temp;
//			}
//			else
//			{
//				items[index] = items[index]->next;
//			}
//
//		}
//
//		while (current != NULL)
//		{
//			Node* temp = items[index];
//			if (current->next != NULL && current->next->key == key)
//			{
//				if (current->next->key == key)
//				{
//					temp = current->next;
//					if (current->next->next != NULL)
//					{
//						current->next = temp->next;
//						temp = NULL;
//					}
//					else
//					{
//						current->next = NULL;
//						temp = NULL;
//					}
//				}
//			}
//			current = current->next;
//		}
//	}
//	size--;
//}

int Dictionary::getLength()
{
	return size;
}

bool Dictionary::isEmpty()
{
	bool empty = false;
	if (size == 0)
	{
		return true;
	}
}

ItemType Dictionary::get(KeyType key)
{
	int index = hash(key);
	ItemType keyItem;
	cout << keyItem;
	Node* current = items[index];
	if (items[index] != NULL)
	{
		if (items[index]->next != NULL)
		{
			while (current != NULL)
			{
				if (current->key == key)
				{
					keyItem = current->item;
				}
				current = current->next;
			}
		}
		else
			keyItem = items[index]->item;
	}
	else
	{
		cout << "Username not found! Please try again." << endl;
	}
	return keyItem;
}

ItemType Dictionary::getUser(KeyType key)
{
	int index = hash(key);
	ItemType keyItem;
	cout << keyItem;
	Node* current = items[index];
	if (items[index] != NULL)
	{
		if (items[index]->next != NULL)
		{
			while (current != NULL)
			{
				if (current->key == key)
				{
					keyItem = current->key;
				}
				current = current->next;
			}
		}
		else
			keyItem = items[index]->key;
	}
	else
	{
		cout << "Username not found! Please try again." << endl;
	}
	return keyItem;
}
bool Dictionary:: isExist(KeyType item)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (items[i] != NULL && items[i]->item == item)
		{
			return true;
		}
	}
	return false;
}

