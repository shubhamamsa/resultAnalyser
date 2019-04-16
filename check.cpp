#include<iostream>
#include<fstream>
#include<math.h>
#include<string.h>

using namespace std;

class Student{
		int roll_no;
		char name[40];
		char gender[2];
		int sub_code[6], marks[6];
		char grade[9][3];
		char result[5];
		char stream[15];
		char sub_stream[30];
		int total_marks;
	public:
		void show();
		char* getSubject(int);
		int totalMarks();
		
};

void showData();
void showTopper();
void showSubTopper(char[]);
void search();

void Student::show()	{
		cout<<stream<<": "<<sub_stream<<endl;
		cout<<roll_no<<endl<<name<<endl<<gender<<endl;
		for(int i=0;i<6;i++)	
			cout<<getSubject(sub_code[i])<<": "<<" "<<marks[i]<<" "<<grade[i]<<endl;
		cout<<result<<endl<<endl;
}*
char* Student::getSubject(int sub_code)	{
	char* sub_name = new char;
	switch(sub_code)	{
		case 301:
			strcpy(sub_name, "English Core");
			break;
		case 42:
			strcpy(sub_name, "Physics");
			break;
		case 43:
			strcpy(sub_name, "Chemistry");
			break;
		case 41:
			strcpy(sub_name, "Mathematics");
			break;
		case 44:
			strcpy(sub_name, "Biology");
			break;
		case 83:
			strcpy(sub_name, "Computer Science");
			break;
		case 302:
			strcpy(sub_name, "Hindi Core");
			break;
		case 54:
			strcpy(sub_name, "Business Studies");
			break;
		case 30:
			strcpy(sub_name, "Economics");
			break;
		case 27:
			strcpy(sub_name, "History");
			break;
		case 28:
			strcpy(sub_name, "Political Science");
			break;
		case 29:
			strcpy(sub_name, "Geography");
			break;
		case 55:
			strcpy(sub_name, "Accountancy");
			break;
		case 48:
			strcpy(sub_name, "Physical Education");
			break;
		default:
			cout<<"Something is not right";
	}
	return sub_name;
}
int totalMarks()	{
	return total_marks;
}
int main()	{
	Student s;
	ifstream ifs("student.dat", ios::binary);
	while(ifs.read((char*)&s, sizeof(s)))	{
		s.show();
	}
	ifs.close();
	return 0;
}
void showData()	{
	Student s;
	ifstream ifs("student.dat", ios::binary);
	if(!ifs)	{
		cout<<"Error opening file";
		return;
	}
	while(ifs.read((char*)&s, sizeof(s)))
		s.show();
	ifs.close();
}

void showTopper()	{
	Student s, top;
	ifstream ifs("student.dat", ios::binary);
	if(!ifs)	{
		cout<<"Error opening file";
		return;
	}
	int topper=0;
	while(ifs.read((char*)&s, sizeof(s)))	{
		if(topper<s.totalMarks())	{
			topper = s.totalMarks;
			top=s;
		}
	}
	while()n 
	ifs.close();
}