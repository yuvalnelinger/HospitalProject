#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#define _CRT_SECURE_NO_WARNINGS
#define INIT_SIZE 50
#include "doctor.h"
#include "Nurse.h"
#include "patient.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Department
{
private:
	char* name;
	vector<StaffMember*> staff_members;
	//int size_of_stf_mem;
	//int num_of_stf_mem;
	vector<Patient*> patients;
	//int size_of_patients;
	//int num_of_patients;

public:
	//c'tor and d'tor
	Department(const char* name);
	~Department();

	//getters and setters
	int getNumOfStaffMembers() const;
	char* getName() const;
	void setName(const char* name);

	//operators
	const Department& operator+=(const StaffMember* mem);

	//methods
	void addStaffMember(const StaffMember* mem);
	void addPatient(const Patient* patient);
	void showPatients() const;
	void showStaff() const;
	//files methods
	/*
	friend ostream& operator<<(ostream& out, const Department& d)
	{
		//save to file:
		//name of department, names of assigned staff members
		//and names of assigned patients

		out << d.getName() << " ";

		int sm_size = d.staff_members.size();
		out << sm_size << " ";		//save number of staff members

		vector<StaffMember*>::iterator itr = v.begin();
		vector<StaffMember*>::iterator itrEnd = v.end();

		while (itr != itrEnd)
		{
			outFile << *itr;
			++itr;
		}
		
		for (int i = 0; i < sm_size; i++)
		{
			out << d.staff_members[i]->getName() << ",";
		}

		int p_size = d.patients.size();
		out << p_size << " ";		//save number of patients
		for (int i = 0; i < p_size; i++)
		{
			out << d.patients[i]->getName() << ",";
		}
	}
	*/
private:
	//copy c'tor
	Department(const Department&); //prevent from user to make a copy of department
};

#endif
