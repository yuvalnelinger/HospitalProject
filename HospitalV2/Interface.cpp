#include "Interface.h"

void Interface::mainMenu(Hospital& hospital)
{
	int proceed;
	int selection;
	do {
		cout << "Welcome to " << hospital.getName() << " hospital!" << endl;
		Interface::printMainMenu();
		cin >> selection;
		switch (selection)
		{
		case 1: //add a department
		{
			char* name = new char[MAX_NAME];
			Interface::getDepartmentInfo(&name);
			hospital.addDepartment(name);
			delete[] name;
		}
		break;
		case 2: //add a staff member
		{
			//prevent from the user to add a staff member without any departments in the hospital
			if (hospital.getNumOfDepartments() == 0)
			{
				cout << "It not possible to add a staff memeber without any departments!\n"
					<< "please add a department first" << endl;
				//create department
				char* name = new char[MAX_NAME];
				Interface::getDepartmentInfo(&name);
				hospital.addDepartment(name);
				delete[] name;
			}

			int selection;
			char* name = new char[MAX_NAME];
			Department* assigned_dep = nullptr;
			bool isSurgeon;
			bool isResearcher;
			int num_of_surgeries;
			Interface::printAddStaffMemberMenu();

			bool again = true;
			while (again)
			{
				again = false;
				cin >> selection;
				switch (selection)
				{
				case 1: //add doctor
				{
					char* docSpecialty = new char[MAX_NAME];
					Interface::getDoctorInfo(&name, &docSpecialty, &assigned_dep, hospital, &isSurgeon, &isResearcher, &num_of_surgeries);
					hospital.addDoctor(name, docSpecialty, assigned_dep, isSurgeon, isResearcher, num_of_surgeries);
					delete[] docSpecialty;
				}
				break;
				case 2: //add nurse
				{
					int yearsExperience;
					Interface::getNurseInfo(&name, &yearsExperience, &assigned_dep, hospital);
					hospital.addNurse(name, yearsExperience, assigned_dep);
				}
				break;

				delete[] name;

				default:
				{
					again = true;
					cout << "Invalid selection. Please select again" << endl;
				}
				break;
				}//end switch
			}//end while
		}
		break;
		case 3: //patient operations
		{
			int choice;
			if (hospital.getNumOfDepartments() == 0)
			{
				cout << "You have to create a department before making any patient operations." << endl;
				char* name = new char[MAX_NAME];
				Interface::getDepartmentInfo(&name);
				hospital.addDepartment(name);
				delete[] name;
			}
			Interface::printPatientsMenu();
			cin >> choice;
			bool invalid = true;
			while (invalid)
			{
				switch (choice)
				{
				case 1: //add a new visit
				{
					invalid = false;
					bool isNewPatient = false;
					bool isSurgery=false;
					bool isFast = false;
					int room;
					Patient* newPatient = nullptr;
					Date visitDate;
					char* visPurpose = new char[MAX_NAME];
					Department* depToAdd;
					StaffMember* treatDoc = nullptr;

					Interface::getVisitInfo(&newPatient, &visitDate, &visPurpose, &depToAdd, &treatDoc, isNewPatient, &isFast, &room,&isSurgery, hospital);
					newPatient->addVisit(newPatient, visitDate, treatDoc,visPurpose,&isFast,room,&isSurgery);  //add new visit to patient
					depToAdd->addPatient(newPatient); //add patient to current department (of visit)

					if (isNewPatient = true) //add patient to hospital only if he is new patient
						hospital.addPatient(newPatient);

					delete[]visPurpose;
					cout << "Successfully added visit." << endl;
				}
				break;
				case 2: //show all patients that belong to a department
				{
					invalid = false;
					int select;
					Department* depToShow;
					cout << "Please select a department: " << endl;
					hospital.showDepartments();
					cin >> select;
					while (!Interface::isValid(select - 1, 0, hospital.getNumOfDepartments() - 1))
					{
						cout << "Invalid input. Please enter a valid department ID" << endl;
						cin >> select;
					}

					depToShow = hospital.getDepartmentByIndex(select - 1);
					cout << "These are the patients of department " << depToShow->getName() << endl;
					depToShow->showPatients();
					break;
				}

				case 3: //search a patient by ID
				{
					invalid = false;
					int patID;
					Patient* patientToShow;
					cout << "Enter the ID of the patient to search:" << endl;
					cin >> patID;
					patientToShow = hospital.getPatientByID(patID);
					if (patientToShow == 0)
					{
						cout << "Patient not found." << endl;
					}
					else
					{
						cout << "Patient with ID " << patID << " is " << patientToShow->getName() << " and his/her current department is " << patientToShow->getCurrentDepartment()->getName() << "." << endl;
						if (patientToShow->getLastVisitType())
						{
							cout << "The patient's last visit was for surgery, in room " << ((SurgeryVisit*)(patientToShow->getLastVisit()))->getRoomNum();
							if (((SurgeryVisit*)(patientToShow->getLastVisit()))->getIsFast())
							{
								cout << " and was in fast." << endl;
							}
							else
							{
								cout << " and wasn't in fast." << endl;
							}
						}
						else
						{
							cout << "The patient's last visit was for tests." << endl;
						}
					}
					break;
				}
				default:
				{
					cout << "Invalid selection. Please try again" << endl;
					break;
				}

				}
			}
			break;
		}//end patient operations

		case 4:  //enter the research institute
		{
			Interface::printRIMenu();
			bool again = true;
			while (again)
			{
				again = false;
				int selection;
				cin >> selection;
				switch (selection)
				{
				case 1: //add a researcher
				{
					char* name = new char[MAX_NAME];
					Interface::getResearcherInfo(&name);
					hospital.getResearchInstitute().addResearcher(name);
					delete[] name;
				}
				break;
				case 2: //add an article
				{
					if (hospital.getResearchInstitute().getNumOfResearchers() == 0)
					{
						cout << "There are no researchers in the research institute. Please add a researcher first" << endl;
						char* name = new char[MAX_NAME];
						Interface::getResearcherInfo(&name);
						hospital.getResearchInstitute().addResearcher(name);
						hospital.getResearchInstitute().showResearchers();
						delete[] name;
					}
					int r_index;
					Date date;
					char* title = new char[MAX_TITLE];
					char* name_of_magazine = new char[MAX_NAME];
					Interface::getArticleInfo(&title, &name_of_magazine, &date, &r_index, hospital);
					hospital.getResearchInstitute().addArticle(date, title, name_of_magazine, r_index);
					delete[] title;
					delete[] name_of_magazine;
				}
				break;
				case 3: //show all researchers
					hospital.getResearchInstitute().showResearchers();
					break;
				default:
				{
					again = true;
					cout << "Invalid value. Please try again" << endl;
				}
				break;
				}//end switch
			}//end while
		}
		break;
		case 5: //show all staff members
		{
			hospital.showStaff();
		}
		break;
		case 6: //show all doctor-researchers
		{
			hospital.showDocResearchers();
		}
		break;
		case 7: //compare researchers by number of articles
		{
			Interface::compareResearchers(hospital.getResearchInstitute());
		}
		break;
		default:
		{
			cout << "Invalid value. Please try again" << endl;
		}
		break;

		}

		cout << "Would you like to perform another action?\n"
			<< "Press 1 for YES or 0 for NO" << endl;
		cin >> proceed;
		while(proceed != 0 && proceed != 1)
		{
			cout << "Invalid choice. Press 1 for YES or 0 for NO" << endl;
			cin >> proceed;
		} 

	} while (proceed);

	cout << "Get well soon, Goodbye!" << endl;

}


//menues print
void Interface::printMainMenu()
{
	cout << "What would you like to do? please choose an option from the menu:" << endl;
	cout << "1. Add a department\n"
	 	<< "2. Add a staff member\n"
		<< "3. Patient operations\n"
		<< "4. Enter the research institute\n"
		<< "5. Show all staff members\n"
		<< "6. Show all Doctor-Researchers\n"
		<< "7. Compare researchers by number of articles"
		<< endl;
}

void Interface::printAddStaffMemberMenu()
{
	cout << "What would you like to add? Choose the option from the menu:" << endl;
	cout << "1. Doctor\n"
		<< "2. Nurse"
		<< endl;
}

void Interface::printPatientsMenu()
{
	cout << "What operation would you like to perform?" << endl;
	cout << "1. Add a new visit\n"
	 	 << "2. Show all patients of a specific department\n"
		 << "3. Search patient by ID and get his details" << endl;
}

void Interface::printRIMenu()
{
	cout << "Welcome to the research institute! What would you like to do?" << endl;
	cout << "1. Add a researcher\n"
		<< "2. Add an article to a researcher\n"
		<< "3. Show all researchers"
		<< endl;
}

//cases
void Interface::getDepartmentInfo(char** name)
{
	cout << "Adding a new department, choose name: " << endl;
	*name = getInput();
}

void Interface::getDoctorInfo(char** name, char** specialty, Department** depart, Hospital& hospital,bool* isSurgeon,bool* isResearcher, int* num_of_surgeries)
{
	int depIndex;

	cout << "Adding a new doctor, choose name: " << endl;
	*name = getInput();
	cout << "Adding a new doctor, choose specialty: " << endl;
	*specialty = getInput();
	cout << "In which department is the doctor going to work? Insert the index" << endl;
	hospital.showDepartments();
	cin >> depIndex;

	while (!isValid(depIndex-1, 0, hospital.getNumOfDepartments()-1))
	{
		cout << "Invalid input. Please enter a valid department ID" << endl;
		cin.ignore();
		cin >>depIndex;
	}

	*depart = hospital.getDepartmentByIndex(depIndex-1);
	cout << "Is this doctor a surgeon? press 1 for YES, 0 for NO" << endl;
	cin >> *isSurgeon;
	if (*isSurgeon==1)
	{
		cout << "How many surgeries did the surgeon perform?" << endl;
		cin >> *num_of_surgeries;

	}
	cout << "Is this doctor a researcher? press 1 for YES, 0 for NO" << endl;
	cin >> *isResearcher;
}

void Interface::getNurseInfo(char** name, int* yearsExperience, Department** depart, Hospital& hospital)
{
	int depIndex;

	cout << "Adding a new nurse, choose name: " << endl;
	*name = getInput();
	cout << "Adding a new nurse, type years of experience: " << endl;
	cin >> *yearsExperience;
	cout << "In which department is the nurse going to work? Insert the index" << endl;
	hospital.showDepartments();
	cin >> depIndex;

	while (!isValid(depIndex-1, 0, hospital.getNumOfDepartments()-1))
	{
		cout << "Invalid input. Please enter a valid department ID" << endl;
		cin >> depIndex;
	}

	*depart = hospital.getDepartmentByIndex(depIndex-1);
}

void Interface::getResearcherInfo(char** name)
{
	cout << "Please enter name:" << endl;
	*name = getInput();
}

void Interface::getArticleInfo(char** title, char** name_of_magazine, Date* p_date, int* r_index, Hospital& hospital)
{
	cout << "This is the list of researchers:" << endl;
	hospital.getResearchInstitute().showResearchers();
	char* search_name = new char[MAX_NAME];
	cout << "To whom you would like to add the article? please type name:" << endl;
	search_name = getInput();

	*r_index = hospital.getResearchInstitute().searchResearcherByName(search_name);

	while (*r_index == NOT_FOUND)
	{
		cout << "There is no researcher with this name! please try again:" << endl;
		delete[] search_name;
		search_name = getInput();
		*r_index = hospital.getResearchInstitute().searchResearcherByName(search_name);
	}

	//researcher found
	cout << "Adding a new article for " << search_name << ":" << endl;
	cout << "What is the article's date?" << endl;

	int day, month, year;
	bool res;

	do {
		cout << "please enter day:" << endl;
		cin >> day;
		res = p_date->setDay(day);

	} while (res != true);

	do {
		cout << "please enter month:" << endl;
		cin >> month;
		res = p_date->setMonth(month);

	} while (res != true);

	do {
		cout << "please enter year:" << endl;
		cin >> year;
		res = p_date->setYear(year);

	} while (res != true);

	cout << "enter the title: " << endl;
	*title = getInput();
	cout << "enter the magazine's name: " << endl;
	*name_of_magazine = getInput();

	delete[] search_name;
}

void Interface::getVisitInfo(Patient** newPatient, Date* visitDate, char** visPurpose, Department** depToAdd, StaffMember** treatDoc, bool isNewPatient, bool* isFast, int* room, bool* isSurgery,Hospital& hospital)
{
	int patientID;
	char* nameToAdd = new char[MAX_NAME];
	int newYear = 0;
	int newGen = 0;
	int genIndex = 0;

	cout << "Adding a new visit, Please enter Patient ID (9 digits): " << endl;
	cin >> patientID;
	int numOfDigits = (int)log10((double)patientID) + 1;
	while (numOfDigits != 9)
	{
		cout << "Patint ID must be 9 digits. Please enter ID" << endl;
		cin >> patientID;
		numOfDigits = (int)log10((double)patientID) + 1;
	}
	*newPatient = hospital.getPatientByID(patientID);

	if (!*newPatient)
	{
		cout << "Patient not found, creating a new patient, enter details: " << endl;
		cout << "Enter Name: " << endl;
		nameToAdd = getInput();
		cout << "Enter Year Of Birth: " << endl;
		cin >> newYear;
		cout << "Enter Gender (0 for MALE, 1 for FEMALE): " << endl;
		cin >> genIndex;
		newGen = genIndex;
		cout << "Received details, creating Patient" << endl;
		*newPatient = new Patient(nameToAdd, patientID, newYear, newGen);
		isNewPatient = true;
		delete[] nameToAdd;
	}

	cout << "What is the department the visit is to? insert the index of it " << endl;
	int patDep;
	hospital.showDepartments();
	cin >> patDep;
	while (!isValid(patDep-1, 0, hospital.getNumOfDepartments()-1))
	{
		cout << "Invalid input. Please enter a valid department ID" << endl;
		cin >> patDep;
	}
	*depToAdd = hospital.getDepartmentByIndex(patDep-1);
	(*newPatient)->setCurrDepartment(*depToAdd);
	if ((*depToAdd)->getNumOfStaffMembers() == 0)
	{
		cout << "No staff in this department yet. Please add staff" << endl;
		int selection;
		printAddStaffMemberMenu();
		cin >> selection;
		while (!isValid(selection, 1, 2))
		{
			cout << "Invalid input, select between Nurse to Doctor" << endl;
			cin >> selection;
		}
		char* name = new char[MAX_NAME];
		bool isSurgeon;
		bool isResearcher;
		int num_of_surgeries;
		if (selection == 1)
		{
			char* docSpecialty = new char[MAX_NAME];
			Interface::getDoctorInfo(&name, &docSpecialty, depToAdd, hospital,&isSurgeon,&isResearcher,&num_of_surgeries);
			hospital.addDoctor(name, docSpecialty, *depToAdd,isSurgeon,isResearcher,num_of_surgeries);
			delete[] name;
			delete[] docSpecialty;
		}
		else
		{
			int yearsExperience;
			Interface::getNurseInfo(&name, &yearsExperience, depToAdd, hospital);
			hospital.addNurse(name, yearsExperience, *depToAdd);
			delete[] name;
		}

	}
	cout << "Enter visit details. Visit date (day, month, year): " << endl;
	int day, month, year;
	bool res;
	do {
		cout << "please enter day:" << endl;
		cin >> day;
		res = visitDate->setDay(day);

	} while (res != true);

	do {
		cout << "please enter month:" << endl;
		cin >> month;
		res = visitDate->setMonth(month);

	} while (res != true);

	do {
		cout << "please enter year:" << endl;
		cin >> year;
		res = visitDate->setYear(year);

	} while (res != true);

	int visPurp=0;
	cout << "What is the visit type? for surgery press 2, for tests press 1: " << endl;
	cin >> visPurp;
	while (visPurp != 1 && visPurp != 2)
	{
		cout << "Invalid selection. Please press 1 for tests visit, 2 for surgery visit" << endl;
		cin >> visPurp;
	}

	if (visPurp == 2)
	{
		*isSurgery = true;
		cout << "Is the patient in fast? press 1 if YES, 0 if NO" << endl;
		cin >> *isFast;
		cout << "What is the room number of the surgery?" << endl;
		cin >> *room;
	}
	cout << "What is the visit purpose?" << endl;
	*visPurpose = getInput();
	int idToCheck;
	cout << "This is the list of doctors and nurses you can choose from:" << endl;
	(*depToAdd)->showStaff();
	
	cout << "Enter the staff member ID: " << endl;
	cin >> idToCheck;
	*treatDoc = hospital.getStaffMemberByID(idToCheck);

	while (*treatDoc == 0)
		{
			cout << "Couldn't find staff member, insert ID of doctor/nurse from the list above." << endl;
			cin >> idToCheck;
			*treatDoc = hospital.getStaffMemberByID(idToCheck);
		}
	cout << "Staff member set as treating staff." << endl;

}

void Interface::compareResearchers(Research_Institute& RI)
{
	if (RI.getNumOfResearchers() < 2)
	{
		cout << "There must be at least 2 researchers to compare" << endl;
		return;
	}

	char* search_name;
	int index;

	cout << "Choose two researches to compare by their number of articles\n"
		<< "This is the list of available researchers:" << endl;
	RI.showResearchers();

	cout << "Choose the first researcher, type the name:" << endl;

	do
	{
		search_name = getInput();
		index = RI.searchResearcherByName(search_name);
	} while (index == -1);

	StaffMember* temp1 = RI.getResearcherByIndex(index);

	cout << "Choose the second researcher, type the name:" << endl;

	do
	{
		search_name = getInput();
		index = RI.searchResearcherByName(search_name);
	} while (index == -1);

	StaffMember* temp2 = RI.getResearcherByIndex(index);

	Researcher* researcher1 = dynamic_cast<Researcher*>(temp1);
	Researcher* researcher2 = dynamic_cast<Researcher*>(temp2);

	if (*researcher1 > *researcher2)
	{
		cout << researcher1->getName() << " has more articles than " << researcher2->getName() << endl;
	}
	else
	{
		cout << researcher2->getName() << " has more articles than " << researcher1->getName() << endl;
	}
}

//utilities
char* Interface::getInput()
{
	char* input = new char[MAX_SIZE];
	int logSize = 0;

	int c = getchar();
	if (c == '\n')
		c = getchar();
	while (c != '\n')
	{
		input[logSize] = c;
		logSize++;

		c = getchar();
	}

	input[logSize] = '\0';
	char* resized_input = new char[strlen(input)+1];
	strcpy(resized_input, input);
	resized_input[logSize] = '\0';

	delete[]input;
	input = resized_input;

	return input;
}

bool Interface::isValid(int check, int lower, int upper)
{
	return (lower <= check) && (check <= upper);
}