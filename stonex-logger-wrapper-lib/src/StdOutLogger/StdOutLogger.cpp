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

#include <StdOutLogger/StdOutLogger.h>
#include <iostream>
#include <iomanip>

StdOutLogger::StdOutLogger()
{
	log(SEVERITY::LOG_INFO, "StdOutLogger", "logger created");
}

StdOutLogger::~StdOutLogger()
{
	log(SEVERITY::LOG_INFO, "StdOutLogger", "logger destroyed");
}

void StdOutLogger::configure(const std::string& loggerConfigFile)
{
}

void StdOutLogger::log(SEVERITY severity, const char * source, const char * message)
{
//	std::lock_guard<std::mutex> lk(ostream_lock);

	if (severity != SEVERITY::LOG_ERROR)
		std::cout << "[" << source << "]" << " " << message<<std::endl;
	else				 
		std::cerr << "[" << source << "]" << " " << message << std::endl;
}
