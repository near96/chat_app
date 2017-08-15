#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
 struct sockaddr_in server;
 int sock;
 int sock0;
 char buf[50];
 char a[50];
 int n;

 /* ソケットの作成 */
 sock = socket(AF_INET, SOCK_STREAM, 0);

 /* 接続先指定用構造体の準備 */
 server.sin_family = AF_INET;
 server.sin_port = htons(12345);
 server.sin_addr.s_addr = inet_addr("127.0.0.1");

 /* サーバに接続 */
 connect(sock, (struct sockaddr *)&server, sizeof(server));
 printf("サーバに接続完了");
 while(1){
 memset(buf, 0, sizeof(buf));
 fgets(a,50,stdin);
 write(sock,a,50);
 n = read(sock, buf, sizeof(buf));
 printf("%s",buf); 
 }
 //if(fgets(a,50,stdin) != NULL){
 // fgets(a,50,stdin);
 // write(sock,a,50);
 //}
 //if(n < 1){
 //break;
 //}
 //printf("%s",buf);

 /* socketの終了 */
 close(sock);

 return 0;

}
