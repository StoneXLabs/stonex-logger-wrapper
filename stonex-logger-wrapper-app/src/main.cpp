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
#include <SpdLogLogger/SpdLogLogger.h>
#include <Log4CxxLogger/Log4CxxLogger.h>
#include <LoggerFactory/LoggerFactory.h>
#include <fmt/format.h>
#include <thread>
#include <sstream>
#include <log4cxx/xml/domconfigurator.h>

//#define LOGGER_LOG4CXX

#ifdef LOGGER_LOG4CXX
#define LOGGER_TYPE LoggerFactory::LoggerType::LOG4CXX
#endif // LOGGER_LOG4CXX

#ifdef LOGGER_SPDLOG
#define LOGGER_TYPE LoggerFactory::LoggerType::SPDLOG
#endif // LOGGER_SPDLOG

#ifdef LOGGER_STDOUT
#define LOGGER_TYPE LoggerFactory::LoggerType::STDOUT
#endif // LOGGER_STDOUT

#ifndef LOGGER_TYPE
#define LOGGER_TYPE LoggerFactory::LoggerType::UNKNOWN
#endif // LOGGER_TYPE

class TestClass
{
public:
	explicit TestClass(const std::string& id)
	{
		mLogger = LoggerFactory::getInstance().create(id);

	}

	void fun1() {
		if (mLogger) {
			mLogger->log(SEVERITY::LOG_DEBUG, __FUNCTION__);
		}
	}
	void fun2() {
		if (mLogger) {
			mLogger->log(SEVERITY::LOG_INFO, __FUNCTION__);
		}
	}
	void fun3() {
		if (mLogger) {
			mLogger->log(SEVERITY::LOG_WARNING, __FUNCTION__);
		}
	}

private:
	std::shared_ptr<StonexLogger> mLogger;

};

void test_1() {

	switch (LOGGER_TYPE)
	{
	case LoggerFactory::LoggerType::STDOUT:
		break;
	case LoggerFactory::LoggerType::SPDLOG:
		break;
	case LoggerFactory::LoggerType::LOG4CXX:
		log4cxx::xml::DOMConfigurator::configure("bin/logger.xml");
		break;
	default:
		break;
	}

	TestClass t1("com.stonex.app.obj1");
	TestClass t2("com.stonex.app.obj2");

	t1.fun1();
	t1.fun2();
	t1.fun3();

	t2.fun1();
	t2.fun2();
	t2.fun3();
}

void test_synchronization()
{

	switch (LOGGER_TYPE)
	{
	case LoggerFactory::LoggerType::STDOUT:
		break;
	case LoggerFactory::LoggerType::SPDLOG:
		break;
	case LoggerFactory::LoggerType::LOG4CXX:
		log4cxx::xml::DOMConfigurator::configure("bin/logger.xml");
		break;
	default:
		break;
	}

	TestClass t1("com.stonex.app.obj1");
	TestClass t2("com.stonex.app.obj2");

	auto test_fun = [](TestClass& log_client) {
		for (int i = 0; i < 10; i++) {
			std::stringstream ss;
			ss << std::this_thread::get_id();
			log_client.fun1();
			log_client.fun2();
			log_client.fun3();
		}
	};

	std::thread th1(std::bind(test_fun, std::ref(t1)));
	std::thread th2(std::bind(test_fun, std::ref(t2)));


	std::stringstream ss;
	ss << std::this_thread::get_id();

	for (int i = 0; i < 10 ; i++)
	{
		t1.fun1();
		t1.fun2();
		t1.fun3();

		t2.fun1();
		t2.fun2();
		t2.fun3();
	}

	th1.join();
	th2.join();
}



int main()
{
	stonex::logger::initialize(LOGGER_TYPE);
	test_1();
    test_synchronization();

	return 0;
}