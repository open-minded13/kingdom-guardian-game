#ifndef MACHINEGUNTURRET_MODEL2_HPP
#define MACHINEGUNTURRET_MODEL2_HPP
#include "PlayScene.hpp"
#include "Bullet.hpp"
#include "Turret.hpp"

class PlayScene;
class MachineGunTurret_model2: public Turret {
public:
	static const int Price;
    MachineGunTurret_model2(float x, float y);
	void CreateBullet() override;
};
#endif // MACHINEGUNTURRET_MODEL2_HPP

