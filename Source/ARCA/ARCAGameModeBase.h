// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ARCAGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ARCA_API AARCAGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public :
	virtual void BeginPlay() override;
	
};
