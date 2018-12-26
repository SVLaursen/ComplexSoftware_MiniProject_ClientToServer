#include <iostream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

std::string ipAddress;
int port;
std::string username;

void setupUser()
{
	// IP Address of the server
	std::cout << "Please input the server's IP address\n";
	std::cout << ">";
	//std::string ipAddress;
	getline(std::cin, ipAddress);

	// Listening port # on the server
	std::cout << "Please input the port #\n";
	std::cout << ">";
	std::string textToNum;
	getline(std::cin, textToNum);
	port = std::stoi(textToNum);

	//Set username
	std::cout << "Please enter your username\n";
	std::cout << ">";
	getline(std::cin, username);
}

int main(int argc, char *argv[])
{
	setupUser();

    // Initialize WinSock
    WSAData data;
    WORD ver = MAKEWORD(2, 2);
    int wsResult = WSAStartup(ver, &data);

    if (wsResult != 0)
    {
        std::cerr << "Can't start Winsock, Err #" << wsResult << std::endl;
        return 0;
    }

    // Create socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == INVALID_SOCKET)
    {
        std::cerr << "Can't create socket, Err #" << WSAGetLastError() << std::endl;
        WSACleanup();
        return 0;
    }

    // Fill in a hint structure
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    // Connect to server
    int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));

    if (connResult == SOCKET_ERROR)
    {
        std::cerr << "Can't connect to server, Err #" << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return 0;
    }


	// Send username to server
	send(sock, username.c_str(), username.size() + 1, 0);

    // Do-while loop to send and receive data
    char buf[4096];
    std::string userInput;

	// Recieve welcome message from server
	ZeroMemory(buf, 4096);
	int bytesReceived = recv(sock, buf, 4096, 0);

	if (bytesReceived > 0)
	{
		// Echo response to console
		std::cout << "SERVER> " << std::string(buf, 0, bytesReceived) << std::endl;
	}

    do
    {
        // Prompt the user for some text
        std::cout << "> ";
        getline(std::cin, userInput);

        if (userInput.size() > 0)		// Make sure the user has typed in something
        {
            // Send the text
            int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);

            if (sendResult != SOCKET_ERROR)
            {
                // Wait for response
                ZeroMemory(buf, 4096);
                int bytesReceived = recv(sock, buf, 4096, 0);

                if (bytesReceived > 0)
                {
                    // Echo response to console
                    std::cout << std::string(buf, 0, bytesReceived) << std::endl;
                }
            }
        }

    } while (userInput.size() > 0);

    // Gracefully close down everything
    closesocket(sock);
    WSACleanup();
    return 0;
}
