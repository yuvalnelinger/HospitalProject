#include "hospital.h"

Hospital::Hospital(const char* name) : name(nullptr), size_of_departments(INIT_SIZE), size_of_doctors(INIT_SIZE), size_of_nurses(INIT_SIZE), size_of_patients(INIT_SIZE)
{
	cout << "In Hospital c'tor..." << endl;
	setName(name);
	departments = new Department*[size_of_departments];
	num_of_departments = 0;
	doctors = new Doctor*[size_of_doctors];
	num_of_doctors = 0;
	nurses = new Nurse*[size_of_nurses];
	num_of_nurses = 0;
	patients = new Patient*[size_of_patients];
	num_of_patients = 0;
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
char* Hospital::getName() const { return name; }

Department* Hospital::getDepartmentByIndex(int num) const { return departments[num]; }

Patient* Hospital::getPatientByID(int id) const
{
	for (int i = 0; i < num_of_patients; i++)
	{
		if (patients[i]->getId() == id)
		{
			return patients[i];
		}
	}
	return nullptr;
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

Nurse* Hospital::getNurseByID(int id) const
{
	for (int i = 0; i < num_of_nurses; i++)
	{
		if (nurses[i]->getId() == id)
		{
			return nurses[i];
		}
	}
	return 0;
}

int Hospital::getNumOfDepartments()
{
	return num_of_departments;
}

Research_Institute& Hospital::getResearchInstitute()
{
	return RI;
}

void Hospital::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}



//methods
void Hospital::addDepartment(char* name)
{
	if (num_of_departments == size_of_departments) //array increment if needed
	{
		size_of_departments *= 2;
		Department** temp = new Department*[size_of_departments];
		for (int i = 0; i < num_of_departments; i++) //copy from old array to new array
			temp[i] = departments[i];
		delete[] departments;
		departments = temp;
	}

	Department* dep = new Department(name);
	this->departments[num_of_departments++] = dep;  //add department to hospital
	cout << "Successfully added department to hospital" << endl;
	
}

void Hospital::addDoctor(char* name, char* docSpecialty, Department* assigned_dep)
{
	if (num_of_doctors == size_of_doctors) //array increment if needed
	{
		size_of_doctors *= 2;
		Doctor** temp = new Doctor*[size_of_doctors];
		for (int i = 0; i < num_of_doctors; i++) //copy from old array to new array
			temp[i] = doctors[i];
		delete[] doctors;
		doctors = temp;
	}

	Doctor* doc = new Doctor(name, docSpecialty,assigned_dep);
	this->doctors[num_of_doctors++] = doc;	//add doctor to hospital
	assigned_dep->addDoctor(doc);   //add doctor to deparement
	doc->setDepartment(assigned_dep);  //add department to the doctor
	cout << "Successfully added doctor to hospital" << endl;
}

void Hospital::addNurse(char* name, int yearsExperience, Department* assigned_dep)
{
	if (num_of_nurses == size_of_nurses) //array increment if needed
	{
		size_of_nurses *= 2;
		Nurse** temp = new Nurse*[size_of_nurses];
		for (int i = 0; i < num_of_nurses; i++) //copy from old array to new array
			temp[i] = nurses[i];
		delete[] nurses;
		nurses = temp;
	}

	Nurse* nurse = new Nurse(name, yearsExperience, assigned_dep);
	this->nurses[num_of_nurses++] = nurse;	//add nurse to hospital
	assigned_dep->addNurse(nurse);   //add nurse to deparement
	nurse->setDepartment(assigned_dep);  //add department to the nurse
	cout << "Successfully added nurse to hospital" << endl;
}

void Hospital::addPatient(Patient* patientToAdd)
{
	if (num_of_patients == size_of_patients) //array increment if needed
	{
		size_of_patients *= 2;
		Patient** temp = new Patient*[size_of_patients];
		for (int i = 0; i < num_of_patients; i++) //copy from old array to new array
			temp[i] = patients[i];
		delete[] patients;
		patients = temp;
	}

	patients[num_of_patients++] = patientToAdd;
	cout << "Successfully added patient to hospital" << endl;
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
			cout << "\t" << i+1 << "." << doctors[i]->getName() << ", ID " <<doctors[i]->getId() << endl;
	}

	if (num_of_nurses == 0)
		cout << "No nurses yet" << endl;

	else
	{
		cout << "List of nurses: \n";
		for (i = 0; i < num_of_nurses; i++)
			cout << "\t" << i+1 << "."<< nurses[i]->getName() << ", ID " << nurses[i]->getId() << endl;
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