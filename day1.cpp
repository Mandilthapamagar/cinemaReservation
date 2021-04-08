#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>

using namespace std;
struct filmdata{
    char filmname[20],dirname[20],date[20];
}f1;



class loginmanager
{
    string username1,password1;
    string username_attempt1,password_attempt1;
    int attempt=3;

public:
    void login()
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
                cout<<"welcome abroad";
            }
            else
            {
                cout<<"invalid password";
                --attempt;
                if(attempt==0)
                {
                    exit(0);
                }
                login();
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
            login();
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
class loginmanager2{

	string username,password,un,pw,una,database;
	long int number;
	char dob[10];

	public:

	void signup()
	{
		cout<<"enter the username:";
		cin>>username;
		cout<<"enter the password:";
		cin>>password;
		cout<<"enter your phone number:";
		cin>>number;
		cout<<"enter your D.O.B:";
		cin>>dob;
		ofstream file;
		ofstream data;
		una="database/"+username+".txt";
		file.open(una.c_str());
		file.open("data.txt",ios::app);
		file<<username<<endl<<password;
		data<<username<<"\t"<<number<<"\t"<<dob<<endl;
		cout<<"\nSign up Sucessfull!!\n";
		file.close();
		data.close();
	}
	int login()
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
			return 1;
		}
		else
		{
			return 0;
		}
	}
};
class menu:public loginmanager2,public loginmanager{
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
            loginmanager2 l2;
            l2.login();
        }
        else if(choice==2)
        {
            loginmanager2 l2;
            l2.signup();
        }
        else
        {
            frontpage();
        }

    }
    void adminmenu()
    {
        cout<<"1.Register Film!!\n";
        cout<<"2.View user's details\n";
        cout<<"4.previous menu!!\n";
        cin>>choice;
        if(choice==1)
        {
            ofstream file;
            file.open("filmsdata.txt",ios::app);
            do
            {
                cout<<"enter the name of the movie:";
                cin>>f1.filmname;
                cout<<"enter the name of the director:";
                cin>>f1.dirname;
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
        else if(choice==2)
        {
            ifstream file;
            file.open("data.txt");
            cout<<"name\t\t"<<"address\t\t"<<"number";
            while(!file.eof())
            {
                getline(file,line);
                cout<<line;
            }
        }
        else
        {
            frontpage();
        }
    }
};
class front:public menu{
	int choice;
	public:
		void frontpage()
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
		//            menu m1;
		            adminmenu();
		            break;
		        case 3:
		            exit(0);
		        default:
		            cout<<"Invalid choice";
		            getch();
		            system("cls");
		            frontpage();
		    }
};

int main()
{
    front f;
    f.frontpage();
}







