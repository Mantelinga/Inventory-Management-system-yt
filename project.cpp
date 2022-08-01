#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
#include<ostream>
using namespace std;
// global varible for  total item entered
int productsub[100];
int prodcutsadd[100];
ofstream file;
ifstream ifile;
string filename;
int out;
float itemtotal;
string itemspurchased;
string date;
int productid;
int itemsnum;
int totalproducts;
int defaultamount;
int newamount;
int price[9];
int subproductsnum[100];
int productsnum[100];
int newproductsnum[100];
string products[100] = { "Milk", "Rice", " Sugar", " Butter", " Bread", " Meat","Fish", " Cereal","Candy" };

// function prototypes
 void displaystock();
//void defaultstock();
void items();
void search();
void exportfile();
void menu();
void addproducts();
void disstock();
void viewstock();
void updatestock();
void deleteproducts();
int main()
{
	char yes;
	system("cls");
	cout << " Inventory Management System program\n";
	cout << " Press Any key to proceed\n";
	cin >> yes;
	system("cls");
	menu();
	return 0;

}
// function for program menu
void menu() {
	int ch;
	cout << "Menu list\n";
	cout << "\n1.owner Menu\n";
	cout << "2.staff user Menu\n";
	cout << " 3.customer Menu\n";
	cout << "Enter your choice here:";
	cin >> ch;
	if (ch == 1)
	{
		system("cls");
		addproducts();

	}
	else if (ch == 2) {
		system("cls");
		items();

	}
	else if (ch == 3) {
		system("cls");
		cout << "what is Today's Date?\n";
		cout << "Enter Here:";
		cin.ignore();
		getline(cin, date);
		exportfile();
	}
	else if (ch == 4) {
		system("cls");
		displaystock();

	}
	else {
		system("cls");
		cout << "BYe Hope To See YOU Again:)";

	}

}
// function to export data to file for printing
void  exportfile() {
	char exit;
	int itembought;
	string filename;
	ofstream file;
	cout << "what would you want the recent  bill to be saved as?";
	cin >> filename;
	system("cls");
	file.open(string(filename + ".txt").c_str(), ios::out | ios::app);
	cout << "MilkID:0, RiceID:1, sugarID:2, ButterID:3,BreadID:4, MeatID:5, FishID:6,CerealID:7,CandyID:8\n";
	cout << "what was bought? Enter Product ID:";
	cin >> itembought;
	cout << "Writing to file..\n";
	cout << "About to finish..\n";
	file << " Product Bought:" << products[itembought] << "\n";
	file << "Amount to Pay:Rs" << price[itembought] << "\n";
	file << "Date:" << date << "\n";
	file << "\n Thank You  for doing purchase with us, Hope to see you  soon";
	cout << "\nDone! You can print out the bill now!";
	file.close();
	cout << "press any Key and <enter> to skip to menu";
	cin >> exit;
	if (exit != '/') {
		menu();
	}

}
// function to adding products to stock
void addproducts() {
	int choice;
	cout << "1. Add products to stock" << endl;
	cout << "2. Go to menu" << endl;
	cout << "3. Update stock" << endl;
	cout << "4. delete Stock" << endl;
	cout << "Enter here:";
	cin >> choice;
	if (choice == 1) {
		system("cls");
		for (int p = 0; p < 9; p++) {
			cout << "\n Enter Amount of " << products[p] << ":";
			cin >> productsnum[p];
			cout << "Enter price of " << products[p] << ":Rs";
			cin >> price[p];
		}
	}
	else if (choice == 2) {
		menu();

	}
	else if (choice == 3) {
		updatestock();
	}
	else if (choice == 4) {
		deleteproducts();
	}
	else {
		addproducts();
	}
	displaystock();
}
//Function for items the user enters
void items() {
	int itemsnum;
	char exit;
	cout << "ready to enter item(s) Purchased\n";
	cout << "Press 'e' & <enter> to skip to menu or any other key & <enter> to proceed\n\n";
	cin >> exit;
	if (exit == 'e') {
		menu();
	}
	else {
		cout << "MilkID:0, RiceID:1,SugarID:2, ButterID:3, BreadID:4, MeatID:5, FishID:6, CerealID:7, CandyID:8\n";
		cout << "Enter Id of item puechased:";
	}
	cin >> productid;
	if (productid == 0) {
		cout << "Enter the Amount of Milk:";
		cin >> productsub[0];
		subproductsnum[0] = productsnum[0] - productsub[0];
		items();
	}
	else if (productid == 1) {
		cout << "Enter the Amount of Rice:";
		cin >> productsub[1];
		subproductsnum[1] = productsnum[1] - productsub[1];
		items();
	}
	else if (productid == 2) {
		cout << "Enter the Amount of Sugar:";
		cin >> productsub[2];
		subproductsnum[2] = productsnum[2] - productsub[2];
		items();
	}
	else if (productid == 3) {
		cout << "Enter the Amount of Butter:";
		cin >> productsub[3];
		subproductsnum[3] = productsnum[3] - productsub[3];
		items();
	}
	else if (productid == 4) {
		cout << "Enter the Amount of Bread:";
		cin >> productsub[4];
		subproductsnum[4] = productsnum[4] - productsub[4];
		items();
	}
	else if (productid == 5) {
		cout << "Enter the Amount of Meat:";
		cin >> productsub[5];
		subproductsnum[5] = productsnum[5] - productsub[5];
		items();
	}
	else if (productid == 6) {
		cout << "Enter the Amount of Fish:";
		cin >> productsub[6];
		subproductsnum[6] = productsnum[6] - productsub[6];
		items();
	}
	else if (productid == 7) {
		cout << "Enter the Amount of Cereal:";
		cin >> productsub[7];
		subproductsnum[7] = productsnum[7] - productsub[7];
		items();
	}
	else if (productid == 8) {
		cout << "Enter the Amount of Candy:";
		cin >> productsub[8];
		subproductsnum[8] = productsnum[8] - productsub[8];
		items();
	}
	else {
		cout << "no products with that ID, try again!\n\n";
		items();
	}
}
void calculatestock() {
	for (productid = 0; productid < 9; productid++) {
		productsnum[productid] = productsnum[productid] + newproductsnum[productid];
		subproductsnum[productid] = newproductsnum[productid] - productsub[productid];
	}
}
void displaystock() {
	cout << "productID\t\t"
		<< "Products"
		<< "\t"
		<< "Num of Products"
		<< "\t\t"
		<< "New Num of Products"
		<< " \t Unit Price" << endl;
	for (productid = 0; productid < 9; productid++) {
		subproductsnum[productid] = productsnum[productid] - productsub[productid];
		productsnum[productid] = productsnum[productid] + newproductsnum[productid];
		cout << productid << "\t\t\t" << products[productid] << "\t\t\t" <<
			productsnum[productid] << "\t\t\t" << subproductsnum[productid] << "\t\t\t Rs" <<
			price[productid] << endl;

	}
	file.open("DefaultStock");
	cout << "productID\t\t"
		<< "Products"
		<< "\t"
		<< "Num of Products"
		<< "\t\t"
		<< "New Num of Products"
		<< " \t Unit Price" << endl;
	for (productid = 0; productid < 9; productid++) {
		file << productid << "\t\t\t" << products[productid] << "\t\t\t" <<
			productsnum[productid] << "\t\t\t" << subproductsnum[productid] << "\t\t\t Rs" <<
			price[productid] << endl;
	}
	cout << "\n Writing to file..\n";
	cout << "Done writing new stock to file...\n";
	cout << "your file is automatically saved as""defaultStock";
	int out;
	cout << "press any number to proceed";
	cin >> out;
	if (out != 0) {
		menu();
	}
}
void disstock()
{
	ifile.open("DefaultSTOCk");
	if (ifile.is_open())
	{
		string getcontent;
		while (getline(ifile, getcontent))
		{
			cout << getcontent << endl;
		}
	}
	int out;
	cout << "\n\npress any number to proceed";
	cin >> out;
	if (out != 0) {
		menu();
	}
}
void viewstock()
{
	ifile.open("DefaultSTOCk");
	if (ifile.is_open())
	{
		string getcontent;
		while (getline(ifile, getcontent))
		{
			cout << getcontent << endl;
		}
	}
	int product_menu;
	cout << "\n\npress any number to proceed";
	cin >> product_menu;
	if (product_menu != 0) {
		system("cls");
		addproducts();
	}
	file.close();
}

void updatestock()
{

}

void deleteproducts()
{
}

void search()
{
	int productid;
	char exit;
	cout << "press 'e' & <enter> to exit or & other key to proceed & <enter>" << endl;
	cin >> exit;
	if (exit != 'e') {
		cout << "MilkID:0, RiceID:1, sugarID:2, ButterID:3,BreadID:4, MeatID:5, FishID:6,CerealID:7,CandyID:8\n";
		cout << "what products information u want to see?Enter its ID here:";
		cin >> productid;
		if (productid == 0) {
			cout << "\t\tPRODUCT DETAILS\n";
			cout << "PRODUCT NAME:"
				<< products[0] << "\n";
			cout << " TOTAl UNIT IN STOCk :" << subproductsnum[0] << "\n";
			cout << "UNIT PRICE:" << price[0] << endl;
			cout << "press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
			cin >> exit;
			if (exit == 'e') {
				menu();
			}
			else if (exit == 's') {
				system("cls");
				search();
			}
		}
		else if (productid == 1) {
			cout << "\t\tPRODUCT DETAILS\n";
			cout << "PRODUCT NAME:"
				<< products[1] << "\n";
			cout << " TOTAl UNIT IN STOCk :" << subproductsnum[1] << "\n";
			cout << "UNIT PRICE:" << price[1] << endl;
			cout << "press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
			cin >> exit;
			if (exit == 'e') {
				menu();
			}
			else if (exit == 's') {
				system("cls");
				search();
			}

		}
		else if (productid == 2) {
			cout << "\t\tPRODUCT DETAILS\n";
			cout << "PRODUCT NAME:"
				<< products[2] << "\n";
			cout << " TOTAl UNIT IN STOCk :" << subproductsnum[2] << "\n";
			cout << "UNIT PRICE:" << price[2] << endl;
			cout << "press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
			cin >> exit;
			if (exit == 'e') {
				menu();
			}
			else if (exit == 's') {
				system("cls");
				search();
			}

		}
		else if (productid == 3) {
			cout << "\t\tPRODUCT DETAILS\n";
			cout << "PRODUCT NAME:"
				<< products[3] << "\n";
			cout << " TOTAl UNIT IN STOCk :" << subproductsnum[3] << "\n";
			cout << "UNIT PRICE:" << price[3] << endl;
			cout << "press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
			cin >> exit;
			if (exit == 'e') {
				menu();
			}
			else if (exit == 's') {
				system("cls");
				search();
			}

		}
		else if (productid == 4) {
			cout << "\t\tPRODUCT DETAILS\n";
			cout << "PRODUCT NAME:"
				<< products[4] << "\n";
			cout << " TOTAl UNIT IN STOCk :" << subproductsnum[4] << "\n";
			cout << "UNIT PRICE:" << price[4] << endl;
			cout << "press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
			cin >> exit;
			if (exit == 'e') {
				menu();
			}
			else if (exit == 's') {
				system("cls");
				search();
			}

		}
		else if (productid == 5) {
			cout << "\t\tPRODUCT DETAILS\n";
			cout << "PRODUCT NAME:"
				<< products[5] << "\n";
			cout << " TOTAl UNIT IN STOCk :" << subproductsnum[5] << "\n";
			cout << "UNIT PRICE:" << price[5] << endl;
			cout << "press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
			cin >> exit;
			if (exit == 'e') {
				menu();
			}
			else if (exit == 's') {
				system("cls");
				search();
			}

		}
		else if (productid == 6) {
			cout << "\t\tPRODUCT DETAILS\n";
			cout << "PRODUCT NAME:"
				<< products[6] << "\n";
			cout << " TOTAl UNIT IN STOCk :" << subproductsnum[6] << "\n";
			cout << "UNIT PRICE:" << price[6] << endl;
			cout << "press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
			cin >> exit;
			if (exit == 'e') {
				menu();
			}
			else if (exit == 's') {
				system("cls");
				search();
			}

		}
		else if (productid == 7) {
			cout << "\t\tPRODUCT DETAILS\n";
			cout << "PRODUCT NAME:"
				<< products[7] << "\n";
			cout << " TOTAl UNIT IN STOCk :" << subproductsnum[7] << "\n";
			cout << "UNIT PRICE:" << price[7] << endl;
			cout << "press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
			cin >> exit;
			if (exit == 'e') {
				menu();
			}
			else if (exit == 's') {
				system("cls");
				search();
			}

		}
		else if (productid == 8) {
			cout << "\t\tPRODUCT DETAILS\n";
			cout << "PRODUCT NAME:"
				<< products[8] << "\n";
			cout << " TOTAl UNIT IN STOCk :" << subproductsnum[8] << "\n";
			cout << "UNIT PRICE:" << price[8] << endl;
			cout << "press 'e' & <enter> to go to menu or 's' & <enter> to search another items details";
			cin >> exit;
			if (exit == 'e') {
				menu();
			}
			else if (exit == 's') {
				system("cls");
				search();
			}

		}
		else {
			menu();
		}

	}

}


