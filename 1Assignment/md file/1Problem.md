# Assignment No.1: Problem 1
# Basic String Operations without Built-In Functions  

---

## Title  
Implement basic string operations such as length calculation, copy, reverse, and concatenation using character single-dimensional arrays without using built-in string library functions.

---

## Theory  
String operations form the foundation of text processing in computer programming. When implemented without library functions, these operations help understand how strings are represented and manipulated in memory.  

- **String Length Calculation**:  
  Count the number of characters until the null terminator `'\0'` is reached.  

- **String Copy**:  
  Copy each character from the source string to the destination string one by one.  

- **String Reverse**:  
  Swap characters from both ends until the middle of the string is reached.  

- **String Concatenation**:  
  Append the second string to the end of the first string manually, starting from the null terminator position.  

This program demonstrates these operations using **character arrays** and **loops** instead of using functions from the `<string>` library.

---

## Algorithm  

1. Start.  
2. Display the menu with options to:  
   - Enter a string  
   - Calculate string length  
   - Reverse the string  
   - Exit  
3. Read the user’s choice.  
4. For **length** operation:  
   - Initialize a counter.  
   - Traverse the string until `'\0'` is reached.  
   - Display the count as string length.  
5. For **reverse** operation:  
   - Find the string length.  
   - Copy characters from the end to a new string.  
   - Display the reversed string.  
6. Repeat the menu until the user chooses Exit.  
7. Stop.  

---

## Code  

```cpp
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
```
## OUTPUT
\*\*\*\*\*\*\*\*MENU\*\*\*\*\*\*\*

1.Enter a String

2.Calculate Length of the String

3.Reversal of String

4.Exit

1

Enter a String

hello

\*\*\*\*\*\*\*\*MENU\*\*\*\*\*\*\*

1.Enter a String

2.Calculate Length of the String

3.Reversal of String

4.Exit

2

Length of string hello : 5

\*\*\*\*\*\*\*\*MENU\*\*\*\*\*\*\*

1.Enter a String

2.Calculate Length of the String

3.Reversal of String

4.Exit

3

Reversal of String hello is olleh

\*\*\*\*\*\*\*\*MENU\*\*\*\*\*\*\*

1.Enter a String

2.Calculate Length of the String

3.Reversal of String

4.Exit

4

You choose to exit...