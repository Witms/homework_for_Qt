#include "Message.h"

//сообщение в чат
Message::Message() : _sender(""), _recipient("") , _text("")
{
}
Message::Message(std::string writer, std::string text) : _sender(writer), _text(text)
{
}

Message::Message(std::string writer, std::string recipient, std::string text) : _sender(writer), _recipient(recipient), _text(text)
{
}

bool Message::searchByTarget(int n) const {
    return (_destID == n);
}

std::string Message::getSender() const {
    return _sender;
}

int Message::getDest() const {
    return _destID;
}

std::string Message::getText() const {
    return _text;
}

int Message::getID() const {
    return _id;
}

std::string Message::getRecipient() const
{
    return _recipient;
}
