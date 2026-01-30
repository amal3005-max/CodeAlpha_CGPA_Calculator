#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//FUNCTION PROTOTYPE
float gradepoint_conversion(string grade);
//MAIN 
int main()
{
	int n;
	
	cout<<"=====================================\n"<<endl;
	cout<<"\t CGPA CALCULATOR \n"<<endl;
	cout<<"=====================================\n"<<endl;
	
	cout<<"Enter number of courses / subjects : ";
	cin>>n;
	if(n<0||n>100)
	{
		cout<<"Invalid input!"<<endl;
		exit(0);
	}
	
	string name[n] = {""};
	int credits[n] = {0};
	string grades[n] = {};
	float gp[n]={0};
	
	cout<<"\nEnter Courses Names : "<<endl;
	cout<<"-------------------------\n"<<endl;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		cout<<"Enter course "<<i+1<<" name : ";
		getline(cin,name[i]);
	}
	
	
	cout<<"\n\nEnter Course's Credit Hours : "<<endl;
	cout<<"-------------------------\n"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter "<<name[i]<<" Credit Hours : ";
		cin>>credits[i];
		if(credits[i]<0||credits[i]>100)
		{
			cout<<"Invalid input!"<<endl;
			exit(0);
		}
	}
	
	
	cout<<"\n\nEnter Course's Grades : "<<endl;
	cout<<"-------------------------\n"<<endl;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		cout<<"Enter "<<name[i]<<" Grades : ";
		cin >> grades[i];
	}
	
	// GRADEPOINT CONVERSION
	for(int i=0;i<n;i++)
	{
		gp[i]=gradepoint_conversion(grades[i]);
		if(gp[i]==-1)
		{
			cout<<"Invalid grade input!"<<endl;
			exit(0);
		}
	}
	
	int totalCredits=0;
	float totalGradePoints=0;
	for(int i=0;i<n;i++)
	{
		totalCredits += credits[i];
		totalGradePoints += gp[i]*credits[i];
	}
	double CGPA=totalGradePoints/totalCredits;
	cout<<left<<setw(15)<<"Course"<<setw(10)<<"Credits"<<setw(8)<<"Grade"<<setw(12)<<"Grade Points"<<"\n";	
	cout<<"----------------------------------------\n";
	for(int i=0;i<n;i++) 
	{
		cout<<left<<setw(15)<<name[i]<<setw(8)<<credits[i]<<setw(6)<<grades[i]<<setw(8)<<gp[i]<<"\n";	
	}
	cout<<"----------------------------------------\n";
	cout<<"Total Credits: "<<totalCredits<<"\n";
	cout<<"CGPA: "<<fixed<<setprecision(2)<<CGPA<<"\n";
	return 0;
}
//=========================================================
// GRADE POINT CALCULATION
float gradepoint_conversion(string grade)
{
	double gradePoint=-1;
	
	if(grade=="A+"||grade=="A")
	{
    	gradePoint=4.00;
	}
	else if(grade=="A-")
    {
    	gradePoint=3.67;
	}
	else if(grade=="B+")
    {
		gradePoint=3.33;
	}
	else if(grade=="B")
    {
		gradePoint=3.00;
	}
	else if(grade=="B-")
    {
		gradePoint=2.67;
	}
	else if(grade=="C+")
    {
		gradePoint=2.33;
	}
	else if(grade=="C")
    {
		gradePoint=2.00;
	}
	else if(grade=="C-")
    {
		gradePoint=1.67;
	}
	else if(grade=="D+")
    {
		gradePoint=1.33;
	}
	else if(grade=="D")
    {
		gradePoint=1.00;
	}
	else if(grade=="F")
    {
		gradePoint=0.00;
	}
	return gradePoint;
}
