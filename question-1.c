#include<stdio.h>
int addBook(int isbns[], char title[][50], float prices[], int quantities[],int a);
int addBook(int isbns[],char title[][50],float prices[],int quantities[],int a){
	 int i,j,num;
	printf("\nEnter the number of books you want to add(max100)\n");
	scanf("%d",&num);
	 
	for(i=a;i<(a+num);i++){
	printf("\nEnter the ISBNS Number for book\n");
	scanf("%d",&isbns[i]);
	int duplicate = 0;
    for ( j = 0; j < i; j++) {
        if (isbns[j] == isbns[i]) {
            printf("Duplicate ISBN! Please enter a unique ISBN.\n");
            duplicate = 1;
            i--;
            break;
        }
    }
    if (duplicate==1)
        continue;
	
	 
	printf("\nProvide the title for this book with ISBN %d\n",isbns[i]);
	scanf("%s",title[i]);
	printf("\nProvide prices of the book with ISBN %d\n",isbns[i]);
	scanf("%f",&prices[i]);
	printf("\nProvide quantity of the book with ISBN %d\n",isbns[i]);
	scanf("%d",&quantities[i]);
	printf("\n*********Book Successfully registered in database***********\n");}
	a=a+num;
	return a; 
}

void processSale(int isbns[], int quantities[],int a);
void processSale(int isbns[], int quantities[],int a){
	int isbn,sold,i,num;
 
printf("\nProvide the ISBNS number of book\n ");
scanf("%d",&isbn);

printf("\nProvide number of books sold\n ");
scanf("%d",&sold);

for(i=0;i<a;i++){
	if(isbns[i]==isbn){
	 if(quantities[i]<sold){printf("\nOut of stock for the book\n");}
	 else  {quantities[i]=quantities[i]-sold;
	 printf("\n*********Database updated Sucessfully**********\n");}}
}	}



void generateLowStockReport(int isbns[], char title[][50], float prices[], int quantities[],int a);
void generateLowStockReport(int isbns[], char title[][50], float prices[], int quantities[],int a)
{int i;
for(i=0;i<a;i++){ 
	if(quantities[i]<=5){
		printf("\nThe Book with ISBN %d is low in stock\nISBN NO#=%d\ntitle=%s\nprices=%.2f\nquantity=%d\n",isbns[i],isbns[i],title[i],prices[i],quantities[i]);
	}
}

}




int main()
{   int menu;
    int isbns[100];
    char title[100][50];
    float prices[100];
    int quantities[100];
    int i,j;
	int bookcount=0;  
	
	printf("***********WELCOME TO LIBERTY BOOKS SALES SOFTWARE***************\n");
	
  do{printf("\n1.Add new book\n2.Process a sale\n3.Generate a low stock report\n4.Exit\n");
	printf("Press the number(1-3) for further processing\n");
	scanf("%d",&menu);
	
	switch(menu){
		case 1: bookcount=addBook(isbns,title,prices,quantities,bookcount);break;
		
		case 2:processSale(isbns,quantities,bookcount);break;
		
		case 3:generateLowStockReport(isbns,title,prices,quantities,bookcount);break;
	}}
	while(menu!=4);
}
