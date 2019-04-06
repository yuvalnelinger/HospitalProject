#include "hospital.h"
#include "main.h"
#include <string.h>

using namespace std;

int main()
{
	Hospital hospital("Assuta");
	
	bool proceed = true;
	int selection;
	do {
		cout << "Welcome to " << hospital.getName() << " hospital!" << endl;
		cout << "What would you like to do? please choose an option from the menu:" << endl;
		cout << "1. Add a department\n"
			<< "2. Add a staff member\n"
			<< "3. Patient operations\n"
			<< "4. Enter the research institute\n"
			<< "5. Show all staff members"
			<< endl;

		cin >> selection;
		switch (selection)
		{
		case 1: //add a department
		{
			char* name = new char[MAX_NAME];
			cout << "Adding a new department, choose name: " << endl;
			cin.ignore();
			cin.getline(name, MAX_NAME);
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
				cout << "Adding a new department, choose name: " << endl;
				cin.ignore();
				cin.getline(name, MAX_NAME);
				hospital.addDepartment(name);
				delete[] name;
			}

			int selection;
			int depIndex;
			Department* assigned_dep;
			char* name = new char[MAX_NAME];
			cout << "Would you like to add a doctor or a nurse? Choose the option from the menu:" << endl;
			cout << "1. Doctor\n"
				<< "2. Nurse" << endl;

			bool again = true;
			while (again)
			{
				again = false;
				cin >> selection;
				switch (selection)
				{
					case 1:
					{
						char* docSpecialty = new char[MAX_NAME];
						cout << "Adding a new doctor, choose name: " << endl;
						cin.ignore();
						cin.getline(name, MAX_NAME);
						cout << "Adding a new doctor, choose specialty: " << endl;
						cin.getline(docSpecialty, MAX_NAME);
						cout << "In which department is the doctor going to work? Insert the index" << endl;
						hospital.showDepartments();
						cin >> depIndex;

						//check validity of index
						/*if (depIndex > hospital.getNumOfDepartments())
						{
							cout << "Invalid input. Please enter a valid department ID" << endl;
							cin >> depIndex;
							if (depIndex > hospital.getNumOfDepartments())
							{
								cout << "Invalid input. Doctor creation failed" << endl;
								return;
							}
						}*/

						assigned_dep = hospital.getDepartmentByIndex(depIndex);
						hospital.addDoctor(name, docSpecialty, assigned_dep);
						delete[] name;
						delete[] docSpecialty;
					}
					break;
					case 2:
					{
						int yearsExperience;
						cout << "Adding a new nurse, choose name: " << endl;
						cin.ignore();
						cin.getline(name, MAX_NAME);
						cout << "Adding a new nurse, type years of experience: " << endl;
						cin >> yearsExperience;
						cout << "In which department is the nurse going to work? Insert the index" << endl;
						hospital.showDepartments();
						cin >> depIndex;

						//check validity of index
						//if (depIndex > hospital.getNumOfDepartments())
						//{
						//	cout << "Invalid input. Please enter a valid department ID" << endl;
						//	cin >> depIndex;
						//	if (depIndex > hospital.getNumOfDepartments())
						//	{
						//		cout << "Invalid input. Doctor creation failed" << endl;
						//		return;
						//	}
						//}

						assigned_dep = hospital.getDepartmentByIndex(depIndex);
						hospital.addNurse(name, yearsExperience, assigned_dep);
						delete[] name;
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
					//implement code here
			break;
		case 4:  //enter the research institute
		{
			cout << "Welcome to the research institute! What would you like to do?" << endl;
			cout << "1. Add a researcher\n"
				<< "2. Add an article to a researcher\n"
				<< "3. Show all researchers"
				<< endl;

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
					cout << "Please enter name:" << endl;
					char* name = new char[MAX_NAME];
					cin.ignore();
					cin.getline(name, MAX_NAME);
					hospital.getResearchInstitute().addResearcher(name);
					hospital.getResearchInstitute().showResearchers();
					delete[] name;
				}
				break;
				case 2: //add an article
				{
					char* title = new char[MAX_TITLE];
					char* name_of_magazine = new char[MAX_NAME];
					char* search_name = new char[MAX_NAME];
					int r_index;
					cout << "To whom you would like to add the article? please type name:" << endl;

					cin.ignore();
					cin.getline(search_name, MAX_NAME);

					//resize string to logic size - create func for this
					int len = strlen(search_name);
					char* new_search_name = new char[len + 1];
					for (int i = 0; i < len + 1; i++)
						new_search_name[i] = search_name[i];
					new_search_name[len] = '\0'; //lock string
					delete[]search_name;
					search_name = new_search_name;
					r_index = hospital.getResearchInstitute().searchResearcherByName(search_name);

					while (r_index == NOT_FOUND)
					{
						cout << "There is no researcher with this name! please try again:" << endl;
						cin.getline(search_name, MAX_NAME);

						//resize string to logic size - create func for this
						int len = strlen(search_name);
						char* new_search_name = new char[len + 1];
						for (int i = 0; i < len + 1; i++)
							new_search_name[i] = search_name[i];
						new_search_name[len] = '\0'; //lock string
						delete[]search_name;
						search_name = new_search_name;
						r_index = hospital.getResearchInstitute().searchResearcherByName(search_name);
					}

					//researcher found
					cout << "let's add a new article for " << search_name << ":" << endl;
					cout << "What is the article's date?" << endl;
					int day, month, year;
					Date date;
					bool res;

					do {
						cout << "please enter day:" << endl;
						cin >> day;
						res = date.setDay(day);

					} while (res != true);

					do {
						cout << "please enter month:" << endl;
						cin >> month;
						res = date.setMonth(month);

					} while (res != true);

					do {
						cout << "please enter year:" << endl;
						cin >> year;
						res = date.setYear(year);

					} while (res != true);

					cout << "enter the title: " << endl;
					cin.ignore();
					cin.getline(title, MAX_TITLE);
					cout << "enter the magazine's name: " << endl;
					cin.getline(name_of_magazine, MAX_NAME);

					hospital.getResearchInstitute().addArticle(date, title, name_of_magazine, r_index);

					delete[] title;
					delete[] name_of_magazine;
					delete[] search_name;

					break;
				}
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
			break;
		}
		case 5: //show all staff members
			hospital.showStaff();
			break;
		default: cout << "Invalid value. Please try again" << endl;
			break;
		}

		cout << "Would you like to perform another action?\n"
			<< "Press 1 for YES or 0 for NO" << endl;
		cin >> proceed;

	} while (proceed);

	cout << "Goodbye!" << endl;
}

	///*Q4*/
	//Patient* newPatient;
	//Date visitDate;
	//char* visPurpose = new char[MAX_NAME];
	//Doctor* treatDoc;
	//int patientID;
	//char* nameToAdd = new char[MAX_NAME];
	//bool isNewPatient;
	//cout << "Please enter Patient ID: " << endl;
	//cin >> patientID;
	//newPatient = hospital.getPatientByID(patientID);
	//int newYear;
	//int newGen;
	//int genIndex;
	//if (newPatient != 0)
	//{
	//	cout << "Patient found" << endl;
	//	isNewPatient = false;
	//}
	//else
	//{
	//	cout << "Patient not found, enter details: " << endl;
	//	cout << "Enter Name: " << endl;
	//	cin.ignore();
	//	cin.getline(nameToAdd, MAX_NAME);
	//	cout << "Enter Year Of Birth: " << endl;
	//	cin >> newYear;
	//	cout << "Enter Gender (0 for MALE, 1 for FEMALE): " << endl;
	//	cin >> genIndex;
	//	newGen = genIndex;
	//	cout << "Received details, creating Patient" << endl;
	//	newPatient = new Patient(nameToAdd, patientID, newYear, newGen);
	//	isNewPatient = true;
	//}
	//cout << "What is the department the visit is to? insert the index of it " << endl;
	//int patDep;
	//hospital.showDepartments();
	//cin >> patDep;  
	//if (patDep > hospital.getNumOfDepartments())
	//{
	//	cout << "Invalid input. Please enter a valid department ID" << endl;
	//	cin >> patDep;
	//} //once there's a function, if it's invalid again, send back to the main menu
	//Department* depToAdd = hospital.getDepartmentByIndex(patDep);
	//newPatient->setCurrDepartment(depToAdd);

	//cout << "Enter visit details. Visit date (day, month, year): " << endl;
	//int newday, newmonth, newyear;
	//cin >> newday >> newmonth >> newyear;
	//visitDate.setDay(newday);
	//visitDate.setMonth(newmonth);
	//visitDate.setYear(newyear);
	//cout << "Enter the visit purpose: " << endl;
	//cin.ignore();
	//cin.getline(visPurpose, MAX_NAME);

	//cout << "Enter the Doctor ID: " << endl;
	//int idToCheck;
	//cin >> idToCheck;
	//treatDoc = hospital.getDoctorByID(idToCheck);
	//if (treatDoc != 0)
	//{
	//	cout << "Doctor set." << endl;
	//}
	//else
	//{
	//	cout << "Doctor not found, please create a new doctor" << endl;
	//	//add here the function to add new doctor to hospital and assign to treatDoc
	//}
	//Visit newVisit(newPatient, &visitDate, visPurpose, treatDoc);

	//newPatient->addVisit(&newVisit);
	//if (isNewPatient = true)
	//{
	//	depToAdd->addPatient(newPatient);  
	//	hospital.addPatient(newPatient); 
	//}

	//cout << "Successfully added visit." << endl;
	//hospital.show();

	///*End Q4*/