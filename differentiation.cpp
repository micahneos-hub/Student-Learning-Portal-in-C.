#include "Functionlist.h"

// Changed var and function names based on micah's suggestions
//Question structure
struct Question
{
    string text;
    string answer;
    string type;
};


void diffQuiz(int level, string ID, string name)
{
    switch (level)
    {
    case 1:
        diffQuizBeginner(ID, name);
        break;
    case 2:
        diffQuizInter(ID, name);
        break;
    case 3:
        diffQuizAdv(ID, name);
        break;
    }
}

void showDiffFormulas(int difficulty)
{
    cout << endl;
    cout << "-------- DIFFERENTIATION FORMULAS & RULES --------" << endl;
    cout << endl;

    if (difficulty == 1)
    {
        // BEGINNER FORMULAS
        cout << "---------------------------------------------" << endl;
        cout << "1. POWER RULE:" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "If f(x) = x^n, then f'(x) = n*x^(n-1)" << endl;
        cout << endl;
        cout << "Example 1: f(x) = x^3" << endl;
        cout << "Solution:  f'(x) = 3*x^(3-1) = 3x^2" << endl;
        cout << endl;
        cout << "Example 2: f(x) = x^2" << endl;
        cout << "Solution:  f'(x) = 2*x^(2-1) = 2x" << endl;
        cout << endl;

        cout << "---------------------------------------------" << endl;
        cout << "2. CONSTANT MULTIPLE RULE:" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "If f(x) = c*x^n, then f'(x) = c*n*x^(n-1)" << endl;
        cout << endl;
        cout << "Example: f(x) = 5x^3" << endl;
        cout << "Solution: f'(x) = 5*3*x^2 = 15x^2" << endl;
        cout << endl;

        cout << "---------------------------------------------" << endl;
        cout << "3. TRIGONOMETRIC FUNCTIONS:" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "d/dx[sin(x)] = cos(x)" << endl;
        cout << "d/dx[cos(x)] = -sin(x)" << endl;
        cout << "d/dx[tan(x)] = sec^2(x)" << endl;
        cout << endl;

        cout << "--- With coefficient ---" << endl;
        cout << "d/dx[sin(ax)] = a*cos(ax)" << endl;
        cout << "d/dx[cos(ax)] = -a*sin(ax)" << endl;
        cout << "d/dx[tan(ax)] = a*sec^2(ax)" << endl;
        cout << endl;

        cout << "Example 1: f(x) = sin(3x)" << endl;
        cout << "Solution:  f'(x) = 3*cos(3x)" << endl;
        cout << endl;
        cout << "Example 2: f(x) = cos(2x)" << endl;
        cout << "Solution:  f'(x) = -2*sin(2x)" << endl;
        cout << endl;
    }
    else if (difficulty == 2)
    {
        // INTERMEDIATE FORMULAS
        cout << "---------------------------------------------" << endl;
        cout << "1. PRODUCT RULE:" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "d/dx [f(x)*g(x)] = f'(x)*g(x) + f(x)*g'(x)" << endl;
        cout << endl;
        cout << "Example: f(x) = x^2*sin(x)" << endl;
        cout << "Let f(x) = x^2, g(x) = sin(x)" << endl;
        cout << "f'(x) = 2x, g'(x) = cos(x)" << endl;
        cout << "Result: 2x*sin(x) + x^2*cos(x)" << endl;
        cout << endl;

        cout << "---------------------------------------------" << endl;
        cout << "2. QUOTIENT RULE:" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "d/dx [u/v] = [v(du/dx) - u(dv/dx)] / v^2" << endl;
        cout << endl;
        cout << "Example: f(x) = x^2/sin(x)" << endl;
        cout << "Let u = x^2, v = sin(x)" << endl;
        cout << "du/dx = 2x, dv/dx = cos(x)" << endl;
        cout << "Result: [sin(x)*2x - x^2*cos(x)] / sin^2(x)" << endl;
        cout << endl;

        cout << "---------------------------------------------" << endl;
        cout << "3. CHAIN RULE:" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "If f(x) = g(h(x))" << endl;
        cout << "Then f'(x) = g'(h(x))*h'(x)" << endl;
        cout << endl;
        cout << "Example: f(x) = (x^2 + 1)^3" << endl;
        cout << "Let u = x^2 + 1" << endl;
        cout << "f'(x) = 3(x^2 + 1)^2*(2x)" << endl;
        cout << "f'(x) = 6x(x^2 + 1)^2" << endl;
        cout << endl;
    }
    else if (difficulty == 3)
    {
        //ADVANCED FORMULAS
        cout << "---------------------------------------------" << endl;
        cout << "1. LOGARITHMIC DIFFERENTIATION:" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "d/dx[ln(x)] = 1/x" << endl;
        cout << "d/dx[ln(f(x))] = f'(x)/f(x)" << endl;
        cout << endl;
        cout << "Example 1: f(x) = ln(x)" << endl;
        cout << "f'(x) = 1/x" << endl;
        cout << endl;
        cout << "Example 2: f(x) = ln(x^2)" << endl;
        cout << "f'(x) = 2x/x^2 = 2/x" << endl;
        cout << endl;

        cout << "---------------------------------------------" << endl;
        cout << "2. EXPONENTIAL DIFFERENTIATION:" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "d/dx[e^x] = e^x" << endl;
        cout << "d/dx[e^(f(x))] = e^(f(x))*f'(x)" << endl;
        cout << endl;
        cout << "Example 1: f(x) = e^x" << endl;
        cout << "f'(x) = e^x" << endl;
        cout << endl;
        cout << "Example 2: f(x) = e^(x^2)" << endl;
        cout << "f'(x) = e^(x^2)*2x = 2x*e^(x^2)" << endl;
        cout << endl;
    }

    cout << endl;
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}


//BEGINNER QUESTIONS

Question genPowerQ(int maxPower)
{
    Question q;
    int power = randNum(2, maxPower);
    int coeff = randNum(1, 10);

    q.type = "power";
    q.text = "Differentiate: f(x) = ";

    if (coeff == 1)
    {
        q.text += "x^" + to_string(power);
        q.answer = to_string(power) + "x^" + to_string(power - 1);
    }
    else
    {
        q.text += to_string(coeff) + "x^" + to_string(power);
        int resultCoeff = coeff * power;
        q.answer = to_string(resultCoeff) + "x^" + to_string(power - 1);
    }

    return q;
}

Question genBasicTrigQ()
{
    Question q;
    q.type = "trig";

    int trigType = randNum(1, 3);  //1=sin,2=cos,3=tan
    int coeff = randNum(1, 5);

    string trigFunc, derivative;

    switch (trigType) {
    case 1:
        trigFunc = "sin";
        derivative = to_string(coeff) + "cos(" + to_string(coeff) + "x)";
        break;
    case 2:
        trigFunc = "cos";
        derivative = "-" + to_string(coeff) + "sin(" + to_string(coeff) + "x)";
        break;
    case 3:
        trigFunc = "tan";
        derivative = to_string(coeff) + "sec^2(" + to_string(coeff) + "x)";
        break;
    }

    q.text = "Differentiate: f(x) = " + trigFunc + "(" + to_string(coeff) + "x)";
    q.answer = derivative;

    return q;
}


void diffQuizBeginner(string ID, string name)
{
    srand(time(NULL));

    system("cls");

    cout << "-------- DIFFERENTIATION QUIZ - BEGINNER LEVEL --------" << endl;
    cout << endl;

    const int numQ = 5;
    vector<Question> questions;
    vector<double> quizTimes;
    int score = 0;

    // generate 5 questions
    for (int i = 0; i < 5; i++)
    {
        int Qask = randNum(1, 2);
        (Qask == 1) ? questions.push_back(genPowerQ(3)) : questions.push_back(genBasicTrigQ());
    }

    clock_t quizStart = clock();

    for (int i = 0; i < numQ; i++) {
        cout << "Question " << (i + 1) << "/" << numQ << endl;
        cout << questions[i].text << endl;
        cout << endl;

        clock_t questionStart = clock();

        string userAns;
        cout << "Your answer: ";
        cin >> userAns;

        clock_t questionEnd = clock();
        double questionTime = double(questionEnd - questionStart) / CLOCKS_PER_SEC;
        quizTimes.push_back(questionTime);

        // clean and compare ans
        string cleanAns = "";
        string cleanUser = "";

        for (char c : questions[i].answer)
        {
            if (c != ' ') cleanAns += tolower(c);
        }
        for (char c : userAns) {
            if (c != ' ') cleanUser += tolower(c);
        }

        if (cleanAns == cleanUser)
        {
            cout << "Correct!" << endl;
            score++;
        }
        else
        {
            cout << "Wrong! Correct answer: " << questions[i].answer << endl;
        }

        cout << "---------------------------------------------" << endl;
        cout << endl;
    }

    clock_t quizEnd = clock();
    double totalTime = double(quizEnd - quizStart) / CLOCKS_PER_SEC;
    cout << "Press Enter to vieww result";
    cin.ignore();
    cin.get();
    system("cls");

    showResults(score, numQ, totalTime, quizTimes);
    saveScore(ID, name, score, numQ, totalTime, "Differentiation", "Beginner");

    cout << "Your score has been saved!" << endl;
    cout << "Press Enter to continue...";

    cin.get();
    system("cls");
}

// INTERMEDIATE QUESTIONS
Question genProductQ()
{
    Question q;
    q.type = "product";

    // randomize both functions
    int firstType = randNum(1, 2);
    int secondType = randNum(1, 2);  // 1=power,2=trig

    string u, v, du, dv;

    // first function u(x)
    if (firstType == 1) {
        int power = randNum(2, 4);
        u = "x^" + to_string(power);
        du = to_string(power) + "x^" + to_string(power - 1);
    }
    else {
        int trigChoice = randNum(1, 2);
        if (trigChoice == 1) {
            u = "sin(x)";
            du = "cos(x)";
        }
        else {
            u = "cos(x)";
            du = "-sin(x)";
        }
    }

    // second function v(x)
    if (secondType == 1) {
        int power = randNum(2, 4);
        v = "x^" + to_string(power);
        dv = to_string(power) + "x^" + to_string(power - 1);
    }
    else
    {
        int trigChoice = randNum(1, 2);
        if (trigChoice == 1)
        {
            v = "sin(x)";
            dv = "cos(x)";
        }
        else {
            v = "cos(x)";
            dv = "-sin(x)";
        }
    }

    q.text = "Differentiate using PRODUCT RULE:\nf(x) = " + u + " * " + v;
    q.text += "\n(f'(x) = f'(x)*g(x) + f(x)*g'(x))";

    // Answer: u'v + uv'
    q.answer = du + "*" + v + "+" + u + "*" + dv;

    return q;
}

Question genQuotientQ()
{
    Question q;
    q.type = "quotient";

    int numerType = randNum(1, 2);
    int denomType = randNum(1, 2);   // 1=power, 2=trig

    string u, v, du, dv;

    // numerator u(x)
    if (numerType == 1) {
        int power = randNum(2, 4);
        u = "x^" + to_string(power);
        du = to_string(power) + "x^" + to_string(power - 1);
    }
    else
    {
        int trigChoice = randNum(1, 2);
        if (trigChoice == 1)
        {
            u = "sin(x)";
            du = "cos(x)";
        }
        else
        {
            u = "cos(x)";
            du = "-sin(x)";
        }
    }

    // denominator v(x)
    if (denomType == 1)
    {
        int power = randNum(2, 3);
        v = "x^" + to_string(power);
        dv = to_string(power) + "x^" + to_string(power - 1);
    }
    else
    {
        int trigChoice = randNum(1, 2);
        if (trigChoice == 1)
        {
            v = "sin(x)";
            dv = "cos(x)";
        }
        else {
            v = "cos(x)";
            dv = "-sin(x)";
        }
    }

    q.text = "Differentiate using QUOTIENT RULE:\nf(x) = (" + u + ") / (" + v + ")";
    q.text += "\n(f'(x) = [v(du/dx) - u(dv/dx)] / v^2)";

    // Answer: (u'v - uv') / v^2
    q.answer = "(" + du + "*" + v + "-" + u + "*" + dv + ")/" + v + "^2";

    return q;
}

Question 


genChainQ()
{
    Question q;
    q.type = "chain";

    int outerType = randNum(1, 2);
    int innerType = randNum(1, 2);  // 1=power,2=trig

    string inner, outer, innerDeriv, outerDeriv;

    // inner function h(x)
    if (innerType == 1) {
        int coeff = randNum(2, 5);
        int power = randNum(2, 3);
        inner = to_string(coeff) + "x^" + to_string(power);
        innerDeriv = to_string(coeff * power) + "x^" + to_string(power - 1);
    }
    else {
        int trigChoice = randNum(1, 2);
        int coeff = randNum(2, 4);
        if (trigChoice == 1) {
            inner = "sin(" + to_string(coeff) + "x)";
            innerDeriv = to_string(coeff) + "cos(" + to_string(coeff) + "x)";
        }
        else {
            inner = "cos(" + to_string(coeff) + "x)";
            innerDeriv = "-" + to_string(coeff) + "sin(" + to_string(coeff) + "x)";
        }
    }

    // outer function g(u)
    if (outerType == 1) {
        int power = randNum(2, 4);
        q.text = "Differentiate using CHAIN RULE:\nf(x) = (" + inner + ")^" + to_string(power);
        q.text += "\n(f'(x) = g'(h(x)) * ( h'(x))";

        outerDeriv = to_string(power) + "(" + inner + ")^" + to_string(power - 1);
        q.answer = outerDeriv + "*(" + innerDeriv + ")";
    }
    else {
        int trigChoice = randNum(1, 2);
        if (trigChoice == 1)
        {
            q.text = "Differentiate using CHAIN RULE:\nf(x) = sin(" + inner + ")";
            q.text += "\n(f'(x) = g'(h(x)) * (h'(x))";

            outerDeriv = "cos(" + inner + ")";
        }
        else
        {
            q.text = "Differentiate using CHAIN RULE:\nf(x) = cos(" + inner + ")";
            q.text += "\n(f'(x) = g'(h(x)) * (h'(x))";
            outerDeriv = "-sin(" + inner + ")";
        }

        q.answer = outerDeriv + "*(" + innerDeriv + ")";
    }

    return q;
}

void diffQuizInter(string ID, string name)
{
    srand(time(NULL));

    system("cls");

    cout << "-------- DIFFERENTIATION QUIZ - INTERMEDIATE LEVEL --------" << endl;
    cout << endl;

    const int numQ = 5;
    vector<Question> questions;
    vector<double> quizTimes;
    int score = 0;

    // mixed questions
    for (int i = 0; i < numQ; i++)
    {
        int qType = randNum(1, 4);
        switch (qType)
        {
        case 1:
            questions.push_back(genPowerQ(5));  // increased pow
            break;
        case 2:
            questions.push_back(genProductQ());
            break;
        case 3:
            questions.push_back(genQuotientQ());
            break;
        case 4:
            questions.push_back(genChainQ());
            break;
        }
    }

    clock_t quizStart = clock();

    for (int i = 0; i < numQ; i++) {
        cout << "Question " << (i + 1) << "/" << numQ << endl;
        cout << questions[i].text << endl;
        cout << "Type: " << questions[i].type << " rule" << endl;
        cout << endl;

        clock_t questionStart = clock();

        string userAns;
        cout << "Your answer: ";
        cin >> userAns;

        clock_t questionEnd = clock();
        double questionTime = double(questionEnd - questionStart) / CLOCKS_PER_SEC;
        quizTimes.push_back(questionTime);

        // Clean and compare
        string cleanAns = "";
        string cleanUser = "";

        for (char c : questions[i].answer)
        {
            if (c != ' ') cleanAns += tolower(c);
        }
        for (char c : userAns)
        {
            if (c != ' ') cleanUser += tolower(c);
        }

        if (cleanAns == cleanUser)
        {
            cout << "Correct!" << endl;
            score++;
        }
        else {
            cout << "Wrong! Correct answer: " << questions[i].answer << endl;
        }

        cout << "---------------------------------------------" << endl;
        cout << endl;
    }

    clock_t quizEnd = clock();
    double totalTime = double(quizEnd - quizStart) / CLOCKS_PER_SEC;
    cout << "Press Enter to view result";
    cin.ignore();
    cin.get();
    system("cls");

    showResults(score, numQ, totalTime, quizTimes);
    saveScore(ID, name, score, numQ, totalTime, "Differentiation", "Intermediate");

    cout << "Your score has been saved!" << endl;
    cout << "Press Enter to continue...";

    cin.get();
    system("cls");
}

// ADVANCED QUESTIONS
Question genLogQ()
{
    Question q;
    q.type = "logarithm";

    int qType = randNum(1, 3);

    if (qType == 1) {
        // simple: ln(ax)
        int coeff = randNum(2, 9);
        q.text = "Differentiate: f(x) = ln(" + to_string(coeff) + "x)";
        q.answer = "1/x";
    }
    else if (qType == 2) {
        // inter: ln(x^n)
        int power = randNum(2, 5);
        q.text = "Differentiate: f(x) = ln(x^" + to_string(power) + ")";
        q.answer = to_string(power) + "/x";
    }
    else {
        // advan: ln(ax^n)
        int coeff = randNum(2, 5);
        int power = randNum(2, 4);
        q.text = "Differentiate: f(x) = ln(" + to_string(coeff) + "x^" + to_string(power) + ")";
        q.answer = to_string(power) + "/x";
    }

    return q;
}

Question genExpQ()
{
    Question q;
    q.type = "exponential";

    int qType = randNum(1, 3);

    if (qType == 1) {
        // simple: e^(ax)
        int coeff = randNum(2, 5);
        q.text = "Differentiate: f(x) = e^(" + to_string(coeff) + "x)";
        q.answer = to_string(coeff) + "e^(" + to_string(coeff) + "x)";
    }
    else if (qType == 2) {
        // inter: e^(x^n)
        int power = randNum(2, 4);
        q.text = "Differentiate: f(x) = e^(x^" + to_string(power) + ")";
        q.answer = to_string(power) + "x^" + to_string(power - 1) + "e^(x^" + to_string(power) + ")";
    }
    else {
        // advan: e^(ax^n)
        int coeff = randNum(2, 4);
        int power = randNum(2, 3);
        q.text = "Differentiate: f(x) = e^(" + to_string(coeff) + "x^" + to_string(power) + ")";
        int derivCoeff = coeff * power;
        q.answer = to_string(derivCoeff) + "x^" + to_string(power - 1) + "e^(" + to_string(coeff) + "x^" + to_string(power) + ")";
    }

    return q;
}

void diffQuizAdv(string ID, string name)
{
    srand(time(NULL));


    system("cls");

    cout << "-------- DIFFERENTIATION QUIZ - ADVANCED LEVEL --------" << endl;
    cout << endl;

    const int numQ = 5;
    vector<Question> questions;
    vector<double> qTimes;
    int score = 0;

    for (int i = 0; i < numQ; i++)
    {
        int qType = randNum(1, 2);
        (qType == 1) ?
            questions.push_back(genLogQ()) :
            questions.push_back(genExpQ());

    }

    clock_t quizStart = clock();

    for (int i = 0; i < numQ; i++)
    {
        cout << "Question " << (i + 1) << "/" << numQ << endl;
        cout << questions[i].text << endl;
        cout << "Type: " << questions[i].type << endl;
        cout << endl;

        clock_t questionStart = clock();

        string userAns;
        cout << "Your answer: ";
        cin >> userAns;

        clock_t questionEnd = clock();
        double questionTime = double(questionEnd - questionStart) / CLOCKS_PER_SEC;
        qTimes.push_back(questionTime);

        string cleanAnswer = "";
        string cleanUserAnswer = "";

        for (char c : questions[i].answer)
        {
            if (c != ' ') cleanAnswer += tolower(c);
        }
        for (char c : userAns)
        {
            if (c != ' ') cleanUserAnswer += tolower(c);
        }

        if (cleanAnswer == cleanUserAnswer)
        {
            cout << "Correct!" << endl;
            score++;
        }
        else
        {
            cout << "Wrong! Correct answer: " << questions[i].answer << endl;
        }

        cout << "---------------------------------------------" << endl;
        cout << endl;
    }

    clock_t quizEnd = clock();
    double totalTime = double(quizEnd - quizStart) / CLOCKS_PER_SEC;
    cout << "Press Enter to view result";
    cin.ignore();
    cin.get();
    system("cls");

    showResults(score, numQ, totalTime, qTimes);
    saveScore(ID, name, score, numQ, totalTime, "Differentiation", "Advanced");

    cout << "Your score has been saved!" << endl;
    cout << "Press Enter to continue...";

    cin.get();
    system("cls");
}