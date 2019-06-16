#include "hospital.h"
#include <string>

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
	departments.clear();

	for (i = 0; i < staff_members.size(); i++)
	{
		StaffMember* temp1 = dynamic_cast<DoctorResearcher*>(staff_members[i]);
		StaffMember* temp2 = dynamic_cast<SurgeonResearcher*>(staff_members[i]);
		if (temp1 && temp2)
			delete staff_members[i];
	}
	staff_members.clear();

	for (i = 0; i < patients.size(); i++)
		delete patients[i];
	patients.clear();
}

//getters and setters
string Hospital::getName() const { return name; }

Department* Hospital::getDepartmentByIndex(int num) const throw (const string)
{ 
	if (num < 0 || num > departments.size()-1)
	{
		throw "Invalid Index! Please try again";
	}
	return departments[num]; 
}

Patient* Hospital::getPatientByID(int id) const throw (const string)
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

StaffMember* Hospital::getStaffMemberByID(int id) const throw (const string)
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
	return departments.size();
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
	//this->departments[num_of_departments++] = dep;  //add department to hospital
	cout << "Successfully added department to hospital" << endl;
}

void Hospital::addDoctor(const string name, const string docSpecialty, Department* assigned_dep,bool isSurgeon,bool isResearcher,int num_of_surgeries)
{
	//if (num_of_stf_mem == size_of_stf_mem) //array increment if needed
	//{
	//	size_of_stf_mem *= 2;
	//	StaffMember** temp = new StaffMember*[size_of_stf_mem];
	//	for (int i = 0; i < num_of_stf_mem; i++) //copy from old array to new array
	//		temp[i] = staff_members[i];
	//	delete[] staff_members;
	//	staff_members = temp;
	//}

	Doctor* doc = new Doctor(name, docSpecialty, assigned_dep);

	if (isSurgeon && !isResearcher)
	{
		StaffMember* surgeon = new Surgeon(*doc, num_of_surgeries); //create a surgeon
		staff_members.push_back(surgeon); //add to hospital
		//this->staff_members[num_of_stf_mem++] = surgeon;	
		*assigned_dep += surgeon;	//add to deparement
	}
	else if (isSurgeon && isResearcher)
	{
		Surgeon* surge = new Surgeon(*doc, num_of_surgeries);
		StaffMember* surgeResearch = new SurgeonResearcher(*surge, Researcher(name));  //create a surgeon-researcher
		staff_members.push_back(surgeResearch); //add to hospital
		//this->staff_members[num_of_stf_mem++] = surgeResearch;
		*assigned_dep += surgeResearch;	//add to deparement
		addToRI(surgeResearch); //add to Research Institute
		delete surge;
	}
	else if (!isSurgeon && isResearcher)
	{
		StaffMember* docResearcher = new DoctorResearcher(*doc, Researcher(name)); //create doctor research
		staff_members.push_back(docResearcher); //add to hospital
		//this->staff_members[num_of_stf_mem++] = docResearcher;	//add to hospital
		*assigned_dep += docResearcher;	//add to deparement
		addToRI(docResearcher); //add to Research Institute
	}
	else // regular doctor
	{
		staff_members.push_back(doc); //add to hospital
		//this->staff_members[num_of_stf_mem++] = doc;	//add to hospital
		*assigned_dep += doc;	//add to deparement
	}
	cout << "Successfully added doctor to hospital" << endl;
}

void Hospital::addNurse(const string name, int yearsExperience, Department* assigned_dep)
{
	//if (num_of_stf_mem == size_of_stf_mem) //array increment if needed
	//{
	//	size_of_stf_mem *= 2;
	//	StaffMember** temp = new StaffMember*[size_of_stf_mem];
	//	for (int i = 0; i < num_of_stf_mem; i++) //copy from old array to new array
	//		temp[i] = staff_members[i];
	//	delete[] staff_members;
	//	staff_members = temp;
	//}

	StaffMember* nurse = new Nurse(name, yearsExperience, assigned_dep);
	staff_members.push_back(nurse);	//add nurse to hospital
	//this->staff_members[num_of_stf_mem++] = nurse;	//add nurse to hospital
	*assigned_dep += nurse;	//add to deparement
	cout << "Successfully added nurse to hospital" << endl;
}

void Hospital::addPatient(Patient* patientToAdd)
{
	//if (num_of_patients == size_of_patients) //array increment if needed
	//{
	//	size_of_patients *= 2;
	//	Patient** temp = new Patient*[size_of_patients];
	//	for (int i = 0; i < num_of_patients; i++) //copy from old array to new array
	//		temp[i] = patients[i];
	//	delete[] patients;
	//	patients = temp;
	//}

	patients.push_back(patientToAdd);
	//patients[num_of_patients++] = patientToAdd;
	cout << "Successfully added patient to hospital" << endl;
}

void Hospital::addToRI(StaffMember* mem)
{
	this->getResearchInstitute().researchers.push_back(mem);
	//StaffMember** arr = getResearchInstitute().researchers;
	//arr[getResearchInstitute().num_of_researchers++] = mem;
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