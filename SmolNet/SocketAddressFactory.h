#pragma once

#include <WS2tcpip.h>
#include <string>

#include "SocketAddress.h"

namespace SmolNet
{
	/*
	* 
	*/
	class SocketAddressFactory
	{
	public:
		/*
		* Creates a SocketAddress pointer from a string containing the hostname
		* and port. This method will return null if there is a problem with the 
		* name conversion. 
		*
		* @param The string representing the hostname and port, delimited by ':'
		* @return A SocketAddress pointer or null.
		*/
		static SocketAddressPtr CreateIPv4FromString(const std::string inString)
		{
			size_t pos = inString.find_last_of(':');
			std::string host, service;
			if (pos != std::string::npos)
			{
				host = inString.substr(0, pos);
				service = inString.substr(pos + 1);
			}
			else
			{
				host = inString;
				// use default port...
				service = "0";
			}
			addrinfo hint;
			memset(&hint, 0, sizeof(hint));
			hint.ai_family = AF_INET;

			addrinfo* result;
			int error = getaddrinfo(host.c_str(), service.c_str(), &hint, &result);

			if (error != 0 && result != nullptr)
			{
				freeaddrinfo(result);
				return nullptr;
			}

			while (!result->ai_addr && result->ai_next)
			{
				result = result->ai_next;
			}

			if (!result->ai_addr)
			{
				freeaddrinfo(result);
				return nullptr;
			}
			auto toReturn = std::make_shared<SocketAddress>(*result->ai_addr);

			freeaddrinfo(result);

			return toReturn;
		}
	
	};
}


