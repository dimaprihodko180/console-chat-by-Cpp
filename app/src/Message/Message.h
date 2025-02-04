#pragma once
#include "../User/User.h"

class Message
    {
        const string _from;
        const string _to;
        const string _text;

    public:
        Message(const string &from, const string to, const string text);

        const string &GetFrom() const;

        const string &GetTo() const;

        const string &GetText() const;
    };
