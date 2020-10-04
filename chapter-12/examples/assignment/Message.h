#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <string_view>

class Message
{
private:
    inline static size_t id {0};
    std::string* pMessage;
    size_t message_id;
public:
    explicit Message(std::string_view message = "") : 
        pMessage {new std::string(message)}, message_id {Message::id++}
    {
#ifdef DEBUG
        std::cout << "Create message with ID " << this->message_id << '\n';
#endif
    };

    Message(const Message& m)
    {
#ifdef DEBUG
        std::cout << "Copy message with ID " << m.message_id << '\n';
#endif
        pMessage = new std::string(*m.pMessage);
        this->message_id = Message::id++;
    }

    ~Message() 
    { 
#ifdef DEBUG 
        std::cout << "Deleteing message with ID " << this->message_id << '\n';
#endif
        delete pMessage; 
    };

    inline Message& operator=(const Message& msg)
    {
        *pMessage = *msg.pMessage;
        return *this;
    }
};

#endif 