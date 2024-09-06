#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
float grade_point(int p){
  if(p>84&&p<101)
  return 4.0;
  else if(p>79&&p<85)
  return 3.7;
   else if(p>74&&p<80)
  return 3.3;
   else if(p>69&&p<75)
  return 3.0;
   else if(p>64&&p<70)
  return 2.7;
   else if(p>60&&p<65)
  return 2.3;
   else if(p>57&&p<61)
  return 2.0;
   else if(p>54&&p<58)
  return 1.7;
   else if(p>49&&p<55)
  return 1.0;
   else 
  return 0.0;
}
int Percentage(double m,double tm){
float percent;
percent= (m/tm)*100;
return static_cast<int>(percent);
}
int main()
{ 
  do{
    system("cls");
  int no_of_sub,semester,P=0;
  float SUM=0,sum=0,GPA,gsum=0;
  char choice;
   start:
   cout<<"                                                "<<endl;
   cout<<"              |--------------------------------|"<<endl;
   cout<<"              |        GPA CALCULATOR          |"<<endl;
   cout<<"              |--------------------------------|"<<endl<<endl;
  
   cout<<"PRESS 1 TO CALCULATE GPA "<<endl;
   cout<<"PRESS 2 TO CALCULATE CGPA"<<endl;
   cout<<"1 GPA"<<endl;
   cout<<"2 CGPA"<<endl;
   cin>>choice;

if (choice=='1'){
  
cout<<"Enter number of subjects :" ;
cin>> no_of_sub;

  int*Subjects=new int[no_of_sub];
  int* credit =new int[no_of_sub];
  double* obtain_marks= new double[no_of_sub];
  double* total_marks= new double[no_of_sub];
  int*percentage=new int[no_of_sub];
  float*Grade_points=new float[no_of_sub];
  

for(int i=0;i<no_of_sub;i++){
   cout<<"Enter credit hours of subject "<<i+1<<": ";
    cin>> credit[i];
    cout<<"Enter obtained marks of subject "<<i+1<<": ";
    cin>>obtain_marks[i];
    cout<<"Enter total marks of subject "<<i+1<<": ";
    cin>>total_marks[i];
    cout<<endl;
}
for(int i=0;i<no_of_sub;i++){
  percentage[i]= Percentage(obtain_marks[i],total_marks[i]);
  Grade_points[i]=grade_point(percentage[i]);
  SUM= (Grade_points[i]*credit[i])+SUM;
  sum= credit[i]+sum;
  cout<<"The Grade Points of Subject "<< i+1 <<" is :"<<fixed<<setprecision(2)<<Grade_points[i]<<endl;
}

 GPA= SUM/sum;
  cout<<"The Total Grade Point of All Subjects :"<<GPA<<endl;
  cout<<endl<<"           PRESS ANY KEY TO RETURN TO THE MAIN MENU...";
  getche();
delete[] Subjects;
delete[] credit;
delete[] obtain_marks;
delete[] total_marks;
delete[] percentage;
delete[] Grade_points;

}
else if(choice=='2'){
  cout<<"CHOOSE YOUR SEMESTER "<<endl;
  cout<<"1: 1st SEMESTER "<<endl;
  cout<<"2: 2nd SEMESTER "<<endl;
  cout<<"3: 3rd SEMESTER "<<endl;
  cout<<"4: 4th SEMESTER "<<endl;
  cout<<"5: 5th SEMESTER "<<endl;
  cout<<"6: 6th SEMESTER "<<endl;
  cout<<"7: 7th SEMESTER "<<endl;
  cout<<"8: 8th SEMESTER "<<endl;
  cin>>semester;
  float*gpa=new float[semester];
for(int i=0;i<semester;i++){
  cout<<"Enter GPA of Semester "<<i+1<<" :"<<endl;
  cin>>gpa[i];
  gsum=gsum+gpa[i];
}
cout<<"YOUR CGPA OF SEMESTERS :"<<endl;
cout<<fixed<<setprecision(2)<<gsum/semester<<endl;
cout<<endl<<"           PRESS ANY KEY TO RETURN TO THE MAIN MENU...";
getche();
delete[] gpa;
}
  }while(1);
}