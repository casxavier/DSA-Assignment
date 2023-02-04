#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <vector>
#include "List.h"
#include"Dictionary.h"
#include "Queue.h"
#include "ForumPost.h"
using namespace std;
string getDateToday()
{
    auto now = chrono::system_clock::now();
    std::time_t now_c = chrono::system_clock::to_time_t(now);
    tm tm;
    gmtime_s(&tm, &now_c);
    stringstream ss;
    ss << put_time(&tm, "%d-%m-%Y");
    string dateToday = ss.str();

    return dateToday;
}

int main()
{
    List forum;
    string target, password;
    KeyType username;
    int choice;
    Dictionary userList;
    bool accCreated = false;
    bool loggedIn = false;
    // Creating Topics and its respective posts
    int postNum = 1;

    //ADDING SAMPLE DATA
    //==========================================================================================

    // for C++ topic
    Queue Cpost;

    ForumPost* newPost1C = new ForumPost;
    newPost1C->author = "C++ Genius";
    newPost1C->content = "C++ was originally called The New C.";
    newPost1C->datePosted = "3-2-2023";
    newPost1C->postNum = postNum;
    Cpost.enqueue(newPost1C);

    ForumPost* newPost2C = new ForumPost;
    newPost2C->author = "C++ Genius";
    newPost2C->content = "C++ was created by Danish computer scientist Bjarne Stroustrup.";
    newPost2C->datePosted = "5-2-2023";
    postNum++;
    newPost2C->postNum = postNum;
    Cpost.enqueue(newPost2C);

    ForumPost* newPost3C = new ForumPost;
    newPost3C->author = "C++ Genius";
    newPost3C->content = "C++ is an extension of the C programming language.";
    newPost3C->datePosted = "8-2-2023";
    postNum++;
    newPost3C->postNum = postNum;
    Cpost.enqueue(newPost3C);
    postNum++;

    // add topic to forum list
    ForumNode* forumNode1 = new ForumNode;
    forumNode1->topic = "C++";
    forumNode1->author = "C++ Inventor";
    forumNode1->posts = Cpost;
    forumNode1->datePost = "1-2-2023";
    forum.add(forumNode1);

    // for JavaScript topic
    Queue Jpost;
    ForumPost* newPost1J = new ForumPost;
    newPost1J->content = "JavaScript is the third most popular language in the world.";
    newPost1J->author = "JavaScript Genius";
    newPost1J->datePosted = "1-2-2023";
    newPost1J->postNum = postNum;
    Jpost.enqueue(newPost1J);

    ForumPost* newPost2J = new ForumPost;
    newPost2J->content = "You can also use a semicolon at the beginning of a line.";
    newPost2J->author = "JavaScipt Genius";
    newPost2J->datePosted = "2-2-2023";
    postNum++;
    newPost2J->postNum = postNum;
    Jpost.enqueue(newPost2J);
    postNum++;

    ForumPost* newPost3J = new ForumPost;
    newPost3J->content = "JavaScript took just 10 days to develop.";
    newPost3J->author = "JavaScript Genius";
    newPost3J->datePosted = "4-2-2023";
    newPost3J->postNum = postNum;
    Jpost.enqueue(newPost3J);

    // add topic to forum
    ForumNode* forumNode2 = new ForumNode;
    forumNode2->topic = "JavaScript";
    forumNode2->author = "JavaScript Inventor";
    forumNode2->datePost = "20-1-2023";
    forumNode2->posts = Jpost;
    forum.add(forumNode2);

    // for Phyton topic
    Queue Ppost;

    ForumPost* newPost1P = new ForumPost;
    newPost1P->content = "The language's name isn't about snakes, but about the popular British comedy troupe Monty Python.";
    newPost1P->author = "Phyton Genius";
    newPost1P->datePosted = "5-3-2023";
    postNum++;
    newPost1P->postNum;
    Ppost.enqueue(newPost1P);

    ForumPost* newPost2P = new ForumPost;
    newPost2P->content = "If you type in 'import this' in your Python IDLE, you'll find a poem, which is written by Tim Peters, a major contributor to the Phyton Community. ";
    newPost2P->author = "Phyton Genius";
    newPost2P->datePosted = "7-3-2023";
    postNum++;
    newPost2P->postNum;
    Ppost.enqueue(newPost2P);

    ForumPost* newPost3P = new ForumPost;
    newPost3P->content = "Python ranked #1 on the IEEE Spectrum list of top programming languages for 2019.";
    newPost3P->author = "Phyton Genius";
    newPost3P->datePosted = "8-3-2023";
    postNum++;
    newPost3P->postNum;
    Ppost.enqueue(newPost3P);

    ForumNode* forumNode3 = new ForumNode;
    // add topic to forum
    forumNode3->topic = "Phyton";
    forumNode3->author = "Phyton Inventor";
    forumNode3->datePost = "12-2-2023";
    forumNode3->posts = Ppost;
    forum.add(forumNode3);
    //==========================================================================================

    userList.add("Saiful", "1234");
    userList.add("C++ Inventor", "Cinvent");
    userList.add("JavaScript Inventor", "Jinvent");
    userList.add("Phyton Inventor", "Pinvent");
    userList.add("C++ Genius", "iloveC++");
    userList.add("JavaScript Genius", "iloveJS");
    userList.add("Phyton Genius", "ilovePhy");
    //register for and log into account
    userList.add("test", "1234");
    //register for and log into account
    while (!(accCreated))
    {
        cout << "REGISTER ACCOUNT" << endl;
        cout << "----------------" << endl;
        int befLength = userList.getLength();

        cout << "Enter a username: ";
        getline(cin >> ws, username);
        cout << "Enter a password: ";
        cin >> password;

        userList.add(username, password);

        // Verifying if new account is existing user
        if (userList.getLength() == befLength)
        {
            cout << "Username already exists! Please try again.\n" << endl;
        }

        //breaking out of loop
        if (userList.getLength() != befLength)
        {
            accCreated = true;
            cout << "Succesfuly created account!" << endl;
        }
    }
    while (accCreated)
    {
        string userPass = "";
        cout << "" << endl;
        cout << "LOG IN" << endl;
        cout << "---------" << endl;
        cout << "Enter username: ";
        getline(cin >> ws, username);
        userPass = userList.get(username);
        if (userPass != "")
        {
            cout << "Enter password: ";
            cin >> password;
            if (password == userPass && password != "")
            {
                loggedIn = true;
                cout << "\n\nWELCOME " << username << "!" << endl;
                break;
            }
            else
                cout << "Wrong password! Please try again." << endl;
        }
    }

    //display menu and its functions until user exits the application
    while (loggedIn && accCreated)
    {
        cout << "\n---------------MAIN MENU---------------" << endl;
        cout << "1) View all topics and posts " << endl;
        cout << "2) Create new topics" << endl;
        cout << "3) Pin Topic (Sticky Topic)" << endl;
        cout << "0) Exit" << endl;
        cout << "---------------------------------------" << endl;

        cout << "Enter option: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number." << std::endl;
        }

        else {

            //Exit application
            if (choice == 0)
            {
                cout << "Have a good day!";
                loggedIn = false;
                break;
            }

            //View topics and posts
            else if (choice == 1)
            {
                cout << "Topics available: " << endl;
                forum.printTopics();
                TopicType chosenTopic, post;
                cout << "\nChoose a topic (In Words): ";
                cin >> chosenTopic;
                ForumNode* current = new ForumNode;

                if ((forum.searchTopic(chosenTopic)))
                {
                    Queue selectedTopic;
                    ForumNode* current = new ForumNode;
                    cout << "" << endl;
                    cout << "Posts for " << chosenTopic << ":" << endl;
                    selectedTopic = forum.getTopic(chosenTopic);
                    selectedTopic.displayContent();
                    current = current->next;
                }
                else
                    cout << chosenTopic << " topic does not exist. Please try again." << endl;
            }
            //Create Topic
            else if (choice == 2)
            {
                while (true)
                {
                    string newTopic;
                    cout << "Enter a new topic: ";
                    cin >> newTopic;
                    if (!(forum.searchTopic(newTopic)))
                    {
                        string dateToday = getDateToday();
                        Queue newTopicPost;
                        ForumNode* newTopicNode = new ForumNode;
                        newTopicNode->author = username;
                        newTopicNode->topic = newTopic;
                        newTopicNode->posts = newTopicPost;
                        newTopicNode->datePost = dateToday;
                        forum.add(newTopicNode);
                        cout << "New Topic " << newTopic << " added! [ Date Added: " << dateToday << " ]" << endl;
                        break;
                    }
                    else
                        cout << newTopic << " topic already exists. Please try again." << endl;
                }
            }
            else if (choice == 3)
            {
                cout << "Topics available: " << endl;
                forum.printTopics();
                TopicType chosenTopic;
                cout << "\nChoose a topic to pin (In Words): ";
                cin >> chosenTopic;

                if ((forum.searchTopic(chosenTopic)))
                {
                    forum.pinTopic(chosenTopic);
                }
                else
                    cout << chosenTopic << " topic does not exist. Please try again." << endl;
            }
            
        }
    }

}







//else if (choice == 4)
            //{
            //    while (true)
            //    {
            //        string searchChoice, choseTopic, choseUser, chosePost;
            //        cout << "Do you want to search for topic, posts or user: ";
            //        cin >> searchChoice;
            //        for (char& lowChar : searchChoice) lowChar = tolower(lowChar);

            //        // searching for topic
            //        if (searchChoice == "topic")
            //        {
            //            cout << "Choose a topic: ";
            //            cin >> choseTopic;
            //            if ((forum.searchTopic(choseTopic)))
            //            {
            //                cout << "" << endl;
            //                cout << "Topic "<<choseTopic<<" found!\n"<<"Number of Posts: "<< forum.getTopic(choseTopic).getNoOfElements() << "\n"<<endl;
            //                break;
            //            }
            //            else
            //                cout << choseTopic << " topic does not exist. Please try again." << endl;
            //        }
            //        else if (searchChoice == "post")
            //        {

            //        }

            //        else if (searchChoice == "user")
            //        {
            //            string user;
            //            cout << "Select username: ";


            //            user = userList.getUser(choseUser);
            //            if (user != "")
            //            {
            //                cout << "User " << user << " found!\n" << "Number of Posts made: " << forum.countPosts(user) << endl;
            //            }
            //            else
            //                cout << user << " user does not exist. Please try again." << endl;
            //            break; 
            //        }
            //        else
            //            cout << "Invalid choice. Please try again." << endl;
            //    }
            //}
            //else
            //{
            //    cout << "Please enter a valid choice." << endl;
            //}