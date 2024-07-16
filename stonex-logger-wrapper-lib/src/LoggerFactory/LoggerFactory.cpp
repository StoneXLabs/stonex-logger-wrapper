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

#include <LoggerFactory/LoggerFactory.h>
#include <Log4CxxLogger/Log4CxxLogger.h>
#include <STDOutLogger/STDOutLogger.h>
#include <SPDLogLogger/SpdLogLogger.h>

LoggerFactory* LoggerFactory::mInstance = nullptr;

void stonex::logger::initialize(LoggerFactory::LoggerType type)
{
	LoggerFactory::getInstance(type);
}

logger_ptr LoggerFactory::create(const std::string& id)
{
	switch (mType)
	{
	case LoggerType::STDOUT:
		return std::make_shared<StdOutLogger>(id);
		break;
	case LoggerType::SPDLOG:
		return std::make_shared<SpdLogLogger>(id);
		break;
	case LoggerType::LOG4CXX:
		return std::make_shared<Log4CxxLogger>(id);
		break;
	default:
		return nullptr;
		break;
	}
}

LoggerFactory& LoggerFactory::getInstance(LoggerType type)
{
	if (mInstance == nullptr)
	{
		mInstance = new LoggerFactory(type);
		return *mInstance;
	}
	else if (mInstance != nullptr)
		return *mInstance;
}


LoggerFactory::LoggerFactory(LoggerType type)
	:mType(type)
{
}