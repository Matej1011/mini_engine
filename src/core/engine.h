#ifndef ENGINE_H
#define ENGINE_H

#include "../platforms/Windows/WindowsWindow.h"

namespace mini_engine {
	class engine
	{
	public:
		engine();
		void run();
	private:
		bool init();
		void cleanup();
		void render_loop();
	private:
		bool m_running = true;
		std::unique_ptr<mini_window> m_Window;
	};
}

#endif