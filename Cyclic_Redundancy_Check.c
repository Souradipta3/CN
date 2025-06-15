#include<stdio.h>
#include<conio.h>
//C Program: Cyclic Redundancy Check - CodeWithC.com
void main()
{
int i,f[20],n[50],div[50],j,temp,quotient[20],z[10];
clrscr();
printf("enter the number\n");
for(i=0;i<8;i++)
{
scanf("%d",&n[i]);
}
printf("enter the divisor\n");
for(i=0;i<4;i++)
{
scanf("%d",&div[i]);
}
for(i=8;i<12;i++)
{
n[i]=0;
}
for(i=0;i<8;i++)
{
temp=i;
if(n[i]==1)
{
for (j=0;j<4;j++)
{
if (n[temp]==div[j])
{n[temp]=0;
f[j]=0;}
else
{n[temp]=1;
f[j]=1;}
temp=temp+1;

}
quotient[i]=1;
}
else
quotient[i]=0;
}
printf("\nthe quotient is \n");
for(i=0;i<8;i++)
printf("%d",quotient[i]);

printf("\n and the remainder is \n ");

for(j=0;j<4;j++)
printf("%d",f[j]);

getch();
}









#include <stdio.h>

int main() {
    int data[50], divisor[10], remainder[10], quotient[50];
    int data_bits, divisor_bits, i, j;

    
    data_bits = 8;
    divisor_bits = 4;

    printf("Enter 8-bit data (space-separated):\n");
    for (i = 0; i < data_bits; i++) {
        scanf("%d", &data[i]);
    }

    printf("Enter 4-bit divisor (space-separated):\n");
    for (i = 0; i < divisor_bits; i++) {
        scanf("%d", &divisor[i]);
    }

    
    for (i = data_bits; i < data_bits + divisor_bits - 1; i++) {
        data[i] = 0;
    }

    
    int temp[50];
    for (i = 0; i < data_bits + divisor_bits - 1; i++) {
        temp[i] = data[i];
    }

    
    for (i = 0; i < data_bits; i++) {
        quotient[i] = temp[i];
        if (temp[i] == 1) {
            for (j = 0; j < divisor_bits; j++) {
                temp[i + j] = temp[i + j] ^ divisor[j];
            }
        }
    }

    
    for (i = 0; i < divisor_bits - 1; i++) {
        remainder[i] = temp[data_bits + i];
    }

    
    printf("\nQuotient: ");
    for (i = 0; i < data_bits; i++) {
        printf("%d", quotient[i]);
    }

    printf("\nCRC (Remainder): ");
    for (i = 0; i < divisor_bits - 1; i++) {
        printf("%d", remainder[i]);
    }

    
    printf("\nTransmitted Data (Data + CRC): ");
    for (i = 0; i < data_bits; i++) {
        printf("%d", data[i]);
    }
    for (i = 0; i < divisor_bits - 1; i++) {
        printf("%d", remainder[i]);
    }

    printf("\n");
    return 0;
}
