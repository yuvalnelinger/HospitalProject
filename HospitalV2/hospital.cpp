#include "hospital.h"

Hospital::Hospital()
{
	cout << "In Hospital c'tor..." << endl;
	doctors = new Doctor*[50];
	num_of_doctors = 0;
	departments = new Department*[50];
	num_of_departments = 0;
	patients = new Patient*[50];
	num_of_patients = 0;
	nurses = new Nurse*[50];
	num_of_nurses = 0;
}
//I dont think we'll use  this
Hospital::Hospital(Doctor** docs, int numDocs, Department** deps, int numDeps, Patient** patientList, int numPatients)
{
	doctors = docs;
	num_of_doctors = numDocs;
	departments = deps;
	num_of_departments = numDeps;
	patients = patientList;
	num_of_patients = numPatients;
}
Hospital::~Hospital()
{
	cout << "In Hospital d'tor..." << endl;
	int i;

	for (i = 0; i < num_of_doctors; i++)
		delete doctors[i];
	delete[]doctors;

	for (i = 0; i < num_of_nurses; i++)
		delete nurses[i];
	delete[]nurses;

	for (i = 0; i < num_of_departments; i++)
		delete departments[i];
	delete[]departments;

	for (i = 0; i < num_of_patients; i++)
		delete patients[i];
	delete[]patients;
}

//getters and setters
Department* Hospital::getDepartmentByIndex(int num) const
{
	return departments[num];
}

Patient* Hospital::getPatientByID(int id) const
{
	for (int i = 0; i < num_of_patients; i++)
	{
		if (patients[i]->getId() == id)
		{
			return patients[i];
		}
	}
	return 0;
}

Doctor* Hospital::getDoctorByID(int id) const
{
	for (int i = 0; i < num_of_doctors; i++)
	{
		if (doctors[i]->getId() == id)
		{
			return doctors[i];
		}
	}
	return 0;
}

int Hospital::getNumOfDepartments()
{
	return num_of_departments;
}

//methods
void Hospital::addDepartment()
{
	char* name = new char[MAX_NAME];
	cout << "Adding a new department, choose name: " << endl;
	cin.ignore();
	cin.getline(name, MAX_NAME);
	Department* dep = new Department(name);
	this->departments[num_of_departments++] = dep;
	cout << "Successfully added department to hospital" << endl;
	delete[] name;
	//include here code for array increment
}

void Hospital::addDoctor(Doctor* docToAdd)
{
	doctors[num_of_doctors++] = docToAdd;
	cout << "Successfully added doctor to hospital" << endl;
	//include here code for array increment
}

void Hospital::addNurse(Nurse* nurseToAdd)
{
	nurses[num_of_nurses++] = nurseToAdd;
	cout << "Successfully added nurse to hospital" << endl;
	//include here code for array increment
}


void Hospital::addPatient(Patient* patientToAdd)
{
	patients[num_of_patients++] = patientToAdd;
	cout << "Successfully added patient to hospital" << endl;
	//include here code for array increment
}

void Hospital::showDepartments() const
{
	for (int i = 0; i < num_of_departments; i++)
	{
		cout << "\t" << i << ". " << departments[i]->getDepName() << endl;
	}
}

void Hospital::showPatientById(int id) const
{
	Department* dep;
	for (int i = 0; i < num_of_patients; i++)
	{
		if (patients[i]->getId() == id)
		{
			dep = patients[i]->getCurrentDepartment();
			cout << "Patient Name: " << patients[i]->getName() << " Patient Department: " << dep->getDepName() << endl;
		}
	}
}


void Hospital::showStaff() const
{
	int i;

	if (num_of_doctors == 0)
		cout << "No doctors yet" << endl;
	else
	{
		cout << "List of doctors: \n";
		for (i = 0; i < num_of_doctors; i++)
			cout << "\t" << i+1 << "." << doctors[i]->getName() << endl;
	}

	if (num_of_nurses == 0)
		cout << "No nurses yet" << endl;

	else
	{
		cout << "List of nurses: \n";
		for (i = 0; i < num_of_nurses; i++)
			cout << "\t" << i+1 << "."<< nurses[i]->getName() << endl;
	}
}

void Hospital::show() const
{
	int i;
	cout << "List of departments: \n";
	for (i = 0; i < num_of_departments; i++)
		cout << "\t" << i <<"." << departments[i]->getDepName() << endl;

	cout << "List of doctors: \n";
	for (i = 0; i < num_of_doctors; i++)
		cout << "\t" << i << "." << doctors[i]->getName() << endl;

	cout << "List of nurses: \n";
	for (i = 0; i < num_of_nurses; i++)
		cout << "\t" << i << "."<< nurses[i]->getName() << endl;

	cout << "List of patients: \n";
	for (i = 0; i < num_of_patients; i++)
		cout << i << "." << "\t" << patients[i]->getName() << endl;
}

void Hospital::createDoctor()
{
	char* docName = new char[MAX_NAME];
	char* docSpecialty = new char[MAX_NAME];
	int depIndex;
	Department* assigned_dep;

	cout << "Adding a new doctor, choose name: " << endl;
	cin.ignore();
	cin.getline(docName, MAX_NAME);
	cout << "Adding a new doctor, choose specialty: " << endl;
	cin.getline(docSpecialty, MAX_NAME);
	cout << "In which department is the doctor going to work? Insert the index" << endl;
	this->showDepartments();
	cin >> depIndex;
	/*if (depIndex > this->getNumOfDepartments())
	{
		cout << "Invalid input. Please enter a valid department ID" << endl;
		cin >> depIndex;
		if (depIndex > this->getNumOfDepartments())
		{
			cout << "Invalid input. Doctor creation failed" << endl;
			return;
		}
	}*/
	assigned_dep = this->getDepartmentByIndex(depIndex);
	Doctor* doc = new Doctor(docName, docSpecialty, assigned_dep);
	this->addDoctor(doc);	//add doctor to hospital
	assigned_dep->addDoctor(doc);   //add doctor to deparement
	doc->setDepartment(assigned_dep);  //add department to the doctor

	//for debug//this->getDepartmentByIndex(depIndex)->show();

}

void Hospital::createNurse()
{
	char* nurseName = new char[MAX_NAME];
	int nurseYears;
	int depIndex;
	Department* assigned_dep;

	cout << "Adding a new nurse, choose name: " << endl;
	cin.ignore();
	cin.getline(nurseName, MAX_NAME);
	cout << "Adding a new nurse, type years of experience: " << endl;
	cin >> nurseYears;
	cout << "In which department is the nurse going to work? Insert the index" << endl;
	this->showDepartments();
	cin >> depIndex;
	//if (depIndexNurse > this->getNumOfDepartments())
	//{
	//	cout << "Invalid input. Please enter a valid department ID" << endl;
	//	cin >> depIndexNurse;
	//	if (depIndexNurse > this->getNumOfDepartments())
	//	{
	//		cout << "Invalid input. Nurse creation failed" << endl;
	//		return;
	//	}
	//} 
	//once there's a function, if it's invalid again, send back to the main menu
	assigned_dep = this->getDepartmentByIndex(depIndex);
	Nurse* nurse = new Nurse(nurseName, nurseYears, assigned_dep);
	this->addNurse(nurse);  //add nurse to hospital
	assigned_dep->addNurse(nurse); //add nurse to department
	nurse->setDepartment(assigned_dep); //add department to nurse

	this->getDepartmentByIndex(depIndex)->show();
}

//menu methods

void Hospital::mainMenu()
{
	bool proceed = true;
	int selection;
	do {
		cout << "Welcome to Assuta hospital!" << endl;
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
		case 1: this->addDepartment();
			break;
		case 2: this->addStaffMemberMenu();
			break;
		case 3: this->patientsMenu();
			break;
		case 4: this->researchInstituteMenu();
			break;
		case 5: this->showStaff();
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

//Q2,Q3
void Hospital::addStaffMemberMenu()
{
	//prevent from the user to add a staff member without any departments in the hospital
	if (this->num_of_departments == 0)
	{
		cout << "It not possible to add a staff memeber without any departments!\n"
			<< "please add a department first" << endl;
		this->addDepartment();
		this->addStaffMemberMenu();
	}

	else
	{
		int selection;
		cout << "Would you like to add a doctor or a nurse? Choose the option from the menu:" << endl;
		cout << "1. Doctor\n"
			<< "2. Nurse" << endl;
		cin >> selection;
		switch (selection)
		{
		case 1: this->createDoctor();
			break;
		case 2: this->createNurse();
			break;
		default: cout << "Invalid selection. Please select again" << endl;
			this->addStaffMemberMenu();
		}
	}
}

//Q4,Q7,Q10
void Hospital::patientsMenu()
{


}

//Q5,Q6,Q9
void Hospital::researchInstituteMenu()
{
	cout << "Welcome to the research institute! What would you like to do?" << endl;
	cout << "1. Add a researcher\n"
		<< "2. Add an article to a researcher\n"
		<< "3. Show all researchers"
		<< endl;

	int selection;
	cin >> selection;
	switch (selection)
	{
	case 1:
	{
		cout << "Please enter name:" << endl;
		char* name = new char[MAX_NAME];
		cin.ignore();
		cin.getline(name, MAX_NAME);
		Researcher* researcher = new Researcher(name);
		this->RI.addResearcher(researcher);  //add researcher to the research institute

		this->RI.show();

		delete[] name;

		break;
	}
	case 2:
	{
		cout << "To whom you would like to add the article?" << endl;
		char* title = new char[MAX_TITLE];
		char* name_of_magazine = new char[MAX_NAME];
		char* search_name = new char[MAX_NAME];
		int r_index;
		
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
		r_index = this->RI.searchResearcherByName(search_name);

		while (r_index == NOT_FOUND)
		{
			cout << "There is no researcher with this name! try again:" << endl;
			cin.getline(search_name, MAX_NAME);

			//resize string to logic size - create func for this
			int len = strlen(search_name);
			char* new_search_name = new char[len + 1];
			for (int i = 0; i < len + 1; i++)
				new_search_name[i] = search_name[i];
			new_search_name[len] = '\0'; //lock string
			delete[]search_name;
			search_name = new_search_name;
			r_index = this->RI.searchResearcherByName(search_name);
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

		Article* article = new Article(date, title, name_of_magazine);
		article->show();

		this->RI.addArticle(article);
		this->RI.addArticle(article, r_index);
		cout << "Article successfully added" << endl;

		delete[] title;
		delete[] name_of_magazine;
		delete[] search_name;

		break;
	}
	case 3:
		this->RI.show();
		break;
	default: cout << "Invalid value. Please try again" << endl;
		this->researchInstituteMenu();
		break;
	}


}
