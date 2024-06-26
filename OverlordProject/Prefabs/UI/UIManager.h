﻿#pragma once
class BombermanCharacter;
class GameLoopManager;

class Timer;

class UIManager : public GameObject
{
public:
	UIManager(std::vector<BombermanCharacter*> players);
	virtual ~UIManager() override = default;

	UIManager(const UIManager& other) = delete;
	UIManager(UIManager&& other) noexcept = delete;
	UIManager& operator=(const UIManager& other) = delete;
	UIManager& operator=(UIManager&& other) noexcept = delete;

	virtual void Initialize(const SceneContext& sceneContext) override;

	void StartTimer() const;
	void ResetTimer() const;
	void ZeroTimer() const;

protected:
	virtual void Update(const SceneContext& sceneContext) override;

private:
	std::vector<BombermanCharacter*> m_pPlayers{};
	Timer* m_pTimer{ nullptr };
};
