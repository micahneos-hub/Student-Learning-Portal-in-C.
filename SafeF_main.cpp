#include "FunctionList.h" //connects to header.

//_____________________________________________________________________________________________________________________________________________\\
//														//
//		FUNCTION TO READ THE ENTIRE FILE FOR USE:		// "const" is there to make the function promise you NOT to change the string, at the same time, &, alias, is like
//														// int x = 5; int& y = x; y = 10; Now x = 10. y is just another name for x. wow.
vector<userdataformat> ReadUsersffmain(const string& Userbase) // The reason why we make an alias is to avoid copying it, to save memory and processing. C++ makes a copy of stuff lol idk when you're inputting it into a function i think.
{
	vector<userdataformat> UserRn; //Creates a vector to save data into.
	ifstream ifile(Userbase); //Tries to open the file that you type into the vector command immediately for reading.
	if (!ifile)
	{
		cout << "file doesn't exist";
	}
	else
	{
		string line2;
		while (getline(ifile, line2)) //Reads until all lines have been exhausted.
		{
			istringstream line(line2);
			userdataformat user; // Creates an object to associate to the structure.

			line >> user.IDff >> user.passff >> user.displayname >> user.Class; // ADD MORE STRUCTURE STUFF HERE WHEN UPDATING "CurrentUser" in future.
			UserRn.push_back(user); // Feeds the structure into the empty vector.
		}
	}
	ifile.close();
	return UserRn; //Returns the ENTIRE vector.
}



//_____________________________________________________//

//		What to input:
//		Input the database name, and the vector UserRn, which is collected from the function ReadUsersff().
//		Remember to store the data from UserRn into a vector in the structure vector<CurrentUser> variable = ReadUsersff("Userbase.txt

void givebacktfmain(const string& Userbase, const vector<userdataformat>& UserRn) //"tf" meaning "to file."
{
	ofstream outfile(Userbase); //Opens Userbase immediately for editing.
	if (!outfile)
	{
		cout << "file doesn't exist";  return;
	}
	for (int i = 0; i < UserRn.size(); i++) //Repeats the function until the i reaches the size of the array, or the end as you would call it. UserRn is the whole table, currentuser is format, user is the struct.
	{
		const userdataformat& user = UserRn[i]; //I get it now, it's so beautiful. const is to make it read only, & is to prevent C++ from making it a copy.
		//and it would paste the struct data from UserRn[ in this particular cell ] to the CurrentUser Structure which would format it in ID, Password... e.t.c; it's called structure for a reason.
		outfile << user.IDff << " " << user.passff << " " << user.displayname << " " << user.Class;
		if (i < UserRn.size() - 1)
		{
			outfile << endl;
		}
	}
	outfile.close();
}
//_____________________________________________________//

//		What to input:
//		Input Vector that you're going to edit: UserRn, and then the struct data of the new user.
//

void newUser(vector<userdataformat>& UserRn, const userdataformat& newUser) // vector isn't const, cuz you're changing it dumbass.
{
	UserRn.push_back(newUser); //Place the new user, in the format of the Structure, CurrentUser, into the Vector.
	addidtomark("markmath.txt");
	addidtomark("markscience.txt");
}							   // Don't need to open the file because you're just updating the vector.
//_____________________________________________________//

bool updatethisusermain(vector<userdataformat>& UserRn, const string& ID, const userdataformat& Upd_info_user) //This function will only update what is given. You give ID, it saves it.
{
	for (int i = 0; i < UserRn.size(); i++)
	{
		userdataformat& user = UserRn[i]; // Reference to the element/structure inside the vector, i.e the ID of the position in the vector, and info in that structure.
		if (user.IDff == ID)
		{
			if (Upd_info_user.passff != "if this is shown, an error has occured") // only does this if the variable entered here is not empty.
			{
				user.passff = Upd_info_user.passff; //Changes the data ONLY IN this USER in the row i. Nothing else.
			}
			if (Upd_info_user.displayname != "if this is shown, an error has occured")
			{
				user.displayname = Upd_info_user.displayname; //Changes data only this user in row i about displayname.
			}
			if (Upd_info_user.IDff != "if this is shown, an error has occured")
			{
				user.IDff = Upd_info_user.IDff; //you get it.
			}
			if (Upd_info_user.Class != -1)
			{
				user.Class = Upd_info_user.Class; //you get it.
			}
			return true;
		}
	}
	return false; // for failure in seeing the ID.
}
//_____________________________________________________//

bool removethisusermain(vector<userdataformat>& UserRn, vector<userpointformat>& marktablemath, vector<userpointformat>& marktablescience, const string& ID) // Don't need Const currentUser& cuz you're not referencing the structure, you're deleting the row, from vector directly.
{
	for (int i = 0; i < UserRn.size(); i++)
	{
		userdataformat& user = UserRn[i];
		if (user.IDff == ID)
		{
			UserRn.erase(UserRn.begin() + i); //UserRn.begin(), is an iterator/pointer. You can convert an index/number into a pointer, you need it for the function .erase(). need iterators to know which position to modify.
			//using UserRn.begin() which points to the first element. 0, and then add i to move along the array.
			marktablemath.erase(marktablemath.begin() + i);
			marktablescience.erase(marktablescience.begin() + i);
			return true;//Vectors are freaking strange dawg, they're like an array, storing datatypes like struct/int/char, whatever, and then to manually access something you need a pointer.
			//And vector[i] acts like a reference for struct, which is kidna like a pointer, but isn't.
		}
	}
	return false; //Can't find user.
}
//_____________________________________________________//
int ObtainInfomain(const vector<userdataformat>& Table, const string& ID)
{
	for (int num = 0; num < Table.size(); num++)
	{
		if (Table[num].IDff == ID) //compares ID directly from table.
		{
			return num; //returns the index of the element in the vector.
		}
	}
	return -1; // Returns -1 if there is no index.
}

//________________________________________________________//

string IDinputprocess(const vector<userdataformat>& Table, int type) //Just like... seperated the functions cuz it looks nicer.
{
	bool valid;
	userdataformat Structure;
	cout << "\nIdentity Number:\n";
	int checkint;
	do
	{
		valid = true;
		cin >> Structure.IDff;
		if (Structure.IDff.size() != 7)
		{
			cout << "\nInvalid ID Length\n";
			valid = false;
		}
		if (Structure.IDff[0] != 'S' && Structure.IDff[0] != 'T')
		{
			cout << "\nInvalid User ID\n";
			valid = false;
		}
		istringstream numraw(Structure.IDff.substr(1)); // For checking later, hehe.
		if (!(numraw >> checkint) || !numraw.eof()) // If you can't put the string into checkint, an int, you fail the condition. and if can't read, fail.
		{
			cout << "\nID is invalid due to invalid Numeric\n";
			valid = false;
		}
		for (int a = 0; a < Table.size(); a++) //Checks if the name is already in the file.
		{
			if (Table[a].IDff == Structure.IDff) //checking file.
			{
				valid = false;
				cout << "\nThis ID has been taken\n";
				break;
			}
		}
		if (type == 0 && Structure.IDff[0] == 'T') //Type is stuff right now lol
		{
			cout << "\nAuthority not given to assign roles\nPlease ask a staff member to change your ID to a teacher\n";
			valid = false;
		}
	} while (!valid); //checks the condition AFTER the code block above.
	//if the condition in the while is true, it would do it again
	return Structure.IDff;
}

userdataformat NewUserUi(vector<userdataformat>& Table, int type)
{
	unsigned int block = 178;
	int choice;
	userdataformat Structure; //these Structure variables have no & because they're not referencing anything existing yet.
	bool valid = true;
	displayline(60, block, 0);
	cout << "\nEnter Custom ID [1], generate ID [2/default]: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		Structure.IDff = IDinputprocess(Table, type); //entire codebase here lol.
		break;
	}
	default:
	{
		if (!Table.empty())
		{
			bool used;
			int num = stoi(Table[Table.size() - 1].IDff.substr(1)) + 1; //grabs ID number only from the back of the table, converts it into int, adds 1.
			ostringstream idbuffer; //sstream for string manipulation. using <<;
			do
			{
				used = false;
				idbuffer << "S" << setw(6) << setfill('0') << num; // setw(6), basically says, in this width, i fill with 0's [setfill(0)] in the front if num < 100000;
				Structure.IDff = idbuffer.str(); //turns the ios stream into a string, for easier processing... using str(); provided in sstream library. str() treats sstream like a string.
				idbuffer.str(""); //replace the entire sstream with nothing.
				for (int a = 0; a < Table.size(); a++)
				{
					if (Structure.IDff == Table[a].IDff)
					{
						used = true;
						break;
					}
				}
				if (used && num < 999999) num++;
				else num -= 999999;
			} while (used);
		}
		else
		{
			cout << "\nTable is empty, error occured.\n";
		}
		break;
	}
	}
	cout << "\nPassword: ";
	cin >> Structure.passff;
	cout << "\nDisplay Name: ";
	cin >> Structure.displayname;
	bool retry;
	int ans;
	classdisplay(Table);
	do
	{
		retry = false;
		cout << "\nClass: ";
		cin >> Structure.Class;
		ans = validclass(Structure.Class, Structure.IDff, Table); //valid class gives a valid class instead.
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

	newUser(Table, Structure);
	signinff(Structure.IDff);
	givebacktfmain("Userbase.txt", Table);
	return Structure;
}


int validclass(const int classnum, const string IDhere,const vector<userdataformat>& Table) //Returns your original classnum if it succeeds, fails, returns -1, and if it finds a suitable class, returns that class id
{
	struct role
	{
		int id = -1;
		int t = 2;
		int s = 10;
	};
	vector<int> classcounteach;
	vector<int> classcount;
	vector<role> classnotfull;
	int highest = 0;; //INT_MAX, gives the maximum integer.
	for (int i = 0; i < Table.size(); i++)
	{
		if (Table[i].Class > highest)
		{
			highest = Table[i].Class; //gets class.
		}
	}
	int max_vector_size = highest + 1; //take into account index 0;
	classcounteach.assign(max_vector_size, 0); //assigns the amount of cells the vectors should have.
	classcount.assign(max_vector_size, 0);
	for (int count = 0; count < Table.size(); count++)
	{
		classcount[Table[count].Class]++; //since every index is aligned perfectly to each class, just count when the Table[count].class gives a number which is then assigned to the cell.
		if (Table[count].IDff[0] == 'T')
		{
			classcounteach[Table[count].Class]++;
		}
	}
	for (int a = 0; a < classcount.size(); a++)
	{
		bool save = false;
		role g;
		int cstudent = classcount[a] - classcounteach[a];
		if (cstudent < 10)
		{
			g.s = cstudent; //count of student.
			save = true;
		}
		if (classcounteach[a] < 2)
		{
			g.t = classcounteach[a];
			save = true;
		}
		if (save)
		{
			g.id = a;
			classnotfull.push_back(g);
		}
	}
	string person;
	if (classnum > highest) //basically saying, if the classnum you're registering to does not exist, and that a previous class still has available room, it would return the class with the lowest available slots.
	{
		if (classnotfull.size() != 1)
		{
			if (IDhere[0] == 'S')
			{
				person = " Student ";
			}
			else
			{
				person = " Teacher ";
			}
			cout << left << "\nThis class for this" << person << "doesn't exist yet, the classes available are classes: " << endl << setw(10) << "Class" << setw(10) << "Students" << "Teacher" << endl;
			for (int g = 1; g <	classnotfull.size(); g++)
			{
				if (classnotfull[g].id != -1)
				{
					cout << setw(10) << classnotfull[g].id << setw(10) << classnotfull[g].s << classnotfull[g].t << endl;
				}
			}
			return -1;
		}
		else
		{
			cout << "\nAll classes are full, please add a class that's after " << highest << endl;
			return highest + 1; //gives a class above the normal one.
		}
	}
	if (IDhere[0] == 'S')
	{
		if (classcount[classnum] - classcounteach[classnum] < 10) //if student and the class for students is less than 10, return the classnum as a valid option to put class number into.
		{
			return classnum; //student fits.
		}
		person = " Student ";
	}
	else
	{
		if (classcounteach[classnum] < 2)
		{
			return classnum; //basically saying, yeah that works, go with it!
		}
		person = " Teacher ";
	}
	cout << left << "\nThis class for this" << person << "is too full, the classes available are classes: " << endl << setw(10) << "Class" << setw(10) << "Students" << "Teacher" << endl;
	for (int g = 1; g < classnotfull.size(); g++)
	{
		if (classnotfull[g].id != -1)
		{
			cout << setw(10) << classnotfull[g].id << setw(10) << classnotfull[g].s << classnotfull[g].t << endl; //SORRY TEACHER
		}
	}
	return -1; //failure
}

void classdisplay(const vector<userdataformat> Table) // I KNOW THIS IS INEFFICIENT, PLEASE DON'T MARK ME DOWN. please i beg you.
{
	struct role
	{
		int id = -1;
		int t = 2;
		int s = 10;
	};
	vector<int> classcounteach;
	vector<int> classcount;
	vector<role> classnotfull;
	int highest = 0;; //INT_MAX, gives the maximum integer.
	for (int i = 0; i < Table.size(); i++)
	{
		if (Table[i].Class > highest)
		{
			highest = Table[i].Class; //gets class.
		}
	}
	int max_vector_size = highest + 1; //take into account index 0;
	classcounteach.assign(max_vector_size, 0); //assigns the amount of cells the vectors should have.
	classcount.assign(max_vector_size, 0);
	for (int count = 0; count < Table.size(); count++)
	{
		classcount[Table[count].Class]++; //since every index is aligned perfectly to each class, just count when the Table[count].class gives a number which is then assigned to the cell.
		if (Table[count].IDff[0] == 'T')
		{
			classcounteach[Table[count].Class]++; //so if the vector of our userbase.txt at index count, has a value of 1, which means class number 1, it would assign it to index 1 of clsascounteach
			//representing class 1 of classcount(each).
		}
	}
	for (int a = 0; a < classcount.size(); a++)
	{
		bool save = false;
		role g;
		int cstudent = classcount[a] - classcounteach[a];
		if (cstudent < 10) // checks if the count of students is in less than 10, the reason why this is here is because it checks whether if the class is full or not.
		{
			g.s = cstudent; //count of student.
			save = true;
		}
		if (classcounteach[a] < 2)
		{
			g.t = classcounteach[a];
			save = true;
		}
		if (save)
		{
			g.id = a;
			classnotfull.push_back(g);
		}
	}
	if (classnotfull.size() != 1)
	{
		cout << left << "\nAvailable Classes are: " << endl << setw(10) << "Class" << setw(10) << "Students" << "Teacher" << endl;
		for (int g = 1; g < classnotfull.size(); g++)
		{
			if (classnotfull[g].id != -1)
			{
				cout << setw(10) << classnotfull[g].id << setw(10) << classnotfull[g].s << classnotfull[g].t << endl;
			}
		}
	}
	else
	{
		cout << "No available classes... Please create a new class [" << highest + 1 << "]" << endl;
	}
}

//write emails
bool writeemail(const string& text, const string& ID, const string& IDsender, const vector<userdataformat>& table)
{
	int index = ObtainInfomain(table, ID);
	if (index == -1)
	{
		cout << "\nInvalid Teacher ID.";
		return false;
	}
	ofstream onfile("Email.txt", ofstream::app);
	onfile << '\n' << table[index].IDff << ' ' << IDsender << ' ' << text;
	cout << "Sent an Email to " << table[index].IDff << endl;
	onfile.close();
	return true;
}

//read emails;
vector<useremails> reademails()
{
	
	vector<useremails> emailtable;
	ifstream infile("Email.txt");
	string line, senderid;
	bool found;
	while (getline(infile, line)) //read email.
	{
		useremails email; //declare container for struct vect.
		istringstream parse(line); //figure out the email.id;
		parse >> email.id >> senderid;
		found = false; //prep
		useremail email1{ senderid, line.substr(16) }; //prep for etext.
		for (size_t comb = 0; comb < emailtable.size(); comb++) //search through email usertable.
		{
			if (emailtable[comb].id == email.id) //if there are users.
			{
				found = true;
				emailtable[comb].etext.push_back(email1); //add text to it.
				break;
			}
		}
		if (!found)
		{
			email.etext.push_back(email1); //otherwise.
			emailtable.push_back(email);
		}
	}
	infile.close();
	return emailtable;
}

//clear emails;
bool clearemail(const string& ID, vector<useremails>& emailtable)
{
	int count = 0;
	for (int comb = 0; comb < emailtable.size(); comb++)
	{
		if (emailtable[comb].id == ID)
		{
			count = emailtable[comb].etext.size(); //amount of emails.
			emailtable.erase(emailtable.begin() + comb);
		}
	}
	cout << "Deleted: " << count << " Emails.";
	ofstream offile("Email.txt");
	for (int g = 0; g < emailtable.size(); g++)
	{
		for (int a = 0; a < emailtable[g].etext.size(); a++)
		{
			offile << emailtable[g].id << ' ' << emailtable[g].etext[a].senderid << ' ' << emailtable[g].etext[a].text;
			if (g < emailtable.size() - 1)
			{
				offile << '\n';
			}
		}
	}
	return true;
}
