#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include<netinet/in.h>
#include<arpa/inet.h>

#include <netdb.h>
int main( int argc,char **argv)
{
	int sockfd;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if (sockfd == -1)
	{
		fprintf(stderr,"an error occured in creating socket");

		exit(1);
	}else{
			//struct hostent *gethostbyname(const char *name);
			/*The address information*/	
			struct sockaddr_in addr;
			addr.sin_family = AF_INET;
			addr.sin_port = htons(9002);/*convert the port to BIG-ENDIAN*/
			addr.sin_addr.s_addr = inet_addr("127.0.0.1");

			/*create the connection and handle errors*/
			if (connect(sockfd,(struct sockaddr *)&addr,sizeof(addr)) == -1)
			{
				perror("connection");
				exit(4);
			
			}else{
				//	host = gethostbyname(sockfd);	
				//	printf("host name :%s\n",host->h_name);
					char server_response[255];
					recv(sockfd,&server_response,sizeof(server_response),0); 
					printf("The server says >>> %s\n",server_response);
					/*THIS AREA OF THE CODE STILL NEED TO BE WORKED ON...*/
					send(sockfd,"client ready ",20,0);
					printf("Do you want to keep charting(Y/N)");
					char res;
					scanf(" %c",&res);
					if (res == 'N' || res == 'n')
					{
						printf("the program will now terminate\n");
						close(sockfd);
						exit(0);
					
					}else{
							char tosend[255];
					
							while (1)
							{   
								
								recv (sockfd,&server_response,sizeof(server_response),0);
								printf(" server:>>%s\n",server_response);
								memset(&server_response,'\0',255);/*clear the buffer*/
						
								printf("To send:>>");
								scanf(" %[^\n]s",tosend);
								send(sockfd,tosend,100,0);
								memset(&tosend,'\0',255);
								printf("\n");

							//	printf("press q to exit chat\n");
							//	char cont;
							//	scanf(" %c",&cont);
							//	if (cont == 'q'){
							//		break;
							//	}
							
							
							}
					
					
					
					}

					close(sockfd);
			
			
			
			}


	
	
	
	}



	return 0;
}/*
*THE CODE IS WORKING WELL THOUGH AM STILL HAVING ISSUES  *
*IMPROVE HOW THE CLIENT COMMUNICATES TO SERVER          *
*DO MORE ON ERROR HANDLING                               *
*/
