#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sendmsgsocket() {
	int connectionSocket;
	char sentence[5000];
	struct hostent* hp;
	connectionSocket = socket(AF_INET, SOCK_STREAM, 0);
	hp = gethostbyname("astra");
	puts(hp->h_name);
	struct sockaddr_in sin;
	bzero((char*)&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(6789);
	bcopy(hp->h_addr, (char*)&sin.sin_addr, hp->h_length);


	connect(connectionSocket, (struct sockaddr*)&sin, sizeof(sin));
	for (;;) {
		fgets(sentence, 5000, stdin);
		sentence[5000 - 1] = '\0';
		write(connectionSocket, sentence,5000);
		char answer[5000];
	
		
		read(connectionSocket, answer, 5000);
		if (answer != NULL) {
			puts("heyyyy answer: ");
			puts(answer);
		}
		
	}

	close(connectionSocket);
}

int main() {
	sendmsgsocket();
}
