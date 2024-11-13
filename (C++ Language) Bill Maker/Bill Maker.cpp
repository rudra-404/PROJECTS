#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
int PriceList[16] = {100, 120, 200, 150, 300, 350, 250, 450, 150, 130, 120, 180, 150, 300, 250, 150};

int CalculateBill(){
    int TotalItem, TotalPrice = 0;
    SetConsoleTextAttribute(color, 0x08); // Gray color
    cout << "\t\tEnter Total Item >>> ";
    SetConsoleTextAttribute(color, 0x06); // Yellow color
    cin >> TotalItem;
    char Section, Item;
    for(int i=0; i<TotalItem; i++){
        SetConsoleTextAttribute(color, 0x08); // Gray color
        cout << "\n\t\tITEM " << i+1 << "\n\t\t----------------------------------\n";
        Section_Invalid_Detected :
        SetConsoleTextAttribute(color, 0x08); // Gray color
        cout << "\t\tEnter Section (A, B, C or D) >>> ";
        SetConsoleTextAttribute(color, 0x06); // Yellow color
        cin >> Section;
        if(Section == 'A' || Section == 'a'){
            Item_Invalid_Detected_1 :
            SetConsoleTextAttribute(color, 0x08); // Gray color
            cout << "\t\tEnter Item (1, 2, 3 or 4)    >>> ";
            SetConsoleTextAttribute(color, 0x06); // Yellow color
            cin >> Item;
            if(Item<49 || Item>53){
                SetConsoleTextAttribute(color, 0x04); // Red color
                cout << "\t\tInvalid Input !!!\n";
                goto Item_Invalid_Detected_1;
            }
            TotalPrice += PriceList[Item-49];
        }else if(Section == 'B' || Section == 'b'){
            Item_Invalid_Detected_2 :
            SetConsoleTextAttribute(color, 0x08); // Gray color
            cout << "\t\tEnter Item (1, 2, 3 or 4)    >>> ";
            SetConsoleTextAttribute(color, 0x06); // Yellow color
            cin >> Item;
            if(Item<49 || Item>53){
                SetConsoleTextAttribute(color, 0x04); // Red color
                cout << "\t\tInvalid Input !!!\n";
                goto Item_Invalid_Detected_2;
            }
            TotalPrice += PriceList[Item-45];
        }else if(Section == 'C' || Section == 'c'){
            Item_Invalid_Detected_3 :
            SetConsoleTextAttribute(color, 0x08); // Gray color
            cout << "\t\tEnter Item (1, 2, 3 or 4)    >>> ";
            SetConsoleTextAttribute(color, 0x06); // Yellow color
            cin >> Item;
            if(Item<49 || Item>53){
                SetConsoleTextAttribute(color, 0x04); // Red color
                cout << "\t\tInvalid Input !!!\n";
                goto Item_Invalid_Detected_3;
            }
            TotalPrice += PriceList[Item-41];
        }else if(Section == 'D' || Section == 'd'){
            Item_Invalid_Detected_4 :
            SetConsoleTextAttribute(color, 0x08); // Gray color
            cout << "\t\tEnter Item (1, 2, 3 or 4)    >>> ";
            SetConsoleTextAttribute(color, 0x06); // Yellow color
            cin >> Item;
            if(Item<49 || Item>53){
                SetConsoleTextAttribute(color, 0x04); // Red color
                cout << "\t\tInvalid Input !!!\n";
                goto Item_Invalid_Detected_4;
            }
            TotalPrice += PriceList[Item-37];
        }else{
            SetConsoleTextAttribute(color, 0x04); // Red color
            cout << "\t\tInvalid Input !!!\n";
            goto Section_Invalid_Detected;
        }
    }
    SetConsoleTextAttribute(color, 0x02); // Green color
    cout << "\n\t\tTOTAL PRICE " << TotalPrice << " TK\n\n";
    SetConsoleTextAttribute(color, 0x07); // White color
    return 1;
}

int MainMenu(){
    SetConsoleTextAttribute(color, 0x0c); // Red color
    cout << "\n\t\t\t\t\t ---------------------------------------\n\t\t\t\t\t|\t\t";
    SetConsoleTextAttribute(color, 0x06); // Yellow color
    cout << "BILL MAKER";
    SetConsoleTextAttribute(color, 0x0c); // Red color
    cout << "\t\t|\n\t\t\t\t\t ---------------------------------------\n\n";
    SetConsoleTextAttribute(color, 0x06); // Yellow color
    cout << "\t\t\t     (A) Appetizers\t\t\t\t     (B) Main Course\n";
    cout << "\t\t----------------------------------------\t----------------------------------------\n";
    SetConsoleTextAttribute(color, 0x02); // Green color
    cout << "\t\t(1) Garlic Bread ---------------- 100 TK\t(1) Chicken Alfredo Pasta ------- 300 TK\n";
    cout << "\t\t(2) Spring Rolls ---------------- 120 TK\t(2) Grilled Chicken ------------- 350 TK\n";
    cout << "\t\t(3) Chicken Wings --------------- 200 TK\t(3) Beef Burger ----------------- 250 TK\n";
    cout << "\t\t(4) Mozzarella Sticks ----------- 150 TK\t(4) Margherita Pizza ------------ 450 TK\n\n";
    SetConsoleTextAttribute(color, 0x06); // Yellow color
    cout << "\t\t\t      (C) Desserts\t\t\t\t      (D) Beverages\n";
    cout << "\t\t----------------------------------------\t----------------------------------------\n";
    SetConsoleTextAttribute(color, 0x02); // Green color
    cout << "\t\t(1) Chocolate Brownie ----------- 150 TK\t(1) Fresh Fruit Juice ----------- 150 TK\n";
    cout << "\t\t(2) Ice Cream Sundae ------------ 130 TK\t(2) Mocktails ------------------- 300 TK\n";
    cout << "\t\t(3) Apple Pie ------------------- 120 TK\t(3) Specialty Coffee ------------ 250 TK\n";
    cout << "\t\t(4) Tiramisu -------------------- 180 TK\t(4) Flavored Iced Tea ----------- 150 TK\n\n";
    return 1;
}

int main(){
    MainMenu();
    CalculateBill();
    getch();
    return 0;
}