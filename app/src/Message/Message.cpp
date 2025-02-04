#include "Message.h"

namespace ChatApp
    {
        Message::Message(const std::string &from, const std::string &to, const std::string &text)
            : _from(from), _to(to), _text(text) {}

        const std::string &Message::GetFrom() const
            {
                return _from;
            }

        const std::string &Message::GetTo() const
            {
                return _to;
            }

        const std::string &Message::GetText() const
            {
                return _text;
            }
    }
