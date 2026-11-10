#include "FunctionList.h"

void simpsonQuiz(int level, string ID, string name)
{
    switch (level)
    {
    case 1:
        simpsonQuizLevel(2, ID, name);  // n=2
        break;
    case 2:
        simpsonQuizLevel(4, ID, name);  // n=4
        break;
    case 3:
        simpsonQuizLevel(6, ID, name);  // n=6
        break;
    }
}

struct SimpsonQ
{
    string text;
    double answer;
    double a, b;
    int n;
    int power;
};

void showSimpsonFormulas(int difficulty)
{
    int n = 2 * difficulty;     // n = amount of harmonics

    cout << endl;
    cout << "-------- SIMPSON'S RULE - FORMULAS --------" << endl;
    cout << endl;

    cout << "---------------------------------------------" << endl;
    cout << "WHAT IS SIMPSON'S RULE?" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Simpson's Rule approximates the definite integral" << endl;
    cout << "of a function using parabolic curves.\n\n";

    cout << "---------------------------------------------" << endl;
    cout << "GENERAL FORMULA (with n intervals):" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Integral[a to b] f(x)dx = (h/3)[f(x0) + 4f(x1) + 2f(x2)" << endl;
    cout << "                           + 4f(x3) + ... + f(xn)]\n\n";

    cout << "Where:" << endl;
    cout << "  h = (b - a) / n" << endl;
    cout << "  n = number of intervals (!MUST BE EVEN!)\n\n";

    cout << "Pattern of coefficients:" << endl;
    cout << "  * First and last points: coefficient 1" << endl;
    cout << "  * Odd index points: coefficient 4" << endl;
    cout << "  * Even index points (not first/last): coefficient 2" << endl;
    cout << endl;

    cout << "---------------------------------------------" << endl;
    cout << "YOUR LEVEL: " << n << " intervals" << endl;
    cout << "---------------------------------------------\n\n";
    cout << "EXAMPLE: Integral[0 to 2] x^2 dx with n=" << n << endl;
    cout << "---------------------------------------------" << endl;

    double a = 0, b = 2;
    double h = (b - a) / n;

    cout << "Step 1: Calculate h" << endl;
    cout << "  h = (2 - 0) / " << n << " = " << h << endl;

    cout << endl << "Step 2: Calculate x values and f(x):" << endl;
    for (int i = 0; i <= n; i++) {
        double x = a + i * h;
        double fx = x * x;
        int coeff;

        if (i == 0 || i == n) coeff = 1;
        else if (i % 2 == 1) coeff = 4;
        else coeff = 2;

        cout << "  x" << i << " = " << fixed << setprecision(2) << x
            << ", f(x" << i << ") = " << fx
            << ", coefficient = " << coeff << endl;
    }

    cout << endl << "Step 3: Apply formula:" << endl;
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        double x = a + i * h;
        double fx = x * x;

        if (i == 0 || i == n) sum += fx;
        else if (i % 2 == 1) sum += 4 * fx;
        else sum += 2 * fx;
    }

    double result = (h / 3.0) * sum;
    cout << "  Result = (" << h << "/3) * " << sum << " = " << result << endl;
    cout << endl;
    cout << "  Exact answer: 8/3 = 2.667" << endl;
    cout << "  Error: " << abs(result - 2.667) << endl;

    cout << endl << "Notice: More intervals = Better accuracy!" << endl;

    cout << endl << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

SimpsonQ genSimpsonQ(int n)
{
    SimpsonQ q;

    q.a = 0;
    q.b = randNum(2, 6);
    q.power = randNum(2, 3);
    q.n = n;

    q.text = "Use Simpson's Rule with n=" + to_string(n) + " to approximate:" + "\n";
    q.text += "Integral[" + to_string((int)q.a) + " to " + to_string((int)q.b) + "] x^" + to_string(q.power) + " dx";

    // Calculate answer using Simpson's Rule
    double h = (q.b - q.a) / n;
    double sum = 0;

    for (int i = 0; i <= n; i++) {
        double x = q.a + i * h;
        double fx = pow(x, q.power);

        if (i == 0 || i == n) {
            sum += fx;
        }
        else if (i % 2 == 1) {
            sum += 4 * fx;
        }
        else {
            sum += 2 * fx;
        }
    }

    q.answer = (h / 3.0) * sum;

    return q;
}


void simpsonQuizLevel(int n, string ID, string name)
{
    srand(time(NULL));
    system("cls");

    string diffText[] = { "", "Beginner", "Intermediate", "Advanced" };
    int diffLevel = n / 2;  // n=2->1, n=4->2, n=6->3

    cout << "-------- SIMPSON'S RULE QUIZ - " << diffText[diffLevel]
        << " (n=" << n << ") --------" << endl;
    cout << endl;

    const int numQ = 5;
    vector<SimpsonQ> questions;
    vector<double> quizTimes;
    int score = 0;

    // genrate questions
    for (int i = 0; i < numQ; i++) {
        questions.push_back(genSimpsonQ(n));
    }

    clock_t quizStart = clock();

    for (int i = 0; i < numQ; i++) {
        cout << "Question " << (i + 1) << "/" << numQ << endl;
        cout << questions[i].text << endl;
        cout << endl;

        clock_t questionStart = clock();

        double userAns;
        cout << "Your answer (round to 2 decimal places): ";
        cin >> userAns;

        clock_t questionEnd = clock();
        double questionTime = double(questionEnd - questionStart) / CLOCKS_PER_SEC;
        quizTimes.push_back(questionTime);

        // check with tolerance
        if (abs(userAns - questions[i].answer) < 0.1)   // cal absolute value
        {
            cout << "Correct!" << endl;
            score++;
        }
        else
        {
            cout << "Wrong! Correct answer: " << fixed << setprecision(2)
                << questions[i].answer << endl;
        }

        cout << "---------------------------------------------\n\n";
    }

    clock_t quizEnd = clock();
    double totalTime = double(quizEnd - quizStart) / CLOCKS_PER_SEC;
    cout << "Press Enter to view result";
    cin.ignore();
    cin.get();
    system("cls");

    showResults(score, numQ, totalTime, quizTimes);
    saveScore(ID, name, score, numQ, totalTime, "SimpsonsRule", diffText[diffLevel]);

    cout << "Your score has been saved!" << endl;
    cout << "Press Enter to continue...";
    cin.get();
    system("cls");
}