#include <iostream>
#include <string>
#include "./Client.h"
#include "./Server.h"

using namespace std;

int main(){
    Server srv;
    srv.setup(8000);
    printf("Client Said: %s\n",srv.listen_request("Hi,Client Baba!!"));
}
