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
#include<iostream>
#include<string>
#include<iomanip>
#include"PatientRegistration.h"
using namespace std;

int main(){
	Front=NULL;
	int no,elem;
	frontEnd();
	return 0;
}
//function that will display first 
int frontEnd(){
	system("cls");
TopDesign();
cout<<"\t*************************************\n";
cout<<"\t**      GLORIOUS HOSPITAL          **\n";
cout<<"\t*************************************\n";
cout<<"\t       WELCOME ENTER YOUR CHOICE\n";
cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t||\t\t\t\t   ||\n";
cout<<"\t||     1-> GENERAL CLINIC          ||\n";
cout<<"\t||     2-> HEART CLINIC            ||\n";
cout<<"\t||     3-> TEETH CLINIC            ||\n";
cout<<"\t||     4-> BONE CLINIC             ||\n";
cout<<"\t||     5-> KIDNEY CLINIC           ||\n";
cout<<"\t||     6-> GO BACK OR EXIT         ||\n";
cout<<"\t||_________________________________||\n";
again:
cin>>getway;
switch(getway)
{
case 1:
		system("cls");
		cout<<"\t******************************************\n";
		cout<<"\t******************************************\n";
        cout<<"\t\tGENERAL CLINIC\n";
        cout<<"\t******************************************\n";
        cout<<"\t******************************************\n";
        contents();
        break;
case 2:
		system("cls");
		cout<<"\t******************************************\n";
		cout<<"\t******************************************\n";
        cout<<"\t\tHEART CLINIC\n";
        cout<<"\t******************************************\n";
        cout<<"\t******************************************\n";
        contents();
        break;
case 3:
		system("cls");
		cout<<"\t******************************************\n";
		cout<<"\t******************************************\n";
        cout<<"\t\tTEETH CLINIC\n";
        cout<<"\t******************************************\n";
        cout<<"\t******************************************\n";
        contents();
        break;
case 4:
		system("cls");
		cout<<"\t******************************************\n";
		cout<<"\t******************************************\n";
        cout<<"\t\tBONE CLINIC\n";
        cout<<"\t******************************************\n";
        cout<<"\t******************************************\n";
        contents();
        break;
case 5:
		system("cls");
		cout<<"\t******************************************\n";
		cout<<"\t******************************************\n";
        cout<<"\t\tKIDNEY CLINIC\n";
        cout<<"\t******************************************\n";
        cout<<"\t******************************************\n";
        contents();
        break;
case 6:
		system("cls");
        cout<<"\t\t----THANK YOU----";
        return 0;
        break;
default:
        cout<<"Please Enter the Correct Choice\n";
        goto again;
        break;
}
return 0;
}
// function used to show the contents that found in all department
void contents(){
        system("cls");
        cout<<"\t\tEnter your choice\n";
        cout<<"\t";BottomDesign();
        cout<<"\n\t";BottomDesign();
        cout<<"\n\t++                                     \t++\n";
        cout<<"\t++     1-> Register New patient      \t++\n";
        cout<<"\t++     2-> Display patient list        \t++\n";
        cout<<"\t++     3-> Remove patient 	      \t++\n";
        cout<<"\t++     4-> Take patient to operation    ++\n";
        cout<<"\t++     5-> Display ongoing operations   ++\n";
        cout<<"\t++     6-> Remove ongoing operations    ++\n";
        cout<<"\t++     7-> Go back or exit \t\t++\n";
        cout<<"\t++                                     \t++\n";
        cout<<"\t";BottomDesign();
        cout<<"\n\t";BottomDesign();
        AllDatabase();
}

	void AllDatabase()
{
	int backer;
	cin>>depstart;
switch(depstart)
{
case 1:
    PNumber(getway);
    cout<<"You Have Successfully Registered Your Patient\n";
    cout<<"Enter 5 to go back\n";
    cin>>backer;
    if(backer==5)
	contents();
	break;
case 2:
    DisplayPatient(getway);
    cout<<"Enter 5 to go back\n";
    cin>>backer;
    if(backer==5)
    contents();
	break;
case 3:
	DeleteP();
	cout<<"Enter 5 to go back\n";
    cin>>backer;
    if(backer==5)
    contents();
	break;
case 4:
	Doclist(getway);
	break;
case 5:
    OperationDisplay();
    cout<<"Under Implementation";
    break;
case 6:
    RemoveOperation();
    break;
case 7:
	frontEnd();
	break;
}
}

void TopDesign()
{
    for(int i=0;i<10;i++)
{
    for(int j=i;j<=10;j++)
    {
        cout<<"*";
        for(int i=0;i<j;i++)
        cout<<" ";
    }
cout<<endl;
}
}
//used to beutify the buttom user interfece
void BottomDesign()
{
    for(int i=0;i<=41;i++)
{
    cout<<"+";
}
}
//instantiating object for Doctors class found in PatientRegistration header 
Doctors doc;
void  Doclist(int dep){
	system("cls");
	cout<<"----------------------------------------------\n";
	cout<<"----------------------------------------------\n";
	cout<<"\t\tTakeoff Your Operation\n";
	cout<<"----------------------------------------------\n";
	cout<<"----------------------------------------------\n";
	
	cout<<"Available Specialist Doctors List\n";
	for(int i=0;i<10;i++){
		if(doc.Specialized[i]==dep){
			cout<<doc.Docname[i]<<setw(20)<<"  ||"<<doc.DocId[i]<<endl;
		}
	}
	cout<<"Patient names on this department\n";
	track = Front;

while(track!=NULL){
	if(track->department==dep){
	cout<<"----------------------------------------\n\n";
	cout<<"ID Number	:	"<<track->id<<endl;
	cout<<"Full Name	:	"<<track->Fname<<" "<<track->Mname<<endl;
	cout<<"\n----------------------------------------\n\n";
	track = track->Next;
}else
	track = track->Next;
	}
	cout<<"Select the Doctor who took the Operation By Id and \n Select Patient by id tobe operated\n";
	int DId;	//variable used to recieve Operator Doctor's Id 
	int PId;	//Variable used to recieve Patient Id to be Operated
	string Doctor; // variable used store Doctors name
	string Patient; // variable used to store Patients FUll Name
	bool bed;
	cout<<"Enter Doctor Id\n";
	cin>>DId;
	for(int i=0;i<10;i++){
		if(doc.Specialized[i]==dep && doc.DocId[i]==DId){
			cout<<"You select Doctor "<<doc.Docname[i]<<endl;
			Doctor = doc.Docname[i];
			break;
		}
	}
	cout<<"Enter Patient Id\n";
	cin>>PId;
	track = Front; //  Our track variable  is used to access all linked lists
	cout<<"Your Selected Patient is \n";
	while(track!=NULL){
	if(track->department==getway  && track->id==PId){
	cout<<"----------------------------------------\n\n";
	cout<<"ID Number	:	"<<track->id<<endl;
	cout<<"Full Name	:	"<<track->Fname<<"	"<<track->Mname<<"	"<<track->Lname<<endl;
	Patient = track->Fname + " " + track->Mname +" "+ track->Lname;
	bed = track->bed;
	cout<<"\n----------------------------------------\n\n";
	StartOperation(Doctor, Patient, DId, PId, bed);
	break;
}else
	track = track->Next;
	}
	cout<<"You Have Successfully Started The Operation\n";
}
bool ISempty(){
	if(Frt == NULL && Rr == NULL)
	return true;
	else
	return false;
}
//Function USed to Start operation
void StartOperation(string Dn, string Pn, int Di, int Pi, bool bd){
	int backer;
	tempo = new Operation;
	tempo->Dname = Dn;
	tempo->Pname = Pn;
	tempo->Did = Di;
	tempo->Pid = Pi;
	tempo->bed = bd;
	if(ISempty()){
          Frt=Rr=tempo;
          tempo->Next=NULL;
       }
       
       else{
       	if(tempo->bed){
       		Second = Frt;
       		Frt = tempo;
       		tempo->Next = Second;
		   }
		   else{
         Rr->Next=tempo;
         tempo->Next=NULL;
         Rr=tempo;
		 }
       }
    cout<<"Enter 5 to go back\n";
    cin>>backer;
    if(backer==5)
    contents();
}
//function to display ongoing operations
void OperationDisplay(){
	system("cls");
	int backer;
	if(ISempty()){
		cout<<"There Is No operation at the moment\n";
	}
	current1 = Frt;
	while(current1!=NULL){
		cout<<"Doctor ID "<<setw(25)<<" Doctor Name"<<endl;
		cout<<current1->Did<<setw(25)<<current1->Dname <<" Starts Operation For Patient\n";
		cout<<setw(30)<<"Patient Id "<<setw(25)<<" Patient Name"<<endl;
		cout<<setw(30)<<current1->Pid<<setw(25)<<current1->Pname<<endl;
		current1++;
	}
	cout<<"Enter 5 to go back\n";
    cin>>backer;
    if(backer==5)
    contents();
}
//function used to Dequeue Patients

void RemoveOperation(){
	if(ISempty())
	cout<<"There is No Started Operation\n";
	else{
		current1 = Frt;
		Frt = Frt->Next;
		delete current1;
		cout<<"You Have Successfully Removed the Operation\n";
	}
}