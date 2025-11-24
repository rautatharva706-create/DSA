#include<iostream>
using namespace std;
#include<string>

int menu()
{	
	cout<<"********MENU*******"<<endl;
	cout<<"1.Enter a String"<<endl;
	cout<<"2.Calculate Length of the String"<<endl;
	cout<<"3.Reversal of String"<<endl;
	cout<<"4.Exit"<<endl;
	int choice=0;
	cin>>choice;
	return choice;	
}

int main()
{
	int choice=0;
	string s,s2;
	
	do {
		choice=menu();
		switch(choice)
		{
			case 1:
			    cout<<"Enter a String"<<endl;
			    cin>>s;
			    break;
			    
			case 2: {
			    int len=0;
			    while(s[len]!='\0')
			    {
					len++;
			    }
			    cout<<"Length of string "<<s<<" : "<<len<<endl;
			    break;
			}
			
			case 3: {
			    int len=0;
			    int i=0; 
			    while(s[len]!='\0')
			    {
					len++;
			    }
			    
			    s2.resize(len);   // allocate space for reversal
			    
			    while(len>0)
			    {
					s2[i]=s[len-1];
					len--;
					i++;
			    }
			    cout<<"Reversal of String "<<s<<" is "<<s2<<endl;
			    break;
			}
			
			case 4:
			    cout<<"You choose to exit..."<<endl;
			    break;
			    
			default:
			    cout<<"Please select correct option"<<endl;
			    break;
		}
	} while(choice!=4);
	
	return 0;
}
