#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

int main(int args, char* argsv[]){

	//1. pick a winning door.
	int winningNumber;
	srand(time(0));
	rand();
	winningNumber = rand() % 3 + 1;
	//cout<<"winning number is " <<winningNumber<<endl;
	//2. ask the user for which door they want to pick
	cout<<"Hello user! Welcome to the game!\nPlease pick a door! Limited to door 1, 2, or 3.\n"<<endl;
	int userChoice;
	bool validInput = false;

	while(validInput == false){
		cin>>userChoice;
		if(userChoice < 1 || userChoice > 3){
			cout<<"Please enter 1, 2, or 3.\n"<<endl;
		}
		else{
			validInput = true;
		}
	}

	//3. pick another door to reveal to player. MUST BE GOAT
	bool newGoat = false;
	int goat = 0;
	for(int i = 1;i < 4;i++){
		if(i != winningNumber & i != userChoice){
			goat = i;
		}
	}
	cout<<"You have chosen door# " << userChoice << "\nI will now reveal to you that door # " << goat << " has a goat behind it!\n"<<endl; 

	//4. ask user if they want to switch
	cout<<"Would you like to switch your choice to the only remaining unopened door? Please respond with a y or n"<<endl;
	char switchResponse;
	validInput = false;
	while(validInput == false){
		cin>>switchResponse;
		if(switchResponse == 'y' || switchResponse == 'n'){
			validInput = true;

		}
		else{
			cout<<"Please enter y or n.\n"<<endl;
		}
	}
	//5. reveal if they won or lost
	//if win:	pick 1 of 5 glorious prizes ( random )
	//if loss:	write a sad message out

	int newUserChoice;
	if(switchResponse == 'y'){
		for(int i = 1;i < 4;i++){
			if(i != userChoice & i != goat){
				newUserChoice = i;
			}
		}
	}
	else{
		newUserChoice = userChoice;
	}

	if(newUserChoice == winningNumber){
		int randPrize = rand() % 5;
		string stringArray[5] = {" A KITTEN!", " A PUPPY", " A JET SKI", " A SPORTS CAR", "1 MILLION DOLLARS"};

		cout<<"CONGRATULATIONS YOU WON!!!" << stringArray[randPrize] <<endl;	
	}
	else{
		cout<<"I'm sorry it looks like you are a loser. Get off my game."<<endl;
	}

	
	return 0;
}