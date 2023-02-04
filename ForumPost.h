#pragma once

using namespace std;
struct ForumPost
{
	int postNum;
	string author;
	string content;
	string datePosted;
	ForumPost* next;
};

