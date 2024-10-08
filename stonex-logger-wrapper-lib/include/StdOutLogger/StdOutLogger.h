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
#include <mutex>

class StdOutLogger final : public StonexLogger{
public:
	explicit StdOutLogger(const std::string& id);
	~StdOutLogger();
	void log(SEVERITY severity, const char* message) override;
	void log(SEVERITY severity, const std::string& message) override;
private:
	std::mutex ostream_lock;
	std::string mId;
};
