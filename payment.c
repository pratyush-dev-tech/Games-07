#include <stdio.h>
#include <stdlib.h>

struct Payment 
{
    char name[50];
    int id;
    float amount;
    char status[10];
};

         void addPayment() 
{
    FILE *fp = fopen("payments.txt", "a");
    struct Payment p;

    printf("\nEnter Name: ");
    scanf("%s", p.name);

    printf("Enter Payment ID: ");
    scanf("%d", &p.id);

    printf("Enter Amount: ");
    scanf("%f", &p.amount);

    printf("Enter Status (Paid/Pending): ");
    scanf("%s", p.status);

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);

    printf("\n✅ Payment Added Successfully!\n");
}

         void displayPayments() 
{
         FILE *fp = fopen("payments.txt", "r");
         struct Payment p;

          if (fp == NULL) 
    {
          printf("\nNo records found!\n");
          return;
    }

    printf("\n--- Payment Records ---\n");

    while (fread(&p, sizeof(p), 1, fp)) {
        printf("\nName: %s", p.name);
        printf("\nID: %d", p.id);
        printf("\nAmount: %.2f", p.amount);
        printf("\nStatus: %s\n", p.status);
        printf("----------------------\n");
    }

    fclose(fp);
}

int main() 
{
    int choice;

    while (1) 
    {
        printf("\n===== Payment Record System =====\n");
        printf("1. Add Payment\n");
        printf("2. View Payments\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                addPayment();
                break;
            case 2:
                displayPayments();
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}