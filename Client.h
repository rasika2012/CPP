// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 


class Client{
	private:
		int sock = 0, valread; 
		struct sockaddr_in serv_addr; 
		char buffer[1024] = {0}; 
		char * destn ;
		int portn=0;
	public:
		int setup(char * dest, int port){
			destn = dest;
			portn = port;
			
			
			
		}
		char* send_request(char* buff){
			

			if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
				printf("\n Socket creation error \n"); 
				return "Null"; 
			} 

			serv_addr.sin_family = AF_INET; 
			serv_addr.sin_port = htons(portn); 
			

			if(inet_pton(AF_INET, destn, &serv_addr.sin_addr)<=0) { 
				printf("\nInvalid address/ Address not supported \n"); 
				return "Null"; 
			} 

			if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
				printf("\nConnection Failed \n"); 
				return "Null";
			} 
			send(sock , buff , strlen(buff) , 0 ); 
			printf("Client : message sent\n"); 
			valread = read( sock , buffer, 1024); 
			return buffer; 
		}

};
// int main(int argc, char const *argv[]) 
// { 
	
// 	Client cli;
// 	cli.setup("192.168.8.101",8080);
// 	for ( int i =0;i<10;i++){
// 		printf("Recieved : %s\n",cli.send_request("Tata Bye!"));
// 	}
// } 
