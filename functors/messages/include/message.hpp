// Copyright 2016

#ifndef _message_hpp_
#define _message_hpp_

#include <iostream>
#include <string>
#include <vector>

class Message {
 private:
    // HEADER
    std::vector<std::string> msFields;

 public:
    enum HeaderField {
        SENDER = 0,   // (FROM) Email of the sender of the message.
        SUBJECT,      // The message's subject or description of the topic of the message.
        DATE,         // Date & Time the message was received.
        RECIPIENT,    // (TO) Email of the recipient of the message.
        REPLYTO,      // Email that will become the recipiente of any reply to the message.
        ATTACHMENTS,  // Flag indicating the existance of any files attached to the message.
        BODY,         // The actual content of the message.
        N_FIELDS      // Just to keep track of the number of fields.
    };

 public:
    Message(std::string = "", std::string = "", std::string = "",
            std::string = "", std::string = "",
            std::string = "", std::string = "");

    std::string getHeaderComponent(HeaderField _field) const;
    std::vector <std::string> getHeader(void) const;

    void setSender(const std::string &_h)    {msFields[HeaderField::SENDER]      = _h;}
    void setSubject(const std::string &_h)   {msFields[HeaderField::SUBJECT]     = _h;}
    void setDateTime(const std::string &_h)  {msFields[HeaderField::DATE]        = _h;}
    void setRecipient(const std::string &_h) {msFields[HeaderField::RECIPIENT]   = _h;}
    void setReplyTo(const std::string &_h)   {msFields[HeaderField::REPLYTO]     = _h;}
    void setAttachment(bool _h)              {msFields[HeaderField::ATTACHMENTS] = _h;}


    inline friend std::ostream &operator<< (std::ostream &_os, const Message &_Obj) {
        _os << "{\n"
            << "  From: ["        << _Obj.msFields[HeaderField::SENDER]      << "]\n"
            << "  Subject: ["     << _Obj.msFields[HeaderField::SUBJECT]     << "]\n"
            << "  Date: ["        << _Obj.msFields[HeaderField::DATE]        << "]\n"
            << "  To: ["          << _Obj.msFields[HeaderField::RECIPIENT]   << "]\n"
            << "  Reply: ["       << _Obj.msFields[HeaderField::REPLYTO]     << "]\n"
            << "  Attachments: [" << _Obj.msFields[HeaderField::ATTACHMENTS] << "]\n"
            << "  Body:\n "       << _Obj.msFields[HeaderField::BODY]        << "\n}";

        return _os;
    }
};

class MessageSorter {
 public:
    // take the field to sort by in the constructor
    MessageSorter(const Message::HeaderField &_field) : m_field(_field) {}
    bool operator()(const Message &_m1, const Message &_m2) {
        return _m1.getHeaderComponent(m_field) < _m2.getHeaderComponent(m_field);
    }
 private:
    Message::HeaderField m_field;
};

#endif
