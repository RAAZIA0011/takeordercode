#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

//GLOBAL VARIABLES FOR MENU ARRAY PRIZES
// for coffee menu
const int COFFEE_COUNT = 6;
const string COFFEE_NAMES[COFFEE_COUNT] = {"Espresso", "Cappuccino", "Latte",
     "Mocha", "Americano", "Macchiato"};
const double COFFEE_PRICES[COFFEE_COUNT] = {250, 350, 380, 420, 300, 400};

// for fast food menu
const int  FOOD_COUNT = 5;
const string FOOD_NAMES[FOOD_COUNT] = { "Club Sandwich", "Chicken Wrap", 
    "Fries", "Garlic Bread", "Croissant"};
const double FOOD_PRICES[FOOD_COUNT] = {550, 480, 220, 180, 220};

// for cold drinks menu
const int COLD_COUNT = 5;
const string COLD_NAMES[COLD_COUNT] = { "Cold Coffee", "Iced Latte", "Frappuccino", 
    "Lemon Iced Tea", "Mango Smoothie"};
const double COLD_PRICES[COLD_COUNT] = {350, 400, 480, 280, 320};

// for dessert menu
const int DESSERT_COUNT = 5;
const string DESSERT_NAMES[DESSERT_COUNT] = { "Chocolate Brownie", "Cheesecake", "Cinnamon Roll",
     "Tiramisu", "Muffin"};
const double DESSERT_PRICES[DESSERT_COUNT] = {300, 450, 250, 500, 180};

// GLOBAL VARIABLES 
int   totalCustomers  = 0;
double totalSales      = 0.0;
double totalDiscount   = 0.0;
int   itemSoldCount[4] = {0, 0, 0, 0}; // coffee, food, cold drinks, desserts

// BANNER ANIMATION

// for printing ===================================

void printLine(char ch = '=', int len = 50)
{
    for(int i = 0;i < len;i++)
    {
       cout << ch;
    }
    cout << endl;
}

// for centralized text

void printCentered(const string& text,int width = 50)
{
     int spaces = (width - (int)text.length()) / 2; // using built in len function
     if(spaces < 0)
     {
        spaces = 0;    // no space will be applied
     }
     for(int i = 0;i < spaces;i++)
     {
        cout << " ";
     }
     cout << text << endl;
     
}

// for pause in loading function
void pause(int ms = 800) 
{
    Sleep(ms);
}

// loading animation
void loadingAnimation()
 {
    cout << "\n";
    printCentered("Brewing your experience...");
    cout << "\n  [";
    for (int i = 0; i < 40; i++) {
        cout << "#" << flush;
        pause(40);
    }
    cout << "] 100%" << endl;
    pause(400);
}

// ----------WELCOMESCREEN----------

void welcomeScreen()
{
    
    printLine('*');
    printLine(' ');
    printCentered("( (");
    printCentered(") )");
    printCentered(".....___.....");
    printCentered("|         |");
    printCentered("|  BREW   |");
    printCentered("|  HAVEN  |");
    printCentered("|_________|");
    printCentered("\\______/");
    printCentered("~~~~~");
    printLine(' ');
    printCentered("W E L C O M E   T O");
    printCentered("B R E W   H A V E N   C A F E");
    printCentered("Where Every Sip Tells a Story");
    printLine(' ');
    printLine('*');

    loadingAnimation();
}

//  SHOW MENU
void showMenu()
 {
    printLine();
    printCentered("BREW HAVEN CAFE FULL MENU");
    printLine();

    // for coffee
    cout << "\n  *** COFFEE *** \n";
    printLine('-', 40);
    for (int i = 0; i < COFFEE_COUNT; i++) {
        cout << "  " << (i + 1) << ". " << left << setw(20) << COFFEE_NAMES[i]
             << "Rs. " << COFFEE_PRICES[i] << endl;
    }

    // for Cold Drinks
    cout << "\n  *** COLD DRINKS *** \n";
    printLine('-', 40);
    for (int i = 0; i < COLD_COUNT; i++) {
        cout << "  " << (i + 1) << ". "<< left << setw(20) << COLD_NAMES[i]
             << "Rs. " << COLD_PRICES[i] << endl;
    }

    // for Desserts
    cout << "\n  *** DESSERTS *** \n";
    printLine('-', 40);
    for (int i = 0; i < DESSERT_COUNT; i++) {
        cout << "  " << (i + 1) << ". " << left << setw(20) << DESSERT_NAMES[i]
             << "Rs. " << DESSERT_PRICES[i] << endl;
    }

    // for Fast Food
    cout << "\n  *** FAST FOOD ***\n";
    printLine('-', 40);
    for (int i = 0; i < FOOD_COUNT; i++) {
        cout << "  " << (i + 1) << ". " << left << setw(20) << FOOD_NAMES[i]
             << "Rs. " << FOOD_PRICES[i] << endl;
    }

    printLine();


}

int orderedItems[50];
int orderedQuantity[50];
int orderCount = 0;
string orderType[50] ;

void coffeeorder(){
int item_coffee ;               
int quantity_coffee ;
  do{
 
cout<< "ENTER ITEM NUMBER  FROM COFFEE PORTION (0 TO 6) : " ;
cin>> item_coffee ;

if(item_coffee< 0 || item_coffee >6 ) {
  cout<< "Invalid item Number " <<endl ;
}
  }
while(item_coffee < 0 || item_coffee > 6) ;


if(item_coffee == 0){
    quantity_coffee = 0 ;
    cout<< "ENTER QUANTITY : "  << quantity_coffee << endl ;
}
else 
{
    do{
     cout<< "ENTER QUANTITY : "  ;
     cin>> quantity_coffee ;
  if(quantity_coffee < 0)
            {
                cout << "Quantity cannot be negative " << endl ;
            }

    }while(quantity_coffee< 0 ) ;
}
if(item_coffee == 0)
{
    return;
}
if(orderCount >= 50)
{
    cout << "Maximum order limit reached!" << endl;
    return;
}

orderType[orderCount] = "coffee";
orderedItems[orderCount] = item_coffee;
orderedQuantity[orderCount] = quantity_coffee;
orderCount++;

}

void foodorder(){
int item_food ;
int quantity_food ;
do{
cout<< "ENTER ITEM NUMBER FROM FOOD PORTION (0 TO 5) :  " ;
cin>>item_food ;
if(item_food <0 || item_food > 5){
 cout << "Invalid item number " <<endl ;
}

}while(item_food < 0 || item_food > 5) ; 

if(item_food == 0 ){
    quantity_food = 0 ;
    cout<< "ENTER QUANTITY : "  <<quantity_food <<endl ;
}
else {
do{
    cout<< "ENTER QUANTITY :"  ;
    cin>> quantity_food ;
if(quantity_food<0){
    cout<< "quantity can not be negative "  ; 
 }

}while(quantity_food < 0 ) ;

}
if(item_food == 0)
{
    return;
}
 if(orderCount >= 50)
{
    cout << "Maximum order limit reached!" << endl;
    return;
}

orderType[orderCount] = "Food";
orderedItems[orderCount] = item_food;
orderedQuantity[orderCount] = quantity_food;
orderCount++;

}
 void colddrinkorder(){
    int item_coldDrinks ;
    int quantity_coldDrinks ;
    
do{
  cout<< "ENTER ITEM NUMBER FROM COLD DRINKS PORTION (0 TO 5) : " ;
  cin>>item_coldDrinks ;
  if(item_coldDrinks <0 ||  item_coldDrinks > 5){
 cout<< "Invalid item Number " << endl ;

  } 
}while(item_coldDrinks<0 || item_coldDrinks > 5 ) ;

  if(item_coldDrinks == 0){
    quantity_coldDrinks = 0 ;
    cout<< "ENTER QUANTITY : " <<quantity_coldDrinks <<endl ;
  }
    else {
    do{
          cout<< "ENTER QUANTITY : " ;
        cin>> quantity_coldDrinks ;

  if(quantity_coldDrinks<0 ){
    cout<< "quantity can not be negative  " ;
  }


    }while(quantity_coldDrinks< 0 ) ;
}
if(item_coldDrinks == 0)
{
    return;
}
 if(orderCount >= 50)
{
    cout << "Maximum order limit reached!" << endl;
    return;
}

orderType[orderCount] = "Cold Drinks";
orderedItems[orderCount] = item_coldDrinks;
orderedQuantity[orderCount] = quantity_coldDrinks;
orderCount++;
 }

 void dessertorder(){

int quantity_desserts ;
int item_desserts ;
do{
 cout<< "ENTER ITEM NUMBER FROM DESSERTS PORTION (0 TO 5) : " ;
 cin>> item_desserts ;

 if (item_desserts< 0 || item_desserts > 5 ){
  cout<< "invalid item number "  <<endl ;
 }
}while(item_desserts< 0 || item_desserts > 5);

 if(item_desserts ==0 ){
    quantity_desserts = 0 ;
    cout<< "ENTER QUANTITY : " <<quantity_desserts <<endl ;
 }
 else{
    do{
    cout<< "ENTER QUANTITY : " ;
    cin>> quantity_desserts ;
if (quantity_desserts < 0 ){
    cout<< "quantity can not be negative "  ; 
}

 }while(quantity_desserts < 0 ) ;


}
if(item_desserts == 0)
{
    return;
}
if(orderCount >= 50)
{
    cout << "Maximum order limit reached!" << endl;
    return;
}

orderType[orderCount] = "Desserts";
orderedItems[orderCount] = item_desserts;
orderedQuantity[orderCount] = quantity_desserts;
orderCount++;
 }

void orderSummaryAndBill();  
int main()
{
    welcomeScreen();

    string customer_name;
    cout << "\nENTER YOUR NAME : ";
    getline(cin, customer_name);

    showMenu();

    int choice;

    do
    {
        cout << "ENTER THE PORTION NUMBER OF YOUR CHOICE : " << endl;
        cout << "1. Coffee" << endl;
        cout << "2. Food" << endl;
        cout << "3. Cold Drinks" << endl;
        cout << "4. Desserts" << endl;
        cout << "5. Order Summary" << endl;

        cin >> choice;

        if(choice == 1)
            coffeeorder();
        else if(choice == 2)
            foodorder();
        else if(choice == 3)
            colddrinkorder();
        else if(choice == 4)
            dessertorder();
        else if(choice == 5)
            orderSummaryAndBill();
        else
            cout << "Invalid choice!" << endl;

    } while(choice != 5);

    return 0;
}
// Function to display complete order summary and calculate bill

void orderSummaryAndBill()
{
    double total = 0;
    double discount = 0;
    double payableBill = 0;

    cout << "\n\n========== ORDER SUMMARY ==========\n";

    for(int i = 0; i < orderCount; i++)
    {
        double itemPrice = 0;

        // Find price according to selected category
        if(orderType[i] == "coffee")
        {
            itemPrice = COFFEE_PRICES[orderedItems[i] - 1];
        }
        else if(orderType[i] == "Food")
        {
            itemPrice = FOOD_PRICES[orderedItems[i] - 1];
        }
        else if(orderType[i] == "Cold Drinks")
        {
            itemPrice = COLD_PRICES[orderedItems[i] - 1];
        }
        else if(orderType[i] == "Desserts")
        {
            itemPrice = DESSERT_PRICES[orderedItems[i] - 1];
        }

        double itemTotal = itemPrice * orderedQuantity[i];

        cout << "\nCategory : " << orderType[i];
        cout << "\nItem No  : " << orderedItems[i];
        cout << "\nQuantity : " << orderedQuantity[i];
        cout << "\nAmount   : Rs. " << itemTotal << endl;

        total += itemTotal;
    }

    // Applying discount according to bill amount
    if(total >= 3000)
    {
        discount = total * 0.15;
    }
    else if(total >= 2000)
    {
        discount = total * 0.10;
    }
    else if(total >= 1000)
    {
        discount = total * 0.05;
    }

    payableBill = total - discount;

    cout << "\n===================================";
    cout << "\nTotal Bill      : Rs. " << total;
    cout << "\nDiscount Given  : Rs. " << discount;
    cout << "\nAmount Payable  : Rs. " << payableBill;
    cout << "\n===================================";
    cout << "\nThank You For Visiting Brew Haven Cafe!\n";

    
    
}



