#include "FunctionList.h" //Header that includes all my functions in SaveFunctions.cpp
 //vectors are a dynamical array, more safer than raw arrays, in some cases D:
using namespace std;
string IDglobal = "NO_USER_FOUND"; //global variable this thing get's called all the time lol.
int main()
{
	char retry = 'S';
	while (retry == 'S')
	{
		string person;
		int length = 100;
		vector<userdataformat> table = ReadUsersffmain("Userbase.txt");
		userdataformat user = mainmenu(table);
		IDglobal = user.IDff;
		if (cherorstud(user.IDff[0]))
		{
			person = "[Teacher]";
		}
		else person = "[Student]";
		cout << "\nLogin Successful! Welcome " << user.displayname << ' ' << person << " of Class: " << user.Class << endl;
		if (person == "[Teacher]")
		{
			displayline(length, 178, 0);
			displayline(length, 177, 0);
			CherAdminPanel(IDglobal);
		}
		else
		{
			StudentPortal(table);
		}
		cout << "Do you want to EXIT this programme [E] Or Sign in again [S]";
		cin >> retry;
	}

	return 0;
}



void StudentPortal(const vector<userdataformat> table)
{
	int index = ObtainInfomain(table, IDglobal);
	int choice;
	displayline(100, 178, 0);
	displayline(100, 177, 0);
	centretext("STUDENT MAIN PAGE:", 100); cout << endl;
	displayline(100, 176, 0); cout << endl;
	centretext("Welcome to the main Student Page", 100); cout << "\n";
	char retry = 'N';
	do
	{
		centretext("OPTION 1: MATHETMATICS", 100); cout << endl;
		centretext("OPTION 2: SCIENCE", 100); cout << endl;
		centretext("OPTION 3: View Score History", 100); cout << endl;
		centretext("OPTION 4: SEND EMAIL TO PEOPLE", 100); cout << endl;
		cout << "You Pick: ";
		while (true)
		{
			if (cin >> choice) //error catching.
			{
				vector<userpointformat> mtsci = readffmark("markscience.txt");
				if (choice == 1)
				{
					MathPortal(IDglobal, table[index].displayname);
					break;
				}
				else if (choice == 2)
				{
					double percentscore = scienceportal();
					addmark(mtsci, index, percentscore);
					writetfmark("markscience.txt", mtsci);
					break;
				}
				else if (choice == 3)
				{
					bool math;
					char choice2;
					cout << "View Math or Science? [M/S]: ";
					while (true)
					{
						while (!(cin >> choice2))
						{
							cout << "invalid Expression, retry: ";
							cin.clear();
							cin.ignore();
						}
						if (choice2 == 'M')
						{
							math = true;
							break;
						}
						else if (choice2 == 'S')
						{
							math = false;
							break;
						}
						else
						{
							cout << "Invalid";
						}
					}
					displaymarkdata(math, IDglobal, index, mtsci);
					break; //end of 3rd option.
				}
				else if (choice == 4)
				{
					inbox(false, table, IDglobal);
					break;
				}
			}
			cin.ignore();
			cin.clear();
			cout << "Option chosen doesn't exist\nYou Pick: ";
		}
		cout << "\nDo you want to continue? [Y/N]: ";
		cin >> retry;
	} while (retry != 'n' && retry != 'N');
	//then waiting for then function.
}
//_____________________________________________________________________________________________________//#include "FunctionList.h" //Header that includes all my functions in SaveFunctions.cpp
 //vectors are a dynamical array, more safer than raw arrays, in some cases D:
using namespace std;
string IDglobal = "NO_USER_FOUND"; //global variable this thing get's called all the time lol.
int main()
{
	char retry = 'S';
	while (retry == 'S')
	{
		string person;
		int length = 100;
		vector<userdataformat> table = ReadUsersffmain("Userbase.txt");
		userdataformat user = mainmenu(table);
		IDglobal = user.IDff;
		if (cherorstud(user.IDff[0]))
		{
			person = "[Teacher]";
		}
		else person = "[Student]";
		cout << "\nLogin Successful! Welcome " << user.displayname << ' ' << person << " of Class: " << user.Class << endl;
		if (person == "[Teacher]")
		{
			displayline(length, 178, 0);
			displayline(length, 177, 0);
			CherAdminPanel(IDglobal);
		}
		else
		{
			StudentPortal(table);
		}
		cout << "Do you want to EXIT this programme [E] Or Sign in again [S]";
		cin >> retry;
	}

	return 0;
}



void StudentPortal(const vector<userdataformat> table)
{
	int index = ObtainInfomain(table, IDglobal);
	int choice;
	displayline(100, 178, 0);
	displayline(100, 177, 0);
	centretext("STUDENT MAIN PAGE:", 100); cout << endl;
	displayline(100, 176, 0); cout << endl;
	centretext("Welcome to the main Student Page", 100); cout << "\n";
	char retry = 'N';
	do
	{
		centretext("OPTION 1: MATHETMATICS", 100); cout << endl;
		centretext("OPTION 2: SCIENCE", 100); cout << endl;
		centretext("OPTION 3: View Score History", 100); cout << endl;
		centretext("OPTION 4: SEND EMAIL TO PEOPLE", 100); cout << endl;
		cout << "You Pick: ";
		while (true)
		{
			if (cin >> choice) //error catching.
			{
				vector<userpointformat> mtsci = readffmark("markscience.txt");
				if (choice == 1)
				{
					MathPortal(IDglobal, table[index].displayname);
					break;
				}
				else if (choice == 2)
				{
					double percentscore = scienceportal();
					addmark(mtsci, index, percentscore);
					writetfmark("markscience.txt", mtsci);
					break;
				}
				else if (choice == 3)
				{
					bool math;
					char choice2;
					cout << "View Math or Science? [M/S]: ";
					while (true)
					{
						while (!(cin >> choice2))
						{
							cout << "invalid Expression, retry: ";
							cin.clear();
							cin.ignore();
						}
						if (choice2 == 'M')
						{
							math = true;
							break;
						}
						else if (choice2 == 'S')
						{
							math = false;
							break;
						}
						else
						{
							cout << "Invalid";
						}
					}
					displaymarkdata(math, IDglobal, index, mtsci);
					break; //end of 3rd option.
				}
				else if (choice == 4)
				{
					inbox(false, table, IDglobal);
					break;
				}
			}
			cin.ignore();
			cin.clear();
			cout << "Option chosen doesn't exist\nYou Pick: ";
		}
		cout << "\nDo you want to continue? [Y/N]: ";
		cin >> retry;
	} while (retry != 'n' && retry != 'N');
	//then waiting for then function.
}
//_____________________________________________________________________________________________________//
