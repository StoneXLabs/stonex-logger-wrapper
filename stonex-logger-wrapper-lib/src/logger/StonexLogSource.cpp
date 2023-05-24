#include <logger/StonexLogSource.h>
#include <logger/StoneXLogger.h>
#include <logger/logger_config.h>
#include <thread>

#include <iostream>

StonexLogSource::StonexLogSource(const StonexLogSource & other)
{
	onLog = other.onLog;
	std::cout << __FUNCTION__ << std::endl;
}

StonexLogSource::StonexLogSource(StonexLogSource && other)
{
	onLog = other.onLog;
	other.onLog = [](SEVERITY severity, const char* source, const char* message) {};
	std::cout << __FUNCTION__ << std::endl;
}

void StonexLogSource::info(const char * source, const char * message) const
{
	std::lock_guard<std::mutex> lock(log_set_mutex);
	onLog(SEVERITY::LOG_INFO, source, message);
}

void StonexLogSource::debug(const char * source, const char * message) const
{
	std::lock_guard<std::mutex> lock(log_set_mutex);
	onLog(SEVERITY::LOG_DEBUG, source, message);
}

void StonexLogSource::warning(const char * source, const char * message) const
{
	std::lock_guard<std::mutex> lock(log_set_mutex);
	onLog(SEVERITY::LOG_WARNING, source, message);
}

void StonexLogSource::trace(const char * source, const char * message) const
{
	std::lock_guard<std::mutex> lock(log_set_mutex);
	onLog(SEVERITY::LOG_TRACE, source, message);
}

void StonexLogSource::error(const char * source, const char * message) const
{
	std::lock_guard<std::mutex> lock(log_set_mutex);
	onLog(SEVERITY::LOG_ERROR, source, message);
}

void StonexLogSource::info(const char * source, const std::string& message) const
{
	std::lock_guard<std::mutex> lock(log_set_mutex);
	onLog(SEVERITY::LOG_INFO, source, message.c_str());
}

void StonexLogSource::debug(const char * source, const std::string& message) const
{
	std::lock_guard<std::mutex> lock(log_set_mutex);
	onLog(SEVERITY::LOG_DEBUG, source, message.c_str());
}

void StonexLogSource::warning(const char * source, const std::string& message) const
{
//  std::lock_guard<std::mutex> lock(log_set_mutex);
	onLog(SEVERITY::LOG_WARNING, source, message.c_str());
}

void StonexLogSource::trace(const char * source, const std::string& message) const
{
	std::lock_guard<std::mutex> lock(log_set_mutex);
	onLog(SEVERITY::LOG_TRACE, source, message.c_str());
}

void StonexLogSource::error(const char * source, const std::string& message) const
{
	std::lock_guard<std::mutex> lock(log_set_mutex);
	onLog(SEVERITY::LOG_ERROR, source, message.c_str());
}

void StonexLogSource::setLogger(std::shared_ptr<StonexLogger> sink)
{
	std::lock_guard<std::mutex> lock(log_set_mutex);

	mLogSink = sink;
	if (mLogSink)
		onLog = std::bind(&StonexLogger::log, mLogSink, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	else
		onLog = [](SEVERITY severity, const char* source, const char* message) {};
	
}
