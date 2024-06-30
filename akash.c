#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <string.h>
struct HashTable
{
     int key;
     char User_Name[20];
     char data[20];
};
#define SIZE 20
int n;
char password[20];
char name[20];
struct HashTable a[SIZE],encryption_[SIZE];

int hashFunction(int key)
{
    return(key % SIZE);
}
char *RANDOMGENERATORPASSWORD(int N)
{
	int i = 0;

	int randomizer = 0;
	srand((unsigned int)(time(NULL)));
	char NUMBERS[] = "0123456789";

	char LETTER[] = "abcdefghijklmnoqprstuvwyzx";

	char LeTTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

char Symbols[] = "!@#$^&*?";

	randomizer = rand() % 4;

	// Iterate over the range [0, N]
	for (i = 0; i < N; i++) {

		if (randomizer == 1) {
			password[i] = NUMBERS[rand() % 10];
			randomizer = rand() % 4;
		}
		else if (randomizer == 2) {
			password[i] = Symbols[rand() % 8];
			randomizer = rand() % 4;
		}
		else if (randomizer == 3) {
			password[i] = LeTTER[rand() % 26];
			randomizer = rand() % 4;
		}
		else {
			password[i] = LETTER[rand() % 26];
			randomizer = rand() % 4;
		}
}
    return(password);
}
char *Manual_password_generator()
{
	printf("enter the password:\n");
	int i=0;
	do{
		password[i]=getch();
		if(password[i]!='\r')
			printf("*");
		i++;
	}while(password[i-1]!='\r');
	return(password); 
}
void insert(int key,char *n2,char *k)
{
    int index=hashFunction(key);
    a[index].key=key;
	for(char i=0;k[i]!='\0';i++)
	{
		a[index].User_Name[i]=k[i];
	}
    for(char i=0;n2[i]!='\0';i++)
    {
        a[index].data[i]=n2[i];
    }
}
char *Name()
{
	printf("enter the name\n");
	scanf("%s",name);
	fflush(stdin);
	return(name);
}
u=0,ind=0,l=0;
void encryption()
{
	int CHOICE=0;
	char encrypt[50];
	printf("1:encrypt the password individually\n2:show all the users with their corresponding encryped passwords\n3:exit\nEnter your choice\n");
	scanf("%d",&CHOICE);
	switch(CHOICE)
	{
		case 1:
			printf("enter the UID of the user_name\n");
			scanf("%d",&u);
			ind=hashFunction(u);
			l=strlen(a[ind].data);
			for(int i=0;i<l;i++)
			{
				encrypt[i]=a[ind].data[i]-9;
			}
			printf("User_name who has having UID %d is: %s\n",u,a[ind].User_Name);
			printf("password of %s: %s\n",a[ind].User_Name,a[ind].data);
			printf("encrypted password: %s\n",encrypt);
			break;
		case 2:
			for(int i=0;i<SIZE;i++)
			{
				if(a[i].key)
				{
					l=strlen(a[i].data);
					for(int j=0;j<l;j++)
					{
						encrypt[j]=a[i].data[j]-9;
					}
					encryption_[i].key=a[i].key;
					for(char s=0;a[i].User_Name[s]!='\0';s++)
					{
						encryption_[i].User_Name[s]=a[i].User_Name[s];
					}
					for(char f=0;encrypt[f]!='\0';f++)
    				{
        				encryption_[i].data[f]=encrypt[f];
    				}
				}
			}
			printf("UID:\tUSER NAME:\tPASSWORD\n");
			for(int i=0;i<SIZE;i++)
			{
				if(encryption_[i].key)
				{
	printf("%d\t%s\t\t%s\n",encryption_[i].key,encryption_[i].User_Name,encryption_[i].data);
				}
			}
			break;
		case 3:
			exit(0);
		default:
			printf("invalid choice\n");
	}
}
void decryption()
{
	display();
}

void display()
{
	printf("UID:\tUSER NAME:\tPASSWORD\n");
	for(int i=0;i<SIZE;i++)
{
		if(a[i].key)
		{
			printf("%d\t%s\t\t%s\n",a[i].key,a[i].User_Name,a[i].data);
		}
	}
} 
int main()
{
	int UID=0,choice=0,t=0,N;
	system("cls");
    while(choice!=6)
    {
		printf("\n1:randomly password generator\n2:enter password manually\n3:Encryption\n4.decryption\n5:exit\nenter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter the User id:\n");
        		scanf("%d",&UID);
				printf("enter the length of the password to be generated:\n");
        		scanf("%d",&N);
				char *m=Name();
				char *n=RANDOMGENERATORPASSWORD(N);
				insert(UID,n,m);
				break;
			case 2:
				printf("enter the User id:\n");
        		scanf("%d",&UID);
				char *a=Name(); 
				char *ptr=Manual_password_generator();
        		insert(UID,ptr,a);
				break;
			case 3:
				encryption();
				break;
			case 4:
				decryption();
				break;
			case 5:
			exit(13);
			default:
				printf("invalid choice\n");
		}
    }
    return(0);
}

