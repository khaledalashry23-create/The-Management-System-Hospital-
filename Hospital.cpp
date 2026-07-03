#include <iostream>
#include<string>
#include <vector>
#include <limits>
#include <fstream>
using namespace std;
//*********************************** The Class of Project ****************************
class Patient
{
public:
	int id;
	string name;
	int age;
	string phone;
	string disease;
};
class Doctor
{
public:
	string name;
	int id;
	int age;
	string phone;
	string specialization;
};
class Appointment
{
public:
	int PatientID;
	int DoctorID;
	string date;
	string time;
};
// ************* function List the Management **************
void List()
{
	cout << "<-------------------------------------------->" << endl;
	cout << "==========Hospital========" << endl;
	cout << "--------- Management Systems ------------" << endl;
	cout << "1.Patients " << endl;
	cout << "2.Doctor " << endl;
	cout << "3.Appointment " << endl;
	cout << "4.Exit" << endl;
	cout << "==============================================" << endl;
	cout << " ## Enter the number choose : ";
}
// ******************* Patients **********************************************
void ShowListPatient()
{
	cout << "<-------------------------------------------->" << endl;
	cout << "1.Add Patient " << endl;
	cout << "2.Show Patients " << endl;
	cout << "3.Search about Patients " << endl;
	cout << "4.Delete Patient " << endl;
	cout << "5.Back " << endl;
	cout << "<-------------------------------------------->" << endl;
	cout << "< Enter the Number choose : ";

}
void SavePatients(const vector<Patient>&Patients)
{
	ofstream patientFile("patient.txt");
	for (int i = 0; i < Patients.size(); i++)
	{
		patientFile << Patients[i].name << endl;
		patientFile << Patients[i].id << endl;
		patientFile << Patients[i].phone << endl;
		patientFile << Patients[i].age << endl;
		patientFile << Patients[i].disease << endl;
	}
	patientFile.close();
}
void AddPatient(vector<Patient>& Patients)
{
	Patient newPatient;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter the name : ";
	getline(cin, newPatient.name);
	cout << "Enter ID : ";
	cin >> newPatient.id;
	for (int i = 0; i < Patients.size(); i++)
	{
		if (newPatient.id == Patients[i].id)
		{
			cout << "<  ^^^  This the Id already exists.  ^^^  >" << endl;
			cout << "-------------------------------------------------" << endl;
			return;
		}

	}
	cout << "Enter the  Phone Number : ";
	cin >> newPatient.phone;
	cout << "Enter the Age : ";
	cin >> newPatient.age;
	cout << "Enter the Type disease : ";
	cin >> newPatient.disease;
	Patients.push_back(newPatient);
	SavePatients(Patients);
	cout << " **********  Patient added successfully! ***************\n";
	cout << "<-------------------------------------------->" << endl;
}
void ShowPatient(const vector<Patient>& Patients)
{
	if (Patients.empty())
	{
		cout << "No Any Patients in the system ! " << endl;
		return;
	}
	cout << "< --------- List The Patient ------> " << endl;
	for (int i = 0; i < Patients.size(); i++)
	{
		cout << "Patiente : " << i + 1 << endl;
		cout << "Name : " << Patients[i].name << endl;
		cout << "Id : " << Patients[i].id << endl;
		cout << "Age : " << Patients[i].age << endl;
		cout << "Nuber phone : " << Patients[i].phone << endl;
		cout << "The Disease : " << Patients[i].disease << endl;
		cout << "----------------------------------------------" << endl;
	}
}
void Search(const vector<Patient>& Patients)
{
	if (Patients.empty())
	{
		cout << "No Any Patients in the system ! " << endl;
		return;
	}
	cout << "< ---- Enter the ID Patient do you want Search aobut you : ";
	int IdSearch;
	cin >> IdSearch;
	for (int i = 0; i < Patients.size(); i++)
	{
		if (Patients[i].id == IdSearch)
		{
			cout << "Patiente : " << i + 1 << endl;
			cout << "Name : " << Patients[i].name << endl;
			cout << "Id : " << Patients[i].id << endl;
			cout << "Age : " << Patients[i].age << endl;
			cout << "Nuber phone : " << Patients[i].phone << endl;
			cout << "The Disease : " << Patients[i].disease << endl;
			cout << "----------------------------------------------" << endl;
			return;
		}
	}
	cout << " ( Patient not found ) " << endl;
}
void DeletePatient(vector<Patient>& Patients)
{
	if (Patients.empty())
	{
		cout << "No Any Patients in the system ! " << endl;
		return;
	}
	cout << " < --- Enter the Id Delete : ";
	int IdDeltet;
	cin >> IdDeltet;
	for (int i = 0; i < Patients.size(); i++)
	{
		if (Patients[i].id == IdDeltet)
		{
			Patients.erase(Patients.begin() + i);
			SavePatients(Patients);
			cout << "Delete the Patients successfully" << endl;
			return;
		}
	}
	cout << "The Id is not founde in the system " << endl;
}
void LoadPatients(vector<Patient>&Patients)
{
	ifstream patientFile;
	patientFile.open("patient.txt");
	Patient p;
	while (getline(patientFile, p.name))
	{
		patientFile >> p.id;
		patientFile >> p.phone;
		patientFile >> p.age;
		patientFile >> p.disease;

		patientFile.ignore(numeric_limits<streamsize>::max(), '\n');
		Patients.push_back(p);
	}
	patientFile.close();
}

// ******************** Doctor **************************************************
void ShowListPatientDoctor()
{
	cout << "1.Add Doctor " << endl;
	cout << "2.Show Doctor " << endl;
	cout << "3.Search about Doctor " << endl;
	cout << "4.Delete Doctor" << endl;
	cout << "5.Back " << endl;
	cout << "<-------------------------------------------->" << endl;
	cout << "< Enter the Number choose : ";

}
void SaveDoctors(const vector<Doctor>& Doctors)
{
	ofstream DoctorFile("doctor.txt");
	for (int i = 0; i < Doctors.size(); i++)
	{
		DoctorFile << Doctors[i].name << endl;
		DoctorFile << Doctors[i].id << endl;
		DoctorFile << Doctors[i].phone << endl;
		DoctorFile << Doctors[i].age << endl;
		DoctorFile << Doctors[i].specialization << endl;
	}	
	DoctorFile.close();

}
void AddDoctor(vector<Doctor>& Doctors)
{
	Doctor newDoctor;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter the name : ";
	getline(cin, newDoctor.name);
	cout << "Enter ID : ";
	cin >> newDoctor.id;
	for (int i = 0; i < Doctors.size(); i++)
	{
		if (newDoctor.id == Doctors[i].id)
		{
			cout << "<  ^^^  Doctor  Id already exists.  ^^^  >" << endl;
			cout << "-------------------------------------------------" << endl;
			return;
		}
	}
	cout << "Enter the Number Phone : ";
	cin >> newDoctor.phone;
	cout << "Enter the Age : ";
	cin >> newDoctor.age;
	cout << "Enter Specialization : ";
	cin >> newDoctor.specialization;
	Doctors.push_back(newDoctor);
	SaveDoctors(Doctors);
	cout << "Doctor added successfully!\n";
	cout << "<---------------------------------------------------->" << endl;
}
void ShowDoctor(const vector<Doctor>& Doctors)
{
	if (Doctors.empty())
	{
		cout << "No any Doctor in the system " << endl;
		cout << "<--------------------------------------->" << endl;
		return;
	}
	cout << " ^^^^^^^^^^^ The List Doctor in the System ^^^^^^^^^" << endl;
	for (int i = 0; i < Doctors.size(); i++)
	{
		cout << "Doctor : " << i + 1 << endl;
		cout << "Name : " << Doctors[i].name << endl;
		cout << "Id : " << Doctors[i].id << endl;
		cout << "Age : " << Doctors[i].age << endl;
		cout << "Nuber phone : " << Doctors[i].phone << endl;
		cout << "Specialization  : " << Doctors[i].specialization << endl;
		cout << "----------------------------------------------" << endl;
	}
}
void SearchDoctor(const vector<Doctor>& Doctors)
{
	if (Doctors.empty())
	{
		cout << "The List Doctor is empty." << endl;
		return;
	}
	cout << "Enter the Id do you want Search about this : ";
	int numberSearch;
	cin >> numberSearch;
	for (int i = 0; i < Doctors.size(); i++)
	{
		if (Doctors[i].id == numberSearch)
		{
			cout << "Doctor : " << i + 1 << endl;
			cout << "Name : " << Doctors[i].name << endl;
			cout << "Id : " << Doctors[i].id << endl;
			cout << "Age : " << Doctors[i].age << endl;
			cout << "Nuber phone : " << Doctors[i].phone << endl;
			cout << "Specialization : " << Doctors[i].specialization << endl;
			cout << "----------------------------------------------" << endl;
			return;
		}
	}
	cout << " -- Not founded the ID -- " << endl;
}
void doctorId(vector<Doctor>& Doctors)
{
	if (Doctors.empty())
	{
		cout << "The List Doctor is empty." << endl;
		return;
	}
	cout << "Enter the Id do you Delete : ";
	int doctorId;
	cin >> doctorId;
	for (int i = 0; i < Doctors.size(); i++)
	{
		if (Doctors[i].id == doctorId)
		{
			Doctors.erase(Doctors.begin() + i);
			SaveDoctors(Doctors);
			cout << "Delete the name Doctor successfully." << endl;
			cout << "------------------------------------" << endl;
			return;
		}
	}
	cout << "Not found the Doctor " << endl;
}
void LoadDoctors(vector<Doctor>& Doctors)
{
	ifstream FileDoctors;
	FileDoctors.open("doctor.txt");
	Doctor d;
	while (getline(FileDoctors, d.name))
	{
		FileDoctors >> d.id;
		FileDoctors >> d.phone;
		FileDoctors >> d.age;
		FileDoctors >> d.specialization;
		FileDoctors.ignore(numeric_limits<streamsize>::max(), '\n');
		Doctors.push_back(d);
	}
	FileDoctors.close();
}

// ********************* Appointment ***************************************************
void AppointmentList()
{
	cout << "1.Book Appointment " << endl;
	cout << "2.Show Appointment " << endl;
	cout << "3.cancle Appointment" << endl;
	cout << "4.Back " << endl;
	cout << "<-------------------------------->" << endl;
	cout << "Enter the Number choose : ";
}
void SaveAppointment(const vector<Appointment>& appointments)
{
	ofstream FileAppointment("appointment.txt");
	for (int i = 0; i < appointments.size(); i++)
	{
		FileAppointment << appointments[i].PatientID << endl;
		FileAppointment << appointments[i].DoctorID << endl;
		FileAppointment << appointments[i].date << endl;
		FileAppointment << appointments[i].time << endl;
	}
	FileAppointment.close();
}
void BookAppointment(const vector<Patient>& Patients, const vector<Doctor>& Doctors, vector<Appointment>& appointments)
{
	Appointment newAppointment;
	cout << " -- Enter the Id Patient -- : ";
	cin >> newAppointment.PatientID;

	cout << "-- Enter the Id Doctor -- : ";
	cin >> newAppointment.DoctorID;
	bool found = false;
	for (int i = 0; i < Patients.size(); i++)
	{
		if (newAppointment.PatientID == Patients[i].id)
		{
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "The Patient not founde ." << endl;
	}
	else
	{
		bool found1 = false;
		for (int i = 0; i < Doctors.size(); i++)
		{
			if (newAppointment.DoctorID == Doctors[i].id)
			{
				found1 = true;
				break;
			}
		}
		if (!found1)
		{

			cout << "The Doctor not founde ." << endl;
		}
		else
		{
			cout << "Enter the Appointment date  : ";
			cin >> newAppointment.date;
			cout << "Enter the Appointment Time : ";
			cin >> newAppointment.time;
			for (int i = 0; i < appointments.size(); i++)
			{
				if (newAppointment.DoctorID == appointments[i].DoctorID &&
					newAppointment.date == appointments[i].date &&
					newAppointment.time == appointments[i].time)
				{
					cout << "<--- The Doctor is Busy ---->" << endl;
					cout << "<---------------------------------------------->" << endl;
					return;
				}
			}
			for (int i = 0; i < appointments.size(); i++)
			{
				if (newAppointment.PatientID == appointments[i].PatientID &&
					newAppointment.date == appointments[i].date &&
					newAppointment.time == appointments[i].time)
				{
					cout << "The Patient already has an appointment at this time." << endl;
					return;
				}
			}
			appointments.push_back(newAppointment);
			SaveAppointment(appointments);
			cout << " <--^^ Appointment Booked Successfully ^^--> " << endl;
			cout << "< --------------- ##### ---------------->" << endl;
		}
	}
}
void ShowAppointment(const vector<Appointment>& appointments)
{
	if (appointments.empty())
	{
		cout << "The Appointments is empty." << endl;
		return;
	}

	for (int i = 0; i < appointments.size(); i++)
	{
		cout << "<--- The List Appointment ---->" << endl;
		cout << i + 1 << " ) \n";
		cout << "Patient  : " << appointments[i].PatientID << endl;
		cout << "Doctor  : " << appointments[i].DoctorID << endl;
		cout << "date : " << appointments[i].date << endl;
		cout << "Time : " << appointments[i].time << endl;
		cout << "<------------------------------------->" << endl;
	}
}
void CancelAppointment(vector<Appointment>& appointements)
{
	if (appointements.empty())
	{
		cout << "The Appointment is empty ." << endl;
		return;
	}
	int idPatient;
	int idDoctor;
	cout << "Enter the Id pateinet do you cancle : ";
	cin >> idPatient;
	cout << "Enter the Id Doctor do you cancle : ";
	cin >> idDoctor;
	for (int i = 0; i < appointements.size(); i++)
	{
		if (idPatient == appointements[i].PatientID && idDoctor == appointements[i].DoctorID)
		{
			appointements.erase(appointements.begin() + i);
			SaveAppointment(appointements);
			cout << "Cancel the Appointent Successfully . \n";
			cout << "^^^ -------------------- ^^^" << endl;
			return;
		}
	}
	cout << " $$$$ Not founde $$$$ " << endl;
	cout << "------------------------------------" << endl;
}
void LoadAppointment(vector<Appointment>& appointements)
{
	ifstream AppointmentFile;
	AppointmentFile.open("appointment.txt");
	Appointment A;
	while (AppointmentFile>> A.PatientID)
	{
		AppointmentFile >> A.DoctorID;
		AppointmentFile >> A.date;
		AppointmentFile >> A.time;

		appointements.push_back(A);
	}
	AppointmentFile.close();
}
// ******************************* Int Main ********************************************
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<Patient>myclinic;
	vector<Doctor>myDoctor;
	vector < Appointment>appointments;

	LoadPatients(myclinic);
	LoadDoctors(myDoctor);
	LoadAppointment(appointments);

	int choose;
	do {
		List();
		cin >> choose;
		switch (choose)
		{
		case 1:
			int choose1;
			do
			{
				ShowListPatient();
				cin >> choose1;
				switch (choose1)
				{
				case 1:
					AddPatient(myclinic);
					break;
				case 2:
					ShowPatient(myclinic);
					break;
				case 3:
					Search(myclinic);
					break;
				case 4:
					DeletePatient(myclinic);
					break;
				case 5:
					cout << " ********* -------------- *********" << endl;
					break;
				default:
					cout << " ********* Error in the choose ********* " << endl;
				}
			} while (choose1 != 5);
			break;
		case 2:
			int choose2;
			do
			{
				ShowListPatientDoctor();
				cin >> choose2;
				switch (choose2)
				{
				case 1:
					AddDoctor(myDoctor);
					break;
				case 2:
					ShowDoctor(myDoctor);
					break;
				case 3:
					SearchDoctor(myDoctor);
					break;
				case 4:
					doctorId(myDoctor);
					break;
				case 5:
					cout << "< ------------------------------>" << endl;
					break;
				default:
					cout << "< --- Error in the System ---- >" << endl;
				}
			} while (choose2 != 5);
			break;

		case 3:
			int choose3;
			do
			{
				AppointmentList();
				cin >> choose3;
				switch (choose3)
				{
				case 1:
					BookAppointment(myclinic, myDoctor, appointments);
					break;
				case 2:
					ShowAppointment(appointments);
					break;
				case 3:
					CancelAppointment(appointments);
					break;
				case 4:
					cout << "<---------------------------------------------->" << endl;
					break;
				default:
					cout << "**** Error in the system ****** \n";
				}
			} while (choose3 != 4);

			break;
		case 4:
			cout << "====== Thank you to use the System ========" << endl;

			cout << "<--------------------------------------------------------->" << endl;
		}


	} while (choose != 4);
}
// **************************************** The End Project ******************************
