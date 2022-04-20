//Carter's Code
#include <iostream>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <list>
#include <vector>
#include <chrono>


using namespace std;


struct Node{
        string first;
        string last;
        string email;
        string add;
        string ssn;
   
        Node* next;
        Node();
        Node(string _ssn, string _first, string _last, string _add, string _email);
        void getfirst();
        void printInfo();
        string getSSN();

};
Node::Node(){
    first = "";
    last = "";
    email = "";
    add = "";
    ssn = "";
    next = NULL;
}
 Node::Node(string _ssn, string _first, string _last, string _add, string _email) {
        ssn = _ssn;
        first = _first;
        last = _last;
        add = _add;
        email = _email;
        next = NULL;
}

string Node::getSSN(){
    return ssn;
}
void Node::getfirst(){
    cout << first << endl;
}

void Node::printInfo(){
    cout << first << " " << last << endl;
}

void searchFirstName(list<Node> &lst, string name){ // prints a list of Node*
    list<Node> foundResults;
    for (auto iter = lst.begin(); iter != lst.end(); iter++){
        if(iter->first.compare(name) == 0){
            foundResults.push_back(*iter);
        }
    }
    if(foundResults.size() != 0){ //accessing the list of Node pointers using a pointer
    
        for (auto iter = foundResults.begin(); iter != foundResults.end(); iter++){
            cout << "\nFull Name: ";
            cout << iter->first << " " << iter->last << endl;
            cout << "Email: ";
            cout << iter->email << endl << endl;
        }
        cout << "We found " << foundResults.size() << " results!\n\n";
    }
    else{
        cout << "Sorry, no results found!\n\n";
    }
}

void searchLastName(list<Node> &lst, string name){ // prints a list of Node*
    list<Node> foundResults;
    for (auto iter = lst.begin(); iter != lst.end(); iter++){
        if(iter->last.compare(name) == 0){
            foundResults.push_back(*iter);
        }
    }
    if(foundResults.size() != 0){ //accessing the list of Node pointers using a pointer
  
        for (auto iter = foundResults.begin(); iter != foundResults.end(); iter++){
            cout << "\nFull Name: ";
            cout << iter->first << " " << iter->last << endl;
            cout << "Email: ";
            cout << iter->email << endl << endl;
        }
        cout << "We found " << foundResults.size() << " results!\n\n";
    }
    else{
        cout << "Sorry, no results found!\n\n";
    }
}

void searchFullName(list<Node> &lst, string firstname, string lastname){ // prints a list of Node*

//Originally, we had worked with a string with both first and last name however trying to manipulate the strings and compare them with node values gave loop errors
//So we changed the input to have seperate string variables and worked from there
    
    list<Node> LastNameResults;
    list<Node> foundResults;

    for (auto iter = lst.begin(); iter != lst.end(); iter++){
        if(iter->last.compare(lastname) == 0){
            LastNameResults.push_back(*iter);
        }
    }
    for (auto it = LastNameResults.begin(); it != LastNameResults.end(); it++){
        if(it->first.compare(firstname) == 0){
            foundResults.push_back(*it);
        }
    }
    if(foundResults.size() != 0){ //accessing the list of Node pointers using a pointer
        cout << "We found " << foundResults.size() << " result!\n\n";   
        for (auto iter = foundResults.begin(); iter != foundResults.end(); iter++){
            cout << "Full Name: ";
            cout << iter->first << " " << iter->last << endl;
            cout << "Email: ";
            cout << iter->email << endl << endl;
        }
    }
    else{
        cout << "\nSorry, no results found!\n\n";
    }
}

void createList(list<Node> &lst, string filePath){
        ifstream infile(filePath);
        int count = 0;
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
                string street;
                string stateZip; 
                string add; 
                string email; 
                getline(stream, index, ',');
                getline(stream, ssnToEdit, ',');
                string ssn = ssnToEdit.substr(0, 3) + ssnToEdit.substr(4, 2) + ssnToEdit.substr(7, 4); 
                getline(stream, first, ',');
                getline(stream, last, ',');
                getline(stream, add, ',');
                getline(stream, email, ',');

                //cout << ssn << endl;
                //cout << first << endl;
                Node newNode = Node(ssn, first, last, add, email);
                lst.push_back(newNode);
            }
        }

}

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
	cout << "\n" << first << " " << last << endl;
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

//Creating a List
    auto start = std::chrono::system_clock::now();
    list<Node> lst;
    string filePath = "EmployeeData.csv";
    createList(lst, filePath);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Time to build linked list implementation for employee search: " << diff.count() << " seconds" << endl;

//Creating a map
    start = std::chrono::system_clock::now();
	string employeeFile = "EmployeeData.csv";
	string adminFile = "AdminData.csv";

	map<int, MapNode> companyMap;
	map<string, string> adminMap;

	createMap(companyMap, employeeFile);
	createAdminMap(adminMap, adminFile);
    end = std::chrono::system_clock::now();
    diff = end - start;
    cout << "Time to build map implementation for employee search: " << diff.count() << " seconds" << endl;
	
    //Checks to see if maps created correctly
	/*int i = 0;
	for (auto iter = companyMap.begin(); iter != companyMap.end(); iter++) {
		i++;
	}
	int j = 0;
	for (auto iter = adminMap.begin(); iter != adminMap.end(); iter++) {
		j++;
	}
	cout << "Items in employee map: " << i << endl;
	cout << "Items in admin map : " << j << endl;
    */

	while (running) {
		cout << "How would you like to search for an employee?\n";
		cout << "1. Employee Search\n2. Admin Search\nOption: ";
		cin >> menuOption;
		if (menuOption == 1 ) {
			int searchOption;
			cout << "Please Select the way you would like to search: " << endl;
			cout << "1. Search for employee first name" << endl;
			cout << "2. Search for employee last name" << endl;
			cout << "3. Search by full name" << endl;
			cout << "Please enter a valid interger: ";
			cin >> searchOption;



            //at this point, we have created the linked list of nodes - now to search using 3 different options
            //following three methods should search for the names, store it into a vector and print full name and email

			if (searchOption == 1) {
				string name;
                cout << "First Name: ";
                cin >> name;
                start = std::chrono::system_clock::now();
                searchFirstName(lst, name);
                end = std::chrono::system_clock::now();
                diff = end - start;
                cout << "Time to search by first name - using list: " << diff.count() << " seconds" << endl;
			}

			else if (searchOption== 2) {
				string name;
                cout << "Name: ";
                cin >> name;
                start = std::chrono::system_clock::now();
                searchLastName(lst, name);
                end = std::chrono::system_clock::now();
                diff = end - start;
                cout << "Time to search by last name - using list: " << diff.count() << " seconds" << endl;
			}
			else if (searchOption == 3) {
				string firstname;
                string lastname;
                cout << "First Name: ";
                cin >> firstname;
                cout << "Last Name: ";
                cin >> lastname;
                start = std::chrono::system_clock::now();
                searchFullName(lst, firstname, lastname);
                end = std::chrono::system_clock::now();
                diff = end - start;
                cout << "Time to search by full name - using list: " << diff.count() << " seconds\n" << endl;
			}
			else {
				cout << "Invalid input" << endl;
			}
			
		}
		else if(menuOption == 2){
			string adminUser;
			string enteredPassword;
			int attempts = 0;
			while (adminLogin == false ) {
				cout << "\nPlease enter valid administrator username: ";
				cin >> adminUser;
				

				if (adminMap.count(adminUser)) {
					bool validPassword = false;
					while (validPassword == false) {
						cout << "Please enter password: ";
						cin >> enteredPassword;
						string correctPassword = adminMap[adminUser];
						if (correctPassword.compare(enteredPassword) == 0) {
							adminLogin = true;
							validPassword = true;
							cout << "Admin login successful.\n\n";
						}
						attempts++;
						if (attempts == 4) {
							cout << "\nToo many failed attempts. Program Terminating." << endl;
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
			while(validSearch == false){
				cout << "Please enter the SSN of the employee: ";
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
                    start = std::chrono::system_clock::now();
					if (companyMap.count(ssnInteger)) {
						MapNode test = companyMap[ssnInteger];
						test.printInfo();
						validSearch = true;
					}
					else {
						cout << "No employee with that SSN can be found." << endl;
						validSearch = true;
					}
                    end = std::chrono::system_clock::now();
                    diff = end - start;
                    cout << "Time to search by Social Security Number - using map: " << diff.count() << " seconds\n" << endl;

				}
				else {
					cout << "Invalid SSN. Please retry." << endl;
				}	
			}
			
		}
	}

	return 0;

}




