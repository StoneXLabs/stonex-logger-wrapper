#pragma once

#include <logger/logger_config.h>

#include <memory>
#include <functional>
#include <mutex>

class StonexLogger;

class StonexLogSource
{
public:
	StonexLogSource() = default;
	StonexLogSource(const StonexLogSource& other);
	StonexLogSource(StonexLogSource&& other);
	void info(const char* source, const char* message) const;
	void debug(const char* source, const char* message) const;
	void warning(const char* source, const char* message) const;
	void trace(const char* source, const char* message) const;
	void error(const char* source, const char* message) const;

	void info(const char* source, const std::string& message) const;
	void debug(const char* source, const std::string& message) const;
	void warning(const char* source, const std::string& message) const;
	void trace(const char* source, const std::string& message) const;
	void error(const char* source, const std::string& message) const;

	virtual void setLogger(std::shared_ptr<StonexLogger> sink);

protected:
	std::shared_ptr<StonexLogger> mLogSink;
	std::function<void(SEVERITY, const char*, const char*)> onLog = [](SEVERITY severity, const char* source, const char* message) {};

private:
	mutable std::mutex log_set_mutex;
};

