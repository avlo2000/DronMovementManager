#pragma once
#include "Sample.h"

namespace controller {
	class Generator {
	public:
		Generator() {};
		~Generator() {};
		Sample Generate(int rangeStart, int rangeEnd, int sampleSize);
	};
}
