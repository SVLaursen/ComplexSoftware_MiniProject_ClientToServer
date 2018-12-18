#include <iostream>
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

using namespace std;

int main(int argc, char *argv[])
{
    //Initialize winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    int wsOk = WSAStartup( ver, &wsData);
    if (wsOk!= 0)
    {
        cerr << "Can't initialize winsock! Quitting" <<endl;
        return 0;
    }

    //Create a socket
    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if(listening == INVALID_SOCKET)
    {
        cerr << "Can't create a socket! Quitting" <<endl;
        return 0;
    }

    //bind the socket to an ip address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    hint.sin_addr.S_un.S_addr = INADDR_ANY;

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    //Tell winsock the socket is for listening
    listen(listening, SOMAXCONN);

	fd_set master;
	FD_ZERO(&master);

	FD_SET(listening, &master);

	while (true)
	{
		fd_set copy = master;

		int socketCount = select(0, &copy, nullptr, nullptr, nullptr);

		for (int i = 0; i < socketCount; i++)
		{
			SOCKET sock = copy.fd_array[i];
			if (sock == listening)
			{
				// Accept a new connection
				SOCKET client = accept(listening, nullptr, nullptr);

				// Add the new connection to the list of connected clients
				FD_SET(client, &master);

				// Send a welcome message to the connected client 
				string welcomeMsg = "Welcome to the Chat Server!";
				send(client, welcomeMsg.c_str(), welcomeMsg.size() + 1, 0);
			}
			else
			{
				char buf[4096];
				ZeroMemory(buf, 4096);

				// Recieve message
				int bytesIn = recv(sock, buf, 4096, 0);
				if (bytesIn <= 0)
				{
					// Drop the client
					closesocket(sock);
					FD_CLR(sock, &master);
				}
				else
				{
					// Send message to the other clients
					for (int i = 0; i < master.fd_count; i++)
					{
						SOCKET outSock = master.fd_array[i];
						if (outSock != listening && outSock != sock)
						{
							send(outSock, buf, bytesIn, 0);
						}
					}
				}
				
			}
		}
	}


    //Clean up winsock
    WSACleanup();
    return 0;
}


////wait for a connection
//
//sockaddr_in client;
//int clientsize = sizeof(client);
//
//socket clientsocket = accept(listening, (sockaddr*)&client, &clientsize);
//
//char host[ni_maxhost];  //client's remote name
//char service[ni_maxhost];//servie (i.e. port) the client is connected on
//
//zeromemory(host, ni_maxhost);
//zeromemory(service, ni_maxhost);
//
//if (getnameinfo((sockaddr*)&client, sizeof(client), host, ni_maxhost, service, ni_maxserv, 0) == 0)
//{
//	cout << host << " connected on port " << service << endl;
//}
//else
//{
//	inet_ntop(af_inet, &client.sin_addr, host, ni_maxhost);
//	cout << host << " connected on port " <<
//		ntohs(client.sin_port) << endl;
//}
//
//
////close listening socket
//closesocket(listening);
//
////while loop: accept and echo message back to client
//char buf[4096];
//
//while (true)
//{
//	zeromemory(buf, 4096);
//
//	//wait for client to send data
//	int bytesreceived = recv(clientsocket, buf, 4096, 0);
//	if (bytesreceived == socket_error)
//	{
//		cerr << "error in recv(). quitting" << endl;
//		break;
//	}
//
//	if (bytesreceived == 0)
//	{
//		cout << "client disconnected " << endl;
//		break;
//	}
//	//echo message back to client
//	send(clientsocket, buf, bytesreceived + 1, 0);
//}