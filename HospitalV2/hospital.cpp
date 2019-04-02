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
void Hospital::addDepartment(Department* depToAdd)
{
	departments[num_of_departments++] = depToAdd;
	cout << "Successfully added department to hospital" << endl;
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
	cout << "List of doctors: \n";
	for (i = 0; i < num_of_doctors; i++)
		cout << "\t" << doctors[i]->getName() << endl;

	cout << "List of nurses: \n";
	for (i = 0; i < num_of_nurses; i++)
		cout << "\t" << nurses[i]->getName() << endl;
}

void Hospital::show() const
{
	int i;
	cout << "List of departments: \n";
	for (i = 0; i < num_of_departments; i++)
		cout << "\t" << departments[i]->getDepName() << endl;

	cout << "List of doctors: \n";
	for (i = 0; i < num_of_doctors; i++)
		cout << "\t" << doctors[i]->getName() << endl;

	cout << "List of nurses: \n";
	for (i = 0; i < num_of_nurses; i++)
		cout << "\t" << nurses[i]->getName() << endl;

	cout << "List of patients: \n";
	for (i = 0; i < num_of_patients; i++)
		cout << "\t" << patients[i]->getName() << endl;
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
	Doctor doc(docName, docSpecialty);
	this->addDoctor(&doc);
	cout << "This is the list of departments in the hospital: " << endl;
	this->showDepartments();
	cout << "Insert the index of the department to add the doctor to " << endl;
	cin >> depIndex;
	if (depIndex > this->getNumOfDepartments())
	{
		cout << "Invalid input. Please enter a valid department ID" << endl;
		cin >> depIndex;
		if (depIndex > this->getNumOfDepartments())
		{
			cout << "Invalid input. Doctor creation failed" << endl;
			return;
		}
	} 
	assigned_dep = this->getDepartmentByIndex(depIndex);
	assigned_dep->addDoctor(&doc);
	doc.setDepartment(assigned_dep);
	this->getDepartmentByIndex(depIndex)->show();
}

//menu methods

void Hospital::mainMenu()
{
	int selection;
	cout << "Welcome to Assuta hospital!" << endl;
	cout << "What would you like to do? plesae choose an option from menu:" << endl;
	cout << "1. Add a department\n"
		<< "2. Add a staff member\n"
		<< "3. To do some operations on patients\n"
		<< "4. Enter the research institute\n"
		<< "5. Show all staff members"
		<< endl;
	cin >> selection;
	switch (selection)
	{
	case 1: cout << "nothing yet" << endl;
	case 2: this->addStaffMemberMenu();
		break;
	case 3: cout << "nothing yet" << endl;
	case 4: cout << "nothing yet" << endl;
	case 5: cout << "nothing yet" << endl;
	default: cout << "Invalid value. Please try again" << endl;
		mainMenu();
	}

}

//Q2,Q3
void Hospital::addStaffMemberMenu()
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
	case 2: //add for nurse
		break;
	default: cout << "Invalid selection. Please select again" << endl;
	this->addStaffMemberMenu();
	}
}

//Q4,Q7,Q10
void patientsMenu()
{


}

//Q5,Q6,Q9
void researchInstituteMenu()
{


}