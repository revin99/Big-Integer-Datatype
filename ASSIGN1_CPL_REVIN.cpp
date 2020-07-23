// Same program using operator overloading
#include <bits/stdc++.h>
using namespace std;


class bigint 
{
	public :
	string s;
	
	
	bigint operator + (bigint b)
	{
				string str1= s; string str2=b.s; bigint ans;
				int neg=0;
				if(str1.at(0)=='-' && str2.at(0)!='-') // first num is negative and second is positive
				{
					s= s.substr(1);
					ans = b-*this;
				}
				else if(str1.at(0)!='-' && str2.at(0)=='-') //first num is positive and second is negative
				{
					b.s = b.s.substr(1);
					ans = *this-b;
				}
				else
				{
						if(str1.at(0)=='-' && str2.at(0)=='-') // both num are negative
						{
							str1 = str1.substr(1);
							str2= str2.substr(1);
							neg=1;
						}
					if (str1.length() > str2.length()) 
				   	    swap(str1, str2); 
				  	string str = ""; 
				  	int n1 = str1.length(), n2 = str2.length(); 
				  	reverse(str1.begin(), str1.end()); 
				  	reverse(str2.begin(), str2.end()); 
				  	int carry = 0; 
				   	for (int i=0; i<n1; i++) 
				   	{ 
				   	    int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
				   	    str.push_back(sum%10 + '0'); 
				    	carry = sum/10; 
				   	} 
				   	for (int i=n1; i<n2; i++) 
				   	{ 
						int sum = ((str2[i]-'0')+carry); 
					    str.push_back(sum%10 + '0'); 
				        carry = sum/10; 
				    } 
				    if(carry) 
				        str.push_back(carry+'0'); 
				    	reverse(str.begin(), str.end()); 
				  	string answer="";
				  	
				  	if(neg==1) // if number is negative
				  	{
				  		answer+='-';
				  		answer+=str;
					}
					else
					{
						answer=str;
					}
				  	
					ans.s= answer;
				}
			    return ans; 
	}
	
	bigint operator - (bigint b)
	{
		string str1 = s;
		string str2= b.s;
		 string str = ""; 
		int neg=0;
		bigint ans;
		if(s.at(0)=='-' && b.s.at(0)!='-') // -50 - (36) = -86
		{
			s=s.substr(1);
			ans = *this + b;
			neg=1;
			str = ans.s;		
		}
		else if(s.at(0)!='-' && b.s.at(0)=='-') // 50 - (-36) = 86
		{
			b.s=b.s.substr(1);
			ans = *this + b;
			str= ans.s;
		}
		else if( s.at(0)=='-' && b.s.at(0)=='-' ) // -50 - (-36) = -50 + 36 = -(50 - 36)
		{
			s=s.substr(1);
			b.s=b.s.substr(1);
			ans = *this - b;
			str=ans.s;
			neg=1;
		}
		else {
		int issmaller=0;
		int n11 = str1.length(), n22 = str2.length(); 
	    if (n11 < n22) 
	    issmaller=1;
	    else if (n22 < n11) 
	    issmaller=0;
	  	else {
			    		for (int i=0; i<n11; i++) 
			    		if (str1[i] < str2[i]) 
			    		{
			    			issmaller=1;
			    			break;
						} 
			    		else if (str1[i] > str2[i]) 
			    		{
			    			issmaller=0;
			    			break;
						} 
			  	}
				
				    if (issmaller==1) // true if str1 is smaller than str2
				    	{
				    		neg=1; // since answer will be smaller
				    		swap(str1,str2);
						}
				    int n1 = str1.length(), n2 = str2.length(); 
				    reverse(str1.begin(), str1.end()); 
				    reverse(str2.begin(), str2.end()); 
				      
				    int carry = 0; 
				    for (int i=0; i<n2; i++) 
				    { 
				        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
				        if (sub < 0) 
				        { 
				            sub = sub + 10; 
				            carry = 1; 
				        } 
				        else
				            carry = 0; 
				  
				        str.push_back(sub + '0'); 
				    } 
				    for (int i=n2; i<n1; i++) 
				    { 
				        int sub = ((str1[i]-'0') - carry); 
				        if (sub < 0) 
				        { 
				            sub = sub + 10; 
				            carry = 1; 
				        } 
				        else
				            carry = 0; 
				              
				        str.push_back(sub + '0'); 
				    } 
				    reverse(str.begin(), str.end()); 
		}
	    string answer="";
	    if(neg==1) // answer is negative
	    {
	    	answer+="-";
	    	answer+=str;
		}
	    else
	    {
	    	answer+=str;
		}
	  	ans.s=answer;
	    return ans; 
	}
	
	bigint operator * (bigint b)
	{
		string num1= s;
		string num2= b.s;
		int neg=0; bigint ans;
		string answer="";
		
		if(num1.at(0)=='-' && num2.at(0)!='-') // first number is negative and second is positive
		{
			neg=1;
			num1 = num1.substr(1);
		}
		else if(num1.at(0)!='-' && num2.at(0)=='-') // first number is positive and second is negative
		{
			neg=1;
			num2 = num2.substr(1);
		}
		else if(num1.at(0)=='-' && num2.at(0)=='-' ) // both numbers are negative 
		{
			num1 = num1.substr(1);
			num2 = num2.substr(1);
		}
		
		int len1 = num1.size(); 
	    int len2 = num2.size(); 
	    string s = "";
	    if (len1 == 0 || len2 == 0) 
	    s="0";
	    vector<int> result(len1 + len2, 0); 
	    int i_n1 = 0;  
	    int i_n2 = 0;  
	    for (int i=len1-1; i>=0; i--) 
	    { 
	        int carry = 0; 
	        int n1 = num1[i] - '0'; 
	        i_n2 = 0;               
	        for (int j=len2-1; j>=0; j--) 
	        { 
	            
	            int n2 = num2[j] - '0'; 
	            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
	  
	            carry = sum/10; 
	  
	            result[i_n1 + i_n2] = sum % 10; 
	  
	            i_n2++; 
	        } 
	        if (carry > 0) 
	            result[i_n1 + i_n2] += carry; 
	        i_n1++; 
	    } 
	    int i = result.size() - 1; 
	    while (i>=0 && result[i] == 0) 
	    i--; 
	    if (i == -1) 
	    s="0";
	      string temp="";
	    while (i >= 0) {
	    	temp = to_string(result[i--]);
	    	s+=temp;
		}
	  	if(neg==1) // answer is negative
	  	{
	  		answer+="-";
	  		answer+=s;
		}
		else
		{
			answer=s;
		}
		ans.s= answer;
	    return ans;
	}
	
	bigint operator = (int x)
	{
		string temp = to_string(x);
		s=temp;
		return *this;
	}
};
	

int main()
{
	/*	bigint x,y,z,p,q,r;
		x.s="12345";
		y.s="13141";
		z.s="-12311";
		p = x+y+z;
		q= x-y+z;
		r = x*y-z;
		cout << p.s << " " << q.s << " " << r.s << endl; */
		int choose=0;
		cout <<"Example operations on bigint numbers" << endl; bigint a; bigint b; bigint c;
		a.s="undefined"; b.s="undefined";
		while(choose!=5)
		{
			cout <<"1.To input BigInt numbers\n2.To perform example addition\n3.To perform example subtraction\n4.To perform example multiplication\n5.To exit\n";
			cout <<"Current two variable values are " << a.s << " & " << b.s << endl;
			cin >> choose;
			switch(choose)
			{
				case 1: 
						cout <<"\nEnter the two numbers\n";
						cin >> a.s >> b.s;
						break;
				case 2: c=a+b;
						if(c.s.at(0)=='-' && c.s.at(1)=='-')
						cout << "\nAns is " << c.s.substr(2) << endl;
						else
						cout << "\nAns is " << c.s << endl;
						break;
				case 3: c = a-b;
						if(c.s.at(0)=='-' && c.s.at(1)=='-')
						cout << "\nAns is " << c.s.substr(2) << endl;
						else
						cout << "\nAns is " << c.s << endl;
						break;
				case 4: c = a*b;
						if(c.s.at(0)=='-' && c.s.at(1)=='-')
						cout << "\nAns is " << c.s.substr(2) << endl;
						else
						cout << "\nAns is " << c.s << endl;
						break;
			}
		}
	
}
