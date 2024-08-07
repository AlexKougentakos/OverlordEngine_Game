#pragma once

class ControllerComponent : public BaseComponent
{
public:
	ControllerComponent(const PxCapsuleControllerDesc& controllerDesc);
	~ControllerComponent() override;

	ControllerComponent(const ControllerComponent& other) = delete;
	ControllerComponent(ControllerComponent&& other) noexcept = delete;
	ControllerComponent& operator=(const ControllerComponent& other) = delete;
	ControllerComponent& operator=(ControllerComponent&& other) noexcept = delete;

	void Translate(const XMFLOAT3& pos) const;
	void Move(const XMFLOAT3& displacement, float minDistance = 0);

	void SetCollisionGroup(CollisionGroup groups);
	void SetCollisionIgnoreGroup(CollisionGroup ignoreGroups);

	XMFLOAT3 GetPosition() const;
	XMFLOAT3 GetFootPosition() const;
	void SetFootPosition(const XMFLOAT3 footPosition) const;
	PxF32 GetContactOffset() const;
	void SetContactOffset(const float offset) const;
	PxControllerCollisionFlags GetCollisionFlags() const {return m_CollisionFlag;}
	PxController* GetPxController() const { return m_pController; }

	void SetStepOffset(const float offset) const;
	void SetSlopeLimit(float limit) const;
	PxF32 GetStepOffset() const;

	CollisionGroup GetCollisionGroup() const;

protected:
	void Initialize(const SceneContext& sceneContext) override;
	void OnSceneDetach(GameScene*) override;
	void OnSceneAttach(GameScene*) override;
	void OnOwnerAttach(GameObject*) override;
	void OnOwnerDetach(GameObject*) override;

private:

	PxCapsuleControllerDesc m_ControllerDesc{};
	PxControllerFilters m_ControllerFilters;

	PxController* m_pController{};
	PxControllerCollisionFlags m_CollisionFlag{};
	PxFilterData m_CollisionGroups{ static_cast<UINT32>(CollisionGroup::Group0), 0, 0, 0 };

	void ApplyFilterData() const;
};

