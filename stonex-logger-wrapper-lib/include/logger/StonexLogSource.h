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

