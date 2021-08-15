#ifndef MESSAGEBUFFER_H
#define MESSAGEBUFFER_H
//----------------------------------------------------------------------------------------------------------------------
#include <vector>
#include <memory>
//----------------------------------------------------------------------------------------------------------------------
//channel messages types
enum MessageType {
    CHAN_DATA_PACKET = 1,
    CHAN_OPEN_PACKET = 2,
    CHAN_CLOSE_PACKET = 3,
    CHAN_DATA_PACKET_ZIPPED = 4
};
//----------------------------------------------------------------------------------------------------------------------
using namespace std;
class MessageBuffer
{
    enum MessageType msgType;
    std::vector<char> data;
    uint32_t fd=-1;
    string chanaddr="";
public:
    uint32_t seqnum=0;
    MessageBuffer(uint32_t cfd, size_t length, enum MessageType type, string chaddr="");
    MessageBuffer(MessageBuffer* src);
    enum MessageType Type() {return msgType;}
    void SetType(enum MessageType type) {msgType = type;}
    char* Data() {return data.data();}
    uint32_t Length() {return data.size();}
    uint32_t getfd(){return fd;}
    void setfd(uint32_t newfd){fd=newfd;}
    string getChanAddr(){return chanaddr;}
};
//----------------------------------------------------------------------------------------------------------------------
#endif //MESSAGEBUFFER_H
