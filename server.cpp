#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>
#include<sys/time.h>
#include<sys/wait.h>
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	int port;
	if(argc < 2)
	{
		//if port number is not supplied, default is 2000
		port = 2000;
	}
	else
	{
		port=atoi(argv[1]);
	}
	char message[1500];
	
	//sockaddr_in struct for server (listening) socket
	sockaddr_in serverSocket;
	serverSocket.sin_family=AF_INET;
	serverSocket.sin_port=htons(port);
	serverSocket.sin_addr.s_addr=htonl(INADDR_ANY);
	//INADDR_ANY -> listen to all interfaces for connection requests
	
	//Create a communication endpoint and return a file descriptor for that endpoint
	//socket(Family, Type, Protocol)
	int serverSocketID=socket(AF_INET,SOCK_STREAM,0);
	if(serverSocketID<0)
	{
		cout<<"Unsuccessful socket()\n";
		exit(0);
	}
        
	//Bind the socket to a port
	//bind(socketID, &addressPort, sizeOfPort)
	int bindStatus=bind(serverSocketID, (struct sockaddr *)&serverSocket, sizeof(serverSocket));
	if(bindStatus<0)
	{
		cout<<"Unsuccessful bind\n";
		exit(0);
	}
 
 	cout<<"Waiting for client to connect..."<<endl;
	
	//Listen for incoming connections
	//listen(socketID, queueLimit)
	listen(serverSocketID,1);
	
 	//sockaddr_in struct of client (connecting) socket
	sockaddr_in newSocket;
   	socklen_t newSocketLen=sizeof(newSocket);
	//The fields of this struct will be filled by the accept() function
        
	//Accept the connection request
	//newID = accept(socketID, &clientAddress, &addressLength)
	int newSocketID = accept(serverSocketID, (sockaddr *) &newSocket, &newSocketLen);
 	if(newSocketID < 0)
        {
	        cout<<"Unsuccessful accept()\n";
	}
	cout<<"Client connected successfully\n";
        
	//Receive the user's choice from the client
	int choice;
	recv(newSocketID, &choice, sizeof(int), 0);

	if(choice == 1)
	{	
		//Code to chat with the client
		//Send and receive files (data)
		cout<<"Enter 'exit' (without quotes) to end the chat."<<endl;
		cout<<"Waiting for a message from client\n";
		while(1)
        	{
		
			//recv(socketID, &msgBuf, msgBufLen, flags(special options))
			recv(newSocketID, (char *)&message, sizeof(message), 0);
			if(strcmp(message,"exit") == 0)
			{
				cout<<"Session terminated"<<endl;
		        	break;
			}
			cout<<"Client: "<<message<<endl;
		
			cout<<"Server: ";
                	cin.getline(message, 1500);
                	//send - syntax similar to recv
                	send(newSocketID, (char *) &message, sizeof(message),0);
                	if(strcmp(message,"exit") == 0)
                	{
                	        cout<<"Session terminated"<<endl;
                	        break;
                	}
		
		
		}
	}	
	else if(choice == 2)
	{	
		//Code to perform mathematical computations
		while(1)
		{
                	//recv(socketID, &msgBuf, msgBufLen, flags(special options))
                	recv(newSocketID, (char *)&message, sizeof(message), 0);
                	if(strcmp(message,"exit") == 0)
                	{
                	        cout<<"Session terminated"<<endl;
                	        break;
                	}
			string str(message);
				
			string res;
	        	try
			{
				//Extract the operands and the operator from the message
				size_t i1 = str.find_first_of(" ");
				size_t i2 = str.find_last_of(" ");
 	        		double a = stod(str.substr(0, i1));
	        		double b = stod(str.substr(i2+1, 100));
	        		char op = str.at(i1+1);	
			
				//Perform the computation
				switch(op)
				{
					case '+': res = to_string(a + b);
					  break;
					case '-': res = to_string(a - b);
					  break;
					case '*': res = to_string(a * b);
					  break;
					case '/': res = to_string(a / b);
					  break;
					default: res = "Invalid operator";
		        		  break;		 
				}
                	}
			catch(...)
			{	
				res = "Invalid expression";
			}	
			strcpy(message, res.c_str());
			//send - syntax similar to recv
			send(newSocketID, (char *) &message, sizeof(message),0);
		}
	}

	//Free up the sockets
	close(newSocketID);
	close(serverSocketID);
}


