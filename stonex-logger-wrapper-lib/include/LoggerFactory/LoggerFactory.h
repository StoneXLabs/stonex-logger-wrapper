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

#pragma once

#include <logger/StoneXLogger.h>

typedef std::shared_ptr<StonexLogger> logger_ptr;

class LoggerFactory
{
public:
	enum class LoggerType
	{
		LOG4CXX,
		SPDLOG,
		STDOUT,
		UNKNOWN
	};

	logger_ptr create(const std::string& id);
	static LoggerFactory& getInstance(LoggerType type = LoggerType::UNKNOWN);
private:
	explicit LoggerFactory(LoggerType type);
	const LoggerType mType;
	static LoggerFactory* mInstance;
};

namespace stonex::logger
{
	void initialize(LoggerFactory::LoggerType type);
}