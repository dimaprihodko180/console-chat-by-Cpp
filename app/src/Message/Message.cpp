#include "Message.h"

Message::Message(const string& from, const string to, const string text) :_from(from), _to(to), _text(text) {}

const string& Message::GetFrom()const
{
	return _from;
}

const string& Message::GetTo()const
{
	return _to;
}

const string& Message::GetText()const
{
	return _text;
}