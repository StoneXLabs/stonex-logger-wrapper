
#include <benchmark/benchmark.h>

#include <StdOutLogger/StdOutLogger.h>
#include <SpdLogLogger/SpdLogLogger.h>
#include <Log4CxxLogger/Log4CxxLogger.h>
#include <logger/StonexLogSource.h>
#include <fmt/format.h>

class Fixture_spdlog_logger : public benchmark::Fixture 
{
public:
	void SetUp(const ::benchmark::State& state) override {
		logger = std::make_shared<SpdLogLogger>();
		src = new StonexLogSource;
		logger->attach("src", src);

	}

	void TearDown(const ::benchmark::State& state) override {
		delete src;
		logger.reset();
	}

	std::shared_ptr<StonexLogger> logger;
	StonexLogSource* src;
};

BENCHMARK_DEFINE_F(Fixture_spdlog_logger, spdlog_test)(benchmark::State& state)
{
	for (auto _ : state) {
		src->info("src", fmt::format("test message {} {} {}", 1, "test", false).c_str());
	}
}

BENCHMARK_REGISTER_F(Fixture_spdlog_logger, spdlog_test);

class Fixture_stdout_logger : public benchmark::Fixture
{
public:
	void SetUp(const ::benchmark::State& state) override {
		logger = std::make_shared<StdOutLogger>();
		src = new StonexLogSource;
		logger->attach("src", src);

	}

	void TearDown(const ::benchmark::State& state) override {
		delete src;
		logger.reset();
	}

	std::shared_ptr<StonexLogger> logger;
	StonexLogSource* src;
};

BENCHMARK_DEFINE_F(Fixture_stdout_logger, stdout_log_test)(benchmark::State& state)
{
	for (auto _ : state) {
		src->debug("src", fmt::format("test message {} {} {}", 1, "test", false).c_str());
	}
}

BENCHMARK_REGISTER_F(Fixture_stdout_logger, stdout_log_test);


class Fixture_log4cxx_logger : public benchmark::Fixture
{
public:
	void SetUp(const ::benchmark::State& state) override {
		logger = std::make_shared<Log4CxxLogger>();
		logger->configure("");
		src = new StonexLogSource;
		logger->attach("src", src);

	}

	void TearDown(const ::benchmark::State& state) override {
		delete src;
		logger.reset();
	}

	std::shared_ptr<StonexLogger> logger;
	StonexLogSource* src;
};

BENCHMARK_DEFINE_F(Fixture_log4cxx_logger, log4cxx_log_test)(benchmark::State& state)
{
	for (auto _ : state) {
		src->debug("src", fmt::format("test message {} {} {}", 1, "test", false).c_str());
	}
}

BENCHMARK_REGISTER_F(Fixture_log4cxx_logger, log4cxx_log_test);



//BENCHMARK_MAIN();


//
//static void BM_spdlog_logger(benchmark::State& state)
//{
//	std::shared_ptr<StonexLogger> logger = std::make_shared<SpdLogLogger>();
//	StonexLogSource src1;
//	logger->attach("src1", &src1);
//	auto msg = fmt::format("test message {} {} {}", 1, "test", false).c_str();
//
//	for (auto _ : state) {
//		src1.debug("src1", fmt::format("test message {} {} {}", 1, "test", false).c_str());
//	}
//
//}
//
//static void BM_log4cxx_logger(benchmark::State& state)
//{
//	std::shared_ptr<StonexLogger> logger = std::make_shared<Log4CxxLogger>();
//	logger->configure();
//	StonexLogSource src1;
//	logger->attach("src1", &src1);
//	auto msg = fmt::format("test message {} {} {}", 1, "test", false).c_str();
//
//	for (auto _ : state) {
//		src1.debug("src1", fmt::format("test message {} {} {}", 1, "test", false).c_str());
//	}
//
//}
//
//

//BENCHMARK(BM_stdout_logger);
//BENCHMARK(BM_spdlog_logger);
//BENCHMARK(BM_log4cxx_logger);

//BENCHMARK_MAIN();

