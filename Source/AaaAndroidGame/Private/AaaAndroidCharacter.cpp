#include "AaaAndroidCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputEvents.h"

AAaaAndroidCharacter::AAaaAndroidCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	ActiveTouch = ETouchIndex::Touch1;

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	GetCharacterMovement()->MaxAcceleration = 2048.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2048.0f;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 650.0f;
	SpringArm->SetRelativeRotation(FRotator(-55.0f, -45.0f, 0.0f));
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 8.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
}

void AAaaAndroidCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	ApplyVirtualJoystick(DeltaSeconds);
}

void AAaaAndroidCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AAaaAndroidCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AAaaAndroidCharacter::MoveRight);
	PlayerInputComponent->BindTouch(EInputEvent::Pressed, this, &AAaaAndroidCharacter::TouchPressed);
	PlayerInputComponent->BindTouch(EInputEvent::Moved, this, &AAaaAndroidCharacter::TouchMoved);
	PlayerInputComponent->BindTouch(EInputEvent::Released, this, &AAaaAndroidCharacter::TouchReleased);
}

void AAaaAndroidCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0.0f)
	{
		const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AAaaAndroidCharacter::MoveRight(float Value)
{
	if (Controller && Value != 0.0f)
	{
		const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AAaaAndroidCharacter::TouchPressed(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (FingerIndex != ETouchIndex::Touch1)
	{
		return;
	}

	ActiveTouch = FingerIndex;
	JoystickAnchor = FVector2D(Location.X, Location.Y);
	JoystickVector = FVector2D::ZeroVector;
}

void AAaaAndroidCharacter::TouchMoved(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (FingerIndex != ActiveTouch)
	{
		return;
	}

	const FVector2D Current(Location.X, Location.Y);
	FVector2D Delta = Current - JoystickAnchor;
	if (Delta.SizeSquared() > 4096.0f)
	{
		Delta.Normalize();
		Delta *= 64.0f;
	}

	JoystickVector = Delta / 64.0f;
	JoystickVector.X = FMath::Clamp(JoystickVector.X, -1.0f, 1.0f);
	JoystickVector.Y = FMath::Clamp(JoystickVector.Y, -1.0f, 1.0f);
}

void AAaaAndroidCharacter::TouchReleased(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (FingerIndex != ActiveTouch)
	{
		return;
	}

	ActiveTouch = ETouchIndex::Touch1;
	JoystickVector = FVector2D::ZeroVector;
}

void AAaaAndroidCharacter::ApplyVirtualJoystick(float DeltaSeconds)
{
	if (!Controller || JoystickVector.IsNearlyZero())
	{
		return;
	}

	const float AxisValue = 1.0f;
	const FVector Forward = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	const FVector Right = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Forward, JoystickVector.Y * AxisValue);
	AddMovementInput(Right, JoystickVector.X * AxisValue);
}
