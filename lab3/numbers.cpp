/*
 * numbers.cpp
 *
 * Math Challenge (Lab #3 - Let's Do Some Math...)
 *
 * Prompts the user for three numbers, calculates
 * the sum and the average and determines the
 * largest and smallest numbers. The user is then
 * quizzed on the answers to the sum, average,
 * largest, and smallest. The score (number of
 * questions correctly answer) is then displayed
 * along with a message depending on the score.
 *
 * Brooke Cantwell
 *
 * 1 October 2015
 */

#include <iostream>
#include <iomanip>

using namespace std;

main () {

	// Declare local variables
	
	int num1, num2, num3;
	int sum, largest, smallest;
	int sumAnswer, largestAnswer, smallestAnswer;
	int score = 0;
	float average, averageAnswer;
	string gameAnswer, firstName;
	string sumAnswerCheck, averageAnswerCheck, largestAnswerCheck, smallestAnswerCheck;

	// Begin user interaction, ask the user of they want to play
	
	cout << "Welcome to Math Challenge CISC1600!\nMy name is Brooke and I challenge you to test your math skills.\nDo you accept my challenge (yes/no)?\n";
	cin >> gameAnswer;

	// If the user says no display a message and quit, if not continue
	
	if (gameAnswer == "no" || gameAnswer == "No" || gameAnswer == " NO")
		cout << "Are you afraid of being beaten by a computer program? That's not very brave...maybe next time.\n";
	else {
		cout << "What is your first name?\n";	
		cin >> firstName;

		cout << "Thank you " << firstName << ", you are very brave. Here we go!\n";

		cout << "Please enter three numbers (between 1 and 100) seperated by spaces.\n";
		cin >> num1 >> num2 >> num3;

		// If the numbers aren't within the appropriate range alert the user and quit the program

		if (num1 > 100 || num1 < 0 || num2 > 100 || num2 < 0 || num3 > 100 || num3 < 0)
			cout << "You must choose numbers between 1 and 100.\n";
		
		// If the numbers are in the acceptable range continue the program

		else {

			// Game starts here
			
			cout << "Thank you " << firstName << ", you entered: " << num1 << ", " << num2 << ", " << num3 << "\n";

			// Find the average and sum of the numbers

			sum = num1 + num2 + num3;
			average = (float) sum / 3;

			// Calculate the largest number
			
			if (num1 > num2 && num1 > num3)
				largest = num1;
			else
			if (num2 > num1 && num2 > num3)
				largest = num2;
			else
			if (num3 > num2 && num3 > num1)
				largest = num3;

			// Calculate the smallest number

			if (num1 < num2 && num1 < num3)
				smallest = num1;
			else
			if (num2 < num1 && num2 < num3)
				smallest = num2;
			else
			if (num3 < num1 && num3 < num1)
				smallest = num3;

			// Prompt the user to answer questions and check their answers, increase the score for correct answers
			
			cout << "Guess the sum? ";
			cin >> sumAnswer;
			if (sumAnswer == sum) {
				score++;
				sumAnswerCheck = "right";
			}
			else
				sumAnswerCheck = "wrong";

			cout << "Guess the average? ";
			cin >> averageAnswer;
			if (average - averageAnswer < 0.001 || averageAnswer - average < 0.001) {
				score++;
				averageAnswerCheck = "right";
			}
			else
				averageAnswerCheck = "wrong";

			cout << "Guess the largest? ";
			cin >> largestAnswer;
			if (largestAnswer == largest) {
				score++;
				largestAnswerCheck = "right";
			}
			else
				largestAnswerCheck = "wrong";
			
			cout << "Guess the smallest? ";
			cin >> smallestAnswer;
			if (smallestAnswer == smallest) {
				score++;
				smallestAnswerCheck = "right";
			}
			else
				smallestAnswerCheck = "wrong";

			// Display the score, and answers and user answer so they can check their work

			cout << "Your score is: " << score << "\n\n";
			cout << "Check your answers:\n\n";
			
			cout << "Question 1: Guess the sum.\nAnswer: " << sum << "\n" << "Your answer: " << sumAnswer << "\n" << "You got this question " << sumAnswerCheck << ".\n";
			cout << "Question 2: Guess the average.\nAnswer: " << average << "\n" << "Your answer: " << averageAnswer << "\n" << "You got this question " << averageAnswerCheck << ".\n";
			cout << "Question 3: Guess the largest.\nAnswer: " << largest << "\n" << "Your answer: " << largestAnswer << "\n" << "You got this question " << largestAnswerCheck << ".\n";
			cout << "Question 4: Guess the smallest.\nAnswer: " << smallest << "\n" << "Your answer: " <<smallestAnswer << "\n" << "You got this question " << smallestAnswerCheck << ".\n";

			// Display message depending on user score
			
			if (score == 4)
				cout << "\nBrilliant! You got all of the questions right!\n";
			else
			if (score == 3)
				cout << "\nGood job! You got 3 questions right!\n";
			else
				cout << "\nConsider a math tutor! You only got " << score << " out of 4 questions right.\n";
		}
	}
}
