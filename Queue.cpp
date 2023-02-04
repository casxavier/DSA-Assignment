#include "Queue.h"
#include<iostream>

Queue::Queue() {};
Queue:: ~Queue() {};

bool Queue::enqueue(QueueItem item)
{
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	if (isEmpty())
	{
		frontNode = newNode;
		backNode = newNode;
	}

	else
	{
		backNode->next = newNode;
		backNode = newNode;
	}

	return true;
}

bool Queue::dequeue()
{
	Node* temp = new Node;

	if (frontNode == NULL)
	{
		frontNode = NULL;
		backNode = NULL;
	}
	else
	{
		temp = frontNode;
		frontNode = frontNode->next;
		temp->next = NULL;

	}
	delete temp;

	return true;
}

ForumPost* Queue::getFront()
{
	ForumPost* frontItem = new ForumPost;
	if (!isEmpty())
	{
		frontItem = frontNode->item;
	}
	return frontItem;
}

bool Queue::isEmpty() { return frontNode == NULL; }

void Queue::displayContent()
{
	Node* temp = frontNode;
	Queue queue;
	while (temp != NULL)
	{
		queue.enqueue(temp->item);
		temp = temp->next;
	}
	ForumPost* displayPost = new ForumPost;
	int i = 1;
	while (!(queue.isEmpty()))
	{

		displayPost = queue.getFront();
		cout << i << ") " << displayPost->content << "\n   [Date Posted: " << displayPost->datePosted << "]\n" << endl;
		queue.dequeue();
		i++;
	}
}

int Queue::getNoOfElements()
{
	int elementCount = 0;
	Node* temp = frontNode;
	while (temp != NULL)
	{
		elementCount++;
		temp = temp->next;
	}

	return elementCount;
}

//int Queue:: countPosts(string user)
//{
//	int count = 0;
//	Node* temp = frontNode;
//	Queue queue;
//	while (temp != NULL)
//	{
//		queue.enqueue(temp->item);
//		temp = temp->next;
//	}
//	ForumPost* displayPost = new ForumPost;
//	while (!(queue.isEmpty()))
//	{
//
//		displayPost = queue.getFront();
//		if (displayPost->author == user)
//		{
//			count++;
//		}
//		queue.dequeue();
//	}
//	return count;
//}
