#pragma once
#include "net_common.h"
#include "net_message.h"
#include "net_tsqueue.h"
#include "net_connection.h"	

namespace olc
{
	namespace net
	{
		template <typename T>
		class client_interface
		{
			client_interface() : m_socket(m_context)
			{

			}

			virtual ~client_interface()
			{
				Disconnect();
			}

		public:
			bool Connect(const std::string& host, const uint16_t port)
			{

				return false;
			}

			void Disconnect()
			{

			}

			bool IsConnected()
			{
				return false;
			}

			tsqueue<owned_message<T>>& Incomming()
			{
				return m_qMessageIn;
			}

		protected:
			asio::io_context m_context;
			std::thread thrContext;
			asio::ip::tcp::socket m_socket;
			std::unique_ptr<connection<T>> m_connection;

		private:
			tsqueue<owned_message<T>> m_qMessagesIn;
		};
	}
}