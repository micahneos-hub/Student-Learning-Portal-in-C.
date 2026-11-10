#include "FunctionList.h"

double scienceportal()
{
	// Declaring all the variables present
	ifstream PQuestions;
	string keywords, studentans = "", studentansword, pors;
	static string qn[100], pelq[100], pelk1[100], pelk2[100], selq[100], selk[100];
	int i = 0, noqn, points = 0, follow = 1, option = 0, totqn = 0;
	double totpoints = 0;
	srand(time(NULL)); //to randomize the questions that are asked and the answers that are deemed correct from the text file
	int qnout;
	double percentage, percentscore = 0;

	// Getting information from the Primary School questions text files
	PQuestions.open("PQuestions.txt");
	if (!PQuestions)
	{
		cout << "File doesn't exist.";
	}
	while (getline(PQuestions, pelq[i]))//store question into an array
	{
		i++;
	}

	PQuestions.close();

	// Getting information from the Primary school keywords text files
	ifstream PKeywords1;
	PKeywords1.open("PKeywords1.txt");
	if (!PKeywords1)
	{
		cout << "File doesn't exist.";
	}
	i = 0;
	while (getline(PKeywords1, pelk1[i]))//get question answers into an  array
	{
		i++;
	}
	PKeywords1.close();

	// Getting information from the Primary school keywords text files
	ifstream PKeywords2;
	PKeywords2.open("PKeywords2.txt");
	if (!PKeywords2)
	{
		cout << "File doesn't exist.";
	}
	i = 0;
	while (getline(PKeywords2, pelk2[i]))//get question answers into an  array
	{
		i++;
	}
	PKeywords2.close();

	// Getting information from the Secondary School questions text files
	ifstream SQuestions;
	SQuestions.open("SQuestions.txt");
	if (!SQuestions)
	{
		cout << "File doesn't exist.";
	}
	i = 0;
	while (getline(SQuestions, selq[i]))//get question answers into an  array
	{
		i++;
	}
	SQuestions.close();

	// Getting information from the Secondary School keywords text files
	ifstream SKeywords;
	SKeywords.open("SKeywords.txt");
	if (!SKeywords)
	{
		cout << "File doesn't exist.";
	}
	i = 0;
	while (getline(SKeywords, selk[i]))//get question answers into an  array
	{
		i++;
	}
	SKeywords.close();

	//Asking the students the questions and how many qns they wanna do

	cout << "Welcome to the Science Library, would you like to practice Primary School Syllabus or Secondary School Syllabus?" << endl;
	cout << "1. Primary School Syllabus (12<= years old)" << endl;
	cout << "2. Secondary Schoo; Syllabus (16<= years old)" << endl;
	cin >> pors;
	while (follow == 1)
	{
		if (pors == "1")
		{
			system("cls");
			while (follow == 1)
			{
				cout << "All asnwers are to be answered in lower case.\n";
				cout << "How many questions would you like too do today?";
				cin >> noqn;
				cin.ignore(); //clears the buffer from cin (idek what ts means im so fried)
				for (int a = 0; a < noqn; a++)
				{
					qnout = rand() % 56; // roulette!!
					cout << pelq[qnout] << endl; //extract the question from the array that you placed the question into prior
					getline(cin, studentans);

					if (studentans.length() >= pelk1[qnout].length() && studentans.find(pelk1[qnout]) != string::npos) //!= string::npos helps to 
					{
						std::cout << "\033[32;1;4m\nGreat job!\033[0m\n";
						points++;
						totpoints++;
					}
					else if (studentans.length() >= pelk2[qnout].length() && studentans.find(pelk2[qnout]) != string::npos) //!= string::npos helps to 
					{
						std::cout << "\033[32;1;4m\nGreat job!\033[0m\n";
						points++;
						totpoints++;
					}
					else
					{
						std::cout << "\033[31;1;4m\nBetter luck next time!\033[0m\n";	//loser lmao.
						totpoints++;
					}
				}
				percentage = points / totpoints * 100;
				totqn += noqn;

				cout << fixed << setprecision(2) << "You have completed " << totqn << " questions for today. Your total score is " << percentage << "%" << endl;
				percentscore += percentage;
				cout << "Would you like to attempt more questions?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. I tired la bro\n" << endl;
				cin >> option;
				if (option == 2)
					break;
				if (option == 1)
				{
					cin.ignore();
					system("cls");
				}
			}
		}
		if (option == 2) break;
		else if (pors == "2")
		{
			system("cls");
			while (follow == 1)
			{
				cout << "Answers that require a divide, use / . E.g:(distance / time) is correct, (distance over time) or (distance/time) is incorrect." << endl;
				cout << "Ansers that require a multiply, use * . E.g:(distance * time) is correct, (distance x time) or (distance*time) is incorrect." << endl;
				cout << "\nHow many questions would you like too do today?";
				cin >> noqn;
				cin.ignore(); //clears the buffer from cin (idek what ts means im so fried)
				for (int a = 0; a < noqn; a++)
				{
					qnout = rand() % 70; // roulette!!
					cout << selq[qnout] << endl; //extract the question from the array that you placed the question into prior
					getline(cin, studentans);

					if (studentans.length() >= selk[qnout].length() && studentans.find(selk[qnout]) != string::npos) //!= string::npos helps to 
					{
						std::cout << "\033[32;1;4m\nGreat job!\033[0m\n";
						points++;
						totpoints++;
					}
					else
					{
						std::cout << "\033[31;1;4m\nBetter luck next time!\033[0m\n";
						totpoints++;
					}
				}
				percentage = points / totpoints * 100;
				totqn += noqn;

				cout << fixed << setprecision(2) << "You have completed " << totqn << " questions for today. Your total score is " << percentage << "%" << endl;
				percentscore += percentage;
				cout << "Would you like to attempt more questions?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. I tired la bro\n" << endl;
				cin >> option;
				if (option == 2)
					break;
				if (option == 1)
				{
					cin.ignore();
					system("cls");
				}
			}
		}
		if (option == 2) break;
		else
		{
			cout << "That is not an option! Please pick again" << endl;
			cin >> pors;
		}
	}
	system("cls");
	cout << "Stand proud, you are strong.";
	cout << R"(        .                                                                             .          .
                   .   :     ..            .                             .                       
   .             .   .::   .... ..:. .:.  ::                                  .:::    .:::.      
                .:. ...: .  :. ... ..:.. -.....          .        .      . .-.            .:-    
            :.  .::..        ..   :   ..    .:.                 .        .:.              .  .+: 
            .:...:.:  .  ..  ..... ...   .:...  ..:           . .       :.                     --
        :.  .:..: .      .      .:.    .:.      ..   .                .:              .        ..
  ..    ::...-     ...  :....              .:.    ..:.        .  . . .=       .  .    .          
     .:.:-....: :.....   . ..  .    ..    ........::.        .   .   =.                          
    . .. .  :.  ..: .:      . ..   . ...  .:    .   .:.:            :                            
 .  .:..... .:.. ...  ..     .:...   ...     .  .....:..           ..        :-.:--:=.: ::-=-    
    ..:   .. ..   ..  :. . .  ::.   .:.  ...:.     ..              ..       *##-.=-#*+%#=*.+-    
     .::. .        .. .       . .      .. .:    ... ..:: .         .       .#+. -+-.+= ==*:      
    :...:.. .... ..:..::....:.:..   .        . ...:..:     .       .      .==-:--:.:=- -:--==.   
     ..::..:::.:. ::::::.... ..:::.:..:.  .....   .....:.          ..    .+#+=#*-==.:++-=+--=    
       :--:...      .      .  .      . ..:...:.:..-..-*:          ...    :=  -:.--%#:.%*:*=. +:  
        -..                            ..:::-=-==+*#%*--..          :.                .          
     .  ..        :.    -.              .:--+#%@@@@@@%=.         .   :                           
        ..  .     -.-- :-.       .      . .-+%@*:+%@@@*.              : .                 .     :
        :.        =+..:+:                 .:=@%: .:%@#=.              ..              .        =:
  .     :.::::.    :..:      ...::-:.       .%=.=:-%@=.                ..                     =: 
        ::   .::         .-::..           .  *.:-:.=-:::...              -                  -:   
 .       .:     .-.  .  .:.    ...          .. .-...  .       ...::.   .  .::.          . .:.    
   . .    ...:===-:.   -.    . .:-==.    .    .= .=:::::.. .          .:      .::::*++==-. .     
               :-=-.        .**-=-::.         ...#+::::::::::..:      .:    .     -.       .     
     .      .:. ...         ..       . .: -..  :::-   .  ..::::.      ...  .                     
       .  .  -::::-.        .::*-:.:.::::*#+. .:  -..       :::       : :      .           .     
         .   .=-  .=*-+#*+==:.        ....===+:   -.    .   ::       .  :           .            
              ::    .                   . .:-   .+#+:      .=.   . ..   ..       .    .  .       
               . .                        ::: :.   +--.    -.     .      :                       
    . .        .:   --. :.              .-::.     ..=::-...    ..        =     .                 
                 ..                   .:-::: .:.    ::.     ..        :. .:.                     
                  ...-=:.. ....-   .:--::::. :-:..        ::       .-:.    ...              .    
                   .: .::::.    :::--.  .:-... .      ....       .::.      ..                    
                   --+:   .:=*-.-:::  .::.    .     ..       ...::.        ..         .          
  .           .. .:::--: ::  :=:::.:: .         ..    .  ..::.:.           :. .                  
             .  .: .-::-==------:.         ...       ...::..             ..-.                    
         .     ::  :=  :--**-.         ...  ..   .::::.   .     ..:::::::: .:    .  .            
          .  ..:...-===+-..     ...:.         .::-:     ...::::....:::..     :                   
  .        .:.     ::.   .  ....     .    .....    ..:::::::::....          .:                   
         . .:      :  ..       .      .:::     .:: .:-:.          .   .     :                    
      .    +#-     .... ::=:::     .:::.    .::.  .     .                 -%@#.                  
.        =@@@@%#=.::::. --=---  .:..     ...:..                        :+@@@@@@-                 
       -@@@@@@@@@@@- :-.::.   .   .:--.                   ..:-+##%@@@@@@@@@@@@@@#..              
     -@@@@@@@@@@@@@@@#+- .::--::.:..    .:=*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%:              
   -%@@@@@@@@@@@@@@@@@@@#:-:===   . -*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+==++*@@@@*             
.+@@@@@@@@@@@@@@@@@@@@@@@@@-   .=%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%+======*@@@%-           
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%+=======+@@@@#:         
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%==**==*@@@@@@@+        
@@@@@@@@@@@%%##+====+++**##%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*=+#%##%@@@@@@:      
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%@@@@@@@@@@@@@@@@%**@@@@@@@@@@@@@@@@@@@*=++=*%@@@@#*#@@=     
@@@@@@@@@##%#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%-==:-%@@@@@%@@@@@@@@@@##%@@@@@@#===#@@%%=    
@@@@@@@@@@@@@#*+++*#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=:-.++@@@@%*@@@@@@@@@@%@@@@@@@*==#@@@@@@@@-    )";
	for (int blank = 0; blank < 8; blank++)
		cout << "\n" << endl;

	return percentscore;
}
