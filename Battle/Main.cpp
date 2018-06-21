#include "main.h"

using namespace std;

int main() {
	srand(time(NULL));

	// vars
	int amountOfPeople = 1;
	vector<Person*> persons;
	vector<Person*> ownPersons;

	string createPerson;

	// the welcome message
	cout << "Welcome to the battle" << "\n";

	// ask if the user want to create a person
	cout << "Do you want to create your own person || yes or no" << "\n";
	// get the awnser

	// TODO: fix the yes no awnsers

	/*	
	bool correctAwnser = false;
	while (!correctAwnser) {
		cin >> createPerson;
		if (createPerson == "yes" || createPerson == "Yes")
		{
			cout << "Yeaahh" << endl;
		}
		else if (createPerson == "no" || createPerson == "No")
		{

		}
		else
		{
			cout << "Please enter yes or no. \n\n";
			cin.clear();
		}
	}*/
	
	/*while (createPerson != "yes" || createPerson != "Yes" || createPerson != "no" || createPerson != "No") {
		cout << createPerson << "\n";
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}  	  */

	cout << "How many people do you want to create" << "\n";
	
	while (!(cin >> amountOfPeople)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}

	cout << "You enterd: " << amountOfPeople << endl;

	// start the clock
	clock_t start;
	double duration = 0;
	start = clock();

	// create the people 
	for (unsigned int i = 0; i < amountOfPeople; i++) {
		Person* p = new Person();
		persons.push_back(p);
	}

	while (persons.size() > 1) {
		// the active person
		Person* activePerson = persons[RandomInt(persons.size())];

		// get the second random
		Person * secondPerson = persons[RandomInt(persons.size())];


		// random action
		switch (RandomInt(2)) {
		case 0: 
			if (activePerson == secondPerson)
			{
			
			}
			else {
				activePerson->AttackPerson(secondPerson);
			}	 
			break;
		case 1:
			activePerson->SearchErea();
			cout << activePerson->personID << "|| Searched the area: "  << "\n";

			break;
		} 

		vector<Person*>::iterator it = persons.begin();
		while (it != persons.end()) {
			if ((*it)->health <= 0) {
				delete (*it);
				it = persons.erase(it);
			}
			else it++;
		}
		cout << persons.size() << " | " << "Person: " << activePerson->personID << " | " << activePerson->health << "\n";
	}

	// Show the winner
	cout << "The winner is: " << "\n";
	cout << "Person: " << persons[0]->personID << " | " << persons[0]->health << " : health left" << "\n";



	// clear the program
	vector<Person*>::iterator it = persons.begin();
	while (it != persons.end()) {
		delete (*it);
		it = persons.erase(it);
	}

	// calc the duration
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;

	int sec = duration;
	int min = 0;
	while (sec > 60) {
		min++;
		sec -= 60;
	}

	cout << "time " << min << ":" << sec << "\n";

	cout << "Cleared - Press 1 + enter to stop" << endl;
	string input = "";
	cin >> input;

	return 0;
}	   

int RandomInt(int i) {
	return rand() % i;
}

