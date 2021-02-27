# ACM-networking-project
This is an open project on Computer Networking that I completed with IIT Roorkee ACM Student Chapter, in December 2020.

## Introduction
This project implements a basic Client-Server communication model using C++. Client-Server communication is accomplished by the process of **networking**, which is the process of connecting two or more computers together to share data. In this project, the 'client' application connects to the 'server' application, and this provides a basic interface for two users at both the ends to 'chat' or converse with each other, by sending and receiving messages.

## How to Run
* The 'client.cpp' file should be downloaded to the client computer and the 'server.cpp' file, to the server computer.
* Compile both files (on two separate Linux terminals), using `g++ -o client client.cpp` and `g++ -o server server.cpp`.
* Run the **server** file **first** using either `./server` (for using the default connection port of 2000) or `./server <port number>`.
* Once the message 'Waiting for client to connect...' is displayed on the server terminal, run the client file using `./client <IP address of server> <port number>` (the port number should be the **same** as in the previous step). In case both the client and the server are the same computer, you could use either `./client localhost <port number>` (if the port number is not 2000) or just `./client` (here the default server name is 'localhost' and the default port number is 2000).
* You should see confirmation messages of the successful connection on both the terminals.

*Note:* Here *port* refers to an endpoint of the communication.

## Tech Stack Used
This project is completely written in C++ and runs on Linux operating system.

## Important Logic Used
The **original** project (before modification) had the following sequence of (important) steps:
### Server side
1. Get the port number from the user
2. Create and initialize a `sockaddr_in` struct for the server *socket* (a means to use the endpoint for the communication), using the port number and other details
3. Create a communication endpoint and return a file descriptor for that endpoint, using `socket()`
4. *Bind* the socket to a port, using `bind()`
5. Use the socket to *listen* for incoming connections
6. When a connection request is encountered, *accept* the connection, and retrieve the ID of the client socket
7. Repeat the following steps:
 * Receive a message from the client; if it is 'exit' (without quotes), go to step 8
 * Display the message
 * Using `cin`, get a message from the server-side user
 * Send the message to the client
 * If the message was 'exit' (without quotes), go to step 8
8. Close both the sockets

### Client side
1. Get the port number and server IP address from the user
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
 * Display the message
8. Close the client socket

## Results Obtained
The client-server communication model was implemented successfully - messages sent from the client side successfully reached the server side (and vice versa), and a simple chatting interface was established. Entering 'exit' at either end terminated both the programs together.

## Additions to the Project
After completing the project, I made the following additions to the project to further build my skills:
1. I provided a default port number (2000) and a default host name (localhost) in case the user does not enter either of these as command-line arguments.
2. The original project, as I discovered, could not send more than one word at a time (words here are sequences of characters demarcated by spaces). To fix this, instead of using `cin>>...` for input, I used `cin.getline(...)`. Then it became possible to send multiple words.
3. In addition, I added an extra feature to the project - to make the server do **simple arithmetic calculations** instead of starting a chat. In the modified project, after a successful connection is made, the user (at the client side) is asked whether he/she wants to start a chat or ask the server to do arithmetic calculations. This choice is sent to the server. If the first option is chosen, the project works as described above. If the second option is chosen, the client-side user can enter an expression of the form 'num1 \<space\> operator \<space\> num2' and the message is sent to the server. The server extracts the operands and the operator, and the result is returned back to the client (note here that there is *no* user at the server side in this case). This process continues until the user types 'exit' (as before).

## Future Goals of the Project
After making modifications to the project as I mentioned above, I realized that client-server communication is a useful tool. While the basic arithmetic operations I implemented in this project can be implemented without using socket programming as well (that is, without the need of a server), I realized that if the program was more complex and had a number of files occupying a lot of space, it would be inconvenient to store all the files on the client computer, and instead store them on a larger computer (i.e., the server). With networking it becomes possible to run a program/piece of code that is not stored locally on your system, making it useful for larger applications. With the above points in mind, one of the future goals of this project is to develop it into a larger application of some kind which harnesses the power of networking (for example, using it to send files from the server to the client, along with some other functions). Another goal might be to develop a suitable front-end for the application to improve the user experience.

## Working of the Project
1. Working of the 'chat' function
![client-server-chat](https://user-images.githubusercontent.com/69714469/109390380-4a33c100-7937-11eb-983a-27526da5f4ad.png)
2. Working of the 'arithmetic operations' function
![client-server-arithmetic](https://user-images.githubusercontent.com/69714469/109390480-e65dc800-7937-11eb-8d6d-4b003c78ba6f.png)
