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
		char* getName();
		int* getSubcode();
		int* getMarks();
		char* getStream();
		char* getGender();
		int getRno();
		
};

void showData();
void topper();
void showStreamTopper();
void showGenderTopper();
void showSchoolTopper();
void showSubTopper();
void search();
void searchByRno();
void searchByName();

void Student::show()	{
		cout<<stream<<": "<<sub_stream<<endl;
		cout<<roll_no<<endl<<name<<endl<<gender<<endl;
		for(int i=0;i<6;i++)	
			cout<<getSubject(sub_code[i])<<": "<<" "<<marks[i]<<" "<<grade[i]<<endl;
		cout<<result<<endl;
		cout<<float(total_marks)/5.0<<"%"<<endl<<endl;
}
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

int Student::totalMarks()	{
	return total_marks;
}

char* Student::getName()	{
	return name;
}
int Student::getRno()	{
	return roll_no;
}

int* Student::getSubcode()	{
	return sub_code;
}

char* Student::getStream()	{
	return stream;
}

char* Student::getGender()	{
	return gender;
}

int* Student::getMarks()	{
	return marks;
}
int main()	{
	while(1)	{
		int choice;
		cout<<endl<<"1. Topper"<<endl;
		cout<<"2. Search"<<endl;
		cout<<"3. Full data"<<endl;
		cout<<"4. Exit"<<endl<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)	{
			case 1:
				topper();
				break;
			case 2:
				search();
				break;
			case 3:
				showData();
				break;
			case 4:
				cout<<"Exiting..."<<endl;
				return 0;
		}
	}
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

void showSchoolTopper()	{
	Student s;
	ifstream ifs("student.dat", ios::binary);
	if(!ifs)	{
		cout<<"Error opening file";
		return;
	}
	int topper=0;
	while(ifs.read((char*)&s, sizeof(s)))	{
		if(topper<s.totalMarks())	{
			topper = s.totalMarks();
		}
	}
	ifs.clear();
	ifs.seekg(0, ios::beg);
	while(ifs.read((char*)&s, sizeof(s)))
		if(s.totalMarks() == topper)
			s.show();
	ifs.close();
}

void search()	{
	cout<<"1. Search by Roll no."<<endl;
	cout<<"2. Search by name"<<endl;
	int choice;
	cout<<endl<<"Enter your choice: ";
	cin>>choice;
	switch(choice)	{
		case 1:
			searchByRno();
			break;
		case 2:
			searchByName();
			break;
		default:
			cout<<"Wrong choice entered.";
	}
}

void searchByRno()	{
	Student s;
	ifstream ifs("student.dat", ios::binary);
	if(!ifs)	{
		cout<<"Error opening file";
		return;
	}
	int rno, flag=0;
	cout<<"Enter roll no: ";
	cin>>rno;
	while(ifs.read((char*)&s, sizeof(s)))	{
		if(s.getRno()==rno)	{
			s.show();
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"No records found";
	ifs.close();
}

void searchByName()	{
	Student s;
	ifstream ifs("student.dat", ios::binary);
	if(!ifs)	{
		cout<<"Error opening file";
		return;
	}
	char searched_name[40], student_name[40];
	int length_student_name, length_searched_name, mainflag=0, searchflag=0;
	cout<<"Enter your name: ";
	cin.ignore();
	cin.getline(searched_name, 40);
	length_searched_name = strlen(searched_name);
	for(int i=0;i<length_searched_name;i++)
		searched_name[i] = toupper(searched_name[i]);
	while(ifs.read((char*)&s, sizeof(s)))	{
		searchflag = 0;
		strcpy(student_name, s.getName());
		length_student_name = strlen(student_name);
		for(int i=0;i<length_student_name;i++){
			if(student_name[i]==searched_name[searchflag])	{
				searchflag++;
				if(searchflag==length_searched_name)
					break;
				else
					continue;
			}
			else
				searchflag=0;
		}
		if(searchflag==length_searched_name)	{
			mainflag++;
			s.show();
		}
	}
	cout<<"Total results: "<<mainflag;
	ifs.close();
}

void topper()	{
	cout<<endl<<"1. School Topper"<<endl;
	cout<<"2. Subject wise Topper"<<endl;
	cout<<"3. Stream wise Topper"<<endl;
	cout<<"4. Gender wise Topper"<<endl;
	cout<<"5. Exit"<<endl<<endl;
	cout<<"Enter your choice: ";
	int choice;
	cin>>choice;
	switch(choice)	{
		case 1:
			showSchoolTopper();
			break;
		case 2:
			showSubTopper();
			break;
		case 3:
			showStreamTopper();
			break;
		case 4:
			showGenderTopper();
			break;
		case 5:
			return;
	}
}

void showSubTopper()	{
	Student s;
	ifstream ifs("student.dat", ios::binary);
	if(!ifs)	{
		cout<<"Error opening file";
		return;
	}
	int subTopper[14]; 
	while(ifs.read((char*)&s, sizeof(s)))	{
		if(topper<s.totalMarks())	{
			topper = s.totalMarks();
		}
	}
	ifs.clear();
	ifs.seekg(0);
	while(ifs.read((char*)&s, sizeof(s)))
		if(s.totalMarks() == topper)
			s.show();
	ifs.close();
}

void showStreamTopper()	{
	
	Student s;
	int Science_topper=0, Commerce_topper=0, Humanities_topper=0;
	ifstream ifs("student.dat", ios::binary);
	if(!ifs)	{
		cout<<"Error opening file";
		return;
	}
	while(ifs.read((char*)&s, sizeof(s)))	{
		if(Science_topper<s.totalMarks() && !strcmp(s.getStream(), "Science"))	{
			Science_topper = s.totalMarks();
		}
		else if(Commerce_topper<s.totalMarks() && !strcmp(s.getStream(), "Commerce"))	{
			Commerce_topper = s.totalMarks();
		}
		else if(Humanities_topper<s.totalMarks() && !strcmp(s.getStream(), "Humanities"))	{
			Humanities_topper = s.totalMarks();
		}
	}
	ifs.clear();
	ifs.seekg(0);
	while(ifs.read((char*)&s, sizeof(s)))	{
		if(s.totalMarks() == Science_topper && !strcmp(s.getStream(), "Science"))	{
			cout<<"Science Topper: "<<endl;
			s.show();
		}
		else if(s.totalMarks() == Commerce_topper && !strcmp(s.getStream(), "Commerce"))	{
			cout<<"Commerce Topper: "<<endl;
			s.show();
		}
		else if(s.totalMarks() == Humanities_topper && !strcmp(s.getStream(), "Humanities"))	{
			cout<<"Humanities Topper: "<<endl;
			s.show();
		}
	}
	ifs.close();
	
}

void showGenderTopper()	{
	Student s;
	ifstream ifs("student.dat", ios::binary);
	if(!ifs)	{
		cout<<"Error opening file";
		return;
	}
	int male_topper=0, female_topper=0;
	while(ifs.read((char*)&s, sizeof(s)))	{
		if(male_topper<s.totalMarks() && !strcmp(s.getGender(), "M"))	{
			male_topper = s.totalMarks();
		}
		else if(female_topper<s.totalMarks() && !strcmp(s.getGender(), "F"))	{
			female_topper = s.totalMarks();
		}
	}
	ifs.clear();
	ifs.seekg(0);
	while(ifs.read((char*)&s, sizeof(s)))
		if(s.totalMarks() == male_topper && !strcmp(s.getGender(), "M"))	{
			cout<<"Male Topper: "<<endl;
			s.show();
		}
		else if(s.totalMarks() == female_topper && !strcmp(s.getGender(), "F"))	{
			cout<<"Female Topper: "<<endl;
			s.show();
		}
	ifs.close();
}





























/*
	Student s;
	ifstream ifs("student.dat", ios::binary);
	if(!ifs)	{
		cout<<"Error opening file";
		return;
	}
	while(ifs.read((char*)&s, sizeof(s)))	{
	}
	ifs.close();
*/