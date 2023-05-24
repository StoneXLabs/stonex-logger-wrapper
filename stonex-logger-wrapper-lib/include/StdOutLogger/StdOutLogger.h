#pragma once
#include <logger/StoneXLogger.h>
#include <mutex>

class StdOutLogger final : public StonexLogger{
public:
	StdOutLogger();
	~StdOutLogger();
	void configure(const std::string& loggerConfigFile) override;

protected:
	void log(SEVERITY severity, const char* source, const char* message) override;
private:
	std::mutex ostream_lock;
};
