#pragma once

#include <logger/logger_config.h>
#include <memory>
#include <string>

class StonexLogSource;

class StonexLogger : public std::enable_shared_from_this<StonexLogger> {
public:
	virtual ~StonexLogger() = default;
	virtual void configure(const std::string& loggerConfigFile) = 0;
	virtual void attach(const char* sourceId, StonexLogSource* logSource);
	virtual void log(SEVERITY severity, const char* source, const char* message) = 0;
};