#ifndef BTCTOOLS_UTILS_IPGENERATOR
#define BTCTOOLS_UTILS_IPGENERATOR

#include <string>
#include <list>
#include <boost/coroutine2/all.hpp>

#ifdef _WIN32
 #include <winsock2.h>
#else
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
#endif

namespace btctools
{
    namespace utils
    {
        using std::string;
		
		using coro_ip_long_t = boost::coroutines2::coroutine<uint32_t>;
		using IpLongYield = coro_ip_long_t::push_type;
		using IpLongSource = coro_ip_long_t::pull_type;

		using coro_string_t = boost::coroutines2::coroutine<string>;
		using IpStrYield = coro_string_t::push_type;
		using IpStrSource = coro_string_t::pull_type;

		class IpGenerator
		{
		public:
			IpGenerator(const string &ipRange);
			IpStrSource genIpRange();
			IpStrSource genIpRange(int stepSize);
			bool hasNext();
			string next();
			string getLastIp();
			string getNextIp();
			string getEndIp();
			uint64_t getIpNumber();

		private:
			uint32_t ipLongBegin_;
			uint32_t ipLongEnd_;

			/********************** static functions at below **********************/
		public:
			static uint32_t ip2long(const string &ipString);
			static string long2ip(const uint32_t &ipLong);
			static void splitIpRange(string ipRangeString, string &begin, string &end);
            
		}; // end of class


		using IpGeneratorList = std::list<IpGenerator>;

		class IpGeneratorGroup
		{
		public:
			IpGeneratorGroup();

			void addIpRange(const string &ipRange);
			void addIpRange(IpGenerator ips);
			void clear();

			IpStrSource genIpRange();
			IpStrSource genIpRange(int stepSize);

			bool hasNext();
			string next();

			string getLastIp();
			string getNextIp();
			string getEndIp();

			uint64_t getIpNumber();

		private:
			uint64_t ipNumber_;
			IpGeneratorList ipGenerators_;
		}; // end of class


    } // namespace utils
} // namespace btctools

#endif //BTCTOOLS_UTILS_IPGENERATOR
