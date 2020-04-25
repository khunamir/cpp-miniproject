#include <iostream>                               
#include <cstring>
using namespace std;

struct services
{
	char name [40];
	double price;
};

void totalColl (double&, double);
void coll (char, services[], double&, double&, double&, double&, double&, double&, double&, double&, double&);
void Employee ( char&,double&, double&, double&, double&, double&, double&, double&, double&, double&, double&);
void Customer ( char&, double&, double&, double&, double&, double&, double&, double&, double&, double&, double&);
void serviceInit (services[]);

int main ()
{   
	double acoll = 0, bcoll = 0, ccoll = 0, dcoll = 0, ecoll = 0, fcoll = 0, gcoll = 0, hcoll = 0, icoll = 0;
	int answer;
	double collection=0;

	char program = 'Y';
	
	while (program == 'Y' || program == 'y')
	{		
	//Company Introduction
	cout<<"\n\n--------------MONDAIKAIKETSU-----------------\n"<<endl;
	cout<<"Welcome to MONDAIKAIKETSU Phone Service Center!"<<endl;
	cout<<"MONDAIKAIKETSU stands for problem solver in Japanese."<<endl;
	cout<<"Our company, consisting of many experts in the"<<endl;
	cout<<"Phone Servicing Industry are ready to solve"<<endl;
	cout<<"whatever problem that is occuring on your phone."<<endl;
	cout<<"\n---------------------------------------------\n"<<endl;
	cout<<"Are you a Customer or an Employee? [ 1: Customer 2: Employee] = ";
	cin>>answer;
		
	if(answer==1)
	   Customer(program,collection, acoll,bcoll,ccoll,dcoll,ecoll,fcoll,gcoll,hcoll,icoll);
    else if (answer==2)
       Employee(program,collection,acoll,bcoll,ccoll,dcoll,ecoll,fcoll,gcoll,hcoll,icoll);
       
    else
       cout<<"Invalid input!"<<endl;
	}
       cout<<"\n\nThank You for using our service. See you again!"<<endl;
}

void Employee(char& program,double& collection, double& acoll,double& bcoll,double& ccoll,double& dcoll,double& ecoll,double& fcoll,double& gcoll,double& hcoll,double& icoll)
{
	char code;
	double price;
	double finalPrice;
	char name [40];
	char password [20]; 
	
	cin.ignore();
	cout<<"Enter name = ";
	cin.getline(name,40);
	cout<<"Enter employee password = ";
	cin.getline(password,20);
	
	if (strcmp(password,"mondemp001")==0)
	{
	   cout<<"\n--------------EMPLOYEE-----------------\n"<<endl;
		
	   cout<<"Today's total collection = RM "<<collection<<endl;
	   cout<<"[a] = RM "<<acoll<<endl;
	   cout<<"[b] = RM "<<bcoll<<endl;
	   cout<<"[c] = RM "<<ccoll<<endl;
	   cout<<"[d] = RM "<<dcoll<<endl;
	   cout<<"[e] = RM "<<ecoll<<endl;
	   cout<<"[f] = RM "<<fcoll<<endl;
	   cout<<"[g] = RM "<<gcoll<<endl;
	   cout<<"[h] = RM "<<hcoll<<endl;
	   cout<<"[i] = RM "<<icoll<<endl; 
	   
	}
	   
	else
	   cout<<"Invalid password!"<<endl;
	   
	cout<<"Use program again? [Enter Y to use again or any other character to stop] = ";
	cin>>program;
}

void Customer ( char& program, double& collection, double& acoll,double& bcoll,double& ccoll,double& dcoll,double& ecoll,double& fcoll,double& gcoll,double& hcoll,double& icoll)
{
	//Variable declaration
	int count=0;
	int code;
	char answer [10];
	double price;
	double discount;
	double totalPriceDiscount;
	double finalPrice;
	double totalPrice = 0.00;
	services serv[9];
	serviceInit (serv);	
	
	cout<<"\n--------------CUSTOMER-----------------\n"<<endl;
	
	//Services Offering
	cout<<"SCREEN CRACK? OVERCHARGED BATTERY?"<<endl;
	cout<<"No worries, we have the solution.\n"<<endl;
	cout<<"Here are some of the services we offer :\n"<<endl;
	
	cout<<"[1]"<<serv[0].name<<"\t\t\t\t : RM 10.00"<<endl;
	cout<<"[2]"<<serv[1].name<<"\t\t : RM 50.00"<<endl;
	cout<<"[3]"<<serv[2].name<<"\t\t\t\t : RM 30.00"<<endl;
	cout<<"[4]"<<serv[3].name<<"\t\t\t : RM 10.00"<<endl;
	cout<<"[5]"<<serv[4].name<<"\t\t\t : RM 15.00"<<endl;
	cout<<"[6]"<<serv[5].name<<"\t\t : RM 30.00"<<endl;
	cout<<"[7]"<<serv[6].name<<"\t : RM 15.00"<<endl;
	cout<<"[8]"<<serv[7].name<<"\t : RM 20.00"<<endl;
	cout<<"[9]"<<serv[8].name<<"\t\t\t\t : RM 10.00"<<endl;
	
	cout<<"\nDiscount 20% are given for total services more than RM 100\n"<<endl;

	
	do
	{
		cout<<"Enter code of service (1/2/3 and so on) = ";
		cin>>code;
				   
		totalPrice = totalPrice + serv[code-1].price;
		coll (code, serv,acoll,bcoll,ccoll,dcoll,ecoll,fcoll,gcoll,hcoll,icoll);
		   
		cout<<"Current price = RM "<<totalPrice<<endl;		
		cout<<"Any other services to add? [Enter Yes to add service] = ";
		cin.ignore();
		cin.getline(answer,10); //Repeat process if user wants to add a service
		cout<<"\n";
		count++; //To calculate amount of services
	
	}   while (strcmpi(answer,"yes")==0);
	
    //Billing information
	cout<<"\n------------BILLING INFORMATION--------------\n"<<endl;
	cout<<"Amount of services = "<<count<<endl;
	cout<<"Total price = RM "<<totalPrice<<endl;	
			
    //Discount calculation
	if (totalPrice > 100.00)
	{ 
		discount = totalPrice * 0.2;
	   	cout<<"Discount = RM "<<discount<<endl; 
	}
	
	if (discount > 0)
	{
		totalPriceDiscount = totalPrice - discount;
		cout<<"Total price after discount = RM "<<totalPriceDiscount<<endl;
	}	
	
	else
		totalPriceDiscount = totalPrice;
	
	finalPrice = totalPriceDiscount * 1.06;
	cout<<"Final price including 6% SST = RM "<<finalPrice<<endl; 
	totalColl (collection, finalPrice);
	
	cout<<"Use program again? [Enter Y to use again or any other character to stop] = ";
	cin>>program;
	
	system("cls");

}


void serviceInit (services serv[])
{
	strcpy(serv[0].name,"Crack Screen Repair");
	strcpy(serv[1].name,"Overcharged Battery Replacement");
	strcpy(serv[2].name,"Camera Repair");
	strcpy(serv[3].name,"Broken Buttons Replacement");
	strcpy(serv[4].name,"Speaker or Mic Replacement");
	strcpy(serv[5].name,"Unresponsive Touchscreen Repair");
	strcpy(serv[6].name,"Unresponsive Fingerprint Scanner Repair");
	strcpy(serv[7].name,"Broken USB or Earphone Jack Replacement");
	strcpy(serv[8].name,"Water Damage Repair");
	
	serv[0].price = 10.00;
	serv[1].price = 50.00;
	serv[2].price = 30.00;
	serv[3].price = 10.00;
	serv[4].price = 15.00;
	serv[5].price = 30.00;
	serv[6].price = 15.00;
	serv[7].price = 20.00;
	serv[8].price = 10.00;
	
}

void coll(char code, services serv[], double& acoll,double& bcoll,double& ccoll,double& dcoll,double& ecoll,double& fcoll,double& gcoll,double& hcoll,double& icoll)
{
    //Collection for each type of service
	if (code == 1)
	   acoll = acoll + serv[code-1].price;
	   
	else if (code == 2)
	   bcoll = bcoll + serv[code-1].price;
	   
	else if (code == 3)
	   ccoll = ccoll + serv[code-1].price;
	   
	else if (code == 4)
	   dcoll = dcoll + serv[code-1].price;
	   
	else if (code == 5)
	   ecoll = ecoll + serv[code-1].price;
	   
	else if (code == 6)
	   fcoll = fcoll + serv[code-1].price;
	   
	else if (code == 7)
	   gcoll = gcoll + serv[code-1].price;
	   
	else if (code == 8)
	   hcoll = hcoll + serv[code-1].price;
	   
	else if (code == 9)
	   icoll = icoll + serv[code-1].price;
	   
	else
	   cout<<"Invalid input"<<endl;        
}

void totalColl (double& collection, double finalPrice)
{
    //Total collection for all services
	collection = collection + finalPrice;
}
