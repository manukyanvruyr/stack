#pragma once

namespace base
{

class exception
{
public:
	exception() = default;
	~exception() = default;
	exception(const exception&) = default;
	exception(exception&&) = default;
	exception& operator=(const exception&) = default;
	exception& operator=(exception&&) = default;

public:
	virtual const char* what() const
	{
	    return "";
	}
};

}
