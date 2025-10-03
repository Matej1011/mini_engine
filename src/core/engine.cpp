#include "engine.h"
#include "Time.h"

#include <chrono>
#include <stdexcept>
#include <iostream>

namespace mini_engine
{
	engine::engine()
	{
		m_Window = WindowsWindow::Create();
		m_StartTime = 0.0f;
	}
	void engine::run()
	{
		if (!init())
			throw std::runtime_error("Failed to Initialize Engine\n");
		render_loop();
	}
	bool engine::init()
	{
		std::cout << "Engine Initialized\n";

		// bruh
		m_StartTime = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count() / 1000000.0f;
		return true;
	}
	void engine::cleanup()
	{
		std::cout << "Cleaning up the engine";
	}
	void engine::render_loop()
	{
		Time::timeScale = 0.0f;
		while (m_running)
		{

			auto startTime = std::chrono::high_resolution_clock::now();
			// keep running the engine
			if (!m_running)
			{
				cleanup();
				break;
			}
			m_Window->OnUpdate();

			auto endTime = std::chrono::high_resolution_clock::now();
			auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTime).time_since_epoch().count();
			auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime).time_since_epoch().count();

			Time::_unscaledDeltaTime = (float)(end - start) / 1000.0f;
			Time::_deltaTime = Time::_unscaledDeltaTime * Time::timeScale;

			Time::_realTimeSinceStartup = end / 1000000.0f - m_StartTime;
			Time::_time = Time::_realTimeSinceStartup * Time::timeScale;
			Time::_frameCount++;

			printf("Time Format: %s\tDeltaTime: %f\tUnscaled Delta Time: %f\tTime Scale: %f\tTime: %f\tReal Time Since Startup: %f\tFrame Count: %d\n",
				   Time::GetLocalTimeFormat().c_str(), Time::deltaTime(), Time::unscaledDeltaTime(), Time::timeScale, Time::time(),
				   Time::realTimeSinceStartup(), Time::frameCount());
		}
	}
}
