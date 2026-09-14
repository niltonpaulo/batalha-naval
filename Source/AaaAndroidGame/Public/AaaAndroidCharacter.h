#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AaaAndroidCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class AAaaAndroidCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AAaaAndroidCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	TObjectPtr<UCameraComponent> Camera;

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaSeconds) override;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void TouchPressed(const ETouchIndex::Type FingerIndex, const FVector Location);
	void TouchMoved(const ETouchIndex::Type FingerIndex, const FVector Location);
	void TouchReleased(const ETouchIndex::Type FingerIndex, const FVector Location);
	void ApplyVirtualJoystick(float DeltaSeconds);

	ETouchIndex::Type ActiveTouch;
	FVector2D JoystickAnchor;
	FVector2D JoystickVector;
};
