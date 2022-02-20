/*******************************************************************************
 * Programmers: Yiqing Du, Christopher Infranco, Shalini Sivakumar             *
 * Date: 02/19/2022                                                            *
 *                                                                             *
 * Description: This program matches WSU students with other students based    *
 *			    on personality factors                                         *
 *                                                                             *
 ******************************************************************************/

#ifndef  COUG_FRIENDS_H
#define COUG_FRIENDS_H

#define _CRT_SECURE_NO_WARNINGS

#define NEW 1
#define EDIT 2
#define DELETE 3
#define MATCH 4
#define EXIT 5

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person
{
	char name[51];
	char username[31];
	char password[21];
	char contactInfo[31];
	int astrologicalSign;
	int catDog;
	int gender;
	int grade;
	char funFact[71];
	char hobby[51];
	int personalityNum;
}Person;

typedef struct node
{
	Person data;
	struct node* pNext;
}Node;

// description: Prints the main menu of the program
void printMainMenu(void);

// description: Ensures option is between 1 and 5
int getMainMenuOption(void);

//description: Dynamically allocates memory for node.
Node* makeNode(Person* pPersonInformation);

// description: inserts item at front of linked list
int insertFront(Node** pList, Person* pPersonInformation);

// description: Creates attributes for user.
Person* newProfile(Person* pPersonInformation, Node* pHead);

//description: Obtains username and password from user.
void getUserPass(char* user, char* pass);

// description: Ensures the username and password combination lines up
int checkUserPass(Node* pHead, char* user, char* pass);

// description: Series of questions that yield a personality index for the user.
int getPersonalityNumber(void);

// description: Finds exact and close matches for user.
void findMatch(Node* pHead, char* username);

// description: Prints user attributes
void printUserInfo(Node* pList);

// description: Deletes profile from list
void delete(Node** pList, char* username);

// description: Allows user to edit their information
void edit(Node* pHead, char* username);

// description: Displays user information for the edit menu
void printEditMenu(void);

//description: Allows user to update their name
void newName(Person* pPersonInformation);

// description: Allows users to update their gender.
void newGender(Person* pPersonInformation);

//description: Allows the user to update their grade level.
void newGrade(Person* pPersonInformation);

//description: Allows the user to update their fun fact attribute.
void newFact(Person* pPersonInformation);

//description: Allows the user to update their hobby.
void newHobby(Person* pPersonInformation);

//description: Allows the user to update their cat-or-dog preference
void newCatDog(Person* pPersonInformation);

//description: Allows the user to update their astrological sign
void newAstro(Person* pPersonInformation);

// description: Allows users to update their communication information
void newConInfo(Person* pPersonInformation);

// description: Allows the user to update their username
void newUsername(Person* pPersonInformation, Node* pHead);

// descriptions: gets new password from user
void newPassword(Person* pPersonInformation);

// description: loads names from file
void loadUsers(Node** pList, FILE* infile);

#endif