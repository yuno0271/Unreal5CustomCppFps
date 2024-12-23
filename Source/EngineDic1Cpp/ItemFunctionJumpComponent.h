// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemFunctionJumpComponent.generated.h"

class UInputAction;
class AEngineDic1CppCharacter;
class UInputMappingContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPickJumpBuff);

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ENGINEDIC1CPP_API UItemFunctionJumpComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = "true"))
	UInputAction* JumpAction;

	UPROPERTY(BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = "true"))
	AEngineDic1CppCharacter* TargetCharacter;

	UPROPERTY(BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = "true"))
	UInputMappingContext* AdditionalMovement;

	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnPickJumpBuff OnPickJumpBuff;

	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnPickJumpBuff OffPickJumpBuff;

	FTimerHandle TimerHandle;

	uint32 JumpActionHandle;
	uint32 EndJumpActionHandle;

private :
	void DestroyItemFunction();

public:	
	// Sets default values for this component's properties
	UItemFunctionJumpComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
