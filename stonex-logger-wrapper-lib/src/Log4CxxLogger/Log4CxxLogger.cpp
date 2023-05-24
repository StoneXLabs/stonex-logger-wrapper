#include <Log4CxxLogger/Log4CxxLogger.h>
#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/xml/domconfigurator.h>
#include <log4cxx/propertyconfigurator.h>

#include <logger/StonexLogSource.h>


#if __cplusplus >= 201703L
	#include <filesystem>
#else
	#include <algorithm>
#endif

void Log4CxxLogger::configure(const std::string& loggerConfigFile)
{
	#if __cplusplus >= 201703L
		if (std::filesystem::path(loggerConfigFile).extension() == ".xml")
		{
			log4cxx::xml::DOMConfigurator::configure(loggerConfigFile);
		}
		else if (std::filesystem::path(loggerConfigFile).extension() == ".config")
		{
			log4cxx::PropertyConfigurator::configure(loggerConfigFile);
		}
		else
			log4cxx::BasicConfigurator::configure();
	#else
	auto extension_separator = loggerConfigFile.find_last_of('.');

		if (extension_separator != std::string::npos)
		{
			if (loggerConfigFile.substr(extension_separator) == ".properties")
			{
				log4cxx::PropertyConfigurator::configure(loggerConfigFile);
			}
			else if (loggerConfigFile.substr(extension_separator) == ".xml")
			{
				log4cxx::xml::DOMConfigurator::configure(loggerConfigFile);
			}
			else
				log4cxx::BasicConfigurator::configure();
		}
		else
			log4cxx::BasicConfigurator::configure();
	#endif

}

void Log4CxxLogger::attach(const char * sourceId, StonexLogSource * logSource)
{
	auto logger = log4cxx::Logger::getLogger(sourceId);
	logSource->setLogger(shared_from_this());
}

void Log4CxxLogger::log(SEVERITY severity, const char * source, const char * message)
{
	if (auto logger = log4cxx::Logger::getLogger(source))
	{
		switch (severity)
		{
		case SEVERITY::LOG_INFO:
			LOG4CXX_INFO(logger, message);
			break;
		case SEVERITY::LOG_WARNING:
			LOG4CXX_WARN(logger, message);
			break;
		case SEVERITY::LOG_ERROR:
			LOG4CXX_ERROR(logger, message);
			break;
		case SEVERITY::LOG_DEBUG:
			LOG4CXX_DEBUG(logger, message);
			break;
		case SEVERITY::LOG_TRACE:
			LOG4CXX_TRACE(logger, message);
			break;
		default:
			break;
		}
	}
}
