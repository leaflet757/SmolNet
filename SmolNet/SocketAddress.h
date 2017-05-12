#pragma once

#include <iostream>
#include <memory>
#include <WinSock2.h>

namespace SmolNet
{
	/*
	* Wrapper for the 'sockaddr' structure. Used for specifying source and
	* destination addresses.
	*/
	class SocketAddress
	{
	public:
		/*
		* Constructs a new SocketAddress object. Requires a 4-byte IPv4
		* address and 2-byte port value.
		*
		* @param inAddress An IPv4 address.
		* @param inPort The accepting port.
		*/
		SocketAddress(uint32_t inAddress, uint16_t inPort);
		
		/*
		* Constructs a new SocketAddress object from a native sockaddr
		* structure. Copies all data from inSockAddr to this object.
		*/
		SocketAddress(const sockaddr& inSockAddr);
		
		/*
		* Returns the size of sockaddr.
		*/
		size_t getSize();

	private:
		/*
		* Internal sockaddr type.
		*/
		sockaddr m_socketAddress;

		/*
		* Returns a pointer to a sockaddr IPv4 type.
		*/
		sockaddr_in* getAsSockAddrIn();
	};

	/*
	* Shared pointer of SocketAddress object.
	*/
	typedef std::shared_ptr<SocketAddress> SocketAddressPtr;
}

