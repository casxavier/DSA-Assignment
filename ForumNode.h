#pragma once
#include "Queue.h"

typedef ForumPost PostType;
typedef string TopicType;

struct ForumNode
{
	TopicType topic;
	TopicType author;
	Queue posts;
	TopicType datePost;
	ForumNode* next;
};


