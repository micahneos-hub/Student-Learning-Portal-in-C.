#include "FunctionList.h"
int randNum(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

void showResults(int score, int total, double totalTime, vector<double>& questionTimes)
{
    cout << endl;
    cout << "-------- QUIZ RESULTS --------" << endl;
    cout << endl;

    double percentage = (score * 100.0) / total;

    cout << "Score: " << score << "/" << total << " (" << fixed
        << setprecision(1) << percentage << "%)" << endl;
    cout << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Time taken for each question:" << endl;

    for (int i = 0; i < questionTimes.size(); i++) {
        cout << "Question " << (i + 1) << ": " << fixed << setprecision(2)
            << questionTimes[i] << " seconds" << endl;
    }

    cout << "---------------------------------------------" << endl;
    cout << "Total time taken: " << totalTime << " seconds" << endl;
    cout << endl;

    // encouragement messages
    if (percentage >= 90) {
        cout << "Perfect score! You've mastered this topic!" << endl;
    }
    else if (percentage >= 70) {
        cout << "Excellent job! Keep up the good work!" << endl;
    }
    else if (percentage >= 50) {
        cout << "Good job! Keep practicing to improve your score!" << endl;
    }
    else {
        cout << "Don't give up! Review the formula and try again!" << endl;
    }

    cout << endl;
}

void saveScore(string ID, string name, int score, int total, double timeTaken, string topic, string difficulty)
{
    ofstream outfile("saveMscore.txt", ios::app);

    if (!outfile)
    {
        cout << endl << "Error: Could not save score!" << endl;
        return;
    }
    if (difficulty == "1")
    {
        difficulty = "Beginner";
    }
    else if (difficulty == "2")
    {
        difficulty = "Intermediate";
    }
    else if (difficulty == "3")
    {
        difficulty = "Advanced";
    }

    double percentage = (score * 100.0) / total;

    outfile << endl << ID << " " << name << " " << fixed << setprecision(2)
        << percentage << " " << timeTaken << " " << topic << " "
        << difficulty;

    outfile.close();
}
