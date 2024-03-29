// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractiveProp.generated.h"

UCLASS()
class EXPERIMENTALGAME3_API AInteractiveProp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractiveProp();

public:
	UPROPERTY(VisibleAnywhere)
	bool bShouldHit = false;

	UPROPERTY(EditAnywhere)
	bool bShouldDestroyAfterInteraction = true;

protected:
	class UNervousComponent* PlayerNervousComp;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void NotifyHit
		(
			class UPrimitiveComponent * MyComp,
			AActor * Other,
			class UPrimitiveComponent * OtherComp,
			bool bSelfMoved,
			FVector HitLocation,
			FVector HitNormal,
			FVector NormalImpulse,
			const FHitResult & Hit
		) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetActivateProp(bool bShouldActivate);

	UFUNCTION(BlueprintCallable)
	void HighlightSelf();

};
