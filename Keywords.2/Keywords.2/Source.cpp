#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cctype>
#include<cstdlib>


using namespace std;

int main()
{
	string playAgain = "";

	//select the keywords for the user to unscrable
	do {


		// Display Title of program to user
		cout << "Welcome to Code Breaker Training Simulation Program" << endl;
		cout << "===================================================" << endl;
		// Ask the recruit to login using thier name
		string login;
		cout << "Please log in using your name." << endl;
		cout << "Login: ";

		// Hold the recruit's name in a var, and address them by it throughout the simulation.
		vector <string> loggedUsers;
		cin >> login;
		loggedUsers.push_back(login);

		// Display an overview of what Keywords II is to the recruit 
		cout << "Welcome, " << login << "!" << endl;
		cout << "===================================================" << endl;
		cout << "In Code Breaker Training Simulation Program you will be tasked with guessing the correct words." << endl;
		cout << "The program has 10 words available to be selected from. The program will select 3 of these words for you to unscramble." << endl;
		cout << "When you guess the correct word, you will move on to the next word. If you guess wrong, you will be notified and your remain guess count will be updated." << endl;
		cout << "If you use all of your guesses, you will fail the word and will move on to the next word." << endl;
		cout << "The quicker you guess the right words, the better your score will be. Try to get the best score possible." << endl;
		cout << "===================================================" << endl;
		cout << " " << endl;
		system("pause");
		// Display an directions to the recruit on how to use Keywords
		cout << "===================================================" << endl;
		cout << "The word will not be displayed on the screen. You have to make guesses as to what letters are in the word." << endl;
		cout << "When you guess a letter correctly, it will appear on the screen in the position it belongs." << endl;
		cout << "When you guess wrong, the program will tell you and you will see your remaining guess decrement by one. When you have used all your guesses the word will be revealed to you and you will be given the next word." << endl;
		cout << "If you get it in 1 guess you will get a 100% for the word. Each wrong guess you use will dock you 10% for the word." << endl;
		cout << "Your final score will be the average of the scores. You're goal is to get the highest score possible." << endl;
		cout << "===================================================" << endl;
		cout << " " << endl;
		system("pause");
		// Create a collection of 10 words you had wrote down manually
		//holds all the possible keywords
		string theKeyWords[] = { "agent", "operative", "dossier", "sneaky", "snoop", "sleuth", "examine", "secret", "undercover", "mole" };
		//vector to hold the slected keywords
		vector <string> selectedKeywords;

		srand(time(0));


		// Create an int var to count the number of simulations being run starting at 1
		int simulationNumber = 1;

		// Display the simulation # is staring to the recruit.
		cout << "===================================================" << endl;
		cout << "Simulation #" << simulationNumber << endl;

		// Pick new 3 random words from your collection as the secret code word the recruit has to guess.
		for (int i = 0; i < 3; i++)
		{
			//generate a random number based off the size of the array
			int randomIndex = rand() % (sizeof(theKeyWords) / sizeof(*theKeyWords));

			//after it picks a word push it to the vector selectedKeywords
			selectedKeywords.push_back(theKeyWords[randomIndex]);

		}

		random_shuffle(selectedKeywords.begin(), selectedKeywords.end());
		const string theWord = selectedKeywords[0];
		const int maxGuesses = 10;
		int wrongGuesses = 0;
		string soFar(theWord.size(), '-');
		string used = "";

		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		while (wrongGuesses < maxGuesses && soFar != theWord) {
			//Tell recruit how many incorrect guesses they have left
			cout << "Guesses Remaining: " << (maxGuesses - wrongGuesses) << endl;
			//Show the recruit the letters they have guessed:
			cout << "You have guesses the following letters: \n" << used << endl;
			//Shoe the player how much of the word they have guessed
			cout << "So far, the word is: " << soFar << endl;

			//get the recruits next guess
			char guess;
			cout << " " << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = tolower(guess); //make the letters all lowercase since they are all stored in the array as lowercase
			//while the user guess a letter they've already guessed
			while (used.find(guess) != string::npos)
			{
				cout << " " << endl;
				cout << "You've already guessed " << guess << endl;
				cout << "Enter your guess: ";
				//get the recruits guess
				cin >> guess;
				guess = tolower(guess); //change guess to lowercase
			}

			used += guess; //add guess to used

			//if the guess is in the word
			if (theWord.find(guess) != string::npos)
			{
				//Tell the recurit the guess is right
				cout << "That's right! " << guess << " is in the word. \n";
				//get the new group of used letters and add them to used
				for (int i = 0; i < theWord.length(); i++)
				{
					//update the word so far with the guessed letter
					if (theWord[i] == guess)
					{
						soFar[i] = guess;
					}
				}
			}
			//otherwise,
			else {
				//tell the recruit the guess is incorrect
				cout << "Sorry, " << guess << " isn't in the word. \n";
				//increment the number of wrong guess made
				wrongGuesses++;
			}

		}
		//if the recruit has made too many incorect guesses
		if (wrongGuesses == maxGuesses)
		{
			//tell the recruit they have failed the course
			cout << "You've reached the number of allotted guesses and have failed the Keywords 2 course.";
		}
		//otherwise,
		else {
			//Congratulate the recruit on guessing the secret word
			cout << "\nYou've guessed the word!";
		}

		cout << "\nThe word was " << theWord << endl;
		system("pause");

		//Ask the recruit if they would like to play again
		cout << "\nWould you like to play again?" << endl;
		cout << "press 'y' to play again or 'n' to quit the program" << endl;
		cin >> playAgain;
		//if the recuit choose yes increment the simulation number
		if (playAgain == "y")
		{
			//increment the simulation number
			simulationNumber++;
		}
		else
		{
			cout << "End of Simulation" << endl;
		}
		//system pause
		system("pause");

	} while (playAgain == "y");


}