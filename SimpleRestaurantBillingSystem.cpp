#include<iostream>
using namespace std;

class basicInfo {
protected:
    char name[30];
    int empId;
    char gender;

public:
    void getBasicInfo(void)
    {
        cout << "Enter Name: ";
        cin.getline(name, 30);
        cout << "Enter Emp. Id: ";
        cin >> empId;
        cout << "Enter Gender: ";
        cin >> gender;
    }
};

// Base Class - deptInfo
class deptInfo {
protected:
    char deptName[30];
    char assignedWork[30];
    

public:
    void getDeptInfo(void)
    {
        cout << "Enter Department Name: ";
        cin.ignore(1);
        cin.getline(deptName, 30);
        cout << "Enter assigned work: ";
        fflush(stdin);
        cin.getline(assignedWork, 30);
        
    }
};

// final class (Derived Class)- employee
class employee : private basicInfo, private deptInfo {
public:
    void getEmployeeInfo(void)
    {
        cout << "Enter employee's basic info: " << endl;
        //call getBasicInfo() of class basicInfo
        getBasicInfo(); //calling of public member function
        cout << "Enter employee's department info: " << endl;
        //call getDeptInfo() of class deptInfo
        getDeptInfo(); //calling of public member function
    }
    void printEmployeeInfo(void)
    {
        cout << "Employee's Information is: " << endl;
        cout << "Basic Information...:" << endl;
        cout << "Name: " << name << endl; //accessing protected data
        cout << "Employee ID: " << empId << endl; //accessing protected data
        cout << "Gender: " << gender << endl
             << endl; //accessing protected data

        cout << "Department Information...:" << endl;
        cout << "Department Name: " << deptName << endl; //accessing protected data
        cout << "Assigned Work: " << assignedWork << endl; //accessing protected data
	  cout << "\n\n-----------------------------\n\n";
    }
};



double getUnitprice(int itemCode);

int main(){
employee emp;
    
    emp.getEmployeeInfo();

  double invoice[10][4];
  int i=0; char more; char date[100];

  cout << "\n\n********* Here are the Item prices for your information********** \n\nItem code\tUnitPrice\n\nPizza\t1\t100\nBurger\t2\t200\nBiryani\t3\t300\nInvalidCode\t0\n\n";
  cout << "Enter the date: ";
  cin >> date;
  
  do {
    cout << "\n\nItem code: ";
    cin >> invoice[i][0];
    cout << "Quantity : ";
    cin >> invoice[i][1];
    
    invoice[i][2] = getUnitprice(invoice[i][0]); 
    invoice[i][3] = invoice[i][1] * invoice[i][2]; 
    
    cout << "Do you have any other items to be entered next (y/n) ? ";
    cin >> more;
  
    i++;
  } while(more == 'y');
    
 
  cout << "\n\n-----------------------------\n\n";
  cout << "Date : " << date << "\n\n";
  cout<<"Pearl Restaurants Pvt. Ltd.\n\n\n";

  emp.printEmployeeInfo();
  cout << "ItemCode|Quantity|UnitPrice|TotalPrice\n\n";
  int tot=0;
  for(int k=0; k<i; k++)   
    
	{
		for(int l=0; l<4; l++) 
		{
		    cout << invoice[k][l]  << "\t\t\t";		   
		}
		cout << endl;
		tot = tot + invoice[k][3];
	}

  cout << "\n\nTotal : " << tot<<"\n\n";
  cout<<"Thank you!";
  cout << "\n\n-----------------------------\n\n\n";
  
  return 0;
}

double getUnitprice(int itemCode){
  double price;
  switch (itemCode)
  {
    case 1: price = 100;
      break; 
    case 2: price = 200;
      break;
    case 3: price = 300;
      break;
    default: price = 0;
      break;
  }
  return price;
}
