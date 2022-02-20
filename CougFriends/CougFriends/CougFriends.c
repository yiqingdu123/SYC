/*******************************************************************************
 * Programmers: Yiqing Du, Christopher Infranco, Shalini Sivakumar             *
 * Date: 02/19/2022                                                            *
 *                                                                             *
 * Description: This program matches WSU students with other students based    *
 *			    on personality factors                                         *
 *                                                                             *
 ******************************************************************************/

#include "CougFriends.h"

// description: Prints the main menu of the program
void printMainMenu(void)
{
	printf("1. Enter new profile.\n");
	printf("2. Edit existing profile.\n");
	printf("3. Delete your profile.\n");
	printf("4. Find a match.\n");
	printf("5. Exit.\n");
}
// description: Ensures option is between 1 and 5
int getMainMenuOption(void)
{
	int option = 0;
	char temp[50] = "";

	do
	{
		printf("enter a value on the menu.\n");
		fgets(temp, 50, stdin);
		option = atoi(temp);
	} while (option < 1 || option > 5);
	return option;
}
//description: Dynamically allocates memory for node.
Node* makeNode(Person* pPersonInformation)
{
	Node* pMem = (Node*)malloc(sizeof(Node));
	if (pMem != NULL)
	{
		// memory allocated successfully
		pMem->pNext = NULL;
		strcpy(pMem->data.name, pPersonInformation->name);
		strcpy(pMem->data.username, pPersonInformation->username);
		strcpy(pMem->data.password, pPersonInformation->password);
		strcpy(pMem->data.funFact, pPersonInformation->funFact);
		strcpy(pMem->data.hobby, pPersonInformation->hobby);
		pMem->data.astrologicalSign = pPersonInformation->astrologicalSign;
		pMem->data.catDog = pPersonInformation->catDog;
		strcpy(pMem->data.contactInfo, pPersonInformation->contactInfo);
		pMem->data.gender = pPersonInformation->gender;
		pMem->data.grade = pPersonInformation->grade;
		pMem->data.personalityNum = pPersonInformation->personalityNum;
	}
	return pMem;
}
// description: inserts item at front of linked list
int insertFront(Node** pList, Person* pPersonInformation)
{
	Node* pMem = makeNode(pPersonInformation);
	int success = 0;

	if (pMem != NULL)
	{
		pMem->pNext = *pList;
		*pList = pMem;

		success = 1;
	}

	return success;
}

// description: Creates attributes for user.
Person* newProfile(Person* pPersonInformation, Node* pHead)
{
	
	printf("-----------\n");
	
	newName(pPersonInformation);

	printf("-----------\n");

	newUsername(pPersonInformation, pHead);
	
	printf("-----------\n");

	newPassword(pPersonInformation);

	printf("-----------\n");

	printf("Enter the following for your bio, this will be shared with other users:\n");
	
	printf("-----------\n");

	newGender(pPersonInformation);

	printf("-----------\n");

	newGrade(pPersonInformation);

	printf("-----------\n");

	newFact(pPersonInformation);

	printf("-----------\n");

	newHobby(pPersonInformation);

	printf("-----------\n");

	newCatDog(pPersonInformation);

	printf("-----------\n");

	newAstro(pPersonInformation);

	printf("-----------\n");

	newConInfo(pPersonInformation);

	system("pause");
	system("cls");

	printf("Let's take a short quiz to get your personality information!\nThe sum of your scores is your personality index.\n");
	printf("-----------\n");

	pPersonInformation->personalityNum = getPersonalityNumber();

	return pPersonInformation;
}
//description: Obtains username and password from user.
void getUserPass(char* user, char* pass)
{
	char temp[50] = "";
	
	printf("Enter your username (max 30 char):\n");
	fgets(user, 31, stdin);
	
	if (user[strlen(user) - 1] == '\n')
	{
		user[strlen(user) - 1] = '\0';
	}
	else
	{
		fgets(temp, 50, stdin);
	}


	printf("Enter your password:\n");
	fgets(pass, 21, stdin);
	if (pass[strlen(pass) - 1] == '\n')
	{
		pass[strlen(pass) - 1] = '\0';
	}
	else
	{
		fgets(temp, 50, stdin);
	}
}
// description: Ensures the username and password combination lines up
int checkUserPass(Node* pHead, char* user, char* pass)
{
	Node* pCur = pHead;
	int success = 0;

	while (pCur != NULL)
	{
		if (strcmp(user, pCur->data.username) == 0)
		{
			if (strcmp(pass, pCur->data.password) == 0)
			{
				success = 1;
			}
		}
		pCur = pCur->pNext;
	}
	return success;
}
// description: Series of questions that yield a personality index for the user.
int getPersonalityNumber(void)
{
	int personalityNumber = 0, choice = 0;
	printf("Q1: Your teacher has assigned you a 3-page essay that is due in two days. What is the first thing that you do?\n");
	printf("1. Immediately begin the essay and work on it non-stop until finishing\n");
	printf("2. Start making an outline, and start portions of the essay\n");
	printf("3. Plan out when to work on it and do a little bit\n");
	printf("4. Put it off till last minute\n");
	printf("5. Don't think about or do the assignment at all\n");
	choice = getMainMenuOption();
	personalityNumber += choice;
	printf("-----------\n");
	printf("Q2: How easily do you make new friends?\n");
	printf("1. Never, avoid making friends\n");
	printf("2. Generally don't socialize\n");
	printf("3.Can socialize but don't enjoy it\n");
	printf("4. Enjoy socializing\n");
	printf("5. Enjoy talking to strangers and often make friends\n");
	choice = getMainMenuOption();
	personalityNumber += choice;
	printf("-----------\n");
	printf("Q3: What is one word to describe yourself?\n");
	printf("1. timid/shy\n");
	printf("2. reserved\n");
	printf("3.average\n");
	printf("4. outgoing\n");
	printf("5. exciting/entertaining\n");
	choice = getMainMenuOption();
	personalityNumber += choice;
	printf("-----------\n");
	printf("Q4: What is your favorite drink?\n");
	printf("1. Milk\n");
	printf("2. Orange Juice\n");
	printf("3. Coffee or Lattes\n");
	printf("4. Beer\n");
	printf("5. Vodka/Spirits\n");
	choice = getMainMenuOption();
	personalityNumber += choice;
	printf("-----------\n");
	printf("Q5: How often do you change your hairstyle?\n");
	printf("1. I've never changed it since I was little\n");
	printf("2. Once every few years\n");
	printf("3. Once a year\n");
	printf("4. Once every few months\n");
	printf("5. Every time I get a haircut\n");
	choice = getMainMenuOption();
	personalityNumber += choice;
	printf("-----------\n");
	printf("Q6: What do you do in your free time?\n");
	printf("1. Stay in your dorm\n");
	printf("2. Go out to lunch at Yia Yia Nikki's\n");
	printf("3. Go out to lunch at Black Cypress\n");
	printf("4. Go to Etsi Bravo\n");
	printf("5. Go to a frat party\n");
	choice = getMainMenuOption();
	personalityNumber += choice;
	printf("-----------\n");
	printf("Q7: How many WSU-related clubs are you in?\n");
	printf("1. None\n");
	printf("2. 1-2\n");
	printf("3. 2-3\n");
	printf("4. 3-4\n");
	printf("5. 5+\n");
	choice = getMainMenuOption();
	personalityNumber += choice;
	printf("-----------\n");
	printf("Q8: What grade do you get most often?\n");
	printf("1. A\n");
	printf("2. B\n");
	printf("3. C\n");
	printf("4. D\n");
	printf("5. F\n");
	choice = getMainMenuOption();
	personalityNumber += choice; 
	printf("-----------\n");
	printf("Q9: What music do you listen to?\n");
	printf("1. Classical\n");
	printf("2. 60s/70s/Retro music\n");
	printf("3. Country\n");
	printf("4. Pop\n");
	printf("5. Rock/Rap/Metal\n");
	choice = getMainMenuOption();
	personalityNumber += choice;
	printf("-----------\n");
	printf("Q10: What is your major?\n");
	printf("1. STEM\n");
	printf("2. History\n");
	printf("3. English\n");
	printf("4. Business\n");
	printf("5. Communications/Other\n");
	choice = getMainMenuOption();
	personalityNumber += choice;

	return personalityNumber;

}
// description: Finds exact and close matches for user.
void findMatch(Node* pHead, char* username)
{
	Person temp = {"", "", "", "", 0, 0, 0, 0, "", "", 0};
	Node* pCur = pHead;
	int difference = 0, count = 0;

	while (pCur != NULL && strcmp(pCur->data.username, username) != 0)
	{
		pCur = pCur->pNext;
	}

	if (pCur == NULL)
	{
		printf("username not found.\n");
	}
	else
	{
		temp = pCur->data;
	}

	pCur = pHead;
	
	printf("-----------\n");
	printf("Your personality index is: %d\n", temp.personalityNum);
	
	printf("Matching on personality index...\n");
	Sleep(3000);
	printf("-----------\n");

	printf("Exact Matches (score within 5):\n");
	while (pCur != NULL)
	{
		difference = pCur->data.personalityNum - temp.personalityNum;
		
		if (difference <= 5 && difference >= -5 && strcmp(pCur->data.username, username) != 0)
		{
			printUserInfo(pCur);
			printf("-----------\n");
			count++;
		}
		pCur = pCur->pNext;
	}
	printf("Exact matches found: %d\n", count);

	printf("-----------\n");
	printf("Close Matches (score within 10):\n");
	count = 0;
	pCur = pHead;
	while (pCur != NULL)
	{
		difference = pCur->data.personalityNum - temp.personalityNum;

		if ((difference > 5 && difference <= 10) || (difference >= -10 && difference < -5))
		{
			printUserInfo(pCur);
			printf("-----------\n");
			count++;
		}
		pCur = pCur->pNext;
	}
	printf("Close matches found: %d\n", count);
	printf("-----------\n");
}
// description: Prints user attributes
void printUserInfo(Node* pList)
{
	printf("\nName: %s\n", pList->data.name);
	printf("Personality Index: %d\n", pList->data.personalityNum);
	switch (pList->data.gender)
	{
	case 1:
		printf("Gender: Female\n");
		break;
	case 2:
		printf("Gender: Male\n");
		break;
	case 3:
		printf("Gender: Non-binary\n");
		break;
	case 4:
		printf("Gender: Other\n");
		break;

	}
	switch (pList->data.grade)
	{
	case 1:
		printf("Grade Level: Freshman\n");
		break;
	case 2:
		printf("Grade Level: Sophomore\n");
		break;
	case 3:
		printf("Grade Level: Junior\n");
		break;
	case 4:
		printf("Grade Level: Senior\n");
		break;
	}
	printf("Fun fact: %s\n", pList->data.funFact);
	printf("Hobby: %s\n", pList->data.hobby);
	switch (pList->data.catDog)
	{
	case 1:
		printf("Dog person\n");
		break;
	case 2:
		printf("Cat person\n");
		break;
	}
	switch (pList->data.astrologicalSign)
	{
	case 1:
		printf("Astrological Sign: Aries\n");
		break;
	case 2:
		printf("Astrological Sign: Taurus\n");
		break;
	case 3:
		printf("Astrological Sign: Gemini\n");
		break;
	case 4:
		printf("Astrological Sign: Cancer\n");
		break;
	case 5:
		printf("Astrological Sign: Leo\n");
		break;
	case 6:
		printf("Astrological Sign: Virgo\n");
		break;
	case 7:
		printf("Astrological Sign: Libra\n");
		break;
	case 8:
		printf("Astrological Sign: Scorpio\n");
		break;
	case 9:
		printf("Astrological Sign: Saggittarius\n");
		break;
	case 10:
		printf("Astrological Sign: Capricorn\n");
		break;
	case 11:
		printf("Astrological Sign: Aquarius\n");
		break;
	case 12:
		printf("Astrological Sign: Pisces\n");
		break;
	}
	printf("Contact Info: %s\n", pList->data.contactInfo);

}
// description: Deletes profile from list
void delete(Node** pList, char* username)
{
	Node* pCur = *pList, *pPrev = NULL;

	while (pCur != NULL && strcmp(pCur->data.username, username) != 0)
	{
		pPrev = pCur;
		pCur = pCur->pNext;
	}

	if (pCur == NULL)
	{
		printf("username not found.\n");
	}
	else if (pPrev == NULL)
	{
		*pList = pCur->pNext;
		free(pCur);
	}
	else
	{
		pPrev->pNext = pCur->pNext;
		free(pCur);
	}
}
// description: Allows user to edit their information
void edit(Node* pHead, char* username)
{
	Node* pCur = pHead;
	int option = 0;
	char temp[50] = "";

	while (pCur != NULL && strcmp(pCur->data.username, username) != 0)
	{
		pCur = pCur->pNext;
	}

	if (pCur == NULL)
	{
		printf("username not found...\n");
	}
	else
	{
		printf("\nCURRENT INFORMATION:");
		printf("-----------\n");

		printUserInfo(pCur);
		printf("-----------\n");

		printf("1. edit basic information\n");
		printf("2. take the personality quiz again\n");
		
		do
		{
			printf("enter a value on the menu: \n");
			fgets(temp, 50, stdin);
			option = atoi(temp);
		} while (option < 1 || option > 2);
		printf("-----------\n");

		switch (option)
		{
		case 1:
			printf("WHAT FIELD WOULD YOU LIKE TO EDIT?\n");
			printEditMenu();

			do
			{
				printf("enter a value on the menu: \n");
				fgets(temp, 50, stdin);
				option = atoi(temp);
			} while (option < 1 || option > 7);

			switch (option)
			{
			case 1:
				newName(&(pCur->data));
				break;
			case 2:
				newGender(&(pCur->data));
				break;
			case 3:
				newFact(&(pCur->data));
				break;
			case 4:
				newHobby(&(pCur->data));
				break;
			case 5:
				newCatDog(&(pCur->data));
				break;
			case 6:
				newAstro(&(pCur->data));
				break;
			case 7:
				newConInfo(&(pCur->data));
				break;
			}
			break;
		case 2:
			pCur->data.personalityNum = getPersonalityNumber();
			break;
		}

	}

}
// description: Displays user information for the edit menu
void printEditMenu(void)
{
	printf("1. name\n");
	printf("2. gender\n");
	printf("3. fun fact\n");
	printf("4. hobby\n");
	printf("5. cat or dog\n");
	printf("6. astrological sign\n");
	printf("7. contact information\n");
}
//description: Allows user to update their name
void newName(Person* pPersonInformation)
{
	char temp[50] = "";
	
	do
	{
		printf("Enter your name (50 char max):\n");
		fgets(pPersonInformation->name, 51, stdin);

		if ((pPersonInformation->name)[strlen(pPersonInformation->name) - 1] == '\n')
		{
			(pPersonInformation->name)[strlen(pPersonInformation->name) - 1] = '\0';
		}
		else
		{
			fgets(temp, 50, stdin);
		}
	} while (strcmp("", pPersonInformation->name) == 0);


}

// description: Allows users to update their gender.
void newGender(Person* pPersonInformation)
{
	int option = 0;
	char temp[50] = "";
	printf("1. Female\n");
	printf("2. Male\n");
	printf("3. Non-binary\n");
	printf("4. Other\n");

	do
	{
		printf("enter a value on the menu.\n");
		fgets(temp, 50, stdin);
		option = atoi(temp);
	} while (option < 1 || option > 4);

	pPersonInformation->gender = option;
}
//description: Allows the user to update their grade level.
void newGrade(Person* pPersonInformation)
{
	int option = 0;
	char temp[50] = "";
	printf("1. Freshman\n");
	printf("2. Sophomore\n");
	printf("3. Junior\n");
	printf("4. Senior\n");

	do
	{
		printf("enter a value on the menu.\n");
		fgets(temp, 50, stdin);
		option = atoi(temp);
	} while (option < 1 || option > 4);

	pPersonInformation->grade = option;
}
//description: Allows the user to update their fun fact attribute.

void newFact(Person* pPersonInformation) {
	char temp[50] = "";
	do
	{
		printf("Enter a fun fact about you (max 70 char):\n");
		fgets(pPersonInformation->funFact, 71, stdin);
		if ((pPersonInformation->funFact)[strlen(pPersonInformation->funFact) - 1] == '\n')
		{
			(pPersonInformation->funFact)[strlen(pPersonInformation->funFact) - 1] = '\0';
		}
		else
		{
			fgets(temp, 50, stdin);
		}
	} while (strcmp("", pPersonInformation->funFact) == 0);
}

//description: Allows the user to update their hobby.
void newHobby(Person* pPersonInformation) {
	char temp[50] = "";
	do
	{
		printf("Enter a hobby (max 50 char):\n");
		fgets(pPersonInformation->hobby, 51, stdin);
		if ((pPersonInformation->hobby)[strlen(pPersonInformation->hobby) - 1] == '\n')
		{
			(pPersonInformation->hobby)[strlen(pPersonInformation->hobby) - 1] = '\0';
		}
		else
		{
			fgets(temp, 50, stdin);
		}
	} while (strcmp("", pPersonInformation->hobby) == 0);
}

//description: Allows the user to update their cat-or-dog preference
void newCatDog(Person* pPersonInformation) {
	
	int option = 0;
	char temp[50] = "";
	printf("1. Dog\n");
	printf("2. Cat\n");

	do
	{
		printf("enter a value on the menu.\n");
		fgets(temp, 50, stdin);
		option = atoi(temp);
	} while (option < 1 || option > 2);

	pPersonInformation->catDog = option;
}

//description: Allows the user to update their astrological sign
void newAstro(Person* pPersonInformation) {
	int option = 0;
	char temp[50] = "";
	printf("1. Aries\n");
	printf("2. Taurus\n");
	printf("3. Gemini\n");
	printf("4. Cancer\n");
	printf("5. Leo\n");
	printf("6. Virgo\n");
	printf("7. Libra\n");
	printf("8. Scorpio\n");
	printf("9. Sagittarius\n");
	printf("10. Capricorn\n");
	printf("11. Aquarius\n");
	printf("12. Pisces\n");

	do
	{
		printf("enter a value on the menu.\n");
		fgets(temp, 50, stdin);
		option = atoi(temp);
	} while (option < 1 || option > 12);

	pPersonInformation->astrologicalSign = option;
}
// description: Allows users to update their communication information
void newConInfo(Person* pPersonInformation) {
	char temp[50] = "";
	printf("Enter your contact information (phone number or email) (30 char max)\n");
	do
	{
		fgets(pPersonInformation->contactInfo, 31, stdin);
		if ((pPersonInformation->contactInfo)[strlen(pPersonInformation->contactInfo) - 1] == '\n')
		{
			(pPersonInformation->contactInfo)[strlen(pPersonInformation->contactInfo) - 1] = '\0';
		}
		else
		{
			fgets(temp, 50, stdin);
		}
	} while (strcmp("", pPersonInformation->contactInfo) == 0);
}
// description: Allows the user to update their username
void newUsername(Person* pPersonInformation, Node *pHead) {
	Node* pCur = pHead;
	int match = 0;
	char temp[50] = "";
	
	do
	{
		if (match == 0)
		{
			printf("Create your username (max 30 char):\n");
		}
		else
		{
			printf("Username already taken. Please enter another:\n");
		}
		fgets(pPersonInformation->username, 31, stdin);
		if ((pPersonInformation->username)[strlen(pPersonInformation->username) - 1] == '\n')
		{
			(pPersonInformation->username)[strlen(pPersonInformation->username) - 1] = '\0';
		}
		else
		{
			fgets(temp, 50, stdin);
		}
		match = 0;
		pCur = pHead;
		while (pCur != NULL && match != 1)
		{
			if (strcmp(pCur->data.username, pPersonInformation->username) == 0)
			{
				match = 1;
			}
			pCur = pCur->pNext;
		}
	} while (match == 1 || strcmp("", pPersonInformation->username) == 0);
	
}

// descriptions: gets new password from user
void newPassword(Person* pPersonInformation) {
	char temp[50] = "";
	do
	{
		printf("Create your password (max 20 char):\n");
		fgets(pPersonInformation->password, 21, stdin);
		if ((pPersonInformation->password)[strlen(pPersonInformation->password) - 1] == '\n')
		{
			(pPersonInformation->password)[strlen(pPersonInformation->password) - 1] = '\0';
		}
		else
		{
			fgets(temp, 50, stdin);
		}
	} while (strcmp("", pPersonInformation->password) == 0);
}

// description: loads names from file
void loadUsers(Node** pList, FILE* infile)
{
	Person temp;

	char temparr[50] = "";

	while (!feof(infile))
	{
		fgets(temp.name, 51, infile);
		temp.name[strlen(temp.name) - 1] = '\0';

		fgets(temp.username, 31, infile);
		temp.username[strlen(temp.username) - 1] = '\0';

		fgets(temp.password, 21, infile);
		temp.password[strlen(temp.password) - 1] = '\0';

		fgets(temparr, 50, infile);
		temp.personalityNum = atoi(temparr);


		fgets(temparr, 50, infile);
		temp.gender = atoi(temparr);
		
		fgets(temparr, 50, infile);
		temp.grade = atoi(temparr);

		fgets(temp.funFact, 71, infile);
		temp.funFact[strlen(temp.funFact) - 1] = '\0';

		fgets(temp.hobby, 51, infile);
		temp.hobby[strlen(temp.hobby) - 1] = '\0';
		
		fgets(temparr, 50, infile);
		temp.catDog = atoi(temparr);

		fgets(temparr, 50, infile);
		temp.astrologicalSign = atoi(temparr);

		fgets(temp.contactInfo, 31, infile);
		temp.contactInfo[strlen(temp.contactInfo) - 1] = '\0';

		insertFront(pList, &temp);
	}

}
