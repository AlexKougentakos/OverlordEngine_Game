﻿#pragma once

class BombermanCharacter;

enum class GamePhase
{
	PreRound,
	Round,
	PostRound
};

class GameLoopManager : public GameObject, public Observer<BombermanCharacter>, public Subject<GameLoopManager>
{
public:
	GameLoopManager(const std::vector<BombermanCharacter*>& characters);
	virtual ~GameLoopManager() override = default;

	GameLoopManager(const GameLoopManager& other) = delete;
	GameLoopManager(GameLoopManager&& other) noexcept = delete;
	GameLoopManager& operator=(const GameLoopManager& other) = delete;
	GameLoopManager& operator=(GameLoopManager&& other) noexcept = delete;

	void IncreaseRoundNumber() { ++m_RoundNumber; }

	void DrawOnGUI();

protected:
	void Initialize(const SceneContext& sceneContext) override;
	void Update(const SceneContext& sceneContext) override;

	void OnNotify(BombermanCharacter* source, const std::string& field) override;


private:
	const float m_PreRoundTime{ 5.f }; //Seconds
	const float m_RoundTime{ 120.f }; //Seconds
	const float m_PostRoundTime{ 5.f }; //Seconds

	float m_ElapsedRoundTime{0.f};

	int m_RoundNumber{ 1 };

	const std::vector<BombermanCharacter*>& m_pPlayers{};

	void SwitchToNextPhase();

	GamePhase m_GamePhase{ GamePhase::PreRound };
	SceneContext m_SceneContext{};
};
