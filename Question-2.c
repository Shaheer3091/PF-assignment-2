#include <stdio.h>

#include <string.h>
char name[100];
char cnic[100];
int productCode[5] = {101, 102, 103, 104, 105};
int quantities[5] = {50, 100, 150, 200, 250};
float price[5] = {100, 200, 300, 150, 1000};

int number = 5;
int cartitem = 0;
int cartcode[100];
int cartquantity[100];
char PromoCode[15] = "Eid2025";
float totalbillD = 0;
void display()
{
    printf("===Welcome To Helly's Mart===\n");
    printf("1.Enter Customer Information\n");
    printf("2.Show Inventory\n");
    printf("3.Add Item To Cart\n");
    printf("4.Check Out\n");
    printf("5.Print Invoice\n");
    printf("6.Exit\n");
}
void CustomerInfo()
{
    printf("Enter Your Name:");
    scanf(" %[^\n]", name);
    printf("Enter Your CNIC:");
    scanf(" %[^\n]", cnic);
    printf("Customer Information Saved!\n");
}
void Inventory()
{
    printf("=======INVENTORY=======\n");
    printf("Product Code\tQuantity\tPrice\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t\t%d\t\t%.2f\n", productCode[i], quantities[i], price[i]);
    }
}
void addtocart()
{
    int productcode;
    int quantity;
    char choice = 'y';
    int index = -1;
    while (choice == 'Y' || choice == 'y')
    {
        Inventory();
        printf("Enter Product Code:");
        scanf("%d", &productcode);
        for (int i = 0; i < number; i++)
        {
            if (productCode[i] == productcode)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            printf("Invalide Product Code!!\n");
            return;
        }
        printf("Enter Quantity:");
        scanf("%d", &quantity);
        if (quantities[index] >= quantity)
        {
            cartcode[cartitem] = productcode;
            cartquantity[cartitem] = quantity;
            cartitem++;
            quantities[index] -= quantity;
        }
        else
        {
            printf("Not Enough Quantity!\n");
            return;
        }
        printf("Do You want to add more item?(Y/N):\n");
        scanf(" %c", &choice);
        if (choice == 'N' || choice == 'n')
        {
            printf("Thank You for Shopping!\n");
        }
    }
}
void totalBill()
{
    char choice;
    char promocode[15];
    float totalbill = 0;
    if (cartitem > 0)
    {
        printf("====Total Bill====\n");
        printf("ProductCode\tQuantity\tPrice Per Product\n");
        for (int i = 0; i < cartitem; i++)
        {
            int found = -1;
            for (int j = 0; j < number; j++)
            {
                if (cartcode[i] == productCode[j])
                {
                    found = j;
                    break;
                }
            }
            printf("%d\t\t%d\t\t%.2f\n", cartcode[i], cartquantity[i], price[found]);
            totalbill += cartquantity[i] * price[found];
        }
        printf("Do You have any Promocode?");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y')
        {
            printf("Enter Promocode:");
            scanf(" %s", promocode);
            if (strcmp(PromoCode, promocode) == 0)
            {
                totalbillD = totalbill - 0.25 * totalbill;
                printf("You have got 25%% discount!\n ");
                printf("====================\n");
                printf("Total Bill With 25%% Discount = %.2f\n", totalbillD);
            }
            else
            {
                printf("Invalid Code!\n");
            }
        }
        else
        {
            printf("\n=========================\n");
            printf("Total Bill With out Discount = %.2f\n", totalbill);
        }
    }
    else
    {
        printf("Cart is Empty!\n");
    }
}

void Invoice()
{
    float totalbill = 0;
    if (cartitem == 0)
    {
        printf("Cart is Empty !\n");
        return;
    }
    if (name[0] == '\0')
    {
        printf("Please Enter Customer Information!\n");
        return;
    }
    char choice;
    char promocode[15];
    printf("==========================\n");
    printf("        HELLY'S MART       \n");
    printf("==========================\n");
    printf("          Invoice         \n");
    printf("Customer's Name : %s\n", name);
    printf("CNIC : %s\n", cnic);
    printf("==========================\n");
    printf("ProductCode\tQuantity\tPrice Per Product\tTotal\n");
    for (int i = 0; i < cartitem; i++)
    {
        int found = -1;
        for (int j = 0; j < number; j++)
        {
            if (cartcode[i] == productCode[j])
            {
                found = j;
                break;
            }
        }

        if (found != -1)
        {
            float itemTotal = cartquantity[i] * price[found];
            printf("%d\t\t%d\t\t%.2f\t\t\t%.2f\n", cartcode[i], cartquantity[i], price[found], itemTotal);
            totalbill += itemTotal;
        }
    }
    printf("========================================\n");
    printf("Total Bill Without Discount: %.2f\n", totalbill);
    printf("Do You have any Promocode?(Y/N):");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        printf("Enter Promocode:");
        scanf(" %s", promocode);
        if (strcmp(PromoCode, promocode) == 0)
        {
            totalbillD = totalbill - 0.25 * totalbill;
            printf("You have got 25%% discount!\n ");
            printf("====================\n");
            printf("Total Bill With 25%% Discount = %.2f\n", totalbillD);
        }
        else
        {
            printf("Invalid Promocode!\n");
        }
    }

    printf("======THANKYOU FOR SHOPPING======\n");
}

int main()
{
    int choice;
    while (choice != 6)
    {
        display();
        printf("Enter Your Choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            CustomerInfo();
            break;
        case 2:
            Inventory();
            break;
        case 3:
            addtocart();
            break;
        case 4:
            totalBill();
            break;
        case 5:
            Invoice();
            break;
        case 6:
            printf("EXITING.....\n");
            return 0;
        default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}