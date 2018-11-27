
#include "netheaders.h"

int main (int agrc, char **argv)
{
	int sockfd,newSockfd,sin_size;
	struct sockaddr_in serverAddr;
	sockfd = socket ( AF_INET, SOCK_STREAM,0);
	if (sockfd == -1)
	{
		perror("socket");
		exit(1);
	
	}else{
			serverAddr.sin_family = AF_INET;
			serverAddr.sin_port = htons(9002);
			serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
			memset((&serverAddr.sin_zero),'\0',8);
			
			bind(sockfd,(struct sockaddr *)&serverAddr,sizeof(struct sockaddr));

			if ((listen(sockfd,10)) != -1)
			{
				sin_size = sizeof(struct sockaddr_in);
				newSockfd = accept(sockfd,(struct sockaddr *)&serverAddr,&sin_size);
				if (newSockfd == -1)
				{
					perror("accept");
					exit(3);
				}else{
					char info[250];
					char in[254];
					send(newSockfd,"hello from server",20,0);
					
						while(1){	
							char action;
							recv(newSockfd,&info,100,0);
							printf("client:>> %s\n",info);
							memset(info,'\0',250);
							printf("\n");
							fflush(stdin);
							printf("data to send:>> ");
							fgets(in,sizeof(in),stdin);
							send(newSockfd,in,100,0);
							memset(&in,'\0',254);
							printf("\n");

						//	recv(sockfd,&info,sizeof(info),0);
						//	printf(" client:>>%s\n",info);
						//	memset(&info,'\0',250);

							if(action == 'q'){
								printf("quiting the server");
								exit(0);
							}
						}
				
				
				}
			
			
			
			}else{
			
					perror("listen");
					exit(2);

			
			}


					
					
					
				
	}



return 0;
}
/*
 *THE SERVER CODE IS WORKING AS EXPECTED
 *WORK ON THE LOOPING PART TO IMPROVE THE COMMUNICATION*
 * */
