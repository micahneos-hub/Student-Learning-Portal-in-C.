#include "FunctionList.h"

int MathPortal(const string ID, const string name)
{
    int choice;
    do
    {
        cout << "-------- MATH LEARNING PORTAL --------" << endl;
        cout << "1. Learn Topics" << endl;
        cout << "2. Take Quiz" << endl;
        cout << "3. View My Progress" << endl;
        cout << "4. Exit Program" << endl;
        cout << "Your choice: ";
        while (!(cin >> choice))
        {
            cin.ignore();
            cin.clear();
        }
        switch (choice)
        {
        case 1:
            system("cls");
            learnTopics();
            break;
        case 2:
            system("cls");
            takeQuiz(ID, name);
            break;
        case 3:
            system("cls");
            viewProgress(ID, name);
            break;
        case 4:
            cout << endl << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}

void learnTopics()
{
    int topic = chooseTopic();

    if (topic == 4)
    {
        return;
    }

    system("cls");

    int level = chooseDifficulty();

    if (level == 4) {
        return;
    }
    // return to main menu
    system("cls");

    switch (topic) {
    case 1:
        showDiffFormulas(level);
        break;
    case 2:
        showSimpsonFormulas(level);

        break;
    case 3:
        // Integration
        cout << "Oops...no formulas for this topic\nYou can take the quizzes to practice!" << endl;
        cout << "Press Enter to return to return to the menu...";
        cin.ignore();
        cin.get();
        break;
    default:
        cout << "Invalid choice!" << endl;
    }

    system("cls");
}

int chooseTopic()
{
    int option;
    cout << endl;
    cout << "-------- CHOOSE A TOPIC --------" << endl;
    cout << "1. Differentiation" << endl;
    cout << "2. Simpson's Rule" << endl;
    cout << "3. Integration and Simultaneous Equations" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "Your choice: ";
    cin >> option;
    return option;
}

int chooseDifficulty()
{
    int option;
    cout << endl;
    cout << "-------- CHOOSE DIFFICULTY --------" << endl;
    cout << "1. Beginner" << endl;
    cout << "2. Intermediate" << endl;
    cout << "3. Advanced" << endl;
    cout << "4. Back" << endl;
    cout << "Your choice: ";
    cin >> option;
    return option;
}

void takeQuiz(string ID, string name)
{
    int topic = chooseTopic();

    if (topic == 4)
    {
        return;
    }

    int InSi = -1;
    system("cls");
    if (topic == 3)
    {
        cout << "-------- CHOOSE YOUR QUIZ TOPIC --------" << endl;
        cout << "1.Integration" << endl;
        cout << "2. Simultneous Equation" << endl;
        cout << "3. Back" << endl;
        cout << "Your choice: ";
        cin >> InSi;
        if (InSi == 3) return;
        system("cls");
    }

    int level = chooseDifficulty();

    if (level == 4)
    {
        return;
    }

    system("cls");

    switch (topic)
    {
    case 1:
        diffQuiz(level, ID, name);
        break;
    case 2:
        simpsonQuiz(level, ID, name);
        break;
    case 3:
        (InSi == 1) ? Integration(level, ID, name) : Simultaneous(level, ID, name);
        break;
    default:
        cout << "Invalid choice!" << endl;
    }
}

void viewProgress(string ID, string name)
{
    cout << endl;
    cout << "-------- YOUR MATHEMATICS PROGRESS --------" << endl;
    cout << endl;

    ifstream infile("saveMscore.txt");

    if (!infile)
    {
        cout << "No quiz records found yet." << endl;
        cout << "Take some quizzes to see your progress!" << endl;
        cout << endl << "Press Enter to continue...";
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }

    //Store user's scores
    vector<string> topics;
    vector<string> difficulties;
    vector<double> percentages;
    vector<double> times;

    string fileID, fileName, topic, difficulty;
    double percentage, timeTaken;

    cout << left << setw(15) << "Topic" << setw(15) << "Difficulty"
        << setw(12) << "Score %" << "Time (s)" << endl;
    cout << "---------------------------------------------" << endl;

    bool found = false;

    while (infile >> fileID >> fileName >> percentage >> timeTaken >> topic >> difficulty)
    {
        if (fileID == ID)
        {
            found = true;
            cout << left << setw(15) << topic << setw(15) << difficulty << setw(15) << fixed << setprecision(1) << percentage << setprecision(2) << timeTaken << endl;

            topics.push_back(topic);
            difficulties.push_back(difficulty);
            percentages.push_back(percentage);
            times.push_back(timeTaken);
        }
    }

    infile.close();

    if (!found)
    {
        cout << "No quiz records found for ID: " << ID << endl;
    }
    else
    {
        // cal overall statistics
        cout << "---------------------------------------------" << endl;
        cout << endl;

        double totalScore = 0;
        for (double p : percentages)
        {
            totalScore += p;
        }
        double avgScore = totalScore / percentages.size();

        cout << "Total quizzes taken: " << percentages.size() << endl;
        cout << "Average score: " << fixed << setprecision(1) << avgScore << "%" << endl;
        cout << endl;

        if (avgScore >= 90) {
            cout << "Excellent work! You're mastering these topics!" << endl;
        }
        else if (avgScore >= 70) {
            cout << "Good job! Keep practicing to improve further." << endl;
        }
        else if (avgScore >= 50) {
            cout << "You're getting there! Review the formulas and try again." << endl;
        }
        else {
            cout << "Keep trying! Review the learning materials." << endl;
        }
    }

    cout << endl << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    system("cls");
}