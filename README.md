# ACM-networking-project
This is an open project on Computer Networking that I completed with IIT Roorkee ACM Student Chapter, in December 2020.

## Introduction
This project implements a basic Client-Server communication model using C++. Client-Server communication is accomplished by the process of **networking**, which is the process of connecting two or more computers together to share data. In this project, the 'client' application connects to the 'server' application, and this provides a basic interface for two users at both the ends to 'chat' or converse with each other, by sending and receiving messages.

## How to Run
* The 'client.cpp' file should be downloaded to the client computer and the 'server.cpp' file, to the server computer.
* Compile both files (on two separate Linux terminals), using `g++ -o client client.cpp` and `g++ -o server server.cpp`.
* Run the **server** file **first** using either `./server` (for using default connection port of 2000) or `./server <port number>`.
* Once the message 'Waiting for client to connect...' is displayed on the server terminal, run the client file using `./client <IP address of server> <port number>` (the port number should be the **same** as in the previous step). In case both the client and the server are the same computer, you could use either `./client localhost <port number>` (if the port number is not 2000) or just `./client` (here default server name is 'localhost' and default port number is 2000).
* You should see confirmation messages of the successful connection on both the terminals.

*Note:* Here *port* refers to an endpoint of the communication.

## Tech Stack Used
This project is completely written in C++ and runs on Linux operating system.

## Important Logic Used
The **original** project had the following sequence of (important) steps:
### Server side
1. Get the port number from the user (or use the default)
2. Create and initialize a `sockaddr_in` struct for the server *socket* (a means to use the endpoint for the communication), using the port number and other details
3. Create a communication endpoint and return a file descriptor for that endpoint, using `socket()`
4. *Bind* the socket to a port, using `bind()`
5. Use the socket to *listen* for incoming connections
6. When a connection request is encountered, *accept* the connection, and retrieve the ID of the client socket
7. Repeat the following steps:
 * Receive a message from the client; if it is 'exit' (without quotes), go to step 8
 * Using `cin`, get a message from the server-side user
 * Send the message to the client
 * If the message was 'exit' (without quotes), go to step 8
8. Close both the sockets

### Client side
1. Get the port number and server IP address from the user (or use the defaults)
2. Get the `hostent*` struct for the server IP address
3. Create and initialize a `sockaddr_in` struct for the client socket, using the port number, host details and other details
4. Create a communication endpoint and return a file descriptor for that endpoint, using `socket()`
5. Bind the socket to a port, using `bind()`
6. Connect to the client socket
7. Repeat the following steps:
 * Using `cin`, get a message from the client-side user
 * Send the message to the server
 * If the message was 'exit' (without quotes), go to step 8
 * Receive a message from the server; if it is 'exit' (without quotes), go to step 8
8. Close the client socket

## Results Obtained

## Additions to the Project

## Future Goals of the Project

## Working of the Project
