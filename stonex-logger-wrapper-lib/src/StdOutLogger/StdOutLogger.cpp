#include <StdOutLogger/StdOutLogger.h>
#include <iostream>
#include <iomanip>

StdOutLogger::StdOutLogger()
{
	log(SEVERITY::LOG_INFO, "StdOutLogger", "logger created");
}

StdOutLogger::~StdOutLogger()
{
	log(SEVERITY::LOG_INFO, "StdOutLogger", "logger destroyed");
}

void StdOutLogger::configure(const std::string& loggerConfigFile)
{
}

void StdOutLogger::log(SEVERITY severity, const char * source, const char * message)
{
//	std::lock_guard<std::mutex> lk(ostream_lock);

	if (severity != SEVERITY::LOG_ERROR)
		std::cout << "[" << source << "]" << " " << message<<std::endl;
	else				 
		std::cerr << "[" << source << "]" << " " << message << std::endl;
}
