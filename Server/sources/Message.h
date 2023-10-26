#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message
{
    int _id; //
    std::string _sender;
    std::string _recipient;
    std::string _text;
    int _destID; //
public:
    Message();
    Message(std::string writer, std::string text);//сообщение в чат

  bool searchByTarget(int) const;
  std::string getSender() const;
  std::string getRecipient() const;
  int getDest() const;
  int getID() const;
  std::string getText() const;

};


#endif // MESSAGE_H
