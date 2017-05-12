#include "SocketAddress.h"

namespace SmolNet
{
	SocketAddress::SocketAddress(uint32_t inAddress, uint16_t inPort)
	{
		getAsSockAddrIn()->sin_family = AF_INET;
		getAsSockAddrIn()->sin_addr.S_un.S_addr = htonl(inAddress);
		getAsSockAddrIn()->sin_port = htons(inPort);
	}

	SocketAddress::SocketAddress(const sockaddr& inSockAddr)
	{
		memcpy(&m_socketAddress, &inSockAddr, sizeof(sockaddr));
	}

	size_t SocketAddress::getSize()
	{
		return sizeof(sockaddr);
	}

	sockaddr_in* SocketAddress::getAsSockAddrIn()
	{
		return reinterpret_cast<sockaddr_in*>(&m_socketAddress);
	}

}

