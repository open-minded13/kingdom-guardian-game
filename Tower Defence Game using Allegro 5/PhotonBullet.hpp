#ifndef PHOTONBULLET_HPP
#define PHOTONBULLET_HPP
#include "Bullet.hpp"

class PhotonBullet : public Bullet {
public:
	explicit PhotonBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
	void OnExplode(Enemy* enemy) override;
};

#endif // FIREBULLET_HPP
