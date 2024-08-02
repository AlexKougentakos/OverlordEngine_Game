#pragma once

class BombermanCharacter;
struct GridCell;
class GridComponent;

class BombPrefab final : public GameObject
{
public:
	BombPrefab(int blastRadius, GridComponent* pGridComponent, BombermanCharacter* playerWhoPlacedBomb);
	virtual ~BombPrefab() override = default;

	BombPrefab(const BombPrefab& other) = delete;
	BombPrefab(BombPrefab&& other) noexcept = delete;
	BombPrefab& operator=(const BombPrefab& other) = delete;
	BombPrefab& operator=(BombPrefab&& other) noexcept = delete;

	virtual void Initialize(const SceneContext& gameContext) override;	

	float GetWidth() const { return m_pBombModelComponent->CalculateWidth(); }
protected:
	virtual void Update(const SceneContext& sceneContext) override;

private:
	void InitializeParticles();
	bool m_InitializedParticles{ false };
	
	ModelComponent* m_pBombModelComponent{};
	ModelComponent* m_pFuseModelComponent{};

	const float m_ExplosionTime{ 3.f };
	float m_FuseElapsedTime{0.f};
	int m_BlastRadius{ 1 };

	BombermanCharacter* m_pPlayerWhoPlacedBomb{};

	void Explode(int explosionDistance);
	void ExplodeRecursive(const GridCell& cell, int explosionDistance, std::vector<GridCell>& affectedCellsOut) const;
	GridComponent* m_pGrid{};
	const XMFLOAT3& m_CameraPosition{};

	GameObject* m_pBombFuse{};
};
