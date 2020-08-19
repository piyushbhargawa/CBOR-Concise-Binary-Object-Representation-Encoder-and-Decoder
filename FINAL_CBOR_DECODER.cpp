#include<iostream>
#include<stack>
#include<string.h>
#include <sstream> 
#include<vector>
#include<queue>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>

using namespace std;

char strToChar(string data) {				//binary to character conversion
	bitset<8> temp(data);
    return temp.to_ulong();
}

int binaryToDecimal(int n)                          //binary to decimal
{ 
    int num = n; 
    int dec_value = 0; 
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
    int temp = num; 
    while (temp) { 
        int last_digit = temp % 10; 
        temp = temp / 10; 
        dec_value += last_digit * base; 
        base = base * 2; 
    } 
    return dec_value; 
} 

int stringtoint(string str)                         //convert string to integer
{
stringstream geek(str);
    int x1 = 0; 
    geek >> x1;
    return x1;
}

string inttostring(int val)                         //convert integer to string
{
ostringstream str1; 
    str1 << val; 
    string geek = str1.str();
    return geek;
}

int hextodec(char *num)                                //hex to decimal
{
	int i, r, len, hex = 0;
	len = strlen(num);
    for (i = 0; num[i] != '\0'; i++)
    {
        len--;
        if(num[i] >= '0' && num[i] <= '9')
            r = num[i] - 48;
        else if(num[i] >= 'a' && num[i] <= 'f')
                r = num[i] - 87;
        else if(num[i] >= 'A' && num[i] <= 'F')
                    r = num[i] - 55;
        hex += r * pow(16,len);
    }
    return hex;
}

string decimaltobin(long int n)	//decimal to binary
{	
int binaryNum[32]; 
    int i = 0;
    string s="";
    while (n > 0) { 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    for (int j = i - 1; j >= 0; j--) 
    {
   string geek = inttostring(binaryNum[j]);
        s+=geek;
}
int ss=s.size();
string m="";
for(int i=0;i<8-ss;i++)
{
m+="0";
}
    return m+s;
}

string htob(string str)
{
	string j="";
	int value;
	int len=str.size();
	for(int i=0;str[i]!='\0';i=i+2)
	{
		string part=str.substr(i,2);
		istringstream ost(part);
		ost >> hex >> value;
		bitset<8> bits(value);
		string binaryString (bits.to_string());
		j=j+binaryString;
	}
	return j;
}

int main()
{
	int flag,size,m=-1,a=-1;
	vector<int> vmap,varr;
	stack<char> st;
	//string str="83 01 02 03";
	//string str="A2 01 02 02 82 01 64 612E6163";
	//string str="81 A2 01 02 02 83 01 62 6161 01";
	//string str="84 01 83 41 00 02 01 82 83 0A 01 01 83 02 01 A1 01 01 A0";
	//string str="98 18 01 01 02 02 03 03 04 04 78 18 666666 05 06 06 07 07 08 08 09 09 0A 0A 0B 0B 0C 01";
	//string str="A1 82 A0 83 A0 80 A0 01";
	//string str="84 01 83 41 00 0B 01 82 83 01 01 19 0800 83 02 01 A1 00 F5 A0";
	//string str="81 81 81 A1 78 18 6F72672E69736F2E31383031332D352E323031392E6D646C 01"; 
	string str="A2 67 56657273696F6E 63 312E30 69 446F63756D656E7473 A1 78 18 6F72672E69736F2E31383031332D352E323031392E6D646C A3 6C 4973737565725369676E6564 A2 6A 4E616D65537061636573 A2 74 6F72672E69736F2E31383031332D352E32303139 84 84 01 41 00 6A 676976656E5F6E616D65 63 546F6D 84 02 41 00 68 706F727472616974 41 00 84 05 41 00 6D 6D676D745F76616C6964697479 70 3230313930323238543030303030305A 84 03 41 00 6F 6D676D745F6E657874757064617465 70 3230313930323234543030303030305A 6C 6F72672E61616D76612E7573 81 84 17 41 00 66 5265616C4944 F5 6A 49737375657241757468 84 41 00 A0 41 00 41 00 6C 4465766963655369676E6564 A2 6A 4E616D65537061636573 A0 6A 44657669636541757468 A1 63 4D4143 84 41 00 A0 F6 41 00 66 4572726F7273 A1 74 6F72672E69736F2E31383031332D352E32303139 81 A1 6F 646F63756D656E745F6E756D626572 16";
	//string str="A2 67 56657273696F6E 63 312E30 6B 446F635265717565737473 81 A1 6C 4974656D7352657175657374 A2 67 446F6354797065 78 18 6F72672E69736F2E31383031332D352E323031392E6D646C 6A 4E616D65537061636573 A2 74 6F72672E69736F2E31383031332D352E32303139 85 6A 676976656E5F6E616D65 6F 646F63756D656E745F6E756D626572 68 706F727472616974 6D 6D676D745F76616C6964697479 6F 6D676D745F6E657874757064617465 6C 6F72672E61616D76612E7573 81 66 5265616C4944";
	//string str="A3 A1 01 01 83 01 81 02 03 01 61 61 83 01 02 81 03 A2 62 6161 62 6161 81 01 81 62 6262";
	//string str="81 A3 A1 01 01 83 01 81 02 03 01 61 61 83 01 02 81 03 A2 62 6161 62 6161 81 01 81 62 6262";
	//string str="A2 01 A1 61 61 01 02 82 01 62 6161";
	//string str="A2 A1 01 01 83 01 81 02 03 01 61 61";
	//string str="A1 63 616161 3";
	for(int i=0;str[i]!='\0';i++) 
    {
    	string s="";
    	while(str[i]!=' '&& str[i]!='\0')
		{
			s+=str[i];
			i++;
		}
		if(str[i]=='\0')
			i--;
		int len=s.size();
		char char_array[len + 1]; 
		strcpy(char_array, s.c_str()); 
		string bin=decimaltobin(hextodec(char_array));
		//string bin=htob(s);
		if(bin[0]=='1' && bin[1]=='0' && bin[2]=='1')
		{
			if(m>=0 && st.top()=='{' && vmap[m]%2!=0)
				cout<<":";
			cout<<"{";
			if(!varr.empty() && st.top()=='[')
			{
				varr[a]--;
			}
			st.push('{');
			m++;
			bin[0]='0';
			bin[2]='0';
			size=binaryToDecimal(stringtoint(bin));
			if(size>23)
    		{
    			i++;
				string s="";
    			while(str[i]!=' '&& str[i]!='\0')
				{
					s+=str[i];
					i++;
				}
				if(str[i]=='\0')
					i--;
				int len=s.size();
				char char_array[len + 1]; 
				strcpy(char_array, s.c_str()); 
				size=hextodec(char_array);
			}
			flag=size*2;
			vmap.push_back(flag);
			if(m>=0 && vmap[m]%2==0 && vmap[m]>0 && vmap[m]!=flag)
					cout<<",";
		}
		else if(bin[0]=='1' && bin[1]=='0' && bin[2]=='0')
		{
			if(m>=0 && st.top()=='{' && vmap[m]%2!=0)
			{
				cout<<":";
			}
			bin[0]='0';
    		a++;
    		cout<<"[";
    		if(!vmap.empty() && st.top()=='{')
			{
				vmap[m]--;
			}
    		st.push('[');
    		int size=binaryToDecimal(stringtoint(bin));
    		if(size>23)
    		{
    			i++;
				string s="";
    			while(str[i]!=' '&& str[i]!='\0')
				{
					s+=str[i];
					i++;
				}
				if(str[i]=='\0')
					i--;
				int len=s.size();
				char char_array[len + 1]; 
				strcpy(char_array, s.c_str()); 
				size=hextodec(char_array);	
			}
    		varr.push_back(size);
		}
		else if(bin[0]=='0' && bin[1]=='0' && bin[2]=='0')
		{
			if(st.top()=='{')
			{
				if(vmap[m]%2!=0)
					cout<<":";
			    vmap[m]--;	
			    if(binaryToDecimal(stringtoint(bin))>23)
			    {
			    	i++;
					string s="";
    				while(str[i]!=' '&& str[i]!='\0')
					{
						s+=str[i];
						i++;
					}
					if(str[i]=='\0')
						i--;
					int len=s.size();
					char char_array[len + 1]; 
					strcpy(char_array, s.c_str()); 
					cout<<hextodec(char_array);
				}
				else
					cout<<binaryToDecimal(stringtoint(bin));
			    if(m>=0 && vmap[m]%2==0 && vmap[m]>0)
					cout<<",";
			}
			else
			{
				if(binaryToDecimal(stringtoint(bin))>23)
			    {
			    	i++;
					string s="";
    				while(str[i]!=' '&& str[i]!='\0')
					{
						s+=str[i];
						i++;
					}
					if(str[i]=='\0')
						i--;
					int len=s.size();
					char char_array[len + 1]; 
					strcpy(char_array, s.c_str()); 
					cout<<hextodec(char_array);
				}
				else
					cout<<binaryToDecimal(stringtoint(bin));
    	    	varr[a]--;
				if(a>=0 && varr[a]>0)	
    	    		cout<<",";
			}
		}
		else if(bin[0]=='0' && bin[1]=='1' && bin[2]=='1')
		{
			
			if(st.top()=='{')
			{
				if(vmap[m]%2!=0)
					cout<<":";
			    vmap[m]--;
		    }
		    else
		    {
		    	varr[a]--;
			}
			bin[1]='0';
			bin[2]='0';
			if(binaryToDecimal(stringtoint(bin))>23)
			{
				i++;
				string s="";
    			while(str[i]!=' '&& str[i]!='\0')
				{
					s+=str[i];
					i++;
				}
				if(str[i]=='\0')
					i--;
			}
			i++;
			string s="";
    		while(str[i]!=' '&& str[i]!='\0')
			{
				s+=str[i];
				i++;
			}
			if(str[i]=='\0')
				i--;
			int len=s.size();
			char char_array[len+1];
			strcpy(char_array, s.c_str()); 
			//string bin=decimaltobin(hextodec(char_array));
			string bin=htob(s);
			int ss=bin.size();
			string j="";
			if(ss<8)
				ss=(8-ss);
			else
				ss=8-(ss%8);
			for(int i=0;i<ss;i++)
				j+="0";
			bin=j+bin;
			//cout<<endl<<bin<<endl;
			j="";
			for(int x=0;x<bin.length();x+=8)
			{
				string part = bin.substr(x,8);
				j=j+strToChar(part);
			}
			cout<<'"'<<j<<'"';
			if(m>=0 && vmap[m]%2==0 && vmap[m]>0)
				cout<<",";
			if(a>=0 && varr[a]>0)	
    	    		cout<<",";	
		}
		else if(bin[0]=='0' && bin[1]=='1' && bin[2]=='0')
		{
			if(st.top()=='{')
			{
				if(vmap[m]%2!=0)
					cout<<":";
			    vmap[m]--;
		    }
		    else
		    {
		    	varr[a]--;
			}
			bin[1]='0';
			if(binaryToDecimal(stringtoint(bin))>23)
			{
				i++;
				string s="";
    			while(str[i]!=' '&& str[i]!='\0')
				{
					s+=str[i];
					i++;
				}
				if(str[i]=='\0')
					i--;
			}
			i++;
			string s="";
    		while(str[i]!=' '&& str[i]!='\0')
			{
				s+=str[i];
				i++;
			}
			if(str[i]=='\0')
				i--;
			int len=s.size();
			if(s=="00")
			{
				cout<<"h"<<"'"<<"00"<<"'";		
			}
			else
			{
				char char_array[len + 1]; 
				strcpy(char_array, s.c_str()); 
				//string bin=decimaltobin(hextodec(char_array));
				string bin=htob(s);
				int ss=bin.size();
				string j="";
				if(ss<8)
					ss=(8-ss);
				else
					ss=8-(ss%8);
				for(int i=0;i<ss;i++)
					j+="0";
				bin=j+bin;
				j="";
				for(int x=0;x<bin.length();x+=8)
				{
					string part = bin.substr(x,8);
					j=j+strToChar(part);
				}
				cout<<"h"<<"'"<<j<<"'";
			}
			if(m>=0 && vmap[m]%2==0 && vmap[m]>0)
				cout<<",";
			if(a>=0 && varr[a]>0)	
    	    	cout<<",";	
		}
		else if(bin[0]=='1' && bin[1]=='1' && bin[2]=='1')
		{
			if(st.top()=='{')
			{
				if(vmap[m]%2!=0)
					cout<<":";
			    vmap[m]--;	
			}
			else
				varr[a]--;
			if(bin=="11110101")
				cout<<"true";
			else if(bin=="11110100")
				cout<<"false";
			else if(bin=="11110110")
				cout<<"null";
			if(m>=0 && vmap[m]%2==0 && vmap[m]>0)
				cout<<",";
			if(a>=0 && varr[a]>0)	
    	    		cout<<",";		
		}			
		l1:while(a>=0  && varr[a]==0 && st.top()=='[')
		{
			cout<<"]";
			st.pop();
			varr.pop_back();
			a--;
			if(a>=0 && varr[a]!=0)
				varr[a]--;
			if(m>=0 && vmap[m]%2==0 && vmap[m]>0 && st.top()=='{')
				cout<<",";
			if(a>=0 && varr[a]>0 && st.top()=='[')	
    	    	cout<<",";
    		//if(m>=0 && st.top()=='{' && vmap[m]%2!=0)
			//	cout<<":";
		}
		while(m>=0  && vmap[m]==0 && st.top()=='{')
		{
			cout<<"}";
			st.pop();
			vmap.pop_back();
			m--;
			if(m>=0)
				vmap[m]--;
			if(m>=0 && vmap[m]%2==0 && st.top()=='{')
					cout<<",";
			if(a>=0 && varr[a]>0 && st.top()=='[')	
    	    	cout<<",";		
			//if(m>=0 && st.top()=='{' && vmap[m]%2!=0)
			//	cout<<":";
			goto l1;
		}	
		//cout<<endl;
	}
	for(int i=0;i<=a;i++)
       	cout<<"]";
//	for(int i=0;i<=m;i++)
  //     	cout<<"}";
	return 0;
}
