#include "PlayScene.hpp"
#include "MachineGunTurret_model2.hpp"
#include "PhotonBullet.hpp"
#include "AudioHelper.hpp"

const int MachineGunTurret_model2::Price = 50;
MachineGunTurret_model2::MachineGunTurret_model2(float x, float y) :
	Turret("play/tower-base.png", "play/turret-4.png", x, y, 200, Price, 0.5) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}

void MachineGunTurret_model2::CreateBullet() {
	Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
	float rotation = atan2(diff.y, diff.x);
	Engine::Point normalized = diff.Normalize();
	// Change bullet position to the front of the gun barrel.
	getPlayScene()->BulletGroup->AddNewObject(new PhotonBullet(Position + normalized * 36, diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}
