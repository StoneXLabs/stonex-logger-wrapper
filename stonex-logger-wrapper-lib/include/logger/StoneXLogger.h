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

#include <logger/logger_config.h>
#include <memory>
#include <string>

enum class SEVERITY
{
	LOG_INFO,
	LOG_DEBUG,
	LOG_WARNING,
	LOG_TRACE,
	LOG_ERROR
};

class StonexLogger : public std::enable_shared_from_this<StonexLogger> {
public:
	virtual ~StonexLogger() = default;
	virtual void log(SEVERITY severity, const char* message) = 0;
	virtual void log(SEVERITY severity, const std::string& message) = 0;
};

using StonexLoggerPtr = std::shared_ptr<StonexLogger>;