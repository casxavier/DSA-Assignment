#pragma once
#include<string>
#include<iostream>
#include "ForumPost.h"
using namespace std;

typedef ForumPost* QueueItem;

class Queue
{
private:

    struct Node
    {
        QueueItem item;	// item
        Node* next;	// pointer pointing to next item
    };

    Node* frontNode;	// point to the first item
    Node* backNode;	// point to the first item
    int size;

public:
    // constructor
    Queue();
    ~Queue();

    // enqueue (add) item at the back of queue
    bool enqueue(QueueItem item);

    // dequeue (remove) item from front of queue
    bool dequeue();


    // retrieve (get) item from front of queue
    /*void getFront(ForumPost* item);*/
    ForumPost* getFront();

    // check if the queue is empty
    bool isEmpty();

    // get size of queue
    int getNoOfElements();

    void displayContent();
    //int countPosts(string user);
};

