#include "hospital.h"
#include <string>

Hospital::Hospital(const char* name) : name(nullptr), size_of_departments(INIT_SIZE), size_of_stf_mem(INIT_SIZE), size_of_patients(INIT_SIZE)
{
	setName(name);
	departments = new Department*[size_of_departments];
	num_of_departments = 0;
	staff_members = new StaffMember*[size_of_stf_mem];
	num_of_stf_mem = 0;
	patients = new Patient*[size_of_patients];
	num_of_patients = 0;
}

Hospital::~Hospital()
{
	int i;

	delete[] name;

	for (i = 0; i < num_of_departments; i++)
		delete departments[i];
	delete[]departments;

	for (i = 0; i < num_of_stf_mem; i++)
		delete staff_members[i];
	delete[]staff_members;

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

StaffMember* Hospital::getStaffMemberByID(int id) const
{
	for (int i = 0; i < num_of_stf_mem; i++)
	{
		if (staff_members[i]->getId() == id)
		{
			return staff_members[i];
		}
	}
	return 0;
}
/* OLD
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
*/
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
void Hospital::addDepartment(const char* name)
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

void Hospital::addDoctor(const char* name, const char* docSpecialty, Department* assigned_dep,bool isSurgeon,bool isResearcher,int num_of_surgeries)
{
	if (num_of_stf_mem == size_of_stf_mem) //array increment if needed
	{
		size_of_stf_mem *= 2;
		StaffMember** temp = new StaffMember*[size_of_stf_mem];
		for (int i = 0; i < num_of_stf_mem; i++) //copy from old array to new array
			temp[i] = staff_members[i];
		delete[] staff_members;
		staff_members = temp;
	}

	Doctor* doc = new Doctor(name, docSpecialty, assigned_dep);

	if (isSurgeon && !isResearcher)
	{
		StaffMember* surgeon = new Surgeon(*doc, num_of_surgeries); //create a surgeon
		this->staff_members[num_of_stf_mem++] = surgeon;	//add to hospital
		//assigned_dep->addStaffMember(surgeon);//add to deparement
		*assigned_dep += *surgeon;	//add to deparement
		//surgeon->setDepartment(assigned_dep);  // ***department set already in StaffMember c'tor...***

	}
	else if (isSurgeon && isResearcher)
	{
		Surgeon* surge = new Surgeon(*doc, num_of_surgeries);
		StaffMember* surgeResearch = new SurgeonResearcher(*surge, Researcher(name));  //create a surgeon-researcher
		this->staff_members[num_of_stf_mem++] = surgeResearch;	//add to hospital
		//assigned_dep->addStaffMember(surgeResearch);   //add to deparement
		*assigned_dep += *surgeResearch;	//add to deparement
		addToRI(surgeResearch); //add to Research Institute
		//surgeresearch->setDepartment(assigned_dep);  // ***department set already in StaffMember c'tor...***
		delete surge;
	}
	else if (!isSurgeon && isResearcher)
	{
		StaffMember* docResearcher = new DoctorResearcher(*doc, Researcher(name)); //create doctor research
		this->staff_members[num_of_stf_mem++] = docResearcher;	//add to hospital
		//assigned_dep->addStaffMember(docResearcher);   //add to deparement
		*assigned_dep += *docResearcher;	//add to deparement
		addToRI(docResearcher); //add to Research Institute
		//docresearch->setDepartment(assigned_dep);  // ***department set already in StaffMember c'tor...***

	}
	else // regular doctor
	{
		this->staff_members[num_of_stf_mem++] = doc;	//add to hospital
		//assigned_dep->addStaffMember(doc);   //add to deparement
		*assigned_dep += *doc;	//add to deparement
		//doc->setDepartment(assigned_dep);  // ***department set already in StaffMember c'tor...***
	}

	cout << "Successfully added doctor to hospital" << endl;
}

void Hospital::addNurse(const char* name, int yearsExperience, Department* assigned_dep)
{
	if (num_of_stf_mem == size_of_stf_mem) //array increment if needed
	{
		size_of_stf_mem *= 2;
		StaffMember** temp = new StaffMember*[size_of_stf_mem];
		for (int i = 0; i < num_of_stf_mem; i++) //copy from old array to new array
			temp[i] = staff_members[i];
		delete[] staff_members;
		staff_members = temp;
	}

	StaffMember* nurse = new Nurse(name, yearsExperience, assigned_dep);
	this->staff_members[num_of_stf_mem++] = nurse;	//add nurse to hospital
	//assigned_dep->addStaffMember(nurse);
	*assigned_dep += *nurse;	//add to deparement
	//nurse->setDepartment(assigned_dep);  // ***department set already in StaffMember c'tor...***
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

void Hospital::addToRI(StaffMember* mem)
{
	StaffMember** arr = getResearchInstitute().researchers;
	arr[getResearchInstitute().num_of_researchers++] = mem;
}

void Hospital::showDepartments() const
{
	for (int i = 1; i < num_of_departments+1; i++)
	{
		cout << "\t" << i << ". " << departments[i-1]->getName() << endl;
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
			cout << "Patient Name: " << patients[i]->getName() << " Patient Department: " << dep->getName() << endl;
		}
	}
}

void Hospital::showDocResearchers() const
{
	for (int i = 0; i < num_of_stf_mem; i++)
	{
		StaffMember* temp = dynamic_cast<DoctorResearcher*>(staff_members[i]);
		if (temp)
		{
			cout << "\t" << i+1 <<"." << *temp;
		}
	}
}

void Hospital::showStaff() const
{
	int i;

	if (num_of_stf_mem == 0)
	{
		cout << "No staff members yet" << endl;
	}
	else
	{
		cout << "List of staff members: \n";
		for (i = 0; i < num_of_stf_mem; i++)
		{
			cout << "\t" << i + 1 << "." << *staff_members[i] << endl;
		}
	}
}

void Hospital::show() const
{
	int i;
	if (num_of_departments == 0)
	{
		cout << "No departments yet" << endl;
	}
	else 
	{
		cout << "List of departments: \n";
		for (i = 0; i < num_of_departments; i++)
			cout << "\t" << i << "." << departments[i]->getName() << endl;
	}
	if (num_of_stf_mem == 0)
	{
		cout << "No staff members yet" << endl;
	}
	else
	{
		cout << "List of staff members: \n";
		for (i = 0; i < num_of_stf_mem; i++)
			cout << "\t" << i << "." << staff_members[i]->getName() << endl;
	}
	if (num_of_patients == 0)
	{
		cout << "No patients yet" << endl;
	}
	else
	{
		cout << "List of patients: \n";
		for (i = 0; i < num_of_patients; i++)
			cout << i << "." << "\t" << patients[i]->getName() << endl;
	}



	
}