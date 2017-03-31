#pragma once

#include "common.h"
#include "../lua/oolua/oolua.h"

namespace btctools
{
	namespace miner
	{
		class ScannerHelper
		{
		public:
			ScannerHelper();
			void makeRequest(WorkContext *context);
			void makeResult(WorkContext *context, btctools::tcpclient::Response *response);

		private:
			OOLUA::Script script_;
		};

	} // namespace tcpclient
} // namespace btctools