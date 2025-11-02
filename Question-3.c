#include <stdio.h>
void display()
{
    printf("\n=============\n");
    printf("1. Update Sector Status\n");
    printf("2. Query Sector Status\n");
    printf("3. Run System Diagnostic\n");
    printf("4. Exit\n");
}
void update(int gird[4][4], int row, int col, int set, int flag)
{
    if (set == 1)
    {
        gird[row][col] |= flag;
    }
    else
    {
        gird[row][col] &= ~flag;
    }
}
void Query(int gird[4][4], int row, int col)
{
    int status = gird[row][col];
    int power = status & 1;
    int overload = status & 2;
    int maintenance = status & 4;
    printf("===STATUS===\n");
    power ? printf("Power is On\n") : printf("Power is OFF\n");
    overload ? printf("Overload\n") : printf("Not Overload\n");
    maintenance ? printf("Maintenance Required\n") : printf("Maintenance Not Required\n");
}
void diagnostic(int gird[4][4])
{
    int overload = 0, maintenance = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (gird[i][j] & 2)
                overload++;
            if (gird[i][j] & 4)
                maintenance++;
        }
    }
    printf("===Diagnosis===\n");
    printf("Total Overloaded Sector:%d\n", overload);
    printf("Total Sector Where Maintenace is Required : %d\n", maintenance);
}
int main()
{
    int choice = 0;
    int rows, col;
    int gird[4][4] = {0};
    int flag, set;
    while (choice != 4)
    {
        display();
        printf("Enter Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Row And Column Of Sector(0-3):");
            scanf("%d %d", &rows, &col);
            printf("Select Flag(1.Power 2.Overload 4.Maintenance):");
            scanf("%d", &flag);
            printf("Set(1) or Clear(0):");
            scanf("%d", &set);
            update(gird, rows, col, set, flag);
            break;
        case 2:
            printf("Enter Row And Column Of Sector(0-3):");
            scanf("%d %d", &rows, &col);
            Query(gird, rows, col);
            break;
        case 3:
            diagnostic(gird);
            break;
        case 4:
            printf("Exiting.......\n");
            return 0;
            break;
        default:
            printf("Invalid Choice!\n");
        }
    }
}