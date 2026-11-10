#pragma once //IF LIBRARY IS CALLED TWICE, IGNORE THE SECOND ONE.
#include <vector>  //Initialized library.
#include <iomanip>
#include <sstream>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

//Saving infrastructure: Upload the whole Userbase into a "structure" variable: collates diff types of data into one, like a string array type shi, but for this instance.
struct userdataformat
{
	//ff means "From File".
	string IDff = "if this is shown, an error has occured"; //Initializing so that the compiler will shut up
	string passff = "if this is shown, an error has occured"; //it's also for error catching if a field isn't met.
	string displayname = "if this is shown, an error has occured";
	int Class = -1;
	//PLease deal with mainmenu, in save functions, 
};

/* EXPLANATION ON STRUCT: BELOW */

struct userpointformat
{
	vector<double> mrks; //marks from previous attempts.
};

struct userpointformatmath
{
	double mrks = -1;
	double time = -1;
	string topic = "No Topic";
	string difficulty = "No Diff";
};

struct userpointformatmathvec
{
	string id;
	vector<userpointformatmath> sumofvect;
	double maverage;
};

struct useremail
{
	string senderid;
	string text;
};

struct useremails
{
	string id;
	vector<useremail> etext;
};

// A vector is used together with a structure to organize data.
// A vector is like a 1D array, but if it stores a struct (e.g. struct CurrentUser),
// it can store multiple users, each following the same structure.
//
// Example: vector<CurrentUser> users;
// This creates a vector called "users" that you can store information into.
//
// Data can be read from a text file using getline(filename, variable),
// then spliced into strings/int/double/whatever lol and stored inside the vector<struct>.
//
// New elements are added to the vector using push_back(variable),
// which adds data to the end of the vector (not index 0 every time). Yay!!! We can now read and store data in our programme rather than in txt.
// 
// Example layout of vector<struct>:
// users[0] = User { ID, password }
// users[1] = User { ID, password }
// users[2] = User { ID, password }
/*			Saving Functions :				*/
//____________________________________________//
vector<userdataformat> ReadUsersffmain(const string& Userbase); //input: Textfile | Output: Vector<Structure> containing textfile data.
void givebacktfmain(const string& Userbase, const vector<userdataformat>& UserRn); //input: Vector<Structure> containing textfile data | Output: Back into text file. [Save]
void newUser(vector<userdataformat>& UserRn, const userdataformat& newUser); //input: Vector<Structure> containing textfile data, and Structure Data of new User | Output: New row/User in Vector.
bool updatethisusermain(vector<userdataformat>& UserRn, const string& ID, const userdataformat& Upd_info_user); //input: Vector<Structure> containing textfile data, ID, and Structure Data of updated User | Output: Updated User in Vector, of all datatypes.
bool removethisusermain(vector<userdataformat>& UserRn, vector<userpointformat>& marktablemath, vector<userpointformat>& marktablescience, const string& ID); //input: Vector<Structure> containing textfile data, ID | Output: Removes row/User from vector file.
int ObtainInfomain(const vector<userdataformat>& Table, const string& ID); //extracts index information in the vector.
userdataformat NewUserUi(vector<userdataformat>& Table, int type);//Like newUser, but has Ui. 0 for No account, 1 for TeacherAdminPanel
void displayline(int length, int text, int width);//creates a line of char, with length, and setw(width).
void alldata(vector<userdataformat>& Table);//Extracts all data from the file, and presents it neatly.
void CherAdminPanel(const string& ID);//summons the admin panel.

//saving functions in marks:

vector<userpointformat> readffmark(const string filename); //reads from file.
void writetfmark(const string filename, const vector<userpointformat>& marktable); //writes to the file.
bool addmark(vector<userpointformat>& marktable, const int index, const double mark); //requires the ID from table to edit the parallel array.
void addidtomark(const string filename); //since it's parallel, and all user information is appended at the end of the textfile.
userpointformatmathvec readffmathmarkmini(const string ID); //cuz sophia is doing extra D:
vector<userpointformatmathvec> readffmathmark(); //double vector. God do so help me.

//write emails:
bool writeemail(const string& text, const string& ID, const string& IDsender, const vector<userdataformat>& table); //write emails.
vector<useremails> reademails();
bool clearemail(const string& ID, vector<useremails>& emailtable);
//____________________________________________//

//MAIN MENU PROCESSES:
string IDinputprocess(const vector<userdataformat>& Table, int type); //Just like... seperated the functions cuz it looks nicer.
string checkifsignedin();
void signinff(const string IDnew);
string didyoumean(const string ID); //outputs noidfound, fail, for when it can't find the ID, or when the ID length is bad, returns the name of the closest user too
bool cherorstud(char role);
bool isindatabase(string ID, string password);
void StudentPortal(const vector<userdataformat> table);
void centretext(string text, int length);
userdataformat mainmenu(vector<userdataformat>& table);
int validclass(const int classnum, const string IDhere, const vector<userdataformat>& Table); //Returns your original classnum if it succeeds, fails, returns -1, and if it finds a suitable class, returns that class id
void classdisplay(const vector<userdataformat> Table); //don't ask me why i did this.
void displaymarkdata(bool math, const string& ID, const int& index, const vector<userpointformat>& sciencedatatable);
void inbox(bool teacher, const vector<userdataformat>& table, const string& ID);
// Main menu functions
int MathPortal(const string ID, const string name);
void learnTopics();
void takeQuiz(string ID, string name);
void viewProgress(string ID, string name);
int chooseTopic();
int chooseDifficulty();

// Differentiation functions
void diffQuiz(int level, string ID, string name);
void showDiffFormulas(int difficulty);
//i made all the display, save and random static since i use them in both diff and simpson

// Differentiation quiz functions by difficulty
void diffQuizBeginner(string ID, string name);
void diffQuizInter(string ID, string name);
void diffQuizAdv(string ID, string name);

// Simpson's Rule functions
void showSimpsonFormulas(int difficulty);
void simpsonQuiz(int level, string ID, string name);
void simpsonQuizLevel(int n, string ID, string name);

// Repeated functions, diff and simpson
int randNum(int min, int max);
void showResults(int score, int total, double totalTime, vector<double>& questionTimes);
void saveScore(string ID, string name, int score, int total, double timeTaken, string topic, string difficulty);

// Is it a must to initialize a member variable?#pragma once - sop

//yann's
double Simultaneous(int diff, string ID, string name);
double Integration(int diff, string ID, string name);
void Qresult(string ID, string name, string topic, string difficulty, int score, int total, double totalTime);
//sciencebaby!
double scienceportal();
