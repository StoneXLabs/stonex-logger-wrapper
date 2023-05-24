
#include <StdOutLogger/StdOutLogger.h>
#include <SpdLogLogger/SpdLogLogger.h>
#include <Log4CxxLogger/Log4CxxLogger.h>
#include <logger/StonexLogSource.h>
#include <fmt/format.h>
#include <thread>
#include <sstream>

void test_1() {
	std::shared_ptr<StonexLogger> logger = std::make_shared<StdOutLogger>();
	StonexLogSource src1;
	StonexLogSource src2;

	logger->attach("src1", &src1);
	logger->attach("src2", &src2);

	src1.debug("src1", fmt::format("test message {} {} {}", 1, "test", false).c_str());

	src2.debug("src2", fmt::format("test message {} {} {}", 1, "test", false).c_str());


	std::shared_ptr<StonexLogger> spd_logger = std::make_shared<SpdLogLogger>();

	spd_logger->attach("src1", &src1);
	spd_logger->attach("src2", &src2);

	src1.error("src1", fmt::format("test message {} {} {}", 1, "test", false).c_str());

	src2.error("src2", fmt::format("test message {} {} {}", 1, "test", false).c_str());

	std::shared_ptr<StonexLogger> log4cxx_logger = std::make_shared<Log4CxxLogger>();
	log4cxx_logger->configure("");

	log4cxx_logger->attach("src1", &src1);
	log4cxx_logger->attach("src2", &src2);

	src1.info("src1", fmt::format("test message {} {} {}", 1, "test", false).c_str());

	src2.info("src2", fmt::format("test message {} {} {}", 1, "test", false).c_str());
}

void test_synchronization() 
{
	auto test_fun = [](StonexLogSource& log_client, const char* source, const char* message) {
		while (1) {
			std::stringstream ss;
			ss << std::this_thread::get_id();
			log_client.info(ss.str().c_str(), "test message");
		}
	};

	auto thread_test_fun = [](std::shared_ptr<StonexLogger> logger, const char* message) {
		while (1)
		{
			std::stringstream ss;
			ss << std::this_thread::get_id();
			StonexLogSource src2;
			logger->attach(ss.str().c_str(), &src2);

			src2.info(ss.str().c_str(), message);
			src2.info(ss.str().c_str(), message);
		}
	};


	std::shared_ptr<StonexLogger> logger = std::make_shared<StdOutLogger>();

	StonexLogSource src1;

	logger->attach("src1", &src1);

	std::thread t1(std::bind(test_fun, std::ref(src1), "test", "test\n"));
	std::thread t2(std::bind(thread_test_fun, std::ref(logger), "test\n"));


	std::stringstream ss;
	ss << std::this_thread::get_id();

	while (1) 
	{
		StonexLogSource src2;
		logger->attach(ss.str().c_str(), &src2);
		src2.info(ss.str().c_str(), "test message");
		src2.info(ss.str().c_str(), "test message");
		src2.info(ss.str().c_str(), "test message");
		src2.info(ss.str().c_str(), "test message");
	}



	t1.join();
//	t2.join();


	//class test {
	//public:
	//	void fun() { fmt::print("hello\n"); }
	//	void fun2(const char* msg) { fmt::print(msg); }
	//	void fun3(const char* msg, const char* msg2) { fmt::print(msg); fmt::print(msg2); }
	//};

	//test TC;

	//auto test_fun = [](StonexLogSource& log_client, const char* source, const char* message) {log_client.info("log client", "test message"); };


	//std::thread t1(&test::fun, std::ref(TC));
	//std::thread t2(&test::fun2, std::ref(TC), "test\n");
	//std::thread t3(std::bind(&test::fun3, &TC, "test", "test\n"));
	//std::thread t4(std::bind(&test::fun3, &TC, "test", "test\n"));
//	std::thread t2(&StonexLogSource::info, std::ref(TC), std::bind("test log", "test log"));
}

int main()
{
	
	test_synchronization();

	return 0;
}