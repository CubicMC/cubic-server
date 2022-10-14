#ifndef D23DD5CC_1F28_49BB_B77D_E244C60CC705
#define D23DD5CC_1F28_49BB_B77D_E244C60CC705

#include <arpa/inet.h>
#include <thread>
#include <deque>
#include <vector>
#include "common.hpp"

class Client
{
public:
    Client(int sockfd, struct sockaddr_in addr);
    ~Client();

    void networkLoop();

    void setRunningThread(std::thread *thread);
    std::thread *getRunningThread();

    [[nodiscard]] bool isDisconnected() const;

    void sendData(const std::vector<uint8_t> &data);

    std::vector<uint8_t> &get_recv_buffer();

    [[nodiscard]] protocol::ClientStatus getStatus() const {
        return _status;
    }

    void setStatus(protocol::ClientStatus status) {
        _status = status;
    }

private:
    void _sendData();

    const int _sockfd;
    const struct sockaddr_in _addr;
    bool _is_running;
    std::thread *_current_thread{};
    std::vector<uint8_t> _recv_buffer;
    std::vector<uint8_t> _send_buffer;
    protocol::ClientStatus _status;

protected:
};

#endif /* D23DD5CC_1F28_49BB_B77D_E244C60CC705 */
