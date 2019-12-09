#pragma once

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
		static SocketAddressPtr CreateIPv4FromString(const std::string &inString);
	
	};
}


