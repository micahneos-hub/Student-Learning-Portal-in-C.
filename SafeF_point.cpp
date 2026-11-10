#include "FunctionList.h"



//read
vector<userpointformat> readffmark(const string filename) //reads from file.
{
	vector<userpointformat> table;
	ifstream infile(filename);
	if (!infile)
	{
		cout << "file doesn't exist";
	}
	else
	{
		double mark;
		string line;
		while (getline(infile, line))
		{
			istringstream parse(line);
			userpointformat userpoint;
			userpoint.mrks.clear();
			while (parse >> mark)
			{
				userpoint.mrks.push_back(mark);
			}
			if (!userpoint.mrks.empty())
			{
				table.push_back(userpoint);
			}
		}
	}
	infile.close();
	return table;
}

//read from SOPHIA'S GOSH DARN OWN CUSTOM LITTLE GOOGLY GOOGLY GOO.
userpointformatmathvec readffmathmarkmini(const string ID)
{
	userpointformatmathvec mathscores;
	userpointformatmath mathscore;
	vector<userpointformat> table;
	ifstream infile("saveMscore.txt");
	if (!infile)
	{
		cout << "file doesn't exist";
	}
	else
	{
		string id, name, topic, difficulty;
		double score, time;
		int instance = 0;
		double sum = 0;
		double mark;
		while (infile >> id >> name >> score >> time >> topic >> difficulty)
		{
			sum += score;
			if (ID == id)
			{
				mathscore.mrks = score;
				mathscore.time = time;
				mathscore.topic = topic;
				mathscore.difficulty = difficulty;
				mathscores.sumofvect.push_back(mathscore);
			}
			instance++;
		}
		if (!mathscores.sumofvect.empty())
		{
			mathscores.maverage = sum / instance;
		}
	}
	infile.close();
	return mathscores;
}

vector<userpointformatmathvec> readffmathmark() //double vector. God do so help me.
{
	vector<userpointformatmathvec> usermathtable;
	userpointformatmath mathscore;
	ifstream infile("SaveMscore.txt");
	bool found;
	string id, name;
	while (infile >> id >> name >> mathscore.mrks >> mathscore.time >> mathscore.topic >> mathscore.difficulty)
	{
		found = false;
		for (int find = 0; find < usermathtable.size(); find++)
		{
			if (id == usermathtable[find].id) //if user is found, add data.
			{
				found = true;
				usermathtable[find].sumofvect.push_back(mathscore);
				break;
			}
		}
		if (!found) //create new user if not found;
		{
			userpointformatmathvec newuser;
			newuser.id = id;
			newuser.sumofvect.push_back(mathscore); //add data to sumofvect.
			usermathtable.push_back(newuser); //add data to usermathtable.
		}
	}
	double sum;
	for (int comb = 0; comb < usermathtable.size(); comb++)
	{
		sum = 0;
		size_t size = usermathtable[comb].sumofvect.size(); //dataloss if this is not size_t;
		for (int through = 0; through < size; through++)
		{
			sum += usermathtable[comb].sumofvect[through].mrks;
		}
		usermathtable[comb].maverage = sum / size;
	}
	infile.close();
	return usermathtable;
}

//write
void writetfmark(const string filename, const vector<userpointformat>& marktable) //writes to the file.
{
	ofstream outfile(filename);
	if (!outfile)
	{
		cout << "file doesn't exist";  return;
	}
	cout << fixed << setprecision(4);
	for (int i = 0; i < marktable.size(); i++)
	{
		for (int a = 0; a < marktable[i].mrks.size(); a++)
		{
			outfile << marktable[i].mrks[a] << ' ';
		}
		if (i < marktable.size() - 1)
		{
			outfile << endl;
		}
	}
	outfile.close();
}

//edit
bool addmark(vector<userpointformat>& marktable, const int index, const double mark) //requires the ID from table to edit the parallel array.
{
	if (index < marktable.size() && index > 0)
	{
		if (marktable[index].mrks[0] != -1)
		{
			marktable[index].mrks.insert(marktable[index].mrks.begin(), mark); //inserts the mark at the first indx.
		}
		else
		{
			marktable[index].mrks[0] = mark;
		}
		return true;
	}
	cout << "\nindex invalid for addmark\n";
	return false;
}

//addpeople.
void addidtomark(const string filename) //since it's parallel, and all user information is appended at the end of the textfile.
{
	ofstream out(filename,ofstream::app);
	if (!out)
	{
		cout << "file doesn't exist";  return; //oopsies, looks like a terrible thing to add here cuz I wouldn't know if bugs could happen here.
	}
	out << '\n' << -1;
	out.close();
} //simpler version.
