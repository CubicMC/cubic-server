#ifndef D23DD5CC_1F28_49BB_B77D_E244C60CC705
#define D23DD5CC_1F28_49BB_B77D_E244C60CC705

#include <arpa/inet.h>

class Client
{
public:
    Client(int sockfd, struct sockaddr_in addr);
    ~Client();

private:
protected:
};

#endif /* D23DD5CC_1F28_49BB_B77D_E244C60CC705 */
