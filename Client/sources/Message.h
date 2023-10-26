#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message
{
    std::string _sender;
    std::string _recipient;
    std::string _text;
public:
    Message();
    Message(std::string writer, std::string text);
    Message(std::string writer, std::string recipient, std::string text);

  std::string getSender() const;
  std::string getRecipient() const;
  std::string getText() const;

};


#endif // MESSAGE_H
