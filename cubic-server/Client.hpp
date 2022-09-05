#ifndef D23DD5CC_1F28_49BB_B77D_E244C60CC705
#define D23DD5CC_1F28_49BB_B77D_E244C60CC705

#include <arpa/inet.h>
#include <thread>
#include <deque>

class Client
{
public:
    Client(int sockfd, struct sockaddr_in addr);
    ~Client();

    void networkLoop();

    void setRunningThread(std::thread *thread);
    std::thread *getRunningThread();

    bool isDisconnected() const;

private:
    const int _sockfd;
    const struct sockaddr_in _addr;
    bool _is_running;
    std::thread *_current_thread;
    std::deque<uint8_t> _recv_buffer;

protected:
};

#endif /* D23DD5CC_1F28_49BB_B77D_E244C60CC705 */
