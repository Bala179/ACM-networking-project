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

## Tech Stack Used
This project is completely written in C++ and runs on Linux operating system.

## Important Logic Used

## Results Obtained

## Additions to the Project

## Future Goals of the Project

## Working of the Project
