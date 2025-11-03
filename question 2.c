#include<stdio.h>

//customer info function
void customerinfo(char a[],char b[]);
void customerinfo(char a[],char b[])

{printf("Enter your name\n");
scanf("%s",a);
printf("\nEnter your CNIC number\n");
scanf("%s",b);
}
// inventory view function 
void inventory(int a[],int b[],float c[]);
void inventory(int a[],int b[],float c[]){
	int i;
	printf("code    quantity     price\n");
	for(i=0;i<4;i++){
		printf("%d         %02d         %0.2f\n",a[i],b[i],c[i]);
	}
}
///cart funtion/////
float cart(int a[],int b[],float c[]);
float cart(int a[],int b[],float c[]){
	int choice=1,product,quan,i,j,sum=0;
	float total=0;
	 
while(choice==1){ printf("\n1.Add items\n");
                  printf("2.Exit\n");
                  scanf("%d", &choice);

                 if (choice == 2)
                 break;
		         printf("Enter the product code you want to purchase\n");
		         scanf("%d",&product);
	            printf("\nEnter the product quantity you want to purchase\n");
		        scanf("%d",&quan);
		
		for(i=0;i<4;i++){
			if(product==a[i]){sum=c[i]*quan;b[i]=b[i]-quan;printf("\nInventory updated\n");
			}
		}
		total=sum+total;        
	}
	return total;
}
	 
	 
	 
	

////voucher code////
float promo(float b);
float promo(float bill){
	
	int vouch,discount;
	printf("\nDo you have EID2025 voucher\n1.YES\n2.NO\n");
	scanf("%d",&vouch);
	
	if(vouch==1){
	   discount=bill*0.25;}
	else{discount=0;}
	return discount;
	   
	}
	
void invoice(char info[],char cnic[],float bills,float discount);
void invoice(char info[],char cnic[],float bills,float discount){
	
	printf("\n\n********Final Invoice**********\n\n");
	printf("Customer Name:%s\n",info);
	printf("CNIC Number:%s\n\n",cnic);
	printf("_________________________________");
	 
	printf("\nBill without discount=%f\n",bills);
	printf("Final bill=%f\n",bills-discount);
	printf("You saved %0.2f$\n",discount);
	printf("_________________________________");
	printf("\nThanks for shopping\n\n");
}

int main()
{   int menu;
    char info[20];
    char cnic[20];
    int code[4]={001,002,003,004};
    int quantity[4]={50,10,20,8};
    float price[4]={100,200,300,150};
    float totals;
    float bills;
    float disc;
    
    printf("Welcome to Kifayah Supermarket\n");
	printf("Whats on your mind proceed\n");
do { 
	printf("1.Do Grocery\n2.View inventory\n3.Exit\n");
	scanf("%d",&menu);
	
	switch(menu){
case 1:
    customerinfo(info,cnic); 
	printf("The current inventory is as follow\n");
	inventory(code,quantity,price);
	printf("\nProceed if you want to add items to your cart\n");
	totals=cart(code,quantity,price);
	bills=bills+totals;
    printf("The current total is %0.2f",bills);
    disc=promo(bills);
    invoice(info,cnic,bills,disc);
    break;
    
case 2:inventory(code,quantity,price);
       break;
       
case 3:printf("Exiting the program");break;}
 	}
 	while(menu!=3);
	
}
