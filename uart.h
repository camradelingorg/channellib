#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED
//----------------------------------------------------------------------------------------------------------------------
#include <string>
#include <termios.h>
#include <sys/epoll.h>
//----------------------------------------------------------------------------------------------------------------------
#include "basicchannel.h"
#include "config.h"
//----------------------------------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------------------------------
class ChanPool;
//----------------------------------------------------------------------------------------------------------------------
class COMPort : public BasicChannel
{
public:
    COMPort(shared_ptr<ChanPool> chp) : BasicChannel(chp) {chanType="COMPort";}
    virtual ~COMPort(){}
    virtual int init();
    virtual void thread_run();
    virtual void config_com();
    virtual int send_packet(MessageBuffer *packet, enum io_state state, bool zipped=0);
    virtual int recv_packet(std::unique_ptr<MessageBuffer> *packet, enum io_state state);
    virtual int com_write_chunk(int fd, char *buf, int nbytes);
public:
    UARTConfig_t			tcfg;
    struct termios  		Config;
    uint32_t      			SymTO;
    string                  dev;
};
//----------------------------------------------------------------------------------------------------------------------
#endif // UART_H_INCLUDED
