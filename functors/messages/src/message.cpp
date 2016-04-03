// Copyright 2016

#include <string>

#include "message.hpp"

// Constructor
Message::Message(std::string sender, std::string subject, std::string date,
                 std::string recipient, std::string replyto,
                 std::string attachments, std::string body) {
    this->msFields.resize(HeaderField::N_FIELDS);

    this->msFields[HeaderField::SENDER]      = sender;
    this->msFields[HeaderField::SUBJECT]     = subject;
    this->msFields[HeaderField::DATE]        = date;
    this->msFields[HeaderField::RECIPIENT]   = recipient;
    this->msFields[HeaderField::REPLYTO]     = replyto;
    this->msFields[HeaderField::ATTACHMENTS] = attachments;
    this->msFields[HeaderField::BODY]        = body;
}

// Getters
std::string Message::getHeaderComponent(HeaderField _field) const {
    return this->msFields[_field];
}
std::vector <std::string> Message::getHeader(void) const {
    return this->msFields;
}
