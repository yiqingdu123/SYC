/*******************************************************************************
 * Programmers: Yiqing Du, Christopher Infranco, Shalini Sivakumar             *
 * Date: 02/19/2022                                                            *
 *                                                                             *
 * Description: This program matches WSU students with other students based    *
 *			    on personality factors                                         *
 *                                                                             *
 ******************************************************************************/

#include "CougFriends.h"

int main(void)
{
	int mainOption = 0, success = 0;

	Person currentPerson;
	Node* pHead = NULL;

	char username[30] = "", password[20];

	FILE* infile = fopen("samples.txt", "r");
	
	loadUsers(&pHead, infile);

	printf("Welcome to...\n");

	printf("  _____                  ______    _                _\n");
	printf(" / ____|                |  ____ | (_)              | |\n");
	printf("| |     ___  _   _  __ _| |__ _ __ _  ___ _ __    _| |___\n");
	printf("| |    / _ \\| | | |/ _` | __ | '__| |/ _ \\  '_ \\ / _` / __|\n");
	printf("| |___| (_) | |_| | (_| | |  | |  | |  __/| | | | (_  \\__ \\\n");
	printf(" \\_____\\___/ \\__,_|\\__, |_|  |_|  |_|\\___ |_| |_|\\__,_|___/\n");
	printf("		    __/ |\n");
	printf("                   |___/\n");
	printf("Some users have been preloaded.\n");






	do
	{
		system("pause");
		system("cls");
		printMainMenu();
		mainOption = getMainMenuOption();
		system("cls");

		switch (mainOption)
		{
		case NEW:
			newProfile(&currentPerson, pHead);
			insertFront(&pHead, &currentPerson);
			break;
		case EDIT:
			getUserPass(username, password);

			success = checkUserPass(pHead, username, password);
			if (success == 1)
			{
				edit(pHead, username);
			}
			else
			{
				printf("Username/password incorrect.\n");
			}
			break;
		case DELETE:
			getUserPass(username, password);

			success = checkUserPass(pHead, username, password);
			if (success == 1)
			{
				delete(&pHead, username);
			}
			else
			{
				printf("Username/password incorrect.\n");
			}
			break;
		case MATCH:
			getUserPass(username, password);

			success = checkUserPass(pHead, username, password);
			if (success == 1)
			{
				findMatch(pHead, username);
			}
			else
			{
				printf("Username/password incorrect.\n");
			}
			break;
		}

		

	} while (mainOption != 5);
	
	
	return 0;
}