#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define Max_size 10000

int asciiToBinary(int ascii);
int bintogray(int);

void main()
{
    char str[Max_size],binary[Max_size],onesComp[Max_size];
    int i=0,j=0,ch,bin,gray;
    
    printf("Enter a message: ");
    gets(str);

    for(i=0;str[i]!='\0';i++)
    {
        printf("%c = %d",str[i],str[i]);
        ch=str[i];

        printf("= %d",asciiToBinary(ch));
        bin=asciiToBinary(ch);

        gray = bintogray(bin);
        printf("= %d ", gray);

        sprintf(binary, "%d", gray);
        for(j=0; j<strlen(binary); j++)
        {
            if(binary[j] == '1')
            {
                onesComp[j] = '0';
            }
            else if(binary[j] == '0')
            {
                onesComp[j] = '1';
            }
            else
            {
                printf("Invaild character");
                
            }
        }  
        printf("= %s= ", onesComp);

         for(j=0;j<strlen(onesComp);j++)
        {
            switch(onesComp[j])
            {
               case '1':printf(".----");break;

               case '0':printf("-----");break;

               default :printf("Invalid character\n");
           }

        }
        printf("\n");
    }
    getch();

}



int asciiToBinary(int ascii)
{
	int res = 0, i = 1, rem;     
	while (ascii > 0)
	{
		rem = ascii % 2;
		res = res + (i * rem);
		ascii = ascii / 2;
		i = i * 10;
	}
	return(res);
}

int bintogray(int bin)
{
    int a, b, result = 0, i = 0;
    while (bin != 0)
    {
        a = bin % 10;
        bin = bin / 10;
        b = bin % 10;
        if ((a && !b) || (!a && b))
        {
            result = result + pow(10, i);
        }
        i++;
    }
    return result;
}