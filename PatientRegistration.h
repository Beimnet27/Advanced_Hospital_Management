/****************************************************************
*****************************************************************
**															   **
**															   **
**			This Part Of The Project Is used To				   **
**					Register And Display New Patients!		   **
**															   **
**															   **
**															   **
*****************************************************************
****************************************************************/
#ifndef PATIENTREGISTRATION_H_INCLUDED
#define PATIENTREGISTRATION_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;
//Fucntion Prototypes
void OperationDisplay();
void RemoveOperation();
int PatientRegistration(int i);
void  Doclist(int dep);
void contents();
void TopDesign();
void BottomDesign();
void AllDatabase();
void StartOperation(string Dn, string Pn, int Di, int Pi, bool bd);
int frontEnd();
// Sample Doctors Available on the Hospital

class Doctors{
	public:	
string Docname[10]={"Widad KidhaneMariam","Werkneh Eshete","Hadas Maleda","Aklilu Lema",
    "Aster Tsegaye","Kaleab Wasyehun","Robel Beyene","Henok Beyene","Mamitu Gashe","Mekdes Birhanu"};
    int Specialized[10]={1,3,2,4,2,5,1,3,5,4};//used to set the doctors specialitiy
    int DocId[10]={3212,5490,3870,1934,2301,3343,7632,7934,1065,8843};//ID number for doctors
};
// class used to Store Patients
class Patient{
	public:
	string Fname;
	string Mname;
	string Lname;
	int age;
	float weight;
	float height;
	bool bed;
	float systolic_blood_pressure;//Top blood pressure of the patient
	float diastolic_blood_pressure;
	int id;	//variable for Patients Id used to assign id number to patient automatically
	char gender[2];
	short department;//to identify the illnes of the patient
	char blood[4];
	int phone;
	string adress;
	Patient *Next;
};
// pointer class objcets used to build linked list and Queue
Patient *Front=NULL , *Rear=NULL, *temp, *current , *track;
//Class used to Store operation
class Operation{
	public:
	string Pname;
	string Dname;
	int Pid;
	int Did;
	bool bed;
	Operation *Next;
};
Operation *Frt=NULL , *Rr = NULL, *tempo, *current1, *Second;
//function used to check if the queue is empty or not
bool isEmpty()
    {
    	if(Front==NULL && Rear==NULL)
    		return true;
		else
			return false;
	 }

//global variables and functions
int count=0;
int getway , depstart;
int n;// variable used to count how many patients to register
char forBed;//variable used to know whether th patient needs a bed or not
void Doclist(int dep);
void PNumber(int dep){
cout<<"Enter How Many Patients You Want To Register\n";
cin>>n;
getway = dep;
int s=0;
//function calling
PatientRegistration(s);
}
// function used to register the patient and also to enqueue
int PatientRegistration(int i){
	system("cls");
	for(i;i<n;i++){
		temp = new Patient;
		cout<<"Patient "<<i+1<<endl;
		temp->id = 300+i;
		cout<<"First Name:	";cin>>temp->Fname;
		cout<<"Middle Name:	";cin>>temp->Mname;
		cout<<"Last Name:	";cin>>temp->Lname;
		cout<<"Age		:	";cin>>temp->age;
		cout<<"Weight	:	";cin>>temp->weight;
		cout<<"Height	:	";cin>>temp->height;
		cout<<"systolic blood pressure(Top)	:	";cin>>temp->systolic_blood_pressure;
		cout<<"diastolic blood pressure(Buttom)	:	";cin>>temp->diastolic_blood_pressure;
		cout<<"Gender(m/f):	";cin>>temp->gender;
		temp->department = getway;
		again:
	cout<<"Blood Type		:  ";cin>>temp->blood;
	if((strcmp(temp->blood,"A+")==0)||(strcmp(temp->blood,"a+")==0)||(strcmp(temp->blood,"A-")==0)||(strcmp(temp->blood,"a-")==0)||
      (strcmp(temp->blood,"B+")==0)||(strcmp(temp->blood,"b+")==0)||(strcmp(temp->blood,"B-")==0)||(strcmp(temp->blood,"b-")==0)||
      (strcmp(temp->blood,"O+")==0)||(strcmp(temp->blood,"o+")==0)||(strcmp(temp->blood,"O-")==0)||(strcmp(temp->blood,"o-")==0)||
      (strcmp(temp->blood,"AB+")==0)||(strcmp(temp->blood,"ab+")==0)||(strcmp(temp->blood,"AB-")==0)||(strcmp(temp->blood,"ab-")==0));

    else
    {
        cout<<"\n   Invalid Blood Group Try Again..\n\n";
        goto again;
        }
		cout<<"Phone Number:	";cin>>temp->phone;
		cout<<"Address:	";cin>>temp->adress;
		cout<<"Reserve A bed Type y for yes N for No\n";
		cin>>forBed;
		if(forBed=='y')
		temp->bed=true;
		else
		temp->bed=false;
		if(isEmpty()){
          Front=Rear=temp;
          temp->Next=NULL;
       }
       
       else{
         Rear->Next=temp;
         temp->Next=NULL;
         Rear=temp;
       }	

}
	return 0;
}
//function used to Display the patient
int DisplayPatient(int filter){
	system("cls");
	cout<<"*********************************************\n";
	cout<<"*********************************************\n";
	cout<<"\tHERE ARE PATIENT LISTS\n";
	cout<<"*********************************************\n";
	cout<<"*********************************************\n";
	if(count==0)
	cout<<"There is No Registered Patient\n";
track = Front;

while(track!=NULL){
	if(track->department==filter){
	cout<<"----------------------------------------\n\n";
	cout<<"ID Number	:	"<<track->id<<endl;
	cout<<"First Name	:	"<<track->Fname<<endl;
	cout<<"Middle Name	:	"<<track->Mname<<endl;
	cout<<"Last Name	:	"<<track->Lname<<endl;
	cout<<"Age		:	"<<track->age<<endl;
	cout<<"Weight	:	"<<temp->weight<<endl;
	cout<<"Height	:	"<<temp->height<<endl;
	cout<<"systolic blood pressure(Top)	:	"<<temp->systolic_blood_pressure<<endl;
	cout<<"diastolic blood pressure(Buttom)	:	"<<temp->diastolic_blood_pressure<<endl;
	cout<<"gender		:	"<<track->gender<<endl;
	cout<<"Blood Type	:	"<<track->blood<<endl;
	cout<<"Phone Number	:	"<<track->phone<<endl;
	cout<<"Address		:	"<<track->adress<<endl;
	cout<<"\n----------------------------------------\n\n";
	track = track->Next;
}else
	track = track->Next;
	}
	return 0;
}

//function used to Dequeue Patients

void DeleteP(){
	if(isEmpty())
	cout<<"There is No registered Patient to delete\n";
	else{
		current = Front;
		Front = Front->Next;
		delete current;
		cout<<"You Have Successfully Removed the Patient\n";
	}
}
#endif // PATIENTREGISTRATION_H_INCLUDED