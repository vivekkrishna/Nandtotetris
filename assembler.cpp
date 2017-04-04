	#include<iostream>
	#include <string>
	#include <ctype.h>
	#include <cstdlib>
	#include <sstream>
//	#include <array>
	using namespace std;
	
	
	long ConvertToBinary(int n)
	{
		long sum=0;
		int dec=n,i=1,rem;
		do
	    {
	        rem=dec%2;
	        sum=sum + (i*rem);
	        dec=dec/2;
	        i=i*10;
	    }while(dec>0);
	    return sum;
	}
	
	string parse(string instruction){
		int arraylen;
		stringstream ss;
		string Str3;
		long destb,compb,jumpb;
		string destbi,compbi,jumpbi;
		string dest_codes[8] = {"\0", "M", "D", "MD", "A", "AM", "AD", "AMD"};
		string jump_codes[8] = {"\0", "JGT", "JEQ", "JGE", "JLT", "JNE", "JLE", "JMP"};
		string comp_codes[56] = { "0", "0101010",  "1", "0111111",  "-1", "0111010", "D", "0001100", 
                    "A", "0110000",  "!D", "0001101", "!A", "0110001", "-D", "0001111", 
                    "-A", "0110011", "D+1", "0011111","A+1", "0110111","D-1", "0001110", 
                    "A-1", "0110010","D+A", "0000010","D-A", "0010011","A-D", "0000111", 
                    "D&A", "0000000","D|A", "0010101",
                    
                    "M", "1110000",  "!M", "1110001",
                    "-M", "1110011",  "M+1", "1110111",
                    "M-1", "1110010","D+M", "1000010","D-M", "1010011","M-D", "1000111", 
                    "D&M", "1000000", "D|M", "1010101" };
        string jump,dest,comp;
        int i=0,c=0,j;
        int col=0;
        cout<<instruction.length()<<endl;
        do{
        	if(instruction[i]=='='){
        		cout<<"inside dest"<<endl;
        		dest=instruction.substr(0,i);

        		c=i+1;
			}else if(instruction[i]==';'){
				col=1;
				comp=instruction.substr(c,i-c);

        		c=i+1;
        		jump=instruction.substr(c);

			}else if(i==instruction.length()-1 && col==0){
				cout<<"in no col condition"<<endl;
				comp=instruction.substr(c);

			}
			
        	i++;
		}while(i<instruction.length());
        cout<<dest<<endl;
        cout<<comp<<endl;
        cout<<jump<<endl;
        arraylen=sizeof( dest_codes ) / sizeof( dest_codes[ 0 ] );
        for(i=0;i<arraylen;i++){
        	if(dest==dest_codes[i]){
        		destb=ConvertToBinary(i);
        		ss << destb;
				Str3 = ss.str();
				cout<<Str3.length()<<endl;
				for(i=Str3.length();i<3;i++)
				{
					Str3="0"+Str3;
				}
				destbi=Str3;
			}
		}
		ss.str(std::string());
		arraylen=sizeof( jump_codes ) / sizeof( jump_codes[ 0 ] );
		for(i=0;i<arraylen;i++){
        	if(jump==jump_codes[i]){
        		jumpb=ConvertToBinary(i);
        		cout<<"jumpb"<<jumpb<<endl;
        		ss << jumpb;
				Str3 = ss.str();
				cout<<Str3.length()<<endl;
				for(i=Str3.length();i<3;i++)
				{
					Str3="0"+Str3;
				}
				jumpbi=Str3;
			}
		}
		ss.str(std::string());
		arraylen=sizeof( comp_codes ) / sizeof( comp_codes[ 0 ] );
		for(i=0;i<arraylen;i=i+2){
        	if(comp==comp_codes[i]){
				compbi=comp_codes[i+1];
			}
		}
		cout<<destbi<<endl;
		cout<<jumpbi<<endl;
        return "111"+compbi+destbi+jumpbi;
	}
	
	int main(){
	string Str1, word, Str3 ;
	stringstream ss;
	char *strin;
	int addr,i=0;
	long bina;
	bool isNumber = true;
	Str1 = "MD=M+1;JMP";	//check M=M+1
	if(Str1[0]=='@'){	//address instruction
		word=Str1.substr(1,20 );
		//cout<<Str2<<"complete"<<endl;
		
		for(string::const_iterator k = word.begin(); k != word.end(); ++k)
	    	isNumber = isNumber&&isdigit(*k);	
		if(isNumber){
		
			//cout<<"number"<<endl;
			//convert decimal to binary of integer
			addr=atoi(word.c_str());
			//cout<<addr<<endl;
			bina=ConvertToBinary(addr);
			cout<<bina<<endl;
	
			ss << bina;
			Str3 = ss.str();
			cout<<Str3.length()<<endl;
			for(i=Str3.length();i<16;i++)
			{
				Str3="0"+Str3;
			}
			cout<<Str3<<endl;
		}
		else
			cout<<"label"<<endl;		
	}else{	//Compute instruction
		Str3=parse(Str1);
		cout<<"final"<<Str3<<endl;
	}
	}
