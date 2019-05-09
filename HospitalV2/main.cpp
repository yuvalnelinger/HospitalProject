#include "hospital.h"
#include "Interface.h"
#include <string.h>

using namespace std;

int main()
{
	Hospital hospital("Assuta");

	bool proceed = true;
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
					Interface::getDoctorInfo(&name, &docSpecialty, &assigned_dep, hospital);
					hospital.addDoctor(name, docSpecialty, assigned_dep);
					delete[] name;
					delete[] docSpecialty;
				}
				break;
				case 2: //add nurse
				{
					int yearsExperience;
					Interface::getNurseInfo(&name, &yearsExperience, &assigned_dep, hospital);
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
					bool isNewPatient = 0;
					Patient* newPatient = nullptr;
					Date visitDate;
					char* visPurpose = new char[MAX_NAME];
					Department* depToAdd;
					Doctor* treatDoc = nullptr;
					Nurse* treatNurse = nullptr;

					Interface::getVisitInfo(&newPatient, &visitDate, &visPurpose, &depToAdd, &treatDoc, &treatNurse, isNewPatient, hospital);
					newPatient->addVisit(newPatient, visitDate, visPurpose, treatDoc, treatNurse);  //add new visit to patient
					depToAdd->addPatient(newPatient); //add patient to current department (of visit)

					if (isNewPatient = true) //add patient to hospital only if he is new patient
						hospital.addPatient(newPatient);

					delete[]visPurpose;
					cout << "Successfully added visit." << endl;
				}
				break;
				case 2:
				{
					invalid = false;
					int select;
					Department* depToShow;
					cout << "Please select a department: " << endl;
					hospital.showDepartments();
					cin >> select;
					while (!Interface::isValid(select-1, 0, hospital.getNumOfDepartments()-1))
					{
						cout << "Invalid input. Please enter a valid department ID" << endl;
						cin >> select;
					}

					depToShow = hospital.getDepartmentByIndex(select-1);
					cout << "These are the patients of department " << depToShow->getDepName() << endl;
					depToShow->showPatients();
					break;
				}

				case 3:
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
						cout << "Patient with ID " << patID << "is " << patientToShow->getName() << "and his current department is " << patientToShow->getCurrentDepartment()->getDepName() << endl;
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
					hospital.getResearchInstitute().showResearchers();
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
		default:
		{
			cout << "Invalid value. Please try again" << endl;
		}
		break;

		}

		cout << "Would you like to perform another action?\n"
			<< "Press any key for YES or 0 for NO" << endl;
		cin >> proceed;

	} while (proceed);

	cout << "Get well soon, Goodbye!" << endl;
}