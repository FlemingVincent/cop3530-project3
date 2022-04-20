#include <iostream>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct MapNode {
	string first;
	string last;
	string email;
	string add;
	string username;
	string password;
	MapNode(string _first, string _last, string _email, string _add, string _user, string _pass) {
		first = _first;
		last = _last;
		email = _email;
		add = _add;
		username = _user;
		password = _pass;
	}
	MapNode() {
		first = "";
		last = "";
		email = "";
		add = "";
		username = "";
		password = "";
	}
	void printInfo();
};


void MapNode::printInfo() {
	cout << first << " " << last << endl;
	cout << "Email: " << email << endl;
	cout << "Address On File: " << add << endl;
	cout << "Employee Username: " << username << endl;
	cout << "Employee Password: " << password << endl;
}

void createMap(std::map<int, MapNode>& temp_map, string fileName) {
	ifstream infile(fileName);
	string firstLine;
	getline(infile, firstLine);
	//cout << firstLine << endl;
	//cout << firstLine << endl;
	string current;
	while (getline(infile, current)) {
		//Create a stream of data 
		istringstream stream(current);

		string garbageNumber;
		string ssnString;
		string first;
		string last;
		string email;
		//Dropped commas from address in data file creation for consistent format
		/*
		string street;
		string stateZip;
		*/
		string address;
		string user;
		string pass;
		string what;

		getline(stream, garbageNumber, ',');
		getline(stream, ssnString, ',');
		//cout << ssnString << endl;
		ssnString = ssnString.substr(0, 3) + ssnString.substr(4, 2) + ssnString.substr(7, 4);

		int ssn = atoi(ssnString.c_str());

		getline(stream, first, ',');
		getline(stream, last, ',');
		getline(stream, address, ',');
		getline(stream, email, ',');
		getline(stream, user, ',');
		getline(stream, pass, ',');
		getline(stream, what, ',');




		MapNode nodeToAdd = MapNode(first, last, email, address, user, pass);
		//cout << ssn << endl;
		temp_map.emplace(ssn, nodeToAdd);
	}
}

void createAdminMap(std::map<string, string>& admin_map, string fileName) {
	ifstream infile(fileName);
	//Read Header 
	string firstLine;
	getline(infile, firstLine);

	string current;
	while (getline(infile, current)) {
		//Create a stream of data 
		istringstream stream(current);

		string garbageNumber;
		string userName;
		string password;



		getline(stream, garbageNumber, ',');
		getline(stream, userName, ',');
		getline(stream, password, ',');

		admin_map.emplace(userName, password);
	}

}


int convertSSNtoInt(string ssn) {
	string ssnString = ssn.substr(0, 3) + ssn.substr(4, 2) + ssn.substr(7, 4);
	return  atoi(ssnString.c_str());
}

bool isNumber(const string& s)
{
	for (char const& ch : s) {
		if (std::isdigit(ch) == 0)
			return false;
	}
	return true;
}

int main() {

	//cout << validSSNInput("223-57-8492") << endl;
	string ssnInput;
	int menuOption;
	bool running = true;
	bool doesExist = true;

	bool adminLogin = false;

	cout << "Welcome to the Mira Incorporated Employee Database!\n";

	/*
	ifstream infile("userData.csv");
	string firstLine;
	getline(infile, firstLine);
	cout << firstLine << endl;
	*/
	string employeeFile = "userData.csv";
	string adminFile = "AdminData.csv";

	map<int, MapNode> companyMap;
	map<string, string> adminMap;

	createMap(companyMap, employeeFile);
	createAdminMap(adminMap, adminFile);
	//Checks to see if maps created correctly
	int i = 0;
	for (auto iter = companyMap.begin(); iter != companyMap.end(); iter++) {
		i++;
	}
	int j = 0;
	for (auto iter = adminMap.begin(); iter != adminMap.end(); iter++) {
		j++;
	}
	cout << "Items in employee map: " << i << endl;
	cout << "Items in admin map : " << j << endl;

	while (running) {
		cout << "How would you like to search for an employee?\n";
		cout << "1. Employee Search\n2. Admin Search\nOption: ";
		cin >> menuOption;
		if (menuOption == 1) {
			int searchOption;
			cout << "Please Select the way you would like to search: " << endl;
			cout << "1. Search for employee first name" << endl;
			cout << "2. Search for employee second name" << endl;
			cout << "3. Search by full name" << endl;
			cout << "Please enter a valid interger: " << endl;
			cin >> searchOption;

			if (searchOption == 1) {
				cout << "Searching by first name\n";
			}

			else if (searchOption == 2) {
				cout << "Searching by last name\n";

			}
			else if (searchOption == 3) {
				cout << "Searching by full name\n";
			}
			else {
				cout << "Invalid input" << endl;
			}

		}
		else if (menuOption == 2) {
			string adminUser;
			string enteredPassword;
			int attempts = 0;
			while (adminLogin == false) {
				cout << "Please enter valid administrator username\n";
				cin >> adminUser;


				if (adminMap.count(adminUser)) {
					bool validPassword = false;
					while (validPassword == false) {
						cout << "Please enter password\n";
						cin >> enteredPassword;
						string correctPassword = adminMap[adminUser];
						if (correctPassword.compare(enteredPassword) == 0) {
							adminLogin = true;
							validPassword = true;
							cout << "Admin login successful.\n";
						}
						attempts++;
						if (attempts == 4) {
							cout << "Too many failed attempts. Program Terminating." << endl;
							return 0;

							break;
						}
					}

				}
				else {
					cout << "Invalid Username." << endl;
				}
			}


			string ssnToSearch;
			bool validSearch = false;
			while (validSearch == false) {
				cout << "Please enter the SSN of the employee:\n";
				cin >> ssnToSearch;
				bool validSSN = true;
				if (ssnToSearch.size() != 11) {
					validSSN = false;
				}
				else {
					//string ssnString = ssn.substr(0, 3) + ssn.substr(4, 2) + ssn.substr(7, 4);

					//check dashes
					char dash1 = ssnToSearch.at(3);
					char dash2 = ssnToSearch.at(6);
					if (dash1 != '-' || dash2 != '-') {
						validSSN = false;
					}
					else {
						//Check the numbers to make sure they are valid
						string first3 = ssnToSearch.substr(0, 3);
						string second2 = ssnToSearch.substr(4, 2);
						string last4 = ssnToSearch.substr(7, 4);
						bool validfirst = isNumber(first3);
						bool validsecond = isNumber(second2);
						bool validlast = isNumber(last4);
						if (!validfirst || !validsecond || !validlast) {
							validSSN = false;
						}
					}
				}



				if (validSSN) {
					int ssnInteger = convertSSNtoInt(ssnToSearch);
					if (companyMap.count(ssnInteger)) {
						MapNode test = companyMap[ssnInteger];
						test.printInfo();
						validSearch = true;
					}
					else {
						cout << "No employee with that SSN can be found." << endl;
						validSearch = true;
					}

				}
				else {
					cout << "Invalid SSN. Please retry." << endl;
				}
			}

		}
	}

	return 0;

}


/*
	const int lines = 100000;
	Node* ptr = new Node[lines];
	int i = 0;
	ifstream infile("userData.csv");
	if (infile.is_open()) {
		//Reads first line of the file aka the header
		string firstLine;
		getline(infile, firstLine);

		string currentLine;
		while (getline(infile, currentLine)) {
			//Create a stream of data
			istringstream stream(currentLine);

			string index;
			string ssnToEdit;
			string first;
			string last;
			string add;
			string email;

			getline(stream, index, ',');
			getline(stream, ssnToEdit, ',');
			int ssn = stoi(ssnToEdit.substr(1, 3) + ssnToEdit.substr(5, 6) + ssnToEdit.substr(8, 11));
			getline(stream, first, ',');
			getline(stream, last, ',');
			getline(stream, add, ',');
			getline(stream, email, ',');



			ptr[i] = Node(ssn, first, last, add, email);

		}
	}

	for (int i = 0; i < 10; i++) {
		string first = ptr[i].getfirst();
		cout << first << endl;
	}



	*/