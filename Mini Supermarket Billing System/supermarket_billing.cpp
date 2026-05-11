#include <iostream>
#include <string>
using namespace std;

int main() {

    // ===== MINI SUPERMARKET BILLING SYSTEM =====

    int totalProducts;

    cout << "============================================" << endl;
    cout << "       WELCOME TO AL-NOOR SUPERMARKET       " << endl;
    cout << "============================================" << endl;

    // USER INPUT - How many products to add to shop
    cout << "Enter number of products in shop (max 8): ";
    cin >> totalProducts;

    if (totalProducts < 1 || totalProducts > 8) {
        cout << "Invalid! Please enter between 1 and 8." << endl;
        return 0;
    }

    // 1D Arrays for products
    string productName[8];
    float productPrice[8];
    int stock[8];

    // 2D Array - purchase record [item][0=qty, 1=total price]
    float purchaseRecord[8][2];

    // USER INPUT - Enter product details
    cout << endl;
    cout << "-------- ENTER PRODUCT DETAILS ---------" << endl;

    for (int i = 0; i < totalProducts; i++) {
        cout << endl;
        cout << "Product " << i + 1 << " Name: ";
        cin >> productName[i];
        cout << "Price of " << productName[i] << " (Rs.): ";
        cin >> productPrice[i];
        cout << "Stock available for " << productName[i] << ": ";
        cin >> stock[i];

        purchaseRecord[i][0] = 0;
        purchaseRecord[i][1] = 0;
    }

    // Show product menu
    cout << endl;
    cout << "============================================" << endl;
    cout << "             PRODUCT MENU                   " << endl;
    cout << "============================================" << endl;
    cout << "No.\tProduct Name\t\tPrice\t\tStock" << endl;
    cout << "--------------------------------------------" << endl;

    for (int i = 0; i < totalProducts; i++) {
        cout << i + 1 << ".\t" << productName[i] << "\t\tRs." << productPrice[i] << "\t\t" << stock[i] << " units" << endl;
    }

    cout << "--------------------------------------------" << endl;

    // USER INPUT - Customer name
    string customerName;
    cout << endl;
    cout << "Enter Customer Name: ";
    cin >> customerName;
    cout << "Welcome, " << customerName << "! Start Shopping." << endl;
    cout << "Enter 0 to finish shopping." << endl;
    cout << endl;

    int choice;
    int quantity;
    float grandTotal = 0;

    // Shopping loop
    for (int order = 0; order < 20; order++) {

        cout << "Enter product number (1-" << totalProducts << ") or 0 to checkout: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > totalProducts) {
            cout << "Invalid choice! Enter 1 to " << totalProducts << "." << endl;
            continue;
        }

        int index = choice - 1;

        cout << "Enter quantity: ";
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Quantity must be at least 1!" << endl;
            continue;
        }

        if (quantity > stock[index]) {
            cout << "Sorry! Only " << stock[index] << " units available." << endl;
            continue;
        }

        // Update purchase record
        purchaseRecord[index][0] = purchaseRecord[index][0] + quantity;
        purchaseRecord[index][1] = purchaseRecord[index][1] + (quantity * productPrice[index]);

        // Update stock
        stock[index] = stock[index] - quantity;

        float itemTotal = quantity * productPrice[index];
        grandTotal = grandTotal + itemTotal;

        cout << "Added: " << quantity << " x " << productName[index] << " = Rs." << itemTotal << endl;
        cout << "Running Total: Rs." << grandTotal << endl;
        cout << endl;
    }

    // Generate Bill
    cout << endl;
    cout << "============================================" << endl;
    cout << "               FINAL BILL                   " << endl;
    cout << "============================================" << endl;
    cout << "Customer : " << customerName << endl;
    cout << "Shop     : AL-NOOR SUPERMARKET" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Item\t\t\tQty\tRate\t\tAmount" << endl;
    cout << "--------------------------------------------" << endl;

    for (int i = 0; i < totalProducts; i++) {
        if (purchaseRecord[i][0] > 0) {
            cout << productName[i] << "\t\t" << purchaseRecord[i][0] << "\tRs." << productPrice[i] << "\t\tRs." << purchaseRecord[i][1] << endl;
        }
    }

    cout << "--------------------------------------------" << endl;
    cout << "Sub Total:\t\t\t\t\tRs." << grandTotal << endl;

    // Discount
    float discount = 0;

    if (grandTotal >= 2000) {
        discount = grandTotal * 0.10;
        cout << "Discount (10%):\t\t\t\t\t-Rs." << discount << endl;
    } else if (grandTotal >= 1000) {
        discount = grandTotal * 0.05;
        cout << "Discount (5%):\t\t\t\t\t-Rs." << discount << endl;
    } else {
        cout << "No Discount Applied" << endl;
    }

    // GST
    float afterDiscount = grandTotal - discount;
    float tax = afterDiscount * 0.17;
    float finalAmount = afterDiscount + tax;

    cout << "GST (17%):\t\t\t\t\tRs." << tax << endl;
    cout << "============================================" << endl;
    cout << "TOTAL PAYABLE:\t\t\t\t\tRs." << finalAmount << endl;
    cout << "============================================" << endl;

    // USER INPUT - Cash payment
    float cashPaid;
    cout << "Enter Cash Paid by " << customerName << ": Rs.";
    cin >> cashPaid;

    if (cashPaid < finalAmount) {
        cout << "Insufficient amount! Remaining: Rs." << finalAmount - cashPaid << endl;
    } else {
        float change = cashPaid - finalAmount;
        cout << "Change Returned : Rs." << change << endl;
        cout << endl;
        cout << "Thank you, " << customerName << "!" << endl;
        cout << "Thank you for shopping at AL-NOOR!" << endl;
    }

    cout << "============================================" << endl;

    return 0;
}
