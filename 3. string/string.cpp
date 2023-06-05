#include <iostream>
#include <string.h>
using namespace std;

int validate(char s[]){
	for(int i=0;s[i]!='\0';i++){
		if(!(s[i]>96&&s[i]<123)&&!(s[i]>64&&s[i]<91)&&!(s[i]>=48&&s[i]<=57))
			return 0;
	}
	return 1;
}
char * change_case(char s[]){
	int i=0;
	char * temp=new char[0];
	cout<<endl<<"Changing case: ";
	for(;s[i]!='\0';i++){
		if(s[i]>96&&s[i]<123)
			temp[i]=s[i]-32;
		else if(s[i]>64&&s[i]<91)
			temp[i]+=32;
		// else{
		// 			cout<<endl<<"Invalid Input, please try again"<<endl;
		// 	gets(s);
		// 	i=-1;
		// }
	}
	cout<<temp;
	return temp;
}
char* reverse(char s[],int l){
	char *s2=new char[l];
	char temp;
	for(int i=0,j=l-1;j>=0;i++,j--){

			s2[i]=s[j];}
	cout<<endl<<l;
	cout<<endl<<s2;
	cout<<endl;
	return s2;
	//free(s1);
}

void palindrome(char s[]){
	char *temp=reverse(s,strlen(s));

	int i=0;
	for(;temp[i]!='\0'&&s[i]!='\0';i++){
		if(temp[i]!=s[i]){
			break;
		}
	}

	if(s[i]==temp[i])
		cout<<endl<<"palindrome.";
	else
		cout<<endl<<"not a palindrome";

}
//racecar
void duplicate(char s[],int l){
	int dl=0;
	int cl=0;
	//char *p=&s[0];
	int c=0;
	int *count=new int[dl];
	char *d=new char[dl];
	for(int i=0;s[i]!='\0';i++){
		c=1;
		for(int j=i+1;s[j]!='\0';j++){
			if(s[i]==s[j]&&s[i]!=' '){
				c++;
				if(d[dl-1]!=s[i]){
					d[dl++]=s[j];
					
				}
				
				
			}
			//cout<<endl<<c;

			
		}
		if(c>1)
			count[cl++]=c;
		
			

	}
	//cout<<endl<<count[0];
	//cout<<endl<<dl;
	for(int i=0;i<dl;i++){
		cout<<endl<<d[i]<<" - "<<count[i];
		
	}
	delete []count;
	delete []d;
}

void h_map_dupli(char s[]){
	int H[26]={0};
	int j=0;
	while(s[j]!='\0'){
		if(s[j]>=97&&s[j]<123)
			s[j]-=32;
		else
			continue;
		j++;
	}
	//cout<<endl<<s;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>=65&&s[i]<91)
			H[s[i]-65]+=1;
	}


	for(int i=0;i<26;i++){
		if(H[i]>1)
			cout<<endl<<(char)(i+65)<<" - "<<H[i];
	}
}

void bitwise_dupli(char s[]){
	int H=0,x=0;
	for(int i=0;s[i]!='\0';i++){
		x=1;
		x=x<<(s[i]-97);
		if(x&H){
			
			cout<<endl<<s[i];

		}
		else
			H=H|x;
	}
}

void check_anagram(char s[],char s2[]){
	//cout<<endl<<s<<" and "<<s2;

	if(strlen(s)==strlen(s2)){
		int H[26]={0};
		int j=0;
		while(s2[j]!='\0'){
			if(s2[j]>=97&&s2[j]<123){
							s2[j]-=32;}
							else if(s[j]>=97&&s[j]<123){
							s[j]-=32;}
			else{
							continue;}
			j++;
		}	
		// cout<<endl<<s<<" - "<<s2;
		for(int i=0;s[i]!='\0';i++){
					H[s[i]-65]+=1;
					
				}
				int i=0;
				for(;s2[i]!='\0';i++){
				
					H[s2[i]-65]-=1;

					if(H[s2[i]-65]<0){
						cout<<endl<<"Not anagram";
						break;
					}
					
				}
					if(s[i]=='\0'){
						cout<<endl<<"Anagram";
					}
		
		//cout<<endl<<c;
		
	}
	else
		cout<<endl<<"Not an anagram";
}
int main(){
	//Your code here
	char s[]="";
	
	gets(s);

	char *sp;
	sp=change_case(s);
	
	
	
	int v=0,c=0,w=0;
	int i=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]>64&&s[i]<91||s[i]>96&&s[i]<123){
					if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
						v++;
					}
					else
						c++;
				}

		if(s[i]==' '&&s[i-1]!=' ')
			w++;
		// else{
		// 			cout<<endl<<"Invalid Input, please try again"<<endl;
		// 	gets(s);
		// 	i=-1;
		// }
	}
	int l=i;
	cout<<endl<<"Length of string is: "<<i;
	cout<<endl<<"Consonants present are: "<<c;
	cout<<endl<<"Vowels present are: "<<v;
	cout<<endl<<"Words are: "<<w+1;

	if(validate(s))
		cout<<endl<<"Valid"; 
	else
		cout<<endl<<"invalid";
	
	// cout<<endl<<"Reverse of string is: ";
	// char *temp=reverse(s,l);

	char s2[]="";

	//cout<<endl<<"Enter another string to check palindrome: ";
	gets(s2);

	//palindrome(s2);
	
	//cout<<endl<<"The duplicates are:- ";
	//duplicate(s2,strlen(s2));
	//h_map_dupli(s2);
	//bitwise_dupli(s2);
	check_anagram(s,s2);

	cout<<endl;
	return 0;
}