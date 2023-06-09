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

#include <SpdLogLogger/SpdLogLogger.h>
#include <spdlog/spdlog.h>

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <iostream>

#include <logger/StonexLogSource.h>

SpdLogLogger::~SpdLogLogger() 
{
	spdlog::drop_all();
}

void SpdLogLogger::configure(const std::string& loggerConfigFile)
{
}

void SpdLogLogger::attach(const char * sourceId, StonexLogSource * logSource)
{
	try
	{
		spdlog::stdout_color_mt(sourceId);
	//	spdlog::basic_logger_mt(sourceId,"logs/"+std::string(sourceId)+".log");

		logSource->setLogger(shared_from_this());

	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void SpdLogLogger::log(SEVERITY severity, const char * source, const char * message)
{
	if (auto logger = spdlog::get(source)) 
	{
		switch (severity)
		{
		case SEVERITY::LOG_INFO:
			logger->info(message);
			break;
		case SEVERITY::LOG_WARNING:
			logger->warn(message);
			break;
		case SEVERITY::LOG_ERROR:
			logger->error(message);
			break;
		case SEVERITY::LOG_DEBUG:
			logger->debug(message);
			break;
		case SEVERITY::LOG_TRACE:
			logger->trace(message);
			break;
		default:
			break;
		}
	}

}
