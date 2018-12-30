# ComplexSoftware_MiniProject_ClientToServer
Mini Project made for the AAU Medialogy course "Programming of Complex Software Systems"

For information pertaining to the different elements created by the group members for this project, please take a look at the wiki section in this repository.

#### Members:
- Emil Valberg-Madsen
- Nolan Rux
- Daniel Aalykke
- Stefan Nordborg Eriksen
- Mathias Sebastian Johansen
- Simon Vestergaard Laursen

## Setting Up & Running The Software
If you want to run the client and/or the server program you got two options. You can either choose to use one of the pre-build applications found within the releases folder, or build the software yourself from the source code. 

To acquire this software you can either download the source code from this page on GitHub, or go to the release section of this repository and download the 'Build.zip' folder, which contains the an .exe file for both the client and the server software.

#### WARNING: THIS APPLICATION IS ONLY USABLE ON THE WINDOWS OPERATING SYSTEM!

##### If you choose to use the pre-build executables, follow these steps:
- Run the Server.exe file
- Wait for Server program to be done with initialization 
- Once the previous step is completed, run the Client.exe file
- Enter the IP-address of your local network 
- Enter the port number: 54000
- Enter your username
- If you wish to connect with multiple clients, simply do step 3-6 again

##### If you choose to use the source code, follow these steps:
- Make sure you have the MinGW compiler installed
- Open up Command Prompt
- Enter 'cd' + the path to the server main.cpp file
- Once you're at the Server's main.cpp file enter 'g++ main.cpp -o server.exe'
- Then enter 'server.exe' in the command prompt to start up the server
- Now open a second Command Prompt window
- Use 'cd' + the path to the main.cpp file within the Client source folder
- Compile the Client's main.cpp using the previous command, 'g++ main.cpp -o client.exe'
- Run the Client by entering 'client.exe'
- Once the client is running, enter the local network's IP-address, followed by the port number: 54000, and your username
- If you wish to connect multiple clients, simply repeat step 9-10 in a new Command Prompt window

### IMPORTANT! If you want multiple clients connected to the server, make sure that the first client has send a message prior to the second client connects.
