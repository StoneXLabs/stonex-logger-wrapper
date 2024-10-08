/*
 * Copyright 2023 StoneX Financial Ltd.
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <Log4CxxLogger/Log4CxxLogger.h>
#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/xml/domconfigurator.h>
#include <log4cxx/propertyconfigurator.h>


#if __cplusplus >= 201703L
	#include <filesystem>
#else
	#include <algorithm>
#endif

Log4CxxLogger::Log4CxxLogger(const std::string& id)
{
	mLogger = log4cxx::Logger::getLogger(id);
}

void Log4CxxLogger::log(SEVERITY severity, const char * message)
{
	if (mLogger)
	{
		switch (severity)
		{
		case SEVERITY::LOG_INFO:
			LOG4CXX_INFO(mLogger, message);
			break;
		case SEVERITY::LOG_WARNING:
			LOG4CXX_WARN(mLogger, message);
			break;
		case SEVERITY::LOG_ERROR:
			LOG4CXX_ERROR(mLogger, message);
			break;
		case SEVERITY::LOG_DEBUG:
			LOG4CXX_DEBUG(mLogger, message);
			break;
		case SEVERITY::LOG_TRACE:
			LOG4CXX_TRACE(mLogger, message);
			break;
		default:
			break;
		}
	}
}

void Log4CxxLogger::log(SEVERITY severity, const std::string& message)
{
	if (mLogger)
	{
		switch (severity)
		{
		case SEVERITY::LOG_INFO:
			LOG4CXX_INFO(mLogger, message);
			break;
		case SEVERITY::LOG_WARNING:
			LOG4CXX_WARN(mLogger, message);
			break;
		case SEVERITY::LOG_ERROR:
			LOG4CXX_ERROR(mLogger, message);
			break;
		case SEVERITY::LOG_DEBUG:
			LOG4CXX_DEBUG(mLogger, message);
			break;
		case SEVERITY::LOG_TRACE:
			LOG4CXX_TRACE(mLogger, message);
			break;
		default:
			break;
		}
	}
}
