#pragma once
#include <logger/StoneXLogger.h>
#include <spdlog/spdlog.h>

class SpdLogLogger final : public StonexLogger{
public:
	~SpdLogLogger();
	void configure(const std::string& loggerConfigFile) override;
	void attach(const char* sourceId, StonexLogSource* logSource) override;
protected:
	void log(SEVERITY severity, const char* source, const char* message) override;
};
