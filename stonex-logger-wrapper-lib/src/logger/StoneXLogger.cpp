#pragma once

#include <logger/StoneXLogger.h>
#include <logger/StonexLogSource.h>

void StonexLogger::attach(const char * sourceId, StonexLogSource * logSource)
{
	logSource->setLogger(shared_from_this());
	log(SEVERITY::LOG_INFO, sourceId, "log source attached");
}
