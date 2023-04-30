#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


struct SSH{
    char PORT[8];
    char IP[18];
    char USER[36];
};

void menu(){
    printf("Welcome to SSH command maker!\n");
    printf("This program was coded by mov.\n");
    printf("Version: SSHMaker 1.0\n");
    printf("Note: This is a very basic SSH command maker.\n");
    printf("Type start to get started!\n");
}
void lower_string(char *string){
    int i = 0;

    while(string[i]){
        string[i] = tolower(string[i]);
        i++;
    }

}

int main(){
    char input[11];
    struct SSH s;

    menu();
    while(1){
        printf(">> ");
        fgets(input, sizeof(input), stdin);
        lower_string(input);

        if(strncmp(input, "exit", 4) == 0){
            exit(0);
        }
        else if(strncmp(input, "start", 5) == 0){

            printf("\nEnter the IP of the ssh server: ");
            fgets(s.IP, sizeof(s.IP), stdin);
            printf("IP Address of the SSH server >> %s\n", s.IP);

            s.IP[strcspn(s.IP, "\n")] = '\0';

            printf("Enter the port of the SSH server: ");
            fgets(s.PORT, sizeof(s.PORT), stdin);  
            printf("Port of the SSH Server >> %s\n", s.PORT);

            s.PORT[strcspn(s.PORT, "\n")] = '\0';
            
            printf("Enter the username: "); 
            fgets(s.USER, sizeof(s.USER), stdin);
            s.USER[strcspn(s.USER, "\n")] = '\0';

            printf("Command generated!\nssh -p %s %s@%s", s.PORT, s.USER, s.IP);
            getchar();
            exit(0);

        }
        else{
            printf("\nPlease enter a valid input: start/exit.\n");
        }
    }

    return 0;
}
