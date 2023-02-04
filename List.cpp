#include "List.h"
List::List()
{
	size = 0;
	firstNode = NULL;
};

bool List::add(ForumNode* newItem)
{
	ForumNode* newNode = new ForumNode;
	ForumNode* current = new ForumNode;
	newNode = newItem;
	newNode->next = NULL;
	if (size == 0)
	{
		firstNode = newNode;
	}
	else
	{
		current = firstNode;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
	size++;
	return true;
}

void List::remove(int index)
{
	if (index == 0)
	{
		firstNode = firstNode->next;
	}
	else {
		ForumNode* current = firstNode;
		for (int i = 0; i < index - 1;i++)
		{
			current = current->next;
		}
		current->next = current->next->next;
	}
	size--;
}

void List::print()
{
	ForumNode* temp = firstNode;
	string objItem;
	while (temp != NULL)
	{
		objItem = temp->topic;
		cout << objItem << endl;
		temp = temp->next;
	}
}

bool List::searchTopic(TopicType& chosenTopic) {
	ForumNode* temp = firstNode;
	while (temp != NULL) {
		if (temp->topic == chosenTopic)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

Queue List::getTopicQueue(TopicType topic)
{
	Queue chosenTopicPost;
	ForumNode* newNode = new ForumNode;
	if (firstNode->next == NULL)
	{
		chosenTopicPost = firstNode->posts;
	}

	else {
		ForumNode* current = firstNode;
		while (current != NULL)
		{
			if (current->topic == topic)
			{
				chosenTopicPost = current->posts;
			}
			current->next = current->next->next;
		}
	}
	return chosenTopicPost;
}

Queue List::getTopic(TopicType topic)
{
	ForumNode* temp = firstNode;
	while (temp != NULL)
	{
		if (temp->topic == topic)
		{
			return temp->posts;
		}
		temp = temp->next;
	}
}

void List::printTopics()
{
	ForumNode* temp = firstNode;
	int i = 1;
	while (temp != NULL)
	{
		cout << i << ") " << temp->topic << "\n\t[Date posted: " << temp->datePost << "]" << endl;
		temp = temp->next;
		i++;
	}
}

void List::pinTopic(TopicType chosenTopic)
{
	ForumNode* current = firstNode;
	ForumNode* previous = NULL;
	ForumNode* pinnedTopic = NULL;
	while (current != NULL)
	{
		if (current->topic == chosenTopic)
		{
			pinnedTopic = current;
			if (previous != NULL)
			{
				previous->next = current->next;
			}
			break;
		}
		previous = current;
		current = current->next;
	}
		pinnedTopic->next = firstNode;
		firstNode = pinnedTopic;
		cout << "\nSuccessfully pinned " << chosenTopic << " topic!" << endl;
		printTopics();
}
//In this code, we first traverse the linked list to find the node with the topic matching the input topic. 
//Once we find it, we unlink it from its current position by updating the next pointer of the previous node 
//to the next node of the current node. We then make the pinnedTopic the first node by updating firstNode to be pinnedTopic.

//int List:: countPosts(TopicType user)
//{
//	int count = 0;
//	ForumNode* topics = firstNode;
//	while (topics != NULL)
//	{
//		count += topics->posts.countPosts(user);
//		topics = topics->next;
//	}
//	return count;
//}