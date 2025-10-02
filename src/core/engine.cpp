#include "engine.h"
#include <stdexcept>
#include <iostream>

namespace mini_engine {
	engine::engine()
	{
		m_Window = WindowsWindow::Create();
	}
	void engine::run() {
		if (!init()) throw std::runtime_error("Failed to Initialize Engine\n");
		render_loop();
	}
	bool engine::init() {
		std::cout << "Engine Initialized\n";
		return true;
	}
	void engine::cleanup() {
		std::cout << "Cleaning up the engine";
	}
	void engine::render_loop() {
		while (m_running) {
			//keep running the engine
			if (!m_running) { cleanup(); break; }
			m_Window->OnUpdate();
		}
	}
}
