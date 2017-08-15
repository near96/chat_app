#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main()
{
 int sock0;
 int sock;
 struct sockaddr_in addr;
 struct sockaddr_in client;
 int len;
 char a[50];
 char buf[50];
 int n;

 /* ソケットの作成 */
 sock0 = socket(AF_INET, SOCK_STREAM, 0);

 /* ソケットの設定 */
 addr.sin_family = AF_INET;
 addr.sin_port = htons(12345);
 addr.sin_addr.s_addr = INADDR_ANY;
 bind(sock0, (struct sockaddr *)&addr, sizeof(addr));

 /* TCPクライアントからの接続要求を待てる状態にする */
 listen(sock0, 5);
 sock = accept(sock0, (struct sockaddr *)&client, &len);
 len = sizeof(client);
 printf("クライアントが来たよ\n");

 /*  TCPクライアントからの接続要求を受け付ける */ 
 while(1){ 
 //while(n = (read(sock, buf, sizeof(buf))) > 0){
  memset(buf, 0, sizeof(buf));
  n = read(sock, buf, sizeof(buf));
  printf("%s",buf);
  //fgets(a,50,stdin);
  fgets(a,50,stdin);
  write(sock,a,50);
 }

 /* TCPセッションの終了*/
 close(sock);

 /* listen するsocketの終了 */
 close(sock0);

 return 0;
}
