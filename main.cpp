#include <iostream>
#include <stdio.h>
#include "login.cpp"


using namespace std;

int main()
{

    int bracket = 123;
    int bracketc = 125;
//        printf("%c %c",bracket, bracketc);
    cout << "Hello world!" << endl;

    //POST Request
    char user[64] = "foox21";
    char pass[64] = "paulnoea2101";
    char data[1024];

    char* posturi = " %c\"agent\": %c\"name\": \"Minecraft\",\"version\": 1%c,\"username\": \"%s\",\"password\": \"%s\"%c ";

    wsprintfA( data, posturi, bracket, bracket, bracketc, user, pass,bracketc);
    //printf("%s",data);
    Request(POST, "https://authserver.mojang.com", "/authenticate", "Content-Type: application/json", data);

    printf("%s",data);
    return 0;
}
