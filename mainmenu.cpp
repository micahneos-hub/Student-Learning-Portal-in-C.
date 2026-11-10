#include "FunctionList.h" //connects to header

void alldata(vector<userdataformat>& Table)
{
	string input;
	vector<int> classpick;
	int classchoice, g;
	char seepasswords, choice2;
	displayline(60, 178, 0);
	cout << "\nOptions:\nT. Teachers[T]\nS. Students[S]\nA. All Users[default]\n";
	cin >> choice2;
	cout << "See passwords: Y\n";
	cin >> seepasswords;
	cout << "See specific Classes[1]? or All classes[2]: ";
	cin >> classchoice;
	if (classchoice == 1)
	{
		bool retry;
		do
		{
			retry = false;
			cout << "Which Classes, input multiple if necessary:\nYou Pick : [ ";
			cin.ignore(1000, '\n'); //sometimes it triggers and infinite loop due to it not clearing the entire buffer.
			getline(cin, input);
			string line = input + "You Pick : [   ";
			cout << "\x1b[A" << "\x1b[" << line.size() << "G" << "]\n"; // and then i basically tell the cursor to move up and to go until the end of the line and insert ']'.
			istringstream parseline(input); //sorry cher, i know you hate me doing this but this is necessary, for an option that scales.
			while (!parseline.eof())
			{
				if (!(parseline >> g)) //error catching!!!!!!
				{
					cin.ignore(1000, '\n');
					cin.clear();
					retry = true;
					break; // GET BACK INTO INPUTTING THAT AGAIN.
				}
				classpick.push_back(g);
			}
		} while (retry);
	}
	bool empty = true;
	if (!classpick.empty()) //if no class is chosen lol.
	{
		empty = false;
	}
	cout << left << setw(20) << "ID Number" << setw(20) << "DisplayName";
	if (seepasswords == 'Y')
	{
		cout << setw(20) << "Passwords";
	}
	cout << setw(20) << "Class" << endl;
	bool inlist;
	if (choice2 == 'T' || choice2 == 'S' || choice2 == 't' || choice2 == 's') //see specific students/teachers.
	{
		for (int row = 0; row < Table.size(); row++)
		{
			inlist = false;
			if (!empty)
			{
				for (int lp = 0; lp < classpick.size(); lp++) //check if you're in the Class specification.
				{
					if (classpick[lp] == Table[row].Class)
					{
						inlist = true;
					}
				}
			}
			else inlist = true;
			if (Table[row].IDff[0] == choice2 && inlist)
			{
				cout << setw(20) << Table[row].IDff << setw(20) << Table[row].displayname;
				if (seepasswords == 'Y')
				{
					cout << setw(20) << Table[row].passff; //output Password.
				}
				cout << setw(20) << Table[row].Class << endl;
			}
		}
	}
	else //see all users.
	{
		for (int row = 0; row < Table.size(); row++)
		{
			inlist = false;
			if (!empty)
			{
				for (int lp = 0; lp < classpick.size(); lp++) //check if you're in the Class specification.
				{
					if (classpick[lp] == Table[row].Class)
					{
						inlist = true;
					}
				}
			}
			else inlist = true;
			if (inlist)
			{
				cout << setw(20) << Table[row].IDff << setw(20) << Table[row].displayname;
				if (seepasswords == 'Y')
				{
					cout << setw(20) << Table[row].passff; //output Password.
				}
				cout << setw(20) << Table[row].Class << endl;
			}
		}
	}
}

void CherAdminPanel(const string& ID)
{
	vector<userdataformat> Table = ReadUsersffmain("Userbase.txt");
	//Example build.
	int choice;
	char goagain = 'Y';
	while (goagain == 'Y')
	{
		cout << "\nOPTIONS:\n 1. Edit User\n 2. Add user\n 3. Remove User\n 4. See List of Users\n 5. View Inbox\n You Pick: ";
		cin >> choice;
		switch (choice)
		{
		case 1: // Update User Information.
		{
			string IDhere, input;
			bool cont;
			userdataformat Structure;
			cont = false;
			bool retry;
			do
			{
				retry = false;
				cout << "\nID number: ";
				cin >> IDhere;
				string IDclose = didyoumean(IDhere); //check if ID was inputted correctly.
				if (IDclose == "fail")
				{
					retry = true;
				}
				else if (IDclose != "noidfound")
				{
					if (IDclose != "same")
					{
						char replace;
						cout << "Did you mean: " << IDclose << "? [Y/N]\n";
						cin >> replace;
						if (replace == 'Y')
						{
							IDhere = IDclose;
						}
					}
				}
				int index = ObtainInfomain(Table, IDhere);
				if (index != -1) //If there is no user.
				{
					cout << left << setw(20) << "ID No." << setw(20) << "Password:" << setw(20) << "Displayname:" << "Class:" << endl
						<< setw(20) << Table[index].IDff << setw(20) << Table[index].passff << setw(20) << Table[index].displayname << Table[index].Class << endl << right << endl
						<< "Edit: ID-number [1], Password [2], or Displayname [3], or Class [4] or [5] to change editing user/exit:\n";
					displayline(30, 177, 0);
					cout << "\n\nYou Pick : [ ";
				}
				else
				{
					cout << "\nThis User Does Not Exist!\n";
					retry = true;
				}
			} while (retry);
			cin.ignore(1000, '\n'); //sometimes it triggers and infinite loop due to it not clearing the entire buffer.
			getline(cin, input);
			string line = input + "You Pick : [   ";
			cout << "\x1b[A" << "\x1b[" << line.size() << "G" << "]\n"; // and then i basically tell the cursor to move up and to go until the end of the line and insert ']'.
			for (int i = 0; i < input.size(); i++) //continues until chosen not to.
			{
				if (input[i] == '1') //UPDATE ID.
				{
					cout << "New: ";
					Structure.IDff = IDinputprocess(Table, 1);
				}
				else if (input[i] == '2') //UPDATE PASSWORD.
				{
					cout << "New:\nPassword: ";
					cin >> Structure.passff;
				}
				else if (input[i] == '3') //UPDATE DISPLAYNAME.
				{
					cout << "New\nDisplayname: ";
					cin >> Structure.displayname;
				}
				else if (input[i] == '4') //UPDATE CLASS.
				{
					bool retry;
					int ans;
					classdisplay(Table);
					do
					{
						retry = false;
						cout << "New\nClass: ";
						cin >> Structure.Class;
						ans = validclass(Structure.Class, IDhere, Table);
						if (ans == -1)
						{
							retry = true;
						}
						else if (ans != Structure.Class)
						{
							char choice;
							cout << "\nWould you like to replace class? Y/N: ";
							cin >> choice;
							if (choice == 'Y')
							{
								Structure.Class = ans;
							}
						}
					} while (retry);
				}
				else if (input[i] == '5')
				{
					cout << "Exiting... this page:" << endl;
					break;
				}
			}
			if (!cont)
			{
				if (updatethisusermain(Table, IDhere, Structure))
				{
					cout << "\nThe User has been edited to have:\n";
					if (Structure.IDff != "if this is shown, an error has occured") //If this is not empty.
					{
						cout << "an ID of: " << Structure.IDff << endl;
					}
					if (Structure.passff != "if this is shown, an error has occured")
					{
						cout << "a password of: " << Structure.passff << endl;
					}
					if (Structure.displayname != "if this is shown, an error has occured")
					{
						cout << "a displayname of: " << Structure.displayname << endl;
					}
					if (Structure.Class != -1)
					{
						cout << "a class of: " << Structure.Class << endl;
					}
				}
			}
			givebacktfmain("Userbase.txt", Table);
			break;
		}
		case 2: //Add neww users:
		{
			int studentam;
			userdataformat Structure;
			cout << "How many students to add to the Database: ";
			cin >> studentam;

			for (int i = 1; i <= studentam; i++)
			{
				NewUserUi(Table, 1);
			}
			cout << "\nSuccessfully Added: " << studentam << " new Users.";
			givebacktfmain("Userbase.txt", Table);
			break;
		}
		case 3: //Delete User information.
		{
			vector<userpointformat> marktmath = readffmark("markmath.txt"), marktsci = readffmark("markscience.txt");
			//EXTRACT INFORMATION ABOVE;
			string IDhere;
			bool retry;
			do
			{
				retry = false;
				cout << "\nID: ";
				cin >> IDhere;
				string IDclose = didyoumean(IDhere); //too lazy to make this an actual function.
				if (IDclose == "fail")
				{
					retry = true;
				}
				else if (IDclose != "noidfound")
				{
					if (IDclose != "same")
					{
						char replace;
						cout << "Did you mean: " << IDclose << "? [Y/N]\n";
						cin >> replace;
						if (replace == 'Y')
						{
							IDhere = IDclose;
						}
					}
				}
				// didyoumean function ends here.
				if (removethisusermain(Table,marktmath, marktsci, IDhere))
				{
					cout << "Account Deleted...";
					break;
				}
				else cout << "This User does not exist\n\n";
			} while (retry);
			givebacktfmain("Userbase.txt", Table);
			writetfmark("markmath.txt", marktmath);
			writetfmark("markscience.txt", marktsci);
			break;
		}
		case 4:
		{
			//see all data;
			alldata(Table);
			break;
		}
		case 5:
		{
			inbox(true, Table, ID);
			break;
		}
		default:
		{
			cout << "Invalid Expression Received";
		}
		}
		cout << "\nDo you want to process more users: Y/N\n";
		cin >> goagain;
		//Teachers should be able to view, write, delete, and or create new accounts for students.
	}
}

void inbox(bool teacher, const vector<userdataformat>& table, const string& ID)
{
	vector<userpointformat> sciencetable = readffmark("markscience.txt");
	cout << left;
	int index = ObtainInfomain(table, ID);
	if (teacher)
	{
		vector<userpointformatmathvec> usermathtable = readffmathmark();
		displayline(100, 178, 0);

		cout << " TEACHER INBOX: WELCOME " << table[index].displayname << " Of Class: " << table[index].Class << " ID: " << table[index].IDff << "\n\n" << "[	inbox: Users who are Below score range:" << "\n\n";
		//figure out inbox
		for (int comb = 0; comb < usermathtable.size(); comb++)
		{
			if (usermathtable[comb].maverage < 50)
			{
				int indexed = ObtainInfomain(table, usermathtable[comb].id);
				if (table[indexed].Class == table[index].Class) //check if the student's class is the same as the teachers.
				{
					cout << "[Mathematics]:" << setw(10) << "User ID: " << usermathtable[comb].id << setw(15)
						<< "| Username: " << table[indexed].displayname << setw(10)
						<< "| Class: " << table[indexed].Class << endl;
				}
			}
		}
		for (int comb = 0; comb < sciencetable.size(); comb++)
		{
			int sum = 0;
			if (sciencetable[comb].mrks[0] != -1)
			{
				for (int through = 0; through < sciencetable[comb].mrks.size(); through++)
				{
					sum += through;
				}
				if (sum / sciencetable[comb].mrks.size() < 50 && table[comb].Class == table[index].Class)//check if the student's class is the same as the teachers.
				{
					cout << "[Science]:" << setw(10) << "User ID: " << table[comb].IDff << setw(15)
						<< "| Username: " << table[comb].displayname << setw(10)
						<< "| Class: " << table[comb].Class << endl;
				}
			}
		}
	}
	else
	{
		cout << " STUDENT INBOX: WELCOME " << table[index].displayname << " Of Class: " << table[index].Class << " ID: " << table[index].IDff << "\n\n" << "	inbox: received:" << "\n\n";
	}
	//inbox moment.
	int indexer = 0;
	bool found = false;
	vector<useremails> emailtable = reademails();
	for (size_t comb = 0; comb < emailtable.size(); comb++)
	{
		if (emailtable[comb].id == ID)
		{
			found = true;
			indexer = comb;
		}
	}
	if (found) //if there are emails, at all.
	{
		cout << "You have: " << emailtable[indexer].etext.size() << " Emails." << endl;
		for (size_t comb = 0; comb < emailtable[indexer].etext.size(); comb++)
		{
			cout << "[Email]: " << " from[" << emailtable[indexer].etext[comb].senderid << "]: " << emailtable[indexer].etext[comb].text << endl;
		}
	}
	else
	{
		cout << "You have: No Emails. Consider writing some." << endl;
	}
	int choice;
	cout << "\nClear Emails [1], Write Email [2], Exit [any other No.]: ";
	while (true)
	{
		while (!(cin >> choice))
		{
			cout << "Invalid Expression, try again: ";
			cin.clear();
			cin.ignore();
		}
		if (choice == 1)
		{
			cout << "Clearing Emails..." << endl;
			if (clearemail(ID, emailtable)) break;
		}
		else if (choice == 2)
		{
			char choice43;
			cout << "see Library of Users? [Y/N]: ";
			while (!(cin >> choice43))
			{
				cin.clear();
				cin.ignore();
			}
			if (choice43 == 'Y')
			{
				for (int i = 0; i < table.size(); i++)
				{
					if (table[i].Class == table[index].Class)
					{
						if (table[i].IDff[0] == 'T')
						{
							cout << "ID:" << table[i].IDff << " Username: " << table[i].displayname << endl;
						}
						if (teacher && table[i].IDff[0] == 'S')
						{
							cout << "ID:" << table[i].IDff << " Username: " << table[i].displayname << endl;
						}
					}
				}
				cout << "\n";
				displayline(100, '_', 0);
			}
			string to;
			while(true)
			{
				cout << "To: ";
				while (!(cin >> to))
				{
					cout << "Invalid Input, retry: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max());
				}
				string meant = didyoumean(to);
				if (meant == "fail");
				else if (meant != "noidfound")
				{
					if (meant != "same")
					{
						char replace;
						cout << "Did you mean: " << meant << "? [Y/N]\n";
						cin >> replace;
						if (replace == 'Y')
						{
							to = meant;
						}
					}
					break;
				}
			}
			cout << "From: " << ID << endl;
			cout << "Letter: ";
			cin.ignore();
			string line;
			getline(cin, line);
			cout << "\nPress Enter again to continue.";
			if (writeemail(line, to, ID, table))
			break;
			else
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		else
		{
			cout << "Exiting Programme...";
			break;
		}
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return;
}


string checkifsignedin()
{
	ifstream read("Signin.txt");
	string IDfromfile = "";
	read >> IDfromfile;
	return IDfromfile;
}
void signinff(const string IDnew)//do not put const here.
{
	ofstream write("Signin.txt");
	write << IDnew;
}

string didyoumean(const string ID) //outputs noidfound, fail, for when it can't find the ID, or when the ID length is bad, returns the name of the closest user too.
{
	if (ID.size() != 7) //to make sure the arrays of the ID are the exact same.
	{
		cout << "It appears the ID has an invalid length.\n";
		return "fail";
	}
	if (ID[0] != 'S' && ID[0] != 'T')
	{
		cout << "Invalid User ID\n";
		return "fail";
	}
	int checkint;
	istringstream numraw(ID.substr(1)), numffr; // For checking later, hehe.
	if (!(numraw >> checkint) || !numraw.eof()) // If you can't put the string into checkint, an int, you fail the condition. and if can't read, fail.
	{
		cout << "\nID is invalid due to invalid Numeric\n"; //check for T/S infront of the characters.
		return "fail";
	}
	vector<userdataformat> table = ReadUsersffmain("Userbase.txt");
	string resultname = "noidfound"; //placeholder for when the id isn't similar.
	double accuracy = 0, highest = 4;
	for (int index = 0; index < table.size(); index++)
	{
		accuracy = 0;
		for (int i = 0; i < ID.size(); i++) //algorithm
		{
			if (ID[i] == table[index].IDff[i])
			{
				accuracy++;
			}
		}
		accuracy = accuracy - sqrt(pow(checkint - stoi(table[index].IDff.substr(1)), 2)); //absolute difference.
		if (accuracy > highest)
		{
			resultname = table[index].IDff;
			highest = accuracy;
			if (highest == 7)
			{
				return "same";
			}
		}
	}
	return resultname;
}

userdataformat mainmenu(vector<userdataformat>& table)
{
	userdataformat answers;
	int length = 100, choicems;
	displayline(length, 178, 0);
	displayline(length, 177, 0);
	centretext(R"(__        __   _                            _         )", length); cout << endl; //inefficient mess.
	centretext(R"(\ \      / /__| | ___ ___  _ __ ___   ___  | |_ ___   )", length); cout << endl; //keep hearing about centering divs, i wonder what they mean by that.
	centretext(R"( \ \ / \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \  )", length); cout << endl;
	centretext(R"(  \ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) | )", length); cout << endl;
	centretext(R"(   \_/\_/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/  )", length); cout << endl;
	centretext("THE STUDENT LEARNING PORTAL", length); cout << endl;
	displayline(length, 177, 0);
	displayline(length, 178, 0);
	//Display options to pick from:
	centretext("[1] Sign in to an existing account, [2] or sign up for an account: ", length);
	cin >> choicems;
	switch (choicems)
	{
	default:
	{
		char choic = 'Y';
		string IDfc = checkifsignedin();
		if (IDfc != "")
		{
			int index = ObtainInfomain(table, IDfc);
			string message = "You were signed in from a previous account of " + table[index].displayname + " do you wish to sign in again? [Y/N]: ";
			centretext(message, length);
			answers = table[index];
			cin >> choic;
		}
		else cout << setw(30) << "Sign In:" << endl << setw(50) << "Either as a student (S), or as a teacher (T)." << endl << endl;
		displayline(length, 177, 0); cout << endl;
		while (choic == 'Y') //Until Success.
		{
			bool retry;
			do
			{
				retry = false;
				cout << setw(30) << "[ User-Identity: ";
				cin >> answers.IDff;
				string line =  "               [ User-Identity: " + answers.IDff; //FORMATTING SHENANIGANS LOL, 11 spaces.
				cout << "\x1b[A" << "\x1b[" << line.size() << "G" << "]\n"; // and then i basically tell the cursor to move up and to go until the end of the line and insert ']'.
				string IDclose = didyoumean(answers.IDff);
				if (IDclose == "fail")
				{
					retry = true;
				}
				else if (IDclose != "noidfound")
				{
					if (IDclose != "same")
					{
						char replace;
						cout << "Did you mean: " << IDclose << "? [Y/N]\n";
						cin >> replace;
						if (replace == 'Y')
						{
							answers.IDff = IDclose;
						}
					}
				}
			} while (retry);
			cout << setw(30) << "[      Password: ";
			cin >> answers.passff;
			string line = "                    [ Password: " + answers.passff;
			cout << "\x1b[A" << "\x1b[" << line.size() << "G" << "]\n";
			if (isindatabase(answers.IDff, answers.passff))
			{
				signinff(answers.IDff);
				int index = ObtainInfomain(table, answers.IDff);
				answers.displayname = table[index].displayname; //replaces the struct, since they are already the same lol.
				answers.Class = table[index].Class;
				break;
			}
			else
			{
				cout << "\nLogin Unsuccessful, either Password or Username was incorrect.\nTry again!\n" << endl;
			}
		}
		break;
	}
	case 2:
	{
		answers = NewUserUi(table, 0);
		break;
	}
	}
	return answers;
}

void centretext(string text, int length)
{
	int subwid = static_cast<int>(length - text.length()); //a warning appeared here, clicked on the link that went to the documentation and found that i need to make this a static_cast?
	int width = static_cast<int>((subwid-subwid%2)/2+text.length()); //static cast forces it to be int.
	if (length < 0)
	{
		cout << "ERROR, TEXT LONGER THAN THE GIVEN LENGTH.";
	}
	else
	{
		cout << right;
		cout << setw(width) << text;
	}
}

bool isindatabase(string ID, string password)
{
	ifstream intocpp;
	intocpp.open("Userbase.txt");
	if (!intocpp)
	{
		cout << "\nCould not open Database!\n";
		return false; //Error catching;
	}

	string line, IDinFile, passinfile;
	while (getline(intocpp, line)) //grabs the entire row of words, including spaces, jams it into one string.
		//getline(intocpp,line) is a boolean, if it can read a line, it's true. if it can't, like if it's at the end of a line, it returns false.
	{
		istringstream lol(line);
		// this variable turns "line" string into a stream, stored as a variable which i called lol, inside the while.
		lol >> IDinFile >> passinfile; //Now the lol, variable (which is treated like a stream) can now only seperate the IDinFile and passinfile directly ignoring the rest.
		if (IDinFile == ID && passinfile == password)
		{
			intocpp.close();
			return true;
		}
	}
	intocpp.close();
	return false;
}

bool cherorstud(char role)
{
	if (role == 'T') return true;
	else return false;
}

void displayline(int length, int text, int width)
{
	unsigned char car = static_cast<unsigned char>(text); //the reason why this char is unsigned is because if it was it would only have -128 to 127 possible states
	// additionally i want the compiler to stop screaming at me
	// making it an unsigned allows it to hold until 255, which is necessary for ASCII, signing an integer takes an extra "bit" LOL.
	// IT'S STILL SCREAMING AT ME WHY ARE YOU DOING THAT

	cout << right << setw(width) << "";
	for (int i = 0; i < length; i++)
	{
		cout << car;
	}
	cout << endl;
}

void displaymarkdata(bool math, const string& ID, const int& index, const vector<userpointformat>& sciencedatatable)
{
	int instance;
	double score = 0;
	if (math) //do math;
	{
		userpointformatmathvec mathdata = readffmathmarkmini(ID);
		if (!mathdata.sumofvect.empty())
		{
			double sumtime = 0;
			int adv = 0, inter = 0, beg = 0;
			cout << "To how many instances? [0 to " << mathdata.sumofvect.size() << "]: ";
			while (true)
			{
				if (!(cin >> instance))
				{
					cout << "Invalid Expression, retry: ";
					cin.clear();
					cin.ignore();
				}
				else if (instance < 1 || instance > mathdata.sumofvect.size())
				{
					cout << "Out of range, retry: ";
				}
				else break;

			}
			cout << left << setw(10) << "instance: " << setw(10) << "score" << setw(20) << "time-taken" << setw(20) << "Topic" << "Difficulty" << endl;
			for (int a = 0; a < instance; a++)
			{
				cout << setw(10) << a << setw(10) << mathdata.sumofvect[a].mrks << setw(10) << mathdata.sumofvect[a].time << setw(20) << mathdata.sumofvect[a].topic << mathdata.sumofvect[a].difficulty << endl;
				sumtime += mathdata.sumofvect[a].time;
				score += mathdata.sumofvect[a].mrks;
				if (mathdata.sumofvect[a].difficulty == "Advanced")
				{
					adv++;
				}
				else if (mathdata.sumofvect[a].difficulty == "Intermediate")
				{
					inter++;
				}
				else beg++;
			}
			cout << "Total Time spent: " << sumtime << endl
				<< "Total Accumulated Score: " << score << endl
				<< "Average Score per run: " << score / instance << endl
				<< "Global Average Score: " << mathdata.maverage << endl
				<< "Average Time per run: " << sumtime / instance << endl
				<< "Number of advanced diff: " << adv << "| intermediate diff: " << inter << "| beginner diff: " << beg << endl
				<< "Do you need special attention [";
			if (score / instance < mathdata.maverage)
			{
				cout << "Yes]." << endl;
			}
			else cout << "No]." << endl;
		}
		else cout << "You have no Record.\n";
	}
	else
	{
		double globalsum = 0, indivscore;
		int count = 0;
		userpointformat sciencedata = sciencedatatable[index];
		if (sciencedata.mrks[0] != -1)
		{
			cout << "To how many instances? [0 to " << sciencedata.mrks.size() << "]: ";
			while(true)
			{
				if (!(cin >> instance))
				{
					cout << "Invalid Expression, retry: ";
					cin.clear();
					cin.ignore();
				}
				else if (instance < 1 || instance > sciencedata.mrks.size())
				{
					cout << "Out of range.";
				}
				else break;

			}
			cout << left << setw(10) << "instance: " << "score" << endl;
			for (int a = 0; a < instance; a++)
			{
				cout << setw(10) << a << sciencedata.mrks[a] << endl;
				score += sciencedata.mrks[a];
			}
			cout << "Total Accumulated Score: " << score << endl
				<< "Average Score per Run: " << score / instance << endl
				<< "Global Average Score: ";

			for (int l = 0; l < sciencedatatable.size(); l++)
			{
				for (int g = 0; g < sciencedatatable[l].mrks.size(); g++)
				{
					indivscore = sciencedatatable[l].mrks[g];
					if (indivscore != -1)
					{
						globalsum += indivscore;
						count++;
					}
				}
			}
			double ave = globalsum / count;
			cout << ave << endl
				<< "Do you need special attention [";
			if (score < ave)
			{
				cout << "Yes]." << endl;
			}
			else cout << "No]." << endl;
		}
		else cout << "You have no Record.\n";
	}
	return;
}
