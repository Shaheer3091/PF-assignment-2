#include <stdio.h>
 
void display()
{
    printf("\n====TCS Secure Message Tool====\n");
    printf("1. Encode Message\n");
    printf("2. Decode Message\n");
    printf("3. Exit\n");
}
void toggling(char message[])
{
    for (int i = 0; message[i] != '\0'; i++)
    {
        message[i] = message[i] ^ (1 << 1);
        message[i] = message[i] ^ (1 << 4);
    }
}
void reverseMessage(char message[], int length)
{
    for (int i = 0; i < length / 2; i++)
    {
        char temp = message[i];
        message[i] = message[length - i - 1];
        message[length - i - 1] = temp;
    }
}
void encodeMessage(char message[])
{
    int length = 0;
    while (message[length] != '\0')
    {
        length++;
    }
    reverseMessage(message, length);
    toggling(message);
}
void decodeMessage(char message[])
{
    int length = 0;
    while (message[length] != '\0')
    {
        length++;
    }
    toggling(message);
    reverseMessage(message, length);
}

int main()
{
    char Message[1000];
    char Code[1000];
    int choice = 0;
    while (choice != 3)
    {
        display();
        printf("Enter Your Choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Message To Encode :");
            scanf(" %[^\n]", Message);
            encodeMessage(Message);
            printf(" %s\n", Message);
            break;
        case 2:
            printf("Enter Code To Decode :");
            scanf(" %[^\n]", Code);
            decodeMessage(Code);
            printf(" %s\n", Code);
            break;
        case 3:
            printf("Exiting....\n");
            return 0;
            break;
        default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}
