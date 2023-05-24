
#include <StdOutLogger/StdOutLogger.h>
#include <SpdLogLogger/SpdLogLogger.h>
#include <Log4CxxLogger/Log4CxxLogger.h>
#include <logger/StonexLogSource.h>
#include <fmt/format.h>

int main()
{
	std::shared_ptr<StonexLogger> logger = std::make_shared<StdOutLogger>();
	StonexLogSource src1;
	StonexLogSource src2;

	logger->attach("src1", &src1);
	logger->attach("src2", &src2);

	src1.debug("src1", fmt::format("test message {} {} {}",1,"test",false).c_str());

	src2.debug("src2", fmt::format("test message {} {} {}", 1, "test", false).c_str());


	std::shared_ptr<StonexLogger> spd_logger = std::make_shared<SpdLogLogger>();

	spd_logger->attach("src1", &src1);
	spd_logger->attach("src2", &src2);

	src1.error("src1", fmt::format("test message {} {} {}", 1, "test", false).c_str());

	src2.error("src2", fmt::format("test message {} {} {}", 1, "test", false).c_str());

	std::shared_ptr<StonexLogger> log4cxx_logger = std::make_shared<Log4CxxLogger>();


//	log4cxx_logger->configure("logger.xml");
	log4cxx_logger->configure("logger.properties");	

//	log4cxx_logger->configure("C:/Users/krzysztof.obrebski/OneDrive-StoneX/Documents/GitHub/stonex-logger/stonex-logger-app/config/logger.xml");
//	log4cxx_logger->configure("C:/Users/krzysztof.obrebski/OneDrive-StoneX/Documents/GitHub/stonex-logger/stonex-logger-app/config/logger.properties");	
	//log4cxx_logger->configure("test.txt");
	//log4cxx_logger->configure("test.xml");
	//log4cxx_logger->configure("test.config");
	//log4cxx_logger->configure("path/test.txt");
	//log4cxx_logger->configure("path/test.xml");
	//log4cxx_logger->configure("path/test.config");

	log4cxx_logger->attach("src1", &src1);
	log4cxx_logger->attach("src2", &src2);

	src1.trace("src1", fmt::format("test message {} {} {}", 1, "test", false).c_str());

	src2.debug("src2", fmt::format("test message {} {} {}", 1, "test", false).c_str());


	return 0;
}