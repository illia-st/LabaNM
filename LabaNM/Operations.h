#pragma once
class Operations {
public:
	template <typename T>
	static int Sgn(T val) {
		return (T(0) < val) - (val < T(0));
	}
};