#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>
#include<sys/time.h>
#include<sys/wait.h>
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	char const *serverName;
	int port;
	
	//default server name is 'localhost' and default port number is 2000
	if(argc == 1)
	{
		serverName = "localhost";
		port = 2000;
	}
	else if(argc == 2)
	{
		serverName = argv[1];
		port = 2000;
	}
	else
	{
		serverName = argv[1];
		port = atoi(argv[2]);
	}
	char message[1500];

	//Get host details
	struct hostent* host = gethostbyname(serverName);
	
	//Initialize the sockaddr_in struct for the client socket
	sockaddr_in clientSocket;
	clientSocket.sin_family = AF_INET;
	clientSocket.sin_port = htons(port);
	clientSocket.sin_addr = ** (struct in_addr **)host->h_addr_list;

	//File descriptor for the client socket
	int clientSocketID = socket(AF_INET,SOCK_STREAM,0);
	
	//Connect to the server
	//connect(socketID, &serverAddr, addrLen)
	int status = connect(clientSocketID,(sockaddr *)&clientSocket,sizeof(clientSocket));
	if (status<0)
	{
		cout<<"Error Connecting"<<endl;
		exit(0);
	}
	cout<<"Successful connection!\n"<<endl;
	
	int choice;
	cout << "Enter:\n1-to start a chat with the server\n2-to ask the server to perform mathematical operations"<<endl;
	cin>>choice;

	//Clear the buffer before the next step
	char buffer[1];
	cin.getline(buffer, 1);
	
	//Send the user's choice to the server
	send(clientSocketID, &choice, sizeof(int), 0);
	
	string instructions;
	switch(choice)
	{
		case 1: instructions = "Enter 'exit' (without quotes) to end the chat.";
			break;
		case 2: instructions = "Enter expressions ONLY of the form n1 <space> op <space> n2, or 'exit' (without quotes) to disconnect.";
			break;
		default: instructions = "";
		 	break;	 
	}	
	if(choice == 1 || choice == 2)
	{	
		cout<<endl;
		cout<<instructions<<endl;
		//Send and receive data
		while(1)
		{
			cout<<"Client: ";
			cin.getline(message, 1500);
			send(clientSocketID, (char *) &message, sizeof(message),0);
			if(strcmp(message,"exit") == 0)
			{
				cout<<"Session terminated"<<endl;
				break;
			}

			recv(clientSocketID, (char *) &message, sizeof(message),0);
			if (strcmp(message,"exit") == 0)
			{
				cout<<"Session terminated"<<endl;
				break;
			}
			cout<<"Server: "<<message<<endl;
		}	
	}
	else
	{	
		cout<<"Invalid choice"<<endl;
	}	
  
	//Close the client socket
	close(clientSocketID);
}
