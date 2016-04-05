// Copyright 2016

#include <string>

#include "message.hpp"

// Constructor
Message::Message(std::string sender, std::string subject, std::string date,
                 std::string recipient, std::string replyto,
                 std::string attachments, std::string body) {
    msFields.resize(HeaderField::N_FIELDS);

    msFields[HeaderField::SENDER]      = sender;
    msFields[HeaderField::SUBJECT]     = subject;
    msFields[HeaderField::DATE]        = date;
    msFields[HeaderField::RECIPIENT]   = recipient;
    msFields[HeaderField::REPLYTO]     = replyto;
    msFields[HeaderField::ATTACHMENTS] = attachments;
    msFields[HeaderField::BODY]        = body;
}

// Getters
std::string Message::getHeaderComponent(HeaderField _field) const {
    return msFields[_field];
}
std::vector <std::string> Message::getHeader(void) const {
    return msFields;
}
