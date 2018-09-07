/*
Jiali Chen
Lab 0 - Using the Bag Class
In this lab, we use and adjust a pre-existing 'Bag' class for use in our program driver in order to allow the user to count and/or remove certain items from a store bag.
*/

#include "Bag.h"

using namespace std;

int search_and_remove(string, Bag<string>&);

int main() {

	int i;
	int holder;

	string purchase[] = {
		"eggs",
		"bread",
		"cereal",
		"milk",
		"butter",
		"fish",
		"beef",
		"chicken"
	};

	Bag<string> storeBag; //Initial bag
	Bag<string> fragileBag; //Put fragile stuff in here

	/*
	PART 1
	*/
	cout << "*******\n";
	cout << "PART 1" << endl;
	cout << "*******\n";

	//Go shopping
	storeBag.add(purchase[0]);
	storeBag.add(purchase[1]);
	storeBag.add(purchase[0]);
	storeBag.add(purchase[3]);
	storeBag.add(purchase[4]);
	storeBag.add(purchase[5]);

	//Show store bag
	cout << "STORE BAG" << endl;
	storeBag.displayBagContents();

	cout << '\n';



	//Find fragile items. If found, place into fragileBag.
	cout << "Searching for fragile items and moving items to fragile bag..." << endl;
	

	if (storeBag.contains("eggs")) {
		holder = storeBag.getFrequencyOf("eggs"); //Place inside variable to avoid # change affecting loop
		for (i = 0; i < holder; i++) {
		storeBag.remove("eggs");
		fragileBag.add("eggs");
		}
	}
	if (storeBag.contains("bread")) {
		holder = storeBag.getFrequencyOf("bread"); //Place inside variable to avoid # change affecting loop
		for (i = 0; i < storeBag.getFrequencyOf("bread"); i++) {
			storeBag.remove("bread");
			fragileBag.add("bread");
		}
	}

	// Print contents of both bags

	cout << '\n';

	cout << "STORE BAG" << endl;
	storeBag.displayBagContents();

	cout << '\n';

	cout << "FRAGILE BAG" << endl;
	fragileBag.displayBagContents();

	cout << '\n';

	/* 
	PART 2
	*/

	cout << "*******\n";
	cout << "PART 2" << endl;
	cout << "*******\n";

	//Change bag
	storeBag.clear();
	storeBag.add(purchase[1]);
	storeBag.add(purchase[0]);
	storeBag.add(purchase[0]);
	storeBag.add(purchase[0]);
	storeBag.add(purchase[0]);
	storeBag.add(purchase[0]);

	//Show store bag
	cout << "STORE BAG" << endl;
	storeBag.displayBagContents();

	cout << '\n';

	//cin
	string userInput;
	cout << "What would you like to search for?" << endl;
	cin >> userInput;

	//Test function in single bag
	cout << "THE AMOUNT OF ITEMS REMOVED IS " << search_and_remove(userInput, storeBag) << endl;


	// Print contents of store bag
	
	cout << '\n';

	cout << "STORE BAG" << endl;
	storeBag.displayBagContents();
	
	return 0;
}

int search_and_remove(string searchterm, Bag<string> &bagname) {

	int count = 0; //initiate count to 0 in case there are no case matches

	//If the bag is empty, there should be no occurences, therefore return 0
	if (bagname.isEmpty()) {
		return 0;
	}

	//Get frequency of item
	int freq = bagname.getFrequencyOf(searchterm);

	//Keep looping to make sure all instances of item are fully removed from bag
	int i;
	for (i = 0; i < freq; i++) {
		//Use remove function search and remove item from bag
		if (bagname.remove(searchterm)) {
			//Increase counter when item is removed
			count++;
		}
	}

	return count;
}


/*
**********************************************
OUTPUT
**********************************************


*******
PART 1
*******
STORE BAG
eggs
bread
eggs
milk
butter
fish

Searching for fragile items and moving items to fragile bag...

STORE BAG
fish
milk
butter

FRAGILE BAG
eggs
eggs
bread

*******
PART 2
*******
STORE BAG
bread
eggs
eggs
eggs
eggs
eggs

What would you like to search for?
eggs
THE AMOUNT OF ITEMS REMOVED IS 5

STORE BAG
bread
Press any key to continue . . .


*/