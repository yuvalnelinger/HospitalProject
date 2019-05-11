#include "hospital.h"

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

//int size_of_stf_mem;
//int num_of_stf_mem;

void Hospital::addDoctor(char* name, char* docSpecialty, Department* assigned_dep, bool isSurgeon,bool isResearcher)
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
	if (isSurgeon==1 && isResearcher==0)
	{

		StaffMember* doc = new Surgeon(name, docSpecialty, assigned_dep); //create a surgeon
		this->staff_members[num_of_stf_mem++] = doc;	//add doctor to hospital
		assigned_dep->addStaffMember(doc);   //add doctor to deparement
		doc->setDepartment(assigned_dep);  //add department to the 
		cout << "Successfully added surgoen to hospital" << endl;

	}
	else if (isSurgeon && isResearcher)
	{
		StaffMember* doc = new SurgeonResearcher(Surgeon(name, docSpecialty, assigned_dep), Researcher(name)); //create suegron research
		this->staff_members[num_of_stf_mem++] = doc;	//add doctor to hospital
		assigned_dep->addStaffMember(doc);   //add doctor to deparement
		doc->setDepartment(assigned_dep);  //add department to the doctor
		cout << "Successfully added surgeon researcher to hospital" << endl;

	}
	else if (!isSurgeon && isResearcher)
	{
		StaffMember* doc = new DoctorResearcher(Doctor(name, docSpecialty, assigned_dep), Researcher(name)); //create doctor research
		this->staff_members[num_of_stf_mem++] = doc;	//add doctor to hospital
		assigned_dep->addStaffMember(doc);   //add doctor to deparement
		doc->setDepartment(assigned_dep);  //add department to the doctor
		cout << "Successfully added doctor researcher to hospital" << endl;
	}
	else 
	{
		StaffMember* doc = new Doctor(name, docSpecialty, assigned_dep);
		this->staff_members[num_of_stf_mem++] = doc;	//add doctor to hospital
		assigned_dep->addStaffMember(doc);   //add doctor to deparement
		doc->setDepartment(assigned_dep);  //add department to the doctor
		cout << "Successfully added doctor to hospital" << endl;

	}

}

void Hospital::addNurse(char* name, int yearsExperience, Department* assigned_dep)
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

void Hospital::showStaff() const
{
	int i;

	if (num_of_stf_mem == 0)
		cout << "No staff members yet" << endl;
	else
	{
		cout << "List of staff members: \n";
		for (i = 0; i < num_of_stf_mem; i++)
		{
			//Researcher* temp = dynamic_cast<Researcher*>(staff_members[i]); //do not print researchers

			//if (temp)
				cout << "\t" << i + 1 << "." << staff_members[i]->show() << endl;
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
	if (num_of_doctors == 0)
	{
		cout << "No doctors yet" << endl;
	}
	else
	{
		cout << "List of doctors: \n";
		for (i = 0; i < num_of_doctors; i++)
			cout << "\t" << i << "." << doctors[i]->getName() << endl;
	}
	if (num_of_nurses == 0)
	{
		cout << "No nurses yet" << endl;
	}
	else
	{
		cout << "List of nurses: \n";
		for (i = 0; i < num_of_nurses; i++)
			cout << "\t" << i << "." << nurses[i]->getName() << endl;
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