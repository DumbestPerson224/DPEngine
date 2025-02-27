#include <cmath>
#include <cstdlib>
class ExponentialTrackingAimAssist {
private:
	float strength;
	bool aimAssist;

public:
	friend class LinearTrackingAimAssist;
	ExponentialTrackingAimAssist(float strength, bool aimAssist) {
		this->strength = strength;
		this->aimAssist = aimAssist;
	}

	void compute_strength(float scopeX, float scopeY, float scopeZ, float scopeSpeed, float opponentX, float opponentY, float opponentZ, float opponentDistance, float opponentSpeed) {
		if (isAimAssistOn()) {
			strength += (std::pow(std::fabs(scopeX - opponentX) + std::fabs(scopeY - opponentY - 1) + std::fabs(scopeZ - opponentZ - 1) + std::fabs(opponentSpeed - scopeSpeed) / opponentDistance, 2));
		}
	}

	void decrease_strength(float amount) {
		if (isAimAssistOn() && amount <= strength) {
			strength -= amount;
		}
	}

	bool isAimAssistOn() const {
		return aimAssist;
	}

	bool flip_aim_assist() {
		aimAssist ^= aimAssist;
		return aimAssist;
	}
};

class LinearTrackingAimAssist : public ExponentialTrackingAimAssist {
public:
	void increase_strength(float scopeX, float scopeY, float scopeZ, float scopeSpeed, float opponentX, float opponentY, float opponentZ, float opponentSpeed, float opponentDistance) {
		strength += std::fabs(scopeX - opponentX) + std::fabs(scopeY - opponentY) + std::fabs(scopeZ - opponentZ) + std::(scopeSpeed - opponentSpeed) / opponentDistance;
	}

	void decease_strength(float amount) {
		if (isAimAssistOn() && amount <= strength) {
			strength -= amount;
		}
	}
};
