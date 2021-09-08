#include <iostream>
#include <ctime>



void clearCin();

int getRandomNumber(double max, double min)
{
	static const double fraction = 1.0 / (static_cast <double> (RAND_MAX) + 1.0);
	return static_cast<double>(rand() * fraction * (max - min + 1) + min);
}

int main() 
{
	int min = 1;
	int max = 30;

	int difficulty = 3;

	int guess{};
	bool correctGuess{ false };

	int guessCounter{};
	char goAgain = 'n';
	int bestGuess{};
do 
{
	std::cout << "Options for difiiculty:\n"
		<< "1: Easy (range 1 to 5)\n"
		<< "2: Medium (range 1 to 10)\n"
		<< "3: Hard (range 1 to 30)\n";


	std::cout << "What difficulty level do you want ? : ";
	std::cin >> difficulty;

	switch (difficulty)
	{
	case 1:
		max = 5;
		break;
	case 2:
		max = 10;
		break;
	case 3:
		max = 30;
		break;
	default:
		std::cout << "Invalid input\n";
		break;
	}

	guessCounter = 0;
	correctGuess = false;
	int rightNumber = getRandomNumber(min, max);

	do
	{

		std::cout << "The correct number is : " << rightNumber << "\n"; //Allows you to see the correct number *for debugging purposes*
		std::cout << "Gues a number: ";
		std::cin >> guess;

		system("cls");
		clearCin();

		if (guess < rightNumber)
		{
			std::cout << "You entered a number that is too low\n";
			guessCounter = guessCounter + 1;
		}
		else if (guess > rightNumber)
		{
			std::cout << "You entered a number that is too high\n";
			guessCounter = guessCounter + 1;
		}
		else if (guess == rightNumber)
		{
			guessCounter = guessCounter + 1;
			std::cout << "CORRECT!!!!! (It took you " << guessCounter << " guesses to get it :)\n";
			if (bestGuess == 0) {
				bestGuess = guessCounter;
				std::cout << "The new highscore is now " << bestGuess << "\n";
			}
			else if (bestGuess > guessCounter) {
				std::cout << "You beat your previous highscore of " << bestGuess << "\n";
				bestGuess = guessCounter;
				std::cout << "The new highscore is now " << bestGuess << "\n";
			}
			else {
				std::cout << "The current highscore is " << bestGuess << "\n";
			}

			correctGuess = true;
		}



	} while (correctGuess == false);

	std::cout << "Go again?\ny/n : ";
	std::cin >> goAgain;

} while (goAgain == 'y');




} 



void clearCin()
{
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}