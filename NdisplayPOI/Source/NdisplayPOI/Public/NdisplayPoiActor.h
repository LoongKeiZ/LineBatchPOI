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

	/*�����*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USceneComponent* RootComp;


	/*����LineBatch���*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	ULineBatchComponent* LineBatchComp;

	/*����MaterialBillBorad���*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UMaterialBillboardComponent* MaterialBiilboradComp;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	/*�������������������*/
	UFUNCTION(BlueprintCallable, Category = "NdisplayPOI")
	void DrawNdisplayPoiLine(TArray<FVector> LinePositionArr);

	/*��������ѻ�������*/
	UFUNCTION(BlueprintCallable, Category = "NdisplayPOI")
	void ClearAllNdisplayPoiLines();


public:

	/*������������*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PoiData|LineData")
	TArray<FVector> LinePositions;

	/*������ɫ*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PoiData|LineData")
	FLinearColor LineColor;

	/*������ϸ*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PoiData|LineData")
	float LineThickness;

	/*BillboradͼƬ*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PoiData|BillboradData")
	UTexture* PoiImage;

	/*Billborad�ߴ�*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PoiData|BillboradData")
	FVector2D BillboradSize;

};
