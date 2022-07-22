// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NdisplayPoiActor.generated.h"


class UMaterialBillboardComponent;


UCLASS()
class NDISPLAYPOI_API ANdisplayPoiActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANdisplayPoiActor();

	/*根组件*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USceneComponent* RootComp;


	/*挂载LineBatch组件*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	ULineBatchComponent* LineBatchComp;

	/*挂载MaterialBillBorad组件*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UMaterialBillboardComponent* MaterialBiilboradComp;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	/*根据坐标数组绘制线条*/
	UFUNCTION(BlueprintCallable, Category = "NdisplayPOI")
	void DrawNdisplayPoiLine(TArray<FVector> LinePositionArr);

	/*清除所有已绘制线条*/
	UFUNCTION(BlueprintCallable, Category = "NdisplayPOI")
	void ClearAllNdisplayPoiLines();


public:

	/*线条坐标数组*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PoiData|LineData")
	TArray<FVector> LinePositions;

	/*线条颜色*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PoiData|LineData")
	FLinearColor LineColor;

	/*线条粗细*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PoiData|LineData")
	float LineThickness;

	/*Billborad图片*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PoiData|BillboradData")
	UTexture* PoiImage;

	/*Billborad尺寸*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PoiData|BillboradData")
	FVector2D BillboradSize;

};
