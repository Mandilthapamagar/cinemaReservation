#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#define MAX 100
using namespace std;
class frontpage;

class mainmenu{
    struct filmdata{
    char filmname[MAX],dirname[MAX],date[MAX];
}f1;
    int ch;
    char c;
    string line;
    public:
    void usermm()
    {
          cout<<"1.View movies details\n";
          cout<<"2.Book ticket\n";
          cout<<"3.Exit";
          cin>>ch;
          if(ch==1)
          {
                ifstream file;
                file.open("filmsdata.txt");
                while(!file.eof())
                {
                    file.read((char *) & f1,sizeof(f1));
                    cout<<"Movie:"<<f1.filmname<<endl;
                    cout<<"Directed By:"<<f1.dirname<<endl;
                    cout<<"Release Date:"<<f1.date<<endl;
                    cout<<"-------------------------------------------------------------------"<<endl<<endl;
                }
          }
          else if(ch==2)
          {
              cout<<"work on progress";
          }
          else
          {
              exit(0);
          }
    }
     void amdinmm()
    {
        cout<<"1.Register Film!!\n";
        cout<<"2.View user's details\n";
        cout<<"3.previous menu!!\n";
        cin>>ch;
        if(ch==1)
        {
            ofstream file;
            file.open("filmsdata.txt",ios::app);
            do
            {
                cout<<"enter the name of the movie:";
                cin.getline(f1.filmname,MAX);
                cout<<"enter the name of the director:";
                cin.getline(f1.dirname,MAX);
                cout<<"enter the release date:";
                cin>>f1.date;
    //          cout<<"press enter to continue";
    //          getch()
                cout<<"Do you want to add one more record?\n";
                cout<<"y-for Yes\n n-for No\n";
                cin>>c;
                file.write((char *) & f1,sizeof(f1));
            }while(c=='y');
            file.close();
        }
        else if(ch==2)
        {
            ifstream file;
            file.open("data.txt");
            cout<<"name\t\t"<<"number\t\t"<<"DOB\n";
            while(!file.eof())
            {
                getline(file,line);
                cout<<line<<endl;
            }
        }
        else
        {
            //frontpage();
            cout<<"work on progress!!";
        }
    }
};

class loginmanager:public mainmenu{
    string username1,password1,username_attempt1,password_attempt1;
    string username,password,un,pw,una,database;
    int attempt=3;
    long long int number;
	char dob[10],c;

public:
    void adminlogin()
    {
        cout<<"USERNAME:";
        cin>>username_attempt1;
        username1=getinfo("username.txt");
        password1=getinfo("password.txt");
        if(username1==username_attempt1)
        {
            cout<<"PASSWORD:";
            cin>>password_attempt1;
            if(password1==password_attempt1)
            {
                amdinmm();
            }
            else
            {
                cout<<"invalid password";
                --attempt;
                if(attempt==0)
                {
                    exit(0);
                }
                adminlogin();
            }
        }
        else
        {
            cout<<"invalid username";
            --attempt;
            if(attempt==0)
            {
                exit(0);
            }
            adminlogin();
        }
    }

	void usersignup()
	{
		ofstream file;
		ofstream data;
		do{
			cout<<"enter the username:";
			cin>>username;
			cout<<"enter the password:";
			cin>>password;
			cout<<"enter your phone number:";
			cin>>number;
			cout<<"enter your D.O.B:";
			cin>>dob;
			una="database/"+username+".txt";
			file.open(una.c_str());
			data.open("data.txt",ios::app);
			file<<username<<endl<<password;
			data<<username<<"\t"<<number<<"\t"<<dob<<endl;
			cout<<"\nSign up Sucessfull!!\n";
			cout<<"Do you want to add one more record?\n";
            cout<<"y-for Yes\n n-for No\n";
            cin>>c;

		}while(c=='y');
		file.close();
		data.close();

	}
	void userlogin()
	{

		cout<<"enter the username:";
		cin>>username;
		cout<<"enter the password:";
		cin>>password;
		ifstream file;
		una="database/"+username+".txt";
		file.open(una.c_str());
		getline(file,un);
		getline(file,pw);
		if(un==username && pw==password)
		{
//			return 1;
            usermm();
		}
		else
		{
//			return 0;8
			cout<<"unsucessfull";
		}
	}
    string getinfo(char *file_path)
    {
        string line;
        ifstream file;
        file.open(file_path);
        if(file.is_open())
        {
           getline(file,line);
        }
        file.close();
        return line;
    }
};
class menu:public loginmanager{

	public:
    char c;
    int choice;
    string line;
    void usermenu()
    {
        cout<<"1.Log in!\n";
        cout<<"2.sign up!!\n";
        cout<<"3.previous menu!!\n";
        cin>>choice;
        if(choice==1)
        {
            userlogin();
        }
        else if(choice==2)
        {
            usersignup();
        }
        else if(choice==3)
        {
			  cout<<"work on progress";
        }

    }
    void adminmenu()
    {
        adminlogin();
    }
};

class frontpage:public menu{
	int choice;
	public:
            void fronter()
                {
                    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                    cout<<".......WELCOME TO CINEMA RESERVATION SYSTEM..........\n";
                    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                    cout<<"^^^^^^^^^^^^^^^^^^^^^^MAIN MENU^^^^^^^^^^^^^^^^^^^^\n";
                    cout<<"1.USER MODE\n";
                    cout<<"2.ADMIN MODE\n";
                    cout<<"3.EXIT\n";
                    cout<<"enter the choice:";
                    cin>>choice;
                    switch(choice)
                    {
                    case 1:
                        usermenu();
                        break;
                    case 2:
                        adminmenu();
                        break;
                    case 3:
                        exit(0);
                    default:
                        cout<<"Invalid choice";
                        getch();
                        system("cls");
                        fronter();
                    }
                }
};
int main()
{
    frontpage f1;
	f1.fronter();
}

