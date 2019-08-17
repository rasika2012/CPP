#include <iostream>
#include <string>
#include "./Client.h"
#include "./Server.h"

using namespace std;

int main(){
    Client cli;
    cli.setup("127.0.0.1",8000);
    printf("Server Said: %s\n",cli.send_request("Hi,Server!"));
}
