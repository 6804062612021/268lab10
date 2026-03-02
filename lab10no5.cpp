#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char loginname[64];
	char password[64];
} account ;

typedef struct {
	char stdID[24];
	char nameSurname[25];
	account stdACC;
} hoststd;

int checkLogin(char *login, char *passwd, char *logindb, char *passdb);

int main(){
	char user[64],pass[64]; int valid=0;
	hoststd cs[5] = {
				{"66-040626-2686-9","MR.A",{"user1", "passwd1"}},
				{"66-040626-2687-0","MR.B",{"user2", "passwd2"}},
				{"66-040626-2687-1","MR.C",{"user3", "passwd3"}},
				{"66-040626-2687-2","MR.D",{"user4", "passwd4"}},
				{"66-040626-2687-3","MR.E",{"user5", "passwd5"}}
			};
	printf("Enter username : ");
	scanf("%s",&user);
	printf("Enter password : ");
	scanf("%s",&pass);
	for(int i=0;i<5;i++){
		valid = checkLogin(user,pass,cs[i].stdACC.loginname,cs[i].stdACC.password);
		if(valid){
			printf("Welcome\n");
			break;
		}
	}
	if(!valid)printf("Incorrect login or password\n");
}

int checkLogin(char *login, char *passwd, char *logindb, char *passdb){
	if(!strcmp(login,logindb)){
		return !strcmp(passwd,passdb);
	}
	else return 0;
}

