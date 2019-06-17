#include "Interface.h"
#include <iostream>
using namespace std;

void Interface::mainMenu(Hospital& hospital)
{
	int proceed;
	int selection;
	do {
		cout << "Welcome to " << hospital.getName().c_str() << " hospital!" << endl;
		Interface::printMainMenu();

		cin >> selection;

		switch (selection)
		{
		case 1: //add a department
		{
			string name;
			Interface::getDepartmentInfo(&name);
			hospital.addDepartment(name);
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
				string name;
				Interface::getDepartmentInfo(&name);
				hospital.addDepartment(name);
			}

			int selection;
			string name;
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
					string docSpecialty;
					Interface::getDoctorInfo(&name, &docSpecialty, &assigned_dep, hospital, &isSurgeon, &isResearcher, &num_of_surgeries);
					hospital.addDoctor(name, docSpecialty, assigned_dep, isSurgeon, isResearcher, num_of_surgeries);
				}
				break;
				case 2: //add nurse
				{
					int yearsExperience;
					Interface::getNurseInfo(&name, &yearsExperience, &assigned_dep, hospital);
					hospital.addNurse(name, yearsExperience, assigned_dep);
				}
				break;


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
				string name;
				Interface::getDepartmentInfo(&name);
				hospital.addDepartment(name);
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
					string visPurpose;
					Department* depToAdd;
					StaffMember* treatDoc = nullptr;

					Interface::getVisitInfo(&newPatient, &visitDate, &visPurpose, &depToAdd, &treatDoc, isNewPatient, &isFast, &room,&isSurgery, hospital);
					newPatient->addVisit(newPatient, visitDate, treatDoc,visPurpose,&isFast,room,&isSurgery);  //add new visit to patient
					depToAdd->addPatient(newPatient); //add patient to current department (of visit)

					if (isNewPatient = true) //add patient to hospital only if he is new patient
						hospital.addPatient(newPatient);

					cout << "Successfully added visit." << endl;
				}
				break;
				case 2: //show all patients that belong to a department
				{
					invalid = false;
					int select;
					Department* depToShow=0;
					cout << "Please select a department: " << endl;
					hospital.showDepartments();
					bool isValidDep = false;
					while (!isValidDep)
					{
						cin >> select;
						try
						{
							depToShow = hospital.getDepartmentByIndex(select - 1);
							isValidDep = true;
						}
						catch (char const* msg)
						{
							cout << msg << endl;
						}
					}
					cout << "These are the patients of department " << depToShow->getName().c_str() << endl;
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
						cout << "Patient with ID " << patID << " is " << patientToShow->getName().c_str() << " and his/her current department is " << patientToShow->getCurrentDepartment()->getName().c_str() << "." << endl;
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
					string name;
					Interface::getResearcherInfo(&name);
					hospital.getResearchInstitute().addResearcher(name);
				}
				break;
				case 2: //add an article
				{
					if (hospital.getResearchInstitute().getNumOfResearchers() == 0)
					{
						cout << "There are no researchers in the research institute. Please add a researcher first" << endl;
						string name;
						Interface::getResearcherInfo(&name);
						hospital.getResearchInstitute().addResearcher(name);
						hospital.getResearchInstitute().showResearchers();
					}
					int r_index;
					Date date;
					string title;
					string name_of_magazine;
					Interface::getArticleInfo(&title, &name_of_magazine, &date, &r_index, hospital);
					hospital.getResearchInstitute().addArticle(date, title, name_of_magazine, r_index);

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
			if (hospital.getResearchInstitute().getNumOfResearchers() < 2)
			{
				cout << "There must be at least 2 researchers to compare\n";
			}
			else
			{
				Interface::compareResearchers(hospital.getResearchInstitute());
			}
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
		if (proceed == 0)
		{
			saveHospitalToFiles(hospital);
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
void Interface::getDepartmentInfo(string* name)
{
	cout << "Adding a new department, choose name: " << endl;
	*name = getInput();
}

void Interface::getDoctorInfo(string* name, string* specialty, Department** depart, Hospital& hospital,bool* isSurgeon,bool* isResearcher, int* num_of_surgeries)
{
	int depIndex;

	cout << "Adding a new doctor, choose name: " << endl;
	*name = getInput();
	cout << "Adding a new doctor, choose specialty: " << endl;
	*specialty = getInput();
	cout << "In which department is the doctor going to work? Insert the index" << endl;
	hospital.showDepartments();
	bool isValidDep = false;
	while (!isValidDep)
	{
		cin >> depIndex;
		try
		{
			*depart = hospital.getDepartmentByIndex(depIndex - 1);
			isValidDep = true;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}
	
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

void Interface::getNurseInfo(string* name, int* yearsExperience, Department** depart, Hospital& hospital)
{
	int depIndex;

	cout << "Adding a new nurse, choose name: " << endl;
	*name = getInput();
	cout << "Adding a new nurse, type years of experience: " << endl;
	cin >> *yearsExperience;
	cout << "In which department is the nurse going to work? Insert the index" << endl;
	hospital.showDepartments();

	bool isValidDep = false;
	while (!isValidDep)
	{
		cin >> depIndex;
		try
		{
			*depart = hospital.getDepartmentByIndex(depIndex - 1);
			isValidDep = true;
		}
		catch (char const* msg)
		{
			cout << msg << endl;
		}
	}
}

void Interface::getResearcherInfo(string* name)
{
	cout << "Please enter name:" << endl;
	*name = getInput();
}

void Interface::getArticleInfo(string* title, string* name_of_magazine, Date* p_date, int* r_index, Hospital& hospital)
{
	cout << "This is the list of researchers:" << endl;
	hospital.getResearchInstitute().showResearchers();
	string search_name;
	cout << "To whom you would like to add the article? please type name:" << endl;
	bool nameFound = false;

	while (!nameFound)
	{
		search_name = getInput();
		try
		{
			*r_index = hospital.getResearchInstitute().searchResearcherByName(search_name);
			nameFound = true;
		}
		catch (char const* msg)
		{
			cout << msg << endl;
		}

	}

	//researcher found
	cout << "Adding a new article for " << search_name.c_str() << ":" << endl;
	cout << "What is the article's date?" << endl;

	int day, month, year;
	bool res=false;

	do {
		cout << "please enter day:" << endl;
		cin >> day;
		try
		{
			p_date->setDay(day);
			res = true;
		}
		catch (char const* msg)
		{
			cout << msg << endl;
		}

	} while (res != true);
	res = false;
	do {
		cout << "please enter month:" << endl;
		cin >> month;
		try
		{
			p_date->setMonth(month);
			res = true;
		}
		catch (char const* msg)
		{
			cout << msg << endl;
		}
	} while (res != true);
	res = false;
	do {
		cout << "please enter year:" << endl;
		cin >> year;
		try
		{
			p_date->setYear(year);
			res = true;
		}
		catch (char const* msg)
		{
			cout << msg << endl;
		}

	} while (res != true);

	cout << "enter the title: " << endl;
	*title = getInput();
	cout << "enter the magazine's name: " << endl;
	*name_of_magazine = getInput();

}

void Interface::getVisitInfo(Patient** newPatient, Date* visitDate, string* visPurpose, Department** depToAdd, StaffMember** treatDoc, bool isNewPatient, bool* isFast, int* room, bool* isSurgery,Hospital& hospital)
{
	int patientID;
	string nameToAdd;
	int newYear = 0;
	int newGen = 0;
	int genIndex = 0;
	bool isValidID = false;

	while (!isValidID)
	{
		cout << "Adding a new visit, Please enter Patient ID (9 digits): " << endl;
		cin >> patientID;
		try
		{
			*newPatient = hospital.getPatientByID(patientID);
			isValidID = true;
		}
		catch (char const* msg)
		{
			cout << msg << endl;
		}
	}

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
	}

	cout << "What is the department the visit is to? insert the index of it " << endl;
	int patDep;
	hospital.showDepartments();
	bool isValidDep = false;
	while (!isValidDep)
	{
		cin >> patDep;
		try
		{
			*depToAdd = hospital.getDepartmentByIndex(patDep - 1);
			(*newPatient)->setCurrDepartment(*depToAdd);
			isValidDep = true;
		}
		catch (char const* msg)
		{
			cout << msg << endl;
		}
	}
	
	if ((*depToAdd)->getNumOfStaffMembers() == 0)
	{
		cout << "No staff in this department yet. Please add staff" << endl;
		int selection;
		printAddStaffMemberMenu();
		bool validSel = false;
		while (!validSel)
		{
			try
			{
				cin >> selection;
				isValid(selection, 1, 2);
				validSel = true;

			}
			catch (char const* msg)
			{
				cout << msg << endl;
			}
		}

		string name;
		bool isSurgeon;
		bool isResearcher;
		int num_of_surgeries;
		if (selection == 1)
		{
			string docSpecialty;
			Interface::getDoctorInfo(&name, &docSpecialty, depToAdd, hospital,&isSurgeon,&isResearcher,&num_of_surgeries);
			hospital.addDoctor(name, docSpecialty, *depToAdd,isSurgeon,isResearcher,num_of_surgeries);

		}
		else
		{
			int yearsExperience;
			Interface::getNurseInfo(&name, &yearsExperience, depToAdd, hospital);
			hospital.addNurse(name, yearsExperience, *depToAdd);
		}

	}
	cout << "Enter visit details. Visit date (day, month, year): " << endl;
	int day, month, year;
	bool res = false;

	do {
		cout << "please enter day:" << endl;
		cin >> day;
		try
		{
			visitDate->setDay(day);
			res = true;
		}
		catch (char const* msg)
		{
			cout << msg << endl;
		}

	} while (res != true);
	res = false;
	do {
		cout << "please enter month:" << endl;
		cin >> month;
		try
		{
			visitDate->setMonth(month);
			res = true;
		}
		catch (char const* msg)
		{
			cout << msg << endl;
		}
	} while (res != true);
	res = false;
	do {
		cout << "please enter year:" << endl;
		cin >> year;
		try
		{
			visitDate->setYear(year);
			res = true;
		}
		catch (char const* msg)
		{
			cout << msg << endl;
		}

	} while (res != true);

	int visPurp=0;
	cout << "What is the visit type? for surgery press 2, for tests press 1: " << endl;
	bool validSel = false;
	while (!validSel)
	{	
		cin >> visPurp;
		try
		{
			isValid(visPurp, 1, 2);
			validSel = true;

		}
		catch (char const* msg)
		{
			cout << msg << endl;
		}
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

	bool validID = false;
	while (!validID)
	{
		cin >> idToCheck;
		try
		{
			*treatDoc = hospital.getStaffMemberByID(idToCheck);
			validID = true;
		}
		catch (char const* msg)
		{
			cout << msg << endl;
		}
	}
	cout << "Staff member set as treating staff." << endl;

}

void Interface::compareResearchers(Research_Institute& RI) 
{


	string search_name;
	int index;

	cout << "Choose two researches to compare by their number of articles\n"
		<< "This is the list of available researchers:" << endl;
	RI.showResearchers();

	cout << "Choose the first researcher, type the name:" << endl;
	bool validSel = false;
	while (!validSel)
	{
		search_name = getInput();
		try
		{
			index = RI.searchResearcherByName(search_name);
			validSel = true;
		}
		catch (char const* msg)
		{
			cout << msg << endl;
		}
	}

	StaffMember* temp1 = RI.getResearcherByIndex(index);

	cout << "Choose the second researcher, type the name:" << endl;

	validSel = false;
	while (!validSel)
	{
		search_name = getInput();
		try
		{
			index = RI.searchResearcherByName(search_name);
			validSel = true;
		}
		catch (char const* msg)
		{
			cout << msg << endl;
		}
	}

	StaffMember* temp2 = RI.getResearcherByIndex(index);

	Researcher* researcher1 = dynamic_cast<Researcher*>(temp1);
	Researcher* researcher2 = dynamic_cast<Researcher*>(temp2);

	if (*researcher1 > *researcher2)
	{
		cout << researcher1->getName().c_str() << " has more articles than " << researcher2->getName().c_str() << endl;
	}
	else
	{
		cout << researcher2->getName().c_str() << " has more articles than " << researcher1->getName().c_str() << endl;
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

void Interface::isValid(int check, int lower, int upper) throw (const char*)
{
	if (((lower <= check) && (check <= upper)) == true)
		return;
	else
		throw "Invalid input, please try again";
}

void Interface::saveHospitalToFiles(Hospital& hospital)
{
	//saves all hospital data to file: hospitalSave.txt

	//open file for writing
	ofstream outFile("hospital_save.txt", ios::trunc);

	//save hospital's name
	outFile << hospital.getName().c_str() << endl;

	//save departments
	int num_of_dep = (int)hospital.departments.size();
	int cur_num_of_stf_mem;
	outFile << num_of_dep << " ";

	for (int i = 0; i < num_of_dep; i++)
	{
		outFile << hospital.departments[i]->getName().c_str() << " ";
		cur_num_of_stf_mem = hospital.departments[i]->getNumOfStaffMembers();
		outFile << cur_num_of_stf_mem << " ";
		hospital.departments[i]->printNamesOfStaffToFile(outFile);
	}
	outFile << endl;

	//save staff members
	outFile << StaffMember::getIDCounter() << endl;			//save counter for id's
	int num_of_staff_mem = (int)hospital.staff_members.size();
	outFile << num_of_staff_mem << " ";

	for (int i = 0; i < num_of_staff_mem; i++)
	{
		outFile << typeid(*(hospital.staff_members[i])).name() + 6 << " ";  //print type of object

		outFile << hospital.staff_members[i]->getId() << " "
			<< hospital.staff_members[i]->getName().c_str() << " "
			<< hospital.staff_members[i]->getDepartmentName().c_str() << " ";

		
		if (Doctor* doctemp = dynamic_cast<Doctor*>(hospital.staff_members[i]))
		{
			outFile << doctemp->getSpecialty().c_str() << " ";

			if (Surgeon* temp = (dynamic_cast<Surgeon*>(hospital.staff_members[i])))
			{
				outFile << temp->getNumOfSurgeries() << " ";
			}

			else if (Researcher* temp = (dynamic_cast<Researcher*>(hospital.staff_members[i])))
			{
				//no special data members
			}

			else if (SurgeonResearcher* temp = (dynamic_cast<SurgeonResearcher*>(hospital.staff_members[i])))
			{
				outFile << temp->getNumOfSurgeries() << " ";
			}
			else  // (dynamic_cast<DoctorResearcher*>(hospital.staff_members[i])
			{
				//no special data members
			}
		}
		else if (Nurse* nursetemp = (dynamic_cast<Nurse*>(hospital.staff_members[i])))
		{
			outFile << nursetemp->getYearsOfExperience() << " ";
		}
	}

	outFile.close();
}