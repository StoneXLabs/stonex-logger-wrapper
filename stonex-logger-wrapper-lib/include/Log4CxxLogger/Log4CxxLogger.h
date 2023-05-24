#pragma once
#include <logger/StoneXLogger.h>

class Log4CxxLogger final : public StonexLogger {
public:
	void configure(const std::string& loggerConfigFile) override;
	void attach(const char* sourceId, StonexLogSource* logSource) override;

protected:
	void log(SEVERITY severity, const char* source, const char* message) override;
};