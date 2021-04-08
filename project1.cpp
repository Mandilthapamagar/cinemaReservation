#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<fstream>

using namespace std;
class loginmanager
{
    string username,password;
    string username_attempt,password_attempt;
    int attempt=3;

public:
    void login()
    {
        cout<<"USERNAME:";
        cin>>username_attempt;
        username=getinfo("username.txt");
        password=getinfo("password.txt");
        if(username_attempt==username)
        {
            cout<<"PASSWORD:";
            cin>>password_attempt;
            if(password_attempt==password)
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
	
	string username,password,un,pw,una;
	
	public:
		
	void signup()
	{	
		cout<<"enter the username:";
		cin>>username;
		cout<<"enter the password:";
		cin>>password;
		ofstream file;
		una="database/"+username+".txt";
		file.open(una.c_str());
		file<<username<<endl<<password;
		file.close();
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
int main()
{
//    loginmanager l1;
//    l1.login();
    loginmanager2 l2;
    l2.signup();
    if(l2.login()==1)
    {
    	cout<<"sucess!!";
	}
	else
	{
		cout<<"failure!!";
	}
}

