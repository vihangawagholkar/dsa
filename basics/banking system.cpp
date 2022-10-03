#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

class myexception: public exception{


};
class account{
public:	
	int acc_no;
	string f_name,l_name;
	long long int balance;

public:
	account(string f_n="",string l_n="",int an=0,int b=0){
		f_name=f_n;
		l_name=l_n;
		acc_no=an;
		balance=b;
	}
	int getacc_no(){
		return acc_no;
	}
	int getbalance(){
		return balance;
	}

	void plusbal(int dep){
		balance+=dep;
	}

	void minusbal(int with){
		balance-=with;
	}
	friend ofstream &operator<<(ofstream &ofs,account &a);
	friend ifstream &operator>>(ifstream &ifs,account &a);
	friend ostream &operator<<(ostream &os,account &a);
	~account(){
		

	}
};

ofstream &operator <<(ofstream &ofs,account &a){
	//cout<<endl<<"HELL";
	ofs<<a.acc_no<<endl<<a.f_name<<endl<<a.l_name<<endl<<a.balance<<endl;
	return ofs;
}

ifstream &operator >>(ifstream &ifs,account &a){
	//cout<<endl<<"In ifstream";
	if(ifs)
	ifs>>a.acc_no>>a.f_name>>a.l_name>>a.balance;
	return ifs;
}

ostream &operator<<(ostream &os,account &a){
	os<<a.acc_no<<endl<<a.f_name<<endl<<a.l_name<<endl<<a.balance<<endl;
	return os;
}

class deposit:public account{
private:
	
	int dep;
	public: 
		deposit(int a){
		//constructor
			//cout<<"In deposit";
			account acc;
					//acc->setbalance(dep);
					ofstream ofs("Temp.txt");
					ifstream ifs("Banking.txt");
					while(ifs>>acc){
					
					//cout<<"In while";
					
					if(a==acc.getacc_no()){
						cout<<endl<<" the amount you want to deposit: ";
						cin>>dep;
						acc.plusbal(dep);
					}
					
					ofs<<acc;
				}
				remove("Banking.txt");
				rename("Temp.txt","Banking.txt");
				ifs.close();
				ofs.close();
				}
			
		
		


};

class withdraw: public account{
private:
	int with;
public:
	withdraw(int a){
		account acc;
					//acc->setbalance(dep);
					ofstream ofs("Temp.txt");
					ifstream ifs("Banking.txt");
					while(ifs>>acc){
					
					//cout<<"In while";
					
					if(a==acc.getacc_no()){
						cout<<endl<<"Enter the amount you want to withdraw: ";

						cin>>with;
						// cin.clear();
						// cin.ignore(numeric_limits);
						acc.minusbal(with);
					}
					
					ofs<<acc;
				}
				remove("Banking.txt");
				rename("Temp.txt","Banking.txt");
				ifs.close();
				ofs.close();
	}
};
//int choice=0;

int main(){
	cout<<endl<<"Welcome to my Banking System!!!";
	//Your code here
	//vector <account *> acc;
	int c=1;
	while(c){
		cout<<endl<<"1. Open an Account";
		cout<<endl<<"2. Balance Check";
		cout<<endl<<"3. Deposit";
		cout<<endl<<"4. Withdraw";
		cout<<endl<<"5. Close Account";
		cout<<endl<<"6. Show all accounts";
		cout<<endl<<"7. Quit";
		cout<<endl<<"Enter your choice: ";
		int choice;
		cin>>choice;
		switch(choice){
			case 1:{
						int an,balance;
						
						string str1,str;
						cout<<endl<<"Enter account no.: ";
						cin>>an;
						cin.ignore();
						cout<<endl<<"Enter the first name of account holder: ";
						getline(cin,str);
						//cin.ignore();
						cout<<endl<<"Enter the last name of account holder: ";
						getline(cin,str1);
						cout<<endl<<"Enter the balance: ";
						cin>>balance;
						//cout<<endl<<"HELL";
						account acc(str,str1,an,balance);
						//cout<<endl<<"HELL";
						ofstream ofs("Banking.txt",ios :: app);
				
						ofs<<acc;
						ofs.close();
						break;
			}			

			case 2:{
				int a;
				cout<<endl<<"Enter your account no.: ";
				cin>>a;
				account acc;

				ifstream ifs("Banking.txt");
				while(ifs>>acc){
					
					if(a==acc.getacc_no()){
						cout<<endl<<"Your Balance is: "<<acc.getbalance();
					}
				}
				ifs.close();
				break;
			}

			case 3:{
				int a;
				cout<<endl<<"Enter your account no.: ";
				cin>>a;
				
				try{
					deposit d(a);
				}
				catch(myexception e){
					cout<<endl<<"TYPE A NO. STUPID!!!";
				}
				//d.setbalance();
				break;
			}

			case 4:{
				int a;
				cout<<endl<<"Enter your account no.: ";
				cin>>a;
				withdraw w(a);
				break;
			}
			case 5:{
				cout<<"Enter the account no.: ";
				int a;
				cin>>a;
				account acc;
				string s;
				ifstream ifs("Banking.txt");
				ofstream ofs("Temp.txt");
			
				while(ifs>>acc){
					//ifs>>acc;
					if(a==acc.getacc_no()){
						cout<<endl<<"Are you sure (y/n)?";
						cin>>s;
						if(s.rfind("y", 0) == 0||s.rfind("Y",0)==0){
							cout<<endl<<"Record is deleted";
							acc.~account();
						}
						continue;
						
					}
					ofs<<acc;
				}
				remove("Banking.txt");
				rename("Temp.txt","Banking.txt");
				ifs.close();
				ofs.close();
		 	break;
			}
			case 6:{
						cout<<endl<<"The accounts in this banking system are:-"<<endl;
						account acc;
						
						ifstream ifs("Banking.txt");
						while(ifs>>acc){
							// ifs>>acc;
							cout<<acc<<endl;
						}
						ifs.close();
						break;
			
			}			
			case 7:{
						c=0;
						cout<<endl<<"Thank you for using my Banking System.";
						break;
			}

			default:{
			cout<<endl<<"Invalid input please try again!";
			break;
			}
		}
	}
	return 0;
}