#include "hospital.h"

//c'tor and d'tor
Hospital::Hospital(const string name) 
{
	setName(name);
}

Hospital::~Hospital()
{
	int i;

	for (i = 0; i < departments.size(); i++)  
		delete departments[i];

	for (i = 0; i < staff_members.size(); i++)
	{
		StaffMember* temp1 = dynamic_cast<DoctorResearcher*>(staff_members[i]);
		StaffMember* temp2 = dynamic_cast<SurgeonResearcher*>(staff_members[i]);
		if (temp1 && temp2)
			delete staff_members[i];
	}

	for (i = 0; i < patients.size(); i++)
		delete patients[i];
}

//getters and setters
string Hospital::getName() const { return name; }

Department* Hospital::getDepartmentByIndex(int num) const throw (const char*)
{ 
	if (num < 0 || num > departments.size()-1)
	{
		throw "Invalid Index! Please try again";
	}
	return departments[num]; 
}

Patient* Hospital::getPatientByID(int id) const throw (const char*)
{
	int numOfDigits = (int)log10((double)id) + 1;
	if (numOfDigits != 9)
	{
		throw "Please enter an ID with 9 digits";
	}
		
	for (int i = 0; i < patients.size(); i++)
	{
		if (patients[i]->getId() == id)
		{
			return patients[i];
		}
	}
	return nullptr;
}

StaffMember* Hospital::getStaffMemberByID(int id) const throw (const char*)
{
	for (int i = 0; i < staff_members.size(); i++)
	{
		if (staff_members[i]->getId() == id)
		{
			return staff_members[i];
		}
	}
	throw "Staff Member not found, please try again";
}

int Hospital::getNumOfDepartments()
{
	return (int)departments.size();
}

Research_Institute& Hospital::getResearchInstitute()
{
	return RI;
}

void Hospital::setName(const string name)
{
	this->name = name;
}

//methods
void Hospital::addDepartment(const string name)
{
	Department* dep = new Department(name);
	departments.push_back(dep);
	cout << "Successfully added department to hospital" << endl;
}

void Hospital::addDoctor(const string name, const string docSpecialty, Department* assigned_dep,bool isSurgeon,bool isResearcher,int num_of_surgeries)
{
	Doctor* doc = new Doctor(name, docSpecialty, assigned_dep);

	if (isSurgeon && !isResearcher)
	{
		StaffMember* surgeon = new Surgeon(*doc, num_of_surgeries); //create a surgeon
		staff_members.push_back(surgeon); //add to hospital
		*assigned_dep += surgeon;	//add to deparement
	}
	else if (isSurgeon && isResearcher)
	{
		Surgeon* surge = new Surgeon(*doc, num_of_surgeries);
		StaffMember* surgeResearch = new SurgeonResearcher(*surge, Researcher(name));  //create a surgeon-researcher
		staff_members.push_back(surgeResearch); //add to hospital
		*assigned_dep += surgeResearch;	//add to deparement
		addToRI(surgeResearch); //add to Research Institute
		delete surge;
	}
	else if (!isSurgeon && isResearcher)
	{
		StaffMember* docResearcher = new DoctorResearcher(*doc, Researcher(name)); //create doctor research
		staff_members.push_back(docResearcher); //add to hospital
		*assigned_dep += docResearcher;	//add to deparement
		addToRI(docResearcher); //add to Research Institute
	}
	else // regular doctor
	{
		staff_members.push_back(doc); //add to hospital
		*assigned_dep += doc;	//add to deparement
	}
	cout << "Successfully added doctor to hospital" << endl;
}

void Hospital::addNurse(const string name, int yearsExperience, Department* assigned_dep)
{
	StaffMember* nurse = new Nurse(name, yearsExperience, assigned_dep);
	staff_members.push_back(nurse);	//add nurse to hospital
	*assigned_dep += nurse;	//add to deparement
	cout << "Successfully added nurse to hospital" << endl;
}

void Hospital::addPatient(Patient* patientToAdd)
{
	patients.push_back(patientToAdd);
	cout << "Successfully added patient to hospital" << endl;
}

void Hospital::addToRI(StaffMember* mem)
{
	this->getResearchInstitute().researchers.push_back(mem);
}

void Hospital::showDepartments() const
{
	for (int i = 1; i < departments.size()+1; i++)
	{
		cout << "\t" << i << ". " << departments[i-1]->getName() << endl;
	}
}

void Hospital::showPatientById(int id) const
{
	Department* dep;
	for (int i = 0; i < patients.size(); i++)
	{
		if (patients[i]->getId() == id)
		{
			dep = patients[i]->getCurrentDepartment();
			cout << "Patient Name: " << patients[i]->getName() << " Patient Department: " << dep->getName() << endl;
		}
	}
}

void Hospital::showDocResearchers() const
{
	int count = 0;

	for (int i = 0; i < staff_members.size(); i++)
	{
		StaffMember* temp = dynamic_cast<DoctorResearcher*>(staff_members[i]);
		if (temp)
		{
			cout << "\t" << "-  " << *temp;
			count++;
		}
	}

	if (count == 0)
	{
		cout << "There are no doctors-researchers in the hospital yet." << endl;
	}
}

void Hospital::showStaff() const
{
	int i;

	if (staff_members.size() == 0)
	{
		cout << "No staff members yet" << endl;
	}
	else
	{
		cout << "List of staff members: \n";
		for (i = 0; i < staff_members.size(); i++)
		{
			cout << "\t" << i + 1 << "." << *staff_members[i] << endl;
		}
	}
}

void Hospital::show() const
{
	int i;
	if (departments.size() == 0)
	{
		cout << "No departments yet" << endl;
	}
	else 
	{
		cout << "List of departments: \n";
		for (i = 0; i < departments.size(); i++)
			cout << "\t" << i << "." << departments[i]->getName() << endl;
	}
	if (staff_members.size() == 0)
	{
		cout << "No staff members yet" << endl;
	}
	else
	{
		cout << "List of staff members: \n";
		for (i = 0; i < staff_members.size(); i++)
			cout << "\t" << i << "." << staff_members[i]->getName() << endl;
	}
	if (patients.size() == 0)
	{
		cout << "No patients yet" << endl;
	}
	else
	{
		cout << "List of patients: \n";
		for (i = 0; i < patients.size(); i++)
			cout << i << "." << "\t" << patients[i]->getName() << endl;
	}
}