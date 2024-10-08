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

StdOutLogger::StdOutLogger(const std::string& id)
	:mId(id)
{
	log(SEVERITY::LOG_INFO, "logger created");
}

StdOutLogger::~StdOutLogger()
{
	log(SEVERITY::LOG_INFO, "logger destroyed");
}

void StdOutLogger::log(SEVERITY severity, const char * message)
{
//	std::lock_guard<std::mutex> lk(ostream_lock);

	if (severity != SEVERITY::LOG_ERROR)
		std::cout << "[" << mId << "]" << " " << message<<std::endl;
	else				 
		std::cerr << "[" << mId << "]" << " " << message << std::endl;
}

void StdOutLogger::log(SEVERITY severity, const std::string& message)
{
	if (severity != SEVERITY::LOG_ERROR)
		std::cout << "[" << mId << "]" << " " << message << std::endl;
	else
		std::cerr << "[" << mId << "]" << " " << message << std::endl;
}
