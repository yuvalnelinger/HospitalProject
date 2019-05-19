/*#include "hospital.h"
#include "Interface.h"
#include <string.h>

using namespace std;

//main for cheking inheritence
int main()
{
	Hospital hospital("Aichilov");
	Department* depart1 =new Department("Pnimit A");

	////creating Doctor - V
	//StaffMember* staffmem1 = new Doctor("Avi", "dermatologist", depart1);
	//staffmem1->show();

	////creating Doctor-Surgeon - V
	//Doctor* staffmem10 = new Doctor("Moshe", "optometrist", depart1);

	//StaffMember* staffmem2 = new Surgeon(*staffmem10, 8);
	//staffmem2->show();

	////creating Doctor-Researcher
	//Doctor doc1("Shaul", "orolog", depart1);
	//Researcher research1("Yossi");
	//Article* art1 = new Article(Date(13,3,1990), "How to cure cancer", "Medicin journal");
	//Article* art2 = new Article(Date(25, 1, 2002), "Types of diabetes", "Medicin journal");
	//research1.addArticle(art1);
	//research1.addArticle(art2);
	//StaffMember* staffm3 = new DoctorResearcher(doc1, research1);
	//staffm3->show();

	//creating Surgoen-Researcher - V
	Surgeon surg1 = Surgeon(Doctor("Ronen", "alcoholist", depart1), 1);
	Researcher research2("Dani");
	Article* art3 = new Article(Date(18, 3, 1995), "The best beers in the world", "Medicin journal");
	Article* art4 = new Article(Date(15 ,2, 2008), "Operating under the influence", "Medicin journal");
	research2.addArticle(art3);
	research2.addArticle(art4);

	StaffMember* staffm4 = new SurgeonResearcher(surg1, research2);
	staffm4->show();
}*/