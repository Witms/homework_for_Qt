#include "Message.h"

Message::Message() : _sender(""), _recipient("") , _text("")
{
}
Message::Message(std::string writer, std::string text) : _sender(writer), _text(text)
{
}

Message::Message(std::string writer, std::string recipient, std::string text) : _sender(writer), _recipient(recipient), _text(text)
{
}

std::string Message::getSender() const {
    return _sender;
}

std::string Message::getText() const {
    return _text;
}

std::string Message::getRecipient() const
{
    return _recipient;
}
