// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
#define DOT "."
 int Function(char*);
 bool Validity(char*);

int Function(char* ip_str)
{
	if (ip_str == NULL)
		return 0;
		
	int i, num, dots = 0,count=0, len = strlen(ip_str);
	
	for (int i = 0; i < len; i++)
		if (ip_str[i] == '.')
			count++; // TO CHECK NUMBER OF DOTS IN A STRING
			
	if (count != 3)//it should be equal to 3
		return false;
	

	char *ptr = strtok(ip_str, DOT);
	if (ptr == NULL)
		return 0;

	while (ptr) {

		if (Validity(ptr))
		{
			ptr = strtok(NULL, "."); //splitting a string by some delimiter "."
			if (ptr != NULL)
				++dots;
		}
		else
			return 0;
	}
	
	if (dots != 3)
		return 0;
	return 1;
}

bool Validity(char* s)
{
	int n = strlen(s);
	

	if (n > 3)
		return false;
	

	for (int i = 0; i < n; i++)
		if ((s[i] >= '0' && s[i] <= '9') == false)
			return false;
	string str(s);
	
		
	stringstream ipip(str);
	int x;
	ipip >> x;

	return (x >= 0 && x <= 255);
}

int main()
{
char ip1[12] ;
cout << "Enter the string \n";
cin>>ip1;
Function(ip1) ? cout<<"Valid\n" : cout<<"Not valid\n";

	
	return 0;
}

