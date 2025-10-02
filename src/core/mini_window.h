
#ifndef MINIWINDOW_H
#define MINIWINDOW_H

#include <memory>

namespace mini_engine {
	struct window_properties {
		const char* title;
		uint32_t width;
		uint32_t height;

		window_properties(const char* Title = "Mini Engine", uint32_t Width = 800, uint32_t Height = 600):
			title(Title), width(Width), height(Height){}
	};
	class mini_window {

	public:

		virtual ~mini_window() {}
		virtual void OnUpdate() = 0;
		virtual void OnDraw() = 0;
		virtual void OnClose() = 0;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		static std::unique_ptr<mini_window> Create(const window_properties& props = window_properties());

	};
}

#endif