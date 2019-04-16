#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<ctype.h>

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
		Student();
		void input(ifstream& ifs);
		void getStream();
		void getTotalMarks();
};
Student::Student()
{
	
	roll_no = 0;
	strcpy(name, "");
	strcpy(gender, "");
	for(int i=0;i<6;i++)
	{
		sub_code[i] = marks[i] = 0;
		strcpy(grade[i], "");
	}
	strcpy(grade[6], "");
	strcpy(grade[7], "");
	strcpy(grade[8], "");

}

void Student::getTotalMarks()	{
	total_marks = 0;
	for(int i=0;i<5;i++)
		total_marks+=marks[i];
}
void Student::getStream()	{
	int sum=0;
	for(int i=1;i<5;i++)
		sum+=sub_code[i];
	switch(sum)	{
		case 209:
			strcpy(stream, "Science");
			strcpy(sub_stream, "PCM CS");
			break;
		case 428:
			strcpy(stream, "Science");
			strcpy(sub_stream, "PCM Hindi");
			break;
		case 170:
			strcpy(stream, "Science");
			strcpy(sub_stream, "PCM Biology");
			break;
		case 431:
			strcpy(stream, "Science");
			strcpy(sub_stream, "PCB Hindi");
			break;
		case 180:
			strcpy(stream, "Commerce");
			strcpy(sub_stream, "Mathematics");
			break;
		case 441:
			strcpy(stream, "Commerce");
			strcpy(sub_stream, "Hindi");
			break;
		case 386:
			strcpy(stream, "Humanities");
			strcpy(sub_stream, "Political Science");
			break;
		case 86:
			strcpy(stream, "Humanities");
			strcpy(sub_stream, "Political Science Hindi E");
			break;
		case 388:
			strcpy(stream, "Humanities");
			strcpy(sub_stream, "Economics");
			break;
		case 88:
			strcpy(stream, "Humanities");
			strcpy(sub_stream, "Economics Hindi E");
			break;
		default:
			strcpy(stream, "Unknown");
			strcpy(sub_stream, "Unknown");
			break;
	}
}
void Student::input(ifstream& ifs)
{
	char word[100];
	ifs>>roll_no;
	if(ifs.eof())
		return;
	ifs>>name;
	ifs>>word;
	while(strcmp(word, "M") && strcmp(word, "F"))
	{
		strcat(name, " ");
		strcat(name, word);
		ifs>>word;
	}
	strcpy(gender , word);
	ifs>>sub_code[0];
	ifs>>marks[0];
	ifs>>word;
	if(!isalpha(word[0]))
	{
		sub_code[1]=marks[0];
		marks[0] = 0;
		sub_code[2] = atoi(word);
		ifs>>sub_code[3];
		ifs>>sub_code[4];
		ifs>>sub_code[5];
		ifs>>result;
	}
	
	else	{
		strcpy(grade[0] , word);
		for(int i=1;i<6;i++)
		{
			ifs>>sub_code[i];
			ifs>>word;
			if(!strcmp(word , "AB"))
				marks[i]=0;
			else
				marks[i] = atoi(word);
			ifs>>grade[i];
		}
		ifs>>word;
		int i=6;
		while(strlen(word)<=2 && i<9)	{
		strcpy(grade[i],word);
		ifs>>word;
		i++;
		}
		strcpy(result , word);
	}
	getTotalMarks();
	getStream();
}

/*void Student::show()	{
	cout<<roll_no<<endl<<name<<endl<<gender<<endl;
	for(int i=0;i<6;i++)
	{
		cout<<sub_code[i]<<" "<<marks[i]<<" "<<grade[i]<<endl;
	}
	cout<<grade[6]<<endl<<grade[7]<<endl<<grade[8]<<endl;
	cout<<result<<endl<<endl;
}*/	

int main()	{
	Student s;
	ifstream ifs("mark.txt");
	ofstream ofs("student.dat", ios::binary);
	while(!ifs.eof())	{
	s.input(ifs);
	if(ifs.eof())
		break;
	ofs.write((char*)&s, sizeof(s));
	}
	ifs.close();
	ofs.close();
	return 0;
}