#pragma once
#include<string>
#include<iostream>
#include "ForumNode.h"
#include "Queue.h"
using namespace std;

typedef ForumPost PostType;
typedef string TopicType;

class List
{

	ForumNode* firstNode;	// point to the first item
	int  size;		// number of items in the list

public:
	// constructor
	List();

	// destructor
	/*~List();*/

	// add an item to the back of the list (append)
	bool add(ForumNode* newItem);

	bool addTopic(TopicType t, TopicType a);
	// add an item at a specified position in the list (insert)
	//bool add(int index, TopicType t, TopicType a)
	// remove an item at a specified position in the list
	void remove(int index);

	// get Queue for topic
	Queue getTopicQueue(TopicType topic);

	// check if the list is empty
	//bool isEmpty();

	bool searchTopic(TopicType& chosenTopic);

	Queue getTopic(TopicType topic);

	void printTopics();

	void pinTopic(TopicType topic);

	//int countPosts(TopicType user);
};










